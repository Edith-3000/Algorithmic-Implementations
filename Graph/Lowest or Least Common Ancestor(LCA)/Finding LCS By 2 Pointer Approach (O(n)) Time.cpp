// Following is a brute force approach to find LCS of 2 nodes in O(n) time, where n = #vertices
// In this approach preprocessing is also done using DFS traversal of the graph to find the depth 
// & parent of each vertex, before finding the LCS of 2 nodes.

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
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
const int N = 100005;

vi g[N]; // to store the undirected tree/graph
vi par(N); // to store parent of each vertex in dfs tree
vi dep(N); // to store depth of each vertex (root being at depth = 0)

int lca_brute(int u, int v) {
	// corner case 
	if(u == v) return u;
	
	// considering u to be always at greater depth
	if(dep[u] < dep[v]) swap(u, v);
	
	// bringing both the pointers at the same depth
	while(dep[u] > dep[v]) {
		u = par[u];
	}
	
  // now both the pointers at the same depth
  // so, moving up till both pointers point to the same node
	while(u != v) {
		u = par[u];
		v = par[v];
	}
	
	return u; // or return v
}

// REMEMBER: This type of DFS methos works only when we are sure that there is
//           NO CYCLE in the graph, otherwise it will give RUNTIME ERROR
// As in this problem input graph is tree or a DAG thereby it won't have any cycles.
void dfs(int curr, int parent) {
	par[curr] = parent;
	for(auto x: g[curr]) {
		if(x != parent) {
			dep[x] = dep[curr] + 1;
			dfs(x, curr);
		}
	}
}

void solve()
{
  	// input is an undirected tree with n vertices (1-based indexed)
  	// thereby will have (n-1) edges
  	int n; cin >> n;
  	for(int i = 1; i < n; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v);
  		g[v].pb(u);
  	}
  	
  	// root of the tree
  	int root; cin >> root;
  	
  	// preprocessing to store depth & parent of each vertex
  	dep[root] = 0;
  	dfs(root, 0); // passing parent of root vertex as 0	
  	
  	// vertices whose LCA to be found out
  	int u, v; cin >> u >> v;
  	cout << "LCA of " << u << " & " << v << " = " << lca_brute(u, v) << "\n";
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

/*

Sample i/p --->

19
1 2
2 4
2 5
5 6
6 7
6 8
6 9
1 3
3 10
3 11
10 17
17 18
17 19
11 12
12 13
12 14
12 15
15 16
1
2 9

Sample o/p --->

LCA of 2 & 9 = 2

*/

// Time complexity: O(n), where n = #vertices in the graph