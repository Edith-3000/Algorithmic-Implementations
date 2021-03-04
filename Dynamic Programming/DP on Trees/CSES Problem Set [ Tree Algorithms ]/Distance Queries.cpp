// Problem: Distance Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1135
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 03-03-2021 10:25:31 IST (UTC+05:30)
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

vi tree[200001];
int up[200001][20];
int lvl[200001];
int n, q;

void dfs(int src, int par, int level = 0) {
	lvl[src] = level;
	
	for(auto child: tree[src]) {
		if(child != par) {
			dfs(child, src, level + 1);
		}
	}
}

void binary_lifting(int src, int par) {
	up[src][0] = par;
	
	for(int i = 1; i < 20; i++) {
		if(up[src][i-1] != -1) {
			up[src][i] = up[up[src][i-1]][i-1];
		}
		
		else up[src][i] = -1;
	}
	
	for(auto child: tree[src]) {
		if(child != par) {
			binary_lifting(child, src);
		}
	}
}

// This function is exactly same as the "process_query()" function in "Company Queries I.cpp".
// Only difference is the recusrive and iterative implementations.
int lift_node(int node, int jump_required) {
	for(int i = 19; i >= 0; i--) {
		if(node == -1 || jump_required == 0) {
			break;
		}
		
		if(jump_required >= (1 << i)) {
			node = up[node][i];
			jump_required -= (1 << i);
		}
	}
	
	return node;
}

// LCA in O(log2(n)) time
int LCA(int u, int v) {
	if(lvl[u] < lvl[v]) {
		swap(u, v);
	}
	
	u = lift_node(u, lvl[u] - lvl[v]);
	
	if(u == v) return u;
	
	for(int i = 19; i >= 0; i --) {
		if(up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	return lift_node(u, 1);
}

void solve()
{
  	cin >> n >> q;
  	for(int i = 2; i <= n; i++) {
  		int u, v; cin >> u >> v;
  		tree[u].pb(v);
  		tree[v].pb(u);
  	}
  	
  	binary_lifting(1, -1);
  	dfs(1, -1);
  	
  	while(q--) {
  		int a, b; cin >> a >> b;
  		int lca = LCA(a, b);
  		cout << (lvl[a] - lvl[lca]) + (lvl[b] - lvl[lca]) << "\n";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}