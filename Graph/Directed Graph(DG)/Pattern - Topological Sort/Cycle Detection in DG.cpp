#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> mp;
int n;

bool cycleHelper(int src, vector<bool> &visited, vector<bool> &stack)
{
	//marking a node visited as soon as it is pushed in 
    //internal call stack
	visited[src]=true;

	// the src now becomes a part of the current path
	stack[src]=true;

	// go to all the unvisited nodes of the current src
    // node, but one by one

    // now there can be 2 cases -
    // 1. either the neighbour of the src vertex is not visited
	//    yet, in such a case recursively visit the neighbours and
	//    check for cycle or
	// 2. the neighbour is visited and is also a part of the current path,
	//    then the graph contains cycle
	for(auto x: mp[src])
	{
		// case 1
		if(!visited[x])
		{
			bool cycleFound=cycleHelper(x, visited, stack);
			if(cycleFound) return true;
		}

		// case 2
		else if(stack[x]) return true;
	}

	// removing the current vertex i.e. src from the current path
	// when recursion moves in backward direction
	stack[src]=false;

	// if the above 2 cases fails then no cycle present
	return false;
}


bool containsCycle()
{
	vector<bool> visited(n, false);
	vector<bool> stack(n, false);
	
	bool res=false;
	
	for(auto p: mp)
	{
		if(!visited[p.first]){
			bool temp=cycleHelper(p.first, visited, stack);
			res=res||temp;
		}
	}
	
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	
	// n are the #vertices from 0 to n-1
	// e are the #edges
    cin>>n;
    int e; cin>>e;
    
    for(int i=0; i<e; i++)
    {
    	int x, y; cin>>x>>y;
    	mp[x].push_back(y);
    }
    
    cout<<(containsCycle() ? "Graph contains cycle" : "Graph does't contains cycle");

    return 0;
}