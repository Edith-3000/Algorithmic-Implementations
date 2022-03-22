// Prob: https://leetcode.com/problems/longest-substring-of-one-repeating-character/
// Ref: https://www.youtube.com/watch?v=v8RCUWmybIY
/**********************************************************************************************************/

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

struct seg_node {
	int best_seg, seg_size, best_pref, best_suff;
	char best_pref_char, best_suff_char; 
};

// input string for which Segment Tree will be build
string s;

// Change functions accordingly when needed
struct seg_tree {
	// data members ==>
	
	// size of array[] for which segment tree will be build
	int n;
	
	// underlying vector used for representing segment tree in 
	// linear space. An array of size n can have approx. around 
	// (4 * n + 1) nodes in the corresponding segment tree
	vector<seg_node> t;

	// member functions ===>
	
	// constructor
	seg_tree(int n) {
		this->n = n;
		t.clear(); t.resize(4 * n + 1);
	}
	
	// function to merge child nodes so as to obtain result for the parent node
	void merge_nodes(seg_node &p, seg_node &lf, seg_node &rg) {
		p.best_seg = max({lf.best_seg, rg.best_seg, (lf.best_suff_char == rg.best_pref_char) ? (lf.best_suff + rg.best_pref) : 0});
		
		p.seg_size = lf.seg_size + rg.seg_size;
		
		if(lf.best_pref < lf.seg_size) p.best_pref = lf.best_pref;
		else {
			if(lf.best_pref_char == rg.best_pref_char) p.best_pref = lf.best_pref + rg.best_pref;
			else p.best_pref = lf.best_pref;
		}
		
		p.best_pref_char = lf.best_pref_char;
		
		if(rg.best_suff < rg.seg_size) p.best_suff = rg.best_suff;
		else {
			if(lf.best_suff_char == rg.best_suff_char) p.best_suff = lf.best_suff + rg.best_suff;
			else p.best_suff = rg.best_suff;
		}
		
		p.best_suff_char = rg.best_suff_char;
	}
	
	// build t[] function where,
	// t[ind] is resposnible for storing result corresponding to segment v[tl......tr]
	void build(int tl, int tr, int ind) {
		// base case
		if(tl == tr) {
			t[ind].best_seg = t[ind].seg_size = t[ind].best_pref = t[ind].best_suff = 1;
			t[ind].best_pref_char = t[ind].best_suff_char = s[tl];
			return;
		}
		
		// similar to postorder traversal
		int m = (tl + tr) / 2;
		
		// compute results for child nodes & after it for the parent node i.e. ind
		build(tl, m, 2 * ind);
		build(m + 1, tr, 2 * ind + 1);
		merge_nodes(t[ind], t[2 * ind], t[2 * ind + 1]);
		
		return;
	}
	
	// The overlaps are of [tl, tr] with respect to [ql, qr]. tl, tr, ql, qr are 0-based indexed
	int range_query(int tl, int tr, int ql, int qr, int ind) {		
		// in this problem always one type of query is asked
		return t[ind].best_seg;
	}
	
	// p is the index in s[] at which update is to be done
	void point_update(int tl, int tr, int p, char delta, int ind) {
		// base case(s)
		// case to handle when p is out of bounds of the current segment
		if((p < tl) or (p > tr)) {
			return;
		}
		
		// in leaf node, perform update 
		if(tl == tr) {
			t[ind].best_pref_char = t[ind].best_suff_char = delta;
			return;
		}
		
		int m = (tl + tr) / 2;
		point_update(tl, m, p, delta, 2 * ind);
		point_update(m + 1, tr, p, delta, 2 * ind + 1);
		merge_nodes(t[ind], t[2 * ind], t[2 * ind + 1]);
		
		return;
	}
};

vi longestRepeating(string &qc, vi &qi) {
	int n = sz(s);
	vi res(sz(qc));
	
	struct seg_tree st(n);
  	st.build(0, n - 1, 1);
  	
  	for(int i = 0; i < sz(qc); i++) {
  		int idx = qi[i]; char delta = qc[i]; 
  		st.point_update(0, n - 1, idx, delta, 1); 
  		res[i] = st.range_query(0, n - 1, 0, n - 1, 1);
  	}
  	
  	return res;
}

void solve()
{
  	string qc; cin >> s >> qc;
  	vi qi(sz(qc)); 
  	
  	for(int i = 0; i < sz(qc); i++) cin >> qi[i];
  	
  	vi res = longestRepeating(qc, qi);
  	
  	for(auto x: res) {
  		cout << x << " ";
  	}
  	
  	cout << "\n";
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