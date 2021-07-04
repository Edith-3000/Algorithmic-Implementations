// Prob: https://www.geeksforgeeks.org/find-element-bitonic-array/
// Ref: https://www.youtube.com/watch?v=IjaP8qt1IYI
/****************************************************************************************************/

/* # The main concept behind the algorithm is in a bitonic array ===>
     * The subarray from start to (peak_index-1) is sorted.
     * The subarray from (peak_index) to end is sorted.

   # Therefore - 1. Find the index of peak element in the bitonic array.
                 2. Find the element either in start to (peak_index-1) or (peak_index) to end.

   # NOTE: This method works only for distinct numbers.
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

// return 0-based index
int bin_search(vi &v, int lo, int hi, int k, bool asc) {
    if(lo > hi) return -1;
    
    while(lo <= hi) {
        int m = lo + ((hi - lo) >> 1);
        if(v[m] == k) return m;
        else if(k > v[m]) {
            if(asc) lo = m + 1;
            else hi = m - 1;
        }
        
        else {
            if(asc) hi = m - 1;
            else lo = m + 1;
        }   
    }
    
    return -1;
}

// it returns index of the peak element
int peak_idx(vi &v) {
	int n = sz(v);
	if(n == 0) return -1;
	if(n == 1) return v[0];
	
	int lo = 0, hi = n - 1;
	
	while(lo <= hi) {
		int m = lo + ((hi - lo) >> 1);
		
		if(m == 0) {
			if(v[m] > v[m+1]) return m;
			else return m+1;
		}
		
		else if(m == n - 1) {
			if(v[m] > v[m-1]) return m;
			else return m-1;
		}
		
		else {
			if(v[m] > v[m-1] and v[m] > v[m+1]) return m;
			else if(v[m+1] > v[m]) lo = m + 1;
			else hi = m - 1;
		}
	}
	
	return -1;
}

void solve()
{
	int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
   	int peak = peak_idx(v);
   
   	int q; cin >> q;
   	while(q--) {
   		int x; cin >> x;
   		
   		int a = bin_search(v, 0, peak - 1, x, 1);
   		int b = bin_search(v, peak, n - 1, x, 0);
   		
   		if(a != -1) cout << a;
   		else if(b != -1) cout << b;
   		else cout << -1;
   		
   		cout << "\n";
   	}
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