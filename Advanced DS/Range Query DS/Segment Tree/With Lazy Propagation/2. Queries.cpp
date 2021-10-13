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

void build_seg_tree(vi &t, vi &v, int tl, int tr, int ind) {
	if(tl == tr){
		t[ind] = v[tl];
		return;
	}
	
	int mid = (tl + tr)/2;
	
	build_seg_tree(t, v, tl, mid, 2 * ind);
	build_seg_tree(t, v, mid + 1, tr, 2 * ind + 1);
	t[ind] = min(t[2 * ind], t[2 * ind + 1]);
	
	return;
}

void lazy_range_update_seg_tree(vi &t, vi &lazy, int tl, int tr, int l, int r, int change, int ind) {
	// before going down resolve the lazy value of the current node if it exists
	if(lazy[ind] != 0) {
		t[ind] += lazy[ind];
		
		// if this node is non-leaf node pass it's lazy value to it's children
		if(tl != tr){
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] += lazy[ind];
	    }
	    
	    // clear the lazy value of current node
	    lazy[ind] = 0;
	}
		
	// bases case(s)
	
	// Case 1: no overlap
	if((tl > r) or (tr < l)) {
		return;
	}
	
	// Case 2: complete overlap (this is the case where code is being optimized as we are returning
	//         from here w/o actually updating all the nodes in the subtree rooted at node
	//         ind, instead their changed value is just being stored in the lazy array)
	if((tl >= l) and (tr <= r)) {
		t[ind] += change;
		
		// if children node(s) exist then create a new lazy value for the children
		if(tl != tr){
			lazy[2 * ind] += change;
			lazy[2 * ind + 1] += change;
		}
		
		return;
	}
	
	// recursive case (Case 3: partial overlap)
	int mid = (tl + tr)/2;
	
	lazy_range_update_seg_tree(t, lazy, tl, mid, l, r, change, 2 * ind);
	lazy_range_update_seg_tree(t, lazy, mid + 1, tr, l, r, change, 2 * ind + 1);
	
	// update t[ind] in the returning phase
	t[ind] = min(t[2 * ind], t[2 * ind + 1]);
}

int lazy_query_seg_tree(vi &t, vi &lazy, int tl, int tr, int ql, int qr, int ind) {
	// before going down resolve the lazy value of the current node if it exists
	if(lazy[ind] != 0){
		t[ind] += lazy[ind];
		
		// if this node is non-leaf node pass it's lazy value to it's children
		if(tl != tr){
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] +=lazy[ind];
	    }
	    
	    // clear the lazy value of current node
	    lazy[ind] = 0;
	}
	
	// query logic
	
	// base cases
	// Case 1: no overlap
	if((tl > qr) or (tr < ql)) {
		return INT_MAX;
	}
	
	// Case 2: complete overlap
	if((tl >= ql) and (tr <= qr)) {
		return t[ind];
	}
	
	// Recursive case
	// Case 3: partial overlap
	int mid = (tl + tr)/2;
	
	int left = lazy_query_seg_tree(t, lazy, tl, mid, ql, qr, 2 * ind);
	int right = lazy_query_seg_tree(t, lazy, mid + 1, tr, ql, qr, 2 * ind + 1);
	
	return min(left, right);
}

void solve()
{
    cout << "Enter the size of array for which Segment Tree is to be constructed: ---> ";
    int n; cin >> n; cout << n << "\n";
    
    vi v(n);
    cout << "Enter the elements: ---> ";
    for(int  i = 0; i < n; i++) {
    	cin >> v[i];
    }
    
    for(auto x: v) cout << x << " ";
    cout << "\n\n";
    
    // underlying vector used for representing segment tree in 
    // linear space. An array of size n can have approx. around
    // (4 * n + 1) nodes in the corresponding sement tree
    vi t(4 * n + 1);
    
    build_seg_tree(t, v, 0, n - 1, 1);
    
    // vector to store the lazy values for all the Segment Tree nodes
    vector<int> lazy(4 * n + 1, 0);
    
    lazy_range_update_seg_tree(t, lazy, 0, n - 1, 0, 2, 10, 1);
    lazy_range_update_seg_tree(t, lazy, 0, n - 1, 0, 4, 10, 1);
    cout << lazy_query_seg_tree(t, lazy, 0, n - 1, 1, 1, 1) << "\n";
    lazy_range_update_seg_tree(t, lazy, 0, n - 1, 3, 4, 10, 1);
    cout << lazy_query_seg_tree(t, lazy, 0, n - 1, 3, 5, 1) << "\n";
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

// Time Complexity of query_seg_tree(): O(log(n))

/* Sample i/p: 6
               1 3 2 -5 6 4

   Sample o/p: Enter the size of array for which Segment Tree is to be constructed: ---> 6
               Enter the elements: ---> 1 3 2 -5 6 4 

               23
               4
*/