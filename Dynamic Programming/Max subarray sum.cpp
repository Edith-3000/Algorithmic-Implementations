// PROBLEM LINK: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

/************************************************************************************************************/

// DP BASED IMPLEMENTATION
// (Hanldes the case when all nos. are -ve)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int n){
	vector<int> dp(n, 0);
	dp[0] = v[0];
	int max_so_far = dp[0];
	
	for(int i = 1; i < n; i++){
		dp[i] = max(v[i], dp[i-1] + v[i]);
		max_so_far = max(dp[i], max_so_far);
	}
	
	return max_so_far;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter i/p size: ";
    int n; cin >> n; cout << n << "\n";
    cout << "Enter elements: ";
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(auto x: v) cout << x << " ";
    cout << "\nMax subarray sum = ";
    
    cout << solve(v, n);

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(n)

/***************************************************************************************************************/

// SPACE OPTIMISATION OF THE ABOVE DP BASED IMPLEMENTATION (Also called as "KADANE's ALGORITHM")
// (Hanldes the case when all nos. are -ve)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int n){
	int curr_sum = v[0];
	int max_so_far = v[0];
	
	for(int i = 1; i < n; i++){
		curr_sum = max(v[i], curr_sum + v[i]);
		max_so_far = max(curr_sum, max_so_far);
	}
	
	return max_so_far;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter i/p size: ";
    int n; cin >> n; cout << n << "\n";
    cout << "Enter elements: ";
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(auto x: v) cout << x << " ";
    cout << "\nMax subarray sum = ";
    
    cout << solve(v, n);

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(1)