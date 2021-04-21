// Problem: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
// Ref: https://www.youtube.com/watch?v=x21lPXfkJqw
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

int cnt_submatrices(vvi &v, int k) {
	int n = v.size();
	if(n == 0) return 0;
	int m = v[0].size();
		
	vvi cs(n, vi(m, 0));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cs[i][j] += v[i][j];
			if(j) cs[i][j] += cs[i][j-1];
		}
	}
	
	int res = 0;
	unordered_map<int, int> um;
	
	for(int j1 = 0; j1 < m; j1++) {
		for(int j2 = j1; j2 < m; j2++) {
			um.clear();		
			int sum = 0;
			
			for(int i = 0; i < n; i++) {
				int curr = cs[i][j2] - ((j1 == 0) ? 0 : cs[i][j1-1]);
				sum += curr;
				if(sum == k) res += 1;
				if(um.count(sum - k)) res += um[sum - k];
				um[sum]++;
			}
		}
	}
	
	return res;
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vvi v(n, vi(m));
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cin >> v[i][j];
  	}
  	
  	int target; cin >> target;
  	cout << cnt_submatrices(v, target) << "\n";
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

// Time complexity: O(m^2 x n)