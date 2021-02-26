// Method 1

// Problem: Building Teams
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1668
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 26-02-2021 17:23:35 IST (UTC+05:30)
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
int team[100001];
bool ok;
int n, m;

void dfs(int curr, int par) {
	team[curr] = team[par] == 1 ? 2 : 1;
	
	for(auto x: g[curr]) {
		if(team[x] == -1) dfs(x, curr);
		else if(team[x] == team[curr]) {
			ok = 0;
			return;			
		}
	}
}

void solve()
{
  	memset(team, -1, sizeof team);
  	ok = 1;
  	team[0] = 1;
  	
  	cin >> n >> m;
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v);
  		g[v].pb(u);
  	}
  	
  	for(int i = 1; i <= n; i++) {
  		if(team[i] == -1) {
  			dfs(i, 0);
  		}
  	}
  	
  	if(!ok) cout << "IMPOSSIBLE\n";
  	else {
  		for(int i = 1; i <= n; i++) cout << team[i] << " ";
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

/*************************************************************************************************/

// Method 2
// Ref: https://www.youtube.com/watch?v=MDTq58KLIx0&list=PL2S6Mj7iLqEjNVq0e-pZ9rSnpAacHzVm3&index=5

// Problem: Building Teams
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1668
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 26-02-2021 17:23:35 IST (UTC+05:30)
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

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

vi g[100001];
int color[100001];
int n, m;

bool dfs(int curr, int par) {
  color[curr] = color[par] == 1 ? 2 : 1;
  
  for(auto x: g[curr]) {
    // if parent then continue
    if(x == par) continue;
    
    // if not colored then color it
    if(color[x] == -1) {
      if(!dfs(x, curr)) return false;
    }
    
    // check for any contradiction for already colored node
    if(color[curr] == color[x]) return false;
  }
  
  return true;
}

void solve()
{
    memset(color, -1, sizeof color);
    color[0] = 1;
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    
    for(int i = 1; i <= n; i++) {
      if(color[i] == -1) {
        if(!dfs(i, 0)) { cout << "IMPOSSIBLE\n"; return; }
      }
    }
    
    for(int i = 1; i <= n; i++) cout << color[i] << " ";
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