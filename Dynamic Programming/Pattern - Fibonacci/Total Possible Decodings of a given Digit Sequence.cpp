// Problem: https://www.interviewbit.com/problems/ways-to-decode/
// Ref: https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/
/*****************************************************************************************************/

// METHOD - 1 (Recursion)

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
const ll mod = 1e9+7;

ll helper(int n, string &s) {
	if(n == 0 or n == 1) {
		return 1LL;
	}
	
	if(s[0] == '0') return 0LL;
	
	ll res = 0LL;
	if(s[n-1] != '0') res = (res + helper(n - 1, s)) % mod;
	if(n - 2 >= 0) {
		int num = s[n-2] - '0';
		num = (num * 10) + (s[n-1] - '0');
		if(num >= 10 and num <= 26) res = (res + helper(n - 2, s)) % mod;
	}
	
	return res;
}

ll decode_ways(string &s) {
	int n = (int)s.size();
	if(n == 0 or (n == 1 and s[0] == '0')) return 0LL;
	
	return helper(n, s);
} 

void solve()
{
  	string s; cin >> s;
  	cout << decode_ways(s) << "\n";
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

// TC: Exponential

/********************************************************************************************************/

// METHOD - 2 (Bottom Up DP)

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
const ll mod = 1e9+7;

ll helper(int n, string &s) {
	if(s[0] == '0') return 0LL;
	
	vll dp(n + 1, 0);
	dp[0] = dp[1] = 1LL;
	
	for(int i = 2; i <= n; i++) {
		if(s[i-1] > '0') dp[i] = (dp[i] + dp[i-1]) % mod;
		if(i - 2 >= 0) {
			int num = s[i-2] - '0';
			num = (num * 10) + (s[i-1] - '0');
			if(num >= 10 and num <= 26) dp[i] = (dp[i] + dp[i-2]) % mod;
		}
	}
	
	return dp[n];
}

ll decode_ways(string &s) {
	int n = (int)s.size();
	if(n == 0 or (n == 1 and s[0] == '0')) return 0LL;
	
	return helper(n, s);
} 

void solve()
{
  	string s; cin >> s;
  	cout << decode_ways(s) << "\n";
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

// TC: O(n)
// SC: O(n)

/**************************************************************************************************/

// METHOD - 3 (Space Optimized Top Down DP)

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
const ll mod = 1e9+7;

ll helper(int n, string &s) {
	if(s[0] == '0') return 0LL;
	if(n == 1) return 1LL;
	
	ll fst = 1LL, sec = 1LL;
	ll cur;
	
	for(int i = 2; i <= n; i++) {
		cur = 0LL;
		if(s[i-1] > '0') cur = (cur + fst) % mod;
		if(i - 2 >= 0) {
			int num = s[i-2] - '0';
			num = (num * 10) + (s[i-1] - '0');
			if(num >= 10 and num <= 26) cur = (cur + sec) % mod;
		}
		
		sec = fst;
		fst = cur;
	}
	
	return cur;
}

ll decode_ways(string &s) {
	int n = (int)s.size();
	if(n == 0 or (n == 1 and s[0] == '0')) return 0LL;
	
	return helper(n, s);
} 

void solve()
{
  	string s; cin >> s;
  	cout << decode_ways(s) << "\n";
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

// TC: O(n)
// SC: O(1)