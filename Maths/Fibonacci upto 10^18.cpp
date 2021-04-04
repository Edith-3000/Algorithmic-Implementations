// Ref: https://codeforces.com/blog/entry/14516
/******************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;

// F[n] is the (n + 1)th fibonacci number % mod 
map<ll, ll> F;

ll f(ll n) {
	if(F.count(n)) return F[n];
	
	ll k = n / 2;
	if ((n & 1) == 0) { // n = 2 * k
		return F[n] = (f(k) * f(k) + f(k-1) * f(k-1)) % mod;
	} 
	
	else { // n = 2 * k + 1
		return F[n] = (f(k) * f(k+1) + f(k-1) * f(k)) % mod;
	}
}

void solve()
{
  	ll n;
  	F[0] = F[1] = 1;
  	
  	while(cin >> n) {
  		cout << (n == 0 ? 0 : f(n - 1)) << "\n";
  	}
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
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

// Time complexity: O(log(n) * loglog(n))

/********************************************************************************************************/