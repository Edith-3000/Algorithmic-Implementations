// PROBLEM LINK: https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

// RECURSIVE METHOD

#include<bits/stdc++.h>
using namespace std;

int recursive(vector<int> &prices, int n){
	// base case
	if(n <= 0) return 0;
	
	int res = INT_MIN;
	for(int i = 0; i < n; i++){
		int cut_len = i + 1;
		int curr_res = prices[i] + recursive(prices, n - cut_len);
		res = max(res, curr_res);
	}
	
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    vector<int> prices{1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout << recursive(prices, n);

    return 0;
}

// Time complexity: Exponential

/***********************************************************************************************************/

// BOTTOM UP DP METHOD

#include<bits/stdc++.h>
using namespace std;

int bottom_up(vector<int> &prices, int n){
	vector<int> dp(n+1, 0);
	
	for(int len = 1; len <= n; len++){
		dp[len] = INT_MIN;
		
		for(int i = 0; i < len; i++){
			int cut_len = i + 1;
			int curr_res = prices[i] + dp[len - cut_len];
			dp[len] = max(dp[len], curr_res);
		}
	}
	
	return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    vector<int> prices{1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout << bottom_up(prices, n);

    return 0;
}

// Time complexity: O(n^2)