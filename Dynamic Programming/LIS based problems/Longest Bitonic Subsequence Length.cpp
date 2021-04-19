/*PROBLEM: Given an array arr[0...(n-1)] containing n integers, a subsequence of arr[] is called 
           Bitonic if it is first increasing, then decreasing. Write a function that takes an array 
           as argument and returns the length of the longest bitonic subsequence.
           NOTE: A sequence, sorted in increasing order is considered Bitonic with the decreasing part 
           as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part 
           as empty.

  Link: https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
*/

/*UNDERLYING CONCEPT -----> 
  # This problem is a variation of standard Longest Increasing Subsequence (LIS) problem.
  # We need to construct two arrays lis[] and lds[] using Dynamic Programming solution of LIS problem. 
  # lis[i] stores the length of the Longest Increasing subsequence 𝑬𝒏𝒅𝒊𝒏𝒈 with arr[i]. 
  # lds[i] stores the length of the longest Decreasing subsequence 𝑺𝒕𝒂𝒓𝒕𝒊𝒏𝒈 from arr[i]. 
  # Finally, we need to return the max value of (lis[i] + lds[i] – 1) where i is from 0 to n-1.

  # For example, consider sequence [4, 2, 5, 9, 7, 6, 10, 3, 1]. The contents of LIS and LDS array are

             |lis[i] |lds[i] |
    (i = 0)  |   1   |   3   |
    (i = 1)  |   1   |   2   |
    (i = 2)  |   2   |   3   |
    (i = 3)  |   3   |   5   |
    (i = 4)  |   3   |   4   |
    (i = 5)  |   3   |   3   |
    (i = 6)  |   4   |   3   |
    (i = 7)  |   2   |   3   |
    (i = 8)  |   1   |   1   |

    Longest Bitonic Subsequence length is 7 [4, 5, 9, 7, 6, 3, 1]
    Longest Bitonic Subsequence is formed by (lis[3] + lds[3] - 1)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

int LBS_length(vll &v) {
	int n = (int)v.size();
	if(n == 0) return 0;
	
	vi lis(n), lds(n);
	
	// initialisation of dp matrices lis[] & lds[]
	// longest increasing subsequence ending with v[0] has length 1
	lis[0] = 1;
    
    // longest decreasing subsequence starting with v[n-1] has length 1
	lds[n-1] = 1;

    // choice diagram iterative code 
    // for lis[]
	// start from second element in the vector v[]
	for (int i = 1; i < n; i++) {
		// do for each element in subarray/subvector v[0...(i-1)]
		for(int j = 0; j < i; j++) {
			// find longest increasing subsequence that ends with v[j]
			// where v[j] is less than the current element v[i]
			if (v[i] > v[j] and lis[i] < lis[j]) lis[i] = lis[j];
		}

		// include v[i] in LIS, since for each i we are finding lisLength
		// which ends with v[i]
		lis[i]++;
	}
    
    // for lds[]
	// start from second last element in the vector v[]
	for (int i = (n - 2); i >= 0; i--) {
		// do for each element in subarray/subvector v[(i+1)....(n-1)]
		for(int j = (n - 1); j > i; j--) {
			// find longest decreasing subsequence that starts with v[j]
			// where v[j] is less than the current element v[i]
			if (v[i] > v[j] and lds[i] < lds[j]) lds[i] = lds[j];
		}

		// include v[i] in LDS, since for each i we are finding ldsLength
		// which starts with v[i]
		lds[i]++;
	}

   // find the maximum value of lis[i] + lds[i] - 1
   int mx = lis[0] + lds[0] - 1; 
   
   for(int i = 1; i < n; i++) {
       mx = max(mx, lis[i]+lds[i]-1);
   } 
     
    // return the final answer calculated
	return mx;
}

void solve()
{
  	int n; cin >> n;
  	vll v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << LBS_length(v) << "\n";
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

 /*# n is v.size() 
   # Time Complexity: O(n^2)
   # Auxiliary Space: O(n).
*/