// Given a (n x n) sudoku, where n is a perfect square, writer a possible solution to the sudoku.
// Very much similar to "N-Queens Problem.cpp"

#include<bits/stdc++.h>
using namespace std;

bool is_valid(int i, int j, vector<vector<int>> &board, int n, int num)
{
	for(int x = 0; x < n; x++){
		if(board[x][j] == num || board[i][x] == num){
			return false;
		}
	}
	
	int sub_size = sqrt(n);
	int sx = (i/sub_size) * sub_size;
	int sy = (j/sub_size) * sub_size;
	
	for(int k = sx; k < (sx + sub_size); k++){
		for(int l = sy; l < (sy + sub_size); l++){
			if(board[k][l] == num){
				return false;
			}
		}
	}
	
	return true;
}

bool sudoku_solver(int i, int j, vector<vector<int>> &board, int n)
{
	// base cases
	if(i == n){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<board[i][j]<<" ";
			}
			
			cout<<"\n";
		}
		
		return false;
	}
	
	// go to the next row
	if(j == n){
		return sudoku_solver(i+1, 0, board, n);
	}
	
	// check for the next cell
	if(board[i][j] != 0){
		return sudoku_solver(i, j+1, board, n);
	}
	
	for(int num = 1; num <= n; num++)
	{
		if(is_valid(i, j, board, n, num)){
			board[i][j] = num;
			bool next_cell_mein_sahi_num_rakh_paye = sudoku_solver(i, j+1, board, n);
			
			if(next_cell_mein_sahi_num_rakh_paye == true){
				return true;
			}
			
			// rolling back the incorrect decision
			else board[i][j] = 0; 
		}
	}
	
	// case in which we are not able to place any num from 1 to 9 at pos(i, j)
	return false;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout<<"Enter the size of Sudoku board(must be a perfect square): ";
    int n; cin >> n;
    cout<<n<<"\n";
    
    vector<vector<int>> board(n, vector<int>(n));
    cout<<"Enter the sudoku(blanks cell to be represented by 0) ---> \n";
    
    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		cin>>board[i][j];
    	}
    }
	
	cout<<"\n";
	sudoku_solver(0, 0, board, n);

    return 0;
}

// Time complexity: O(n^(n*n)).
// Reference: https://www.geeksforgeeks.org/sudoku-backtracking-7/ 

/*Sample i/p:

9
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

Sample o/p:

Enter the size of Sudoku board(must be a perfect square): 9
Enter the sudoku(blanks cell to be represented by 0) ---> 

5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 

*/