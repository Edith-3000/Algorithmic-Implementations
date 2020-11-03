/* # Flood Fill Algorithm is a simple variant of BFS or DFS that can be used to label(colour) the various 
     connected components present in a graph.
   # It is generally performed on implicit graphs(2D matrices).
   # Starting from a particular cell we call DFS on the neighbouring cells to colour them.
     Neighbours can be '4' (up, down, left, right) or '8' if include diagonals also.
*/

#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<char>> &v, int row, int col)
{
	for(int i=0; i<row; i++){
    	for(int j=0; j<col; j++){
    		cout<<v[i][j];
    	}
    	
    	cout<<"\n";
    }
}

// North, East, South, West of the current cell
vector<int> dx{-1, 0, 1, 0};
vector<int> dy{0, 1, 0, -1};

void floodFill(vector<vector<char>> &v, int i, int j, char c, char r, int row, int col)
{
	// base condition - matrix bounds
	if(i<0 || i>=row || j<0 || j>=col) return;
		
	// figure boundary condition
	if(v[i][j]!=c) return;
	
	// replacing the current cell 
	v[i][j]=r;
	for(int k=0; k<4; k++)
	{
		// apply floodFill on the neighbouring cells recursively
		floodFill(v, i+dx[k], j+dy[k], c, r, row, col);
	}
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	// #rows & #columns in the input matrix
    int row, col; cin>>row>>col;
    vector<vector<char>> v(row, vector<char>(col));
    for(int i=0; i<row; i++){
    	for(int j=0; j<col; j++){
    		cin>>v[i][j];
    	}
    }
    
    // co-ordinates from where to initiate the algo
    int x, y;  cin>>x>>y; 
    // character which is to be replace by some other character
    char curr, replacement; cin>>curr>>replacement;
    
    // no need of traversal if curr==replacement
    if(curr!=replacement)
        floodFill(v, x, y, curr, replacement, row, col);
    
    print(v, row, col);

    return 0;
}

/*Sample I/P:
  
15 30
..............................
...............#####..........
...............#...#..........
.......#########...#######....
......###......######....###..
.....##....................##.
....##......................##
.....##....................##.
......##..................##..
.......##................##...
........##..............##....
.........###...........###....
...........####......####.....
.............##########.......
.........A..P..P..L..E........
8 20
. K

SAMPLE O/P:
..............................
...............#####..........
...............#...#..........
.......#########...#######....
......###KKKKKK######KKKK###..
.....##KKKKKKKKKKKKKKKKKKKK##.
....##KKKKKKKKKKKKKKKKKKKKKK##
.....##KKKKKKKKKKKKKKKKKKKK##.
......##KKKKKKKKKKKKKKKKKK##..
.......##KKKKKKKKKKKKKKKK##...
........##KKKKKKKKKKKKKK##....
.........###KKKKKKKKKKK###....
...........####KKKKKK####.....
.............##########.......
.........A..P..P..L..E........

*/

// FOR IMPLEMENTATION USING "BFS" REFER: https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/