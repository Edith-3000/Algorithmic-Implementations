// Problem: https://www.interviewbit.com/problems/longest-palindromic-substring/
/*****************************************************************************************************/

// METHOD - 1 O(n^2)

// NOTE: This question can be done easily by making use of the concept used in the problem 
//       "Count All Palindromic Substrings.cpp"

/****************************************************************************************************/

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

// dp[i][j] = store that whether the substring s[i...j] is palindromic
// or not
vector<vector<bool>> dp;
string s; 

string longest_PSub() {
	int n = (int)s.length();
	dp.resize(n, vector<bool>(n));
	
	int len = 0, start;
	
	for(int g = 0; g < n; g++) { 
		for(int i = 0, j = g; j < n; i++, j++) {
			if(g == 0) dp[i][j] = 1;
			
			else if(g == 1) {
				if(s[i] == s[j]) dp[i][j] = 1;
				else dp[i][j] = 0;	
			}
			
			else {
				if(s[i] == s[j] and dp[i+1][j-1]) dp[i][j] = 1;
				else dp[i][j] = 0;
			}
			
			if(dp[i][j] and (g + 1) > len) {
				len = g + 1;
				start = i;
			}
		} 
	}
	
	string res = s.substr(start, len);
	return res;
}

void solve()
{
  	cin >> s; 	
  	cout << longest_PSub() << "\n";
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
// Space complexity: O(n^2)

/***************************************************************************************************/

// NOTE: For more efficient implementation refer editorials of --->
//       https://www.interviewbit.com/problems/longest-palindromic-substring/

/***************************************************************************************************/