// In this method we will be calculating LCS by making use of time-in & time-out concept rather than using 
// depth (which was done in "Finding LCS By Binary Lifting & Sparse Table Approach (O(log2(n)) Time - 1.cpp")

// Code is almost similar except few changes and additionally calculating time-in & time-out of all nodes
// while performing dfs traversal of the input graph.

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

int timer;
vi g[N]; // to store the original graph
vi tin(N); // to store time-in of each vertex 
vi tout(N); // to store time-out of each vertex

// it is the sparse table such that mat[i][j] will
// store the (2^j)th parent of node i in the dfs tree 
// of the graph
vvi mat(N, vi(M, 0)); 

// simple way of dfs & nothing else
// only used to store the time-in & time-out of all nodes in the traversal
// variable par is used in dfs traversal instead of making a visited array
// simple way of dfs & nothing else
// only used to store the depths of all nodes in the traversal
// variable par is used in dfs traversal instead of making a visited array
// REMEMBER: This type of DFS methos works only when we are sure that there is
//           NO CYCLE in the graph, otherwise it will give RUNTIME ERROR
// As in this problem input graph is tree or a DAG thereby it won't have any cycles.
void dfs(int curr, int par) {
	tin[curr] = ++timer;
	for(auto x: g[curr]) {
		if(x != par) {
			dfs(x, curr);
		}
	}
	
	tout[curr] = timer;
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

// function to check if u is an ancestor of v or not
bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca_using_time(int u, int v) {
	// corner cases
	if(u == v) return u;
	if(is_ancestor(u, v)) return u;
	if(is_ancestor(v, u)) return v;
	
	// if mat[u][i] is an ancestor of v, then do nothing
	// else move u upwards
	for(int i = M - 1; i >= 0; i--) {
		if(!is_ancestor(mat[u][i], v)) {
			u = mat[u][i];
		}
	}
	
	return mat[u][0];
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
  	
  	// 0 being the universal parent(i.e. parent of the root)
  	// initialising it's tin & tout value firstly
  	tin[0] = 0; tout[0] = n + 1;
  	
  	// performing simple dfs to store the time-in & time-out
  	// values of each vertex in the dfs tree of the graph
  	dfs(root, 0);
  	
  	// now fill up the sparse table mat
  	cal_sparse_table(root, 0); // parent of root is passed as 0
  	
  	// vertices whose LCA to be found out
  	int u, v; cin >> u >> v;
  	cout << "LCA of " << u << " & " << v << " = " << lca_using_time(u, v) << "\n";
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

LCA of 4 & 9 = 2

*/

// Time complexity: Similar to "Finding LCS By Binary Lifting & Sparse Table Approach (O(log2(n)) Time - 1.cpp"