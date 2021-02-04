// Method 1 

// Problem: Rectangle Cutting
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1744
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 04-02-2021 10:10:03 IST (UTC+05:30)
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

int dp[501][501];
int a, b;
 
int driver(int a, int b) {
	// base case
	if(a == b) return 0;
	
	int &res = dp[a][b];
	if(res != -1) return res;
	
	res = INF;
	// if all possible vertical cuts are made
	for(int i = 1; i <= (a - 1); i++) {
		res = min(res, 1 + driver(i, b) + driver(a - i, b));
	}
	
	// if all possible horizontal cuts are made
	for(int i = 1; i <= (b - 1); i++) {
		res = min(res, 1 + driver(a, i) + driver(a, b - i));
	}
	
	return res; 
}
 
void solve()
{
  	cin >> a >> b;
  	memset(dp, -1, sizeof dp);
  	cout << driver(a, b) << "\n";
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

// Time complexity: O(a x b x (a+b))

/************************************************************************************************************/

// Method 2

// Problem: Rectangle Cutting
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1744
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 04-02-2021 10:20:03 IST (UTC+05:30)
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

int dp[501][501];
int a, b;
 
int driver(int a, int b) {
	for(int length = 1; length <= a; length++) {
		for(int breadth = 1; breadth <= b; breadth++) {
			if(length == breadth) dp[length][breadth] = 0;
			else {
				int res = INF;
				// if all possible vertical cuts are made
				for(int i = 1; i <= (length - 1); i++) {
					res = min(res, 1 + dp[i][breadth] + dp[length-i][breadth]);
	            }
	            
	            // if all possible horizontal cuts are made
				for(int i = 1; i <= (breadth - 1); i++) {
					res = min(res, 1 + dp[length][i] + dp[length][breadth-i]);
	            }
	            
	            dp[length][breadth] = res;
			}
		}
	}
	
	return dp[a][b];
}
 
void solve()
{
  	cin >> a >> b;
  	cout << driver(a, b) << "\n";
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

// Time complexity: O(a x b x (a+b))