// Useful Reference(s): --->
// https://medium.com/algorithms-and-leetcode/best-time-to-buy-sell-stocks-on-leetcode-the-ultimate-guide-ce420259b323

// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

/************************************************************************************************************/

// Method 1 (Recursive Approach)

#include<bits/stdc++.h>
using namespace std;

int solve(int pos, int n, vector<int> &v) {
	// base case for out of bounds
	if(pos >= n) return 0;
	
	// assuming that we are skipping the current day
	int res = solve(pos + 1, n, v);
	
	// assuming that we buy on pos find all the positions 
	// where we can sell the stock
	for(int i = pos + 1; i < n; i++) {
		// to gain profit v[i] must > v[pos]
		if(v[i] > v[pos]) {
			// as we have sell the stock on ith day then there is a cooldown
			// of 1 day, so we now start our subproblem from (i + 2)th day
			res = max(res, v[i] - v[pos] + solve(i + 2, n, v));	
		}
	}
	
	return res;
}

int maxProfit(vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	if(n < 2) return 0;
	if(n == 2) return max(0, v[1] - v[0]);
	
	return solve(0, n, v);	
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {1, 2, 3, 0, 2};
    cout << maxProfit(prices);

    return 0;
}

// Time complexity: O(n^n), where n = size of input array 

/******************************************************************************************************/

// Method 2 (Top Down DP)

#include<bits/stdc++.h>
using namespace std;

int solve(int pos, int n, vector<int> &v, vector<int> &dp) {
	// base case for out of bounds
	if(pos >= n) return 0;
	
	// check if already calculated or not
	if(dp[pos] != -1) return dp[pos];
	
	// assuming that we are skipping the current day
	int res = solve(pos + 1, n, v, dp);
	
	// assuming that we buy on pos find all the positions 
	// where we can sell the stock
	for(int i = pos + 1; i < n; i++) {
		// to gain profit v[i] must > v[pos]
		if(v[i] > v[pos]) {
			// as we have sell the stock on ith day then there is a cooldown
			// of 1 day, so we now start our subproblem from (i + 2)th day
			res = max(res, v[i] - v[pos] + solve(i + 2, n, v, dp));	
		}
	}
	
	return dp[pos] = res;
}

int maxProfit(vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	if(n < 2) return 0;
	if(n == 2) return max(0, v[1] - v[0]);
	
	vector<int> dp(n, -1);
		
	return solve(0, n, v, dp);	
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {1, 2, 3, 0, 2};
    cout << maxProfit(prices);

    return 0;
}

// Time complexity: 

/********************************************************************************************************/

// NOTE: I DID NOT COMPLETELY UNDERSTAND HOW THIS APPROACH SATISFIES THE "COOLDOWN" CONSTRAINT.

// Method 3 (STATE MACHINE DP)
// Link for explanation of this approach --->
// https://www.youtube.com/watch?v=4wNXkhAky3s

#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &v) {
	vector<int> noStock(n);
	vector<int> inHand(n);
	vector<int> sold(n);
	
	noStock[0] = 0;
	inHand[0] = -v[0];
	sold[0] = 0;
	
	for(int i = 1; i < n; i++) {
		noStock[i] = max(noStock[i - 1], sold[i - 1]);
		inHand[i] = max(inHand[i - 1], -v[i] + noStock[i - 1]);
		sold[i] = max(sold[i - 1], v[i] + inHand[i - 1]);
	}
	
	return max(noStock[n - 1], sold[n - 1]);
}

int maxProfit(vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	if(n < 2) return 0;
	if(n == 2) return max(0, v[1] - v[0]);
	
	return solve(n, v);	
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {1, 2, 3, 0, 2};
    cout << maxProfit(prices);

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(n), where n = size of input array 

/*******************************************************************************************************/

// NOTE: I DID NOT COMPLETELY UNDERSTAND HOW THIS APPROACH SATISFIES THE "COOLDOWN" CONSTRAINT.

// Method 4 (SPACE OPTIMIZED STATE MACHINE DP)
// Link for explanation of this approach --->
// https://www.youtube.com/watch?v=4wNXkhAky3s

#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &v) {
    int prevNoStock, prevInHand, prevSold;
    int currNoStock, currInHand, currSold;
    
    prevNoStock = 0;
    prevInHand = -v[0]; // Here we buy a stock on the very first day and have not sold it, yet
    prevSold = 0;
    
    for(int i = 1; i < n; i++) {
    	// We have no stock today if we:
        // 1. Had no stock yesterday also, and we didn't do anything about it
        // 2. We sold a stock yesterday
        currNoStock = max(prevNoStock, prevSold);
        
        // We have a stock in hand today if we:
        // 1. Had a stock in hand yesterday as well, and we didn't do anything about it
        // 2. Had no stock yesterday but we bought a stock today
        currInHand = max(prevInHand, -v[i] + prevNoStock); // We subtract v[i] as we bought a stock
        
        // We have sold a stock today, if we:
        // Only had a stock in hand yesterday and we sold it today
        currSold = max(prevSold, v[i] + prevInHand);  // We add v[i] as we sold a stock
		
		// updating the values
        prevNoStock = currNoStock;
        prevInHand = currInHand;
        prevSold = currSold;
    }
    
    return max(prevNoStock, prevSold);
}

int maxProfit(vector<int> &prices) {
    vector<int> v = prices;
    int n = v.size();
    
     // There are only 1 or fewer days to trade stocks, so then we cannot make a
     // profit by buying and selling stocks, so we don't buy or sell
     // so we return 0
    if(n < 2) return 0;
    
    // self explanatory
    if(n == 2) return max(0, v[1] - v[0]);
    
    return solve(n, v); 
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {1, 2, 3, 0, 2};
    cout << maxProfit(prices);

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(1), where n = size of input array 