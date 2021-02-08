// Reference(s): https://www.youtube.com/watch?v=SKBjnm39Puk
/*************************************************************************************************************/

// Problem: LCM Sum
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/LCMSUM/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// Parsed on: 08-02-2021 17:06:02 IST (UTC+05:30)
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
const ll N = 1e6;

vll phi(N + 1);
vll res(N + 1);

void ETF() {
	for(ll i = 1; i <= N; i++) phi[i] = i;
	
	for(ll i = 2; i <= N; i++) {
		if(phi[i] == i) {
			for(ll j = i; j <= N; j += i) {
				phi[j] /= i;
				phi[j] *= (i - 1);
			}
		}
	}
}

void precompute() {
	for(ll i = 1; i <= N; i++) res[i] = 0;
	
	for(ll i = 1; i <= N; i++) {
		for(ll j = i; j <= N; j += i) {
			res[j] += phi[i] * i;
		}
	}
}

void solve()
{
  	ll n; cin >> n;
  	ll ans = (res[n] - 1) * n;
  	ans /= 2; ans += n;
  	cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
	
	ETF();
	precompute();
	
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

// Time complexity: With precalculations in the ETF() and precompute() function in O(N x log(n)), 
//                  each query is answered in O(1) time.