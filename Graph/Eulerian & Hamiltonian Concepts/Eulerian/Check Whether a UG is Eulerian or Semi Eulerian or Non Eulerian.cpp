/* # For extra knowledge on the topic visit: https://www.geeksforgeeks.org/eulerian-path-and-circuit/
   
   # How to find whether a given graph is Eulerian or not ?
     The problem is same as following question. “Is it possible to draw a given graph without lifting pencil 
     from the paper and without tracing any of the edges more than once”.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
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

vvi g; // adjacency list represenation of graph
vector<bool> vis; // visited array
int n, m; // n = #vertices, m = #edges

void dfs(int curr) {
	vis[curr] = 1;
	for(auto x: g[curr]) {
		if(!vis[x]) dfs(x);
	}
}

bool connectivity_check() {
	// to find a node with degree > 0
	int node = -1; 
	for(int i = 0; i < n; i++) {
		if(g[i].size() > 0) node = i;
	}
	
	// if all nodes have degree = 0 ==> Euler Graph
	if(node == -1) return true;
	
	dfs(node);
	for(int i = 0; i < n; i++) {
		if(!vis[i] && g[i].size() > 0) return false;
	}
	
	return true;
}

int find_graph_type() {
	// Step 1 ==>
	if(connectivity_check() == false) {
		// graph is multiple components edged 
		return 0;
	}
	
	// if connectivity_check is passed (i.e. true) move to Step 2
	// Step 2 ==>
	int cnt = 0; // count of odd-degree vertices
	for(int i = 0; i < n; i++) {
		if(g[i].size() & 1) cnt++;
	}
	
	if(cnt > 2) return 0;
	return cnt == 0 ? 2 : 1;
}

void solve()
{
  	cin >> n >> m;
  	g.clear(); g.resize(n);
  	vis.assign(n, 0);
  	
  	// inputting an UG. 
  	// 0-based indexing is used to represent vertices
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v);
  		g[v].pb(u);
  	}
  	
  	int res = find_graph_type();
  	if(res == 0) cout << "Non Eulerian Graph";
  	else if(res == 1) cout << "Semi Eulerian Graph";
  	else cout << "Eulerian Graph";
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

/*

Sample i/p --->

5 6
1 0
0 2
2 1
0 3
3 4
4 0

Sample o/p --->

Eulerian Graph

*/

// Time complexity: O(|V| + |E|)