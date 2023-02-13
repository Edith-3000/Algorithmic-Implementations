/* # NOTE: Although this problem should come under "Pattern - Hash Table or Hash Map, Map & Hashing" but since it's following the pattern used to solve
           problems involving variable size sliding window, it's being kept here.
*/

/**************************************************************************************************************************************************************/

// Prob: https://leetcode.com/problems/subarrays-with-k-different-integers/description/

/**************************************************************************************************************************************************************/

// METHOD - 1

// Ref: https://www.geeksforgeeks.org/count-of-subarrays-having-exactly-k-distinct-elements/
//      https://www.youtube.com/watch?v=88mGJqbnPVw

// Makes use of the concept used in "Pattern - Sliding Window/Variable Size Sliding Window/Count Subarrays With At Most K Distinct Elements.cpp"

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

// Function to return the count of subarrays in v[] with at most 'k' distinct elements
ll cnt_subarrays_with_at_most_k_distinct_elements(vi &v, int k) {
    int n = sz(v);
    
    // base case(s)
    if(n == 0) return 0;
    
    // w/o taking into consideration a subarray of length = 0
    if(k == 0) return 0;
    
    // to store the result
    ll res = 0LL;
    
    // to store the frequency of each element in the current window from [i, j]
    map<int, int> cnt;
    
    int i = 0, j = 0;
    
    while(j < n) {
        cnt[v[j]] += 1;
        
        if(sz(cnt) <= k) {
            res += (j - i + 1);
            j += 1;
        }
        
        else {
            while(sz(cnt) > k) {
                cnt[v[i]] -= 1;
                if(cnt[v[i]] == 0) cnt.erase(v[i]);
                i += 1;
            }
            
            // removing this will give wrong result
            res += (j - i + 1);
            
            j += 1;
        }
    }
    
    return res;
}

// Function to return the count of subarrays in v[] with exactly 'k' distinct elements
ll cnt_subarrays_with_k_distinct_elements(vi &v, int k) {
    int n = sz(v);
    if((n == 0) or (k > n)) return 0LL;
    
    ll x = cnt_subarrays_with_at_most_k_distinct_elements(v, k);
    ll y = cnt_subarrays_with_at_most_k_distinct_elements(v, k - 1);
    
    ll res = x - y;
    
    return res;
}

void solve()
{
    int n, k; cin >> n >> k;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    ll res = cnt_subarrays_with_k_distinct_elements(v, k);
    
    cout << res << "\n";
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

/**************************************************************************************************************************************************************/

// METHOD - 2

// In order to achieve the same using a single function call refer --->
// https://www.youtube.com/watch?v=CBSeilNvZHs