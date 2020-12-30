// Useful Reference(s): --->
// https://medium.com/algorithms-and-leetcode/best-time-to-buy-sell-stocks-on-leetcode-the-ultimate-guide-ce420259b323

// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

/*********************************************************************************************************/

// Method 1 (Top Down DP - 3D) (using a 3D vector)

/* # In this approach our dp is defined by 3 states (that's why 3D DP)
   # State-1(bought): This shows if the stock just previous to current stock was bought or not
                      We will have max 2 possibilities in this, even though we have 3 choices (skip/buy/sell the current stock)
   # State-2(t): This shows the atmost #transactions we can make from current position to the last of prices array.
                 So there will be (k + 1) values for this (0 to k).
   # State-3(pos): It shows the current position of stock prices which we are working on.                  
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

int solve(bool bought, int t, int pos, int n, vector<int> &v) {
	// base case
	// if out of bounds or if #transactions = 0, then profit which
	// can be achieved = 0
	if(pos >= n || t == 0) return 0;
	
	// check if already calculated or not
	if(dp[bought][t][pos] != -1) return dp[bought][t][pos];
	
	// Now we have 3 choices (skip, buy or sell the current share according to 
	// previous call)
	
	// Case: if we skip the current element
	int ans = solve(bought, t, pos + 1, n, v);
	
	// Case: if we sell the current element
	if(bought) ans = max(ans, v[pos] + solve(false, t - 1, pos + 1, n, v));
	
	// Case: if we buy the current element
	else ans = max(ans, -v[pos] + solve(true, t, pos + 1, n, v));
	
	// return by taking whichever is maximum
	return dp[bought][t][pos] = ans;
}

int maxProfit(int k, vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	dp.resize(2, vector<vector<int>>(k + 1, vector<int>(n, -1)));
	return solve(false, k, 0, n, v);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {3, 2, 6, 5, 0, 3};
    int k; k =3;
    cout << maxProfit(k, prices);

    return 0;
}

// Time complexity: 

/************************************************************************************************************/

// Method 2 (Top Down DP - 3D) (using a unordered_map instead of a 3D table for lookup)
// This method may give TLE in some of the cases as the lookup of a string in the unordered map 
// will not take constant time as in Method 1 above.

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;

int solve(bool bought, int t, int pos, int n, vector<int> &v) {
	// base case
	// if out of bounds or if #transactions = 0, then profit which
	// can be achieved = 0
	if(pos >= n || t == 0) return 0;
	
	// check if already calculated or not
	string key = to_string(bought) + to_string(t) + to_string(pos);
	if(dp.count(key) != 0) return dp[key];
	
	// Now we have 3 choices (skip, buy or sell the current share according to 
	// previous call)
	
	// Case: if we skip the current element
	int ans = solve(bought, t, pos + 1, n, v);
	
	// Case: if we sell the current element
	if(bought) ans = max(ans, v[pos] + solve(false, t - 1, pos + 1, n, v));
	
	// Case: if we buy the current element
	else ans = max(ans, -v[pos] + solve(true, t, pos + 1, n, v));
	
	// return by taking whichever is maximum
	return dp[key] = ans;
}

int maxProfit(int k, vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	return solve(false, k, 0, n, v);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {3, 2, 6, 5, 0, 3};
    int k; k = 2;
    cout << maxProfit(k, prices);

    return 0;
}

// This method is not as efficient in terms of time as compared to Method 1, but it is more efficient
// in terms of space as against Method 1.

/************************************************************************************************************/

