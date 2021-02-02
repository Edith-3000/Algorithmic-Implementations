// Problem: E. Obtain a Permutation
// Contest: Codeforces - Codeforces Round #615 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1294/E#
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 02-02-2021 23:58:06 IST (UTC+05:30)
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

void solve()
{
  	int n, m; cin >> n >> m;
  	int a[n][m];
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) {
  			cin >> a[i][j];
  			--a[i][j];
  		}
  	}
  	
  	int res = 0;
  	for(int j = 0; j < m; j++) {
  		vi cnt(n, 0);
  		for(int i = 0; i < n; i++) {
  			if(a[i][j] % m == j) {
  				int pos = a[i][j] / m;
  				if(pos < n) cnt[(i - pos + n) % n]++;
  			}
  		}
  		
  		int tmp = n - cnt[0];
  		for(int i = 1; i < n; i++) tmp = min(tmp, n - cnt[i] + i);
  		res += tmp;
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}