// Problem: https://leetcode.com/contest/biweekly-contest-24/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
//		    https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/
/**********************************************************************************************************************************/

// METHOD - 1 (Using DP)
// CAUTION: This method will get TLE when n is very large

// The below algorithm is build on concept similar to "Minimum Number Of Coin Change".

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

void calc_fib(vll &v, ll n) {
	v.pb(1); v.pb(1);
	int i = 1;
	
	while(1) {
		ll x = v[i] + v[i-1];
		if(x <= n) v.pb(x), i++;
		else break;
	}
}

int find_ans(ll n) {
	vll v;
	calc_fib(v, n);
	
	vi dp(n + 1, 0);
	for(ll x = 1; x <= n; x++) {
		ll tmp = LLONG_MAX;
		for(int i = 0; i < (int)v.size(); i++) {
			if(x - v[i] >= 0) tmp = min(tmp, (ll)dp[x-v[i]]);
			else break;
		}
		
		dp[x] = tmp + 1;
	}
	
	return dp[n];
}

void solve()
{
  	ll n; cin >> n;
  	cout << find_ans(n) << "\n";
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

/******************************************************************************************************/

// METHOD - 2 (Greedy, but it works on Fibonacci numbers)
// With Fibonacci coin values Greedy approach works.
// Proof: See in the description of the video --->
//        https://www.youtube.com/watch?v=w3zD7kyJE8U
// Ref: https://www.geeksforgeeks.org/minimum-fibonacci-terms-sum-equal-k/

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

void calc_fib(vll &v, ll n) {
	v.pb(1); v.pb(1);
	int i = 1;
	
	while(1) {
		ll x = v[i] + v[i-1];
		if(x <= n) v.pb(x), i++;
		else break;
	}
}

int find_ans(ll n) {
	vll v;
	calc_fib(v, n);
	
	int i = v.size() - 1;
	int res = 0;
	
	// Subtract Fibonacci terms from sum n
    // until n > 0.
	while(n > 0) {
		// Division is repeated subtraction.
		res += (n / v[i]);
		n %= v[i];
		i--;
	}
	
	return res;
}

void solve()
{
  	ll n; cin >> n;
  	cout << find_ans(n) << "\n";
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