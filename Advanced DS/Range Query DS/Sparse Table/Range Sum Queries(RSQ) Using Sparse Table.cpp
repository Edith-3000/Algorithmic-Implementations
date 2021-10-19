// Explanation: https://www.youtube.com/watch?v=2EpX9LkO2T0
/*********************************************************************************************************/

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

struct sparse_table {
	// data members
	
	// n = #rows, m = #columns
	int n, m;
	
	// 2D matrix
	vvll mat; 
	
	// to store the power of 2 such that (1 << p2[i]) <= i 
	// log2 function could be used also but it's slow & could lead to TLE
	vi p2; 
	
	// member functions
	void init(int _n) {
		n = _n;
		m = ceil(log2(n)) + 1;
		
		mat.clear();
		mat.resize(n);
		for(int i = 0; i < n; i++) mat[i].resize(m);
		
		p2.clear();
		p2.resize(n + 1);
		
		for(int i = 2; i <= n; i++) {
			// since log2(n) = log2(n/2) + 1
			p2[i] = p2[i/2] + 1;
		}
	}
	
	void build(vi &v) {
		for(int i = 0; i < n; i++) mat[i][0] = v[i];
		
		for(int j = 1; j < m; j++) {
			for(int i = 0; i + (1 << j) <= n; i++) {
				mat[i][j] = mat[i][j - 1] + mat[i + (1 << (j - 1))][j - 1];
			}
		}
	}
	
	// l & r are 0-based indexed
	ll query(int l, int r) {
		// to store the sum
		ll res = 0; 
		
		for(int j = m; j >= 0; j--) {
			if((1 << j) <= (r - l + 1)) {
				res += mat[l][j];
				l += (1 << j);
			}
		}
		
		return res;
	} 
};

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	sparse_table st;
  	st.init(n);
  	st.build(v);
  	
  	// #queries
  	int q; cin >> q;
  	
  	while(q--) {
  		// use 0-based indexing
  		int l, r; cin >> l >> r; 
  		cout << "Sum of element(s) in the range [" << l << ", " << r << "] = ";
  		cout << st.query(l, r) << "\n";
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

/*

Sample i/p ---->

10
1 2 3 4 5 6 7 8 9 10
5
4 8
0 9
3 7
1 8
5 5

Sample o/p ---->

Sum of element(s) in the range [4, 8] = 35
Sum of element(s) in the range [0, 9] = 55
Sum of element(s) in the range [3, 7] = 30
Sum of element(s) in the range [1, 8] = 44
Sum of element(s) in the range [5, 5] = 6

*/

// Time complexity of build() = O(n x m) = O(n x log2(n))
// Time complexity of query() = O(m) = O(log2(n)), as it is Range Sum Query.
// where n = size of input array.