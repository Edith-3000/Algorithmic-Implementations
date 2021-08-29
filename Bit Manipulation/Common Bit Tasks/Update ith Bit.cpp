#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Function to update the ith bit of n to v (which is either 0 or 1)
// NOTE: in the code below 0-based indexing of bits from RHS to LHS(i.e. from 
//       LSB to MSB) is considered
ll upd_bit(ll n, ll i, ll v) {
	// first clear the ith bit
	ll mask = ~(1LL << i);
	ll cleared_n = n & mask;

	// return updated number
	return cleared_n | (v << i);
}

void solve()
{
  	ll n, pos, v; cin >> n >> pos >> v;
  	cout << upd_bit(n, pos, v) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
    // #endif
    
    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}