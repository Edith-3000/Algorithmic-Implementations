// Ref: https://www.youtube.com/watch?v=WXMnRa3NkTQ
/***********************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())
#define vset(v, n, val) v.clear(); v.resize(n, val)

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(queue <T> v);
template <class T> void _print(priority_queue <T> v);
template <class T> void _print(stack <T> s);

// modify it's definition below as per need such as it can be used for STL containers with custom args passed
template <class T> void _print(T v); 

template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(multimap <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.front()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(priority_queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(stack <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(T v) {  }

/*******************************************************************************************************************************************************************/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// to store the input tree
vvi g;

// n = #nodes, m = #edges in tree
int n, m;

struct LCA {
	// data members
	
	// n = #rows, m = #columns in mat[][]
	// NOTE: nodes are 0-based indexed
	int n, m;
	
	// 2D matrix s.t. mat[i][j] will store the (2^j)th parent of node i in the 
	// dfs tree of the graph
	vvi mat;
	
	// to store depth of each vertex (root being at depth = 0)
	vi dep;
	
	// member functions
	void init(int _n) {
		n = _n;
		m = ceil(log2(n)) + 1;
		
		mat.clear(); mat.resize(n);
		for(int i = 0; i < n; i++) mat[i].resize(m);
		
		dep.clear(); dep.resize(n);
	}
	
	void build() {
		// dfs function to store the immediate parent & level of every node in the tree,
		// ASSUMING THE TREE TO BE ROOTED AT NODE 0 (IF REQUIRED CHANGE ROOT)
		dep[0] = 0;
		DFS(0, -1);
		
		// NOTE: do not make the parent of '0' as '-1', since it may lead to runtime error
		//       while calculating mat[][]
		mat[0][0] = 0;
		
		for(int j = 1; j < m; j++) { 
			for(int i = 0; i < n; i++) {
				// (2^j)th parent of node i = (2^(j-1))th parent of the (2^(j-1))th parent of i
				//                            since (2^(j-1)) + (2^(j-1)) = (2^j)
				int x = mat[i][j - 1];
				mat[i][j] = mat[x][j - 1];
			} 
		} 
	}
	
	void DFS(int cur, int par) {
		mat[cur][0] = par;
		for(auto x: g[cur]) {
			if(x == par) continue;
			dep[x] = dep[cur] + 1;
			DFS(x, cur);
		}
	}
	
	// returns the kth ancestor of node, if k is beyond the height of 
	// tree it returns the root node
	int lift_node(int node, int k) {
		int j = 0;
		while(k > 0) {
			if(k & 1) node = mat[node][j];
			k >>= 1;
			j += 1;
		}
		
		return node;
	}
	
	// finds the LCA of 2 nodes a & b
	int find_lca(int a, int b) {
		// considering b to be always at greater depth
		if(dep[a] > dep[b]) swap(a, b);
		
		// bringing both the nodes at the same depth
		int diff = dep[b] - dep[a];
		b = lift_node(b, diff);
		
		// now a & b are at the same depth
		// return if both at same node
		if(a == b) return a;
		
		// try to move nodes a & b upwards s.t. both are JUST below their LCA
		for(int i = m - 1; i >= 0; i--) {
			if(mat[a][i] != mat[b][i]) {
				a = mat[a][i];
				b = mat[b][i];
			}
		}
		
		return mat[a][0]; // or mat[b][0]
	}
};

void solve()
{
  	cin >> n >> m;
  	vset(g, n, vi(0));
  	
  	// 0-based indexing of nodes is used
  	for(int i = 0; i < m; i++) {
  		int x, y; cin >> x >> y;
  		g[x].pb(y);
  		g[y].pb(x);
  	}
  	
  	struct LCA lca;
  	lca.init(n);
  	lca.build();
  	
  	int q; cin >> q;
  	
  	// use 0-based indexing of node
  	while(q--) {
  		int a, b; cin >> a >> b;
  		int ans = lca.find_lca(a, b);
  		cout << "LCA of " << a << " & " << b << ": " << ans << "\n";
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
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
    // #endif
    
    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}

// Time complexity of find_lca() : O(log(n)), where n are the #nodes in the tree.

// NOTE: However the find_lca() function could also be implemented s.t. it works in O(1) time with
//       some precomputations making use of Euler Tour on a tree, RMQ using Sparse Table on the Euler
//       Tour obtained & some other things, but it becomes quiet implementation heavy.
//       The method's explanation can be found here :--->
//       https://www.youtube.com/watch?v=P8NHOmX5XGM