/* Problem description ----->

You are given a matrix with N rows and M columns. Each cell is either dry or has water. We say that two cells 
are neighbours if they share one of their four sides. A pond is a maximal subset of cells containing water 
such that any cell is accessible from any other cell by moving only along neighbours. You should add water 
to exactly one cell in order to maximise the size of the pond.

Input Format ---->
The first line contains two integers N and M. Each of the next N lines contains M integers: 0 for a dry cell 
and 1 for a cell containing water.

Constraints ---->
1 ≤ N,M ≤ 1000 There is at least one dry cell and one cell filled with water in the matrix.

Output Format ---->
Print a single integer representing the largest possible size of the pond.

Sample Input --->
3 3
0 1 1
0 0 1
0 1 0

Sample Output --->
5

Explanation ---->
Watering the cell at coordinates [2,2] unites the 2 ponds with sizes 1 and 3, resulting a pond of size 5, 
including the newly watered cell.

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const int N = 1001;

int mat[N][N]; // to store the input as well as to make it work as graph later on
vector<vector<bool>> vis(N, vector<bool>(N)); // visited matrix
unordered_map<int, int> comp_sz; // comp_sz[i] will store the size of the component colored with color i
int n, m;

vi dx {-1, 0, 1, 0};
vi dy {0, 1, 0, -1};

bool is_valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

// simple BFS to color the cells belonging to the same conncected component
// with same color as well as store the size of the component colored with color col
void bfs(int i, int j, int col) {
	queue<pii> q;
	q.push({i, j});
	vis[i][j] = true;
	
	while(!q.empty()) {
		int x = q.front().F;
		int y = q.front().S;
		mat[x][y] = col;
		comp_sz[col]++;
		q.pop();
		
		for(int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if(is_valid(nx, ny) && !vis[nx][ny] && mat[nx][ny] != 0) {
				vis[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
	
}

void solve()
{
  	cin >> n >> m;
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) {
  			cin >> mat[i][j];
  			vis[i][j] = false;
  		}
  	}
  	
  	// starting marking cells of same connected component
  	// with same color
  	int col = 1;
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) {
  			if(!vis[i][j] && mat[i][j] != 0) {
  				bfs(i, j, col);
  				col++;
  			}
  		}
  	}
  	
  	// to store the final result
  	int res = INT_MIN;
  	
  	// whenever encountered a cell with 0 value, check the size
  	// of the connected component which can be formed by watering it
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) {
  			set<int> s; // to avoid extra addition in size 
  			if(mat[i][j] == 0) {
  				for(int k = 0; k < 4; k++) {
  					int nx = i + dx[k], ny = j + dy[k];
  					if(is_valid(nx, ny) && mat[nx][ny] != 0) s.insert(comp_sz[mat[nx][ny]]);
  				}
  				
  				int tmp = 0;
  				for(auto x: s) tmp += x;
  				// 1 is added to temp so as to include the curr cell [i][j] which 
  				// was initially dry
  				res = max(res, tmp + 1); 
  			}
  		}
  	}
  	
  	cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}