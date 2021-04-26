// Problem: https://www.interviewbit.com/problems/dungeon-princess/
// Ref: https://www.youtube.com/watch?v=4uUGxZXoR5o
/******************************************************************************************************/

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

int min_energy(vvi &v) {
	int n = v.size();
	if(n == 0) return 0;
	int m = v[0].size();
	
	// abs(dp[i][j]) = (min amt of energy required - 1) by knight
	// to reach from (i, j) to princess(n-1, m-1)
	vvi dp(n, vi(m, 0));
	
	for(int i = n - 1; i >= 0; i--) {
		for(int j = m - 1; j >= 0; j--) {
			if(i == n - 1 and j == m - 1) dp[i][j] = min(0, v[i][j]);
			else if(i == n - 1) dp[i][j] = min(0, v[i][j] + dp[i][j+1]);
			else if(j == m - 1) dp[i][j] = min(0, v[i][j] + dp[i+1][j]);
			else dp[i][j] = min(0, v[i][j] + max(dp[i+1][j], dp[i][j+1]));
		}
	}
	
	return abs(dp[0][0]) + 1;
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vvi dungeon(n, vi(m));
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cin >> dungeon[i][j];
  	}
  	
  	cout << min_energy(dungeon) << "\n";
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