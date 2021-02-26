// Following question is based on "Cycle retrieval in an Undirected Graph."
// Ref: https://www.youtube.com/watch?v=qYyyj2SRsRc&list=PL2S6Mj7iLqEjNVq0e-pZ9rSnpAacHzVm3&index=6
/***************************************************************************************************/

// Problem: Round Trip
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1669
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 26-02-2021 18:22:52 IST (UTC+05:30)
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

vi g[100001];
int parent[100001];
bool vis[100001];
int start_ver, end_ver;
int n, m;

bool dfs(int curr, int par) {
	vis[curr] = 1;
	parent[curr] = par;
	
	for(auto x: g[curr]) {
		if(x == par) continue;
		
		if(!vis[x]) {
			if(dfs(x, curr)) return true;
		}
		
		else {
			end_ver = curr; start_ver = x;
			return true;
		}
	}
	
	return false;
}

bool visit_all() {
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			if(dfs(i, 0)) return true;
		}
	}
	
	return false;
}

void solve()
{
  	cin >> n >> m;
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v);
  		g[v].pb(u);
  	}
  	
  	if(!visit_all()) { 
  		cout << "IMPOSSIBLE\n";
  		return;
  	}
  	
  	vi res;
  	int prev = end_ver;
  	res.pb(prev);
  	
  	while(prev != start_ver) {
  		res.pb(parent[prev]);
  		prev = parent[prev];
  	}
  	
  	res.pb(end_ver);
  	
  	cout << res.size() << "\n";
  	for(auto x: res) cout << x << " ";
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