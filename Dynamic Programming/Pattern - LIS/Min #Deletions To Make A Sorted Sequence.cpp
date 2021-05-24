/*PROBLEM: Given an array of n integers. Find the minimum number of elements from the array to 
           remove or delete so that when the remaining elements are placed in the same sequence 
           order form a sorted sequence(either increasing or decreasing).
*/

/*Underlying Concept: 
  # For the sequence to be sorted we need to check for both the longest increasing and decreasing 
    subsequence.
  # Let, Longest increasing subsequence be known as LIS and Longest decreasing subsequence as LDS.
  # So minimum elements to be deleted = array length - max(LIS, LDS).
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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;

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

int len_LIS(vi &v, int n) {
	// dp[i] = LIS length ending at index i of the vector v[]
	vi dp(n, 0);
	
	// initialisation of dp matrix 
	// LIS ending with v[0] has length = 1
	dp[0] = 1;
	
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(v[j] < v[i] and dp[j] > dp[i]) dp[i] = dp[j];
		}
		
		dp[i] += 1;
	}
	
	int res = dp[0];
	for(int i = 1; i < n; i++) res = max(res, dp[i]);
	
	return res;
}

int len_LDS(vi &v, int n) {
	// dp[i] = LDS length ending at index i of the vector v[]
	vi dp(n, 0);
	
	// initialisation of dp matrix 
	// LIS ending with v[0] has length = 1
	dp[n-1] = 1;
	
	for(int i = (n - 2); i >= 0; i--) {
		for(int j = (n - 1); j > i; j--) {
			if(v[j] < v[i] and dp[j] > dp[i]) dp[i] = dp[j];
		}
		
		dp[i] += 1;
	}
	
	int res = dp[0];
	for(int i = 1; i < n; i++) res = max(res, dp[i]);
	
	return res;
}

int min_deletions(vi &v, int n) {
	if(n == 0) return 0;
	
	int x = len_LIS(v, n);
	int y = len_LDS(v, n);
	
	return n - max(x, y);
}

void solve()
{
	int n; cin >> n;
	vi v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	
	cout << min_deletions(v, n) << "\n";
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

/* # lis[] & lds[] are 1-D dp[] global matrices or vectors of size (n) to store sub-problem solution.
     lis[i] for each 0 <= i <= (n-1) stores the length of the longest increasing subsequence 
     of subarray/subvector v[0...i] 𝙬𝙝𝙞𝙘𝙝 𝙚𝙣𝙙𝙨 𝙬𝙞𝙩𝙝 𝙫[𝙞], while
     lds[i] for each 0 <= i <= (n-1) stores the length of the longest decreasing subsequence 
     of subarray/subvector v[0...i] 𝙬𝙝𝙞𝙘𝙝 𝙚𝙣𝙙𝙨 𝙬𝙞𝙩𝙝 𝙫[𝙞].
   
   # Time Complexity: O(n^2)
   # Auxiliary Space: O(n).
*/ 