// Problem: B. Orac and Models
// Contest: Codeforces - Codeforces Round #641 (Div. 2)
// URL: https://codeforces.com/contest/1350/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Parsed on: 27-01-2021 16:34:27 IST (UTC+05:30)
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
  	int n; cin >> n;
  	int a[n + 1], dp[n + 1];
  	
  	// dp[i] = max #models Orac can buy such that the
  	// last bought model is ith
  	
  	for(int i = 1; i <= n; i++) {
  		cin >> a[i];
  		dp[i] = 1;
  	}
  	
  	int res = 1;
  	for(int i = 2; i <= n; i++) {
  		int mx = 0;
  		for(int j = 1; (j * j) <= i; j++) {
  			if(i % j == 0) {
  				int d1 = j, d2 = i/j;
  				if(a[d1] < a[i]) mx = max(mx, dp[d1]);
  				if(a[d2] < a[i]) mx = max(mx, dp[d2]);
  			}
  		}
  		
  		dp[i] += mx;
  		res = max(res, dp[i]);
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}