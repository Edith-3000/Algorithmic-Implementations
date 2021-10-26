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
const int N = 1000000, M = 21; // M = ceil(log2(N)) + 1

vi g[N]; // to store the original graph
vi dep(N); // to store depth of each vertex (root being at depth = 0)

// it is the sparse table such that mat[i][j] will
// store the (2^j)th parent of node i in the dfs tree 
// of the graph
vvi mat(N, vi(M, 0)); 

// simple way of dfs & nothing else
// only used to store the depths of all nodes in the traversal
// variable par is used in dfs traversal instead of making a visited array
// REMEMBER: This type of DFS methos works only when we are sure that there is
//           NO CYCLE in the graph, otherwise it will give RUNTIME ERROR
// As in this problem input graph is tree or a DAG thereby it won't have any cycles.
void dfs(int curr, int par) {
	for(auto x: g[curr]) {
		if(x != par) {
			dep[x] = dep[curr] + 1;
			dfs(x, curr);
		}
	}
} 					 

// this function is also a simple type of dfs only
void cal_sparse_table(int curr, int par) {
	mat[curr][0] = par;
	for(int j = 1; j < M; j++) {
		mat[curr][j] = mat[mat[curr][j - 1]][j - 1];
	}
	
	for(auto x: g[curr]) {
		if(x != par) {
			cal_sparse_table(x, curr);
		}
	}
}

int lca_using_depth(int u, int v) {
	// corner case 
	if(u == v) return u;
	
	// considering u to be always at greater depth
	if(dep[u] < dep[v]) swap(u, v);
	
	// bringing both the pointers at the same depth
	int diff = dep[u] - dep[v];
	for(int i = M - 1; i >= 0; i--) {
		if((diff >> i) & 1) { // or (1 << i) <= diff
			u = mat[u][i];
		}
	}
	
	// corner case
	if(u == v) return u;
	
	for(int i = M - 1; i >= 0; i--) {
		if(mat[u][i] != mat[v][i]) {
			u = mat[u][i];
			v = mat[v][i];
		}
	}
	
	return mat[u][0]; // or mat[v][0]
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
  	
  	// performing simple dfs to store the depth
  	// of each vertex in the dfs tree of the graph
  	dfs(root, 0);
  	
  	// now fill up the sparse table mat
  	cal_sparse_table(root, 0); // parent of root is passed as 0
  	
  	// vertices whose LCA to be found out
  	int u, v; cin >> u >> v;
  	cout << "LCA of " << u << " & " << v << " = " << lca_using_depth(u, v) << "\n";
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

LCA of 15 & 19 = 3

*/

// Time complexity analysis ---->
// dfs() function take O(n) time.
// cal_sparse_table() fills the sparse table mat of size (n x m), where m is O(log2(n)), therefore
//                    overall time of filling sparse table is O(n x log2(n)). 
//                    [See Sparse Table DS for more info]

// lca_using_depth() takes O(M) =~ O(log2(n))

// Therefore preprocessing takes O(n x log2(n)) & answering queries (finding LCA of 2 nodes)
// takes O(log2(n)) time.
// Here n = #vertices in the i/p undirected tree or DAG.

// Special NOTE : The only difference between lca_using_depth() used in this approach & lca_brute()
//                used in the "Finding LCS By 2 Pointer Approach (O(n)) Time.cpp" is that in the latter
//                we were reaching to the LCS in 'n' steps while in the former we accomplished this
//                in O(log2(n)) steps by binary lifting (or by exploiting the fact that every number
//                can be represented as the summation of powers of 2).