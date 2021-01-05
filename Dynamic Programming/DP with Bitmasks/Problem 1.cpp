/* Problem Statement --->

Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that 
may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one
worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is 
minimized.

Input Format --->
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input --->
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4

Sample Output --->
13

Constraints --->
N <= 20

*/

// FIRST THING TO MAKE SURE BEFORE USING BITMASKS FOR SOLVING A PROBLEM IS THAT IT MUST BE HAVING SMALL 
// CONSTRAINTS, AS SOLUTIONS WHICH USE BITMASKING GENERALLY TAKE UP EXPONENTIAL TIME AND MEMORY.

// DP + Bitmask Approach

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

int dp[20][1 << 20];
int cost[20][20];
int n;

int dp_with_bitmask(int i, int mask) {
	// base case
	if(i == n) return 0;
	
	// check if already calculated
	if(dp[i][mask] != -1) return dp[i][mask];
	
	int res = INT_MAX;
	for(int j = 0; j < n; j++) {
		if(mask & (1 << j)) {
			res = min(res, cost[j][i] + dp_with_bitmask(i + 1, mask ^ (1 << j)));
		}
	}
	
	return dp[i][mask] = res;
}

void solve()
{
  	cin >> n;
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < n; j++) {
  			cin >> cost[i][j];
  		}
  	}
  	
  	memset(dp, -1, sizeof(dp));
  	cout << dp_with_bitmask(0, (1 << n) - 1);
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

// Time complexity: 
// Space complexity: O(n x 2^n)