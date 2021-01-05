// Problem: F - Close Group
// Contest: AtCoder - AtCoder Beginner Contest 187
// URL: https://atcoder.jp/contests/abc187/tasks/abc187_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// Parsed on: 05-01-2021 23:44:06 IST (UTC+05:30)
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

int dp[(1 << 18)];
bool good[(1 << 18)];
bool edge[18][18];
int n, m;

void solve()
{
	memset(edge, 0, sizeof(edge));
	memset(good, true, sizeof(good));
  	cin >> n >> m;
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		edge[--u][--v] = 1;
  		edge[v][u] = 1;
  	}
  	
  	if(m == 0) { cout << n; return; }
  	
  	for(int mask = 1; mask < (1 << n); mask++) {
  		vi tmp;
  		for(int j = 0; j < n; j++) {
  			if(mask & (1 << j)) tmp.pb(j);
  		}
  		
  		for(int k = 0; k < tmp.size(); k++) {
  			for(int kk = k + 1; kk < tmp.size(); kk++) {
  				if(!edge[tmp[k]][tmp[kk]]) good[mask] = false;
  			}
  		}
  	}
  	
  	for(int mask = 1; mask < (1 << n); mask++) dp[mask] = INF;
  	dp[0] = 0;
  	
  	for(int mask = 1; mask < (1 << n); mask++) {
  		if(good[mask]) dp[mask] = 1;
  		else {
  			// standard method of iterating over all the submasks of a given mask
  			for(int submask = mask; submask; submask = (submask - 1) & mask) {
  				dp[mask] = min(dp[mask], dp[submask] + dp[submask ^ mask]);
  			}
  		}
  	}
  	
  	cout << dp[(1 << n) - 1];
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

// Time complexity: https://atcoder.jp/contests/abc187/editorial/500
// USEFUL LINK: https://cp-algorithms.com/algebra/all-submasks.html