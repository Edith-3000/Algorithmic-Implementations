// Ref: https://www.geeksforgeeks.org/maximum-mex-from-all-subarrays-of-length-k/
/**************************************************************************************************/

// Problem ---> Given an array arr[] consisting of N "distinct" integers and an integer K, the task 
//              is to find the maximum MEX from all subarrays of length K.

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

int find_max_MEX(vi &v, int n, int k) {
	set<int> s;
	for(int i = 0; i <= n; i++) s.insert(i);
	
	for(int i = 0; i < k; i++) {
		s.erase(v[i]);
	}
	
	int mex = *(s.begin());
	
	for(int i = k; i < n; i++) {
		s.erase(v[i]);
		s.insert(v[i-k]);
		mex = max(mex, *(s.begin()));
	}
	
	return mex;
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << find_max_MEX(v, n, k);
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}