/* # Reference: https://brilliant.org/wiki/bellman-ford-algorithm/
			 https://cp-algorithms.com/graph/bellman_ford.html
   
   # This algorithm is DP based.

   # It is a graph search algorithm that finds the shortest path between a given source vertex and all other
     vertices in the graph. This algorithm can be used on both weighted and unweighted graphs and also on 
     DG & UG.

   # Like Dijkstra's shortest path algorithm, the Bellman-Ford algorithm is also guaranteed to find the 
     shortest path in a graph. 
   # Though it is slower than Dijkstra's algorithm (Time Complexity: O(V x log(E))), Bellman-Ford 
     (Time Complexity: O(V x E) is capable of handling graphs that contain negative edge weights, so it is 
     more versatile. 

   # It is worth noting that if there exists a negative cycle in the graph, then there is no shortest path. 
     As Going around the negative cycle an infinite number of times would continue to decrease the cost of the 
     path (even though the path length is increasing). 
     Because of this, Bellman-Ford can also detect negative cycles which is a useful feature.

   # An UG can be converted in a DG, and so if a UG contains a -ve weight edge, then basically we can say that
     it's a -ve weight cycle and hence no shortest path exists.

   # Simple algorithm ---->
     1. Mark the dist[src] = 0 (from itself) 
        and dist[all other vertices from src] = infinity
     
     2. If we consider the #vertices = n and #edges = m
        then we just have to relax m edges (n-1) times for worst case.
        i.e. for(int i=1; i<n-1; i++){
                 for(int j=1; j<=m; j++){
                     relax the jth edge
                 }
        }

   # Unlike many other graph algorithms, for Bellman-Ford algorithm, it is more convenient to represent the 
     graph using a single list of all edges (instead of n lists of edges - edges from each vertex) i.e. 
     edge list representation.
*/ 

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
  // data member
  vector<pair<T, pair<T, int>>> mp;
  
  public:
    // memebr functions
    void addEdge(T u, T v, int wt, bool isBidir)
    {
      mp.push_back({u, {v, wt}});
      if(isBidir) mp.push_back({v, {u, wt}});
    }
    
    void printGraph()
    {
      for(auto p: mp)
      {
        cout<<p.first<<" ---- "<<"("<<p.second.first<<", "<<p.second.second<<")";   
        cout<<"\n";
      }
    }
    
    void bellman_ford_SSSP(T src)
    {
      // dist[key] stores the minimum distance 
      // of key from given src
      unordered_map<T, int> dist;
      
      // parent[key] stores the immediate parent of key
      // in the shortest path from src to key
      unordered_map<T, T> par;
      

      // initialising the distances of all nodes 
      // from src as infinity
      for(auto p: mp){
        dist[p.first] = INT_MAX;
        dist[p.second.first] = INT_MAX;
        
        par[p.first] = p.first;
        par[p.second.first] = p.second.first;
      }
      
      // the minimum distance of sc from itself = 0
      dist[src] = 0;
      int n = mp.size();
      
      // relax all the edges (n-1) times
      for(int i=1; i<n; i++)
      {
        // iterate through all the edges of the graph 
        for(auto p: mp)
        {
          int u = p.first;
          int v = p.second.first, w = p.second.second;
          
          // to avoid overflow check dist[u] != INT_MAX
          if((dist[u] != INT_MAX) && ((dist[u] + w) < dist[v])){
            dist[v] = (dist[u] + w);
            par[v] = u;
          }
        }
      }
      
      // to check if there is -ve weight cycle in the graph
      // (if after (n-1) iterations any relaxation is performed
      // then -ve weight cycle is present)
      for(auto p: mp)
      {
        int u = p.first;
        int v = p.second.first, w = p.second.second;
          
        if((dist[u] != INT_MAX) && ((dist[u] + w) < dist[v])){
          cout<<"Negative Weight Cycle Present in Input Graph"<<"\n";
          // exit_success
              exit(0); 
        }
      }
      
      // print length of shortest distances of all nodes from src
      for(auto p: dist){
        cout<<"Shortest distance of "<<p.first<<" from "<<src<<" = "<<p.second;
        cout<<"\n"; 
      }
      
      cout<<"\n";
      
      // print shortest path of all nodes from src
      for(auto p: par){
        T node = p.first;
        
        if(node != src)
        {
          cout<<node<<" <-- ";
          while(par[node] != src){
            cout<<par[node]<<" <-- ";
            node=par[node];
            }
        }
        
        cout<<src;
        cout<<"\n";
      }
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout<<"Enter the number of EDGES in the graph: ";
    int n; cin>>n; cout<<n<<"\n";
    
    Graph<int> g;
    for(int i=0; i<n; i++)
    {
      int u, v, wt; 
      cin >> u >> v >> wt;
      g.addEdge(u, v, wt, false);
    }
    
    int src; cin>>src;
    
    g.printGraph(); 
    cout<<"\n";
    g.bellman_ford_SSSP(src);
    
    return 0;
}

/*

Sample i/p:
3
1 2 4
1 3 5
3 2 -7
1

Sample o/p:
Enter the number of edges in the graph: 3
1 ---- (2, 4)
1 ---- (3, 5)
3 ---- (2, -7)

Shortest distance of 3 from 1 = 5
Shortest distance of 1 from 1 = 0
Shortest distance of 2 from 1 = -2

3 <-- 1
1
2 <-- 3 <-- 1

*/

// Time Complexity: O(|V| x |E|)