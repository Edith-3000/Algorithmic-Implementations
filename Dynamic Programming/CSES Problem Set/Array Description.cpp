// Problem: Array Description
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1746
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 03-02-2021 14:44:51 IST (UTC+05:30)
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
  	int n, m; cin >> n >> m;
  	vi v(n + 1);
  	for(int i = 1; i <= n; i++) cin >> v[i];
  	
  	// dp[i][x] store the #valid arrays consisting of
  	// first 'i' elements and ending with 'x' 
  	int dp[n+1][m+2] = {0};
  	
  	for(int i = 1; i <= n; i++) {
  		for(int x = 1; x <= m; x++) {
  			if(i == 1) {
  				if(v[i] == 0 || x == v[i]) dp[i][x] = 1;
  				else dp[i][x] = 0;
  			}
  			
  			else {
  				if(v[i] == 0 || v[i] == x) {
  					dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x]) % mod + dp[i-1][x+1]) % mod;
  				}
  				
  				else dp[i][x] = 0;
  			}
  		}
  	}
  	
  	int res = 0;
  	for(int x = 1; x <= m; x++) {
  		res = (res + dp[n][x]) % mod;
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