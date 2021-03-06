/* Link: https://www.geeksforgeeks.org/check-if-a-string-is-a-scrambled-form-of-another-string/
         https://www.interviewbit.com/problems/scramble-string/

   PROBLEM: Given two strings S1 and S2 of equal length, the task is to determine if S2 is a 
            scrambled form of S1.

           Scrambled string:
           Given string str, we can represent it as a binary tree by partitioning it to two non-empty 
           substrings recursively.
           # Note: Srambled string is not same as an Anagram
           Below is one possible representation of str = “coder”:

                                    coder
                                   /    \
                                  co    der
                                 / \    /  \
                                c   o  d   er
                                           / \
                                          e   r
           To scramble the string, we may choose any non-leaf node and swap its two children.
           Suppose, we choose the node "co" and swap its two children, it produces a scrambled 
           string "ocder". 0 or more swappings are allowed.

                                    ocder
                                   /    \
                                  oc    der
                                 / \    /  \
                                o   c  d   er
                                           / \
                                          e   r
           Thus, “ocder” is a scrambled string of “coder”.

           Similarly, if we continue to swap the children of nodes “der” and “er”, it produces a scrambled 
           string “ocred”.

                                    ocred
                                   /    \
                                  oc    red
                                 / \    /  \
                                o   c  re  d
                                       / \
                                      r   e
           Thus, “ocred” is a scrambled string of “coder”.
*/

/******************************************************************************************************/

// RECURSIVE IMPLEMENTATION
// Ref: https://www.youtube.com/watch?v=SqA0o-DGmEw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=40

/*Underlying concept: 
  # In order to obtain scrambled string s2 from s1, we divide s1 at every character, so if
    s1.length()=n, then we check for (n-1) times using iterator i.
  # i goes from 1 ----> (n-1), ∴ loop runs for (n-1)-1+1=(n-1) times.
  # for every iᵗʰ iteration:
    • for the string s1[0....(n-1)] to be a scrambled string of s2
      there are only 2 possibilities.
      Case 1). if the child of s1 which are strings s1ₗ[0...(i-1)] and s1ᵣ[i...(n-1)]
               were swapped, then just find out if -->
               s1ₗ[0...(i-1)] is scrambled string of s2ᵣ[(n-i)...(n-1)] 
                                      &&
               s1ᵣ[i...(n-1)] is scrambled string of s2ₗ[0...(n-i-1)] 
               * s1ₗ = s1(left)
                 s1ᵣ = s2(right), similarly for s2

      Case 2). if the child of s1 which are strings s1ₗ[0...(i-1)] and s1ᵣ[i...(n-1)]
               were NOT swapped, then just find out if -->
               s1ₗ[0...(i-1)] is scrambled string of s2ₗ[0...(i-1)] 
                                      &&
               s1ᵣ[i...(n-1)] is scrambled string of s2ᵣ[i...(n-1)] 

      Now if(Case_1==true || Case_2==true) 
             s1 ans s2 are scrambled strings;               
      
 * NOTE:# All the comparisons are to be done Recursively 
        # if s2 is scrambled string of s1, then s1 is also scrambled string of s2 & vice versa.
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

bool is_scramble(string &s1, string &s2) {
    int n = sz(s1), m = sz(s2);
    
    // base case(s)
    if(s1 == s2) return 1;
    if(n != m) return 0;
    if(n <= 1) return 0;
    
    // choice diagram code
    // to return final result, initially assuming that strings are not scrambled
    bool res = 0;
    
    for(int i = 1; i <= (n - 1); i++) {
        string ss1 = s1.substr(0, i), ss2 = s2.substr(n-i, i);
        string ss3 = s1.substr(i, n-i), ss4 = s2.substr(0, n-i);
        
        // possibility 1: if swapping was done
        bool op1 = is_scramble(ss1, ss2) and is_scramble(ss3, ss4);
        
        ss1 = s1.substr(0, i), ss2 = s2.substr(0, i);
        ss3 = s1.substr(i, n-i), ss4 = s2.substr(i, n-i);
        
        // possibility 2: if swapping was not done
        bool op2 = is_scramble(ss1, ss2) and is_scramble(ss3, ss4);
                   
        if(op1 or op2) { res = 1; break; }
    }
    
    return res;
}

void solve()
{
    string s1, s2; cin >> s1 >> s2;
    if(is_scramble(s1, s2)) cout << "YES\n";
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

// This algorithm can also be implemented by choosing extreme indices i and j and 
// "k for loop scheme".

// Time complexity of the above naive recursive approach is exponential.

/******************************************************************************************************/

// MEMOIZED IMPLEMENTATION
// Ref: https://www.youtube.com/watch?v=VyHEglhbm-A&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=41

/* # As matrix implementation is slightly difficult(though not impossible), we will 
     we use a std::map for cache to avoid duplicated processing.
   # The key of the map will be a string composed of "s1 s2"
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

map<string, bool> dp;

bool is_scramble(string &s1, string &s2) {
    int n = sz(s1), m = sz(s2);
    
    // base case(s)
    if(s1 == s2) return 1;
    if(n != m) return 0;
    if(n <= 1) return 0;
    
    // forming a unique key(type: string) of the form: "s1 s2"
    string key = s1;
    key.pb(' ');
    key.append(s2);
    
    // check if already calculated or not
    if(dp.find(key) != dp.end()) return dp[key]; 
    
    // choice diagram code
    // to return final result, initially assuming that strings are not scrambled
    bool res = 0;
    
    for(int i = 1; i <= (n - 1); i++) {
        string ss1 = s1.substr(0, i), ss2 = s2.substr(n-i, i);
        string ss3 = s1.substr(i, n-i), ss4 = s2.substr(0, n-i);
        
        // possibility 1: if swapping was done
        bool op1 = is_scramble(ss1, ss2) and is_scramble(ss3, ss4);
        
        ss1 = s1.substr(0, i), ss2 = s2.substr(0, i);
        ss3 = s1.substr(i, n-i), ss4 = s2.substr(i, n-i);
        
        // possibility 2: if swapping was not done
        bool op2 = is_scramble(ss1, ss2) and is_scramble(ss3, ss4);
                   
        if(op1 or op2) { res = 1; break; }
    }
    
    return dp[key] = res;
}

void solve()
{
    string s1, s2; cin >> s1 >> s2;
    
    dp.clear();
    if(is_scramble(s1, s2)) cout << "YES\n";
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

// Time complexity: ??

/*****************************************************************************************************/

// MEMOIZED IMPLEMENTATION USING DP MATRIX
// Ref: Editorial of Interviewbit