// Problem ----> Given an undirected tree with n vertices and root in the vertex 1. Find out the value of the 
//               smallest node in subtree rooted at each of the vertex from 1 to n.

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
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

vi g[100005];
vi dp(100005);

void dfs(int curr, int par) {
	dp[curr] = curr;
	for(auto x: g[curr]) {
		if(x != par) {
			dfs(x, curr);
			dp[curr] = min(dp[curr], dp[x]);
		}
	}
	
	return;
}

void solve()
{
  	int n; cin >> n;
  	for(int i = 0; i < n - 1; i++) {
  		int x, y; cin >> x >> y;
  		g[x].pb(y);
  		g[y].pb(x);
  	}
  	
  	// simple dfs
  	dfs(1, 0);
  	
  	for(int i = 1; i <= n; i++) {
  		cout << "For subtree rooted at " << i << " ans = " << dp[i] << "\n";
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

/*

Sample i/p --->

10
1 2
1 4
2 8
8 6
8 10
6 9
4 3
4 5 
5 7

Sample o/p --->

For subtree rooted at 1 ans = 1
For subtree rooted at 2 ans = 2
For subtree rooted at 3 ans = 3
For subtree rooted at 4 ans = 3
For subtree rooted at 5 ans = 5
For subtree rooted at 6 ans = 6
For subtree rooted at 7 ans = 7
For subtree rooted at 8 ans = 6
For subtree rooted at 9 ans = 9
For subtree rooted at 10 ans = 10

*/