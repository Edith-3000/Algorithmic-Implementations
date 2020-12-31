// Useful Reference(s): --->
// https://medium.com/algorithms-and-leetcode/best-time-to-buy-sell-stocks-on-leetcode-the-ultimate-guide-ce420259b323

// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

/*********************************************************************************************************/

// Method 1 (STATE MACHINE DP)
// Link for ver nice explanation of this approach --->
// https://www.youtube.com/watch?v=pTQB9wbIpfU

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int n, int fee) {
	// prevBSP = previous Bought State Profit
	// prevSSP = previous Sold State Profit
	int prevBSP, prevSSP;
	
	// currBSP = current Bought State Profit
	// currSSP = current Sold State Profit
	int currBSP, currSSP;
	
	prevBSP = -v[0]; prevSSP = 0;
	
	for(int i = 1; i < n; i++) {
		currBSP = max(prevBSP, prevSSP - v[i]);
		currSSP = max(prevSSP, prevBSP + v[i] - fee);
		
		// updating values
		prevBSP = currBSP;
		prevSSP = currSSP;
	}
	
	return prevSSP;
}

int maxProfit(vector<int> &prices, int fee) {
	vector<int> v = prices;
	int n = v.size();
	
	return solve(v, n, fee);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {1, 3, 2, 8, 4, 9};
    int fee; 
    fee = 2;
    cout << maxProfit(prices, fee);

    return 0;
}

// Time complexity: O(n), where n = size of input array 