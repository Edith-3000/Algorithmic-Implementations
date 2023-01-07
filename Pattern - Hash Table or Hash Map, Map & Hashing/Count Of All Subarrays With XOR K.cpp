// Problem: https://www.interviewbit.com/problems/subarray-with-given-xor/

// Ref: https://www.youtube.com/watch?v=lO9R5CaGRPY
/******************************************************************************************************************************************/

// NOTE: The below algorithm is very much similar to "Longest Subarray With Sum K.cpp"

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

ll cnt_subarr(vi &v, ll k) {
	int n = (int)v.size();
	if(n == 0) return 0LL;
	
	map<ll, ll> m;
	
	// x is used to store the prefix xor of array  
	ll x = 0LL; 
	
	// to store the total count
	ll res = 0LL;
	
	for(int i = 0; i < n; i++) {
		x ^= v[i];
		if(x == k) res += 1;
		
		if(m.find(x ^ k) != m.end()) {
			res += m[x ^ k];
		}

		// the current xor must be added in the map after checking
		// for the above condition in order to avoid same subarray
		// taken into consideration
		m[x] += 1;
	}
	
	return res;
}

void solve()
{
	int n; ll k;
	cin >> n >> k;
	
	vi v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	
	cout << cnt_subarr(v, k) << "\n";
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