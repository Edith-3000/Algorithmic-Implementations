/*
   # Kruskal's algorithm to find the minimum cost spanning tree uses the greedy approach. 
   # This algorithm treats the graph as a forest and every node it has as an individual tree
     (i.e. n connected components initially). 
   # A tree connects to another only and only if, it has the least cost among all available options and does 
     not violate MST properties.

   # Algorithm ---->
     1. Remove all loops and Parallel Edges.
        (In case of parallel edges, keep the one which has the least cost associated and remove all others.)
     2. Sort all edges in their increasing order of weight.
     3. Repeatedly add the first (n-1) edges which have the least weightage, iff it does not form a cycle
        i.e. add the least cost edge one by one whose vertices are present in 2 different connected components.
*/

// Problem: Minimum Spanning Tree
// Contest: SPOJ - Partial
// URL: https://www.spoj.com/problems/MST/
// Memory Limit: 1536 MB
// Time Limit: 2000 ms
// Parsed on: 30-11-2020 21:05:56 IST (UTC+05:30)
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int mod = 1e9+7;

// DSU data structure implemented using both
// path compression + union by rank optimisations
class DSU{
  ll *parent, *rank;
  ll n;
  
  public:
    DSU(ll n){
      this->n = n;
      parent = new ll[n];
      rank = new ll[n];
      for(ll i = 0; i < n; i++){
        parent[i] = -1;
        rank[i] = 1;
      }
    }
    
    ll dsu_find(ll i){
      // base case
      if(parent[i] == -1){
        return i;
      }
      
      return parent[i] = dsu_find(parent[i]);
    }
    
    void dsu_union(ll x, ll y){
      ll s1 = dsu_find(x);
      ll s2 = dsu_find(y);
      
      if(s1 == s2) return;
      
      if(rank[s1] < rank[s2]){
        parent[s1] = s2;
        rank[s2] += rank[s1];
      }
      
      else{
        parent[s2] = s1;
        rank[s1] += rank[s2];
      }
    }
};

// using edge list representation of graph as
// sorting of edges is required
class Graph{
  ll n;
  vector<vector<ll>> edgeList;
  
  public:
    Graph(ll n){
      this->n = n; 
    }
    
    void addEdge(ll x, ll y, ll w){
      // w is inserted first so that 
      // sorting is done on the basis of 'w'
      edgeList.pb({w, x, y});
    }
    
    ll kruskal_algo(){
      // initialising DSU data structure
      DSU d(n);
      
      // sorting on thye basis of edge weight
      sort(edgeList.begin(), edgeList.end());
      
      ll res = 0; // to store final result
      
      for(auto edge: edgeList){
        ll s1 = d.dsu_find(edge[1]);
        ll s2 = d.dsu_find(edge[2]);
        
        // include the edge (x, y) in MST if it
        // does not form a cycle(i.e. include in
        // MST if 'x' & 'y' elong to different sets)
        if(s1 != s2){
          res += edge[0];
          d.dsu_union(edge[1], edge[2]);
        }
      }
      
      return res; // final result (min weight)
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
    
    cout << g.kruskal_algo();
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

// Time Complexity: O(|E| x log|V|)
// Refer: https://stackoverflow.com/questions/20432801/time-complexity-of-the-kruskal-algorithm