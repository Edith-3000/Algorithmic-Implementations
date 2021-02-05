// Problem: Two Sets II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1093
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 04-02-2021 11:21:09 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_expo(ll a, ll b) {
	a %= mod;
	if(a == 0) return 0;
	ll res = 1;
	while(b > 0) {
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	
	return res;
}

// to calculate modulo multiplicative inverse of 
// a number 'n' under modulo 'mod'
ll mod_inv(ll n) {
	return mod_expo(n, mod - 2) % mod;
}

void solve()
{
  	ll n; cin >> n;
  	if((n * (n + 1)) % 4 != 0) { cout << 0 << "\n"; return; }
  	
  	ll dp[n+1][n*(n+1)/4 + 1];
  	dp[0][0] = 1;
  	for(ll x = 1; x <= (n * (n + 1))/4; x++) dp[0][x] = 0;
  	
  	for(ll i = 1; i <= n; i++) {
  		for(ll x = 0; x <= (n * (n + 1))/4; x++) {
  			dp[i][x] = (((x < i) ? 0 : dp[i-1][x-i]) + dp[i-1][x]) % mod;
  		}
  	}
  	
    // we have to divide the result by 2 but as we are dealing
    // with modular arithmetic we must multiply the result
    // by mod_inv of 2 under mod
  	ll res = (dp[n][n*(n+1)/4] * mod_inv(2)) % mod;
  	cout << res << "\n";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}