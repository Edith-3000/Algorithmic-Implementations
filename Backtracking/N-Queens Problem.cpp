/* PROBLEM STATEMENT: Given a chessboard of size n x n, determine how many ways n queens can be placed on 
                      this board so that no two queens attack each other.
                      The chess queens(wazeer) can attack in any direction as horizontal, vertical and 
                      diagonal way.
                      A matrix must be used to display the positions of N Queens, where no queens can 
                      attack other queens (use 'Q' for queen and '.' for empty position).
*/

/****************************************************************************************************************************************************************/

// METHOD - 1

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

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// in this function no need to check below the current row as 
// we are filling the rows from top to bottom
bool is_valid(int i, int j, int n, vvi &board) {
	// check for all the cells vertically above the ith row
	for(int row = 0; row < i; row++) {
		if(board[row][j] == 1) return false;
	}
	
	// check for all the left diagonal positions
	int x = i - 1, y = j - 1;
	
	while(x >= 0 and y >= 0) {
		if(board[x][y] == 1) return false;
		x -= 1;
		y -= 1;
	}
	
	// check for all the right diagonal positions
	x = i - 1, y = j + 1;
	
	while(x >= 0 and y < n) {
		if(board[x][y] == 1) return false;
		x -= 1;
		y += 1;
	}
	
	// if safe position return true
	return 1;
}

bool n_queen(int i, int n, vvi &board) {
	// base case
	// it signifies that we've successfully reached the last row and
	// placed a queen in all rows from (0...n-1) (i.e. reaches the complete 
	// depth of recursion) just print this valid configuration
	if(i == n) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(board[i][j] == 1) cout << 'Q' << " ";
				else cout << '_' << " ";
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
		// check is it safe to place the queen at position (i, j)
		if(is_valid(i, j, n, board)) {
			// if position (i, j) is safe place the queen at this position
			board[i][j] = 1;
			
			// try to place another queen in the next row
			bool next_row_mein_queen_rakh_paye = n_queen(i + 1, n, board);
			
			if(next_row_mein_queen_rakh_paye == true) {
				return true;
			}
			
			// rolling back the incorrect decision
			else board[i][j] = 0;
		}
	}
	
	// case in which we are not able to place a queen in the current row 'i'
	return false;
}

void solve()
{
  	cout << "Enter the chessboard size: ";
    int n; cin >> n;
    cout << n << "\n\n";
    
    vvi board(n, vi(n, 0));
    
    // we'll place queens row-wise (1 queen in a row)
    // start by trying to place a queen in 0th row at suitable column index
    n_queen(0, n, board);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

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

// Time Complexity: Exponential, for details ===>
// Refer: https://medium.com/@jmohon1986/timeout-the-story-of-n-queens-time-complexity-c80636d92f8b#:~:text=The%20worst%20case%20%E2%80%9Cbrute,N%20times%2C%20for%20N%20queens.&text=However%2C%20if%20it%20is%20found,and%20try%20another%20safe%20position.
//        https://www.youtube.com/watch?v=EYjmtxbRnns
// In the description of the video: https://www.youtube.com/watch?v=wGbuCyNpxIg

// https://gist.github.com/Edith-3000/fcff6223d07c69c41a56162891628130

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

/*********************************************************************************************************************************************************************/

// METHOD - 2 
// In this method there is just slight optimization of the is_valid() fn. (which runs in O(n) time).
// Here in this algorithm that work is being done in O(1) time.

// Ref to this optimization: see @27:35 in the link below ===>
// https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0rQ6cnlaHRMuOp4H_D-7hwP&index=9

// Similar kind of optimization can also be done as given in GfG article
// https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/

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

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

bool n_queen(int i, int n, vvi &board, vi &up_col, vi &left_diag, vi &right_diag) {
	// base case
	// it signifies that we've successfully reached the last row and
	// placed a queen in all rows from (0...n-1) (i.e. reaches the complete 
	// depth of recursion) just print this valid configuration
	if(i == n) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(board[i][j] == 1) cout << 'Q' << " ";
				else cout << '_' << " ";
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
		// check is it safe to place the queen at position (i, j)
		if(up_col[j] == 0 and left_diag[i - j + n - 1] == 0 and right_diag[i + j] == 0) {
			// if position (i, j) is safe place the queen at this position
			board[i][j] = 1;
			up_col[j] = 1; 
			left_diag[i - j + n - 1] = 1;
			right_diag[i + j] = 1;
			
			// try to place another queen in the next row
			bool next_row_mein_queen_rakh_paye = n_queen(i+1, n, board, up_col, left_diag, right_diag);
			
			if(next_row_mein_queen_rakh_paye == true) {
				return true;
			}
			
			// rolling back the incorrect decision
			else {
				board[i][j] = 0;
				up_col[j] = 0; 
				left_diag[i - j + n - 1] = 0;
				right_diag[i + j] = 0;
			}
		}
	}
	
	// case in which we are not able to place a queen in the current row 'i'
	return false;
}

void solve()
{
  	cout << "Enter the chessboard size: ";
    int n; cin >> n;
    cout << n << "\n\n";
    
    vvi board(n, vi(n, 0));
    
    // these vectors will check in constant time that whether it is possible
    // to place a queen at index (i, j)
    vi up_col(n, 0);
    vi left_diag(2 * n - 1, 0);
    vi right_diag(2 * n - 1, 0);
    
    // we'll place queens row-wise (1 queen in a row)
    // start by trying to place a queen in 0th row at suitable column index
    n_queen(0, n, board, up_col, left_diag, right_diag);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

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