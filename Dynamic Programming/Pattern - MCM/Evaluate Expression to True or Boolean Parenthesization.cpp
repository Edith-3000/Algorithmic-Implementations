/* Link: https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
         https://www.interviewbit.com/problems/evaluate-expression-to-true/

   Ref: https://www.youtube.com/watch?v=pGVguAcWX4g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=38
        https://www.youtube.com/watch?v=bzXM1Zond9U&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=39
        https://www.youtube.com/watch?v=MM7fXopgyjw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=54&ab_channel=takeUforward

   PROBLEM: Given a boolean expression with following symbols ->
            Symbols:
               'T' ---> true 
               'F' ---> false 
            And following operators filled between symbols ->
            Operators(logical not bitwise)
                &   ---> boolean AND
                |   ---> boolean OR
                ^   ---> boolean XOR 
            Count the number of ways we can parenthesize the expression so that the value of 
            expression evaluates to true.
            I/p is in the form of a string.
*/

// RECURSIVE IMPLEMENTATION

/* The implementation of the below algorithm slightly differs from MCM algorithm.
   This algo has one extra i/p arguement is_true, which basically helps to find
   whether the function has to return the total #ways for which the expression,
   s[i....j] is evaluated to be "True" or "False".
   For s[0......(s.length()-1)] is_true is passed as "True" from the main() fⁿ.
   But for the recursive calls is_true is passed according to the requirement.
   Suppose -->         
                         
                                       (k-1) (k+1)
                                         ↓     ↓
                         ----------------------------------------          
                         |  |  |  |  |  |  |  |  |  |  |  |  |  |
                         ----------------------------------------
                          ↑                  ↑                ↑
                         (i)             (suppose)           (j)
                                        (k is here)
                                        and s[k]='^'
                                        /           \
                                       /             \
                                      /               \
                                     /                 \
                                    /                   \
                       -------------------         -------------------         
                       |  |  |  |  |  |  |         |  |  |  |  |  |  |
                       -------------------         -------------------
                        ↑               ↑           ↑              ↑ 
                       (i)            (k-1)       (k+1)           (j)
                      
                       <------left(l)----->        <------right(r)----->
          
          # Truth table for xor('^')
              INPUT	        OUTPUT
           Left  Right	 Left ^ Right
            F     F	          F         
            F     T	          T        
            T     F           T        
            T     T	          F        
          
          # For s to be evaluated as true, when s[k]='^', there are 2 possibilities
            1). left part evaluates to true and right part evaluates to false
                i.e. lt and rf, ∴ ways = lt * rf
            2). left part evaluates to false and right part evaluates to true
                i.e. lf and rt, ∴ ways = lf * rt

            Hence total ways for which s evaluates to be true= (lt * rf) + (lf * rt)

          # For s to be evaluated as false, when s[k]='^', there are 2 possibilities
            1). left part evaluates to true and right part evaluates to true
                i.e. lt and rt, ∴ ways = lt * rt
            2). left part evaluates to false and right part evaluates to false
                i.e. lf and rf, ∴ ways = lf * rf

            Hence total ways for which s evaluates to be true= (lt * rt) + (lf * rf)
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

ll bool_paren(string &s, int i, int j, bool is_true) {
    // base case(s)
    // when s.size() is 0
    if(i > j) return 0;
    
    // when s.size() is 1
    if(i == j) {
        // if s[i...j] is evaluated to be true
        if(is_true == true) return (s[i] == 'T') ? 1 : 0;
        
        // if s[i...j] is evaluated to be false
        else return (s[i] == 'F') ? 1 : 0;
    }
    
    //to store final result
    ll res = 0LL;
    
    // "k loop scheme"
    for(int k = i + 1; k <= (j - 1); k += 2) {
        // temporary answers
        ll lt = bool_paren(s, i, k - 1, true);
        ll lf = bool_paren(s, i, k - 1, false);
        ll rt = bool_paren(s, k + 1, j, true);
        ll rf = bool_paren(s, k + 1, j, false);
        
        // calculating final answer i.e. res which is fn(temporary answers)
        if(s[k] == '&') {
            if(is_true == true) res += (lt * rt);
            else res += (lt * rf) + (lf * rt) + (lf * rf);
        }
        
        else if(s[k] == '|') {
            if(is_true == true) res += (lt * rf) + (lf * rt) + (lt * rt);
            else res += (lf * rf);
        }
        
        else {
            if(is_true == true) res += (lt * rf) + (lf * rt);
            else res += (lt * rt) + (lf * rf);
        }
    }
    
    return res;
}

void solve()
{
    string s; cin >> s;
    int n = sz(s);
    
    cout << bool_paren(s, 0, n - 1, true);
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

/* # i is initialised to 0 in the main fⁿ

   # j is initialised to s.size()-1 in the main fⁿ

   # is_true is initialised to "true" in the main fⁿ, ∵ we need to count total #ways for 
     which s from 0 to s.size()-1 evaluates to be "true"

   # Here in the above algorithm i and j always points to the operands i.e. either 'T'
     or 'F', k always points to an operator i.e. s[k] ε {'&', '|', '^'}

   # Time Complexity: Exponential
*/

/************************************************************************************************************************************/

// MEMOIZED IMPLEMENTATION (USING 3D DP)

/* # To implement memoized version of this algorithm, we need a dp matrix, which is a 
     3 D matrix, ∵ 3 parameters of the bool_paren() fⁿ are changing
     (i, j, and is_true are changing while s remains same in all fⁿ calls).
     ∴ dp[n][n][2] ≡ 3D matrix, (as maximum value taken by i and j can be s.length()-1,
       for is_true 2 values are possible).
       Here n = s.size().
*/

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

vector<vvll> dp;

ll bool_paren(string &s, int i, int j, int is_true) {
    // base case(s)
    // when s.size() is 0
    if(i > j) return 0;
    
    // when s.size() is 1
    if(i == j) {
        // if s[i...j] is evaluated to be true
        if(is_true == true) return (s[i] == 'T') ? 1 : 0;
        
        // if s[i...j] is evaluated to be false
        else return (s[i] == 'F') ? 1 : 0;
    }
    
    // check if already calculated or not;
    if(dp[i][j][is_true] != -1) return dp[i][j][is_true];
    
    //to store final result
    ll res = 0LL;
    
    // "k loop scheme"
    for(int k = i + 1; k <= (j - 1); k += 2) {
        // temporary answers
        ll lt = bool_paren(s, i, k - 1, 1);
        ll lf = bool_paren(s, i, k - 1, 0);
        ll rt = bool_paren(s, k + 1, j, 1);
        ll rf = bool_paren(s, k + 1, j, 0);
        
        // calculating final answer i.e. res which is fn(temporary answers)
        if(s[k] == '&') {
            if(is_true == true) res += (lt * rt);
            else res += (lt * rf) + (lf * rt) + (lf * rf);
        }
        
        else if(s[k] == '|') {
            if(is_true == true) res += (lt * rf) + (lf * rt) + (lt * rt);
            else res += (lf * rf);
        }
        
        else {
            if(is_true == true) res += (lt * rf) + (lf * rt);
            else res += (lt * rt) + (lf * rf);
        }
    }
    
    return dp[i][j][is_true] = res;
}

void solve()
{
    string s; cin >> s;
    int n = sz(s);
    
    dp.clear();
    dp.resize(n, vvll(n, vll(2, -1)));
    
    cout << bool_paren(s, 0, n - 1, 1);
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

/************************************************************************************************************************************/

// MEMOIZED IMPLEMENTATION (USING std::map)

/* # Here we will use a map for cache to avoid duplicated processing.

   # The key of the map will be a string composed of "val(i)+val(j)+val(is_true)"
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

// works simlar to dp matrix
map<string, ll> dp;

ll bool_paren(string &s, int i, int j, bool is_true) {
    // base case(s)
    // when s.size() is 0
    if(i > j) return 0;
    
    // when s.size() is 1
    if(i == j) {
        // if s[i...j] is evaluated to be true
        if(is_true == true) return (s[i] == 'T') ? 1 : 0;
        
        // if s[i...j] is evaluated to be false
        else return (s[i] == 'F') ? 1 : 0;
    }
    
    // forming a unique key(type: string) of the form: "i+j+is_true"
    string key = to_string(i);
    key.append(to_string(j));
    key.append(to_string(is_true));

    // check if already calculated or not
    if(dp.find(key) != dp.end()) return dp[key];
    
    //to store final result
    ll res = 0LL;
    
    // "k loop scheme"
    for(int k = i + 1; k <= (j - 1); k += 2) {
        // temporary answers
        ll lt = bool_paren(s, i, k - 1, true);
        ll lf = bool_paren(s, i, k - 1, false);
        ll rt = bool_paren(s, k + 1, j, true);
        ll rf = bool_paren(s, k + 1, j, false);
        
        // calculating final answer i.e. res which is fn(temporary answers)
        if(s[k] == '&') {
            if(is_true == true) res += (lt * rt);
            else res += (lt * rf) + (lf * rt) + (lf * rf);
        }
        
        else if(s[k] == '|') {
            if(is_true == true) res += (lt * rf) + (lf * rt) + (lt * rt);
            else res += (lf * rf);
        }
        
        else {
            if(is_true == true) res += (lt * rf) + (lf * rt);
            else res += (lt * rt) + (lf * rf);
        }
    }
    
    return dp[key] = res;
}

void solve()
{
    string s; cin >> s;
    int n = sz(s);
    
    dp.clear();     
    cout << bool_paren(s, 0, n - 1, true);
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

/* # i is initialised to 0 in the main fⁿ

   # j is initialised to s.size()-1 in the main fⁿ

   # is_true is initialised to "true" in the main fⁿ, ∵ we need to count total #ways for 
     which s from 0 to s.size()-1 evaluates to be "true"

   # Here in the above algorithm i and j always points to the operands i.e. either 'T'
     or 'F', k always points to an operator i.e. s[k] ε {'&', '|', '^'}

   # dp is a map declared globally, whose key is of type "string" & value is of 
     type "long long".

   # Time complexity: O(n^3 x log(n^2))
*/

/***********************************************************************************************************************************/

// TABULATION IMPLEMENTATION 

// By simply converting base cases of recursion into initialisation of dp[][] and rewriting the recursive code into
// iterative format in reverse manner.

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

ll bool_paren(string &s) {
    int n = sz(s);
    if(n == 0) return 0;
    
    vector<vvll> dp(n, vvll(n, vll(2)));
    
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            for(int is_true = 0; is_true < 2; is_true++) {
                if(i > j) dp[i][j][is_true] = 0;
                
                else if(i == j) {
                    if(is_true == 0) dp[i][j][is_true] = (s[i] == 'F');
                    else dp[i][j][is_true] = (s[i] == 'T');
                }
                
                else {
                    ll ans = 0LL;
                    
                    for(int k = i + 1; k <= (j - 1); k += 2) {
                        ll lt = dp[i][k - 1][1];
                        ll lf = dp[i][k - 1][0];
                        ll rt = dp[k + 1][j][1];
                        ll rf = dp[k + 1][j][0];
                        
                        if(s[k] == '&') {
                            if(is_true == 1) ans += (lt * rt);
                            else ans += (lt * rf) + (lf * rt) + (lf * rf);
                        }
                        
                        else if(s[k] == '|') {
                            if(is_true == 1) ans += (lt * rf) + (lf * rt) + (lt * rt);
                            else ans += (lf * rf);
                        }
                        
                        else {
                            if(is_true == 1) ans += (lt * rf) + (lf * rt);
                            else ans += (lt * rt) + (lf * rf);
                        }
                    }
                    
                    dp[i][j][is_true] = ans;
                }
            }
        }
    }
    
    return dp[0][n - 1][1];
}

void solve()
{
    string s; cin >> s;

    cout << bool_paren(s);
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


/***********************************************************************************************************************************/

// TABULATION IMPLEMENTATION (Real DP ;))
// Ref: https://www.youtube.com/watch?v=JbRsM2X2_pg&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=31

// Using "Gap Method"

// NOTE: in this implementation the operator and operand strings are been considered as separate.

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

ll bool_paren(string &s1, string &s2) {
    int n = sz(s1);
    if(n == 0) return 0;

    // T[i...j] = total #ways such that s1[i..j] can be evaluated as true
    // F[i...j] = total #ways such that s1[i..j] can be evaluated as false
    vvll T(n, vll(n)), F(n, vll(n));

    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++, j++) {
            if(g == 0) {
                if(s1[i] == 'T') T[i][j] = 1, F[i][j] = 0;
                else T[i][j] = 0, F[i][j] = 1;
            }
            
            else {
                ll res1 = 0LL, res2 = 0LL;

                for(int k = i; k <= (j - 1); k++) {
                    ll lt = T[i][k];
                    ll lf = F[i][k];
                    ll rt = T[k+1][j];
                    ll rf = F[k+1][j];
                    
                    if(s2[k] == '&') {
                        res1 += (lt * rt);
                        res2 += (lt * rf) + (lf * rt) + (lf * rf);
                    }
        
                    else if(s2[k] == '|') {
                        res1 += (lt * rf) + (lf * rt) + (lt * rt);
                        res2 += (lf * rf);
                    }
        
                    else {
                        res1 += (lt * rf) + (lf * rt);
                        res2 += (lt * rt) + (lf * rf);
                    }
                }
                
                T[i][j] = res1;
                F[i][j] = res2;
            }
        }
    }
    
    return T[0][n-1];
}

void solve()
{
    // s1 is string of operands
    // s2 is string of operators
    string s1, s2; cin >> s1 >> s2;
    
    int n = sz(s1);
    
    cout << bool_paren(s1, s2);
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