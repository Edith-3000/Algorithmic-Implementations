/* Link: https://www.techiedelight.com/longest-bitonic-subsequence/
         https://www.geeksforgeeks.org/printing-longest-bitonic-subsequence/

   PROBLEM: Given an array arr[0...(n-1)] containing n integers, a subsequence of arr[] is called 
            Bitonic if it is first increasing, then decreasing. Write a function that takes an array 
            as argument and returns longest bitonic subsequence in the form of a vector.
            NOTE(s):
            # A sequence, sorted in increasing order is considered Bitonic with the decreasing part 
              as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing 
              part as empty.
            # If more than one solution exit then return any one solution.
*/

/*UNDERLYING CONCEPT ------>
  # We define an array of vectors lis such that lis[i] stores Longest Increasing Subsequence 
    of v[0..i] that 𝒆𝒏𝒅𝒔 𝒘𝒊𝒕𝒉 𝒗[𝒊].
  # Similarly we define an array of vectors lds such that lds[i] stores Longest Decreasing 
    Subsequence of v[i...(n-1)] that 𝒔𝒕𝒂𝒓𝒕𝒔 𝒘𝒊𝒕𝒉 𝒗[𝒊].
  # For example, for array [1 11 2 10 4 5 2 1] ----->

    LIS[0]: 1
    LIS[1]: 1 11
    LIS[2]: 1 2
    LIS[3]: 1 2 10
    LIS[4]: 1 2 4
    LIS[5]: 1 2 4 5
    LIS[6]: 1 2
    LIS[7]: 1

    LDS[0]: 1
    LDS[1]: 11 10 5 2 1
    LDS[2]: 2 1
    LDS[3]: 10 5 2 1
    LDS[4]: 4 2 1
    LDS[5]: 5 2 1
    LDS[6]: 2 1
    LDS[7]: 1
   
   Therefore, Longest Bitonic Subsequence can be
   LIS[1] + LDS[1] = [1 11 10 5 2 1]  or
   LIS[3] + LDS[3] = [1 2 10 5 2 1]   or
   LIS[5] + LDS[5] = [1 2 4 5 2 1]
*/

/****************************************************************************************************/

// METHOD - 1

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

vi print_LBS(vi &v, int n) {
    // LIS[i] stores the longest increasing subsequence of subarray v[0...i] that ends with v[i]
    vvi LIS(n); 
    
    // LDS[i] stores the longest decreasing subsequence of subarray v[i...(n-1)] that starts with v[i]
    vvi LDS(n); 

    // initialisation
    // LIS[0] denotes longest increasing subsequence ending with v[0]
    LIS[0].pb(v[0]);

    // LDS[n-1] denotes longest decreasing subsequence starting with v[n-1]
    LDS[n-1].pb(v[n-1]);
    
    // for LIS[]
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(v[j] < v[i] and sz(LIS[j]) > sz(LIS[i])) LIS[i] = LIS[j];
        }

        LIS[i].pb(v[i]);
    }
    
    // for LDS[]
    for(int i = (n - 2); i >= 0; i--) {
        for(int j = (n - 1); j > i; j--) {
            if(v[j] < v[i] and sz(LDS[j]) > sz(LDS[i])) LDS[i] = LDS[j];
        }

        LDS[i].pb(v[i]);
    }
    
    // reverse each vector LDS[i]  
    for (int i = 0; i < n; i++) reverse(LDS[i].begin(), LDS[i].end());
    
    // find the maximum value of LIS[i].size() + LDS[i].size() - 1
    int mx = sz(LIS[0]) + sz(LDS[0]) - 1; 
    int idx = 0;

    for (int i = 1; i < n; i++) {
        if(sz(LIS[i]) + sz(LDS[i]) - 1 > mx) {
            mx = sz(LIS[i]) + sz(LDS[i]) - 1;
            idx = i;
        }
    }   

    vi res = LIS[idx];
    for(int i = 1; i < sz(LDS[idx]); i++) res.pb(LDS[idx][i]);
    
    return res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vi res = print_LBS(v, n);
    for(auto x: res) cout << x << " ";
    cout << "\n";
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
// Auxiliary Space: O(n^2)

/******************************************************************************************************/

// SPACE OPTIMIZED VERSION OF ABOVE APPROACH [Auxiliary Space: O(n)]
// https://www.geeksforgeeks.org/print-longest-bitonic-subsequence-space-optimized-approach/

/*ALGORITHM: ------>
  1). Create two dp vectors lis[] and lds[] to store, at every ith index, the length of the longest 
      increasing and decreasing subsequences 𝑬𝑵𝑫𝑰𝑵𝑮 & 𝑺𝑻𝑨𝑹𝑻𝑰𝑵𝑮 with the element v[i] respectively.
  2). Once computed, find the ith index which contains the maximum value of lis[i] + lds[i] – 1
  3). Create res[] to store all the elements of the longest bitonic subsequence in increasing order of 
      elements followed by decreasing order of elements.
  4). Return the res[] vector.
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

vi print_LBS(vi &v, int n) {
    // LIS[i] stores the length of longest increasing subsequence of subarray v[0...i] that ends with v[i]
    vi LIS(n); 
    
    // LDS[i] stores the length of longest decreasing subsequence of subarray v[i...(n-1)] that starts with v[i]
    vi LDS(n); 

    // initialisation
    // LIS[0] denotes length of longest increasing subsequence ending with v[0]
    LIS[0] = 1;

    // LDS[n-1] denotes length of longest decreasing subsequence starting with v[n-1]
    LDS[n-1] = 1;
    
    // for LIS[]
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(v[j] < v[i] and LIS[j] > LIS[i]) LIS[i] = LIS[j];
        }

        LIS[i] += 1;
    }
    
    // for LDS[]
    for(int i = (n - 2); i >= 0; i--) {
        for(int j = (n - 1); j > i; j--) {
            if(v[j] < v[i] and LDS[j] > LDS[i]) LDS[i] = LDS[j];
        }

        LDS[i] += 1;
    }
        
    // find the maximum value of LIS[i] + LDS[i] - 1
    int mx = LIS[0] + LDS[0] - 1; 
    int idx = 0;

    for (int i = 1; i < n; i++) {
        if(LIS[i] + LDS[i] - 1 > mx) {
            mx = LIS[i] + LDS[i] - 1;
            idx = i;
        }
    }   
    
   
    // stores the count of elements in increasing order in LBS
    int cnt = LIS[idx];
     
    int prev = INT_MAX;
    vi res;
    
    for(int i = idx; i >= 0 and cnt > 0; i--) {
        if(LIS[i] == cnt and v[i] < prev) {
            res.pb(v[i]);
            prev = v[i];
            cnt -= 1;
        }
    }
    
    reverse(res.begin(), res.end());
    
    cnt = LDS[idx] - 1;
    prev = v[idx];
    
    for(int i = idx + 1; i < n and cnt > 0; i++) {
        if(LDS[i] == cnt and v[i] < prev) {
            res.pb(v[i]);
            prev = v[i];
            cnt -= 1;
        }
    }
    
    return res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vi res = print_LBS(v, n);
    for(auto x: res) cout << x << " ";
    cout << "\n";
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
// Auxiliary Space: O(n)