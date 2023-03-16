/* Link: https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
         https://leetcode.com/problems/palindrome-partitioning-ii/
 
   PROBLEM: Given a string, a partitioning of the string is a palindrome partitioning 
            if every substring of the partition is a palindrome. For example, 
            “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine
            the fewest cuts needed for a palindrome partitioning of a given string. 
            For example, minimum of 3 cuts are needed for “ababbbabbababa”. 
            The three cuts are “a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are
            needed. 
            If a string of length n containing all different characters, then minimum n-1 cuts 
            are needed.

            eg. String =  ababbbabbababa
                Palindrome partitioning = a|babbbab|b|ababa
                Min #cuts required = 3
*/

/*****************************************************************************************************************************************************************/

// NOTE: Apart from the below implementations another approach to solve this problem can be found at :--->
//       https://www.youtube.com/watch?v=_H8V5hJUGd0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=55&ab_channel=takeUforward

/*****************************************************************************************************************************************************************/

// RECURSIVE IMPLEMENTATION
// Ref: https://www.youtube.com/watch?v=szKVpQtBHh8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=35

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

bool is_palindrome(string &s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) return 0;
        i++; j--;
    }
    
    return 1;
}

int min_cuts(string &s, int i, int j) {
    // base case(s)
    // if(i > j ==> s is empty)
    // if(i == j ==> s has only 1 element)
    if(i >= j) return 0;
    
    // no cuts are required if string is already a palindrome
    if(is_palindrome(s, i, j)) return 0;
    
    // to store final result
    int res = INT_MAX;
    
    // choice diagram code
    // place cuts at different places by help of the suitable "k loop scheme" 
    // b/w first and last indices, recursively calculate min #palindrome partitions 
    // for each independent subproblem and return the minimum count result for the 
    // larger problem
    
    for(int k = i; k <= (j - 1); k++) {
        // 1 palindrome partition is required to cut the string into the partitions
        // (i to k) and (k+1 to j) 
        int tmp = min_cuts(s, i, k) + min_cuts(s, k + 1, j) + 1;

        res = min(res, tmp);
    }
    
    return res;
}

void solve()
{
    string s; cin >> s;
    int n = sz(s);

    cout << min_cuts(s, 0, n - 1) << "\n";
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

// Time complexity of the above naive recursive approach is exponential.

/*****************************************************************************************************************************************************************/

// MEMOIZED IMPLEMENTATION
// Ref: https://www.youtube.com/watch?v=9h10fqkI7Nk&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=37

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

vvi dp;

bool is_palindrome(string &s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) return 0;
        i++; j--;
    }
    
    return 1;
}

int min_cuts(string &s, int i, int j) {
    // base case(s)
    // if(i > j ==> s is empty)
    // if(i == j ==> s has only 1 element)
    if(i >= j) return 0;
    
    // no cuts are required if string is already a palindrome
    if(is_palindrome(s, i, j)) return 0;
    
    // check if already calculated or not
    if(dp[i][j] != -1) return dp[i][j];
    
    // to store final result
    int res = INT_MAX;
    
    // choice diagram code
    // place cuts at different places by help of the suitable "k loop scheme" 
    // b/w first and last indices, recursively calculate min #palindrome partitions 
    // for each independent subproblem and return the minimum count result for the 
    // larger problem
    
    for(int k = i; k <= (j - 1); k++) {
        // 1 palindrome partition is required to cut the string into the partitions
        // (i to k) and (k+1 to j) 
        int tmp = min_cuts(s, i, k) + min_cuts(s, k + 1, j) + 1;

        res = min(res, tmp);
    }
    
    return dp[i][j] = res;
}

void solve()
{
    string s; cin >> s;
    int n = sz(s);
    
    dp.clear();
    dp.resize(n);
    for(int i = 0; i < n; i++) dp[i].resize(n, -1);
    
    cout << min_cuts(s, 0, n - 1) << "\n";
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

// dp[][] is a 2 D global matrix/vector of vectors, with size (s.length()) x (s.length()) 
// and initialized with -1, memset(dp, -1, sizeof(dp));
// It's dimensions are [s.length()] × [s.length()], as max values of the changing parameters
// i.e. i and j can be s.length()-1

// Time complexity: O(n^3)
// Space complexity: O(n^2)

/*****************************************************************************************************************************************************************/

// SLIGHTLY OPTIMIZED MEMOIZED IMPLEMENTATION
// NOTE: Although the asymptotic complexity of this and above approach is same.

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

vvi dp;

bool is_palindrome(string &s, int i, int j) {
    while(i < j) {
        if(s[i] != s[j]) return 0;
        i++; j--;
    }
    
    return 1;
}

int min_cuts(string &s, int i, int j) {
    // base case(s)
    // if(i > j ==> s is empty)
    // if(i == j ==> s has only 1 element)
    if(i >= j) return 0;
    
    // no cuts are required if string is already a palindrome
    if(is_palindrome(s, i, j)) return 0;
    
    // check if already calculated or not
    if(dp[i][j] != -1) return dp[i][j];
    
    // to store final result
    int res = INT_MAX;
    
    // choice diagram code
    // place cuts at different places by help of the suitable "k loop scheme" 
    // b/w first and last indices, recursively calculate min #palindrome partitions 
    // for each independent subproblem and return the minimum count result for the 
    // larger problem
    
    for(int k = i; k <= (j - 1); k++) {
        // if left cut is found already 
        int lf;
        
        if(dp[i][k] != -1) lf = dp[i][k];
        else {
            lf = min_cuts(s, i, k);
            dp[i][k] = lf;
        }
        
        // if right cut is found already 
        int rg;
        
        if(dp[k+1][j] != -1) rg = dp[k+1][j];
        else {
            rg = min_cuts(s, k + 1, j);
            dp[k+1][j] = rg;
        }
        
        // 1 palindrome partition is required to cut the string into the partitions
        // (i to k) and (k+1 to j)
        int tmp = lf + rg + 1;
        res = min(res, tmp);
    }
    
    return dp[i][j] = res;
}

void solve()
{
    string s; cin >> s;
    int n = sz(s);
    
    dp.clear();
    dp.resize(n);
    for(int i = 0; i < n; i++) dp[i].resize(n, -1);
    
    cout << min_cuts(s, 0, n - 1) << "\n";
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

// dp[][] is a 2 D global matrix/vector of vectors, with size (s.length()) x (s.length()) 
// and initialized with -1, memset(dp, -1, sizeof(dp));
// It's dimensions are [s.length()] × [s.length()], as max values of the changing parameters
// i.e. i and j can be s.length()-1

// Time complexity: O(n^3)
// Space complexity: O(n^2)

/*****************************************************************************************************************************************************************/

// TABULATION IMPLEMENTATION (Real DP ;))
// Ref: https://www.youtube.com/watch?v=qmTtAbOTqcg&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=29

// GAP METHOD

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

void precompute(string &s, vvb &pal) {
    for(int g = 0; g < sz(pal); g++) {
        for(int i = 0, j = g; j < sz(pal); i++, j++) {
            if(g == 0) pal[i][j] = true;

            else if(g == 1) pal[i][j] = (s[i] == s[j]);

            else {
                if((s[i] == s[j]) and pal[i+1][j-1]) pal[i][j] = true;
                else pal[i][j] = false;
            }
        }
    }
}

int min_cuts(string &s) {
    int n = sz(s);
    if(n == 0) return 0;

    // dp[i][j] = store the result for substring s[i....j]
    vvi dp(n, vi(n));

    // pal[i][j] = store if substring s[i....j] is palindrome or not 
    vvb pal(n, vb(n));

    precompute(s, pal);
    
    for(int g = 0; g < sz(dp); g++) {
        for(int i = 0, j = g; j < sz(dp); i++, j++) {
            if(g == 0) dp[i][j] = 0;

            else if(g == 1) {
                if(s[i] == s[j]) dp[i][j] = 0;
                else dp[i][j] = 1;
            }
            
            else {
                if(pal[i][j]) dp[i][j] = 0;

                else {
                    int res = INT_MAX;

                    for(int k = i; k <= (j - 1); k++) {
                        int tmp = dp[i][k] + dp[k+1][j] + 1;
                        res = min(res, tmp);
                    }
                    
                    dp[i][j] = res;
                }
            }
        }
    }
    
    return dp[0][sz(dp) - 1];
}

void solve()
{
    string s; cin >> s;
    int n = sz(s);
    
    cout << min_cuts(s) << "\n";
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

// Time complexity: O(n^3)
// Space complexity: O(n^2)

/*****************************************************************************************************************************************************************/

// TABULATION IMPLEMENTATION (Real DP ;))
// OPTIMIZATION OF THE ABOVE APPROACH

// Ref: https://youtu.be/qmTtAbOTqcg?list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&t=1792

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

void precompute(string &s, vvb &pal) {
    for(int g = 0; g < sz(pal); g++) {
        for(int i = 0, j = g; j < sz(pal); i++, j++) {
            if(g == 0) pal[i][j] = true;

            else if(g == 1) pal[i][j] = (s[i] == s[j]);

            else {
                if((s[i] == s[j]) and pal[i+1][j-1]) pal[i][j] = true;
                else pal[i][j] = false;
            }
        }
    }
}

int min_cuts(string &s) {
    int n = sz(s);
    if(n == 0) return 0;

    // dp[i] = store the result for substring s[0....i]
    vi dp(n);

    // pal[i][j] = store if substring s[i....j] is palindrome or not 
    vvb pal(n, vb(n));

    precompute(s, pal);
    
    // for string length = 1, no cuts required
    dp[0] = 0;
    
    for(int i = 1; i < sz(dp); i++) {
        if(pal[0][i] == true) {
            dp[i] = 0; continue;
        }
         
        int res = INT_MAX;
        
        for(int j = i; j >= 1; j--) {
            if(pal[j][i] == true) res = min(res, dp[j-1] + 1);
        }
        
        dp[i] = res;
    }
    
    return dp[sz(dp) - 1];
}

void solve()
{
    string s; cin >> s;
    int n = sz(s);
    
    cout << min_cuts(s) << "\n";
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

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)   

/*****************************************************************************************************************************************************************/

// TABULATION IMPLEMENTATION (Real DP ;))
// Slightly different variation from the above one, but the above with "Gap Method" & it's 
// optimization are more easy.

/* eg dp[][] and p[][] matrix of dimensions 4 × 4 ---->
                       
        dp[][]            
               j →
          0    1    2    3
        ---------------------
      0 |  0 |    |    |    |  
        |----|----|----|----|⏎(Lₛₜᵣ=4)(diagonal)  
    i 1 |Inv |  0 |    | Res|
    ↓   |----|----|----|----|⏎(Lₛₜᵣ=3)(diagonal)  
      2 |Inv |Inv | 0  |    |
        |----|----|----|----|⏎(Lₛₜᵣ=2)(diagonal)  
      3 |Inv |Inv |Inv | 0  |
        |----|----|----|----|
                             ⏎(Lₛₜᵣ=1)(diagonal) 
 *Inv = Invalid 

        
        p[][]             
               j →
          0    1    2    3
        ---------------------
      0 |  T |    |    |    |  
        |----|----|----|----|⏎(Lₛₜᵣ=4)(diagonal)  
    i 1 |Inv |  T |    | Res|
    ↓   |----|----|----|----|⏎(Lₛₜᵣ=3)(diagonal)  
      2 |Inv |Inv | T  |    |
        |----|----|----|----|⏎(Lₛₜᵣ=2)(diagonal)  
      3 |Inv |Inv |Inv | T  |
        |----|----|----|----|
                             ⏎(Lₛₜᵣ=1)(diagonal) 
*Inv = Invalid 

*/

ll minPalinPartitionsTabu(string s) {
    //get the length of the string 
    ll n = s.length();

    /*Create two arrays to build the solution in bottom up manner  
      dp[i][j] = Minimum number of cuts needed for  palindrome partitioning  
                 of substring str[i..j]  
      p[i][j] = true if substring str[i..j] is  
                palindrome, else false  
      Note that dp[i][j] = 0 if p[i][j] is true */
    vvll dp(n, vector<long long>(n)); // dp matrix
    vvb p(n, vector<bool>(n)); // isPalindrome matrix

    // initialisation of dp matrix
    /*The lower Δˡʳ matrix is not initialised as in that part (i > j),
      which is an invalid case i.e. s.length()=0
      Every string of length 1 is a palindrome */
    for(ll i = 0; i < n; i++) {
       dp[i][i]=0;
       p[i][i]=true;
    }

    // choice diagram code iterative version
    /* L is string length. Build the solution in bottom up manner by  
       considering all strings of length starting from 2 to n. 
       The loop structure is same as MCM algorithm */   
    for(ll L = 2; L <= n; L++) {
       // For string of length L, set different possible starting indices (i)
       for(ll i = 0; i < (n - L + 1); i++) {
          ll j = i + L - 1; // ∵ L = j - i + 1, j is the ending index for corresponding i
          
          // firstly check if the s[i...j] isPalindrome or not 
          /* If L is 2, then we just need to compare two characters. Else 
             need to check two corner characters and value of p[i+1][j-1] */ 
          if(L == 2) p[i][j] = (s[i] == s[j]);
          else p[i][j] = (s[i] == s[j]) && p[i+1][j-1]; 
          
          // now calculate min #cuts required for s[i...j]
          if(p[i][j] == true) // if s[i..j] isPalindrome, then 0 cuts required 
              dp[i][j]=0; 
              
          // when s[i...j] is not palindrome
          else {
             dp[i][j] = LLONG_MAX; // to store final result for s[i....j]
             for(ll k=i; k <= (j-1); k++) {
                /* make a cut at every possible location starting from i to j,
                   and get the minimum cuts required for s[i....j] */ 
                ll temp = dp[i][k] + dp[k+1][j] + 1;
                if(temp < dp[i][j]) dp[i][j]=temp;
             }
          }
       }
    }

    // Return the min cut value for complete string. i.e., s[0...(n-1)] 
    return dp[0][n-1];
}

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)

/*****************************************************************************************************************************************************************/ 