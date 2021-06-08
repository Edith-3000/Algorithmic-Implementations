// Ref: https://www.geeksforgeeks.org/find-any-simple-cycle-in-an-undirected-unweighted-graph/
// For definition of simple cycle refer the link above.
/******************************************************************************************************/

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
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// to store the i/p graph
vvi g;

// visited & parent vectors
// res is used to store the simple cycle iff exist
vi vis, parent, res;

// n = #vertices, m = #edges
// st = start of the simple cycle
// ed = end of the simple cycle
int n, m, st, ed;

// DFS function to detect if the graph contains a cycle or not
bool is_cycle(int cur, int par) {
	vis[cur] = 1;
	
	for(auto child: g[cur]) {
		if(!vis[child]) {
			if(is_cycle(child, cur)) return 1;
		}
		
		else if(child != par) {
			// a cycle is detected, so marking the start & end
			st = child, ed = cur;
			return 1;
		}
	}
	
	return 0;
}

// BFS function to get the simple cycle from the start & end
// vertices of the cycle we found from DFS helper function (is_cycle())
void find_simple_cycle() {
	queue<int> q;
	q.push(st);
	
	vis[st] = 1;
	bool reached = 0;
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for(auto child: g[cur]) {
			// ignoring the direct edge b/w start and end vectices
			if(cur == st and child == ed) continue;
			
			if(!vis[child]) {
				vis[child] = 1; q.push(child);
				
				// updating the parent array
				parent[child] = cur;
				
				if(child == ed) { reached = 1; break; }
			}
		}
		
		if(reached) break;
	}
	
	res.pb(st);
	int x = ed;
	
	while(x != st) {
		res.pb(x);
		x = parent[x];
	}
}

void solve()
{
  	cin >> n >> m;
  	
  	g.clear(); g.resize(n);
  	vis.clear(); vis.resize(n, 0);
  	parent.clear(); parent.resize(n, -1);
  	res.clear();
  	
  	// vertices are 0-based indexed
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v); g[v].pb(u);
  	}
  
  	if(is_cycle(0, -1)) { 
  		// resetting the visited array for simple cycle finding
  		for(int i = 0; i < n; i++) vis[i] = 0;
  		
  		// BFS approach to find the actual cycle
  		find_simple_cycle();
  		
  		for(auto x: res) cout << x << " ";
  		cout << "\n";
  	}
  	
  	else cout << "No cycle present.\n";
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