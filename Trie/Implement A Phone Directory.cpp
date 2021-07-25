// Prob: https://practice.geeksforgeeks.org/problems/phone-directory4628/1#
/********************************************************************************************************/

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
	// everything is by-default "public" in a struct every trie node will 
	// contain an array/vector of pointers each pointing to a similar trie 
	// node, here we're taking size of the array as 256
	Trie *nxt[256];
	
	// each trie structure will also contain an end marker
	// for indicating how many strings end on that trie node
	int end;
	
	// constructor
	Trie() {
		for(int i = 0; i < 256; i++) nxt[i] = NULL;
		end = 0;
	}
};

void trie_insert(Trie *root, string &s) {
	Trie *cur = root;
	
	for(int i = 0; i < sz(s); i++) {
		if(cur->nxt[s[i]] == NULL) cur->nxt[s[i]] = new Trie();
		cur = cur->nxt[s[i]];
	}
	
	cur->end += 1;
}

void trie_search(Trie *root, string &s, int dep, string &op, vs &tmp) {
	// base case
	if(root == NULL) return;
	
	if(dep < sz(s)) {
		op.pb(s[dep]);
		trie_search(root->nxt[s[dep]], s, dep + 1, op, tmp);
		return;
	}
	
	else {    		
    	if(root->end > 0) tmp.pb(op);
		
		for(int i = 0; i < 256; i++) {
			if(root->nxt[i] != NULL) {
				op.pb(char(i));
				trie_search(root->nxt[i], s, dep, op, tmp);
				op.ppb();
			}
		}
	}
}

Trie* trie_init() {
	Trie *root = new Trie();
	return root;
}

vvs auto_complete(vs &v, string &s) {
	int n = sz(v);
	if(n == 0) return vvs();
	
	Trie *root = trie_init();
	
	for(int i = 0; i < n; i++) {
		trie_insert(root, v[i]);
	}
	
	vvs res;
	int m = sz(s);
	
	for(int i = 0; i < m; i++) {
		vs tmp;
		string op = "", t = s.substr(0, i + 1);
		trie_search(root, t, 0, op, tmp);
		
		if(sz(tmp) == 0) {
			op = "0";
			tmp.pb(op);
		}
		
		res.pb(tmp);
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vs v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	string s; cin >> s;
  	
  	vvs res = auto_complete(v, s);
  	
  	for(auto v: res) {
  		for(auto x: v) cout << x << " ";
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

// Time complexity: O(|s| x n * max|v[i]|)
// Space complexity: O(n x max|v[i]|)

/******************************************************************************************************/

// METHOD - 2
// Slightly improved form of the above method, where we don't iterate over again and again.

// Ref: https://www.geeksforgeeks.org/implement-a-phone-directory/