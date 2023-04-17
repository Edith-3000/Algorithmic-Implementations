// Prob: https://leetcode.com/problems/minimize-the-total-price-of-the-trips/description/

// Ref: https://www.youtube.com/watch?v=Epd0sEIyHrM&ab_channel=codingMohan

/****************************************************************************************************************************************************************/

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

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// to store the input tree
vvi g;

// to store the parent and depth of each node
vi parent, depth;

// n = #vertices, m = #edges
int n, m;

int WITH_HALF = 0, WITHOUT_HALF = 1;

void dfs(int cur, int par, int dep) {
	parent[cur] = par;
	depth[cur] = dep;
	
	for(auto nbr: g[cur]) {
		if(nbr == par) continue;
		dfs(nbr, cur, dep + 1);
	}
}

vi extract_path(int u, int v) {
	vi path;
	
	if(depth[u] < depth[v]) {
		swap(u, v);
	}
	
	while(depth[u] != depth[v]) {
		path.pb(u);
		u = parent[u];
	}
	
	while(u != v) {
		path.pb(u);
		path.pb(v);
		u = parent[u];
		v = parent[v];
	}
	
	path.pb(u); // or path.pb(v);
	
	return path;
}

void dfs_min_cost(int cur, int par, vi &contri, vvi &min_cost) {
	for(auto nbr: g[cur]) {
		if(nbr == par) continue;
		dfs_min_cost(nbr, cur, contri, min_cost);
	}
	
	// with half contribution of the current node
	min_cost[cur][WITH_HALF] = contri[cur] / 2;
	
	for(auto nbr: g[cur]) {
		if(nbr == par) continue;
		min_cost[cur][WITH_HALF] += min_cost[nbr][WITHOUT_HALF];
	}
	
	// without half contribution of the current node
	min_cost[cur][WITHOUT_HALF] = contri[cur];
	
	for(auto nbr: g[cur]) {
		if(nbr == par) continue;
		min_cost[cur][WITHOUT_HALF] += min(min_cost[nbr][WITHOUT_HALF], min_cost[nbr][WITH_HALF]);
	}
}

int minimum_total_price(vvi &edges, vi &price, vvi &trips) {
	g.clear();
	g.resize(n);
	
	parent.clear();
	parent.resize(n);
	
	depth.clear();
	depth.resize(n);
	
	for(int i = 0; i < m; i++) {
		int x = edges[i][0], y = edges[i][1];
		g[x].pb(y);
		g[y].pb(x);
	}
	
	// calculate parent & depth of each node via DFS, by rooting the tree at any node (here 0)
	dfs(0, -1, 0);

	// max contribution (w/o halving) of each node in the final result
	vi contri(n, 0);
	
	for(int i = 0; i < sz(trips); i++) {
		int x = trips[i][0], y = trips[i][1];
		
		vi path = extract_path(x, y);
		
		for(auto node: path) {
			contri[node] += price[node];
		}
	}
	
	vvi min_cost(n, vi(2));
	
	dfs_min_cost(0, -1, contri, min_cost);
	
	int res = min(min_cost[0][WITH_HALF], min_cost[0][WITHOUT_HALF]);
	
	return res;
}

void solve()
{
  	cin >> n;
  	m = n - 1;
  	
  	vvi edges(m, vi(2));
  	
  	for(int i = 0; i < m; i++) {
  		cin >> edges[i][0] >> edges[i][1];
  	}
  	
  	vi price(n);
  	for(int i = 0; i < n; i++) cin >> price[i];
  	
  	int k; cin >> k;
  	
  	vvi trips(k, vi(2));
  	
  	for(int i = 0; i < k; i++) {
  		cin >> trips[i][0] >> trips[i][1];
  	}
  	
  	int res = minimum_total_price(edges, price, trips);
  	
  	cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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