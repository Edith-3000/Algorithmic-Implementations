// Method 1

// Problem: Counting Rooms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1192
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 11-12-2020 05:20:25 IST (UTC+05:30)
// Author: kapil_choudhary
 
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
 
const int mod = 1e9+7;
int n, m;
 
vi dx{-1, 0, 1, 0};
vi dy{0, 1, 0, -1};
 
void flood_fill(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited){
	if(x < 0 || x >= n || y < 0 || y >= m) return;
	if(grid[x][y] != '.' || visited[x][y]) return;
	
	visited[x][y] = true;
	
	for(int k = 0; k < 4; k++){
		int nx = x + dx[k], ny = y + dy[k];
		flood_fill(nx, ny, grid, visited);
	}
}
 
void solve()
{
  	cin >> n >> m;
  	vector<vector<char>> grid(n, vector<char>(m));
  	for(int i = 0; i < n; i++){
  		for(int j = 0; j < m; j++){
  			cin >> grid[i][j];
  		}
  	}
  	
  	vector<vector<bool>> visited(n, vector<bool>(m, 0));
  	int res = 0;
  	
  	for(int i = 0; i < n; i++){
  		for(int j = 0; j < m; j++){
  			if(grid[i][j] == '.' && !visited[i][j]){
  				flood_fill(i, j, grid, visited);
  				res++;
  			}
  		}
  	}
  	
  	cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
 
    return 0;
}

/**************************************************************************************************/

// Method 2

// Problem: Counting Rooms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1192
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 11-12-2020 05:54:28 IST (UTC+05:30)
// Author: kapil_choudhary
 
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
 
const int mod = 1e9+7;
char grid[1000][1000];
bool visited[1000][1000] = {0};
int n, m;
 
vi dx{-1, 0, 1, 0};
vi dy{0, 1, 0, -1};
 
bool is_valid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < m);
}
 
void dfs_helper(int x, int y){
	visited[x][y] = true;
	
	for(int k = 0; k < 4; k++){
		int nx = x + dx[k], ny = y + dy[k];
		if(!visited[nx][ny] && is_valid(nx, ny) && grid[nx][ny] == '.'){
			dfs_helper(nx, ny);
		}
	}
}
 
void solve()
{
  	cin >> n >> m;
  	for(int i = 0; i < n; i++){
  		for(int j = 0; j < m; j++){
  			cin >> grid[i][j];
  		}
  	}
  	
  	int res = 0;
  	for(int i = 0; i < n; i++){
  		for(int j = 0; j < m; j++){
  			if(grid[i][j] == '.' && !visited[i][j]){
  				dfs_helper(i, j);
  				res++;
  			}
  		}
  	}
  	
  	cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }
 
    return 0;
}