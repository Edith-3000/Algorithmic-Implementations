// Useful Reference(s): --->
// https://medium.com/algorithms-and-leetcode/best-time-to-buy-sell-stocks-on-leetcode-the-ultimate-guide-ce420259b323

// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*********************************************************************************************************/

// Method 1

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	if(n < 2) return 0;
	
	int res = INT_MIN;
	for(int i = 0; i < n; i++) {
		int mx_r = -1;
		for(int j = i + 1; j < n; j++) {
			if(v[j] > v[i]) mx_r = max(mx_r, v[j]);
		}
		
		res = max(res, mx_r - v[i]);
	}
	
	return (res < 0 ? 0 : res);
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

// Time complexity: O(n^2), where n = size of input array

/**************************************************************************************************************/

// Method 2

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	if(n < 2) return 0;
	
	int res = INT_MIN;
	int min_stk = v[0];
	
	for(int i = 0; i < n; i++) {
		res = max(res, v[i] - min_stk);
		min_stk = min(min_stk, v[i]);
	}
	
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {7, 1, 5 ,3 , 6, 4};
    cout << maxProfit(prices);

    return 0;
}

// Time complexity: O(n), where n = size of input array