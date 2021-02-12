// Problem: C. Little Girl and Maximum Sum
// Contest: Codeforces - Codeforces Round #169 (Div. 2)
// URL: https://codeforces.com/problemset/problem/276/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 16-01-2021 11:46:22 IST (UTC+05:30)
// Author: kapil_choudhary

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

vll bit;
vll v;
ll n, q;

void bit_update(ll i, ll val) {
	while(i <= n) {
		bit[i] += val;
		i += (i & -i);
	}
}

ll bit_query(ll i) {
	ll res = 0;
	while(i > 0) {
		res += bit[i];
		i -= (i & -i);
	}
	
	return res;
}

void solve()
{
  	cin >> n >> q;
  	v.resize(n);
  	for(ll i = 0; i < n; i++) cin >> v[i];
  	sort(v.rbegin(), v.rend());
  	
  	bit.resize(n + 5, 0);
  	for(ll i = 0; i < q; i++) {
  		ll l, r; cin >> l >> r;
  		bit_update(l, 1);
  		bit_update(r + 1, -1);
  	}
  	
  	vll t(n);
  	for(ll i = 1; i <= n; i++) {
  		t[i-1] = bit_query(i);
  	}
  	
  	sort(t.rbegin(), t.rend());
  	ll res = 0;
  	for(ll i = 0; i < n; i++) res += (v[i] * t[i]);
  	
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