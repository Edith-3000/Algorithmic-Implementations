// Problem: https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/
// Ref: http://satybald.com/dynamic/programming/2017/09/24/ways-to-color-3xN-board/
//      https://www.youtube.com/watch?v=wInXbAHi72g

// Ques. similar to this problem: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/

// Another method is also given at: --->
// https://www.geeksforgeeks.org/ways-color-3n-board-using-4-colors/
/********************************************************************************************************/

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
const ll mod = 1e9+7;

struct triplet {
	int x, y, z;
};

void fill_triplets(vector<triplet> &v) {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				// adjacent colors must not be same in a particular column
				if(i != j and j != k) v.pb({i, j, k});
			}
		}
	}
}

// adjacent colors of 2 different columns must not be same
bool is_compatible(triplet &t1, triplet t2) {
	if(t1.x == t2.x or t1.y == t2.y or t1.z == t2.z) return 0;
	else return 1;
}

int find_ans(int n) {
	if(n <= 0) return 0;
	
	// to store the all possible 36 combinations of color that can 
	// be used to color a particular column of 3 cells
	vector<triplet> v;
	fill_triplets(v);
	
	// dp[i][j][k][x] = #ways to color the board from 1st col to the xth
	// col such that the configuration of the xth col is i, j, k
	int dp[4][4][4][n+1];
	
	for(int i = 1; i <= n; i++) {
		// iterating over every possible configuration that the ith column can attain
		for(int j = 0; j < 36; j++) {
			if(i == 1) dp[v[j].x][v[j].y][v[j].z][i] = 1;
			else {
				ll tmp = 0;
				
				// iterating over every possible configuration that the (i-1)th column can 
				// attain & checking if we can use the jth and kth configurations side by side
				for(int k = 0; k < 36; k++) {
					if(is_compatible(v[j], v[k])) {
						tmp += dp[v[k].x][v[k].y][v[k].z][i-1];
						tmp %= mod;
					}
				}
				
				dp[v[j].x][v[j].y][v[j].z][i] = tmp;
			}
		}
	}
	
	ll res = 0;
	for(int i = 0; i < 36; i++) {
		res += dp[v[i].x][v[i].y][v[i].z][n];
		res %= mod;
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	cout << find_ans(n) << "\n";
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