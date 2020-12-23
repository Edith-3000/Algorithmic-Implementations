// Please refer: https://cp-algorithms.com/graph/edmonds_karp.html#:~:text=Flow%20network,-First%20let's%20define&
//               text=A%20network%20is%20a%20directed,source%20and%20one%20as%20sink.

/* Algorithm --->
   Step 1. Initialize the residual capacity matrix by assuming flow of each edge as 0 initially for every valid 
           edge pair (i, j) & for all other pair fill it with 0. Also initialize max_flow = 0.
   Step 2. Keep finding the augmenting path and increment max_flow accordingly.
           Stop if no augmenting path left.
*/

// Special Note: in the below algorithm 'g' is the adjacency list of the undirected graph, since we have also 
//               to use the reversed of directed edges of the original directed graph when we are looking for 
//               augmenting paths.

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

vvi g; // to store the directed graph
vvi res_cap; // to store the residual capacities of all edges
vi par; // parent array to store parent of each vertex
int n, m; // n = #vertices, m = #edges

int bfs(int s, int t) {
	// assigning parent of each vertex as -1
	fill(par.begin(), par.end(), -1);
	// assigning parent of source(s) as -2
	par[s] = -2;
	
	// queue to store the vertex & min flow discovered so far in the 
	// augmenting path
	queue<pii> q; 
	q.push({s, INF});
	
	while(!q.empty()) {
		int curr = q.front().F;
		int flow = q.front().S;
		q.pop();
		
		for(auto next: g[curr]) {
			if(par[next] == -1 && res_cap[curr][next] > 0) {
				par[next] = curr;
				int new_flow = min(flow, res_cap[curr][next]);
				if(next == t) return new_flow;
				q.push({next, new_flow});
			}
		}
	}
	
	// if no augmenting path found return flow as 0 to stop loop
	return 0;
}

int edmonds_karp_algo(int s, int t) {
	par.resize(n);
	
	int flow = 0; // to store the final result (maximum flow possible)
	int new_flow; // to store the intermediate flows of augmenting paths
	
	while(new_flow = bfs(s, t)) {
		flow += new_flow; // increment the result
		
		// update the residual capacity matrix
		int curr = t;
		while(curr != s) {
			int prev = par[curr]; // previous is parent of current vertex
			res_cap[prev][curr] -= new_flow;
			res_cap[curr][prev] += new_flow;
			curr = prev;
		}
	}
	
	return flow;
}

void solve()
{
  	cin >> n >> m;
  	g.resize(n);
  	res_cap.resize(n);
  	for(int i = 0; i < n; i++) res_cap[i].resize(n);
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < n; j++) {
  			res_cap[i][j] = 0;
  		}
  	}
  	
  	// vertices are 0-based
  	for(int i = 0; i < m; i++) {
  		int u, v, capacity;
  		cin >> u >> v >> capacity;
  		g[u].pb(v);
  		g[v].pb(u);
  		res_cap[u][v] = capacity;
  	}
  	
  	int s, t; // s = source vertex & t = sink vertex in the network
  	cin >> s >> t;
  	cout << "Max flow possible in the network = " << edmonds_karp_algo(s, t) << "\n";
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

6 9
0 1 7
0 4 4
1 2 5
1 3 3
2 5 8
3 2 3
3 5 5
4 3 2
4 1 3
0 5

Sample o/p ---->

Max flow possible in the network = 10

*/