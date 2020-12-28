// Link to very nice explanation of the code below --->
// https://sreeprasad.medium.com/sagheer-the-hausmeister-eceb418fd8e5

/**********************************************************************************************************/

/* CERTAIN THINGS TO KEEP IN MIND
   1. Below is a recursive approach, as the constraints are small.
   2. This is a typical digit DP problem, hence for larger constraints digit DP can be used.
   3. Take the input very carefully, the input 2 D matrix must be of type 'char' not 'int'.
   4. We have to consider the 0th floor as the top floor, hence necessary accomodation must be made in 
      the code to find the highest floor have a light bulb on as well as to fill l[i] & r[i] values.
*/ 

// Problem: B. Sagheer, the Hausmeister
// Contest: Codeforces - Codeforces Round #417 (Div. 2)
// URL: https://codeforces.com/problemset/problem/812/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 28-12-2020 20:50:42 IST (UTC+05:30)
// Author: kapil_choudhary

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

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

char a[15][100];
int l[15], r[15];
int n, m, mx;

int min_time(bool from_left, int floor, int res) {
	// base case
	if(floor == mx) {
		if(from_left) res += l[floor];
		else res += r[floor];
		return res;
	}
	
	// dist_left is moving from current position to next floor from left most stairs
    // dist_right is moving from current position to next floor from right most stairs
	// return min distance after going to next floor through left and right
	
	// Case 1: we enter the current floor from left stairs
	if(from_left) {
		res += l[floor];
		int dist_left = res + l[floor] + 1;
		int dist_right = res + (m - l[floor] - 1) + 1;
		return min(min_time(true, floor + 1, dist_left), min_time(false, floor + 1, dist_right));
	}
	
	// Case 2: we enter the current floor from right stairs
	else {
		res += r[floor];
		int dist_left = res + (m - r[floor] - 1) + 1;
		int dist_right = res + r[floor] + 1;
		return min(min_time(true, floor + 1, dist_left), min_time(false, floor + 1, dist_right));
	}
}

void solve()
{
  	mx = INT_MIN;
  	for(int i = 0; i < 15; i++) {
  		l[i] = 0;
  		r[i] = 0;
  	}
  	
  	cin >> n >> m;
  	m += 2;
  	for(int i = 0; i < n; i++) {
  		cin >> a[i];
  		for(int j = 0; j < m; j++) {
  			if(a[i][j] == '1') {
  				mx = max(mx, n-i-1); 
  				l[n-i-1] = j;
  				r[n-i-1] = max(r[n-i-1], m - l[n-i-1] - 1);
  			}
  		}
  	}
  	
  	if(mx == INT_MIN) cout << 0 << "\n";
  	
  	// start from 0th floor(ground floor) from left stairs
  	// as stated in the question
  	else cout << min_time(true, 0, 0); 
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

// Time Complexity: O(n * 2^n)
// Link: https://codeforces.com/blog/entry/52318