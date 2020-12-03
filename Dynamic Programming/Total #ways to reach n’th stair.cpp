// PROBLEM STATEMENT: There are n stairs, a person standing at the bottom wants to reach the top. 
//                    The person can climb 1 stair or 2 stairs or 3 stairs at a time. 
//                    Count the total number of ways, the person can reach the top.

/*************************************************************************************************************/

// RECURSIVE IMPLEMENTATION

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

int recursive(int n, vi &v){
	// base case
	if(n == 0) return 1;
	
	int res = 0;
	for(int i = 0; i < v.size(); i++){
		if((n-v[i]) >= 0) res += recursive(n - v[i], v);
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v{1, 2, 3};
  	
  	cout << recursive(n, v);
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

// Time Complexity: Exponential

/************************************************************************************************************/

// BOTTOM UP IMPLEMENTATION

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

int bottom_up(ll n, vll &v){
	vll dp(n+1, 0);
	dp[0] = 1;
	
	for(ll i = 1; i <= n; i++){
		ll ans = 0;
		for(ll k = 0; k < v.size(); k++){
			if((i - v[k]) >= 0) ans += dp[i - v[k]];
		}
		
		dp[i] = ans;
	}
	
	return dp[n];
}

void solve()
{
  	ll n; cin >> n;
  	vll v{1, 2, 3};
  	
  	cout << bottom_up(n, v);
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

// Time Complexity: O(n x k), where k = v.size() [ #posiible steps which can be taken ].

/***********************************************************************************************************/

// BOTTOM UP OPMIMISED IMPLEMENTATION (The third method uses the technique of Sliding Window to arrive 
//                                     at the solution.)

// Note ----> This method will work only if the steps which can be taken are contiguos from 1 onwards,
//            eg. 1, 2, 3, 4, 5, .... 

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

int bottom_up_optimised(ll n, vll &v){
	vll dp(n+1, 0);
	dp[0] = dp[1] = 1;
	ll k = v.size();
	
	for(ll i = 2; i <= n; i++){
		if((i-1-k) < 0) dp[i] = (2*dp[i-1]);
		else dp[i] = (2*dp[i-1]) - dp[i-1-k];
	}
	
	return dp[n];
}

void solve()
{
  	ll n; cin >> n;
  	vll v{1, 2, 3};
  	
  	cout << bottom_up_optimised(n, v);
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

// Time Complexity: O(n)