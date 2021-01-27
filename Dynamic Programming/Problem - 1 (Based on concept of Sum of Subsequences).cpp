// Problem: E. Let's Go Rolling!
// Contest: Codeforces - School Personal Contest #1 (Winter Computer School 2010/11) - Codeforces Beta Round #38 (ACM-ICPC Rules)
// URL: https://codeforces.com/problemset/problem/38/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 27-01-2021 15:03:01 IST (UTC+05:30)
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

// const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const ll INF = 1e18;

ll dp[3001][3001];
pii a[3001];
int n;

ll driver(int pos, int prev) {
	// base case
	if(pos > n) return 0;
	
	// check if already calculated
	if(dp[pos][prev] != -INF) return dp[pos][prev];
	
	// Choice 1
	ll choice1 = a[pos].S + driver(pos + 1, pos);
	
	// Choice 2
	ll choice2 = abs(a[pos].F - a[prev].F) + driver(pos + 1, prev);
	
	return dp[pos][prev] = min(choice1, choice2);
}

void solve()
{
  	cin >> n;
  	for(int i = 1; i <= n; i++) cin >> a[i].F >> a[i].S;
  	
  	sort(a + 1, a + n + 1);
  	for(ll i = 0; i <= n; i++) {
  		for(ll j = 0; j <= n; j++) dp[i][j] = -INF;
  	}
  	
  	cout << a[1].S + driver(2, 1) << "\n";
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