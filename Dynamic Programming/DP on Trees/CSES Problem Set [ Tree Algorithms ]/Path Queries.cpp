// Ref: https://www.youtube.com/watch?v=P8NHOmX5XGM&t=1850s
/******************************************************************************************************/

// Problem: Path Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1138
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 27-10-2021 16:14:16 IST (UTC+05:30)
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
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())
#define vset(v, n, val) v.clear(); v.resize(n, val)
#define int ll

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

// void _print(ll t) { cerr << t; }
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

vvi g;
vi val;
int n, q;

// structure for creating euler tour of a tree
// NOTE: there are many ways to create en euler tour, in this way
//       each node comes exactly twice in the tour
struct euler_tour {
	// data members
	
	// n = #nodes in tree, timer is used to explore tree
	int n, timer; 
	
	// tin[i] = in time of ith vertex, tout[i] = out time of ith vertex
	vi tin, tout;
	
	// et[i] stores the info of certain vertex at the ith time, the info to be stored depends 
	// on the problem, also it's size depends on the type of implementation of euler tour
	vi et;
	
	// member functions
	euler_tour(int _n) {
		n = _n;
		
		// the below initializations depends on type of euler tour implemented
		timer = 1;
		tin.clear(); tin.resize(n + 1);
		tout.clear(); tout.resize(n + 1);
		et.clear(); et.resize(2 * n + 1);
	}
	
	void build() {
		// assuming the tree to be rooted at node 1, change if required
		DFS(1, -1);
	}
	
	void DFS(int cur, int par) {
		tin[cur] = timer;
		et[timer] = val[cur]; // change the info to be stored as required
		timer++;
		
		for(auto x: g[cur]) {
			if(x == par) continue;
			DFS(x, cur);
		}
		
		tout[cur] = timer;
		et[timer] = -val[cur];
		timer++;
	}
};

// input array[] for which Fenwick Tree will be build
vll v;

// Change functions accordingly when needed, here functions are coded for
// range sum queries & point update

// NOTE: everything is 1-based indexed in fenwick_tree
// Fenwick Tree structure for range queries & point updates
struct fenwick_tree {
	// data members ==>
	int n;
	vll bit;
	
	// member functions ===>
	
	// constructor
	fenwick_tree(int n) {
		this->n = n;
		bit.clear();
		bit.resize(n + 1);
	}
	
	// to seed the bit[] array with some initial value
	void init() {
		bit[0] = 0LL;
		for(int i = 1; i <= n; i++) bit[i] = 0LL;
	}
	
	// build bit[] using point_update() fn.
	void build() {
		for(int i = 1; i <= n; i++) {
			point_update(i, v[i]);
		}
	}
	
	// fn. to change the value at idx i by delta
	void point_update(int i, ll delta) {
		while(i <= n) {
			bit[i] += delta;
			i += (i & (-i));
		}
	}
	
	// to compute the result for range [l, r] (l & r both inclusive)
	// res[l, r] = fn(res[1, r], res[1, l-1])
	ll range_query(int l, int r) {
		return range_query(r) - range_query(l - 1);
	}
	
	// computes result for range [1, i] (1 & i both inclusive)
	ll range_query(int i) {
		ll res = 0LL;
		while(i > 0) {
			res += bit[i];
			i -= (i & (-i));
		}
		
		return res;
	}
};

void solve()
{
  	cin >> n >> q;
  	vset(g, n + 1, vi(0));
  	vset(val, n + 1, 0);
  	
  	for(int i = 1; i <= n; i++) cin >> val[i];
  	
  	for(int i = 1; i < n; i++) {
  		int x, y; cin >> x >> y;
  		g[x].pb(y);
  		g[y].pb(x);
  	}
  	
  	struct euler_tour e(n);
  	e.build();
  	
  	v = e.et;
  	
  	struct fenwick_tree ft(e.timer);
  	ft.init();
  	ft.build();
  	
  	while(q--) {
  		int tp, node; cin >> tp >> node;
  		
  		if(tp == 1) {
  			int del; cin >> del;
  			int idx1 = e.tin[node], idx2 = e.tout[node];
  			int prev1 = ft.range_query(idx1, idx1);
  			int prev2 = ft.range_query(idx2, idx2);
  			ft.point_update(idx1, del - prev1);
  			ft.point_update(idx2, -del - prev2);
  		}
  		
  		else {
  			int l = e.tin[1], r = e.tin[node];
  			int ans = ft.range_query(l, r);
  			cout << ans << "\n";
  		}
  	}
}

signed main()
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