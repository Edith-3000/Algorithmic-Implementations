// Explanation: https://www.youtube.com/watch?v=yn6ZPaqwlso&list=PLb3g_Z8nEv1i26KO3g9Hw-taqgIejXH49&index=3
/**********************************************************************************************************/

// Problem: E. Directing Edges
// Contest: Codeforces - Codeforces Round #656 (Div. 3)
// URL: https://codeforces.com/contest/1385/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Parsed on: 29-01-2021 13:51:18 IST (UTC+05:30)
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

vi g[200001];
vpii directed, undirected;
vi sorted;
vector<bool> vis;
bool possible;
int n, m;

void topSort(int curr, set<int> &ancestors) {
	vis[curr] = 1;
	ancestors.insert(curr);
	
	for(auto child: g[curr]) {
		if(ancestors.find(child) != ancestors.end()) {
			possible = 0;
			return;
		}
		
		if(!vis[child]) topSort(child, ancestors);
	}
	
	ancestors.erase(curr);
	sorted.pb(curr);
}

void solve()
{
  	cin >> n >> m;
  	for(int i = 1; i <= n; i++) g[i].clear();
  	directed.clear();
  	undirected.clear();
  	sorted.clear(); // store the topological sorting in reverse order
  	vis.assign(n + 1, 0);
  	
  	for(int i = 1; i <= m; i++) {
  		int type, u, v; cin >> type >> u >> v;
  		if(type == 0) undirected.pb({u, v});
  		else {
  			directed.pb({u, v});
  			g[u].pb(v);
  		}
  	}
  	
  	possible = 1;
  	for(int i = 1; i <= n; i++) {
  		if(!vis[i]) {
  			set<int> ancestors;
  			topSort(i, ancestors);
  		}
  	}
  	
  	if(!possible) { cout << "NO\n"; return; }
  	
  	unordered_map<int, int> priority;
  	for(int i = 0; i < sorted.size(); i++) {
  		priority[sorted[i]] = i;
  	}
  	
  	cout << "YES\n";
  	for(auto p: directed) cout << p.F << " " << p.S << "\n";
  	for(auto p: undirected) {
  		int x = priority[p.F];
  		int y = priority[p.S];
  		
  		if(x > y) cout << p.F << " " << p.S;
  		else cout << p.S << " " << p.F;
  		cout << "\n";
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}