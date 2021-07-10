/* # For more info visit: https://www.geeksforgeeks.org/multi-source-shortest-path-in-unweighted-graph/
   # REMEMBER: Shortest path can be found by BFS (single source or multi source) only in UNWEIGHTED GRAPHS.
   # The below could have also been implemented using normal BFS --->
     We can loop through the vertices (cells of the i/p matrix) and from each vertex run a BFS to find the 
     closest 'mx' node (mx is defined in the comments of below algorithm) from that vertex & repeatedly
     find out the max of these. But this will take O(V x E), whill will time out.

   # A better method is to use the Multisource BFS which is a modification of BFS.
   # We will put the all source vertices to the queue at first rather than a single vertex which was in case of 
     standard BFS. This way Multisource BFS will first visit all the source vertices. After that it will visit 
     the vertices which are at a distance of 1 from all source vertices, then at a distance of 2 from all source 
     vertices and so on and so forth.
     Thus Time complexity of this better approach will be: O(|V| + |E|)
*/

// Problem: Snakes and transition from Capitalism to Socialism
// Contest: CodeChef - Practice(Easy)
// URL: https://www.codechef.com/problems/SNSOCIAL
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 25-12-2020 23:02:59 IST (UTC+05:30)
// Author: kapil_choudhary

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

// graph where each cell is a node uniquely represented by
// (row, col) & vpii stores it's adjacent nodes
vpii g[501][501];

int arr[501][501]; // to store the i/p matrix

// it will store all the special nodes (nodes which are sources [these will 
// be the multiple sources from which Multisource BFS will start] or nodes 
// having max value in the arr[][])
vpii spl; 

int n, m; 

vi dx {-1, -1, -1, 0, 1, 1, 1, 0};
vi dy {-1, 0, 1, 1, 1, 0, -1, -1};

bool is_valid(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

void add_edges() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			// to remove neighbors of previous test case
			g[i][j].clear(); 
		
			for(int d = 0; d < 8; d++) {
				int nx = i + dx[d], ny = j + dy[d];
				if(is_valid(nx, ny)) g[i][j].pb({nx, ny});
			}
		}
	}
}

void multisource_bfs(int &res) {
	// visited matrix
	vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, 0));
	
	// distance matrix to store the shortest distance of every
	// cell from the sources 
	vvi dis(n + 1, vi(m + 1));
	
	queue<pii> q; // queue to store the nodes
	
	// initialisation of BFS 
	for(pii src: spl) {
		// inserting all the sources in the queue (similar to which 
		// we do in normal BFS by inserting a single source) 
		q.push(src);
		dis[src.F][src.S] = 0; // dis of a source from itself = 0;
		vis[src.F][src.S] = 1; // just as we do in normal BFS
	}
	
	while(!q.empty()) {
		pii curr = q.front();
		q.pop();
		
		for(pii x: g[curr.F][curr.S]) {
			if(!vis[x.F][x.S]) {
				vis[x.F][x.S] = 1;
				q.push(x);
				dis[x.F][x.S] = dis[curr.F][curr.S] + 1;
				res = max(res, dis[x.F][x.S]);
			}
		}
	}
}

void solve()
{
  	cin >> n >> m;
  	int mx = INT_MIN;
  	for(int i = 1; i <= n; i++) {
  		for(int j = 1; j <= m; j++) {
  			cin >> arr[i][j];
  			mx = max(mx, arr[i][j]);
  		}
  	}
  	
  	// constructing the graph
  	add_edges();
  	
  	// finding out all the sources
  	spl.clear();
  	for(int i = 1; i <= n; i++) {
  		for(int j = 1; j <= m; j++) {
  			if(arr[i][j] == mx) spl.pb({i, j});
  		}
  	}
  	
  	int res = 0; // to store the final result
  	// running Multisource BFS 
  	multisource_bfs(res); // pass res by reference
  	
  	cout << res << "\n";  	
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
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}

// Time complexity: O(|V| + |E|)