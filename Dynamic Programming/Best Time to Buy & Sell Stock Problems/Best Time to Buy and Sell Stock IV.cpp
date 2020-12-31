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

// Method 3 (Bottom up DP - 2D)
// Link for this approach --->
// https://www.youtube.com/watch?v=3YILP-PdEJA 

#include<bits/stdc++.h>
using namespace std;

// dp[i][j] will store the max profit we can gain by performing 
// at most i transactions upto the jth day
vector<vector<int>> dp;

int solve(int k, int n, vector<int> &v) {
	dp.resize(k + 1, vector<int>(n));
	
	// initialization 
	for(int i = 0; i < n; i++) dp[0][i] = 0;
	for(int j = 0; j <= k; j++) dp[j][0] = 0;
	
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j < n; j++) {
			// case when we have already performed at most
			// i transactions upto the (j - 1)th day
			dp[i][j] = dp[i][j - 1];
			
			// case when we have performed at most (i - 1) transactions
			// upto the dth day & we are performing 1 transaction on the 
			// jth day
			for(int d = (j - 1); d >= 0; d--) {
				dp[i][j] = max(dp[i][j], dp[i - 1][d] + v[j] - v[d]);
			}
		}
	}
	
	return dp[k][n - 1];
}

int maxProfit(int k, vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	if(n == 0 || k == 0) return 0; 
	
	return solve(k, n, v);
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

// Time complexity: O(k x n^2)

/************************************************************************************************************/

// Method 4 (Bottom up DP - 2D)
// This method is just a slight modification of "Method 3" to make it more 
// time efficient
// Link for this approach --->
// https://www.youtube.com/watch?v=3YILP-PdEJA 

#include<bits/stdc++.h>
using namespace std;

// dp[i][j] will store the max profit we can gain by performing 
// at most i transactions upto the jth day
vector<vector<int>> dp;

int solve(int k, int n, vector<int> &v) {
	dp.resize(k + 1, vector<int>(n));
	
	// initialization 
	for(int i = 0; i < n; i++) dp[0][i] = 0;
	for(int j = 0; j <= k; j++) dp[j][0] = 0;
	
	int mx;
	for(int i = 1; i <= k; i++) {
		mx = dp[i - 1][0] - v[0];
		for(int j = 1; j < n; j++) {
			// case when we have already performed at most
			// i transactions upto the (j - 1)th day
			dp[i][j] = max(dp[i][j - 1], mx + v[j]);
			mx = max(mx, dp[i - 1][j] - v[j]);
		}
	}
	
	return dp[k][n - 1];
}

int maxProfit(int k, vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	if(n == 0 || k == 0) return 0; 
	
	return solve(k, n, v);
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

// Time complexity: O(k x n)

/************************************************************************************************************/

// Method 5 (STATE MACHINE DP)
// Link for explanation of this approach --->
// https://www.youtube.com/watch?v=6928FkPhGUA

#include<bits/stdc++.h>
using namespace std;

int solve(int k, int n, vector<int> &v) {
	// Case 1: 
	if(n <= 1 || k == 0) return 0;
	
	// Case 2
	if(2 * k >= n) {
		// in this case simply use the peak-valley approach
		int res = 0;
		for(int i = 1; i < n; i++) {
			if(v[i] > v[i - 1]) res += (v[i] - v[i - 1]);
		}
		
		return res;
	}
	
	// Case 3 (when 2 * k < n)
	// dp[i] is used for remembering the max profit which 
	// can be achieved for ith state, (in total there can be atmost
	// (2 * k) states or atmost k transactions 
	vector<int> dp(2 * k);
	
	for(int i = 0; i < (2 * k); i++) {
		if(i & 1) dp[i] = 0; // odd numbered states are buy states
		else dp[i] = INT_MIN; // even numbered states are sell states
	}
	
	// j is used for iterating over the days
	// i is used for iterating over the all (2 * k) states
	// dp[i] upto a particular j will store the the max profit which
	// can be gained by performing at most k transactions(having 2 * k states)
	// by considering the first (j + 1) elements (from v[0] to v[j])
	for(int j = 0; j < n; j++) {
		for(int i = 0; i < (2 * k); i++) {
			// special case
			if(i == 0) dp[i] = max(dp[i], -v[j]);
			
			// when i is the sell state
			else if(i & 1) dp[i] = max(dp[i], dp[i - 1] + v[j]); 
			
			// when i is the buy state
			else dp[i] = max(dp[i], dp[i - 1] - v[j]); 
		}
	}
	
	return dp[2 * k - 1];
}

int maxProfit(int k, vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	return solve(k, n, v);
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

// NOTE: In Case 3, we don't perform 'k' transactions [since (2 * k < n)], the transactions will be 
//       skipped & previous values in the dp[] will be stored.  

// Time complexity: O(k x n)

/************************************************************************************************************/

// Method 6 (STATE MACHINE DP) (Just a slight modification of the Method 5)
// Instead of using a single dp array as in Method 2, in this method, 2 dp
// arrays are considered.

#include<bits/stdc++.h>
using namespace std;

int solve(int k, int n, vector<int> &v) {
	// Case 1: 
	if(n <= 1 || k == 0) return 0;
	
	// Case 2
	if(2 * k >= n) {
		// in this case simply use the peak-valley approach
		int res = 0;
		for(int i = 1; i < n; i++) {
			if(v[i] > v[i - 1]) res += (v[i] - v[i - 1]);
		}
		
		return res;
	}
	
	// Case 3 (when 2 * k < n)
	vector<int> dp_buy(k), dp_sell(k);
	
	for(int i = 1; i < k; i++) {
		dp_buy[i] = INT_MIN;
		dp_sell[i] = 0;
	}
	
	dp_buy[0] = -v[0];
	dp_sell[0] = 0;
	
	for(int j = 0; j < n; j++) {
		for(int i = 0; i < k; i++) {
			if(i == 0) {
				dp_buy[i] = max(dp_buy[i], -v[j]);
				dp_sell[i] = max(dp_sell[i], dp_buy[i] + v[j]);
			}
			
			else {
				dp_buy[i] = max(dp_buy[i], dp_sell[i - 1] - v[j]);
				dp_sell[i] = max(dp_sell[i], dp_buy[i] + v[j]);
			}
		}
	}
	
	return dp_sell[k - 1];
}

int maxProfit(int k, vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	return solve(k, n, v);
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

// NOTE: In Case 3, we don't perform 'k' transactions [since (2 * k < n)], the transactions will be 
//       skipped & previous values in the dp_sell[] & dp_buy[] will be stored.  

// Time complexity: O(k x n)