// Approach: https://www.youtube.com/watch?v=RuNAYVTn9qM&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=2
/***********************************************************************************************************/

// Problem: Tree Matching
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1130
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 05-02-2021 22:53:07 IST (UTC+05:30)
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

vi tree[200001];
int dp[200001][2];
int n;

void dfs(int curr, int par) {
	bool is_leaf = 1;
	dp[curr][0] = dp[curr][1] = 0;
	
	for(auto child: tree[curr]) {
		if(child != par) {
			is_leaf = 0;
			dfs(child, curr);
		}
	}
	
	if(is_leaf) return;
	vi prefix, suffix;
	
	for(auto child: tree[curr]) {
		if(child != par) {
			prefix.pb(max(dp[child][0], dp[child][1]));
			suffix.pb(max(dp[child][0], dp[child][1]));
		}
	}
	
	for(int i = 1; i < (int)prefix.size(); i++) {
		prefix[i] += prefix[i-1];
	}
	
	for(int i = (int)suffix.size() - 2; i >= 0; i--) {
		suffix[i] += suffix[i+1];
	}
	
	dp[curr][0] = suffix[0];
	
	int ch_no = 0;
	for(auto child: tree[curr]) {
		if(child == par) continue;
		
		int leftChildren = (ch_no == 0) ? 0 : prefix[ch_no - 1];
		int rightChildren = (ch_no == (int)suffix.size() - 1) ? 0 : suffix[ch_no + 1];
		
		dp[curr][1] = max(dp[curr][1], leftChildren + 1 + dp[child][0] + rightChildren);
		ch_no++;
	}
}

void solve()
{
  	cin >> n;
  	for(int i = 1; i < n; i++) {
  		int u, v; cin >> u >> v;
  		tree[u].pb(v);
  		tree[v].pb(u);
  	}
  	
  	dfs(1, 0);
  	cout << max(dp[1][0], dp[1][1]) << "\n";
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