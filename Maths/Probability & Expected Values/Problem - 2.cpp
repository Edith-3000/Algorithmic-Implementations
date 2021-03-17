// Ref: https://www.youtube.com/watch?v=QlKNOQKlFto
/***************************************************************************************************/

// Method 1 (Using 2 DFS)

// Problem: C. Journey
// Contest: Codeforces - Codeforces Round #428 (Div. 2)
// URL: https://codeforces.com/problemset/problem/839/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 17-03-2021 09:45:59 IST (UTC+05:30)
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
vi depth, children;
int n;
double res;

void dfs(int cur, int par) {
	if(cur) depth[cur] = depth[par] + 1;
	
	for(auto child: g[cur]) {
		if(child != par) {
			children[cur]++;
			dfs(child, cur);
		}
	}
}

void exp_len(int cur, int par, double probability) {
	bool leaf = 1;
	
	for(auto child: g[cur]) {
		if(child != par) {
			leaf = 0;
			exp_len(child, cur, probability / children[cur]);
		}
	}
	
	if(leaf) res += depth[cur] * probability;
}

void solve()
{
  	cin >> n;
  	
  	g.clear(); g.resize(n);
 	depth.clear(); depth.resize(n, 0);
 	children.clear(); children.resize(n, 0);
  	res = 0.0;
  	
  	for(int i = 0; i < n - 1; i++) {
  		int u, v; cin >> u >> v;
  		u -= 1, v -= 1;
  		g[u].pb(v);
  		g[v].pb(u);
  	}
  	
  	dfs(0, 0);
  	exp_len(0, 0, 1.0);
  	  	
  	cout << fixed << setprecision(6) << res << "\n";
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

/*******************************************************************************************************/

// Method 2 (Using 1 DFS)

// Problem: C. Journey
// Contest: Codeforces - Codeforces Round #428 (Div. 2)
// URL: https://codeforces.com/problemset/problem/839/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 17-03-2021 09:45:59 IST (UTC+05:30)
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
int n;
double res;

void dfs(int cur, int par, int depth, double probability) {
	 // count how many children the current node has
	int children = 0;
	
	for(auto child: g[cur]) {
		if(child != par) children++;
	}
	
	// split the probability of the current node with all it's children
	for(auto child: g[cur]) {
		if(child != par) dfs(child, cur, depth + 1, probability / children);
	}
	
	// check if the current node is a leaf node
	if(children == 0) {
		res += depth * probability;
	}
}

void solve()
{
  	cin >> n;
  	
  	g.clear(); g.resize(n);
  	res = 0.0;
  	
  	for(int i = 0; i < n - 1; i++) {
  		int u, v; cin >> u >> v;
  		u -= 1, v -= 1;
  		g[u].pb(v);
  		g[v].pb(u);
  	}
  	
  	dfs(0, 0, 0, 1.0);  	  	
  	cout << fixed << setprecision(6) << res << "\n";
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