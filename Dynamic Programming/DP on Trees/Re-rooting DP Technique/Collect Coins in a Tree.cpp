// Prob: https://leetcode.com/problems/collect-coins-in-a-tree/description/
// Ref: https://www.youtube.com/watch?v=wUmuRsTGQxs&t=3701s&ab_channel=codingMohan

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

// to store the final result;
int res;

struct node_info {
	// min_edges = for node 'i' minimum #edges required to traverse to
	//             collect all coins and reach back node 'i'
	int min_edges;
	
	// coin_cnt[0] = #nodes in the subtree of node 'i' containing coin and at a distance of 0 from it
	// coin_cnt[1] = #nodes in the subtree of node 'i' containing coin and at a distance of 1 from it
	// coin_cnt[2] = #nodes in the subtree of node 'i' containing coin and at a distance of 2 from it
	// coin_cnt[3] = #nodes in the subtree of node 'i' containing coin and at a distance greater than 2 from it
	vi coin_cnt;
	
	node_info() {
		min_edges = 0;
		coin_cnt.resize(4, 0);
	}
};

void merge_coins(node_info &source, node_info &target) {
	target.coin_cnt[1] += source.coin_cnt[0];
	target.coin_cnt[2] += source.coin_cnt[1];
	target.coin_cnt[3] += (source.coin_cnt[2] + source.coin_cnt[3]);
}

void contribute_to_min_edges(node_info &source, node_info &target) {
	if(source.coin_cnt[2] + source.coin_cnt[3] > 0) {
		target.min_edges += (source.min_edges + 2);
	}
}

void rollback_merge_coins(node_info &source, node_info &target) {
	target.coin_cnt[1] -= source.coin_cnt[0];
	target.coin_cnt[2] -= source.coin_cnt[1];
	target.coin_cnt[3] -= (source.coin_cnt[2] + source.coin_cnt[3]);
}

void rollback_contribute_to_min_edges(node_info &source, node_info &target) {
	if(source.coin_cnt[2] + source.coin_cnt[3] > 0) {
		target.min_edges -= (source.min_edges + 2);
	}
}

void dfs1(int cur, int par, vector<node_info> &dp1, vi &coins) {
	if(coins[cur] == 1) {
		dp1[cur].coin_cnt[0] += 1;
	}
	
	for(auto nbr: g[cur]) {
		if(nbr == par) continue;
		
		dfs1(nbr, cur, dp1, coins);
		
		merge_coins(dp1[nbr], dp1[cur]);
		contribute_to_min_edges(dp1[nbr], dp1[cur]);
	}
}

void dfs2(int cur, int par, vector<node_info> &dp1, vector<node_info> &dp2) {
	res = min(res, dp2[cur].min_edges);
	
	for(auto nbr: g[cur]) {
		if(nbr == par) continue;
		
		dp2[nbr] = dp1[nbr];
		
		node_info x = dp2[cur];
		
		rollback_merge_coins(dp2[nbr], x);
		rollback_contribute_to_min_edges(dp2[nbr], x);
		
		merge_coins(x, dp2[nbr]);
		contribute_to_min_edges(x, dp2[nbr]);
		
		dfs2(nbr, cur, dp1, dp2);
	}
}

int collect_the_coins(vvi &edges, vi &coins) {
	g.clear(); g.resize(n);
	res = INT_MAX;
	
	for(int i = 0; i < (n - 1); i++) {
		int x = edges[i][0], y = edges[i][1];
  		g[x].pb(y);
  		g[y].pb(x);
	}
	
	vector<node_info> dp1(n), dp2(n);
	
	dfs1(0, -1, dp1, coins);
	
	dp2[0] = dp1[0];	
	dfs2(0, -1, dp1, dp2);
	
	return res;
}

void solve()
{
  	cin >> n;
  	
  	vvi edges(n - 1, vi(2));
  	
  	for(int i = 0; i < (n - 1); i++) {
  		cin >> edges[i][0] >> edges[i][1];
  	}
  	
  	vi coins(n);
  	
  	for(int i = 0; i < n; i++) {
  		cin >> coins[i];
  	}
  	
  	int res = collect_the_coins(edges, coins);
  	
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