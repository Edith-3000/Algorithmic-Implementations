// Prob: https://www.geeksforgeeks.org/k-maximum-sums-non-overlapping-contiguous-sub-arrays/
// Ques. based on concept: https://codeforces.com/problemset/problem/467/C
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

void compute_cs(vll &cs, vll &v, int n, int m, int k) {
	for(int i = 0; i < k; i++) cs[0] += v[i];
	
	for(int i = 1; i + k <= n; i++) {
		cs[i] = cs[i-1] - v[i-1] + v[i+k-1];
	}
}

ll calc(int i, int m, int tot, int k, vll &cs, vvll &dp) {
	// base case
	if(i >= tot or m <= 0) return 0LL;
	
	// check if already calculated
	if(dp[i][m] != -1) return dp[i][m];
	
	// 2 choices ===>
	// a) include the subarray starting from ith position
	// b) exclude the subarray starting from ith position
	ll inc = cs[i] + calc(i + k, m - 1, tot, k, cs, dp);
	ll exc = calc(i + 1, m, tot, k, cs, dp);
	
	// return whichever is maximum
	return dp[i][m] = max(inc, exc);
}

// function to find the maximum sum of 'm' non overlapping subarrays
// each of size 'k' in an array v[] of size 'n'
ll max_sum(vll &v, int n, int m, int k) {
	// cs[i] = sum of the subarray of size 'k', beginning with ith element
	vll cs(n - k + 1, 0LL);
	compute_cs(cs, v, n, m, k);
	
	// dp[i][j] = max sum we can obtain from the ith till the last index if 
	//            exactly j #subarrays are left to be taken
	vvll dp(sz(cs), vll(m + 1, -1));
	
	return calc(0, m, sz(cs), k, cs, dp);
}

void solve()
{
  	int n, m, k;
  	cin >> n >> m >> k;
  	
  	vll v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << max_sum(v, n, m, k) << "\n";
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