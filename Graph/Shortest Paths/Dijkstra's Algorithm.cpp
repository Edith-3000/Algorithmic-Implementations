/* # Reference: https://cp-algorithms.com/graph/dijkstra.html
   				https://brilliant.org/wiki/dijkstras-short-path-finder/

   # This algorithm is Greedy based.
   
   # This algorithm is used for finding the shortest path(as well as their costs) from a starting node to all 
     other nodes in a weighted & UD/DG.
   # The edges of the graph can be unidirectional/bidirectional.

   # Dijkstra’s algorithm doesn’t work for graphs with -𝒗𝒆 𝒘𝒆𝒊𝒈𝒉𝒕 𝒄𝒚𝒄𝒍𝒆𝒔, it 𝑴𝑨𝒀 give correct results for a 
     graph with -𝒗𝒆 𝒆𝒅𝒈𝒆𝒔. 
   # For graphs with negative weight edges and cycles, 𝑩𝒆𝒍𝒍𝒎𝒂𝒏–𝑭𝒐𝒓𝒅 𝒂𝒍𝒈𝒐𝒓𝒊𝒕𝒉𝒎 can be used.
     
   # This algorithm basically creates a tree of shortest paths from the starting vertex, the source, to all 
     other points in the graph.
*/

// Below is implementation of the algorithm using Adjacency List representation of graph.
// The implementation is Templated.

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
	// data member
	unordered_map<T, list<pair<T, int>>> mp;
	
	public:
		// memebr functions
		void addEdge(T u, T v, int wt, bool isBidir)
		{
			mp[u].push_back({v, wt});
			if(isBidir) mp[v].push_back({u, wt});
		}
		
		void printGraph()
		{
			for(auto p: mp)
			{
				cout<<p.first<<" ---- ";
				for(auto nbr: p.second){
					cout<<"("<<nbr.first<<", "<<nbr.second<<") ";
				}
				
				cout<<"\n";
			}
		}
		
		void dijkstraSSSP(T src)
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
				par[p.first] = p.first;
			}
			
			// the minimum distance of sc from itself = 0
			dist[src] = 0;
			
			// set to repeatedly find out the node having 
			// minimum distance from src
			set<pair<int, T>> s;

			// inserting the src to initialise the process
			s.insert({0, src});
			
			while(!s.empty())
			{
				// extract the node which is currently at 
				// minimum distance from src
				auto p = *(s.begin());

				// marking this node as processed(visited)
				// by removing from the set
				s.erase(s.begin());
				
				int d = p.first;
				T curr = p.second;
				
				// iterate over the neighbours of the extracted node
				for(auto nbr: mp[curr])
				{
					// for edge(u, v) if dist[u] + edge_weight(u, v) < dist[v], 
					// then update dist[v] to (dist[u] + edge_weight(u, v))
					if((d + nbr.second) < dist[nbr.first])
					{
						// in std::set updation of a inserted value is not allowed
						// therefore, we've to remove the old pair and insert the new 
						// pair to simulate updation
						auto it = s.find({dist[nbr.first], nbr.first});
						if(it != s.end()){
							s.erase(it);
						}
						
						// insert new pair(updated)
						s.insert({d + nbr.second, nbr.first});

						// update the distance of nbr from src
						dist[nbr.first] = (d + nbr.second);
						
						// update the parent of nbr
						par[nbr.first] = curr;
					}
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

  /*Graph<int> g;
    g.addEdge(1, 2, 1, true);
    g.addEdge(1, 3, 4, true);
    g.addEdge(2, 3, 1, true);
    g.addEdge(3, 4, 2, true);
    g.addEdge(1, 4, 7, true);*/

    Graph<string> g;
    g.addEdge("Amritsar", "Delhi", 1, true);
    g.addEdge("Amritsar", "Jaipur", 4, true);
    g.addEdge("Jaipur", "Delhi", 2, true);
    g.addEdge("Jaipur", "Mumbai", 8, true);
    g.addEdge("Bhopal", "Agra", 2, true);
    g.addEdge("Mumbai", "Bhopal", 3, true);
    g.addEdge("Agra", "Delhi", 1, true);
    
    g.printGraph(); 
    cout<<"\n";
    //g.dijkstraSSSP(3);
    g.dijkstraSSSP("Delhi");
    
    return 0;
}

/*Sample o/p:

Agra ---- (Bhopal, 2) (Delhi, 1) 
Delhi ---- (Amritsar, 1) (Jaipur, 2) (Agra, 1) 
Amritsar ---- (Delhi, 1) (Jaipur, 4) 
Jaipur ---- (Amritsar, 4) (Delhi, 2) (Mumbai, 8) 
Bhopal ---- (Agra, 2) (Mumbai, 3) 
Mumbai ---- (Jaipur, 8) (Bhopal, 3) 

Shortest distance of Mumbai from Delhi = 6
Shortest distance of Delhi from Delhi = 0
Shortest distance of Agra from Delhi = 1
Shortest distance of Amritsar from Delhi = 1
Shortest distance of Jaipur from Delhi = 2
Shortest distance of Bhopal from Delhi = 3

Mumbai <-- Bhopal <-- Agra <-- Delhi
Delhi
Agra <-- Delhi
Amritsar <-- Delhi
Jaipur <-- Delhi
Bhopal <-- Agra <-- Delhi

*/

// For Time complexity of Dijkstra's Algorithm implemented using std::priority_queue, visit: --->
// https://cs.stackexchange.com/questions/104566/dijkstra-complexity-analysis-using-adjacency-list-and-priority-queue#:~:text=1%20Answer&text=Dijkstra's%20algorithm%20visits%20every%20node,in%20O(logV).

/**********************************************************************************************************************************************************************************************************/

// NOTE: A similar approach of implementing Dijkstra's by making use of an extra visited array so that
//       the same vertex is not visited again and again, can be seen here ===>
// Problem: https://www.interviewbit.com/problems/useful-extra-edges/
// Sol: https://pastebin.ubuntu.com/p/2kn4dQWVh9/