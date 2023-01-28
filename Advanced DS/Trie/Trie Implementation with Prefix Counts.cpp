// Prob: https://takeuforward.org/data-structure/implement-trie-ii/
//       https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Ref: https://www.youtube.com/watch?v=K5pcpkEMCN0&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=3&ab_channel=takeUforward

/****************************************************************************************************************************************************************/

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
	// each pointing to a similar trie node,
	// in place of an array/vector a map could also be used
	vector<trie_node*> nxt;
		
	// end = indicates whether a string ended at the trie node above this trie node or not
	// freq = indicating the #strings ending on the trie node above this trie node
	// cnt_pref = indicates the #strings inserted so far that have a prefix ending on the trie node above this trie node
	bool end;
	int freq, cnt_pref;
	
	// constructor
	trie_node(int n) {
		nxt.clear();
		nxt.resize(n);
		
		for(int i = 0; i < n; i++) nxt[i] = NULL;
		
		end = false;
		freq = cnt_pref = 0;
	}
};

struct trie {
	// N is the alphabet size
	int N;
	
	// base defines the base character for possible characters in string
	// like '0' for '0', '1', '2'... and 'a' for 'a', 'b', 'c' as possible 
	// characters in string 
    const char base = 'a';
	
	// root node of trie data structure
	trie_node *root;
	
	// constructor
	trie(int n) {
		N = n;
		root = new trie_node(N);
	}
	
	// inserting a string in trie
	void tr_insert(string &s) {
		trie_node *cur = root;
		
		for(int i = 0; i < sz(s); i++) {
			if(cur->nxt[s[i] - base] == NULL) {
				cur->nxt[s[i] - base] = new trie_node(N);
			}
			
			cur = cur->nxt[s[i] - base];
			cur->cnt_pref += 1;
		}
		
		cur->end = true;
		cur->freq += 1;
	}
	
	// searching a string in trie
	bool tr_search(string &s) {
		trie_node *cur = root;
		
		for(int i = 0; i < sz(s); i++) {
			if(cur->nxt[s[i] - base] == NULL) return 0;		
			cur = cur->nxt[s[i] - base];
		}
		
		return cur->end;
	}
	
	// when calling this function pass cur as root & dep = 0;
	trie_node* tr_delete(trie_node* cur, string &s, int dep) {
		// base case
		if(cur == NULL) return cur;
	
		if(dep == sz(s)) {
			cur->freq -= 1;
			
			if(node_empty(cur) and cur->freq == 0) {
				delete (cur);
				cur = NULL;
		    }
		
			return cur;
	    }
	    
	    if(cur->nxt[s[dep] - base] != NULL) {
	    	cur->nxt[s[dep] - base]->cnt_pref -= 1;
	    }
	    
	    cur->nxt[s[dep] - base] = tr_delete(cur->nxt[s[dep] - base], s, dep + 1);
	    
	    if(node_empty(cur) and cur->freq == 0) {
			delete (cur);
			cur = NULL;
	    }
	    
	    return cur;
	}
	
	// returns the number of strings in the trie that have the string "s" as a prefix
	int tr_cnt_words_starting_with(string &s) {
		trie_node *cur = root;
		
		for(int i = 0; i < sz(s); i++) {
			if(cur->nxt[s[i] - base] == NULL) return 0;		
			cur = cur->nxt[s[i] - base];
		}
		
		return cur->cnt_pref;
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
				op.pb(char(i + base));
				tr_display_util(cur->nxt[i], op);
				op.ppb();
		    }
	    }
	} 
};

void solve()
{
  	struct trie tr(26);
  	
  	// #queries
  	int q; cin >> q;
  	
  	while(q--) {
  		// 1 = insert, 2 = search, 3 = delete, 4 = #strings with given prefix
  		int typ; cin >> typ;
  		string s; cin >> s;
  		
  		if(typ == 1) {
  			tr.tr_insert(s);
  		}
  		
  		else if(typ == 2) {
  			if(tr.tr_search(s)) cout << "Yes\n";
  			else cout << "No\n";
  		}
  		
  		else if(typ == 3){
  			tr.tr_delete(tr.root, s, 0);
  		}
  		
  		else {
  			cout << tr.tr_cnt_words_starting_with(s) << "\n";;
  		}
  	}
  	
  	tr.tr_display();
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