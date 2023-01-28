// Prob: https://www.geeksforgeeks.org/maximum-xor-of-two-numbers-in-an-array/
//       https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

// Ref: https://takeuforward.org/data-structure/maximum-xor-of-two-numbers-in-an-array/

/*********************************************************************************************************************************************************************/

/* UNDERLYING CONCEPT:
   # Naive Approach: A Simple Solution is to generate all pairs of the given array and compute XOR of the 
                     pairs. Finally, return maximum XOR value. This solution takes O(n^2) time.
  
   # An efficient approach can be designed by the help of Trie.
*/

/*********************************************************************************************************************************************************************/

// IMPLEMENTATION USING struct & class (TEMPLATED IMPLEMENTATION)

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

struct trie_node {
	// every trie node will contain an array/vector of pointers 
	// each pointing to a similar trie node
	vector<trie_node*> links;
	
	// constructor
	trie_node(int n) {
		links.clear();
		links.resize(n, NULL);
	}
};

class Trie {
	private:
		// N is the size of links[] in each trie_node
		int N;
		
		// root node of trie data structure
		trie_node* root;
		
	public:
		// constructor
		Trie(int n) {
			N = n;
			root = new trie_node(N);
		}
		
		// inserting a number in trie
		// NOTE: here the number is taken as long long, so 64-bits are taken 
		void tr_insert(ll num) {
			trie_node* itr = root;
			
			for(ll i = 63; i >= 0; i--) {
				ll bit = (num >> i) & 1LL;
				
				if(itr->links[bit] == NULL) {
					itr->links[bit] = new trie_node(N);
				}
				
				itr = itr->links[bit];
			}
		}
		
		// to find the max XOR which number 'num' can form with any number present in trie
		ll tr_get_max(ll num) {
			trie_node* itr = root;
			
			ll ans = 0LL;
			
			for(ll i = 63; i >= 0; i--) {
				// finding whether the ith bit is set or not
				ll bit = (num >> i) & 1LL;
				
				// check for complementary of ith bit as in case of XOR it will increment the answer
				if(itr->links[1 - bit] != NULL) {
					// include it in ans
					ans += (1LL << i);
					itr = itr->links[1 - bit];
				}
				
				// if complementary not present move to the same bit
				else itr = itr->links[bit];
			}
			
			return ans;
		}
};

ll max_xor_of_pair(vll &v) {
	int n = sz(v);
	if(n == 0) return 0LL;
	
	class Trie tr(2);
	
	ll res = 0LL;
	
	for(int i = 0; i < n; i++) {
		tr.tr_insert(v[i]);
		res = max(res, tr.tr_get_max(v[i]));
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vll v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  
  	cout << max_xor_of_pair(v) << "\n";
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

// Time complexity: O(64 x n) = O(n)

/*********************************************************************************************************************************************************************/

// IMPLEMENTATION w/o USING class

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

void solve()
{  	
  	int n; cin >> n;
  	vll v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  
  	cout << max_xor(v) << "\n";
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

// Time complexity: O(64 x n) = O(n)