/* # For a vertex to be an articulation point the following condition must hold(valid for all the vertices 
     excluding the root of the DFS Tree formed by DFS traversal of the graph):
     low[child] >= entry[parent]

     • The root of the DFS is articulation point if it has >= 2 children in the DFS Tree representation
       (not in the graph itself).

   # For an edge to be a bridge the following condition must hold(valid for all the vertices including
     the root of the DFS Tree formed by DFS traversal of the graph):
     low[child] > entry[parent]

   # Here low[i] is the lowest time of vertex i(already discussed in "Introduction.txt")
*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> mp;
int n; // the #vertices in the UG from 0 to n-1

// to store all articulation points
vector<int> point;
// to store all bridges
vector<pair<int, int>> bridge;

void dfs(int curr, int par, vector<int> &entry, vector<int> &low, int time)
{
	entry[curr]=low[curr]=time++;
	
	// for storing the count of #child of the curr node
	// in the DFS Tree (not in the graph)
	int no_of_child=0;
	
	// now, there are 2 cases 
	// 1. if the child is not visited, then visit it
	//    and ask for the lowest time of that child
	// 2. if the child is visited and != parent of curr,
	//    then backedge is present and therefore cycle is there
	for(auto child: mp[curr])
	{
		// case 1
		if(entry[child]==0)
		{
			dfs(child, curr, entry, low, time);
			// increment the #child of curr
			no_of_child++;
			
			low[curr]=min(low[curr], low[child]);
			
			// condition for curr to be an articulation pt
			if(par!=-1 && low[child]>=entry[curr])
				point.push_back(curr);
			
			// condition for curr ---> child to be a bridge
			if(low[child]>entry[curr])
				bridge.push_back({curr, child});
		}
		
		// case 2
		else if(child != par)
			low[curr]=min(low[curr], entry[child]);
	}
	
	// separate case for the root of the DFS TREE of the graph
	// to be an articulation pt
	if(par==-1 && no_of_child>=2)
	{
		// the parent of the root of DFS tree was passed as 1
		point.push_back(curr);
	}
	
	return;
}

void artpts_and_bridges()
{	
	// to store the entry/discovery time of all vertices
	// while DFS traversal, it will also be used as visited array
	vector<int> entry(n, 0);

	// to store the lowest time of all the vertices
	vector<int> low(n, 0);
	
	// initialising the time as 1
	int time=1;
	
	for(auto p: mp)
	{
		// if not visited yet, call dfs by taking 
		// p.first as the root of the current DFS traversal
		if(entry[p.first]==0)
			dfs(p.first, -1, entry, low, time);
	}
	
	for(auto v: point) cout<<v<<" ";
	cout<<"\n";
	
	for(auto p: bridge) 
		cout<<p.first<<" ---- "<<p.second<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	
	cin>>n;
	int e; cin>>e; // the #edges in the UG
	for(int i=0; i<e; i++)
	{
		int x, y; cin>>x>>y;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}    

    artpts_and_bridges();
	
    return 0;
}

/*Sample i/p: 

14 17
0 2
0 4
0 8
0 5
2 4
4 6
2 6
2 5
2 7
5 1
1 7
1 3
3 9
8 11
11 10
8 10
12 13

Sample o/p

3 1 0 8 
13 ---- 12
3 ---- 9
1 ---- 3
8 ---- 0
*/

// Time Complexity = O(|V| + |E|)