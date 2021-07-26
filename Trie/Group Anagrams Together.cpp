// Prob: https://www.techiedelight.com/print-all-pairs-of-anagrams/
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
	// each node stores a map to its child nodes
	map<char, Trie*> child;
	
	// stores anagrams in the leaf node
    string words;
};

void trie_insert(Trie *root, string &sorted, string &original) {
	Trie *cur = root;
	int n = sz(sorted);
	
	for(int i = 0; i < n; i++) {
		// create a new node if the path doesn't exist
		if(cur->child.find(sorted[i]) == cur->child.end()) {
			cur->child[sorted[i]] = new Trie();	
		}
		
		// go to the next node
		cur = cur->child[sorted[i]];
	}
	
	// anagrams will end up at the same leaf node
	cur->words += (original + ' ');
}

void find_anagrams(Trie *root, vvs &res) {
	// base case
	if(root == NULL) return;
	
	if(root->words.size() != 0) {
		vs tmp;
		string s = "";
		int n = sz(root->words);
		
		for(int i = 0; i + 1 < n; i++) {
			if(root->words[i] == ' ') tmp.pb(s), s = "";
			else s.pb(root->words[i]);
		}
		
		if(sz(s) != 0) tmp.pb(s);		
		res.pb(tmp);
	}
	
	for(auto x: root->child) {
		find_anagrams(x.S, res);
	}
}

Trie* trie_init() {
	Trie *root = new Trie();
	return root;
}

vvs grp_anagrams(vs &v) {
	int n = sz(v);
	if(n == 0) return vvs();
	
	Trie *root = trie_init();
	
	for(int i = 0; i < n; i++) {
		string sorted = v[i];
		sort(sorted.begin(), sorted.end());
		
		trie_insert(root, sorted, v[i]);
	}
	
	vvs res;
	
	// print all anagrams together
    find_anagrams(root, res);
    
    return res;
}

void solve()
{  	
  	int n; cin >> n;
  	vs v(n);
  	
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vvs res = grp_anagrams(v);
  	
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

// Time complexity: O(n x m x log(m)), where N is the total number of words and M
//                  is the maximum word length.