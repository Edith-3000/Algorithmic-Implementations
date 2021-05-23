/* Reference(s): --->
   https://www.geeksforgeeks.org/count-distinct-subsequences/
   https://www.youtube.com/watch?v=9UEHPiK53BA  
   https://leetcode.com/problems/distinct-subsequences-ii/            
*/

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

// dp[i] store the count of #distinct subseq. in prefix
// of length i (i.e. for s[0......i-1])
vll dp;

// map to store index of last occurence of a char 
unordered_map<char, int> um;

// Returns count of distinct sunsequences (including empty subseq) of 's'
ll cnt_dis_seq(string &s) {
	int n = s.length();
	dp.resize(n + 1);
	
	 // Empty string has only one subsequence
	dp[0] = 1;
	
	// Traverse through all lengths from 1 to n.
	for(int i = 1; i <= n; i++) {
		char ch = s[i-1];
		dp[i] = 2 * dp[i-1];
		
		 // If current char has appeared before, then remove all 
		 // subseq ending with previous occurrence.
		if(um.count(ch)) {
			dp[i] -= dp[um[ch] - 1];
		}
		
		// Mark occurrence of current character
		um[ch] = i;
	}
	
	return dp[n];
}

void solve()
{
  	string s; cin >> s;
  	cout << cnt_dis_seq(s) << "\n";
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

// Time Complexity: O(n) 
// Auxiliary Space: O(n)