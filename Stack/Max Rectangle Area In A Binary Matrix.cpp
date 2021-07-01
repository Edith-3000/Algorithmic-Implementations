/* PROBLEM STATEMENT: Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle 
                      containing all ones and return its area.

   Ref: https://www.youtube.com/watch?v=St0Jf_VmG_g
*/

/* UNDERLYING CONCEPT:----->
   # The problem can be easily tackled by making use of "Max Rectangular Area in a Histogram.cpp" concept.
   # The rows of the binary matrix are converted into histograms one by one and result is found.
   
   # Remember the auxiliary space used in the below algorithm is O(m), but if #columns are very large
     then #rows then the same algorithm can be applied across columns, in that case the space algorithm
     will be (n).
*/

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

// Function which return the 0-based indices of the NSL elements 
// for every array element
vector<int> nsl_indices(vector<int> &v) {
	int n = (int)v.size();
	if(n <= 0) return v;

	// to store the final result
	vector<int> res(n);

	stack<pair<int, int>> st; 
	int pseudo_idx = -1;

    for(int i = 0; i < n; i++) {
		if(st.empty()) res[i] = pseudo_idx;
		else if(st.top().F < v[i]) res[i] = st.top().S;

		else {
			while(!st.empty() && st.top().F >= v[i]) st.pop();

			if(st.empty()) res[i] = pseudo_idx;
			else res[i] = st.top().S;
		}

		st.push({v[i], i});
    }

    // return the final res vector
	return res;
}

// Function which return the 0-based indices of the NSR elements 
// for every array element
vector<int> nsr_indices(vector<int> &v) {
	int n = (int)v.size();
	if(n <= 0) return v;

	// to store the final result
	vector<int> res(n);

	stack<pair<int, int>> st; 
	int pseudo_idx = n;

	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) res[i] = pseudo_idx;
		else if(st.top().F < v[i]) res[i] = st.top().S;

		else {
			while(!st.empty() && st.top().F >= v[i]) st.pop();

			if(st.empty()) res[i] = pseudo_idx;
			else res[i] = st.top().S;
		}

		st.push({v[i], i});
	}

	// return the final res vector
	return res;
}

int max_rect_in_hist(vi &v) {
	int n = (int)v.size();
	if(n == 0) return 0;
	
	vi nsl = nsl_indices(v);
	vi nsr = nsr_indices(v);
	
	vi area(n);
	for(int i = 0; i < n; i++) {
		area[i] = (nsr[i] - nsl[i] - 1) * v[i];
	}
	
	int res = *max_element(area.begin(), area.end());
	return res;
}

int max_rect_area(vvi &v) {
	int n = sz(v);
	if(n == 0) return 0;
	int m = sz(v[0]);
	
	vi hist(v[0]);
	
	int res = 0;
	res = max(res, max_rect_in_hist(hist));
	
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(v[i][j]) hist[j] += 1;
			else hist[j] = 0;
		}
		
		res = max(res, max_rect_in_hist(hist));
	}
	
	return res;
} 

void solve()
{
  	int n, m; cin >> n >> m;
  	vvi v(n, vi(m));
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cin >> v[i][j];
  	}
  	
  	cout << max_rect_area(v) << "\n";
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

// Time Complexity: O(n x m)
// Space Complexity: O(m)