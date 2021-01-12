// Problem: 10325 - The Lottery
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1266
// Memory Limit: 32 MB
// Time Limit: 3000 ms
// Parsed on: 12-01-2021 14:22:33 IST (UTC+05:30)
// Author: kapil_choudhary

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

ll n, m;
vll v;

ll find_gcd(ll a, ll b) {
	return (a == 0) ? b : find_gcd(b % a, a);
}

void solve()
{
  	v.resize(m);
  	for(ll i = 0; i < m; i++) cin >> v[i];
  	
  	ll cnt = 0;
  	for(ll mask = 1; mask < (1 << m); mask++) {
  		ll lcm = 1, bits = 0;
  		for(ll i = 0; i < m; i++) {
  			if(mask & (1 << i)) {
  				bits++;
  				lcm = (lcm * v[i]) / find_gcd(lcm, v[i]);
  			}
  		}
  		
  		if(bits & 1) cnt += (n/lcm);
  		else cnt -= (n/lcm);
  	}
  	
  	cout << n - cnt << "\n";
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
    while(cin >> n >> m) {
      solve();
    }

    return 0;
}