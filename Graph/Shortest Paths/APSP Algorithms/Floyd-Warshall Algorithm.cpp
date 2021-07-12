/* # Reference: https://brilliant.org/wiki/bellman-ford-algorithm/
			    https://cp-algorithms.com/graph/bellman_ford.html
			    https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html

   # This algorithm is DP based as it breaks the problem down into smaller subproblems, then combines the 
     answers to those subproblems to solve the big, initial problem.
   
   # The idea is this: either the quickest path from A to C is the quickest path found so far from A to C, or 
     it's the quickest path from A to B plus the quickest path from B to C.

   # Takes O(|V|^3) time.

   # All pairs shortest path algorithm.
   # Works with -ve edges as well.

   # Can detect -ve weight cycle, with one extra step in the main algorithm.
     * The graph has a negative cycle if at the end of the algorithm, the 
       distance from a vertex v to itself is -ve.

   # Works for weighted DG and UG.

   # As we need to find the shortest path from each node to all other nodes, it is better to represent the graph
     using adjacency matrix.
*/

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
  // data member
  int n;
  vector<vector<T>> mp;
  
  public:
  
    // constructor
    Graph(int n){
    	this->n = n;
    	mp.resize(n, vector<T>(n, 0));
    }
  
    // memebr functions
    void addEdge(T u, T v, int wt, bool isBidir)
    {
      mp[u][v] = wt;
      if(isBidir) mp[v][u] = wt;
    }
    
    void init()
    {
    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			if((i != j) && (mp[i][j] == 0)){
    				mp[i][j] = INT_MAX;
    			}
    		}
    	}
    }
    
    void printGraph()
    {
    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			cout<<mp[i][j]<<" ";
    		}
    		
    		cout<<"\n";
    	}
    }
    
    void floyd_warshall()
    {      
      // parent[key] stores the immediate parent of key
      // in the shortest path from src to key
      unordered_map<T, T> par;
      
      // initialising the parent of all nodes 
      for(int i=0; i<n; i++){
          par[i] = i;
      }
            
      for(int k=0; k<n; k++){
          for(int i=0; i<n; i++){
              for(int j=0; j<n; j++){
                  if(mp[i][k] < INT_MAX && mp[k][j] < INT_MAX){
                      mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
                  }
              }
          }
      }
      
      // to check if there is -ve weight cycle in the graph
      bool flag = false;
      set<pair<T, T>> noShortest;
      
      for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
              for(int t=0; t<n; t++){
                  if(mp[i][t] < INT_MAX && mp[t][j] < INT_MAX && mp[t][t] < 0){
                      flag = true;
                      if(i != j) noShortest.insert({i, j});
                      mp[i][j] = INT_MIN;
                  }
              }
          }
      }
      
      if(flag){
          cout<<"Negative weight cycle exist in the input graph"<<"\n";
          cout<<"Vertex pair b/w which there exist no shortest path are (due to presence of -ve wt cycle b/w them) --->"<<"\n";
          
          for(auto p: noShortest){
              cout<<p.first<<" and "<<p.second<<"\n";
          }
          
          // exit_success
          exit(0);	
      }
      
      // print length of shortest distances of all nodes from src
      for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
              cout<<mp[i][j]<<" ";
          }
          
          cout<<"\n";
      }
   }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout<<"Enter the number of VERTICES in the graph: ";
    int n; cin>>n; cout<<n<<"\n";
    
    cout<<"Enter the number of EDGES in the graph: ";
    int e; cin>>e; cout<<e<<"\n";
    
    Graph<int> g(n);
    for(int i=0; i<e; i++)
    {
      int u, v, wt; 
      cin >> u >> v >> wt;
      g.addEdge(u, v, wt, false);
    }
    
    g.init();
    
    g.printGraph(); 
    cout<<"\n";
    g.floyd_warshall();
    
    return 0;
}

/*

Sample i/p 1:

4
5
0 2 -2
1 0 4
1 2 3
2 3 2
3 1 -1

Sample o/p 1:

Enter the number of VERTICES in the graph: 4
Enter the number of EDGES in the graph: 5
0 2147483647 -2 2147483647 
4 0 3 2147483647 
2147483647 2147483647 0 2 
2147483647 -1 2147483647 0 

0 -1 -2 0 
4 0 2 4 
5 1 0 2 
3 -1 1 0 

-----------------------------------------------------------------------------------------------------------

Sample i/p 2:

6 6
0 5 3
0 1 1
1 2 2
2 3 1
3 1 -4
3 4 5

Smaple o/p 2:

Enter the number of VERTICES in the graph: 6
Enter the number of EDGES in the graph: 6
0 1 2147483647 2147483647 2147483647 3 
2147483647 0 2 2147483647 2147483647 2147483647 
2147483647 2147483647 0 1 2147483647 2147483647 
2147483647 -4 2147483647 0 5 2147483647 
2147483647 2147483647 2147483647 2147483647 0 2147483647 
2147483647 2147483647 2147483647 2147483647 2147483647 0 

Negative weight cycle exist in the input graph
Vertex pair b/w which there exist no shortest path are (due to presence of -ve wt cycle b/w them) --->
0 and 1
0 and 2
0 and 3
0 and 4
1 and 2
1 and 3
1 and 4
2 and 1
2 and 3
2 and 4
3 and 1
3 and 2
3 and 4
0 -2147483648 -2147483648 -2147483648 -2147483648 3 
2147483647 -2147483648 -2147483648 -2147483648 -2147483648 2147483647 
2147483647 -2147483648 -2147483648 -2147483648 -2147483648 2147483647 
2147483647 -2147483648 -2147483648 -2147483648 -2147483648 2147483647 
2147483647 2147483647 2147483647 2147483647 0 2147483647 
2147483647 2147483647 2147483647 2147483647 2147483647 0 

*/