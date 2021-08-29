// Ref: https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/
/********************************************************************************************************************/

// WITHOUT USING BIT MANIPULATION

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Function to find if x is a power of 2 or not
bool power_of_2(ll x) {
	if(x == 0) return 0;
	while(x % 2 == 0) x /= 2;
	return (x == 1LL);
}

void solve()
{
  	ll n; cin >> n;
  	
  	if(power_of_2(n)) cout << "Yes\n";
  	else cout << "No\n";
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

/********************************************************************************************************/

// USING BIT MANIPULATION

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Function to find if x is a power of 2 or not
bool power_of_2(ll x) {
	// x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
	return (x and !(x & (x - 1)));
}

void solve()
{
  	ll n; cin >> n;
  	
  	if(power_of_2(n)) cout << "Yes\n";
  	else cout << "No\n";
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