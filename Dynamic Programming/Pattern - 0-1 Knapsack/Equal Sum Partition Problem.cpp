/* Link: https://www.geeksforgeeks.org/partition-problem-dp-18/
   
   PROBLEM: To determine whether a given set can be partitioned into two subsets such that the 
            sum of elements in both subsets is same.
            NOTE: # The intersection of both the subsets must be Ø.
                  # The union of both the subsets must be the original set.
                  # All the elements of the set are non -ve.

   Ref: https://www.youtube.com/watch?v=UmMh7xp07kY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=8

   Prob. based on this: https://codeforces.com/problemset/problem/1382/D
*/

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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;

/************************************************** DEBUGGER ******************************************************************/

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
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

/******************************************************************************************************************************/

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

vector<vector<bool>> dp;

bool is_subset(vi &v, int sum, int n) {
    // initialisation of dp matrix
    
    // if sum is 0, then Ø is the required subset 
    for(int i = 0; i <= n; i++) dp[i][0] = true;
    for(int j = 1; j <= sum; j++) dp[0][j] = false;
    
    // choice diagram code iterative version
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(v[i-1] <= j) dp[i][j] = dp[i-1][j - v[i-1]] or dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][sum];
}

bool eql_sum_partition(vi &v, int n) {
    ll sum = 0LL;
    for(int i = 0; i < n; i++) sum += v[i];
    
    // odd sum can't be equally partitioned 
    if(sum & 1) return false;
    
    dp.resize(n+1);
    for(int i = 0; i <= n; i++) dp[i].resize(sum/2 + 1);
    
    // find whether a subset with sum = sum/2 is present or not
    return is_subset(v, sum/2, n);
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    if(eql_sum_partition(v, n)) cout << "YES\n";
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

// dp[][] is a 2 D global matrix/vector of vectors, with size (n+1) x (sum/2 + 1), where n is
// the size of v vector.

// Time Complexity: O(n x sum) 
// Auxiliary Space: O(n x sum) 

// NOTE: This solution will not be feasible for big sum value.

/********************************************************************************************************/

// METHOD - 2 (Space Optimization of METHOD - 1)

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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;

/************************************************** DEBUGGER ******************************************************************/

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
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

/******************************************************************************************************************************/

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

vector<bool> dp;

// NOTE: the below function can also be implemented in the following manner :--->
//       https://pastebin.com/wPRnQSL2

bool is_subset(vi &v, int sum, int n) {
    // initialisation of dp matrix by false
    for(int i = 0; i <= sum; i++) dp[i] = false;
    
    // choice diagram code iterative version
    for(int i = 0; i < n; i++) {
        // the element to be included in the sum cannot be greater than the sum
        for(int j = sum; j >= v[i]; j--) {
            // check if sum - v[i] could be formed from a subset using elements before index i
            if(dp[j - v[i]] or (v[i] == j)) dp[j] = 1;
        }
    }
    
    return dp[sum];
}

bool eql_sum_partition(vi &v, int n) {
    ll sum = 0LL;
    for(int i = 0; i < n; i++) sum += v[i];
    
    // odd sum can't be equally partitioned 
    if(sum & 1) return false;
    
    dp.resize(sum/2 + 1);
    
    // find whether a subset with sum = sum/2 is present or not
    return is_subset(v, sum/2, n);
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    if(eql_sum_partition(v, n)) cout << "YES\n";
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

// dp[] is a 1 D global matrix/vector, with size (sum/2 + 1)

// Time Complexity: O(n x sum) 
// Auxiliary Space: O(sum) 

// NOTE: This solution will not be feasible for big sum value.