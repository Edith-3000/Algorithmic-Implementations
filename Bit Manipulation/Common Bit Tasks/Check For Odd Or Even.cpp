#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Function to check if a number is odd or even
bool is_odd(ll n) {
	if(n & 1LL) return 1;
	else return 0;
}

void solve()
{
  	ll n; cin >> n;
  	if(is_odd(n)) cout << "Odd\n";
  	else cout << "Even\n";
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