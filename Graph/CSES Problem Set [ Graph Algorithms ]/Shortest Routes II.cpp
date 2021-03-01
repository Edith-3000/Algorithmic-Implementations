/* # WARNING: The below implementation has given WA in some test cases in CSES, this is because
              below implementation ignores the presence of multiple edges in the input graph.

  # To avoid such errors use the second implementation.
*/

// Implementation which gave WA because of "WARNING" written above.

// Problem: Shortest Routes II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1672
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 01-03-2021 10:48:40 IST (UTC+05:30)
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

const ll INF = 1e15;
const int mod = 1e9+7;

vvll g;
int n, m, q;

void floyd_warshall() {
	for(int aux = 1; aux <= n; aux++) {
		for(int src = 1; src <= n; src++) {
			for(int dst = 1; dst <= n; dst++) {
				if(g[src][aux] < INF and g[aux][dst] < INF) {
					g[src][dst] = min(g[src][dst], g[src][aux] + g[aux][dst]);
				}
			}
		}
	}
}

void solve()
{
  	cin >> n >> m >> q;
  	
  	g.resize(n + 1);
  	for(int i = 1; i <= n; i++) {
  		g[i].resize(n + 1, 0);
  	}
  	
  	for(int i = 0; i < m; i++) {
  		int u, v, wt; 
  		cin >> u >> v >> wt;
  		g[u][v] = g[v][u] = wt;
  	}
  	
  	for(int i = 1; i <= n; i++) {
  		for(int j = 1; j <= n; j++) {
  			if((i != j) and (g[i][j] == 0)) g[i][j] = INF;
  		}
  	}
  	
  	floyd_warshall();
  	
  	while(q--) {
  		int a, b; cin >> a >> b;
  		if(g[a][b] == INF) cout << -1 << "\n";
  		else cout << g[a][b] << "\n";
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

/**************************************************************************************************/

// Implementation which got an AC

// Problem: Shortest Routes II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1672
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 01-03-2021 10:48:40 IST (UTC+05:30)
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const ll INF = 1e15;
const int mod = 1e9+7;

vvll g;
int n, m, q;

void floyd_warshall() {
  for(int aux = 1; aux <= n; aux++) {
    for(int src = 1; src <= n; src++) {
      for(int dst = 1; dst <= n; dst++) {
        if(g[src][aux] < INF and g[aux][dst] < INF) {
          g[src][dst] = min(g[src][dst], g[src][aux] + g[aux][dst]);
        }
      }
    }
  }
}

void solve()
{
    cin >> n >> m >> q;
    
    g.resize(n + 1);
    for(int i = 1; i <= n; i++) {
      g[i].resize(n + 1, 0);
    }
    
    for(int i = 1; i <= n; i++) {
      for(int j = i + 1; j <= n; j++) {
        g[i][j] = g[j][i] = INF;
      }
    }
    
    for(int i = 0; i < m; i++) {
      int u, v, wt; 
      cin >> u >> v >> wt;
      g[u][v] = g[v][u] = min(g[u][v], (ll)wt);
    }
    
    floyd_warshall();
    
    while(q--) {
      int a, b; cin >> a >> b;
      if(g[a][b] == INF) cout << -1 << "\n";
      else cout << g[a][b] << "\n";
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