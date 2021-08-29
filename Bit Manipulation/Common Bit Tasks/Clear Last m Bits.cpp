#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Function to clear the last m bits of n
// NOTE: -1 in 2's complement representation (which is the representation used by machines) ==>
//       11111111111111111......
ll clr_last_m_bits(ll n, ll m) {
    // mask = (~0) << i can also be used 
    // as binary of -1 and ~0 are equivalent
	ll mask = (-1 << m);
	return (n & mask);
}

void solve()
{
  	ll n, m; cin >> n >> m;
  	cout << clr_last_m_bits(n, m) << "\n";
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