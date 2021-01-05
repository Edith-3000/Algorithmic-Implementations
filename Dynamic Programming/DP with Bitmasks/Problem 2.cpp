// Problem: E. Fish
// Contest: Codeforces - Codeforces Beta Round #16 (Div. 2 Only)
// URL: https://codeforces.com/problemset/problem/16/E
// Memory Limit: 128 MB
// Time Limit: 3000 ms
// Parsed on: 05-01-2021 21:48:54 IST (UTC+05:30)
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

double dp[(1 << 18)];
double p[18][18];
int n;

double p_move(int prev_mask, int fish) {
	int k = __builtin_popcount(prev_mask);
	double den = (k * (k - 1))/2;
	double num = 0;
	for(int i = 0; i < n; i++) {
		if(prev_mask & (1 << i)) {
			num += p[i][fish];
		}
	}
	
	return num/den;
}

double driver(int mask) {
	// base case
	int alive = __builtin_popcount(mask);
	if(alive == n) return 1;
	
	// check if already calculated or not
	if(dp[mask] > -0.9) return dp[mask];
	
	double res = 0;
	for(int fish = 0; fish < n; fish++) {
		if((mask & (1 << fish)) == 0) {
			double prev_day_res = driver(mask ^ (1 << fish));
			res += prev_day_res * p_move(mask ^ (1 << fish), fish);
		}
	}
	
	return dp[mask] = res;
}

void solve()
{
  	cin >> n;
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < n; j++) {
  			cin >> p[i][j];
  		}
  	}
  	
  	memset(dp, -1, sizeof(dp));
  	
  	for(int i = 0; i < n; i++) {
  		cout << fixed << setprecision(6) << driver(1 << i) << " ";
  	}
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

// Time Complexity: O(n^2 x 2^n)
// Space Complexity: O(n^2 + 2^n)
