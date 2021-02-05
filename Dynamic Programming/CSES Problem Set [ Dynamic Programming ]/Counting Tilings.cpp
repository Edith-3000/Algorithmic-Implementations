// Time complexity analysis and approach can br found here --->
// https://www.youtube.com/watch?v=lPLhmuWMRag&list=PLb3g_Z8nEv1icFNrtZqByO1CrWVHLlO5g&index=7
/*******************************************************************************************************/

// Problem: Counting Tilings
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2181
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 05-02-2021 15:53:28 IST (UTC+05:30)
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

// dp[i][mask] = #ways of filling the tiles from ith col. to mth (last)
// col. such that such that some positions in the ith col. are already
// filled (due to placement of tiles by the (i-1)th col).
// Filled pos = 1 and empty pos = 0 in the mask
// Final result will be stored in: dp[1][0]
int dp[1001][1 << 10];
int n, m;

void generate_next_masks(int cur_mask, int pos, int next_mask, vi &next_masks) {
	// base case
	if(pos == n) {
		next_masks.pb(next_mask);
		return;
	}
	
	if((cur_mask & (1 << pos)) != 0) 
		generate_next_masks(cur_mask, pos + 1, next_mask, next_masks);
		
	if((cur_mask & (1 << pos)) == 0) 
		generate_next_masks(cur_mask, pos + 1, next_mask + (1 << pos), next_masks);
		
	if(pos + 1 <= n - 1) {
		if((cur_mask & (1 << pos)) == 0 and (cur_mask & (1 << (pos + 1))) == 0)
			generate_next_masks(cur_mask, pos + 2, next_mask, next_masks);
	}
}

int driver(int i, int mask) {
	// base case(s)
	if(i == m + 1) {
		return (mask == 0) ? 1 : 0;
	}
	
	// check if already calculated or not
	if(dp[i][mask] != -1) return dp[i][mask];
	
	int res = 0;
	vi next_masks;
	generate_next_masks(mask, 0, 0, next_masks);
	
	for(auto next_mask: next_masks) {
		res = (res + driver(i + 1, next_mask)) % mod;
	}
	
	return dp[i][mask] = res;
}

void solve()
{
  	cin >> n >> m;
  	memset(dp, -1, sizeof dp);
  	cout << driver(1, 0) << "\n";
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

// A very slightly modified code with dp[1001][1 << 11] can be found here --->
// https://cses.fi/paste/552e141d0426523d195397/