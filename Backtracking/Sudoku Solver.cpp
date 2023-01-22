// Imp. links: https://leetcode.com/problems/sudoku-solver/
//             https://takeuforward.org/data-structure/sudoku-solver/

/**************************************************************************************************************************************************************/ 

// Given an (n x n) sudoku, where n is a perfect square, writer all possible solutions to the sudoku.
// Very much similar to "N-Queens Problem.cpp"

/**************************************************************************************************************************************************************/

// METHOD - 1

#include<bits/stdc++.h>
using namespace std;

bool is_valid(int i, int j, vector<vector<int>> &board, int n, int num) {
	for(int x = 0; x < n; x++) {
		if(board[x][j] == num || board[i][x] == num){
			return false;
		}
	}
	
	int sub_size = sqrt(n);
	int sx = (i / sub_size) * sub_size;
	int sy = (j / sub_size) * sub_size;
	
	for(int k = sx; k < (sx + sub_size); k++) {
		for(int l = sy; l < (sy + sub_size); l++) {
			if(board[k][l] == num) {
				return false;
			}
		}
	}
	
	return true;
}

bool sudoku_solver(int i, int j, vector<vector<int>> &board, int n) {
	// base case(s)
	if(i == n){
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			
			cout << "\n";
		}
		
		return false;
	}
	
	// go to the next row
	if(j == n) {
		return sudoku_solver(i + 1, 0, board, n);
	}
	
	// check for the next cell
	if(board[i][j] != 0) {
		return sudoku_solver(i, j + 1, board, n);
	}
	
	for(int num = 1; num <= n; num++) {
		if(is_valid(i, j, board, n, num)) {
			board[i][j] = num;
			bool next_cell_mein_sahi_num_rakh_paye = sudoku_solver(i, j + 1, board, n);
			
			if(next_cell_mein_sahi_num_rakh_paye == true) {
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

    cout << "Enter the size of Sudoku board(must be a perfect square): ";
    int n; cin >> n;
    cout << n << "\n";
    
    vector<vector<int>> board(n, vector<int>(n));
    cout << "Enter the sudoku(blanks cell to be represented by 0) ---> \n";
    
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++) {
    		cin >> board[i][j];
    	}
    }
	
	cout << "\n";
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

/***************************************************************************************************************/

// METHOD - 2
// Very much similar to "METHOD - 1", only the way of implementation has changed.

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())
#define vset(v, n, val) v.clear(); v.resize(n, val)

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(queue <T> v);
template <class T> void _print(priority_queue <T> v);
template <class T> void _print(stack <T> s);

// modify it's definition below as per need such as it can be used for STL containers with custom args passed
template <class T> void _print(T v); 

template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(multimap <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.front()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(priority_queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(stack <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(T v) {  }

/*******************************************************************************************************************************************************************/

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

bool is_safe(int row, int col, vvi &board, int n, int num) {
    bool ok = 1;
    
    for(int x = 0; x < n; x++) {
    	ok &= (board[row][x] != num);
    	ok &= (board[x][col] != num);
    }
    
    if(!ok) return 0;
    
    int sub_size = sqrt(n);
    
    for(int i = (row - (row % sub_size)); i <= (row - (row % sub_size) + sub_size - 1); i++) {
        for(int j = (col - (col % sub_size)); j <= (col - (col % sub_size) + sub_size - 1); j++) {
            ok &= (board[i][j] != num);
        }
    }
    
    if(!ok) return 0;
    return 1;
}
    
void sudoku_solver(int row, int col, vvi &board, int n) {
	// base case(s)
	if(row == n) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) cout << board[i][j] << " ";
			cout << "\n";
		}
		
		cout << "\n";
		
		return;	
	}
	
	// go to the next row
    if(col == n) {
    	sudoku_solver(row + 1, 0, board, n);
    	return;
    }

    // check for the next cell
    if(board[row][col] != 0) {
    	sudoku_solver(row, col + 1, board, n);
    	return;
    }
    
    for(int d = 1; d <= n; d++) {
        if(is_safe(row, col, board, n, d)) {
            board[row][col] = d;
            
            sudoku_solver(row, col + 1, board, n);
			
			// rolling back the decision taken so as to explore all possibilities
			board[row][col] = 0; 
        }
    }
    
    // case in which we are not able to place any num from 1 to 9 at pos(i, j)
    return;
}

void solve()
{
	
  	cout << "Enter the size of Sudoku board(must be a perfect square): ";
    int n; cin >> n;
    cout << n << "\n";
    
    vvi board(n, vi(n, 0));
    cout << "Enter the sudoku(blanks cell to be represented by 0) ---> \n";
    
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++) {
    		cin >> board[i][j];
    	}
    }
	
	cout << "\n";
	
	sudoku_solver(0, 0, board, n);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
    // #endif
    
    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}

/*Sample i/p:

4
1 0 0 0 
0 0 2 0
0 3 0 0 
0 0 0 0 

Sample o/p:

Enter the size of Sudoku board(must be a perfect square): 4
Enter the sudoku(blanks cell to be represented by 0) ---> 

1 2 3 4 
3 4 2 1 
4 3 1 2 
2 1 4 3 

1 2 4 3 
3 4 2 1 
2 3 1 4 
4 1 3 2 

1 2 4 3 
3 4 2 1 
4 3 1 2 
2 1 3 4 


*/