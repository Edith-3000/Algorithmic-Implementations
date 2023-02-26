/* PROBLEM: Print the Longest Increasing Subsequence (LIS) for a given array.
            The Longest Increasing Subsequence (LIS) subsequence of a given sequence is such that all 
            elements of the subsequence are sorted in increasing order(i.e. monotically increasing
            subsequence). 
            For example --->
            the LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is {10, 22, 33, 50, 60, 80}.
   
   Ref: https://www.youtube.com/watch?v=IFfYfonAFGc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44&ab_channel=takeUforward

   Problem based on this concept --->
   https://codeforces.com/problemset/problem/4/D
*/

/*****************************************************************************************************************************************************************/

// METHOD - 1 O(n^2) Time & Memory
// https://www.techiedelight.com/longest-increasing-subsequence-using-dynamic-programming/

/* Underlyring concept:--->

   Let v[0...(n-1)] be the input array/vector. We define an array of vectors L that stores LIS of v 
   that ends with v[i] for each 0 <= i <= (n-1). For example, for vector [3, 2, 6, 4, 5, 1],

   L[0]: 3
   L[1]: 2
   L[2]: 2 6 (or) 3 6
   L[3]: 2 4 (or) 3 4
   L[4]: 2 4 5
   L[5]: 1
*/

/* Some Extra Points :---->

   Ques. What is the difference between vector<int>v1[] and vector<vector<int>>v2 ?

   Ans. ● v1 is an array of vectors while v2 is a vector of vectors.

        ● v1 can't grow. You cannot make v1.push_back(...) as its not a vector object. Its just an array. 
          While v2 is dynamic. You can grow it as you please.

        ● When you want to work with a fixed number of std::vector elements, you can use vector<int>v1[].
          When you want to work with a dynamic array of std::vector, you can use vector<vector<int>>v2.

        ● Although both can be initialized in the same way, e.g.
          vector<int>v1[]        {{1,2,3}, {4,5,6}};
          vector<vector<int>>v2  {{1,2,3}, {4,5,6}};
         
          Can also be printed in the same way, e.g.
          cout << v1[0].back() << endl;
          cout << v2[0].back() << endl;
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

vi print_LIS(vi &v, int n) {
    // LIS[i] stores the longest increasing subsequence of subarray
    // v[0...i] that ends with v[i]
    vvi LIS(n);
    
    // LIS[0] denotes longest increasing subsequence ending with v[0]
    LIS[0].pb(v[0]);
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(v[j] < v[i] and sz(LIS[j]) > sz(LIS[i])) LIS[i] = LIS[j];
        }
        
        LIS[i].pb(v[i]);
    }
    
    // idx will contain index of increasing subsequence of maximum length
    int mx = 0, idx = -1;
    
    for(int i = 0; i < n; i++) {
        if(sz(LIS[i]) > mx) mx = sz(LIS[i]), idx = i;
    }
    
    return LIS[idx];
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vi res = print_LIS(v, n);
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

/*****************************************************************************************************************************************************************/

// METHOD - 2 O(n^2) Time & O(n) Memory

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

// Function which returns the LIS in vector v[]
vi print_LIS(vi &v, int n) {
    // dp[i] = length of the LIS ending at index i
    vi dp(n);
    
    // this vector will be used to extract the actual LIS
    // par[i] = j such that v[j] < v[i] and v[j] is a part of LIS ending at index i,
    //          and is just left to i in the LIS. If there is no such j, then par[i] = i,
    vi par(n);
    
    // initialising dp[] and par[]
    for(int i = 0; i < n; i++) {
        dp[i] = 0; par[i] = i;
    }
    
    dp[0] = 1;
        
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if((v[j] < v[i]) and (dp[j] > dp[i])) {
                dp[i] = dp[j];
                par[i] = j;
            }
        }
        
        dp[i] += 1;
    }
    
    // idx will contain index of increasing subsequence of maximum length
    int mx = 0, idx = -1;
    
    for(int i = 0; i < n; i++) {
        if(dp[i] > mx) mx = dp[i], idx = i;
    }
    
    int cur = idx;
    vi lis_indices = {cur};
    
    while(cur != par[cur]) {
        cur = par[cur];
        lis_indices.pb(cur);
    }
    
    // stores the actual LIS
    vi res;
    
    for(int i = sz(lis_indices) - 1; i >= 0; i--) {
        res.pb(v[lis_indices[i]]);
    }
    
    return res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vi res = print_LIS(v, n);
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

/*****************************************************************************************************************************************************************/

// NON DP IMPLEMENTATION (in O(n*log₂(n)))
// https://www.techiedelight.com/longest-increasing-subsequence/

/*# Let s[] be a vector & s[i] be defined as the smallest integer that ends an increasing sequence of 
    length (i+1). Now iterate through every integer of the input set v[] and do the following: --->
    ● If x is more than the last element in s, then append x to the end of s. This essentially means we 
      have found a new largest LIS.
    ● Otherwise find the smallest element in s, which is more than or equal to x, and replace it with x.
      Because s is sorted at any time, the element can be found using binary search in log₂(n)time.
  # Let’s illustrate this with the help of an example. Consider below array of integers –>
    {2, 6, 3, 4, 1, 2, 9, 5, 8}
    Below are the steps followed by the algorithm –
    Initialize to an empty set S = {}
    Inserting 2 —- S = {2} – New largest LIS
    Inserting 6 —- S = {2, 6} – New largest LIS
    Inserting 3 —- S = {2, 3} – Replaced 6 with 3
    Inserting 4 —- S = {2, 3, 4} – New largest LIS
    Inserting 1 —- S = {1, 3, 4} – Replaced 2 with 1
    Inserting 2 —- S = {1, 2, 4} – Replaced 3 with 2
    Inserting 9 —- S = {1, 2, 4, 9} – New largest LIS
    Inserting 5 —- S = {1, 2, 4, 5} – Replaced 9 with 5
    Inserting 8 —- S = {1, 2, 4, 5, 8} – New largest LIS

  # To reconstruct the actual LIS we will again use a parent array. Let parent[i] be the predecessor of 
    element with index i in the LIS ending at element with index i.
  # To make things simpler, we can keep in the array s, not the actual integers, but their 
    indices(positions) in the set. We do not keep {1, 2, 4, 5, 8}, but keep {4, 5, 3, 7, 8}.
  # That is v[4] = 1, v[5] = 2, v[3] = 4, v[7] = 5, v[8] = 8.
  
  # If we update properly the parent array, the actual LIS is just reverse of the following:
    v[S[lastElementOfS]], 
    v[parent[S[lastElementOfS]]],
    v[parent[parent[S[lastElementOfS]]]],
   ........................................
  # Now to the important thing - how do we update the parent array? There are two options:
    ● If x > last element in s, then parent[index(x)] = indexOfLastElement. This means the parent of the 
      newest element is the last element. We just prepend x to the end of s.
    ● Otherwise find the index of the smallest element in s, which is >= than x, and change it to x. 
      Here parent[index(x)] = s[index - 1].
*/

// IMPLEMENTATION IS PENDING YET