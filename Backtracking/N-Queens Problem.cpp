/* PROBLEM STATEMENT: Given a chessboard of size n x n, determine how many ways n queens can be placed on 
                      this board so that no two queens attack each other.
                      The chess queens(wazeer) can attack in any direction as horizontal, vertical and 
                      diagonal way.
                      A matrix must be used to display the positions of N Queens, where no queens can 
                      attack other queens (use 'Q' for queen and '.' for empty position).
*/

/******************************************************************************************************/

// METHOD - 1

#include<bits/stdc++.h>
using namespace std;

// in this function no need to check below the current row as 
// we are filling the rows from top to bottom
bool is_valid(int i, int j, int n, vector<vector<int>> &board) {
	// check for all the cells vertically above the ith row
	for(int row = 0; row < i; row++){
		if(board[row][j] == 1){
			return false;
		}
	}
	
	// check for all the left diagonal positions
	int x = i - 1, y = j - 1;
	while(x >= 0 && y >=0) {
		if(board[x][y] == 1){
			return false;
		}
		
		x--;
		y--;
	}
	
	// check for all the right diagonal positions
	x = i - 1, y = j + 1;
	while(x >= 0 && y < n) {
		if(board[x][y] == 1){
			return false;
		}
		
		x--;
		y++;
	}
	
	// if safe position return true
	return true;
}

bool n_queen(int i, int n, vector<vector<int>> &board) {
	// base case
	// it signifies that we've successfully reached the last row and
	// placed a queen in all rows from (0...n-1) (i.e. reaches the complete 
	// depth of recursion) just print this valid configuration
	if(i == n) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(board[i][j] == 1) cout << 'Q' <<" ";
				else cout << '_' <<" ";
			}
			
			cout << "\n";
		}
		
		cout << "\n";
		
		// false is returned so that recursion continues to search
		// for another valid configuration till exhaustion
		return false;
	}
	
	// try to place the queen in the current row 'i' at any suitable
	// column and call on the remaining part which will be automatically
	// handled by recursion
	for(int j = 0; j < n; j++) {
		// chech is it safe to place the queen at position (i, j)
		if(is_valid(i, j, n, board)) {
			// if position (i, j) is safe place the queen at this position
			board[i][j] = 1;
			
			// try to place another queen in the next row
			bool next_row_mein_queen_rakh_paye = n_queen(i+1, n, board);
			
			if(next_row_mein_queen_rakh_paye == true){
				return true;
			}
			
			// rolling back the incorrect decision
			else board[i][j] = 0;
		}
	}
	
	// case in which we are not able to place a queen in the current row 'i'
	return false;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout<<"Enter the chessboard size: ";
    int n; cin >> n;
    cout << n<< "\n\n";
    
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    // we'll place queens row-wise (1 queen in a row)
    // start by trying to place a queen in 0th row at suitable colm index
    n_queen(0, n, board);
    
    return 0;
}

// Time Complexity: Exponential, for details ===>
// Refer: https://medium.com/@jmohon1986/timeout-the-story-of-n-queens-time-complexity-c80636d92f8b#:~:text=The%20worst%20case%20%E2%80%9Cbrute,N%20times%2C%20for%20N%20queens.&text=However%2C%20if%20it%20is%20found,and%20try%20another%20safe%20position.
// In the description of the video: https://www.youtube.com/watch?v=wGbuCyNpxIg

/* Optimizations: The exponential time complexity of above backtracking algorithm can be improved by using 
   Branch and Bound. 
   In backtracking solution we backtrack when we hit a dead end but in branch and bound, after building a 
   partial solution, we figure out that there is no point going any deeper as we are going to hit a dead end.  
*/

/*

Sample i/p:

4

Sample o/p:

Enter the chessboard size: 4

_ Q _ _ 
_ _ _ Q 
Q _ _ _ 
_ _ Q _ 

_ _ Q _ 
Q _ _ _ 
_ _ _ Q 
_ Q _ _ 

*/

/****************************************************************************************************/

// METHOD - 2 
// In this method there is just slight optimization of the is_valid() fn. (which runs in O(n) time).
// Here in this algorithm that work is being done in O(1) time.
// Ref to this optimization: see @27:35 in the link below ===>
// https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0rQ6cnlaHRMuOp4H_D-7hwP&index=9

// Similar kind of optimization can also be done as given in GfG article
// https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/

#include<bits/stdc++.h>
using namespace std;

bool n_queen(int i, int n, vector<vector<int>> &board, vector<int> &up_col, vector<int> &left_diag, vector<int> &right_diag) {
	// base case
	// it signifies that we've successfully reached the last row and
	// placed a queen in all rows from (0...n-1) (i.e. reaches the complete 
	// depth of recursion) just print this valid configuration
	if(i == n) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(board[i][j] == 1) cout << 'Q' <<" ";
				else cout << '_' <<" ";
			}
			
			cout << "\n";
		}
		
		cout << "\n";
		
		// false is returned so that recursion continues to search
		// for another valid configuration till exhaustion
		return false;
	}
	
	// try to place the queen in the current row 'i' at any suitable
	// column and call on the remaining part which will be automatically
	// handled by recursion
	for(int j = 0; j < n; j++) {
		// chech is it safe to place the queen at position (i, j)
		if(up_col[j] == 0 and left_diag[n-1 + i-j] == 0 and right_diag[i+j] == 0) {
			// if position (i, j) is safe place the queen at this position
			board[i][j] = 1;
			up_col[j] = 1; 
			left_diag[n-1 + i-j] = 1;
			right_diag[i+j] = 1;
			
			// try to place another queen in the next row
			bool next_row_mein_queen_rakh_paye = n_queen(i+1, n, board, up_col, left_diag, right_diag);
			
			if(next_row_mein_queen_rakh_paye == true){
				return true;
			}
			
			// rolling back the incorrect decision
			else {
				board[i][j] = 0;
				up_col[j] = 0; 
				left_diag[n-1 + i-j] = 0;
				right_diag[i+j] = 0;
			}
		}
	}
	
	// case in which we are not able to place a queen in the current row 'i'
	return false;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout<<"Enter the chessboard size: ";
    int n; cin >> n;
    cout << n<< "\n\n";
    
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    // these vectors will check in constant time that whether it is possible
    // to place a queen at index (i, j)
    vector<int> up_col(n, 0);
    vector<int> left_diag(2 * n - 1, 0);
    vector<int> right_diag(2 * n - 1, 0);
    
    // we'll place queens row-wise (1 queen in a row)
    // start by trying to place a queen in 0th row at suitable colm index
    n_queen(0, n, board, up_col, left_diag, right_diag);
    
    return 0;
}