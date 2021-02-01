// METHOD 1 - (TC = O(n x log2(n)))

// Problem: B. Inflation
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1476/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 31-01-2021 13:12:32 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

bool ok(ll sum, vll &v, ll k) {
	for(ll i = 1; i < v.size(); i++) {
		if(v[i] > (sum * k)/100) return false;
		sum += v[i];
	}
	
	return true;
}

void solve()
{
  	ll n, k; cin >> n >> k;
  	vll v(n);
  	for(ll i = 0; i < n; i++) cin >> v[i];
  	
  	ll l = 0, r = 1e15;
  	while(l < r) {
  		ll mid = l + ((r - l) >> 1);
  		ll sum = v[0] + mid;
  		if(ok(sum, v, k)) r = mid;
  		else l = mid + 1;
  	}
  	
  	cout << l << "\n";
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

/***********************************************************************************************************/

// METHOD 2 - (TC = O(n)

// Problem: B. Inflation
// Contest: Codeforces - Educational Codeforces Round 103 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1476/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 31-01-2021 12:41:50 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll ceil(ll x, ll y) {
  return (x % y == 0) ? (x/y) : (x/y) + 1;
}

void solve()
{
    ll n, k; cin >> n >> k;
    vll v(n), cs(n + 1, 0);
    for(ll i = 0; i < n; i++) {
      cin >> v[i];
      cs[i+1] = cs[i] + v[i];
    }
    
    ll res = 0, curr = 0;
    for(ll i = 1; i < n; i++) {
      cs[i] += curr;
      if((v[i] * 100) > (k * cs[i])) {
        ll x = ceil((v[i] * 100) - (k * cs[i]), k);
        res += x;
        curr += x;
      }
    }
    
    cout << res << "\n";
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}