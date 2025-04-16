// This type of method will be used in "Hamiltonian/Find & Print All Hamiltonian Paths & Cycles From a Given src in an UG.cpp",
//  that is why this problem is being put in this folder.

// Refer: https://www.tutorialspoint.com/print-all-paths-from-a-given-source-to-a-destination-in-cplusplus
//        https://www.geeksforgeeks.org/find-paths-given-source-destination/

// Below approach can be used for Directed as well as Undirected Graphs

/* Algorithm ---> 
   1. The idea is to do Depth First Traversal of given graph.
   2. Start the DFS traversal from source.
   3. Keep storing the visited vertices in an array or HashMap say ‘res[]’.
   4. If the destination vertex is reached, print contents of res[].
   5. The important thing is to mark current vertices in the res[] as visited also so that the traversal 
      doesn’t go in a cycle, as well as mark them unvisited in the returning phase of the DFS(recursion).
      So as to explore all the available paths.
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

vvi g;
vector<bool> vis;
vi res;
int n, m, ind, src, des;

void dfs(int curr = src) {
	vis[curr] = 1;
	res[ind] = curr;
	ind++;
	
	if(curr == des) {
		for(int i = 0; i < ind; i++) cout << res[i] << " ";
		cout << "\n";
	}
	
	else {
		for(auto x: g[curr]) {
			if(!vis[x]) dfs(x);
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
  	
  	cin >> src >> des;
  	ind = 0;
  	dfs();
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
0 4

Sample o/p --->

0 1 2 3 4 
0 1 2 5 4 
0 1 2 5 6 4 
0 3 2 5 4 
0 3 2 5 6 4 
0 3 4 

*/

// Time Complexity: O(|V| ^ |V|). 
// The time complexity is polynomial because from each vertex there are V vertices that can be visited from 
// current vertex.