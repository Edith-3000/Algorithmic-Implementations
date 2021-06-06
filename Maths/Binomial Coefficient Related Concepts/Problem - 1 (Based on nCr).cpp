// This problem is very much similar to "Finding number of K length subsequences with minimum sum", with
// the only change of maximum sum instead of minimum.
// Visit: https://www.geeksforgeeks.org/number-of-k-length-subsequences-with-minimum-sum/

/*************************************************************************************************************/

// Problem: E. Advertising Agency
// Contest: Codeforces - Codeforces Round #697 (Div. 3)
// URL: https://codeforces.com/contest/1475/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 27-01-2021 23:32:53 IST (UTC+05:30)
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
vll fact(1001);

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

ll nCr(ll n, ll r) {
	ll res = fact[n];
	res = (res % mod * mod_expo(fact[r], mod - 2) % mod) % mod;
	res = (res % mod * mod_expo(fact[n-r], mod - 2) % mod) % mod;
	return res;
}

void prep() {
	fact[0] = 1;
	for(ll i = 1; i <= 1000; i++) {
		fact[i] = (i * fact[i-1]) % mod;
	}
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	sort(v.rbegin(), v.rend());
  	int mn = v[k-1];
  	int cnt = 0, cntK = 0;
  	for(int i = 0; i < k; i++) {
  		if(v[i] == mn) cntK++;
  	}
  	
  	cnt = cntK;
  	for(int i = k; i < n; i++) {
  		if(v[i] == mn) cnt++;
  	}
  	
  	cout << nCr(cnt, cntK) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
	
	prep();
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}