/* PROBLEM STATEMENT: Given a set of cities and distance between every pair of cities, the problem is to find 
                      the shortest possible route that visits every city exactly once and returns to the 
                      starting point.
*/

// Reference: https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/#:~:text=Travelling%20Salesman%20Problem%20(TSP)%3A,between%20Hamiltonian%20Cycle%20and%20TSP.

// The problem is a famous NP hard problem. There is no polynomial time know solution for this problem.

// NOTE: The path obtained after running TSP algorithm is a HAMILTONIAN CYCLE (but the unique featue of that path
//       is that it is the minimum weight hamiltonian cycle of the graph).

// As in the question it says that every pair of city is connected, therefore the graph is complete.
// Graph is represented using Adjacency Matrix

/***************************************************************************************************************/

// USING RECURSION

#include<bits/stdc++.h>
using namespace std;

int tsp(int mask, int pos, int start, int all_visited, vector<vector<int>> &g)
{
	// base condition(s)
	if(mask == all_visited){
		return g[pos][start];
	}
	
	// to store the final result
	int res = INT_MAX;
	
	for(int city=0; city<g.size(); city++)
	{
		// check if the city has not been visited in the path
		if((mask & (1 << city)) == 0){
			int temp = g[pos][city] + tsp(mask | (1 << city), city, start, all_visited, g);
			
			// update the final result
			res = min(res, temp);
		}
	}
	
	// return the final result
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout<<"Enter the number of cities: ";
    int n; cin>>n;
    cout<<n<<"\n";
    
    cout<<"Enter the number of input edges: ";
    int e; cin>>e;
    cout<<e<<"\n";
    
    vector<vector<int>> g(n, vector<int>(n, 0));
    
    while(e--)
    {
    	int u, v, wt;
    	cin >> u >> v >> wt;
    	
    	g[u][v] = wt;
    	g[v][u] = wt;
    }
    
    cout<<"Enter the start city: ";
    int start; cin>>start;
    cout<<start<<"\n";
    
    // to check in the base condition of recursion
    // if all the cities have been visited
    int all_visited = (1 << n) - 1;
    
    cout<<"The TSP cost(i.e. cost of min. wt. Hamiltonian cycle) = "<<tsp(1 << start, start, start, all_visited, g);

    return 0;
}

// Time complexity: O((n-1)!) ≡ O(n!)

/*

Sample i/p:

4
6
0 1 20
0 2 42
0 3 25
1 2 30
1 3 34
2 3 10
0

Sample o/p:

Enter the number of cities: 4
Enter the number of input edges: 6
Enter the start city: 0
The TSP weight(i.e. wt of min. wt. Hamiltonian cycle) = 85

*/

/***************************************************************************************************************/

// USING MEMOISATION (TOP DOWN DP APPROACH)

#include<bits/stdc++.h>
using namespace std;

int tsp(int mask, int pos, int start, int all_visited, vector<vector<int>> &g, vector<vector<int>> &dp)
{
	// base condition(s)
	if(mask == all_visited){
		return g[pos][start];
	}
	
	// check if already calculated or not
	if(dp[mask][pos] != -1){
		return dp[mask][pos];
	}

	// to store the final result
	int res = INT_MAX;
	
	for(int city=0; city<g.size(); city++)
	{
		// check if the city has not been visited in the path
		if((mask & (1 << city)) == 0){
			int temp = g[pos][city] + tsp(mask | (1 << city), city, start, all_visited, g, dp);
			
			// update the final result
			res = min(res, temp);
		}
	}
	
	// store the final result before returning it
	// so that subproblems are not calculated repeatedly
	return dp[mask][pos] = res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout<<"Enter the number of cities: ";
    int n; cin>>n;
    cout<<n<<"\n";
    
    cout<<"Enter the number of input edges: ";
    int e; cin>>e;
    cout<<e<<"\n";
    
    vector<vector<int>> g(n, vector<int>(n, 0));
    
    while(e--)
    {
    	int u, v, wt;
    	cin >> u >> v >> wt;
    	
    	g[u][v] = wt;
    	g[v][u] = wt;
    }
    
    cout<<"Enter the start city: ";
    int start; cin>>start;
    cout<<start<<"\n";
    
    // to check in the base condition of recursion
    // if all the cities have been visited
    int all_visited = (1 << n) - 1;
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    cout<<"The TSP cost(i.e. cost of min. wt. Hamiltonian cycle) = "<<tsp(1 << start, start, start, all_visited, g, dp);
	
  /*cout<<"\n";
	for(auto v: dp){
		for(auto x: v) cout<<x<<" ";
		cout<<"\n";
	}
    return 0;*/
}

// Time complexity: O(2ⁿ x n x n)

/*

Sample i/p:

4
6
0 1 20
0 2 42
0 3 25
1 2 30
1 3 34
2 3 10
0

Sample o/p:

Enter the number of cities: 4
Enter the number of input edges: 6
Enter the start city: 0
The TSP weight(i.e. wt of min. wt. Hamiltonian cycle) = 85

*/