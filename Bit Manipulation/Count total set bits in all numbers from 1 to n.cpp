// Problem: https://www.interviewbit.com/problems/count-total-set-bits/

// Ref: https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/
//      https://www.youtube.com/watch?v=g6OxU-hRGtY

/*********************************************************************************************************************************************************/

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
const ll mod = 1e9+7;

ll mod_exp(ll a, ll b) {
	a %= mod;
	if(a == 0) return 0LL;
	
	ll res = 1LL;
	while(b > 0) {
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	
	return res;
}

// Function to find largest power of 2 <= n
ll find_pow(ll n) {
	int x = 0;
	while((1LL << x) <= n) x += 1;
	x -= 1;
	return x;
}

// Function to find total sets bits in all nos. from 
// 1 to n modulo 1e9+7
ll cnt_bits(ll n) {
	// base case
	if(n == 0) return 0LL;
	
	ll res = 0LL;
	ll x = find_pow(n);
	
	if(x) res = mod_exp(2LL, x - 1); 
	res = (res * x) % mod;
	
	ll y = n - (1 << x) + 1;
	res = (res + y) % mod;
	
	res = (res + cnt_bits(n - (1 << x))) % mod;
	return res;
}

void solve()
{
  	ll n; cin >> n;
  	cout << cnt_bits(n) << "\n";
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