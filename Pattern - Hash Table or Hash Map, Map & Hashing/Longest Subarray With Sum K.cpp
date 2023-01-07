// Link: https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

// Ref: https://www.youtube.com/watch?v=xmguZ6GbatA 
//      https://www.geeksforgeeks.org/longest-sub-array-sum-k/

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

vi longest_subarr(vi &v, ll k) {
	int n = (int)v.size();
	if(n == 0) return vi();
	
	map<ll, int> m;
	ll sum = 0LL;
	int mx_len = 0, st;
	
	for(int i = 0; i < n; i++) {
		sum += v[i];
		if(sum == k) {
			mx_len = i + 1;
			st = 0;
		}
		
		if(m.find(sum - k) != m.end()) {
			if(mx_len < i - m[sum - k]) {
				mx_len = i - m[sum - k];
				st = m[sum - k] + 1;
			}
		}

		// the current sum must be added in the map after checking
		// for the above condition in order to avoid same subarray
		// taken into consideration
		if(m.find(sum) == m.end()) {
			m[sum] = i;
		}
	}
	
	vi res;
	for(int i = st; mx_len > 0; i++, mx_len--) {
		res.pb(v[i]);
	}
	
	return res;
}

void solve()
{
  	int n; ll k;
  	cin >> n >> k;
  	
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vi res = longest_subarr(v, k);
  	
  	cout << res.size() << "\n";
  	for(auto x: res) cout << x << " ";
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

// Time complexity: O(n x log(n))
// Space complexity: O(n)