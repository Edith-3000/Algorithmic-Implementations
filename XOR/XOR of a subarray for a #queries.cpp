// Ref: https://www.geeksforgeeks.org/xor-of-a-subarray-range-of-elements/
/*****************************************************************************************************/

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

// Function to preprocess the array and find count of 
// number of ones upto jth index for ith bit.
// cnt[i][j] stores the total #set bits in the ith bit position
// for all the numbers in the subarray v[0.....j]
void preprocess(vi &v, vvi &cnt) {
	int n = (int)v.size();
	
	for(int i = 0; i < 32; i++) {
		for(int j = 0; j < n; j++) {
			if(v[j] & (1 << i)) cnt[i][j] += 1;
			if(j) cnt[i][j] += cnt[i][j-1];
		}
	}
}

// Function to find XOR value for a range of array elements from
// L to R (L and R are 0-based indexed)
int process_query(int L, int R, vvi &cnt) {
	int res = 0;
	
	// Find number of 1s for each bit position from 0 to 31.
	for(int i = 0; i < 32; i++) {
		int ones = cnt[i][R] - ((L > 0) ? cnt[i][L-1] : 0);
		if(ones & 1) res |= (1 << i);
	}
	
	return res;
}

void solve()
{
  	int n, q; cin >> n >> q;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vvi cnt(32, vi(n, 0));
  	preprocess(v, cnt);
  	
  	for(int i = 0; i < q; i++) {
  		int L, R; cin >> L >> R;
  		cout << process_query(L, R, cnt) << "\n";
  	}
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

// Time Complexity: O(n + q)
// Auxiliary Space: O(n)