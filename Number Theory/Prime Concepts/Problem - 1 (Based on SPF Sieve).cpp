// Approach: https://www.youtube.com/watch?v=EU2TNK2qjSk
// SPF Sieve: https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
/********************************************************************************************************/

// Problem: D. The Number of Pairs
// Contest: Codeforces - Educational Codeforces Round 106 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1499/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Parsed on: 26-03-2021 12:42:20 IST (UTC+05:30)
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
const int MAXN = 2e7;

vi spf_sieve(MAXN + 1);
vi cnt_p_factors(MAXN + 1);

void init() {
	for(int i = 1; i <= MAXN; i++) {
		spf_sieve[i] = i;
		cnt_p_factors[i] = 0;
	}
	
	for(int i = 2; i <= MAXN; i++) {
		if(spf_sieve[i] == i) {
			for(int j = i; j <= MAXN; j += i) {
				if(spf_sieve[j] == j) spf_sieve[j] = i;
				cnt_p_factors[j]++;
			}
		}
	}
}

void solve()
{
  	ll c, d, x; 
  	cin >> c >> d >> x;
  	
  	ll res = 0;
  	
  	for(ll i = 1; i * i <= x; i++) {
  		if(x % i == 0) {
  			ll xx = x / i;
  			if((xx + d) % c == 0) {
  				ll cc = (xx + d) / c;
  				res += (1LL << cnt_p_factors[cc]);
  			}
  			
  			if((x / i) != i) {
  				ll xx = i;
  				if((xx + d) % c == 0) {
  					ll cc = (xx + d) / c;
  					res += (1LL << cnt_p_factors[cc]);
  				}
  			}
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
	
	init();
    int t = 1;
    // int test = 1;
    cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}