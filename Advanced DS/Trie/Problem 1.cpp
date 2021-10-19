// Although for this problem the following less complicated implementation could also be used : --->
// https://pastebin.com/3Uq5sQfq
/********************************************************************************************************/

// Problem: D. Vasiliy's Multiset
// Contest: Codeforces - Codeforces Round #367 (Div. 2)
// URL: https://codeforces.com/problemset/problem/706/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Parsed on: 19-10-2021 15:08:03 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

struct trie_node {
	// every trie node will contain an array/vector of pointers 
	// each pointing to a similar trie node,
	// in place of an array/vector a map could also be used
	vector<trie_node*> nxt;
	
	// end = indicates whether a base N represented num. ended at the trie node above this trie node or not
	// freq = indicating the #base N represented nums. ending on the tire node above this trie node
	bool end;
	int freq;
	
	// constructor
	trie_node(int n) {
		nxt.clear();
		nxt.resize(n);
		for(int i = 0; i < n; i++) nxt[i] = NULL;
		end = false;
		freq = 0;
	}
};

struct trie {
	// N is the base of the numeric system in which numbers are stored in trie
	// eg. for binary it will be 2
	int N;
	
	// root node of trie data structure
	trie_node *root;
	
	// constructor
	trie(int n) {
		N = n;
		root = new trie_node(N);
	}
	
	// inserting a number in trie
	void tr_insert(vi &v) {
		trie_node *cur = root;
		
		for(int i = 0; i < sz(v); i++) {
			if(cur->nxt[v[i]] == NULL) {
				cur->nxt[v[i]] = new trie_node(N);
			}
			
			cur = cur->nxt[v[i]];
		}
		
		cur->end = true;
		cur->freq += 1;
	}
	
	// searching a number in trie
	bool tr_search(vi &v) {
		trie_node *cur = root;
		
		for(int i = 0; i < sz(v); i++) {
			if(cur->nxt[v[i]] == NULL) return 0;		
			cur = cur->nxt[v[i]];
		}
		
		return cur->end;
	}
	
	// when calling this function pass cur as root & dep = 0;
	trie_node* tr_delete(trie_node* cur, vi &v, int dep) {
		// base case
		if(cur == NULL) return cur;
	
		if(dep == sz(v)) {
			cur->freq -= 1;
			if(cur->freq == 0) {
				delete (cur);
				cur = NULL;
		    }
		
			return cur;
	    }
	    
	    cur->nxt[v[dep]] = tr_delete(cur->nxt[v[dep]], v, dep + 1);
	    
	    if(node_empty(cur) and cur->freq == 0) {
			delete (cur);
			cur = NULL;
	    }
	    
	    return cur;
	}
	
	// checks if a trie node is empty or not
	bool node_empty(trie_node *it) {
		for(int i = 0; i < N; i++) {
			if(it->nxt[i] != NULL) return 0;
		}
		
		return 1;
	}
	
	// displays the content of Trie in lexographically sorted order.
	void tr_display() {
		string op = "";
		trie_node *cur = root;
		tr_display_util(cur, op);
	}
	
	void tr_display_util(trie_node *cur, string &op) {
		if(cur == NULL) return;
	
		if(cur->freq != 0) {
			cout << cur->freq << " --> " << op << "\n";
	    }
		
		for(int i = 0; i < N; i++) { 
			if(cur->nxt[i] != NULL) {
				op.pb(char(i + '0'));
				tr_display_util(cur->nxt[i], op);
				op.ppb();
		    }
	    }
	}
	
	// function to find out the maximum XOR value between input x and any num present in trie
	ll max_xor(ll x) {
		trie_node *cur = root;
		ll res = 0LL;
		
		for(ll i = 63; i >= 0; i--) {
			// finding whether the ith bit is set or not
			ll bit = (x >> i) & 1;
			if(bit == 0) {
				// check for complementary of 0 i.e. 1 as it will increment our answer
				if(cur->nxt[1] != NULL) res += (1LL << i), cur = cur->nxt[1];
				else cur = cur->nxt[0];
			}
			
			else {
				// check for complementary of 1 i.e. 0 as it will increment our answer
				if(cur->nxt[0] != NULL) res += (1LL << i), cur = cur->nxt[0];
				else cur = cur->nxt[1];
			}
		}
		
		return res;
	}
};

void solve()
{
  	// assuming 64 bit binary numbers for this problem
  	struct trie tr(2);
  	
  	vi v(64, 0);
  	tr.tr_insert(v);
  	
  	int q; cin >> q;
  	while(q--) {
  		char tp; ll x; cin >> tp >> x;
  		
  		if(tp == '+' or tp == '-') {
  			for(ll i = 63; i >= 0; i--) {
  				ll bit = (x >> i) & 1;
  				v[i] = bit;
  		    }
  		
  			reverse(v.begin(), v.end());	
  		}
  		
  		if(tp == '+') tr.tr_insert(v);
  		else if(tp == '-') tr.tr_delete(tr.root, v, 0);
  		else cout << tr.max_xor(x) << "\n";
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