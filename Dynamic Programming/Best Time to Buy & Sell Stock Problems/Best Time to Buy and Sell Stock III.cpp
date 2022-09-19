// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// Useful Reference(s): --->
// https://medium.com/algorithms-and-leetcode/best-time-to-buy-sell-stocks-on-leetcode-the-ultimate-guide-ce420259b323
// https://www.youtube.com/watch?v=-uQGzhYj8BQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=38&ab_channel=takeUforward

/**************************************************************************************************************************/

// LEGACY CONTENT: https://pastebin.com/TH5Che6n

/**************************************************************************************************************************/

// METHOD - 1 (RECURSIVE APPROACH)

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

int max_profit(int idx, int canBuy, int cap, int n, vi &v) {
	// base case(s)
	if(idx == n) return 0;
	if(cap == 0) return 0;
	
	// to store the final result
	int res;
	
	if(canBuy) {
		int bought = -v[idx] + max_profit(idx + 1, 0, cap, n, v);
		int notBought = max_profit(idx + 1, 1, cap, n, v);
		
		res = max(bought, notBought);
	}
	
	else {
		int sold = v[idx] + max_profit(idx + 1, 1, cap - 1, n, v);
		int notSold = max_profit(idx + 1, 0, cap, n, v);
		
		res = max(sold, notSold);
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi prices(n);
  	for(int i = 0; i < n; i++) cin >> prices[i];
  	
  	cout << max_profit(0, 1, 2, n, prices) << "\n";
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

/**************************************************************************************************************************/

// METHOD - 2 (TOP DOWN DP)

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

// 3-D dp[][][]
vector<vector<vector<int>>> dp;

int max_profit(int idx, int canBuy, int cap, int n, vi &v) {
	// base case(s)
	if(idx == n) return 0;
	if(cap == 0) return 0;
	
	// check if already calculated or not
	if(dp[idx][canBuy][cap] != -1) return dp[idx][canBuy][cap];
	
	// to store the final result
	int res;
	
	if(canBuy) {
		int bought = -v[idx] + max_profit(idx + 1, 0, cap, n, v);
		int notBought = max_profit(idx + 1, 1, cap, n, v);
		
		res = max(bought, notBought);
	}
	
	else {
		int sold = v[idx] + max_profit(idx + 1, 1, cap - 1, n, v);
		int notSold = max_profit(idx + 1, 0, cap, n, v);
		
		res = max(sold, notSold);
	}
	
	return dp[idx][canBuy][cap] = res;
}

void solve()
{
  	int n; cin >> n;
  	vi prices(n);
  	for(int i = 0; i < n; i++) cin >> prices[i];
  	
  	dp.clear();
  	dp.resize(n, vector<vector<int>>(2, vector<int>(3, -1)));
  	
  	cout << max_profit(0, 1, 2, n, prices) << "\n";
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

/**************************************************************************************************************************/

// METHOD - 3 (BOTTOM UP DP)

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

int max_profit(vi &v) {
	int n = sz(v);
	if(n == 0) return 0;
	
	// 3-D dp[][][]
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));
	
	for(int j = 0; j <= 1; j++) {
		for(int k = 0; k <= 2; k++) {
			dp[n][j][k] = 0;
		}
	}
	
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= 1; j++) {
			dp[i][j][0] = 0;
		}
	}
	
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j <= 1; j++) {
			for(int k = 1; k <= 2; k++) {
				if(j == 1) {
					int bought = -v[i] + dp[i + 1][0][k];
					int notBought = dp[i + 1][1][k];
					
					dp[i][j][k] = max(bought, notBought);
				}
				
				else {
					int sold = v[i] + dp[i + 1][1][k - 1];
					int notSold = dp[i + 1][0][k];
					
					dp[i][j][k] = max(sold, notSold);
				}
			}
		}
	}
	
	int res = dp[0][1][2];
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi prices(n);
  	for(int i = 0; i < n; i++) cin >> prices[i];
  	
  	cout << max_profit(prices) << "\n";
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

/**************************************************************************************************************************/

// METHOD - 4 (SPACE OPTIMIZATION OF METHOD - 3)

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

int max_profit(vi &v) {
	int n = sz(v);
	if(n == 0) return 0;
	
	// 2-D dp[][]
	vector<vector<int>> nxt(2, vector<int>(3)), cur(2, vector<int>(3));
	
	for(int j = 0; j <= 1; j++) {
		for(int k = 0; k <= 2; k++) {
			nxt[j][k] = 0;
		}
	}
	
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j <= 1; j++) {
			cur[j][0] = 0;			
			for(int k = 1; k <= 2; k++) {
				if(j == 1) {
					int bought = -v[i] + nxt[0][k];
					int notBought = nxt[1][k];
					
					cur[j][k] = max(bought, notBought);
				}
				
				else {
					int sold = v[i] + nxt[1][k - 1];
					int notSold = nxt[0][k];
					
					cur[j][k] = max(sold, notSold);
				}
			}
		}
		
		nxt = cur;
	}
	
	int res = nxt[1][2];
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi prices(n);
  	for(int i = 0; i < n; i++) cin >> prices[i];
  	
  	cout << max_profit(prices) << "\n";
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

/**************************************************************************************************************************/

// Method 1 (Top Down DP - 3D) (using a 3D vector)

/* # In this approach our dp is defined by 3 states (that's why 3D DP)
   # State-1(bought): This shows if the stock just previous to current stock was bought or not
                      We will have max 2 possibilities in this, even though we have 3 choices (skip/buy/sell the current stock)
   # State-2(t): This shows the atmost #transactions we can make from current position to the last of prices array.
                 So there will be 3 values for this (0/1/2).
   # State-3(pos): It shows the current position of stock prices which we are working on.                  
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

int solve(bool bought, int t, int pos, int n, vector<int> &v) {
	// base case
	// if out of bounds or if #transactions = 0, then profit which
	// can be achieved = 0
	if(pos >= n || t == 0) return 0;
	
	// check if already calculated or not
	if(dp[bought][t][pos] != -1) return dp[bought][t][pos];
	
	// Now we have 3 choices (skip, buy or sell the current share according to 
	// previous call)
	
	// Case: if we skip the current element
	int ans = solve(bought, t, pos + 1, n, v);
	
	// Case: if we sell the current element
	if(bought) ans = max(ans, v[pos] + solve(false, t - 1, pos + 1, n, v));
	
	// Case: if we buy the current element
	else ans = max(ans, -v[pos] + solve(true, t, pos + 1, n, v));
	
	// return by taking whichever is maximum
	return dp[bought][t][pos] = ans;
}

int maxProfit(vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	dp.resize(2, vector<vector<int>>(3, vector<int>(n, -1)));
	return solve(false, 2, 0, n, v);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(n), where n = size of input array

/*********************************************************************************************************/

// Method 2 (Top Down DP - 3D) (using a unordered_map instead of a 3D table for lookup)
// This method may give TLE in some of the cases as the lookup of a string in the unordered map 
// will not take constant time as in Method 1 above.

#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;

int solve(bool bought, int t, int pos, int n, vector<int> &v) {
	// base case
	// if out of bounds or if #transactions = 0, then profit which
	// can be achieved = 0
	if(pos >= n || t == 0) return 0;
	
	// check if already calculated or not
	string key = to_string(bought) + to_string(t) + to_string(pos);
	if(dp.count(key) != 0) return dp[key];
	
	// Now we have 3 choices (skip, buy or sell the current share according to 
	// previous call)
	
	// Case: if we skip the current element
	int ans = solve(bought, t, pos + 1, n, v);
	
	// Case: if we sell the current element
	if(bought) ans = max(ans, v[pos] + solve(false, t - 1, pos + 1, n, v));
	
	// Case: if we buy the current element
	else ans = max(ans, -v[pos] + solve(true, t, pos + 1, n, v));
	
	// return by taking whichever is maximum
	return dp[key] = ans;
}

int maxProfit(vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	
	return solve(false, 2, 0, n, v);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);

    return 0;
}

// This method is not as efficient in terms of time as compared to Method 1, but it is more efficient
// in terms of space as against Method 1.

/**********************************************************************************************************/

// Method 3 (Divide & Conquer)
// Explanation of the approach: https://www.youtube.com/watch?v=37s1_xBiqH0

#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &v) {
	// left[i] will store the max profit we can gain from v[0] to v[i] (both inclusive)
	// by performing at most 1 transaction
	vector<int> left(n, 0);
	
	// right[i] will store the max profit we can gain from v[n - 1] to v[i] (both inclusive)
	// by performing at most 1 transaction
	vector<int> right(n, 0);
	
	// prerocessing the left array
	// considering each v[i] as a selling point & maintaining 
	// a running MINIMUM stock price
	int left_min = v[0];
	for(int i = 1; i < n; i++) {
		left[i] = max(left[i - 1], v[i] - left_min);
		left_min = min(left_min, v[i]);
	}
	
	// preprocessing the right array
	// considering each v[i] as a buying point & maintaining 
	// a running MAXIMUM stock price
	int right_max = v[n - 1];
	for(int i = (n - 2); i >= 0; i--) {
		right[i] = max(right[i + 1], right_max - v[i]);
		right_max = max(right_max, v[i]);
	}
	
	// using divide and conquer approach
	// we divide the whole array in 2 parts at each element v[i]
	// in the left part we include elements from v[0] to v[i - 1]
	// in the right part we include elements from v[i] to v[n - 1]
	int profit = right[0];
	for(int i = 1; i < n; i++) {
		profit = max(profit, left[i - 1] + right[i]);
	}
	
	return profit;
}

int maxProfit(vector<int> &prices) {
	vector<int> v = prices;
	int n = v.size();
	if(n == 0) return 0;
	
	return solve(n, v);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vector<int> prices {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(n), where n = size of input array