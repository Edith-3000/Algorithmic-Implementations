// Problem: https://www.youtube.com/watch?v=_c_R-uIi-zU
// This problem is very much similar to --->
// https://www.geeksforgeeks.org/count-number-ways-tile-floor-size-n-x-m-using-1-x-m-size-tiles/
/*********************************************************************************************************/

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

ll cnt_ways(int n, int m) {
	if(n < 0) return 0;
	
	vll dp(m + 1, 0);
	dp[0] = 1;
	
	for(int i = 1; i <= m; i++) {
		if(i < n) dp[i] = 1;
		else dp[i] = (dp[i-1] + dp[i-n]) % mod;
	}
	
	return dp[m];
}

void solve()
{
  	int n, m; cin >> n >> m;
  	cout << cnt_ways(n, m) << "\n";
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

// TC: O(n)