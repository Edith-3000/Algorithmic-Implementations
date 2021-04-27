// Problem: https://www.interviewbit.com/problems/valid-path/
// Ref: https://www.geeksforgeeks.org/path-rectangle-containing-circles/
/*******************************************************************************************************/

// USING BFS

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
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

vi dx = {-1, -1, 0, 1, 1, 1, 0, -1};
vi dy = {0, 1, 1, 1, 0, -1, -1, -1};

int dist(int x1, int y1, int x2, int y2) {
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool is_valid(int x, int y, int rows, int cols) {
	return x >= 0 and x < rows and y >= 0 and y < cols;
}

bool possible(int x, int y, int n, int r, vi &a, vi &b) {
	int rows = y + 1, cols = x + 1;
	vvi grid(rows, vi(cols, 0));
	
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			for(int circle = 0; circle < n; circle++) {
				int x_cord =  a[circle]; 
				int y_cord = rows - 1 - b[circle];
				if(dist(j, i, x_cord, y_cord) <= (r * r)) grid[i][j] = -1;
			}
		}
	}
	
	if(grid[rows-1][0] == -1) {
		return false;
	}
	
	queue<pii> q;
	q.push({rows-1, 0});
	grid[rows-1][0] = 1;
	
	while(!q.empty()) {
		pii cur = q.front();
		q.pop();
		
		for(int d = 0; d < 8; d++) {
			int nx = cur.F + dx[d];
			int ny = cur.S + dy[d];
			if(is_valid(nx, ny, rows, cols) and grid[nx][ny] == 0) {
				grid[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
	
	if(grid[0][cols-1] == 1) return true;
	else return false;
}

void solve()
{
  	int x, y; cin >> x >> y;
  	int n, r; cin >> n >> r;
  	vi a(n), b(n);
  	
  	for(int i = 0; i < n; i++) cin >> a[i];
  	for(int i = 0; i < n; i++) cin >> b[i];
  	
  	if(possible(x, y, n, r, a, b)) cout << "YES\n";
  	else cout << "NO\n";
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

/******************************************************************************************************/

// USING DFS

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
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

vi dx = {-1, -1, 0, 1, 1, 1, 0, -1};
vi dy = {0, 1, 1, 1, 0, -1, -1, -1};

int dist(int x1, int y1, int x2, int y2) {
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool is_valid(int x, int y, int rows, int cols) {
	return x >= 0 and x < rows and y >= 0 and y < cols;
}

void dfs(pii src, vvi &grid, int rows, int cols) {
	grid[src.F][src.S] = 1;
	
	for(int d = 0; d < 8; d++) {
		int nx = src.F + dx[d];
		int ny = src.S + dy[d];
		if(is_valid(nx, ny, rows, cols) and grid[nx][ny] == 0) {
			dfs({nx, ny}, grid, rows, cols);
		}
	}
}

bool possible(int x, int y, int n, int r, vi &a, vi &b) {
	int rows = y + 1, cols = x + 1;
	vvi grid(rows, vi(cols, 0));
	
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			for(int circle = 0; circle < n; circle++) {
				int x_cord =  a[circle]; 
				int y_cord = rows - 1 - b[circle];
				if(dist(j, i, x_cord, y_cord) <= (r * r)) grid[i][j] = -1;
			}
		}
	}
	
	if(grid[rows-1][0] == -1) {
		return false;
	}
	
	dfs({rows - 1, 0}, grid, rows, cols);
	
	if(grid[0][cols-1] == 1) return true;
	else return false;
}

void solve()
{
  	int x, y; cin >> x >> y;
  	int n, r; cin >> n >> r;
  	vi a(n), b(n);
  	
  	for(int i = 0; i < n; i++) cin >> a[i];
  	for(int i = 0; i < n; i++) cin >> b[i];
  	
  	if(possible(x, y, n, r, a, b)) cout << "YES\n";
  	else cout << "NO\n";
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}