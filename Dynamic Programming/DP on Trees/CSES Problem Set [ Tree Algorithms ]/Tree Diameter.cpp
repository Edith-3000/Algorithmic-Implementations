// METHOD - 1 O(n^2)

/* # Run a DFS from every node of the tree and in every iteration, find the node which is at the farthest
     distance from the selected source node.

   # Update the final result after every iteration.
*/

/****************************************************************************************************************************************************************************************************************************************************************************************************************************/

// METHOD - 2 
// Ref: https://www.youtube.com/watch?v=FQLPNQppBNs
//      https://www.youtube.com/watch?v=x5ZH4pnts7Q

// For Proof: --->
// https://stackoverflow.com/questions/20010472/proof-of-correctness-algorithm-for-diameter-of-a-tree-in-graph-theory#:~:text=Proof%20of%20correctness%3A%20Algorithm%20for%20diameter%20of%20a%20tree%20in%20graph%20theory,-algorithm%20tree%20graph&text=In%20order%20to%20find%20the,BFS%20will%20yield%20the%20diameter
// https://pasteboard.co/JZp6CVR.jpg

/* ALGORITHM --->
   # We can find diameter in only 2 DFS runs.
   # Take any arbitrary node as root node, and find the node which is farthest from it. Let this node
     be x.
   # Run a DFS from node x, and find the maximum distance of this node from any other node, this distance
     will be the diameter of the tree.
*/

// Problem: Tree Diameter
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1131
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 28-04-2021 07:54:23 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

// to store the i/p tree
vi tree[200001];

// the #vertices
int n;

// the maximum distance of the farthest node
// from the source node taken
int mx;

// the node which is at the maximum distance
// from the source node taken
int farthest;

void dfs(int curr, int dist, int par) {
	if(dist > mx) {
		mx = dist;
		farthest = curr;
	}
	
	for(auto child: tree[curr]) {
		if(child != par) dfs(child, dist + 1, curr);
	}
}

void solve()
{
  	cin >> n;
  	for(int i = 1; i < n; i++) {
  		int u, v; cin >> u >> v;
  		tree[u].pb(v);
  		tree[v].pb(u);
  	}
  	
  	// initialising max distance
  	mx = -1;
  	
  	// arbitrarily choosing any root node & finding 
  	// the node which is at max distance from it
  	dfs(1, 0, 0);
  	
  	// again initialising max distance
  	mx = -1;
  	
  	// running DFS for the second time, taking the farthest
  	// node found in the 1st DFS as the source node
  	dfs(farthest, 0, 0);
  	
  	cout << mx << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
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

/******************************************************************************************************/

// METHOD - 3

// Problem: Tree Diameter
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1131
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 06-02-2021 00:23:11 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

// to store the i/p tree
vi tree[200001];

// downPath[i] = length of the longest path in the subtree rooted
// at node 'i' s.t. path starts at node 'i' OR simply it is the height
// or depth of the subtree rooted at node 'i'
int downPath[200001];

// diameter[i] = diameter of the tree if tree assumed to be rooted 
// at node 'i' 
// WLOG (Without Loss Of Generality) here, we assume the tree to be 
// rooted at node 1.
int diameter[200001];

// the #vertices
int n;

void evaluate_downPaths(int curr, int par) {
	int downPath_len = 0;
	bool is_leaf = 1;
	
	for(auto child: tree[curr]) {
		if(child != par) {
			is_leaf = 0;
			evaluate_downPaths(child, curr);
			downPath_len = max(downPath_len, downPath[child]);
		}
	}
	
	if(is_leaf) downPath[curr] = 0;
	else downPath[curr] = 1 + downPath_len;
}

void evaluate_diameter(int curr, int par) {
	// to store the answer if the diameter does not passes
	// through 'curr'
	int ans = 0; 
	vi children_downPaths;
	
	for(auto child: tree[curr]) {
		if(child != par) {
			evaluate_diameter(child, curr);
			ans = max(ans, diameter[child]);
			children_downPaths.pb(downPath[child]);
		}
	}
	
	int num_of_children = children_downPaths.size();
	sort(children_downPaths.begin(), children_downPaths.end());
	
	if(num_of_children == 0) diameter[curr] = 0;
	else if(num_of_children == 1) diameter[curr] = 1 + children_downPaths[0];
	else diameter[curr] = 2 + children_downPaths[num_of_children - 1] + children_downPaths[num_of_children - 2];
	
	// final diameter
	diameter[curr] = max(ans, diameter[curr]);
}

void solve()
{
  	cin >> n;
  	for(int i = 1; i < n; i++) {
  		int u, v; cin >> u >> v;
  		tree[u].pb(v);
  		tree[v].pb(u);
  	}
  	
  	evaluate_downPaths(1, 0);
  	evaluate_diameter(1, 0);
  	cout << diameter[1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

/******************************************************************************************************/

// METHOD - 4
// Ref: https://www.youtube.com/watch?v=QHNqsPygPeA&list=PLzVLIdIx9dQxCKaiktxELrtXtnItgAAIr&index=6

// Problem: Tree Diameter
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1131
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 06-09-2021 16:29:06 IST (UTC+05:30)
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

// to store the i/p tree
vi g[200001];

// dp[i][0] = length of the longest path in the subtree rooted at i, such that
//            i is part of the path but not one of the end point of path.
// dp[i][1] = length of the longest path in the subtree rooted at i, such that
//            i is part of the path and is one of the end point of path.
int dp[200001][2];

// n = the #vertices, res = diameter of tree
int n, res;

bool is_leaf(int cur) {
	return cur != 1 and sz(g[cur]) == 1;
}

void dfs(int cur, int par) {
	// check for base case
	if(is_leaf(cur)) {
		dp[cur][0] = dp[cur][1] = 0;
		return;
	}
	
	// a will store the dp[x][1] values of children of cur
	vi a;
	
	for(auto x: g[cur]) {
		if(x == par) continue;
		dfs(x, cur);
		a.pb(dp[x][1]);
	}
	
	sort(a.rbegin(), a.rend());
	
	if(sz(a) == 1) {
		dp[cur][0] = 0;
		dp[cur][1] = 1 + a[0];
	}
	
	else {
		dp[cur][0] = 2 + a[0] + a[1];
		dp[cur][1] = 1 + a[0];
	}
	
	res = max({res, dp[cur][0], dp[cur][1]});
}

// Function which evaluates the diameter of tree (it counts the #edges in the path)
int diameter() {
	res = 0;
	if(n == 1) return res;	
	dfs(1, 0);
	return res;
}

void solve()
{
  	cin >> n;
  	
  	for(int i = 1; i < n; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v);
  		g[v].pb(u);
  	}
  	
  	cout << diameter() << "\n";
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