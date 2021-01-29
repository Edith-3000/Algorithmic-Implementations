// Explanation link: https://www.youtube.com/watch?v=IgBLv32QFoQ&list=PLb3g_Z8nEv1i26KO3g9Hw-taqgIejXH49&index=6
/***************************************************************************************************************/

// Whenever you are asked to find the best subarray or subsequence & the problem involves DP, then you should
// define your DP in such a way that dp[i] store the best subarray or subsequence that ends at the iᵗʰ element.

/**************************************************************************************************************/

// Problem: D. Beautiful Array
// Contest: Codeforces - Educational Codeforces Round 63 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1155/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 29-01-2021 08:46:41 IST (UTC+05:30)
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

void solve()
{
  	ll n, x; cin >> n >> x;
  	vll v(n);
  	for(ll i = 0 ; i < n; i++) cin >> v[i];
  	
  	// dp[][][] = what is the best possible subaaray ending
  	// at ith position(state 1) such that 'x' is usable(multipliable)
  	// or not usable(state 2) & if usable, then whether we are using
  	// it or not (state 3)
  	ll dp[n][2][2];
  	memset(dp, 0, sizeof dp);
  	dp[0][1][0] = v[0];
  	dp[0][1][1] = x * v[0];
  	
  	ll res = max(0LL, max(dp[0][1][0], dp[0][1][1]));
  	for(ll i = 1; i < n; i++) {
  		// Case 1 (in this the 3rd state is just a dummy variable)
  		dp[i][0][0] = max(v[i], v[i] + max(dp[i-1][0][0], dp[i-1][1][1]));
  		
  		// Case 2
  		dp[i][1][0] = max(v[i], v[i] + dp[i-1][1][0]);
  		
  		// Case 3
  		dp[i][1][1] = max(x * v[i], x * v[i] + max(dp[i-1][1][0], dp[i-1][1][1]));
  		
  		res = max(res, max(dp[i][0][0], max(dp[i][1][0], dp[i][1][1])));
  	}
  	
  	cout << res << "\n";
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