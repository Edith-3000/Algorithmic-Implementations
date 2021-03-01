// Problem: Flight Routes
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1196
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 01-03-2021 18:49:43 IST (UTC+05:30)
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
const int mod = 1e9+7;

vector<vpii> g;
vvll d;
int n, m, k;

void dijkstra() {
	d.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		d[i].resize(k, INF);
	}
	
	d[1][0] = 0LL;
	
	priority_queue<pair<ll, int>,
				   vector<pair<ll, int>>,
				   greater<pair<ll, int>>> q;
				   
	q.push({0, 1});
	
	while(!q.empty()) {
		ll dis = q.top().F;
		int cur = q.top().S;
		q.pop();
		
		if(d[cur][k-1] < dis) continue;
		
		for(auto x: g[cur]) {
			int nbr = x.F;
			ll w = x.S;
			
			if(dis + w < d[nbr][k-1]) {
				d[nbr][k-1] = dis + w;
				q.push({d[nbr][k-1], nbr});
				sort(d[nbr].begin(), d[nbr].end());
			}
		}
	}
}

void solve()
{
  	cin >> n >> m >> k;
  	
  	g.resize(n + 1);
  	for(int i = 0; i < m; i++) {
  		int u, v, w; cin >> u >> v >> w;
      	g[u].pb({v, w});  
  	}
  	
  	dijkstra();
  	
  	for(int i = 0; i < k; i++) {
  		cout << d[n][i] << " ";
  	}
  	
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