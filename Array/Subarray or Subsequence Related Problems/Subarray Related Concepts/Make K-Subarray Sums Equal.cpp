// Prob: https://leetcode.com/problems/make-k-subarray-sums-equal/description/

// Ref: https://www.youtube.com/watch?v=RN3p5xidlWQ&t=1539s&ab_channel=codingMohan

/**********************************************************************************************************************************************************************/

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

// CAUTION : use 0-based indexing for the nodes
struct dsu {
    vi parent, siz;
    
    dsu(int n) {
        parent.clear(); parent.resize(n);
        siz.clear(); siz.resize(n);
    }
    
    void make_set(int n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            siz[i] = 1; 
        }
    }

    int find_set(int v) {
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        int s1 = find_set(a);
        int s2 = find_set(b);

        if(s1 != s2) {
            if(siz[s1] < siz[s2]) swap(s1, s2);
            parent[s2] = s1;
            siz[s1] += siz[s2];
        }
    }
};

ll make_all_elements_equal(vi &v) {
	int n = sz(v);
	if(n == 0) return 0LL;
	
	sort(v.begin(), v.end());
	
	vll cs(n, 0LL);
	
	for(int i = 0; i < n; i++) {
		cs[i] = v[i];
		if(i) cs[i] += cs[i - 1];
	}
	
	ll res = LLONG_MAX;
	
	for(int i = 0; i < n; i++) {
		ll a = i + 1, b = n - a;
		ll sum_a = cs[i], sum_b = cs[n - 1] - cs[i];
		
		ll ans = ((a * v[i]) - sum_a) + (sum_b - (b * v[i]));
		
		res = min(res, ans);
	}
	
	return res;
}

ll make_k_len_circular_subarr_sum_equal(vi &v, int k) {
	int n = sz(v);
	if(n == 0) return 0LL;
	
	vi t;
	
	for(int i = 0; i < (2 * n); i++) {
		t.pb(i % n);
	}
	
	// initialising DSU structure
    struct dsu d(n);
    d.make_set(n);
    
    int idx = 0;
    
    for(int i = k; i <= (n + k - 2); i++) {
    	d.union_sets(t[i], idx);
    	idx += 1;
    	idx %= k;
    }
    
    vvi groups(n);
    
    for(int i = 0; i < n; i++) {
    	int leader = d.find_set(i);
    	groups[leader].pb(v[i]);
    }
    
    ll res = 0LL;
    
    for(int i = 0; i < n; i++) {
    	res += make_all_elements_equal(groups[i]);
    }
    
    return res;
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	ll res = make_k_len_circular_subarr_sum_equal(v, k);
  	
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