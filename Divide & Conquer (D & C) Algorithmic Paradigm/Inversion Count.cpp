// Link ---> https://www.techiedelight.com/inversion-count-array/

/* 
Problem description --->

You are given an array A find out number of pairs (i,j) in array A such that A[i] > A[j] and i < j.

Input Format --->
The first line consists of number of test cases t. Each test case consists of integer N followed by N space
separated integers.

Constraints --->
1 <= N <= 100000 
1 <= t <= 20 
0 <= A[i] <= 100000000

Output Format --->
The number of inversions in array

Sample Input --->
2
4
1 2 4 3
3
3 2 1

Sample Output ---> 
1
3

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll merge_procedure(int *arr, int start, int end, int n) {
	// temporary array to store the sorted result 
	int tmp [n];
	int mid = start + (end - start)/2;
	
	// i = iterator for the first half
	// j = iterator for the second half
	// k = iterator fot the tmp[] array
	int i = start, j = mid + 1, k = start;
	
	ll cnt = 0; // to store the #cross inversion pairs
	while(i <= mid && j <= end) {
		if(arr[i] <= arr[j]) tmp[k++] = arr[i++];
		else {
			tmp[k++] = arr[j++];
			cnt += (mid - i + 1);
		}
	}
	
	// fill the array if some of the elements are still left
	while(i <= mid) tmp[k++] = arr[i++];
	while(j <= end)	tmp[k++] = arr[j++];
	
	// copying back the sorted elements of the 2 parts
	// in the original array
	for(int x = start; x <= end; x++) arr[x] = tmp[x];
	
	return cnt;
}

// function which will give the #inversion pairs in the range
// [start, end]
ll inversion_count(int *arr, int start, int end, int n) {
	// base case
	if(start >= end) return 0;
	
	int mid = start + (end - start)/2;
	
	// function which will give the #inversion pairs in the range
	// [start, mid]
	ll left = inversion_count(arr, start, mid, n);
	
	// function which will give the #inversion pairs in the range
	// [mid + 1, end]
	ll right = inversion_count(arr, mid + 1, end, n);
	
	// function which will give the #cross inversion b/w the 
	// left and right subpart
	// Remember: sorting won't affect the #cross inversions as
	// the relative ordering of elements in left & right subpart
	// will stay the same
	ll cross_cnt = merge_procedure(arr, start, end, n);
	
	// return the total #inversions
	return left + right + cross_cnt;
}

void solve()
{
  	int n; cin >> n;
  	int arr[n];
  	for(int i = 0; i < n; i++) cin >> arr[i];
  	
  	cout << inversion_count(arr, 0, n - 1, n) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

// Time complexity: O(n x log2(n)) [same as that of Merge Sort Algo]
// Space complexity: O(n)