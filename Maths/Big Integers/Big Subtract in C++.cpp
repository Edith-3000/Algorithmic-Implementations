// Prob: https://www.geeksforgeeks.org/difference-of-two-large-numbers/
/*******************************************************************************************************/

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

// returns true if s1 (i.e. x) is smaller than s2 (i.e. y)
bool is_smaller(vi &x, vi &y) {
    int n = sz(x), m = sz(y);
    
    if(n < m) return 1;
    if(n > m) return 0;
    
    for(int i = 0; i < n; i++) {
    	if(x[i] > y[i]) return 0;
    	else if(x[i] < y[i]) return 1;
    }
    
    return 0;
}

vi big_sub_helper(vi &x, vi &y) {  
	// before proceeding further, make sure x is not smaller than y
	if(is_smaller(x, y)) x.swap(y);
 
    // reverse the numbers so that we can subtract them from units place
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
	
	// to store the result
    vi res;

    int len = sz(y);

    for(int i = 0; i < len; i++) {
    	if(x[i] < y[i]) {
    		// borrow from next 10's place
          	x[i+1]--; 
          	// insert answer for current index
          	res.pb(10 + x[i] - y[i]); 
        }
       
    	// simply subtract and push the result when x[i] >= y[i]
       	else res.pb(x[i] - y[i]);
    }
    
    // if there are any digits left in x
    if(sz(x) > len) {
    	for(int i = len; i < sz(x); i++) {  
        	// x[i] can be -ve if we had borrowed repeatedly
          	// from it or initially it was 0 & we borrowed from it
          	if(x[i] < 0) {
            	x[i+1]--;
          		res.pb(10 + x[i]);
            }

        	else res.pb(x[i]);
        }
    }
	
	// remove all the leading zeros in the result 
    if(sz(res) != 1) {
    	while(res.back() == 0) {
        	res.erase(prev(res.end(), 1));
        }	
    }
    
    if(sz(res) == 0) res.pb(0);
    
    // reverse back the vectors
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    
    // reverse res to get back actual answer and return res
    reverse(res.begin(), res.end());
    return res;
}

vi big_sub(string &s1, string &s2) {
    int n = sz(s1), m = sz(s2); 
    vi x, y;
    
    for(int i = 0; i < n; i++) x.pb(s1[i] - '0');
    for(int i = 0; i < m; i++) y.pb(s2[i] - '0');
    
    if(n == 0) return y;
    if(m == 0) return x;
    
    vi res = big_sub_helper(x, y);
    return res;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    
    vi res = big_sub(s1, s2);
    
    for(auto x: res) cout << x;
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