/* Link: https://www.geeksforgeeks.org/printing-maximum-sum-increasing-subsequence/ 

   PROBLEM: Given an array of n integers. Write a program to print/construct the maximum sum 
            subsequence of the given array such that the integers in the subsequence are sorted in 
            increasing order. For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should 
            be (1 + 2 + 3 + 100), if the input array is {3, 4, 5, 10}, then output should be 
            (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10.
*/

/*Underlying concept:
  # To print the MSIS, we actually have to store the maximum sum increasing subsequence in 
    lookup table along with storing maximum sum
  # For example, consider v = [ 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11 ]
    The Maximum sum Increasing Subsequence MSIS[i] of subarray v[0...i] that ends with v[i] 
    are ------>

    MSIS[0] – 8
    MSIS[1] – 4
    MSIS[2] – 8 12
    MSIS[3] – 2
    MSIS[4] – 8 10
    MSIS[5] – 4 6
    MSIS[7] – 1
    MSIS[8] – 4 6 9
    MSIS[9] – 4 5
    MSIS[10] – 8 12 13
    MSIS[11] – 2 3
    MSIS[12] – 4 6 9 11
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

vi print_MSIS(vi &v, int n) {
    // MSIS[i] stores the maximum sum increasing subsequence of subarray
    // v[0...i] that ends with v[i]
    vvi MSIS(n);
    
    // sum[i] stores the maximum sum of increasing subsequence ending with v[0]
    vi sum(n, INT_MIN);
    
    // LIS[0] denotes longest increasing subsequence ending with v[0]
    MSIS[0].pb(v[0]);
    
    // sum of maximum increasing subsequence ending with v[0] is v[0] only
    sum[0] = v[0]; 
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(v[j] < v[i] and sum[j] > sum[i]) {
                MSIS[i] = MSIS[j];
                sum[i] = sum[j];
            }
        }
        
        MSIS[i].pb(v[i]);
        sum[i] += v[i];
    }
    
    // idx will contain index of increasing subsequence of maximum length
    int mx = sum[0], idx = 0;
    
    for(int i = 1; i < n; i++) {
        if(sum[i] > mx) mx = sum[i], idx = i;
    }
    
    return MSIS[idx];
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vi res = print_MSIS(v, n);
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

/* # sum[] is a 1 D global matrix or vector of size (n).
     sum[i] for each 0 <= i <= (n-1) stores the maximum sum of increasing subsequence 
     of subarray/subvector v[0...i] 𝙬𝙝𝙞𝙘𝙝 𝙚𝙣𝙙𝙨 𝙬𝙞𝙩𝙝 𝙫[𝙞].
   
   # Time Complexity: O(n²)
   # Auxiliary Space: O(n²).
*/ 

/*Extra Information ---->
  𝙨𝙩𝙙::𝙖𝙘𝙘𝙪𝙢𝙪𝙡𝙖𝙩𝙚() 𝙞𝙣 𝘾++ 𝙎𝙏𝙇
  This function returns the sum of all the values lying in a range between [first, last) with the 
  variable sum.
  Syntax:
        accumulate(first, last, sum);
        first, last : iterators to the first and last elements of range 
                      whose elements are to be added
        sum :  initial value of the sum
*/