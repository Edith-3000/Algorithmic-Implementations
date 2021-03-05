/* Reference(s) --->
   https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/
   https://medium.com/@shahareg98/finding-all-palindromic-subsequence-in-the-given-string-2317fb50a2d

   # Very detailed mathematical explanation given at --->
   https://www.youtube.com/watch?v=YHSjvswCXC8
*/

// NOTE: In the codes below an empty subsequence is not been considered as a palindromic subsequence, if you
//       want to just add 1 to the final result.


/*************************************************************************************************************/

// Method 1 (Recursive approach)

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
string s; 

ll cnt_all_PSeq(int i, int j) {
	// base case
	if(i == j) return 1;
	if(i > j) return 0;
	
	if(s[i] == s[j]) {
		return cnt_all_PSeq(i, j - 1) + cnt_all_PSeq(i + 1, j) + 1;
	}
	
	else {
		return cnt_all_PSeq(i, j - 1) + cnt_all_PSeq(i + 1, j) - cnt_all_PSeq(i + 1, j - 1);
	}
}

void solve()
{
  	cin >> s;
  	cout << cnt_all_PSeq(0, s.length() - 1) << "\n";
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

// Time complexity: Exponential

/**********************************************************************************************************/

// Method 2 (Bottom Up DP)

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

// dp[i][j] = store the count of all palindromic subseq present
// in the string s[i.....j]
vvll dp;
string s; 

ll cnt_all_PSeq() {
	int n = (int)s.length();
	dp.resize(n, vll(n));
	
	for(int g = 0; g < n; g++) { 
		for(int i = 0, j = g; j < n; i++, j++) {
			if(g == 0) dp[i][j] = 1;
			
			else if(g == 1) {
				if(s[i] == s[j]) dp[i][j] = 3;
				else dp[i][j] = 2;	
			}
			
			else {
				if(s[i] == s[j]) dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
				else dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
			}
		} 
	}
	
	return dp[0][n-1];
}

void solve()
{
  	cin >> s; 	
  	cout << cnt_all_PSeq() << "\n";
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

// Time complexity: O(n^2)