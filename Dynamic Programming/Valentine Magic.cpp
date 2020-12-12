// Problem link ----> https://hack.codingblocks.com/app/contests/1209/281/problem

// Top Down DP Method

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
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

// #define INF 10000000000099ll
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
ll dp[5005][5005];
ll b[5005], g[5005];
ll n, m;

ll top_down(ll i, ll j){
	// base cases
	if(i == n) return 0; // case when we've processed all boys
	if(j == m) return INF; // case when all boys not processed 
	                       // but girls finished
	                       
	// check if already calculated or not
	if(dp[i][j] != -1) return dp[i][j];
	
	// option 1 - pair the ith boy with jth girl
	ll op1 = abs(b[i] - g[j]) + top_down(i+1, j+1);
	// option 2 - do not pair the ith boy with jth girl
	//            instead try pairing him with leftover girls
	ll op2 = top_down(i, j+1);
	
	// return the final result
	return dp[i][j] = min(op1, op2);
}

void solve()
{
  	cin >> n >> m;
  	for(ll i = 0; i < n; i++) cin >> b[i];
  	for(ll j = 0; j < m; j++) cin >> g[j];
  	
  	sort(b, b+n);
  	sort(g, g+m);
  	memset(dp, -1, sizeof(dp));
  	cout << top_down(0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}