// Ref: https://cp-algorithms.com/data_structures/fenwick.html
//      https://github.com/kartikkukreja/blog-codes/blob/master/src/BIT%20or%20Fenwick%20Tree%20Data%20Structure.cpp
/*********************************************************************************************************************/

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
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// input array[] for which Fenwick Tree will be build
vll v;

// Change functions accordingly when needed

// NOTE: everything is 1-based indexed in fenwick_tree

// Fenwick Tree structure for range updates & range queries, here in the tree 
// only the updates are stored. Original array entries are not stored.
struct fenwick_tree {
	// data members ==>
	int n;
	vll bit1, bit2;
	
	// member functions ===>
	
	// constructor
	fenwick_tree(int n) {
		this->n = n;
		bit1.clear();
		bit1.resize(n + 2);
		bit2.clear();
		bit2.resize(n + 2);
	}
	
	// to seed the bit[] array with some initial value
	void init() {
		bit1[0] = bit2[0] = 0LL;
		for(int i = 1; i <= n; i++) bit1[i] = 0LL, bit2[i] = 0LL;
	}
	
	// if y == 1, it returns the value at position i in the array, whose track is kept in bit1[]
	// else if y == 2, it returns value to be subtracted from query(i, 1) * i
	ll query(int i, int y) {
		ll res = 0LL;
		while(i > 0) {
			if(y == 1) res += bit1[i];
			else res += bit2[i];
			i -= (i & (-i));
		}
		
		return res;
    }
	
	// returns the result for the range [1, i] (1 & i both inclusive)
	ll query(int i) {
    	return query(i, 1) * i - query(i, 2);
    }
	
	// to compute the result for range [l, r] (l & r both inclusive)
	// res[l, r] = fn(res[1, r], res[1, l-1])
	ll range_query(int l, int r) {
		return query(r) - query(l - 1);
	}
	
	// fn. to change the value at idx i by delta in bit[] vector
	// if y == 1, change is to be done in bit1[], else in bit2[]
	void point_update(int i, ll delta, int y) {
		while(i <= n) {
			if(y == 1) bit1[i] += delta;
			else bit2[i] += delta;
			i += (i & (-i));
		}
	}
	
	// fn. to change each element in [l, r] (l & r both inclusive) in the array
	// by value delta
	void range_update(int l, int r, ll delta) {
		point_update(l, delta, 1);
		point_update(r + 1, -delta, 1);
		point_update(l, delta * (l - 1), 2);
		point_update(r + 1, -delta * r, 2);
	}
};

void solve()
{
  	int n; cin >> n;
  	vset(v, n + 1, 0LL);
  	
  	// use 1-based indexing, so as to reduce confusion(s)
  	for(int i = 1; i <= n; i++) cin >> v[i];
  	
  	fenwick_tree ft(n);
  	ft.init();
  	
  	int q; cin >> q;
  	
  	// use 1-based indices for queries and updates
  	while(q--) {
  		// typ == 1 : range update. typ == 2 : range query
  		int typ, l, r; cin >> typ >> l >> r;
  		
  		if(typ == 1) {
  			ll delta; cin >> delta;
  			ft.range_update(l, r, delta);
  		}
  		
  		else {
  			cout << ft.range_query(l, r) << "\n";
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