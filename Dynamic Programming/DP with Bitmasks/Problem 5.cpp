// Reference(s): https://www.youtube.com/watch?v=faqm76x4s_U
//               https://atcoder.jp/contests/abc190/submissions/19828399
//               https://atcoder.jp/contests/abc190/editorial/638

/************************************************************************************************************/

// In the below algorithm instead of running "Dijkstra's algorithm" we could also used simple BFS for
// finding out minimum distances.

/**********************************************************************************************************/

// Problem: E - Magical Ornament
// Contest: AtCoder - AtCoder Beginner Contest 190
// URL: https://atcoder.jp/contests/abc190/tasks/abc190_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Parsed on: 01-02-2021 11:35:13 IST (UTC+05:30)
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

int n, m, k;

int driver(int last, int mask, vvi &dp, vvi &d) {
	// base case
	if(mask == (1 << k) - 1) return 0;
	
	int &res = dp[mask][last];
	if(res != -1) return res;
	
	res = INF;
	for(int i = 0; i < k; i++) {
		if(mask & (1 << i)) continue;
		res = min(res, driver(i, mask | (1 << i), dp, d) + d[last][i]);
	}
	
	return res;
}

void solve()
{
  	cin >> n >> m;
  	vector<array<int, 2>> g[n];
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		--u; --v;
  		g[u].pb({1, v});
  		g[v].pb({1, u});
  	}
  	
  	cin >> k;
  	int arr[k];
  	for(int i = 0; i < k; i++) {
  		cin >> arr[i];
  		arr[i]--;
  	}
  	
  	vvi d(k, vi(k));
  	
  	// running dijkstra for every node in arr[] to find out the 
  	// the shortest distance between every pait of verices given in arr[]
  	for(int i = 0; i < k; i++) {
  		priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
  		int dis[n];
  		memset(dis, INF, sizeof dis);
  		q.push({0, arr[i]});
  		dis[arr[i]] = 0;
  		
  		while(!q.empty()) {
  			array<int, 2> x;
  			x = q.top();
  			q.pop();
  			if(x[0] > dis[x[1]]) continue;
  			for(auto y: g[x[1]]) {
  				if(dis[x[1]] + y[0] < dis[y[1]]) {
  					dis[y[1]] = dis[x[1]] + y[0];
  					q.push({dis[y[1]], y[1]});
  				}
  			}
  		}
  		
  		for(int j = 0; j < k; j++) d[i][j] = dis[arr[j]];
  	}
  	
  	vvi dp(1 << k, vi(k, -1));
  	int res = INF;
  	for(int i = 0; i < k; i++) {
  		res = min(res, 1 + driver(i, 1 << i, dp, d));
  	}
  	
  	if(res == INF) cout << -1 << "\n";
  	else cout << res << "\n";
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