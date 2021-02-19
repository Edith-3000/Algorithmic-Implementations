// Concept link: --->
// https://www.geeksforgeeks.org/maximum-sum-possible-by-assigning-alternate-positive-and-negative-sign-to-elements-in-a-subsequence/
/**************************************************************************************************************************************/

// Problem: C1. Pokémon Army (easy version)
// Contest: Codeforces - Codeforces Round #672 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1420/C1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 18-02-2021 09:25:34 IST (UTC+05:30)
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

ll dp[300000][2];
int a[300000];
int n, q;

ll find_max(int i, int flag) {
	// base case(s)
	if(i >= n) return 0;
	
	// check if already calculated or not
	ll &res = dp[i][flag];
	if(res != -1) return res;
	
	if(flag == 0) res = max(find_max(i + 1, 0), -a[i] + find_max(i + 1, 1));
	else res = max(find_max(i + 1, 1), a[i] + find_max(i + 1, 0));
	
	return res;
}

void solve()
{
  	memset(dp, -1, sizeof dp);
  	cin >> n >> q;
  	for(int i = 0; i < n; i++) cin >> a[i];
  	
  	cout << find_max(0, 1) << "\n";
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

// Time Complexity: O(n)
// Auxiliary Space: O(n)