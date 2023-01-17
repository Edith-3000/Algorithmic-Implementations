// Prob: https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/description/

// Ref: https://www.youtube.com/watch?v=OxAKNGSfbjg&ab_channel=codingMohan

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

// to store the i/p tree
vvi g;

// n = #nodes
int n;

// max_dn[i] = maximum path sum (including price[i]) for node 'i' if we consider only the subtree rooted at node 'i'
//             and all the edges above this subtree are not taken into account
vll max_dn;

// max_up[i] = maximum path sum (excluding price[i]) for node 'i' if we do not take into account all the edges 
//             below the subtree rooted at node 'i'
vll max_up;

void dfs_max_dn(int cur, int par, vi &price) {
	max_dn[cur] = 0LL;
	
	for(auto nbr: g[cur]) {
		if(nbr == par) continue;
		dfs_max_dn(nbr, cur, price); 
		max_dn[cur] = max(max_dn[cur], max_dn[nbr]);
	}
	
	max_dn[cur] += price[cur];
	
	return;
}

void dfs_max_up(int cur, int par, vi &price) {
	multiset<ll> mset;
	
	for(auto nbr: g[cur]) {
		if(nbr == par) continue;
		mset.insert(max_dn[nbr]);
	}
	
	for(auto nbr: g[cur]) {
		if(nbr == par) continue;
		
		ll x = max_dn[nbr];
		mset.erase(mset.find(x));
		
		ll mx = mset.empty() ? 0LL : *(--mset.end());
		max_up[nbr] = max(mx, max_up[cur]) + price[cur];
		
		mset.insert(x);
		
		dfs_max_up(nbr, cur, price);
	}
	
	return;
}

ll calc_final_res(vi &price) {
	ll res = 0LL;
	
	for(int i = 0; i < n; i++) {
		ll max_sum_path = max(max_dn[i], max_up[i] + price[i]);
		ll min_sum_path = price[i];
		res = max(res, max_sum_path - min_sum_path);
	}
	
	return res;
}

void solve()
{
  	cin >> n;
  	
  	vi price(n);
  	
  	g.clear(); g.resize(n);
  	max_dn.clear(); max_dn.resize(n, 0LL);
  	max_up.clear(); max_up.resize(n, 0LL);
  	
  	for(int i = 0; i < n - 1; i++) {
  		int x, y; cin >> x >> y;
  		g[x].pb(y);
  		g[y].pb(x);
  	}
  	
  	for(int i = 0; i < n; i++) {
  		cin >> price[i];
  	}
  	
  	dfs_max_dn(0, -1, price);
  	
  	dfs_max_up(0, -1, price);
  	
  	ll res = calc_final_res(price);
  	
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