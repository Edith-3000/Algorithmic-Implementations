// PROBLEM STATEMENT: https://www.spoj.com/problems/MST1/

/*************************************************************************************************************/

// RECURSIVE 

// Problem: Minimum Step To One
// Contest: SPOJ - Tutorial
// URL: https://www.spoj.com/problems/MST1/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// Parsed on: 01-12-2020 18:57:50 IST (UTC+05:30)
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

ll recursive(ll n){
	// base case
	if(n == 1) return 0;
	
	ll res = recursive(n - 1);
	if(n%2 == 0) res = min(res, recursive(n/2));
	if(n%3 == 0) res = min(res, recursive(n/3));
	
	return 1 + res;
}

void solve()
{
  	ll n; cin >> n;
  	cout << recursive(n);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

// Time complexity: Exponential

/***********************************************************************************************************/

// BOTTOM UP DP

// Problem: Minimum Step To One
// Contest: SPOJ - Tutorial
// URL: https://www.spoj.com/problems/MST1/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// Parsed on: 01-12-2020 18:57:50 IST (UTC+05:30)
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
vi dp(20000001, 0);

void bottom_up(){
	// base case
	dp[1] = 0;
	
	for(int i = 2; i <= (20000000); i++){
		int res = dp[i-1];
		if(i % 2 == 0) res = min(res, dp[i/2]);
		if(i % 3 == 0) res = min(res, dp[i/3]);
		
		dp[i] = 1 + res;
	}
}

void solve()
{
  	int n; cin >> n;
  	cout << dp[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	
	bottom_up();
    int t = 1;
    cin >> t;
    for(int test = 1; test <= t; test++){
      cout << "Case " << test << ": ";
      solve();
    }

    return 0;
}

// Time complexity: O(n)