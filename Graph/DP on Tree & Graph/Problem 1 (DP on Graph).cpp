// Problem ----> Given an undirected graph with n vertices from 1 to n. Find out the smallest depth of a node
//               that can be visited from a subtree of a given node x in the DFS tree of the graph.

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
const int N = 100005;

vi g[N];
vector<bool> vis(N, false);
vi depth(N); // for storing depth of each vertex
vi dp(N); // for storing the final result

void dfs(int curr, int par, int dep) {
	vis[curr] = true;
	depth[curr] = dep;
	dp[curr] = dep;
	
	for(auto x: g[curr]) {
		if(vis[x] == false) {
			dfs(x, curr, dep+1);
			dp[curr] = min(dp[curr], dp[x]);
		}
		
		// backedge present
		else if(x != par) {
			dp[curr] = min(dp[curr], depth[x]);
		}
	}
	
	return;
}

void solve()
{
	// n = #vertices, m = #edges
  	int n, m; cin >> n >> m;
  	
  	for(int i = 0; i < m; i++) {
  		int x, y; cin >> x >> y;
  		g[x].pb(y);
  		g[y].pb(x);
  	}
  	
  	// starting dfs with vertex 1
  	dfs(1, 0, 0);
  	
  	for(int i = 1; i <= n; i++) {
  		cout << i << " -- " << dp[i] << "\n";
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

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

/*

Sample i/p ---->

12 16
1 3
1 9
9 12
12 11
11 9
3 5
5 7
7 3
5 1
3 6
6 1
6 2
2 8
8 3
2 4
4 10

Sample o/p ---->

1 -- 0
2 -- 1
3 -- 0
4 -- 4
5 -- 0
6 -- 0
7 -- 1
8 -- 1
9 -- 1
10 -- 5
11 -- 1
12 -- 1

*/