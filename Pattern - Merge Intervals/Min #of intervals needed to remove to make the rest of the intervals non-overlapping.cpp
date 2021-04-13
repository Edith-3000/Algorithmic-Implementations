// Problem: https://leetcode.com/problems/non-overlapping-intervals/
// Ref: https://www.youtube.com/watch?v=BTObFnHbD4U
/*********************************************************************************************************/

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

// Note: In the below algorithm intervals ending and starting at the same 
//       time have been considered non-overlapping (such as [1, 4] and [4, 10])
//       have been considered non-overlapping.
int erase_overlapping(vvi &v) {
	// total #intervals
	int n = (int)v.size();
	
	// sort all intervals in non decreasing order of start time
	sort(v.begin(), v.end());
	
	// L = current left interval
	// R = current right interval
	int L = 0, R = 1;
	
	// to store the final result i.e.  minimum #intervals needed to 
	// remove to make the rest of the intervals non-overlapping.
	int res = 0;
	
	// iterate unless all intervals are compared 
	while(R < n) {
		if(v[L][1] <= v[R][0]) {
			L = R;
			R += 1;	
		}
		
		// remove rigth interval
		else if(v[L][1] <= v[R][1]) {
			R += 1;
			res += 1;
		}
		
		// remove left interval
		else {
			L = R;
			R += 1;
			res += 1;
		}
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vvi v(n, vi(2));
  	for(int i = 0; i < n; i++) {
  		cin >> v[i][0] >> v[i][1];
  	}
  	
  	cout << erase_overlapping(v);
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