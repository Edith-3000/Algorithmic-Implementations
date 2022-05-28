/* PROBLEM STATEMENT: Given a (m x n) matrix, with some cells blocked(0 = cell not blocked, 1 = blocked),
                      you have to -
					  1. Find path from src to dest.
					  2. Count the #paths from src to dest.
					  3. Print all possible paths from src to dest.

					  *NOTE: The rat can only move in forward and downward direction.
*/

#include<bits/stdc++.h>
using namespace std;

bool rat_in_maze(vector<vector<int>> &maze, vector<vector<bool>> &v, int i, int j, int m, int n, int &cnt) {
	// base case(s)
	if(i == (m - 1) && j == (n - 1)) {
		if(maze[i][j] == 1) return false;
		v[i][j] = 1;
		// we've reached the last cell successfull, print the path
		// and increment cnt variable
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cout << v[i][j] << " ";
			}
			
			cout<<"\n";
		}
		
		cnt++;
		cout << "\n";
		return true;
	}
	
	// bounds check(rat must be inside the grid)
	if((i >= m) || (j >= n)) {
		return false;
	}
	
	if(maze[i][j] == 0) {
		return false;
	}
	
	// assuming path exist through current pos(i, j)
	v[i][j] = 1;
	
	bool right_se_path_mila = rat_in_maze(maze, v, i, j + 1, m, n, cnt);
	bool down_se_path_mila = rat_in_maze(maze, v, i + 1, j, m, n, cnt);
	
	// making v[i][j] = 0 in the returning phase(while backtracking)
	// every time so all the path can be found and printed
	v[i][j] = 0;
	
	if(right_se_path_mila || down_se_path_mila) {
		return true;
	}
	
	return false;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter the #rows & #cols in the MAZE: ";
    int m, n; cin >> m >> n;
    cout << m << " " << n << "\n";
    
    cout << "Enter the MAZE, 0 = blocked, 1 = open: " << "\n";
    vector<vector<int>> maze(m, vector<int>(n));
    
    for(int i = 0; i < m; i++) {
    	for(int j = 0; j < n; j++) {
    		cin >> maze[i][j];
    	}
    }
    
    // for counting the total #valid paths
    int cnt = 0;
    
    // for retreving the path
    // v[i][j] = 0 if that cell is not included in the path &
    // it will be 1 if that cell is included in the path
    vector<vector<bool>> v(m, vector<bool>(n, 0));
    
    cout << "==========================================" << "\n";
    
    bool res = rat_in_maze(maze, v, 0, 0, m, n, cnt);
    if(res == false) {
    	cout << "Path doesn't exist";
    }
	
	cout << "Total #valid paths: " << cnt;
	
    return 0;
}

// Time Complexity: O(2^(n^2)), as the recursion can run upperbound 2^(n^2) times.
// Space Complexity: O(n^2), as o/p matrix is required so an extra space of size n*n is needed.
// https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

/*

Sample i/p:

4 4
1 0 0 0
1 1 0 1
1 1 0 0
1 1 1 1

Sample o/p:

Enter the #rows & #cols in the MAZE: 4 4
Enter the MAZE, 0 = blocked, 1 = open: 
==========================================
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 1 

1 0 0 0 
1 0 0 0 
1 1 0 0 
0 1 1 1 

1 0 0 0 
1 0 0 0 
1 0 0 0 
1 1 1 1 

Total #valid paths: 3

*/