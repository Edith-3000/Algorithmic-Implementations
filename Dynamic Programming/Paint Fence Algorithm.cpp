/* Ref ---> https://www.geeksforgeeks.org/painting-fence-algorithm/
   Explanation ---> https://www.youtube.com/watch?v=ju8vrEAsa3Q

   Problem --->
   Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at 
   most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.
*/

// Method 1 (Bottom up DP)

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

ll paint_fence_algo(int n, int k) {
	// if only 1 fence then we have k choices
	if(n == 1) return k;
	
	// dp[i][0] = total #ways such that last two fences 
	//            (i.e. ith & (i-1)th) have same color.
	// dp[i][1] = total #ways such that last two fences 
	//            (i.e. ith & (i-1)th) have different color.
	ll dp[n+1][2];

	dp[2][0] = k;
	dp[2][1] = (k * (k - 1)) % mod;
	
	for(int i = 3; i <= n; i++) {
		dp[i][0] = dp[i-1][1];
		dp[i][1] = ((dp[i-1][1] + dp[i-1][0]) % mod) * ((k - 1) % mod);
	}
	
	return (dp[n][0] + dp[n][1]) % mod;	
}

void solve()
{
  	int n, k; 
  	cin >> n >> k;
  	
  	cout << paint_fence_algo(n, k);
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

// Time Complexity: O(n).
// Auxiliary Space: O(n).

/*******************************************************************************************************/

// Method 2 (SPACE OPTIMIZED IMPLEMENTATION OF THE ABOVE APPROACH)
// As current state of DP depends only on the previous state, space optimizations can be used.

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

ll paint_fence_algo(int n, int k) {
	if(n == 1) return k;
	
	ll same = k;
	ll diff = (k * (k - 1)) % mod;
	ll total = (same + diff) % mod;
	
	for(int i = 3; i <= n; i++) {
		same = diff;
		diff = (total * (k - 1)) % mod;
		total = (same + diff) % mod; 
	}
	
	return total;
}

void solve()
{
  	int n, k; 
  	cin >> n >> k;
  	
  	cout << paint_fence_algo(n, k);
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

// Time Complexity: O(n).
// Auxiliary Space: O(1).