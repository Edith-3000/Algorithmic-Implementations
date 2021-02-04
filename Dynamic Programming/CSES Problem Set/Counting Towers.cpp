// Below is the method -- which was correct but gave TLE on the test #4
// https://cses.fi/file/ffea5f55aa11ddea39c2b670e867f3ede42681402d490390ea365e8c60876c7a/1/1/

// Problem: Counting Towers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2413
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 04-02-2021 17:52:47 IST (UTC+05:30)
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
 
/* Explanation ==>
   * dp[i][0] = #ways of filling the tiles from pos 'i' to pos 'n', if 
   			    tiles at the previous (i-1)th pos were not linked
   			  
   * dp[i][1] = #ways of filling the tiles from pos 'i' to pos 'n', if 
   			    tiles at the previous (i-1)th pos were linked
   			    
   * for the case dp[i][0] ==>
     Possibility 1: if we don't extend the tiles from previous (i-1)th pos: #ways = dp[i+1][0] + dp[i+1][1]
     Possibility 2: if we extend the tiles from previous (i-1)th pos:
                    Here there are 3 choices available as follows --->
                    Choice 1: when both prev tiles are extended: #ways = dp[i+1][0]
                    Choice 2: when left prev tile is extended while right one not: #ways = dp[i+1][0]
                    Choice 3: when right prev tile is extended while left one not: #ways = dp[i+1][0]
   
   * for the case dp[i][1] ==>
     Possibility 1: if we don't extend the single tile from previous (i-1)th pos: #ways = dp[i+1][0] + dp[i+1][1]
     Possibility 2: if we extend the single tile from previous (i-1)th pos: #ways = dp[i+1][1]
     
   # Base cases are: dp[n+1][0] = dp[n+1][1] = 1
     As the #ways of filling the tiles from pos (n+1)th pos (n)th pos, if the tiles at the previous pos were 
     linked or not linked = 1 (it's simple, just don't fill the tiles as we are out of available positions 
     which were upto n)
     
   # Final result will be given by: dp[2][0] + dp[2][1]
*/
 
void solve()
{
  	int n; cin >> n;
  	ll dp[n+2][2];
  	dp[n+1][0] = dp[n+1][1] = 1;
  	
  	for(int i = n; i >= 2; i--) {
  		ll op1 = (dp[i+1][0] + dp[i+1][1]) % mod;
  		ll op2 = dp[i+1][0];
  		ll op3 = (2 * dp[i+1][0]) % mod;
  		ll op4 = dp[i+1][1];
  		
  		dp[i][0] = ((op1 + op2) % mod + op3) % mod;
  		dp[i][1] = (op1 + op4) % mod;
  	}
  	
  	cout << (dp[2][0] + dp[2][1]) % mod << "\n";
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

/**********************************************************************************************************/

// Therefore to avoid TLE I cached the result of a particular test case in an is_calc[] array, which
// got an "AC" [all the other things are same as above method which was giving TLE]

// Problem: Counting Towers
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2413
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 04-02-2021 17:52:47 IST (UTC+05:30)
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
 
/* Explanation ==>
   * dp[i][0] = #ways of filling the tiles from pos 'i' to pos 'n', if 
   			    tiles at the previous (i-1)th pos were not linked
   			  
   * dp[i][1] = #ways of filling the tiles from pos 'i' to pos 'n', if 
   			    tiles at the previous (i-1)th pos were linked
   			    
   * for the case dp[i][0] ==>
     Possibility 1: if we don't extend the tiles from previous (i-1)th pos: #ways = dp[i+1][0] + dp[i+1][1]
     Possibility 2: if we extend the tiles from previous (i-1)th pos:
                    Here there are 3 choices available as follows --->
                    Choice 1: when both prev tiles are extended: #ways = dp[i+1][0]
                    Choice 2: when left prev tile is extended while right one not: #ways = dp[i+1][0]
                    Choice 3: when right prev tile is extended while left one not: #ways = dp[i+1][0]
   
   * for the case dp[i][1] ==>
     Possibility 1: if we don't extend the single tile from previous (i-1)th pos: #ways = dp[i+1][0] + dp[i+1][1]
     Possibility 2: if we extend the single tile from previous (i-1)th pos: #ways = dp[i+1][1]
     
   # Base cases are: dp[n+1][0] = dp[n+1][1] = 1
     As the #ways of filling the tiles from pos (n+1)th pos (n)th pos, if the tiles at the previous pos were 
     linked or not linked = 1 (it's simple, just don't fill the tiles as we are out of available positions 
     which were upto n)
     
   # Final result will be given by: dp[2][0] + dp[2][1]
*/

const int N = 1e6;
ll is_calc[N+1];

void solve()
{
  	int n; cin >> n;
  	
  	if(is_calc[n] != -1) {
  		cout << is_calc[n] << "\n";
  		return;
  	}
  	
  	ll dp[n+2][2];
  	dp[n+1][0] = dp[n+1][1] = 1;
  	
  	for(int i = n; i >= 2; i--) {
  		ll op1 = (dp[i+1][0] + dp[i+1][1]) % mod;
  		ll op2 = dp[i+1][0];
  		ll op3 = (2 * dp[i+1][0]) % mod;
  		ll op4 = dp[i+1][1];
  		
  		dp[i][0] = ((op1 + op2) % mod + op3) % mod;
  		dp[i][1] = (op1 + op4) % mod;
  	}
  	
  	ll res = (dp[2][0] + dp[2][1]) % mod;
  	cout << res << "\n";
  	is_calc[n] = res; 
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
 	
 	memset(is_calc, -1, sizeof is_calc);
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
 
    return 0;
}