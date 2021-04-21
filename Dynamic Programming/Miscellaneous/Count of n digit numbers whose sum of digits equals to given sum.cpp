// Problem: https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/
// Ref: https://www.geeksforgeeks.org/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum/
/******************************************************************************************************/

// METHOD - 1.1 (Exponential Approach)

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

ll helper(int i, ll num, int sum, int len, int s) {
	// base case
	if(i > len) {
		if(sum == s) return 1;
		return 0;
	}
	
	ll res = 0;
	for(int d = 0; d <= 9; d++) {
		if(i == 1 and d == 0) continue;
		res += helper(i + 1, num * 10 + d, sum + d, len, s);
	}
	
	return res; 
}

void solve()
{
  	int n, s; cin >> n >> s;
  	cout << helper(1, 0, 0, n, s) << "\n";
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

/*****************************************************************************************************/

// METHOD - 1.2 (Exponential Approach)

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

// Recursive function to count 'n' digit numbers with sum of digits as 'sum'. 
// This function considers leading 0's also as digits, that is why not directly called
ll helper(int len, int s) {
	// base case(s)
	if(len == 0) return s == 0;
	if(s == 0) return 1;
	
	// To store the result
	ll ans = 0;
	
	// Traverse through every digit and count numbers beginning with it using recursion
	for(int d = 0; d <= 9; d++) {
		if(s - d >= 0) ans += helper(len - 1, s - d);
	}
	
	return ans;
}

// This is mainly a wrapper over helper(). It explicitly handles leading digit and 
// calls helper() for remaining digits.
ll find_ans(int len, int s) {
	// To store the final result
	ll res = 0;
	
	// Traverse through every digit from 1 to 9 and count numbers beginning with it
	for(int d = 1; d <= 9; d++) {
		if(s - d >= 0) res += helper(len - 1, s - d);
	}
	
	return res;
}

void solve()
{
  	int n, s; cin >> n >> s;
  	cout << find_ans(n, s) << "\n";
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

/*****************************************************************************************************/

// METHOD - 2 (Top Down DP Approach)

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

// Memoized function to count 'n' digit numbers with sum of digits as 'sum'. 
// This function considers leading 0's also as digits, that is why not directly called
ll helper(int len, int s, ll dp[][1001]) {
	// base case(s)
	if(len == 0) return s == 0;
	if(s == 0) return 1;
	
	if(dp[len][s] != -1) return dp[len][s];
	
	// To store the result
	ll ans = 0;
	
	// Traverse through every digit and count numbers beginning with it using recursion
	for(int d = 0; d <= 9; d++) {
		if(s - d >= 0) ans = (ans + helper(len - 1, s - d, dp)) % mod;
	}
	
	return dp[len][s] = ans;
}

// This is mainly a wrapper over helper(). It explicitly handles leading digit and 
// calls helper() for remaining digits.
ll find_ans(int len, int s) {
	// for caching the intermediate results
	ll dp[1001][1001];
	memset(dp, -1, sizeof dp);
	
	// To store the final result
	ll res = 0;
	
	// Traverse through every digit from 1 to 9 and count numbers beginning with it
	for(int d = 1; d <= 9; d++) {
		if(s - d >= 0) res = (res + helper(len - 1, s - d, dp)) % mod;
	}
	
	return res;
}

void solve()
{
  	int n, s; cin >> n >> s;
  	cout << find_ans(n, s) << "\n";
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

// Time Complexity: O(n x s)
// Auxiliary Space: O(n x s)