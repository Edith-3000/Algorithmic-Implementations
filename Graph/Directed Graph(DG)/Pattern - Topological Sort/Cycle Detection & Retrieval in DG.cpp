// Problem: Round Trip II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1678
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 02-03-2021 00:19:14 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

// stores the input graph
vvi g;

// to push the nodes which are a part of the 
// current path in DFS
stack<int> stk;

// to keep track, whether any vertex 'i' is part
// of the current stack
vector<bool> stk_flag;

// to keep track of visited vertices
vector<bool> vis;

int n, m;

bool dfs(int cur) {
	// mark the vertex as visited
	vis[cur] = 1;
	
	// push it in the current path stack
	stk.push(cur);
	
	// mark it's presence in the current path stack
	stk_flag[cur] = 1;
	
	for(auto x: g[cur]) {
		// explore if 'x' is unvisited
		if(!vis[x]) {
			if(dfs(x)) return true;
		}
		
		// if 'x' is visited and is also a part
		// of current path stack, then cycle detected
		else if(stk_flag[x]) {
			stk.push(x);
			return true; // no more DFS (as cycle detected)
		}
	}
	
	stk.pop();
	stk_flag[cur] = 0;
	return false; // no cycle detected
}

bool visit_all() {
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			if(dfs(i)) return true;
		}
	}
	
	return false;
}

void solve()
{
  	cin >> n >> m;
  	
  	g.resize(n + 1);
  	stk_flag.resize(n + 1, 0);
  	vis.resize(n + 1, 0);
  	
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v);
  	}
  	
  	// check cycle presence for all the connected 
  	// components of the input graph
  	if(!visit_all()) {
  		cout << "IMPOSSIBLE\n";
  		return;
  	}
  	
  	// retrieval of the cycle
  	vector<int> path;
  	int tmp = stk.top();
  	
  	while(!stk.empty()) {
  		path.pb(stk.top());
  		stk.pop();
  		if(path.back() == tmp and path.size() > 1) break;
  	}
  	
  	reverse(begin(path), end(path));
  	
  	cout << path.size() << "\n";
  	for(auto x: path) cout << x << " ";
  	cout << "\n";
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