/* Approach --->
   First, we split the graph into SCCs. We then treat each component as a node. So then, If the 
   coin collector enters a component, he can collect all the coins in it.
   Since the resulting graph is a DAG, we can use DP to find the maximum coins that can be collected.
*/

// Problem: Coin Collector
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1686
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 04-03-2021 10:58:02 IST (UTC+05:30)
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

vvi g; // adjacency list representation of graph
vvi rg; // to store the reverse graph

// cd[i] stores all the component numbers adjacent to 
// the component number i 
// Basically cd is used to form the condensation graph.
// For def. of condensation graph,
// visit: https://cp-algorithms.com/graph/strongly-connected-components.html 
vector<unordered_set<int>> cd;

vector<bool> vis; // visited array

// if there exists a path from vertex 'x' to 'y' in the DFS tree generated
// of the original graph then in the order vector 'y' must come before 'x'
vi order, coins;

// to store the component number of each vertex
vi comp; 

// sum[i] = total sum of all the coins in the nodes present
// in the ith SCC
vll sum;

int n, m;

void dfs1(int cur) {
	vis[cur] = 1;
	
	for(auto x: g[cur]) {
		if(!vis[x]) dfs1(x);
	}
	
	order.pb(cur);
}

void dfs2(int cur, int col) {
	vis[cur] = 1;
	comp[cur] = col;
	
	for(auto x: rg[cur]) {
		if(!vis[x]) dfs2(x, col);
	}
}

void solve()
{
  	// n = #vertices, m = #edges
  	cin >> n >> m;
  	
  	// resizing all the initializations
  	g.resize(n + 1);
  	rg.resize(n + 1);
  	cd.resize(n + 1);
  	vis.assign(n + 1, 0);
  	coins.resize(n + 1);
  	comp.resize(n + 1);
  	sum.resize(n + 1, 0LL);
  	
  	// input the coins in each vertex
  	for(int i = 1; i <= n; i++) cin >> coins[i];  
  	
  	// inout the edges	
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v); // store in graph
  		rg[v].pb(u); // store in reverse graph
  	}
  	
  	// perform dfs on the original graph so as 
  	// to construct the order vector
  	for(int i = 1; i <= n; i++) {
  		if(!vis[i]) dfs1(i);
  	}
  	
  	// again perform dfs on the reverse graph to 
  	// find out the strongly connected components
  	fill(begin(vis), end(vis), 0);
  	
  	// to mark the vertices belonging to the same SCC with
  	// the same color (or number)
	  int col = 1;
  	
  	// start from the last vertex of order vector
  	for(int i = n - 1; i >= 0; i--) {
  		int x = order[i];
  		
  		if(!vis[x]) {
  			dfs2(x, col);
  			col++;
  		}
  	}
  	
  	// find out the sum of all the coins present in the
  	// each of the SCC
  	for(int i = 1; i <= n; i++) {
  		sum[comp[i]] += coins[i];
  	}
  	
  	// constructing the condensation graph (which is a DAG)
  	for(int i = 1; i <= n; i++) {
  		for(auto j: g[i]) {
  			if(comp[i] != comp[j]) cd[comp[i]].insert(comp[j]);
  		}
  	}
  	
  	vi v;
  	fill(begin(vis), end(vis), 0);
  	
  	while(!order.empty()) {
  		int x = order.back();
  		order.pop_back();
  		
  		if(!vis[comp[x]]) {
  			v.pb(comp[x]);
  			vis[comp[x]] = 1;
  		}
  	}
  	
  	while(!v.empty()) {
  		int k = v.back();
  		v.pop_back();
  		ll mx = sum[k];
  		
  		for(auto nbr_comp: cd[k]) {
  			mx = max(mx, sum[k] + sum[nbr_comp]);
  		}
  		
  		sum[k] = mx;
  	}
  	
  	cout << *max_element(sum.begin() + 1, sum.begin() + col) << "\n";
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