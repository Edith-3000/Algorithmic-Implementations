// Prob: https://www.geeksforgeeks.org/check-if-the-given-permutation-is-a-valid-bfs-of-a-given-tree/
// Ref: // https://www.youtube.com/watch?v=d8SmH0GnFcs
/******************************************************************************************************/

/* MAIN IDEA ===>
   1. Sort the adjacent list of each node by the position at which they come in the claimed BFS 
      ordering.

   2. Now run a normal BFS on this new adjacency list and check it the BFS formed is the same as 
      the claimed BFS ordering
*/

// Problem: D. Valid BFS?
// Contest: Codeforces - Manthan, Codefest 18 (rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1037/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 27-08-2021 15:05:48 IST (UTC+05:30)
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
vvi g;

// to check if vertex has been visited or not
vb vis;

vi pos;

// #nodes
int n;

// custom comparator to sort the adjacent nodes of a node according to their
// positions in the given BFS order to be validated (here v[])
bool cmp(int x, int y) {
	return pos[x] < pos[y];
}

// NOTE: the bfs() starts with node 1, if required change according to problem
void bfs(vi &order) {
	for(int i = 1; i <= n; i++) vis[i] = 0;
	queue<int> q;
	q.push(1);
	order.pb(1);
	vis[1] = 1;
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		sort(g[cur].begin(), g[cur].end(), cmp);
		
		for(auto x: g[cur]) {
			if(vis[x]) continue;
			vis[x] = 1;
			q.push(x);
			order.pb(x);
	    }	
	}
}

// v[] ==> BFS order to be validated
// pos[i] ==> position of node 'i' in the to be validated BFS order v[]
// order[] ==> vector to store the BFS order which we find out by BFS algorithm

bool is_valid_bfs(vi &v) {
	vset(pos, n + 1, -1);
	for(int i = 0; i < n; i++) pos[v[i]] = i;
	
	vi order;
	bfs(order);
	
	return (v == order);
}

void solve()
{
  	cin >> n;
  	
  	vset(g, n + 1, vi(0));
  	vset(vis, n + 1, 0);
  	  	
  	// 1-based indexing of nodes used
  	for(int i = 1; i < n; i++) {
  		int x, y; cin >> x >> y;
  		g[x].pb(y);
  		g[y].pb(x);
  	}
  	
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	  	
  	if(is_valid_bfs(v)) cout << "Yes\n";
  	else cout << "No\n";  	
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