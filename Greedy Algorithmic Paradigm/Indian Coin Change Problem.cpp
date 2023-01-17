/* Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the 
   denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000} 
   valued coins/notes, what is the minimum number of coins and/or notes needed to make the change?
   Eg. Input: V = 121
	    Output: 3
	    We need a 100 Rs note, a 20 Rs note and a 1 Rs coin. 

   Reference: https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll indian_coin_change(ll amt) {
	vector<ll> denom {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};	
	ll cnt = 0;
	
	while(amt > 0){
		ll pos = upper_bound(denom.begin(), denom.end(), amt) - 1 - denom.begin();
		amt -= denom[pos];
		cnt++; 
	}
	
	return cnt;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter the amount: ₹";
    ll amt; cin >> amt; cout << amt << "\n";
    
    cout << "#coins needed = " << indian_coin_change(amt);

    return 0;
}

/* 
   Sample i/p: 213
   Sample o/p: Enter the amount: ₹213
               #coins needed = 4

   Note: The above approach may not work for all denominations. 
   For example, it doesn’t work for denominations {9, 6, 5, 1} and V = 11. 
   The above approach would print 3. But we can use only 2 denominations i.e. 5 and 6.
   For general input, dynamic programming approach can be used.
*/