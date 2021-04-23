// Problem: https://www.interviewbit.com/problems/unique-binary-search-trees-ii/
// Very nice explanation: https://www.youtube.com/watch?v=H1qjjkm3P3c
/********************************************************************************************************/

// METHOD - 1 O(n^2)

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

// n is 0-based
ll nth_catalan_no(ll n) {
	// base condition
	// catalan no. for -ve nos. isn't defined
	if(n < 0) return -1; 
	
	vll dp(n + 1);
	dp[0] = 1;
	
	for(ll i = 1; i <= n; i++) {
		dp[i] = 0; // initializing result for each ith catalan no.
		for(ll j = 0; j < i; j++) dp[i] += (dp[j] * dp[i-1-j]);
	}
	
	return dp[n];
}

ll unique_BST(ll n) {
	return nth_catalan_no(n);
}

void solve()
{
  	ll n; cin >> n;
  	cout << unique_BST(n) << "\n";
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

/********************************************************************************************************/

// METHOD - 2 O(n)

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

ll nCr(ll n, ll r) {
	if(r > n) return 0;
	if(r == n or r == 0) return 1;
	
	// since C(n, r) = C(n, n-r) 
	// it is done so as to reduce the #iterations
	if(r > (n - r)) r = n - r;	
	
	ll res = 1; //initialize result
	
	for(ll i = 0; i < r; i++) {
		res *= (n - i);
		res /= (i + 1);
	}
	
	return res;
}

// n is 0-based
ll nth_catalan_no(ll n) {
	// base condition
	// catalan no. for -ve nos. isn't defined
	if(n < 0) return -1; 
	
	ll res = nCr(2 * n, n);
	res /= (n + 1);
	
	return res;
}

ll unique_BST(ll n) {
	return nth_catalan_no(n);
}

void solve()
{
  	ll n; cin >> n;
  	cout << unique_BST(n) << "\n";
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