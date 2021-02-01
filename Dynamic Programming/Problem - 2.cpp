// Problem: C. Longest Simple Cycle
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1476/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 31-01-2021 15:24:38 IST (UTC+05:30)
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
  	ll n; cin >> n;
  	ll c[n+1], a[n+1], b[n+1];
  	for(ll i = 1; i <= n; i++) cin >> c[i];
  	for(ll i = 1; i <= n; i++) cin >> a[i];
  	for(ll i = 1; i <= n; i++) cin >> b[i];
  	
  	ll dp[n+1], sum[n+1];
  	dp[1] = 0;
  	sum[1] = abs(a[2] - b[2]);
  	
  	dp[2] = c[2] - 1 + 2 + sum[1];
  	if(n >= 3) {
  		ll x = min(a[3], b[3]);
  		ll y = max(a[3], b[3]);
  		if(x == y) sum[2] = 0;
  		else sum[2] = max(y - x, c[2] - y + x - 1 + 2 + sum[1]);
  	}
  	
  	for(ll i = 3; i <= n; i++) {
  		ll x = min(a[i], b[i]);
  		ll y = max(a[i], b[i]);
  		if(x == y) dp[i] = c[i] - 1 + 2;
  		else {
  			dp[i] = max(c[i] - 1 + 2 + y - x, 
  			            c[i] - 1 + 2 + c[i-1] - y + x - 1 + 2 + sum[i-2]);			
  		}
  		
  		if(i < n) {
  			ll m = min(a[i+1], b[i+1]);
  			ll n = max(a[i+1], b[i+1]);
  			if(m == n) sum[i] = 0;
  			else sum[i] = max(n - m, c[i] - n + m - 1 + 2 + sum[i-1]);
  		}
  	}  	 
  	
  	cout << *max_element(dp + 1, dp + n + 1) << "\n";
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