// Problem: D. Checkposts
// Contest: Codeforces - Training Contest #017
// URL: https://codeforces.com/gym/342417/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 29-08-2021 15:22:10 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
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
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

/*******************************************************************************************************************************************************************/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const ll mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

const int N = 100005;
int n, m;

vi g[N]; // adjacency list representation of graph
vi rg[N]; // to store the reverse graph
vi vis(N); // visited array
vll cost(N);

// to store the component of each vertex
// in_comp[i] stores all the vertices in the ith component
vi in_comp[N]; 

// if there exists a path from vertex 'x' to 'y' in the DFS tree generated
// of the original graph then in the order vector 'y' must come before 'x'
vi order;

void dfs(int curr) {
	vis[curr] = 1;
	for(auto x: g[curr]) {
		if(!vis[x]) dfs(x);
	}
	
	order.pb(curr);
}

void dfs_reverse(int curr, int col) {
	vis[curr] = 1;
	in_comp[col].pb(curr); // put it in the component
	for(auto x: rg[curr]) {
		if(!vis[x]) dfs_reverse(x, col);
	}
}

// https://codeforces.com/blog/entry/12082
void solve()
{
  	cin >> n;
  	vset(cost, n + 1, 0LL);
  	for(int i = 1; i <= n; i++) cin >> cost[i];
  	
  	cin >> m;
  	
  	// vertices are 1-based indexed
  	for(int i = 0; i < m; i++) {
  		int x, y; cin >> x >> y;
  		g[x].pb(y); // store in graph
  		rg[y].pb(x); // store in reverse graph
  	}
  	
  	// mark all vertices as not visited initially
  	fill(vis.begin(), vis.end(), 0);
  	
  	// perform dfs on the original graph so as 
  	// to construct the order vector
  	for(int vertex = 1; vertex <= n; vertex++) {
  		if(!vis[vertex]) {
  			dfs(vertex);
  		}
  	}
  	
  	// again perform dfs on the reverse graph to 
  	// find out the strongly connected components
  	fill(vis.begin(), vis.end(), 0);
  	
  	// to mark the vertices belonging to the same SCC with
  	// the same color
  	int col = 1;
  	
  	ll mn_cst = 0LL, ways = 1LL;
  	
  	// start from the last vertex of order vector
  	for(int i = n - 1; i >= 0; i--) {
  		if(!vis[order[i]]) {
  			dfs_reverse(order[i], col);
  			
  			if(in_comp[col].size() > 0) { 
  				vll c;
  				for(auto it = in_comp[col].begin(); it != in_comp[col].end(); it++) {
  					c.pb(cost[*it]);
  			    }
  			    
  			    sort(c.begin(), c.end());
  			    mn_cst += c[0];
  			    ways = (ways * count(c.begin(), c.end(), c[0])) % mod;
  			}
  			
  			col++;
  		}
  	}
  	
  	cout << mn_cst << " " << ways << "\n";
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