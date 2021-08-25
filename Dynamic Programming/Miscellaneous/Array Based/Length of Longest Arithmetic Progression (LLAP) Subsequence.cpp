// Problem: https://www.interviewbit.com/problems/longest-arithmetic-progression/
// Ref: https://www.youtube.com/watch?v=Lm38EAoDc7c
//      https://www.geeksforgeeks.org/longest-subsequence-forming-an-arithmetic-progression-ap/

// For brute force refer hints in : --->
// https://www.interviewbit.com/problems/longest-arithmetic-progression/
/*******************************************************************************************************/

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

// Function that finds the Length of Longest Arithmetic Progression
// (LLAP) subsequence in the input vector v
int LLAP(vi &v) {
	int n = (int)v.size();
	if(n <= 2) return n;
	
	// dp[i] is an unordered_map which as key stores the common
	// difference and as value stores LLAP ending at v[i] with
	// the given common difference (key) 
	vector<unordered_map<int, int>> dp(n);
	
	// initialising the final result
	int res = 2;
	
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int diff = v[j] - v[i];
			if(dp[i].find(diff) != dp[i].end()) {
				dp[j][diff] = dp[i][diff] + 1;
			}
			
			else dp[j][diff] = 2;
			res = max(res, dp[j][diff]);
		}
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << LLAP(v) << "\n";
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

// Time Complexity: O(n^2)
// Auxiliary Space: O(n^2)