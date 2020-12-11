// Problem Link: https://hack.codingblocks.com/app/contests/1043/546/problem

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

const int mod = 1e9+7;

ll bottom_up(ll n, ll x, ll y, ll z){
	vll dp(n+1);
	dp[0] = dp[1] = 0;
	
	for(ll i = 2; i <= n; i++){
		if(i & 1){
			dp[i] = min(dp[i-1] + y, dp[(i+1)/2] + x + z);
		}
		
		else dp[i] = min(dp[i-1] + y, dp[i/2] + x);
	}
	
	return dp[n];
}

void solve()
{
  	ll n; cin >> n;
  	ll x, y, z; cin >> x >> y >> z;
  	
  	cout << bottom_up(n, x, y, z);
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