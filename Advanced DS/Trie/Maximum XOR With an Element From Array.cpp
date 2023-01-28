// Prob: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

// Ref: https://www.youtube.com/watch?v=Q8LhG9Pi5KM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=7&ab_channel=takeUforward

/*****************************************************************************************************************************************************************/

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

vll maximize_xor(vll &v, vvll &queries) {
	int n = sz(v), q = sz(queries);
    
    vvll offline_queries(q);
    
    for(int i = 0; i < q; i++) {
    	offline_queries[i].resize(3);
    	offline_queries[i][0] = queries[i][1];
    	offline_queries[i][1] = queries[i][0];
    	offline_queries[i][2] = i;
    }
    
    sort(offline_queries.begin(), offline_queries.end());
    sort(v.begin(), v.end());
    
    class Trie tr(2);
    vll res(q);
    ll idx = 0;
    
    for(int i = 0; i < q; i++) {
    	ll limit = offline_queries[i][0];
    	ll num = offline_queries[i][1];
    	ll place = offline_queries[i][2];
    	
    	while((idx < n) and (v[idx] <= limit)) {
    		tr.tr_insert(v[idx]);
    		idx += 1;
    	}
    	
    	if(idx == 0) res[place] = -1;            
        else res[place] = tr.tr_get_max(num);
    }    
    
    return res;
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vll v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vvll queries(m);
  	for(int i = 0; i < m; i++) {
  		queries[i].resize(2);
  		cin >> queries[i][0] >> queries[i][1];
  	}
  	
  	vll res = maximize_xor(v, queries);
  	
  	for(auto x: res) {
  		cout << x << " ";
  	}
  	
  	cout << "\n";
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