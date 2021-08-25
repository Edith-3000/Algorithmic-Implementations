/* Problem description --->
You are given a one dimensional array that may contain both positive and negative integers, find the sum of 
contiguous subarray of numbers which has the largest sum. For example, if the given array is 
{-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7. NOTE:- please solve this problem using 
Divide and Conquer instead of kadane's algorithm.

Input Format --->
The first line consists of number of test cases T. Each test case consists of N followed by N integers.

Constraints --->
1 <= N <= 100000 
1 <= t <= 20 
0 <= A[i] <= 100000000

Output Format --->
The maximum subarray sum

Sample Input --->
2
4
1 2 3 4
3
-10 5 10 

Sample Output -->
10
15

*/

// Link: https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/
// Below is a slightly modified version of above (by making prefix sum & suffix sum arrays)

#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;

ll n;
vll v;
vll pcs, scs; // prefix sum & suffix sum arrays

ll max_crossover_sum(ll start, ll end) {
	ll mid = start + ((end - start) >> 1);
	
	ll left_sum = *max_element(scs.begin() + start, scs.begin() + mid + 1) - scs[mid+1];
	ll right_sum = *max_element(pcs.begin() + mid + 1, pcs.end()) - pcs[mid];
	
	return max(left_sum + right_sum, max(left_sum, right_sum));
}

ll max_subarr_sum(ll start, ll end) {
	// base case(s)
	if(start > end) return 0;
	if(start == end) return v[start];
	
	ll mid = start + ((end - start) >> 1);
	
	ll L = max_subarr_sum(start, mid);
	ll R = max_subarr_sum(mid + 1, end);
	ll X = max_crossover_sum(start, end);
	
	return max(X, max(L, R));
}

void solve()
{
    cin >> n;
  	v.resize(n);
  	for(ll i = 0; i < n; i++) cin >> v[i];
  	
  	pcs.resize(n, 0); scs.resize(n, 0);
  	for(ll i = 0; i < n; i++) {
  		pcs[i] = v[i];
  		if(i) pcs[i] += pcs[i-1];
  	}
  	
  	for(ll i = n - 1; i >= 0; i--) {
  		scs[i] = v[i];
  		if(i != n - 1) scs[i] += scs[i+1];
  	}
  	
  	cout << max_subarr_sum(0, n - 1) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}