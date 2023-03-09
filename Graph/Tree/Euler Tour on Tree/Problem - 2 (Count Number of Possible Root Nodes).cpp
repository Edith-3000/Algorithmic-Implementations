// Prob: https://leetcode.com/problems/count-number-of-possible-root-nodes/description/

// Ref: https://www.youtube.com/watch?v=k4PNslLoQTY&ab_channel=codingMohan
//      https://leetcode.com/problems/count-number-of-possible-root-nodes/solutions/3256889/video-explanation-with-intuition-of-every-step/

/********************************************************************************************************************************************************************/

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

// input array[] for which Segment Tree will be build
vi v;

// Change functions accordingly when needed, here functions are coded for range sum queries
// NOTE: this is with lazy propagation 
struct seg_tree {
	// data members ==>
	
	// size of array[] for which segment tree will be build
	int n;
	
	// underlying vector used for representing segment tree in 
	// linear space. An array of size n can have approx. around 
	// (4 * n + 1) nodes in the corresponding segment tree
	vll t;

	// vector to store the lazy values for all the segment tree nodes
	vll lazy;

	// member functions ===>
	
	// constructor
	seg_tree(int n) {
		this->n = n;
		t.clear(); t.resize(4 * n + 1);
		lazy.clear(); lazy.resize(4 * n + 1, 0LL);
	}
	
	// build t[] function where,
	// t[ind] is resposnible for storing result corresponding to segment v[tl......tr]
	void build(int tl, int tr, int ind) {
		// base case
		if(tl == tr) {
			t[ind] = v[tl];
			return;
		}
		
		// similar to postorder traversal
		int m = (tl + tr) / 2;
		
		// compute results for child nodes & after it for the parent node i.e. ind
		build(tl, m, 2 * ind);
		build(m + 1, tr, 2 * ind + 1);
		t[ind] = t[2 * ind] + t[2 * ind + 1];
		
		return;
	}
	
	// The overlaps are of [tl, tr] with respect to [ql, qr]. tl, tr, ql, qr are 0-based indexed
	ll range_query(int tl, int tr, int ql, int qr, int ind) {
		// before going down resolve the lazy value of the current node if it exists
		if(lazy[ind] != 0LL) {
			// include lazy value
			t[ind] += (lazy[ind] * (tr - tl + 1));
			
			// if this node is non-leaf node pass it's lazy value to it's children
			if(tl != tr) {
				lazy[2 * ind] += lazy[ind];
				lazy[2 * ind + 1] += lazy[ind];
			}
			
			// clear the lazy value of current node
			lazy[ind] = 0LL;
		}
		
		// base case(s)
		// Case 1: complete overlap
		if((tl >= ql) and (tr <= qr)) {
			return t[ind];
		}
		
		// Case 2: no overlap
		if((tl > qr) or (tr < ql)) {
			return 0LL;
		}
		
		// Recursive case
		// Case 3: partial overlap
		int m = (tl + tr) / 2;
		ll lf = range_query(tl, m, ql, qr, 2 * ind);
		ll rg = range_query(m + 1, tr, ql, qr, 2 * ind + 1);
		
		return lf + rg;
	}
		
	// The overlaps are of [tl, tr] with respect to [l, r], tl, tr, l, r are 0-based indexed
	void range_update(int tl, int tr, int l, int r, ll delta, int ind) {
		// before going down resolve the lazy value of the current node if it exists
		if(lazy[ind] != 0LL) {
			// include lazy value
			t[ind] += (lazy[ind] * (tr - tl + 1));
			
			// if this node is non-leaf node pass it's lazy value to it's children
			if(tl != tr) {
				lazy[2 * ind] += lazy[ind];
				lazy[2 * ind + 1] += lazy[ind];
			}
			
			// clear the lazy value of current node
			lazy[ind] = 0LL;
		}
		
		// base case(s) 
		
		// Case 1: no overlap
		if((tl > r) or (tr < l)) {
			return;
		}
		
		// Case 2: complete overlap (this is the case where code is being optimized as we are returning
		//         from here w/o actually updating all the nodes in the subtree rooted at node
		//         ind, instead their changed value is just being stored in the lazy array)
		if((tl >= l) and (tr <= r)) {
			t[ind] += (delta * (tr - tl + 1));
			
			// if this node is non-leaf node pass it's lazy value to it's children
			if(tl != tr) {
				lazy[2 * ind] += delta;
				lazy[2 * ind + 1] += delta;
			}
			
			return;
		}
	
		// recursive case (Case 3: partial overlap)		
		int m = (tl + tr)/2;
		range_update(tl, m, l, r, delta, 2 * ind);
		range_update(m + 1, tr, l, r, delta, 2 * ind + 1);
		t[ind] = t[2 * ind] + t[2 * ind + 1];
	
		return;
	}
};

// to store the i/p tree
vvi g;

// n = #nodes in the tree
int n;

// structure for creating euler tour of a tree
// NOTE: there are many other ways to create en euler tour
struct euler_tour {
	// data members
	
	// n = #nodes in tree, timer is used to explore tree
	int n, timer; 
	
	// tin[i] = in time of ith vertex, tout[i] = out time of ith vertex
	vi tin, tout;
	
	// et[i] stores the info of certain vertex at the ith time, the info to be stored depends 
	// on the problem, also it's size depends on the type of implementation of euler tour
	vi et;
	
	// parent[i] = parent of ith vertex in Euler Tour traversal
	vi parent;
	
	// member functions
	euler_tour(int _n) {
		n = _n;
		
		// the below initializations depends on type of euler tour implemented
		timer = 0;
		tin.clear(); tin.resize(n);
		tout.clear(); tout.resize(n);
		et.clear(); et.resize(n, 0);
		parent.clear(); parent.resize(n, 0);
	}
	
	void build() {
		// assuming the tree to be rooted at node 0, change if required
		DFS(0, -1);
	}
	
	void DFS(int cur, int par) {
		tin[cur] = timer;
		parent[cur] = par;
		
		for(auto x: g[cur]) {
			if(x == par) continue;
			timer += 1;
			DFS(x, cur);
		}
		
		tout[cur] = timer;
	}
};

int root_count(vvi &edges, vvi &guesses, int k) {
	g.clear();
	g.resize(n);
	
	for(int i = 0; i < (n - 1); i++) {
		int x = edges[i][0], y = edges[i][1];
		g[x].pb(y);
		g[y].pb(x);
	}
	
	struct euler_tour e(n);
  	e.build();
  	
  	vset(v, n, 0LL);
  	v = e.et;
  	
  	struct seg_tree st(n);
  	st.build(0, n - 1, 1);
  	
  	int m = sz(guesses);
  	
  	for(int i = 0; i < m; i++) {
  		int x = guesses[i][0], y = guesses[i][1];
  		
  		if(x == e.parent[y]) {
  			st.range_update(0, n - 1, 0, n - 1, 1, 1);
  			st.range_update(0, n - 1, e.tin[y], e.tout[y], -1, 1);
  		}
  		
  		else {
  			st.range_update(0, n - 1, e.tin[x], e.tout[x], 1, 1);
  		}
  	}
  	
  	int res = 0;
  	
  	for(int i = 0; i < n; i++) {
  		int valid_guesses = st.range_query(0, n - 1, i, i, 1);
  		if(valid_guesses >= k) res += 1;
  	}
  	
  	return res;
}

void solve()
{
  	cin >> n;
  	
  	vvi edges(n - 1, vi(2));
  	
  	for(int i = 0; i < (n - 1); i++) {
  		cin >> edges[i][0] >> edges[i][1];
  	}
  	
  	int m; cin >> m;
  	
  	vvi guesses(m, vi(2));
  	
  	for(int i = 0; i < (n - 1); i++) {
  		cin >> guesses[i][0] >> guesses[i][1];
  	}
  	
  	int k; cin >> k;
  	
  	int res = root_count(edges, guesses, k);
  	
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