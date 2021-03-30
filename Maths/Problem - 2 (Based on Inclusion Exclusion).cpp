// Approach: https://www.youtube.com/watch?v=YiTOolk_JNc
/*******************************************************************************************************/

// Problem: Bob and consulting sessions
// Contest: HackerEarth - Math - Combinatorics - Inclusion-Exclusion
// URL: https://www.hackerearth.com/practice/math/combinatorics/inclusion-exclusion/practice-problems/algorithm/aryan-and-consulting-sessions-0e0656ab/
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 30-03-2021 16:15:55 IST (UTC+05:30)
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
const ll mod = 1e9+7;
const ll N = 1e5;

ll n;
vll factorial(N + 1);

ll mod_exp(ll a, ll b) {
	a %= mod;
	if(a == 0) return 0LL;
	
	ll res = 1LL;
	while(b > 0) {
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	
	return res;
}

ll mod_inv(ll a, ll b) {
	return mod_exp(a, b - 2);
}

void calculate_factorial() {
	factorial[0] = 1LL;
	for(ll i = 1; i <= N; i++) {
		factorial[i] = (factorial[i-1] * i) % mod;
	}
}

ll nCr(ll n, ll r) {
	if(n == r or n == 0) return 1LL;
	if(n < r) return 0LL;
	
	ll num = factorial[n];
	ll den = (factorial[n-r] * factorial[r]) % mod;
	
	ll res = (num * mod_inv(den, mod)) % mod;
	return res;
}

void solve()
{
  	cin >> n;
  	
  	ll res = 0LL;
  	
  	for(ll i = n; i >= 0; i--) {
  		// applying principal of inclusion and exclusion
  		ll tmp = (nCr(n, i) * mod_exp(2LL, i * (i - 1) / 2)) % mod;
  		
  		if((i % 2) == (n % 2)) res = (res + tmp) % mod;
  		else res = (res - tmp + mod) % mod;
  	}
  	
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
	
	calculate_factorial();
    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}