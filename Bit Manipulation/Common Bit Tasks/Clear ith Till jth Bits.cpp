#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Function to clear the range of bits [....j.....i...] of n
// NOTE: in the code below 0-based indexing of bits from RHS to LHS(i.e. from 
//       LSB to MSB) is considered and j > i
ll clear_range_i_to_j(ll n, ll i, ll j) {
    // to form a number whose binary representation is of the form 1111000000 
    // a = (~0) << (j + 1) can also be used 
	ll a = (-1) << (j + 1);

	// to form a number whose binary representationis of the form 0000000111 
	//(which is of the form 2^n - 1, now 2^n can be represented as 1 << n)
    ll b = (1LL << i) - 1; 
    
    // mask will be of the form 1111000111
    ll mask = a | b;
    return (n & mask);
}

void solve()
{
  	ll n, i, j; cin >> n >> i >> j;
  	cout << clear_range_i_to_j(n, i, j) << "\n";
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