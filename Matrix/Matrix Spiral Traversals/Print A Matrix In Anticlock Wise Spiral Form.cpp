// Ref: https://www.youtube.com/watch?v=SVFXEqn3Ceo
/**************************************************************************************************/

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

vi spiral_anti_clock(vvi &v) {
	int n = (int)v.size();
	if(n == 0) return vi();
	int m = (int)v[0].size();
	
	int cnt = 0, tot = n * m;
	int mnr = 0, mxr = n - 1;
	int mnc = 0, mxc = m - 1;
	vi res;
	
	while(cnt < tot) {
		// left wall
		for(int i = mnr, j = mnc; i <= mxr and cnt < tot; i++) {
			res.pb(v[i][j]);
			cnt += 1;
		}
		
		mnc += 1;
		
		// bottom wall
		for(int i = mxr, j = mnc; j <= mxc and cnt < tot; j++) {
			res.pb(v[i][j]);
			cnt += 1;
		}
		
		mxr -= 1;
		
		// right wall
		for(int i = mxr, j = mxc; i >= mnr and cnt < tot; i--) {
			res.pb(v[i][j]);
			cnt += 1;
		}
		
		mxc -= 1;
		
		// up wall
		for(int i = mnr, j = mxc; j >= mnc and cnt < tot; j--) {
			res.pb(v[i][j]);
			cnt += 1;
		}
		
		mnr += 1;
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
  	
  	vi res = spiral_anti_clock(v);
  	
  	for(int i = 0; i < (int)res.size(); i++) {
  		cout << res[i] << " ";
  	}
  	
  	cout << "\n";
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