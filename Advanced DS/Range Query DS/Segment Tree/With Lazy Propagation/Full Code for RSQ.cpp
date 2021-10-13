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

// input array[] for which Segment Tree will be build
vll v;

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
	
	// p is the index in v[] at which update is to be done
	void point_update(int tl, int tr, int p, ll delta, int ind) {
		// base case(s)
		// case to handle when p is out of bounds of the current segment
		if((p < tl) or (p > tr)) {
			return;
		}
		
		// in leaf node, perform update 
		if(tl == tr) {
			t[ind] += delta;
			return;
		}
		
		int m = (tl + tr) / 2;
		point_update(tl, m, p, delta, 2 * ind);
		point_update(m + 1, tr, p, delta, 2 * ind + 1);
		t[ind] = t[2 * ind] + t[2 * ind + 1];
		
		return;
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

void solve()
{
  	int n; cin >> n;
  	vset(v, n, 0LL);
  	
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	struct seg_tree st(n);
  	st.build(0, n - 1, 1);
  	  	
  	int q; cin >> q;
  	
  	// use 0-based indices for queries and updates
  	while(q--) {
  		// typ == 1 : range query. typ == 2 : point update. typ == 3 range update
  		int typ; cin >> typ;
  		
  		if(typ == 1) {
  			int l, r; cin >> l >> r;
  			cout << "For range [" << l << ", " << r << "] = ";
  			cout << st.range_query(0, n - 1, l, r, 1) << "\n";
  		}
  		
  		else if(typ == 2) {
  			int idx; ll delta; cin >> idx >> delta;
  			st.point_update(0, n - 1, idx, delta, 1);
  		}
  		
  		else {
  			int l, r; cin >> l >> r;
  			ll delta; cin >> delta;
  			st.range_update(0, n - 1, l, r, delta, 1);
  		}
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

/* # Time complexities of functions of struct seg_tree :--->

     * build(): O(n), since we fill all (4 x n) vertices of the Segment Tree.

     * range_query(): O(log(n)), it is so because in this operation we traverse the segment tree from 
                      top to bottom (in worst case) for few paths(branches) & each path contain log(n) 
                      #nodes [as the height of Segment Tree is O(log(n)].
                      OR
                      A nice explanation given on the link: 
                      https://www.quora.com/How-do-we-prove-that-the-time-complexity-of-the-update-and-query-operations-in-a-segment-tree-are-Theta-lg-n 

     * point_update(): O(log(n))

     * range_update(): O(log(n))
*/