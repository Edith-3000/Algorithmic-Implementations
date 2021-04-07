// Explanation: https://www.youtube.com/watch?v=ws98ud9uxl4
//              https://www.youtube.com/watch?v=LPFhl65R7ww
//              https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/share-my-ologminmn-solution-with-explanation

// Problem: https://www.interviewbit.com/problems/median-of-array/
//          https://leetcode.com/problems/median-of-two-sorted-arrays/
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

double find_median(vi &v1, vi &v2) {
	int n = (int)v1.size();
	int m = (int)v2.size();
	
	// Ensuring that v1.length() <= v2.length()
	if(n > m) return find_median(v2, v1);
	
	int start = 0, end = n;
		
	while(start <= end) {
		int i1 = (start + end) / 2;
		int i2 = (n + m + 1) / 2 - i1;
			
		int min1 = (i1 == n) ? INT_MAX : v1[i1];
		int max1 = (i1 == 0) ? INT_MIN : v1[i1-1];
			
		int min2 = (i2 == m) ? INT_MAX : v2[i2];
		int max2 = (i2 == 0) ? INT_MIN : v2[i2-1];
			
		if((max1 <= min2) and (max2 <= min1)) {
			if((n + m) % 2 == 0) {
				return ((double)max(max1, max2) + min(min1, min2)) / 2;
			}
				
			else return (double)max(max1, max2);
		}
			
		else if(max1 > min2) end = i1 - 1;
		else start = i1 + 1;
	} 
	
	// Only we we can come here is if input arrays were not sorted.
	return 0.0; 
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vi v1(n), v2(m);
  	
  	for(int i = 0; i < n; i++) cin >> v1[i];
  	for(int i = 0; i < m; i++) cin >> v2[i];
  	
  	cout << find_median(v1, v2);
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

// Time complexity: O(log(min(m,n))
// Space complexity: O(1)