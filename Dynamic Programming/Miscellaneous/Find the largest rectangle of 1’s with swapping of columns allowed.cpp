// Problem: https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/
// Ref: https://www.youtube.com/watch?v=9vYCQLYF6ng
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

int find_ans(vvi &v) {
	int n = (int)v.size();
	if(n == 0) return 0;
	int m = (int)v[0].size();
	
	vvi pref_up(n, vi(m, 0));
	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			if(v[i][j] == 0) continue;
			pref_up[i][j] += 1;
			int x = (i == 0) ? 0 : pref_up[i-1][j];
			pref_up[i][j] += x;
		}
	}
	
	for(int i = 0; i < n; i++) {
		sort(pref_up[i].begin(), pref_up[i].end());
	}
	
	int res = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(pref_up[i][j] == 0) continue;
			int height = pref_up[i][j];
			int width = m - j;
			res = max(res, height * width);
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
  	
  	cout << find_ans(v) << "\n";
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

// TC: O(n * mlog(m))