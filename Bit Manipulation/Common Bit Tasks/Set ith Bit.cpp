#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Function to set the ith bit in n
// NOTE: in the code below 0-based indexing of bits from RHS to LHS(i.e. from 
//       LSB to MSB) is considered
ll set_bit(ll n, ll i) {
	ll mask = (1LL << i);
	ll res = n | mask;
	return res;
}

void solve()
{
  	ll n, pos; cin >> n >> pos;
  	cout << set_bit(n, pos) << "\n";
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