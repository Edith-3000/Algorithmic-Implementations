/* Problem Description ---->

Field of Dreams:
• A field is represented by a 2D grid of size N x M.
• Each cell in the grid is either a "g" cell or a "d" cell where "g" denotes grass and "d" denotes dirt.
• Two cells are said to be connected if they share an edge.
• The grid is said to be connected if all the "g"  cells can be travelled without passing through a "d" cell.
  Otherwise the grid is said to be disconnected.
 
Write a program to find the minimum number of "g" cells that must be replaced by "d" cells such that the grid is disconnected. If the grid is initially disconnected print 0.
 
Input format
• First line: N and M
• Next N lines: M non space-separated characters (g or d)
 
Output format
Print the minimum number of "g" cells that must be replaced by "d" cells such that the grid is disconnected. If the grid is initially disconnected print 0.
 
Contraints
1 <= N
M <= 400
 
Sample input
ggg
gdg
ggg 
 
Sample output
2

*/

/* # The main crux of the problem is that the answer will always be less than or equal to 2.
   # We form an Undirected Graph of the cells which are green (i.e. "g") & then if ---->
     • #connected components > 1, answer = 0.
     • if(there is atleast one articulation point in the graph), answer = 1 (since the articulation
       point will increase the #connected components, thereby graph will become disconneted as a whole).
     • else our answer will be = 2 (as there are only 3 possible answers - 0 or 1 or 2).
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

string arr[401]; // to take input 
vvi g; // to store the undirected graph

// cur will be used to assign unique value to (i, j) pair of a 'g' cell
// comp will count the #connected components in our graph
// n, m are size of input matrix
int cur = 0, comp = 0, n, m;

// variable to tell whether graph contain cut vertex (articulation pt) or not
bool flag = false;

// to assign unique value to (i, j) value of a grass 'g' cell,
// which will be later on used to construct undirected graph 
// do not use unordered_map instead of map, (for inserting pair as
// key in unordered_map, custom hash function should be defined)
map<pii, int> cd; 

vi dx{-1, 0, 1, 0};
vi dy{0, 1, 0, -1};

bool is_valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

void add_edges() {
	g.resize(cur);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(arr[i][j] == 'd') continue;
			
			int v = cd[{i, j}];
			for(int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if(is_valid(nx, ny) && arr[nx][ny] == 'g') {
					g[v].pb(cd[{nx, ny}]);
				} 
			}
		}
	}
	
	// as cur store the #vertices in our graph
	// now n will also store the same
	n = cur;
}

vector<bool> vis;
vi tin, low;
int timer;
     
void dfs(int curr, int par = -1) {
	vis[curr] = 1;
	tin[curr] = low[curr] = timer++;
	int children = 0;
	
	for(auto x: g[curr]) {
		if(x == par) continue;
		if(vis[x]) low[curr] = min(low[curr], tin[x]);
		else {
			dfs(x, curr);
			low[curr] = min(low[curr], low[x]);
			children++;
			
			// to check if x is articulation point or not
			if(low[x] >= tin[curr] && par != -1) flag = true;
		}
	}
	
	// special case for the root node
	if(par == -1 && children > 1) flag = true;
}
      
void find_cutpoints() {
	vis.assign(n, 0);
	tin.assign(n, -1);
	low.assign(n, -1);
	timer = 0;
	
	for(int v = 0; v < n; v++) {
		if(!vis[v]) {
			comp++; // increase the #connected coponents
			dfs(v);
		}
	}
}
             
void solve()
{
  	cin >> n >> m;
  	for(int i = 0; i < n; i++) cin >> arr[i];
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) {
  			if(arr[i][j] == 'g') cd[{i, j}] = cur++;
  		}
  	}
  	
  	// construct the graph
  	add_edges();
  	
  	// if there are 0 vertices in our graph
  	if(!n) cout << 0 << "\n";
  	
  	// if only 1 vertex remove it
  	else if(n == 1) cout << 1 << "\n";
  	
  	else {
  		find_cutpoints();
  		
  		// if connected componets > 1, then no need to convert 
  		// any 'd' cell to 'g' cell  	
  		if(comp > 1) cout << 0 << "\n";
  		
  		// if there is atleast one cut point, then converting that
  		// vertex to 'd' will suffice
  		else if(flag == true) cout << 1 << "\n";
  		
  		else cout << 2 << "\n"; 	
  	}
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