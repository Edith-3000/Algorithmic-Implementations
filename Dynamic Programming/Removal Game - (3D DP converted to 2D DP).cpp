// 3D DP Approach

// Problem: Removal Game
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1097
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 06-01-2021 21:29:20 IST (UTC+05:30)
// Author: kapil_choudhary

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

ll dp[2][5000][5000];
ll n;
vll v;

ll driver(ll turn, ll l, ll r) {
	// base case(s);
	if(l == r) {
		if(turn) return v[l];
		else return 0;
	}
	
	// check if already calculated or not
	ll &res = dp[turn][l][r];
	if(res != -1) return res;
	
	res = 0;
	if(turn) res = max(v[l] + driver(0, l + 1, r), v[r] + driver(0, l, r - 1));
	else res = min(driver(1, l + 1, r), driver(1, l, r - 1));
	
	return dp[turn][l][r] = res;
}

void solve()
{
  	memset(dp, -1, sizeof(dp));
  	cin >> n;
  	v.resize(n);
  	for(ll i = 0; i < n; i++) cin >> v[i];
  	
  	cout << driver(1, 0, n - 1);
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

/**************************************************************************************************************/

// 2D DP Approach

// Problem: Removal Game
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1097
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 06-01-2021 21:29:20 IST (UTC+05:30)
// Author: kapil_choudhary

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

ll dp[5000][5000];
ll n;
vll v;

ll driver() {
	for(ll len = 1; len <= n; len++) {
		for(ll i = 0; i + len - 1 < n; i++) {
			if(len == 1) {
				ll t = n - len;
				if(t % 2 == 0) dp[i][i] = v[i];
		    }
		    
		    else {
		    	ll t = n - len;
		    	ll l = i, r = i + len - 1;
		    	if(t % 2 == 0) dp[l][r] = max(v[l] + dp[l + 1][r], v[r] + dp[l][r - 1]);
		    	else dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
		    }
		}
	}
	
	// final result
	return dp[0][n - 1];
}

void solve()
{
  	cin >> n;
  	v.resize(n);
  	for(ll i = 0; i < n; i++) cin >> v[i];
  	
  	cout << driver();
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