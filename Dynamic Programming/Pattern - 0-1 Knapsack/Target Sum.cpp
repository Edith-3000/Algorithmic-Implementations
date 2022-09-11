/* Link: https://leetcode.com/problems/target-sum/

   PROBLEM: You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
            Now you have 2 symbols + and -. For each integer, you should choose one from + 
            and - as its new symbol.
            Find out how many ways to assign symbols to make sum of integers equal to 
            target S.

   Ref: https://www.youtube.com/watch?v=Hw6Ygp3JBYw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12
*/

// NOTE: By keen observation it can be deduced that this problem is just a slight variation of 
//       "Count All Subset Pairs With Given Difference.cpp"

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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;

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

int exp(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a);
        a *= a;
        b >>= 1;
    }
    
    return res;
}

vvi dp;

// NOTE: the case of 0 is to be handeled specially
int cnt_subset(vi &v, int sum, int n) {
    // initialisation of dp matrix
    
    // if sum is 0, then only 1 subset is possible(i.e. Ø) 
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int j = 1; j <= sum; j++) dp[0][j] = 0;
    
    // choice diagram code iterative version
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(v[i-1] > j or v[i-1] == 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j - v[i-1]] + dp[i-1][j];
        }
    }
    
    int zer = 0;
    for(int i = 0; i < n; i++) if(v[i] == 0) zer += 1;
    
    return exp(2, zer) * dp[n][sum];
}

int target_sum(vi &v, int n, int target) {
	// sum is to store sum of all elements of v
	int sum = 0;
	for(int i = 0; i < n; i++) sum += v[i];
	
	// base case(s)
	if(target > sum) return 0;
	if((target + sum) % 2 != 0) return 0;
	
	// to avoid overflow
	// (S1 - S2) = target, (S1 + S2) = sum ==> S1 = (target + sum) / 2
	int x = target + (sum - target) / 2;
	
	dp.resize(n+1);
	for(int i = 0; i <= n; i++) dp[i].resize(x+1);
	
	return cnt_subset(v, x, n);
}

void solve()
{
  	int n, target; cin >> n >> target;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    cout << target_sum(v, n, target) << "\n";
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


/*******************************************************************************************************/

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
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;

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

vi dp;

// NOTE: here the case of 0 is being handeled automatically
int cnt_subset(vi &v, int sum, int n) {
    // initialisation of dp matrix
    for(int i = 0; i <= sum; i++) dp[i] = 0;
    
    // if sum is 0, then only 1 subset is possible(i.e. Ø) 
    dp[0] = 1;
    
    // choice diagram code iterative version
    for(int i = 0; i < n; i++) {
        for(int j = sum; j >= v[i]; j--) {
            dp[j] += dp[j - v[i]];
        }
    }
    
    return dp[sum];
}

int target_sum(vi &v, int n, int target) {
	// sum is to store sum of all elements of v
	int sum = 0;
	for(int i = 0; i < n; i++) sum += v[i];
	
	// base case(s)
	if(target > sum) return 0;
	if((target + sum) % 2 != 0) return 0;
	
	// to avoid overflow
	// (S1 - S2) = target, (S1 + S2) = sum ==> S1 = (target + sum) / 2
	int x = target + (sum - target) / 2;
	
	dp.resize(x+1);
	return cnt_subset(v, x, n);
}

void solve()
{
  	int n, target; cin >> n >> target;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    cout << target_sum(v, n, target) << "\n";
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