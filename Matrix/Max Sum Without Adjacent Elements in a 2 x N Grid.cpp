// Problem: https://www.geeksforgeeks.org/maximum-sum-2-x-n-grid-no-two-elements-adjacent/
/***************************************************************************************************/

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

ll find_ans(vvi &v) {
	int n = v.size();
	if(n == 0) return 0;
	
	n = v[0].size();
	
	// dp[i] = max sum that can be obtained by considering the first (i + 1) elements
	vll dp(n, 0);
	dp[0] = max(v[0][0], v[1][0]);
	
	for(int i = 1; i < n; i++) {
		ll op1 = max(v[0][i], v[1][i]) + ((i >= 2) ? dp[i-2] : 0);
		ll op2 = dp[i-1];
		dp[i] = max(op1, op2);
	}
	
	return dp[n-1];
}

void solve()
{
  	int n; cin >> n;
  	vvi v(2, vi(n));
  	
  	for(int i = 0; i < 2; i++) {
  		for(int j = 0; j < n; j++) cin >> v[i][j];
  	}
  	
  	cout << find_ans(v) << "\n";
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
// SC: O(n)

// NOTE: As for calculating the current state, only 2 previos states are required, we can maintain
//       2 variables for this, no need for an entire dp array. Thus getting O(1) space complexity.