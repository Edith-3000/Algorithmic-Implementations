// Problem: Edit Distance
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1639
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 03-02-2021 15:59:27 IST (UTC+05:30)
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

int dp[5000][5000];
string s1, s2;

int driver(int i, int j) {
	// base case(s)
	if(i == (int)s1.length() || j == (int)s2.length()) {
		return max((int)s2.length() - j, (int)s1.length() - i);
	}
	
	// check if already calculated or not
	int &res = dp[i][j];
	if(res != -1) return res;
	
	// if characters at s1(i) and s2(j) are same
	if(s1[i] == s2[j]) res = driver(i + 1, j + 1);
	
	// otherwise we have 3 options
	else {
		int op1 = 1 + driver(i + 1, j + 1); // if s1[i] is replaced
		int op2 = 1 + driver(i + 1, j); // if s1[i] is removed
		int op3 = 1 + driver(i, j + 1); // if a char is added before s1[i]
		res = min(op1, min(op2, op3));
	}
	
	return res;	
}

void solve()
{
  	cin >> s1 >> s2;
  	memset(dp, -1, sizeof dp);
  	cout << driver(0, 0) << "\n";
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

// WORD OF CAUTION: Either make the strings s1 and s2 as global variables or pass them by reference to 
//                  the driver() function, as passing these both strings by value may give TLE as in each
//                  recursive call the string will be copied again and again.