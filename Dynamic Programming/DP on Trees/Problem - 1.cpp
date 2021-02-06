// Problem: D. Distance in Tree
// Contest: Codeforces - VK Cup 2012 Round 1
// URL: https://codeforces.com/problemset/problem/161/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// Parsed on: 06-02-2021 15:52:47 IST (UTC+05:30)
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

// input tree
vi tree[50001];

// dp1[i][x] = the #nodes which are at a distance of 'x' (from
// node 'i') in the subtree rooted at node 'i'
int dp1[50001][501];

// dp1[i][x] = the #nodes which are at a distance of 'x' (from
// node 'i') in the complete tree
int dp2[50001][501];

// input parameters
int n, k;

void dfs(int curr, int par) {
	dp1[curr][0] = 1;
	
	for(int child: tree[curr]) {
		if(child != par) dfs(child, curr);
	}
	
	for(int dist = 1; dist <= k; dist++) {
		dp1[curr][dist] = 0;
		for(auto child: tree[curr]) {
			if(child != par) dp1[curr][dist] += dp1[child][dist - 1];
		}
	}
}

void driver(int curr, int par) {
	for(int dist = 0; dist <= k; dist++) {
		dp2[curr][dist] = dp1[curr][dist];
	}
	
	// i.e. if it is not the root node (1)
	if(par != 0) {
		dp2[curr][1] += 1;
		for(int dist = 2; dist <= k; dist++) {
			dp2[curr][dist] += dp2[par][dist - 1];
			dp2[curr][dist] -= dp1[curr][dist - 2];
		}
	}
	
	for(int child: tree[curr]) {
		if(child != par) driver(child, curr);
	}
}

void solve()
{
  	cin >> n >> k;
  	for(int i = 1; i < n; i++) {
  		int u, v; cin >> u >> v;
  		tree[u].pb(v);
  		tree[v].pb(u);
  	}
  	
  	dfs(1, 0);
  	driver(1, 0);
  	
  	ll res = 0;
  	for(int i = 1; i <= n; i++) res += dp2[i][k];
  	cout << res/2 << "\n";
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