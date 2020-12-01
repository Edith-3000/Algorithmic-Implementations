/*
   # Like Kruskal’s algorithm, Prim’s algorithm is also a Greedy algorithm.
   # Prim's algorithm is very similar to Kruskal's: whereas Kruskal's "grows" a forest of trees, Prim's algorithm 
     grows a single tree until it becomes the minimum spanning tree. 
   # Both algorithms use the greedy approach - they add the cheapest edge that will not cause a cycle. 
     But rather than choosing the cheapest edge that will connect any pair of trees together, Prim's algorithm 
     only adds edges that join nodes to the existing tree. (In this respect, Prim's algorithm is very similar to 
     Dijkstra's algorithm for finding shortest paths.)
     * Reference: [Given at the last].

   # Few terms which will be used in the algorithm ---->
     * V = set of all the vertices of the graph.
     * MST Set = set of all the vertices which have been included in the MST so far.
	 * Active Edge = An edge between a vertex in MST Set and V.
	 * MST Edge = An edge which have been included in the MST so far.

   # Algorithm ---->
     1. Remove all loops and Parallel Edges.
        (In case of parallel edges, keep the one which has the least cost associated and remove all others.)
     2. Choose any vertex as the starting vertex and include it in MST Set and exclude it from V set.
     3. Out of all the active edges choose the one with minimum weight and add it to result.
        * Include the other vertex (say 'Y') of this active edge in MST Set & exclude it from V set.
        * Add edges starting from 'Y' in the Active Edge list.
        * NOTE: No need to consider the edge between 'Y' and previously visited vertex. 
     4. Repeat step 3 until MST Set doesn't contain all the vertices or V set is empty.
*/

// Problem: Minimum Spanning Tree
// Contest: SPOJ - Partial
// URL: https://www.spoj.com/problems/MST/
// Memory Limit: 1536 MB
// Time Limit: 2000 ms
// Parsed on: 30-11-2020 23:27:24 IST (UTC+05:30)
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

const int mod = 1e9+7;

// using adjacency list representation of graph
class Graph{
	ll n;
	vpll *list;
	
	public:
		Graph(ll n){
			this->n = n;
			list = new vpll[n];
		}
		
		void addEdge(ll x, ll y, ll w){
			list[x].pb({y, w});
			list[y].pb({x, w});
		}
		
		ll prim_algo(){
			// minHeap to repeatedly find out the active edge with
			// minimum weight  
			priority_queue<pll, vpll, greater<pll>> q;
			q.push({0, 0}); // {weight, vertex}
			
			// visited array to keep track of all the vertices
			// which have been included in the MST Set so far
			vector<bool> visited(n, false);
			ll res = 0;
			
			while(!q.empty()){
				// extract the edge with minimum weight among
				// all the active edges
				pll pair = q.top();
				q.pop();
				
				ll wt = pair.F;
				ll to = pair.S;
				
				if(visited[to]){
					// discard this edge
					continue;
				}
				
				res += wt;
				visited[to] = true;
				
				for(auto x: list[to]){
					if(visited[x.F] == 0){
						q.push({x.S, x.F});
					}
				}
			}
			
			return res;
		}
};

void solve()
{
  	ll n, m; cin >> n >> m;
  	Graph g(n);
  	for(ll i = 1; i <= m; i++){
  		ll x, y, w; cin >> x >> y >> w;
  		// -1 is done bcoz the DSU data structure 
  		// is formed on 0-based indexing
  		g.addEdge(x - 1, y - 1, w);
  	}
  	
  	cout << g.prim_algo();
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

// Time Complexity: O(|E| x log|E|) which in turn = O(|E| x log|E|), same as Kruskal's algorithm.
// However, Prim's algorithm can be improved using Fibonacci Heaps to O(|E| + log|V|).
// Reference: https://www.cs.auckland.ac.nz/software/AlgAnim/prim.html#:~:text=The%20time%20complexity%20is%20O,O(E%20%2B%20logV).