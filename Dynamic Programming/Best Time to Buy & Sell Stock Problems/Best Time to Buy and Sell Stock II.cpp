// Useful Reference(s): --->
// https://medium.com/algorithms-and-leetcode/best-time-to-buy-sell-stocks-on-leetcode-the-ultimate-guide-ce420259b323

// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*********************************************************************************************************/

// Method 1 (Recursive Approach)

#include<bits/stdc++.h>
using namespace std;

int solve(bool buy, int pos, int n, vector<int> &v) {
	// base case ==> if pos >= n, means elements finished
	// if buy == true && pos == n - 1, we have to return 0
	// as we can't buy the last element, we can either skip it 
	// or sell it
	if((pos >= n) || (buy && pos == n - 1)) return 0;
		
	// Now we have 3 choices (skip, buy or sell the current share according to 
	// previous call)
	
	// Case 1: if we skip the current element
	int skip = solve(buy, pos + 1, n, v);
	
	// Case 2: if we either buy or sell the current element
	int profit = 0;
	
	// Case 2.1: if we buy the current element
	if(buy) {
		profit = -v[pos] + solve(false, pos + 1, n, v);
	}
	
	// Case 2.2: if we sell the current element
	else {
		profit = v[pos] + solve(true, pos + 1, n, v);
	}
	
	// return by taking whichever is maximum
	return max(skip, profit);
}

int maxProfit(vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	if(n < 2) return 0;
	if(n == 2) return max(0, v[1] - v[0]);
		
	// buy is passed as true because we can either skip or buy 
	// the 1st element we can't sell it
	return solve(true, 0, n, v);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);

    return 0;
}

// Time complexity: O(2^n), where n = size of input array

/************************************************************************************************************/

// Method 2 (Top Down DP)

#include<bits/stdc++.h>
using namespace std;

int solve(bool buy, int pos, int n, vector<int> &dp_sell, vector<int> &dp_buy, vector<int> &v) {
	// base case ==> if pos >= n, means elements finished
	// if buy == true && pos == n - 1, we have to return 0
	// as we can't buy the last element, we can either skip it 
	// or sell it
	if((pos >= n) || (buy && pos == n - 1)) return 0;
	
	// check if already calculated or not
	if(buy && dp_buy[pos] != -1) return dp_buy[pos];
	if(!buy && dp_sell[pos] != -1) return dp_sell[pos];
	
	// Now we have 3 choices (skip, buy or sell the current share according to 
	// previous call)
	
	// Case 1: if we skip the current element
	int skip = solve(buy, pos + 1, n, dp_sell, dp_buy, v);
	
	// Case 2: if we either buy or sell the current element
	int profit = 0;
	
	// Case 2.1: if we buy the current element
	if(buy) {
		profit = -v[pos] + solve(false, pos + 1, n, dp_sell, dp_buy, v);
		return dp_buy[pos] = max(skip, profit);
	}
	
	// Case 2.2: if we sell the current element
	else {
		profit = v[pos] + solve(true, pos + 1, n, dp_sell, dp_buy, v);
		return dp_sell[pos] = max(skip, profit); 
	}
	
	// return by taking whichever is maximum
	return max(skip, profit);
}

int maxProfit(vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	if(n < 2) return 0;
	if(n == 2) return max(0, v[1] - v[0]);
	
	vector<int> dp_sell(n, -1);
	vector<int> dp_buy(n, -1);
	
	// buy is passed as true because we can either skip or buy 
	// the 1st element we can't sell it
	return solve(true, 0, n, dp_sell, dp_buy, v);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(n), where n = size of input array

/**********************************************************************************************************/

// Method 3 (Peak-Valley Approach)

// Idea behind the below approach --->
// We need to find the local minima and where there is local minima we need to buy the stock,and we need to 
// sell the stock when there is a local maxima. But the 1st share prices is to be excluded in this method.

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	int profit = 0;
	for(int i = 1; i < n; i++) {
		if(v[i] > v[i - 1]) profit += (v[i] - v[i - 1]);
	}
	
	return profit;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(1), where n = size of input array