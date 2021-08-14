// Ref: https://www.youtube.com/watch?v=3UXK0Mab5fM
//      https://www.youtube.com/watch?v=-wUgqgClBIM
//      https://codeforces.com/contest/1324/submission/90631691
/********************************************************************************************************/

// Problem: F. Maximum White Subtree
// Contest: Codeforces - Codeforces Round #627 (Div. 3)
// URL: https://codeforces.com/contest/1324/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 14-08-2021 20:38:46 IST (UTC+05:30)
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

// to store the i/p graph
vvll g;

// dp1[i] = answer for node 'i' if we consider only the subtree rooted at node 'i'
//          and all the edges above this subtree are not taken into account

// dp2[i] = final answer for node 'i' if we consider the tree rooted at node 'i'
vll dp1, dp2;

// to store the color for each vertex
vll v;

// n = #nodes
int n;

void dfs1(int cur, int par) {
	// initialising value for cur node
	dp1[cur] = (v[cur] == 1) ? 1 : -1;
	
	for(auto x: g[cur]) {
		if(x == par) continue;
		dfs1(x, cur);
		dp1[cur] += max(0LL, dp1[x]);
	}
}

void dfs2(int cur, int par) {
	// value for cur node
	dp2[cur] = dp1[cur];
	
	for(auto x: g[cur]) {
		// if node already visited
		if(x == par) continue;
		
		// shifting the root from cur root to it's child x, it involves 2 steps ===>
		// 1. remove the contribution of x in answer of cur
		// 2. so now x becomes parent of cur, so add contribution of cur in answer of x
		dp1[cur] -= max(0LL, dp1[x]);
		dp1[x] += max(0LL, dp1[cur]);
		
		// recursively calculating values for child nodes
		dfs2(x, cur);
		
		// rolling back the changes done previously
		// 1. remove the contribution of cur in answer of x
		// 2. add contribution of x in answer of cur
		dp1[x] -= max(0LL, dp1[cur]);
		dp1[cur] += max(0LL, dp1[x]); 
	}
}

void solve()
{
  	cin >> n;
  	
  	vset(g, n + 1, vll(0));
  	vset(dp1, n + 1, -INF);
  	vset(dp2, n + 1, -INF);
  	vset(v, n + 1, -INF);
  	
  	for(int i = 1; i <= n; i++) cin >> v[i];
  	
  	for(int i = 1; i < n; i++) {
  		int x, y; cin >> x >> y;
  		g[x].pb(y);
  		g[y].pb(x);
  	}
  	
  	// filling up dp1
  	dfs1(1, 0);
  	
  	// re-rooting technique comes to picture, here we find answer
  	// by considering every node as a root 
  	dfs2(1, 0);
  	
  	for(int i = 1; i <= n; i++) {
  		cout << dp2[i] << " ";
  	}
  	
  	cout << "\n";
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