/* Link: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
   
   PROBLEM: Given an array arr[] which represents the chain of matrices such that the ith 
            matrix Aᵢ is of dimension arr[i-1] x arr[i]. We need to write a function MCM()
            that should return the minimum number of multiplications needed to multiply 
            the chain i.e. minimum cost of multiplying the matrices.

                                           OR

            Given a sequence of matrices, find the most efficient way to multiply these 
            matrices together. The problem is not actually to perform the multiplications,
            but merely to decide in which order to perform the multiplications, so that the
            cost of multiplying these matrices is  minimum.
*/

/******************************************************************************************************************************************************************/

/* # The cost (i.e. #multiplications) of multiplying 2 matrices of order (a × b) & (b × c)
     is equal to (a * b * c).

   # If n elements are given in array then there are (n-1) matrices. 😅

   # In the algorithm written below ->
     ■ i is initialised as 1 (∵ 1ˢᵗ matrix A₁ is of order v[0] × v[1] ≡ v[i-1] × v[i])
     ■ j is initialised as v.size()-1 
       (∵ last matrix A₍ₙ₋₁₎ is of order v[v.size()-2] × v[v.size()-1] ≡ v[j-1] × v[j]), 
       where n is v.size()
*/

/******************************************************************************************************************************************************************/

// RECURSIVE IMPLEMENTATION
// Ref: https://www.youtube.com/watch?v=kMK148J9qEE&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=33

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

ll mcm(vi &v, int i, int j) {
    // base condition(s)
    // if(i > j ==> v[] is empty)
    // if(i == j ==> v[] has only 1 element)
    if(i >= j) return 0;
    
    // to store final result
    ll res = LLONG_MAX;
    
    // choice diagram code
    // place parenthesis at different places by help of the suitable "k loop scheme" b/w 
    // first and last matrix, recursively calculate cost of multiplications for each 
    // parenthesis placement and return the minimum cost
    
    for(int k = i; k <= (j - 1); k++) {
        // (v[i-1] * v[k] * v[j]) is the cost of multiplying matrices from
        // (i to k) and (k+1 to j) 
        ll tmp = mcm(v, i, k) + mcm(v, k + 1, j) + ((ll)v[i-1] * v[k] * v[j]);

        res = min(res, tmp);
    }
    
    return res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    cout << mcm(v, 1, n - 1) << "\n";
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

/******************************************************************************************************************************************************************/

// MEMOIZED IMPLEMENTATION
// Ref: https://www.youtube.com/watch?v=9uUVFNOT3_Y&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=34

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

vvll dp;

ll mcm(vi &v, int i, int j) {
    // base condition(s)
    // if(i > j ==> v[] is empty)
    // if(i == j ==> v[] has only 1 element)
    if(i >= j) return 0;
    
    // check if already calculated or not
    if(dp[i][j] != -1) return dp[i][j];
    
    // to store final result
    ll res = LLONG_MAX;
    
    // choice diagram code
    // place parenthesis at different places by help of the suitable "k loop scheme" b/w 
    // first and last matrix, recursively calculate cost of multiplications for each 
    // parenthesis placement and return the minimum cost
    
    for(int k = i; k <= (j - 1); k++) {
        // (v[i-1] * v[k] * v[j]) is the cost of multiplying matrices from
        // (i to k) and (k+1 to j) 
        ll tmp = mcm(v, i, k) + mcm(v, k + 1, j) + ((ll)v[i-1] * v[k] * v[j]);
        
        res = min(res, tmp);
    }
    
    return dp[i][j] = res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    dp.clear();
    dp.resize(n);
    for(int i = 0; i < n; i++) dp[i].resize(n, -1);
    
    cout << mcm(v, 1, n - 1) << "\n"; 
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

// dp[][] is a 2 D global matrix/vector of vectors, with size (v.size()) x (v.size()) 
// and initialized with -1, memset(dp, -1, sizeof(dp));
// It's dimensions are [v.size()] × [v.size()], as max values of the changing parameters
// i.e. i and j can be v.size() - 1

// Time complexity: O(n^3)
// Space complexity: O(n^2)

/******************************************************************************************************************************************************************/

// TABULATION IMPLEMENTATION (Real DP ;))
// Ref: https://www.youtube.com/watch?v=pEYwLmGJcvs&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=30

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

// tabulation implementation using "Gap Method"
ll mcm(vi &v) {
    int n = sz(v);
    if(n == 0) return 0LL;

    vvll dp;

    dp.clear();
    dp.resize(n - 1);
    for(int i = 0; i < n - 1; i++) dp[i].resize(n - 1);

    for(int g = 0; g < sz(dp); g++) {
        for(int i = 0, j = g; j < sz(dp); i++, j++) {
            if(g == 0) dp[i][j] = 0;

            else if(g == 1) dp[i][j] = (ll)v[i] * v[j] * v[j+1];
            
            else {
                ll res = LLONG_MAX;

                for(int k = i; k <= (j - 1); k++) {
                    ll tmp = dp[i][k] + dp[k+1][j] + ((ll)v[i] * v[k+1] * v[j+1]);
                    res = min(res, tmp);
                }
                
                dp[i][j] = res;
            }
        }
    }
    
    return dp[0][sz(dp) - 1];
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    cout << mcm(v) << "\n"; 
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

// dp[][] is a 2 D global matrix/vector of vectors, with size (v.size() - 1) x (v.size() - 1) 

// Time complexity: O(n^3)
// Space complexity: O(n^2)

/******************************************************************************************************************************************************************/

// ANOTHER TABULATION APPROACH
// Ref: https://www.youtube.com/watch?v=pDCXsbAw5Cg&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=51&ab_channel=takeUforward

/******************************************************************************************************************************************************************/

// TABULATION IMPLEMENTATION (Real DP ;))
// Slightly different variation from the above one, but the above with "Gap Method" is more easy.

/* eg dp[][] matrix of dimensions 4 × 4 ---->
                       
                          j →
                     0    1    2    3
                   ---------------------
                 0 |Inv |Inv |Inv |Inv |  
                   |----|----|----|----|
               i 1 |Inv |  0 |	  | Res|
               ↓   |----|----|----|----|⏎(L=3)(diagonal)  
                 2 |Inv |Inv | 0  |    |
                   |----|----|----|----|⏎(L=2)(diagonal)  
                 3 |Inv |Inv |Inv | 0  |
                   |----|----|----|----|
                                        ⏎(L=1)(diagonal)   
        *Inv = Invalid              
*/

ll mcm(vi &v, int n) {
    // initialisation of dp matrix
    // The lower Δˡʳ matrix is not initialised as in that part (i > j),
    // which is an invalid case.
    // Similarly dp[0][0.....(n-1)] is also not initialised as it's invalid
      
    // cost is zero when multiplying one matrix (i.e. L = 1),
    // where L = chain length
    //         = #matrix(es) taken into consideration at a time
    for(int i = 1; i < n; i++) dp[i][i] = 0;
    
    // choice diagram code iterative version
    for(ll L = 2; L < n; L++) {
       // for each chain length L, i = left end index
       //                          j = right end index
       for(ll i = 1; i < (n-L+1); i++) {
          ll j = i + L - 1;
          dp[i][j] = LLONG_MAX;
          
          // "k loop scheme" for corresponding i and j
          for(long long k=i; k<=(j-1); k++) {
             // (v[i-1] * v[k] * v[j]) is the cost of multiplying matrices from
             // (i to k) and (k+1 to j) 
             ll temp = dp[i][k] + dp[k+1][j] + (v[i-1] * v[k] * v[j]);
             
             if(temp < dp[i][j]) dp[i][j]=temp;
          }
       }
    }
    
    // final result
    return dp[1][n-1]; 
}

// here n=v.size()
// Time Complexity: O(n³)
// Auxiliary Space: O(n²)

// dp[][] is a 2 D global matrix/vector of vectors, with size (v.size()) x (v.size())