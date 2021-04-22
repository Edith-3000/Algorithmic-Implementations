// Problem: https://www.interviewbit.com/problems/unique-paths-in-a-grid/
/********************************************************************************************************/

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

int mcp(int i, int j, int n, int m, vvi &v, vvi &dp) {
    if(i == (n - 1) and j == (m - 1)) return v[i][j];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int res = INF;
    if(i + 1 < n) res = min(res, v[i][j] + mcp(i+1, j, n, m, v, dp));
    if(j + 1 < m) res = min(res, v[i][j] + mcp(i, j+1, n, m, v, dp));
    
    return dp[i][j] = res;
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vvi v(n, vi(m));
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cin >> v[i][j];
  	}
  	
  	vvi dp(n, vi(m, -1));
  	cout << mcp(0, 0, n, m, v, dp) << "\n";
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

// TC: O(n x m)
// SC: O(n x m)