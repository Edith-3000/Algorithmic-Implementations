// Problem: Investigation
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1202
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 02-03-2021 12:42:28 IST (UTC+05:30)
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

const ll INF = 1e17;
const ll mod = 1e9+7;

// adjacency list representation of input graph
vector<vpll> g; 

// cost[i] = minimum cost required to reach vertex 'i' from 
// soucre vertex (which is = 1, in this problem)
vll cost;

// routes[i] = (total #min price routes) % mod, from 1 to i
vll routes;

// min_f[i] = minimum #flights in minimum-price route from 1 to i
vi min_f;

// max_f[i] = maximum #flights in minimum-price route from 1 to i
vi max_f;

int n, m;

void dijkstra() {
	for(int i = 1; i <= n; i++) cost[i] = INF;
	cost[1] = 0LL;
	routes[1] = 1LL;
	
	priority_queue<pll, vpll, greater<pll>> q;
	q.push({0, 1});
	
	while(!q.empty()) {
		ll d = q.top().F;
		int cur = q.top().S;
		q.pop();
		if(cost[cur] < d) continue;
		
		// Current cost to nbr = cost[nbr]
		// Proposed cost to nbr through cur = d + wt 
		for(auto &[nbr, wt]: g[cur]) {
			// If Proposed cost > Current cost, do nothing
			if(d + wt > cost[nbr]) continue;
			
			// If Proposed cost = Current cost, do incerments
			// and other necessary changes
			else if(d + wt == cost[nbr]) {
				routes[nbr] = (routes[nbr] + routes[cur]) % mod;
				min_f[nbr] = min(min_f[nbr], min_f[cur] + 1);
				max_f[nbr] = max(max_f[nbr], max_f[cur] + 1);
			}
			
			// If Proposed cost < Current cost, do resetting
			// as we've found a more optimal cost to reach nbr
			else {
				cost[nbr] = d + wt;
				q.push({cost[nbr], nbr});
				
				routes[nbr] = routes[cur];
				min_f[nbr] = min_f[cur] + 1;
				max_f[nbr] = max_f[cur] + 1;
			}
		}
	}
}

void solve()
{
  	cin >> n >> m;
  	
  	g.resize(n + 1);
  	cost.resize(n + 1);
  	routes.resize(n + 1);
  	min_f.resize(n + 1);
  	max_f.resize(n + 1);
  	
  	for(int i = 0; i < m; i++) {
  		int u, v, wt; 
  		cin >> u >> v >> wt;
  		g[u].pb({v, wt});
  	}
  	
  	dijkstra();
  	
  	cout << cost[n] << " " << routes[n] << " " << min_f[n] << " " << max_f[n];
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