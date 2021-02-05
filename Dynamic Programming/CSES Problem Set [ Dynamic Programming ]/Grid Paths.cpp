// METHOD 1

// Problem: Grid Paths
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1638
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 03-02-2021 00:23:44 IST (UTC+05:30)
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

int dp[1000][1000];
char a[1000][1000];
int n;

bool is_valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int driver(int i, int j) {
	// base case(s)
	if(a[i][j] == '*') return 0;
	if(i == n - 1 and j == n - 1) {
		return a[i][j] == '.' ? 1 : 0;
	}
	
	int &res = dp[i][j];
	if(res != -1) return res;
	
	res = 0;
	int x1 = i + 1, y1 = j;
	if(is_valid(x1, y1) and a[x1][y1] == '.') res = (res % mod + driver(x1, y1) % mod) % mod;
	
	int x2 = i, y2 = j + 1;
	if(is_valid(x2, y2) and a[x2][y2] == '.') res = (res % mod + driver(x2, y2) % mod) % mod;
	
	return res;
}

void solve()
{
  	cin >> n;
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < n; j++) cin >> a[i][j];
  	}
  	
  	memset(dp, -1, sizeof dp);
  	cout << driver(0, 0);
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

/***********************************************************************************************************/

// METHOD 2

// Problem: Grid Paths
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1638
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 03-02-2021 07:54:25 IST (UTC+05:30)
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
  	char a[n][n];
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < n; j++) cin >> a[i][j];
  	}
  	
  	int dp[n][n];
  	for(int i = n - 1; i >= 0; i--) {
  		for(int j = n - 1; j >= 0; j--) {
  			if(i == n - 1 and j == n - 1) {
  				dp[i][j] = (a[i][j] == '.') ? 1 : 0;
  			}
  			
  			else {
  				int op1 = (i + 1 == n) ? 0 : dp[i+1][j] % mod;
  				int op2 = (j + 1 == n) ? 0 : dp[i][j+1] % mod;
  				dp[i][j] = (op1 + op2) % mod;
  				if(a[i][j] == '*') dp[i][j] = 0;
  			}
  		}
  	}
  	
  	cout << dp[0][0] << "\n";
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