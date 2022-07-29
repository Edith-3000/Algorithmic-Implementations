// Problem: https://www.techiedelight.com/wildcard-pattern-matching/

// Ref: https://www.techiedelight.com/wildcard-pattern-matching/
//      https://www.geeksforgeeks.org/wildcard-pattern-matching/

//      https://www.youtube.com/watch?v=NbgUZAoIz3g
//      (In the video explanation is good but implementation is slightly different)

//      https://www.youtube.com/watch?v=ZmlQ3vgAOMo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=36&ab_channel=takeUforward
/***************************************************************************************************************************/

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

// Function that matches the input string str with a given wildcard pattern pat
bool is_matching(string &str, string &pat, int n, int m) {
	// If both the input string and pattern reach their end, return true
	if(n < 0 and m < 0) return 1;
	
	// If only the pattern reaches its end, return false
	else if(m < 0) return 0;
	
	// If only the input string reaches its end, return true
    // if the remaining characters in the pattern are all '*'
	else if(n < 0) {
		for(int i = 0; i <= m; i++) {
			if(pat[i] != '*') return 0;
		}
		
		return 1;
	}
	
	bool res;
	
	// If the current character is not a wildcard character, it should match the current character in the input string
	// OR if current wildcard char is '?' try to match other characters in both strings
	if((str[n] == pat[m]) or (pat[m] == '?')) {
		res = is_matching(str, pat, n - 1, m - 1);
	}
	
	 // 1. Ignore '*' and move to the next character in the pattern
	 // 2. '*' matches with current characters in the input string.
     //    Here, we will move to the next character in the string.            
	else if(pat[m] == '*') res = is_matching(str, pat, n, m - 1) or 
								 is_matching(str, pat, n - 1, m);		 
	
	else res = 0;
	
	return res;
}

void solve()
{
  	string str, pat;
  	cin >> str >> pat;
  	
  	// get the length of string and wildcard pattern
	int n = sz(str);
	int m = sz(pat);
  	
  	if(is_matching(str, pat, n - 1, m - 1)) cout << "YES\n";
  	else cout << "NO\n"; 
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

// TC: Exponential

// The recursive approach can also be written in the following manner:--->
// https://pastebin.com/4i2HHVVp

/********************************************************************************************************/

// NOTE: In case you get MLE on some platforms, use dp as bool instead of int type.

/********************************************************************************************************/

// METHOD - 2 (Top Down DP)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

// Function that matches the input string str with a given wildcard pattern pat
int is_matching(string &str, string &pat, int n, int m, vvi &dp) {
	// If both the input string and pattern reach their end, return true
	if(n < 0 and m < 0) return 1;
	
	// If only the pattern reaches its end, return false
	else if(m < 0) return 0;
	
	// If only the input string reaches its end, return true
    // if the remaining characters in the pattern are all '*'
	else if(n < 0) {
		for(int i = 0; i <= m; i++) {
			if(pat[i] != '*') return 0;
		}
		
		return 1;
	}
	
	// check if already calculated
	if(dp[n][m] != -1) return dp[n][m];
	
	int res = 0;
	
	// If the current character is not a wildcard character, it should match the current character in the input string
	// OR if current wildcard char is '?' try to match other characters in both strings
	if((str[n] == pat[m]) or (pat[m] == '?')) {
		res = is_matching(str, pat, n - 1, m - 1, dp);
	}
	
	 // 1. Ignore '*' and move to the next character in the pattern
	 // 2. '*' matches with current characters in the input string.
     //    Here, we will move to the next character in the string.            
	else if(pat[m] == '*') res = is_matching(str, pat, n, m - 1, dp) or 
								 is_matching(str, pat, n - 1, m, dp);		 
	
	else res = 0;
	
	return dp[n][m] = res;
}

void solve()
{
  	string str, pat;
  	cin >> str >> pat;
  	
  	// get the length of string and wildcard pattern
	int n = (int)str.size();
	int m = (int)pat.size();
  	
  	vvi dp(n, vi(m, -1));
  	
  	if(is_matching(str, pat, n - 1, m - 1, dp)) cout << "YES\n";
  	else cout << "NO\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
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

// TC: O(n x m)
// SC: O(n x m)

/**********************************************************************************************************/

// METHOD - 3 (Bottom Up DP)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

// Function that matches the input string str with a given wildcard pattern pat
bool is_matching(string &str, string &pat) {
	// get the length of string and wildcard pattern
	int n = (int)str.size();
	int m = (int)pat.size();
	
	// create a DP lookup table
	// dp[i][j] = 1, if str of length i (str[0.....i-1]) matches 
	//               with the pat of length j (pat[0....j-1])
	// else dp[i][j] = 0
	// therefore final result at dp[n][m]
	vvi dp(n + 1, vi(m + 1));
	
	// if both pattern and string are empty: match
	dp[0][0] = 1;
	
	// if pattern is empty then no matching, for length 1 to n
	for(int i = 1; i <= n; i++) dp[i][0] = 0;
	
	// handles empty string case (i == 0)
	for(int j = 1; j <= m; j++) {
		if(pat[j-1] == '*') dp[0][j] = dp[0][j-1];
		else dp[0][j] = 0;
	}
	
	// build a matrix in a bottom-up manner
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if((pat[j-1] == '?') or (pat[j-1] == str[i-1])) dp[i][j] = dp[i-1][j-1];
			else if(pat[j-1] == '*') dp[i][j] = dp[i-1][j] or dp[i][j-1];
			else dp[i][j] = 0;
		}
	}
	
	// last cell stores the answer
	return dp[n][m];
}

void solve()
{
  	string str, pat;
  	cin >> str >> pat;
  	
  	if(is_matching(str, pat)) cout << "YES\n";
  	else cout << "NO\n"; 
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
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

// TC: O(n x m)
// SC: O(n x m)

/***************************************************************************************************************/

// METHOD - 4 (Space Optimization of METHOD - 3)

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

// Function that matches the input string str with a given wildcard pattern pat
bool is_matching(string &str, string &pat) {
	// get the length of string and wildcard pattern
	int n = (int)str.size();
	int m = (int)pat.size();
	
	vb prev(m + 1), cur(m + 1);
	
	prev[0] = 1;
	
	for(int j = 1; j <= m; j++) {
        if(pat[j-1] == '*') prev[j] = prev[j-1];
        else prev[j] = 0;
    }

    // build a matrix in a bottom-up manner
    for(int i = 1; i <= n; i++) {
        cur[0] = 0;
        
        for(int j = 1; j <= m; j++) {
            if((pat[j-1] == '?') or (pat[j-1] == str[i-1])) cur[j] = prev[j-1];
            else if(pat[j-1] == '*') cur[j] = prev[j] or cur[j-1];
            else cur[j] = 0;
        }
        
        prev = cur;
    }

    return prev[m];
}

void solve()
{
  	string str, pat;
  	cin >> str >> pat;
  	
  	if(is_matching(str, pat)) cout << "YES\n";
  	else cout << "NO\n"; 
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

// TC: O(n x m)
// SC: O(m)