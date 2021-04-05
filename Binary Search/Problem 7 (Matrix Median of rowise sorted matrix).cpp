// Ref: https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/
/***************************************************************************************************/

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

int find_median(vvi &v) {
	int n = v.size();
	int m = v[0].size();
	
	int mn = INT_MAX, mx = INT_MIN;
	for(int i = 0; i < n; i++) {
		mn = min(mn, v[i][0]);
		mx = max(mx, v[i][m-1]);
	}
	
	int desired = (n * m) / 2 + 1;
	int L = mn - 1, R = mx;
	
	while(L + 1 < R) {
		int mid = L + ((R - L) >> 1);
		int cnt = 0;
		
		for(int i = 0; i < n; i++) {
			cnt += upper_bound(v[i].begin(), v[i].end(), mid) - v[i].begin();
		}
		
		if(cnt < desired) L = mid;
		else R = mid;
	}
	
	return R;
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vvi v(n, vi(m));
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cin >> v[i][j];
  	}
  	
  	cout << find_median(v) << "\n";
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