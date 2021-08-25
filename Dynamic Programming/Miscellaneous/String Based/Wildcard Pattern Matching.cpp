// Problem: https://www.techiedelight.com/wildcard-pattern-matching/
// Ref: https://www.techiedelight.com/wildcard-pattern-matching/
//      https://www.geeksforgeeks.org/wildcard-pattern-matching/
//      https://www.youtube.com/watch?v=NbgUZAoIz3g
//      (In the video explanation is good but implementation is slightly different)
/********************************************************************************************************/

// NOTE: In case you get MLE on some platforms, use dp as bool instead of int type.
/********************************************************************************************************/

// METHOD - 1 (Top Down DP)

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

// Function that matches the input string str with a given 
// wildcard pattern pat
int is_matching(string &str, string &pat, int n, int m, vvi &dp) {
	// If both the input string and pattern reach their end, return true
	if(n < 0 and m < 0) return 1;
	
	// If only the pattern reaches its end, return false
	else if(m < 0) return 0;
	
	// If only the input string reaches its end, return true
    // if the remaining characters in the pattern are all '*'
	else if(n < 0) {
		for(int i = 0; i <= m; i++) {
			if(pat[i] != '*') return 0;
		}
		
		return 1;
	}
	
	// check if already calculated
	if(dp[n][m] != -1) return dp[n][m];
	
	int res = 0;
	
	// if current wildcard char is '?' try to match other characters in both strings
	if(pat[m] == '?') res = is_matching(str, pat, n - 1, m - 1, dp);
	
	 // 1. Ignore '*' and move to the next character in the pattern
	 // 2. '*' matches with current characters in the input string.
     //    Here, we will move to the next character in the string.            
	else if(pat[m] == '*') res = is_matching(str, pat, n, m - 1, dp) or 
								 is_matching(str, pat, n - 1, m, dp);
								 
	// If the current character is not a wildcard character, it
    // should match the current character in the input string
	else if(str[n] == pat[m]) res = is_matching(str, pat, n - 1, m - 1, dp);
	else res = 0;
	
	return dp[n][m] = res;
}

void solve()
{
  	string str, pat;
  	cin >> str >> pat;
  	
  	// get the length of string and wildcard pattern
	int n = (int)str.size();
	int m = (int)pat.size();
  	
  	vvi dp(n, vi(m, -1));
  	if(is_matching(str, pat, n - 1, m - 1, dp)) cout << "YES\n";
  	else cout << "NO\n"; 
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

// TC: O(n x m)
// SC: O(n x m)

/*****************************************************************************************************/

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
const int mod = 1e9+7;

// Function that matches the input string str with a given 
// wildcard pattern pat
bool is_matching(string &str, string &pat) {
	// get the length of string and wildcard pattern
	int n = (int)str.size();
	int m = (int)pat.size();
	
	// create a DP lookup table
	// dp[i][j] = 1, if str of length i (str[0.....i-1]) matches 
	//               with the pat of length j (pat[0....j-1])
	// else dp[i][j] = 0
	// therefore final result at dp[n][m]
	vvi dp(n + 1, vi(m + 1));
	
	// if both pattern and string are empty: match
	dp[0][0] = 1;
	
	// if pattern is empty then no matching, for length 1 to n
	for(int i = 1; i <= n; i++) dp[i][0] = 0;
	
	// handles empty string case (i == 0)
	for(int j = 1; j <= m; j++) {
		if(pat[j-1] == '*') dp[0][j] = dp[0][j-1];
		else dp[0][j] = 0;
	}
	
	// build a matrix in a bottom-up manner
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(pat[j-1] == '?') dp[i][j] = dp[i-1][j-1];
			else if(pat[j-1] == '*') dp[i][j] = dp[i-1][j] or dp[i][j-1];
			else if(pat[j-1] == str[i-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = 0;
		}
	}
	
	// last cell stores the answer
	return dp[n][m];
}

void solve()
{
  	string str, pat;
  	cin >> str >> pat;
  	
  	if(is_matching(str, pat)) cout << "YES\n";
  	else cout << "NO\n"; 
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

// TC: O(n x m)
// SC: O(n x m)