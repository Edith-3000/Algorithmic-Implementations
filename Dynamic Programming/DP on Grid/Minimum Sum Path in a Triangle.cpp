// Problem: https://www.interviewbit.com/problems/min-sum-path-in-triangle/
// Ref: https://www.geeksforgeeks.org/minimum-sum-path-triangle/
//      https://www.youtube.com/watch?v=ZkJNX2Sa4dE
/********************************************************************************************************/

// METHOD - 1 (Bottom Up DP)

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

int mcp(vvi &v) {
	int n = v.size();
	if(n == 0) return 0;
	
	vvi dp(n);
	for(int i = 0; i < n; i++) {
		dp[i].resize(v[i].size());
	}
	
	dp[0][0] = v[0][0];
	
	for(int i = 1; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			int op1 = (j < i) ? dp[i-1][j] : INT_MAX;
			int op2 = ((j > 0) ? dp[i-1][j-1] : INT_MAX);
			dp[i][j] = v[i][j] + min(op1, op2);
		}
	}
	
	int res = INT_MAX;
	for(int j = 0; j < n; j++) res = min(res, dp[n-1][j]);
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vvi v(n);
  	for(int i = 0; i < n; i++) {
  		int sz; cin >> sz;
  		v[i].resize(sz);
  		for(int j = 0; j < sz; j++) cin >> v[i][j];
  	}
  	
  	cout << mcp(v) << "\n";
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

// TC: O(n x n)
// SC: O(n x n)

/******************************************************************************************************/

// METHOD - 2 (Space Optimized Bottom Up DP)
/* # This method is just a slight variation of "METHOD - 1". Instead of using a 2D DP, a 1D DP vector
     has been used in it.
   # DP transition ===>
     dp[i][j] = v[i][j] = min(dp[i-1][j], dp[i-1][j-1])
   # As we know by the DP transitions, result of current row depends only on the previous row, so a single 
     1D vector DP can be maintained throughtout.
*/

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

int mcp(vvi &v) {
	int n = v.size();
	if(n == 0) return 0;
	
	vi dp(n, 0);
	dp[0] = v[0][0];
	
	for(int i = 1; i < n; i++) {
		for(int j = i; j >= 0; j--) {
			if(j == i) dp[j] = v[i][j] + dp[j-1];
			else if(j == 0) dp[j] = v[i][j] + dp[j];
			else dp[j] = v[i][j] + min(dp[j], dp[j-1]);
		}
	}
	
	int res = INT_MAX;
	for(int j = 0; j < n; j++) res = min(res, dp[j]);
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vvi v(n);
  	for(int i = 0; i < n; i++) {
  		int sz; cin >> sz;
  		v[i].resize(sz);
  		for(int j = 0; j < sz; j++) cin >> v[i][j];
  	}
  	
  	cout << mcp(v) << "\n";
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

// TC: O(n x n)
// SC: O(n)