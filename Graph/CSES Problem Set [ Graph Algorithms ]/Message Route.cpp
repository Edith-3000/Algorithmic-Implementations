// Method 1

// Problem: Message Route
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1667
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 26-02-2021 20:23:01 IST (UTC+05:30)
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
int n, m;

bool bfs() {
	queue<int> q;
	parent[1] = 0;
	vis[1] = 1;
	q.push(1);
	
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		if(curr == n) return 1;
		
		for(auto x: g[curr]) {
			if(!vis[x]) {
				vis[x] = 1;
				q.push(x);
				parent[x] = curr;
			}
		}
	}
	
	return 0;
}

void solve()
{
  	cin >> n >> m;
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v);
  		g[v].pb(u);
  	}
  	
  	if(!bfs()) {
  		cout << "IMPOSSIBLE\n";
  		return;
  	}
  	
  	vi res;
  	int prev = n;
  	res.pb(prev);
  	
  	while(prev != 1) {
  		res.pb(parent[prev]);
  		prev = parent[prev];
  	}
  	
  	reverse(res.begin(), res.end());
  	
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

/*********************************************************************************************/

// Method 2
// The only difference b/w this and the above mwthod is that in this method I've used std::stack
// for retrieval of the path.

// Problem: Message Route
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1667
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 26-02-2021 20:23:01 IST (UTC+05:30)
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
int parent[100001];
bool vis[100001];
int n, m;

bool bfs() {
  queue<int> q;
  parent[1] = 0;
  vis[1] = 1;
  q.push(1);
  
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    if(curr == n) return 1;
    
    for(auto x: g[curr]) {
      if(!vis[x]) {
        vis[x] = 1;
        q.push(x);
        parent[x] = curr;
      }
    }
  }
  
  return 0;
}

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
      int u, v; cin >> u >> v;
      g[u].pb(v);
      g[v].pb(u);
    }
    
    if(!bfs()) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    
    int current_node = n;
    stack<int> stk;
    
    while(current_node != 0) {
      stk.push(current_node);
      current_node = parent[current_node];
    }
    
    cout << stk.size() << "\n";
    while(!stk.empty()) {
      cout << stk.top() << " ";
      stk.pop();
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