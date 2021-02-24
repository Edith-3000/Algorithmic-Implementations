// Explanation: https://www.youtube.com/watch?v=m7mlyZ_gc6s&list=PLk_DdB3uhk2DycnANP-kJE1BONUhhJMF6&index=1
/**********************************************************************************************************/

// Problem: E - Traveling Salesman among Aerial Cities
// Contest: AtCoder - AtCoder Beginner Contest 180
// URL: https://atcoder.jp/contests/abc180/tasks/abc180_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Parsed on: 24-02-2021 17:17:12 IST (UTC+05:30)
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

// dp[i][mask] = store the minimum cost if currently we are at city i
// and the current configuration of cities is stored in mask.
// jth city(bit) in mask is '1' if this city is not visited right now, 
// if it's not visited then it is set to 0. 
ll dp[17][1 << 17];
ll a[17][3];
int n;

ll dist(int src, int dst) {
	return abs(a[dst][0] - a[src][0]) + 
		   abs(a[dst][1] - a[src][1]) + 
		   max(0LL, a[dst][2] - a[src][2]);
}

ll driver(int cur_city, int mask) {
	// base case(s)
	if(mask == 0) return dist(cur_city, 0);
	
	// check if already calculated or not
	ll &res = dp[cur_city][mask];
	if(res != -1) return res;
	
	res = LLONG_MAX;
	for(int i = 0; i < n; i++) {
		if(mask & (1 << i)) {
			res = min(res, dist(cur_city, i) + driver(i, mask ^ (1 << i)));
		}
	}
	
	return res;
}

void solve()
{
  	memset(dp, -1, sizeof dp);
  	cin >> n;
  	for(int i = 0; i < n; i++) {
  		cin >> a[i][0] >> a[i][1] >> a[i][2];
  	}
  	
  	cout << driver(0, (1 << n) - 2) << "\n";
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