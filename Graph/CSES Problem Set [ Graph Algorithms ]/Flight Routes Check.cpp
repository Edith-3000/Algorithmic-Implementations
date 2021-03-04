/* Ref: https://cp-algorithms.com/graph/strongly-connected-components.html
        https://github.com/mrsac7/CSES-Solutions/blob/master/src/1682%20-%20Flight%20Routes%20Check.cpp
        https://usaco.guide/solutions/cses-1682?lang=cpp
*/

// Problem: Flight Routes Check
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1682
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 03-03-2021 22:17:07 IST (UTC+05:30)
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

vvi g;
vvi rg;
vector<bool> vis;
vi color;
vi order;
int n, m;

void dfs(int src) {
	vis[src] = 1;
	
	for(auto x: g[src]) {
		if(!vis[x]) dfs(x);
	}
	
	order.pb(src);
}

void reverse_dfs(int src) {
	vis[src] = 1;
	
	for(auto x: rg[src]) {
		if(!vis[x]) reverse_dfs(x);
	}
}

void solve()
{
  	cin >> n >> m;
  	
  	g.resize(n + 1);
  	rg.resize(n + 1);
  	vis.assign(n + 1, 0);
  	color.resize(n + 1);
  	
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v);
  		rg[v].pb(u);
  	}
  	
  	for(int i = 1; i <= n; i++) {
  		if(!vis[i]) dfs(i);
  	}
  	
  	fill(vis.begin(), vis.end(), 0);
  	
  	int x = order[n-1];
  	reverse_dfs(x);  
  	
  	for(int i = 1; i <= n; i++) {
  		if(i == x) continue;
  		if(!vis[i]) {
  			cout << "NO\n";
  			for(auto j: g[i]) {
  				if(j == x) { 
  					cout << x << " " << i << "\n";
  					return;  
  				}
  			}
  			
  			cout << i << " " << x << "\n";
  			return;
  		}
  	}
  	
  	cout << "YES\n";
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