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

// t[ind] is resposnible for storing the result of the segment v[tl......tr]
void build_seg_tree(vi &v, vi &t, int tl, int tr, int ind) {
	// base case
	if(tl == tr){
		t[ind] = v[tl];
		return;
	}
	
	// similar to postorder traversal
	
	// segment representing [tl....mid]
	build_seg_tree(v, t, tl, (tl + tr) / 2, 2 * ind);
	 
	// segment representing [(mid+1)....tr]
	build_seg_tree(v, t, (tl + tr) / 2 + 1, tr, 2 * ind + 1);
	
	t[ind] = min(t[2 * ind], t[2 * ind + 1]);
	return;
}

// The overlaps are of [tl, tr] with respect to [ql, qr]
// tl, tr, ql, qr are 0-based indexed
int query_seg_tree(vi &t, int tl, int tr, int ql, int qr, int ind) {
	// base cases
  	// Case 1: complete overlap
	if((tl >= ql) && (tr <= qr)) {
		return t[ind];
	}
	
	// Case 2: no overlap
	if((tl > qr) || (tr < ql)){
		return INT_MAX;
	}
	
  	// Recursive case
	// Case 3: partial overlap
	int mid = (tl + tr)/2;
	int left = query_seg_tree(t, tl, mid, ql, qr, 2 * ind);
	int right = query_seg_tree(t, mid + 1, tr, ql, qr, 2 * ind + 1);
	
	return min(left, right);
}

void point_update_seg_tree(vi &t, int tl, int tr, int p, int change, int ind) {
	// case to handle when p is out of bounds of the current segment
	if((p < tl) || (p > tr)) {
		return;
	}
	
	// in leaf node, perform update 
	if(tl == tr) {
		t[ind] += change;
		return;
	}
	
	int mid = (tl + tr)/2;
	point_update_seg_tree(t, tl, mid, p, change, 2 * ind);
	point_update_seg_tree(t, mid + 1, tr, p, change, 2 * ind + 1);
	t[ind] = min(t[2 * ind], t[2 * ind + 1]);
	
	return;
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
    cout << "\n";
    
    // underlying vector used for representing segment tree in 
    // linear space. An array of size n can have approx. around
    // (4 * n + 1) nodes in the corresponding sement tree
    vi t(4 * n + 1);
    
    // ind = the index of the current vertex (starting from 1 
    //       & can go upto (4 * n + 1))
    // tl = left boundary of the current segment
    // tr = right boundary of the current segment
    build_seg_tree(v, t, 0, n-1, 1);
    
    cout << "\nLinear representation of Segment Tree --->\n";
    for(auto x: t) cout << x << " ";
    
    cout << "\n\nEnter the #queries ---> ";
    int q; cin >> q; cout << q << "\n";
    
    cout << "Enter left and right indices for the queries(0-based indexing) --->\n";
    while(q--){
    	int ql, qr; cin >> ql >> qr;
    	cout << "Min ele in the range [" << ql << ", " << qr << "] = ";
    	cout << query_seg_tree(t, 0, n - 1, ql, qr, 1) << "\n";
    }
    
    cout << "\nEnter the point(or index, 0-based indexing) to be updated ---> ";
    int p; cin >> p; cout << p << "\n";
    cout << "Value by which the increment/decrement to be done ---> ";
    int change; cin >> change; cout << change << "\n";
    
    point_update_seg_tree(t, 0, n-1, p, change, 1);
    cout << "\nUpdated linear representation of Segment Tree --->\n";
    for(auto x: t) cout << x << " ";
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

// Time Complexity of point_update_seg_tree(): O(log(n)), where n are #elements in the array.

/* Sample i/p: 6
               1 3 2 -5 6 4
               5
               0 5
               1 3
               4 4
               2 4
               4 5
               2
               -20

   Sample o/p: Enter the size of array for which Segment Tree is to be constructed: ---> 6
               Enter the elements: ---> 1 3 2 -5 6 4 

               Linear representation of Segment Tree --->
               0 -5 1 -5 1 2 -5 4 1 3 0 0 -5 6 0 0 0 0 0 0 0 0 0 0 0 

               Enter the #queries ---> 5
               Enter left and right indices for the queries(0-based indexing) --->
               Min ele in the range [0, 5] = -5
               Min ele in the range [1, 3] = -5
               Min ele in the range [4, 4] = 6
               Min ele in the range [2, 4] = -5
               Min ele in the range [4, 5] = 4

			   Enter the point(or index, 0-based indexing) to be updated ---> 2
			   Value by which the increment/decrement to be done ---> -20

			   Updated linear representation of Segment Tree --->
			   0 -18 -18 -5 1 -18 -5 4 1 3 0 0 -5 6 0 0 0 0 0 0 0 0 0 0 0
*/