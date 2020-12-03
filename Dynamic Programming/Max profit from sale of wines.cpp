// PROBLEM LINK: https://www.codechef.com/MALI2017/problems/MAXCOST

/*************************************************************************************************************/

// RECURSIVE (which ofcourse will give TLE)

// Problem: Everyone loves wine
// Contest: CodeChef - Machine Learning Internship
// URL: https://www.codechef.com/MALI2017/problems/MAXCOST
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 02-12-2020 09:33:19 IST (UTC+05:30)
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

ll recursive(ll i, ll j, ll y, vll &v){
	// base case
	if(i > j) return 0;
	
	ll c1 = (v[i] * y) + recursive(i+1, j, y+1, v);
	ll c2 = (v[j] * y) + recursive(i, j-1, y+1, v);
	
	return max(c1, c2);
}

void solve()
{
  	ll n; cin >> n;
  	vll v(n);
  	for(ll i = 0; i < n; i++) cin >> v[i];
  	
  	ll y = 1;
  	cout << recursive(0, n - 1, y, v);
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

// Time complexity: Exponential

/***********************************************************************************************************/

// TOP DOWN DP

// Problem: Everyone loves wine
// Contest: CodeChef - Machine Learning Internship
// URL: https://www.codechef.com/MALI2017/problems/MAXCOST
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 02-12-2020 09:33:19 IST (UTC+05:30)
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
vvll dp(2000, vll(2000, -1));

ll top_down(ll i, ll j, ll y, vll &v){
	// base case
	if(i > j) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	ll c1 = (v[i] * y) + top_down(i+1, j, y+1, v);
	ll c2 = (v[j] * y) + top_down(i, j-1, y+1, v);
	
	return dp[i][j] = max(c1, c2);
}

void solve()
{
  	ll n; cin >> n;
  	vll v(n);
  	for(ll i = 0; i < n; i++) cin >> v[i];
  	
  	ll y = 1;
  	cout << top_down(0, n - 1, y, v);
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

// Time Complexity: O(n2)
// NOTE: For finding out which indexed bottle to sell each time(i.e. to store the strategy) refer below link:
//       https://www.geeksforgeeks.org/maximum-profit-sale-wines/