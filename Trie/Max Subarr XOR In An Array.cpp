// Prob: https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/
/********************************************************************************************************/

/* UNDERLYING CONCEPT:
   # Naive Approach: * Use two loops to find XOR of all subarrays and return the maximum.
                     * Not efficient time complexity, O(n²)

  # Efficient Solution: * O(n) implementation using Trie under the assumption that integers take fixed number
                          of bits to store.
            			* The basic idea is to create a cumulative XOR array cumulative[], such as 
            			  cumulative[i] stores the XOR of all the numbers from (0 to iᵗʰ index) of the main 
            			  given array/vector.
            			* Once the cumulative[] is formed in O(n) time complexity, then an approach similar 
            			  to "Max XOR Value Pair In Array.cpp" can be used to return the max XOR subarray value.
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

struct Trie {
	// lf represents 0, rg represents 1
	Trie *lf, *rg;
	
	Trie() {
		lf = rg = NULL;
	}
};

// assuming numbers to be 64 bit integers
void trie_insert(Trie *root, ll val) {
	Trie *cur = root;
	
	for(ll i = 63; i >= 0; i--) {
		ll bit = (val >> i) & 1;
		
		if(bit == 0) {
			if(cur->lf == NULL) cur->lf = new Trie();
			cur = cur->lf;
		}
		
		else {
			if(cur->rg == NULL) cur->rg = new Trie();
			cur = cur->rg;
		}
	}
}

ll max_xor_util(Trie *root, ll val) {
	Trie *cur = root;

	// to store the max XOR which number 'val' can form with any 
	// number present in trie
	ll ans = 0LL;
	
	for(ll i = 63; i >= 0; i--) {
		// finding whether the ith bit is set or not
		ll bit = (val >> i) & 1;
		
		if(bit == 0) {
			// check for complementary of 0 i.e. 1 as it will increment our answer
			if(cur->rg) {
				// include it in ans
				ans += (1LL << i);
				cur = cur->rg;
			}
			
			else cur = cur->lf;
		}
		
		else {
			// check for complementary of 1 i.e. 0 as it will increment our answer
			if(cur->lf) {
				// include it in ans
				ans += (1LL << i);
				cur = cur->lf;
			}
			
			else cur = cur->rg;
		}
	}
	
	return ans;
}

Trie* trie_init() {
	Trie *root = new Trie();
	return root;
}

// function to find maximum XOR pair in a given array
ll max_xor(vll &v) {
	int n = sz(v);
	if(n == 0) return 0LL;
	
	ll res = 0LL;
	Trie *root = trie_init();
	
	for(int i = 0; i < n; i++) {
		trie_insert(root, v[i]);
		res = max(res, max_xor_util(root, v[i]));
	}
	
	return res;	
}

ll max_xor_subarr(vll &v) {
	int n = sz(v);
	if(n == 0) return 0LL;
	
	vll pref(n);
	pref[0] = v[0];
	
	for(int i = 1; i < n; i++) {
		pref[i] = v[i];
		pref[i] ^= pref[i-1];
	}
	
	ll res = *max_element(pref.begin(), pref.end());
	res = max(res, max_xor(pref));
	
	return res;
}

void solve()
{  	
  	int n; cin >> n;
  	vll v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  
  	cout << max_xor_subarr(v) << "\n";
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