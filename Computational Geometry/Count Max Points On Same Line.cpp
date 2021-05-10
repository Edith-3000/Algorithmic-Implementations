// Problem: https://www.interviewbit.com/problems/points-on-the-straight-line/
// Ref: https://www.geeksforgeeks.org/count-maximum-points-on-same-line/
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

// Function to find maximum #collinear points
int max_collinear_pts(vpii &v) {
	int n = (int)v.size();
	if(n <= 2) return n;
	
	// there will be atleast 2 collinear points if n >= 3
	int res = 2;
	map<pii, int> m;
	
	// looping for each point
	for(int i = 0; i < n; i++) {
		// to find result given by curret point
		int cur_mx = 0; 
		
		// count points have same x co-ordinate as that of ith point
		int ver_pts = 0; 
		
		// count points overlapping with the ith point
		int ovp_pts = 0;
		
		// looping from i + 1 to ignore same pair again
		for(int j = i + 1; j < n; j++) {
			// if both point are equal, increase ovp_cnt count
			if(v[j] == v[i]) ovp_pts += 1;
			
			// if x co-ordinate is same, then both points are vertical to each other
			else if(v[j].F == v[i].F) ver_pts += 1;
			
			else {
				int num = v[j].S - v[i].S;
				int den = v[j].F - v[i].F;
				int GCD = __gcd(num, den);
				
				// reducing the fraction by their gcd
				num /= GCD;
				den /= GCD;
				
				// increasing the frequency of current slope in map
				m[{num, den}] += 1;
				cur_mx = max(cur_mx, m[{num, den}]);
			}
		}
		
		m.clear();
		cur_mx = max(cur_mx, ver_pts);
		
		// updating global maximum by current point's maximum
		res = max(res, cur_mx + ovp_pts + 1);
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vpii v(n);
  	for(int i = 0; i < n; i++) {
  		cin >> v[i].F >> v[i].S;
  	}
  	
  	cout << max_collinear_pts(v) << "\n";
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

// TC: O(n^2 x log(n))
// NOTE: Instead of std::map, std::unordered_map can also be used using Boost library in C++, as
//       given in GfG article.