// Problem: Given a weighted undirected tree with vertices from 1 to n. Your task is to find the length of
//          path b/w given 2 vertices u & v.

/********************************************************************************************************/

/* # This problem can be easily done LCA concept.
   # Let us assume LCA(u, v) = z
     then len(u, v) = len(u, z) + len(v, z), as it's a tree.

   # Now length between 2 vertices can be easily precomputed by calculating length of each vertex from
     the root, for eg. taking root as vertex 1, then ---->
     len(u, z) = len(1, u) - len(1, z), 
     similarly len(v, z) = len(1, v) - len(1, z), 
	
   # Therefore len(u, v) = len(1, u) + len(1, v) - 2 * len(1, z)
*/

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
vpii g[N]; // to store the original tree
vi tin(N); // to store time-in of each vertex 
vi tout(N); // to store time-out of each vertex
vi dis(N); // to store the length of path from root to every vertex

// it is the sparse table such that mat[i][j] will
// store the (2^j)th parent of node i in the dfs tree 
// of the graph
vvi mat(N, vi(M, 0)); 

// simple way of dfs & nothing else
// only used to store the time-in, time-out & dis of all nodes in the traversal
// variable par is used in dfs traversal instead of making a visited array
void dfs(int curr, int par) {
	tin[curr] = ++timer;
	for(auto x: g[curr]) {
		if(x.F != par) {
			dis[x.F] = dis[curr] + x.S;
			dfs(x.F, curr);
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
		if(x.F != par) {
			cal_sparse_table(x.F, curr);
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

int distance(int u, int v) {
	int lca = lca_using_time(u, v);
	return dis[u] + dis[v] - (2 * dis[lca]);
}

void solve()
{
  	// input is an undirected tree with n vertices (1-based indexed)
  	// thereby will have (n-1) edges
  	int n; cin >> n;
  	for(int i = 1; i < n; i++) {
  		int u, v, w; cin >> u >> v >> w;
  		g[u].pb({v, w});
  		g[v].pb({u, w});
  	}
  	  	
  	// 0 being the universal parent(i.e. parent of the root)
  	// initialising it's tin & tout value firstly
  	tin[0] = 0; tout[0] = n + 1;
  	
  	// length of root from itself = 0
  	// taking vertex 1 as root
  	dis[1] = 0;
  	
  	// performing simple dfs to store the time-in, time-out & dis
  	// values of each vertex in the dfs tree of the graph
  	dfs(1, 0);
  	
  	// now fill up the sparse table mat
  	cal_sparse_table(1, 0); // parent of root is passed as 0
  	
  	// vertices b/w which length of the path to be found out
  	int u, v; cin >> u >> v;
  	
  	cout << "Length of path b/w " << u << " & " << v << " = " << distance(u, v) << "\n";
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

Sample i/p ---->

7
1 2 1
2 4 4
2 5 5
5 6 9
1 3 2
3 7 10
4 6

Sample o/p ---->

Length of path b/w 4 & 6 = 18

*/

// Time complexity: Similar to "Finding LCS By Binary Lifting & Sparse Table Approach (O(log2(n)) Time - 2.cpp"