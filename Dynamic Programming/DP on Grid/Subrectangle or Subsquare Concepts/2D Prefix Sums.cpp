// Prob: https://leetcode.com/problems/range-sum-query-2d-immutable/

// Ref: https://usaco.guide/silver/more-prefix-sums?lang=cpp#2d-prefix-sums

/**************************************************************************************************************************/

// LEGACY CONTENT: https://pastebin.com/mM4xWQS4

/**************************************************************************************************************************/

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

// Below struct has been implemented for 2D prefix sums, change the 
// functionality according to requirement ===>

// NOTE: here 0-based indices are used, change it accordingly when required

struct prefix {
	// data members ===>
	
	// n = #rows, m = #columns in the input matrix
	int n, m;

	// dp[i][j] = sum of elements in the matrix with (0, 0) as upper left corner
	//            and (i, j) as bottom right corner
	vvi dp;
	
	// member functions ===>
	
	prefix(int rows, int columns) {
		n = rows;
		m = columns;
		
		// initialise it according to requirement
		dp.clear();
		dp.resize(n, vi(m, 0));
	}
	
	void populate(vvi &v) {
		for(int i = 0; i < n; i++) {
			dp[i][0] = v[i][0];
			if((i - 1) >= 0) dp[i][0] += dp[i - 1][0];
		}
		
		for(int j = 1; j < m; j++) {
			dp[0][j] = v[0][j];
			if((j - 1) >= 0) dp[0][j] += dp[0][j - 1];
		}
		
		for(int i = 1; i < n; i++) {
			for(int j = 1; j < m; j++) {
				int A = 0, B = 0, C = 0, D = 0;

				B = dp[i - 1][j];
				C = dp[i][j - 1];
				D = dp[i - 1][j - 1];
				A = v[i][j] + B + C - D;

				dp[i][j] = A;
			}
		} 
	}
	
	// (r1, c1) = upper left corner 
	// (r2, c2) = bottom right corner
	int query(int r1, int c1, int r2, int c2) {
		int A = 0, B = 0, C = 0, D = 0;
		
		A = dp[r2][c2];
		if((r1 - 1) >= 0) B = dp[r1 - 1][c2];	
		if((c1 - 1) >= 0) C = dp[r2][c1 - 1];	
		if((r1 - 1 >= 0) and (c1 - 1 >= 0)) D = dp[r1 - 1][c1 - 1];
		
		int res = A - B - C + D;
		
		return res;
	} 
};

void solve()
{
  	int n, m; cin >> n >> m;
  	vvi v(n, vi(m));
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) {
  			cin >> v[i][j];
  		}
  	}
  	
  	struct prefix pfx(n, m);
  	pfx.populate(v);
  	
  	int q; cin >> q;
  	
  	// use 0-based indices for rows and columns
  	while(q--) {
  		int r1, c1, r2, c2;
  		cin >> r1 >> c1 >> r2 >> c2;
  		
  		cout << pfx.query(r1, c1, r2, c2) << "\n";
  	}
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