// Ref: https://www.techiedelight.com/find-maximum-product-subarray-given-array/
//      https://www.youtube.com/watch?v=hJ_Uy2DzE08
/******************************************************************************************************/

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

// Function to return the maximum product of a subarray of a given array
ll max_prod_subarr(vll &v) {
	int n = (int)v.size();
	if(n == 0) return 0;
	
	// to store the final result
	ll res = v[0];
	
	// max_ending_here = maximum product ending at the current index. 
    // min_ending_here = minimum product ending at the current index.
	ll max_ending_here = v[0];
	ll min_ending_here = v[0];
	
	for(int i = 1; i < n; i++) {
		ll tmp = max_ending_here;
		
		// update the maximum product ending at the current index
		max_ending_here = max(v[i], max(v[i] * max_ending_here, v[i] * min_ending_here));
		
		// update the minimum product ending at the current index
		min_ending_here = min(v[i], min(v[i] * min_ending_here, v[i] * tmp));
		
		// update final result
		res = max(res, max_ending_here);
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vll v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << max_prod_subarr(v) << "\n";
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

// Time complexity: O(n)
// Space complexity: O(1)