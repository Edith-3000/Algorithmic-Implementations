// Problem: https://www.interviewbit.com/problems/tiling-with-dominoes/
// Ref: https://www.youtube.com/watch?v=yn2jnmlepY8
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
const ll mod = 1e9+7;

ll cnt_ways(int n) {
	if(n < 0) return 0;
	
	// there can be 8 possible states that a column can be in.
	// dp[i][j] = #ways of filling the board upto the jth column
	// such that the jth column has ith configuration out of the
	// 8 possible configurations it can be in.
	vvll dp(8, vll(n + 1, 0));
	dp[7][0] = 1;
	
	for(int j = 1; j <= n; j++) {
		dp[0][j] = (dp[0][j] + dp[7][j-1]) % mod;
		
		dp[1][j] = (dp[1][j] + dp[6][j-1]) % mod;
		
		dp[2][j] = (dp[2][j] + dp[5][j-1]) % mod;
		
		dp[3][j] = (dp[3][j] + dp[7][j-1]) % mod;
		dp[3][j] = (dp[3][j] + dp[4][j-1]) % mod;
		
		dp[4][j] = (dp[4][j] + dp[3][j-1]) % mod;
		
		dp[5][j] = (dp[5][j] + dp[2][j-1]) % mod;
		
		dp[6][j] = (dp[6][j] + dp[7][j-1]) % mod;
		dp[6][j] = (dp[6][j] + dp[1][j-1]) % mod;
		
		dp[7][j] = (dp[7][j] + dp[3][j-1]) % mod;
		dp[7][j] = (dp[7][j] + dp[6][j-1]) % mod;
		dp[7][j] = (dp[7][j] + dp[0][j-1]) % mod;
	}
	
	return dp[7][n];
}

void solve()
{
  	int n; cin >> n;
  	cout << cnt_ways(n) << "\n";
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