/* Problem description --->
   1. You are given an undirected graph with 'n' vertices & 'm' edges and a src vertex.
   2. You are required to find and print all hamiltonian paths and cycles starting from src. 
      The cycles must end with "*" and paths with a "."
*/

// Concept used in the below algorithm is very much similar to the concept which have been used in the file
// "Hamiltonian/Print all paths from a given source to a destination.cpp" with just a slight change in the case to print
// the path.

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

vvi g; 
vector<bool> vis;
vi res;
int n, m, ind, src;

void dfs(int curr) {
	vis[curr] = 1;
	res[ind] = curr;
	ind++;
	
	if(ind == n) {
		for(int i = 0; i < n; i++) {
			if(i == (n - 1)) cout << res[i];
			else cout << res[i] << " ";
		}
		
		bool is_cycle = false;
		for(auto x: g[curr]) {
			if(x == src) {
				is_cycle = true;
				break;
			}
		}
		
		cout << (is_cycle ? "*" : ".") << "\n";
	}
	
	else {
		vis[curr] = 1;
		for(auto x: g[curr]) {
			if(!vis[x]) {
				res.pb(x);
				dfs(x);
		    }
	    }
	}
	
	ind--;
	vis[curr] = 0; // unvisit the current node so as to explore all possibilites
}

void solve()
{
  	cin >> n >> m;
  	g.clear(); g.resize(n);
  	vis.assign(n, 0);
  	res.clear(); res.resize(n);
  	
  	// vertices are 0-based indexed
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v);
  		g[v].pb(u);
  	}
  	
  	cin >> src;
  	ind = 0;
  	dfs(src);
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

/*

Sample i/p --->

7 9
0 1
0 3
1 2
2 3 
2 5
3 4
4 5
4 6
5 6
0

Sample o/p --->

0 1 2 3 4 5 6.
0 1 2 3 4 6 5.
0 1 2 5 6 4 3*
0 3 4 6 5 2 1*

*/

// Time complexity ---> 