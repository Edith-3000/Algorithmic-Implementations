// Editorial: https://codeforces.com/blog/entry/87849
// NOTE: In the algorithm I have used binary search with half-interval, explanation of this technique --->
//       https://codeforces.com/blog/entry/87849?#comment-763558
//       https://codeforces.com/blog/entry/87849?#comment-763573

/**********************************************************************************************************/

// Problem: D. Max Median
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 20-02-2021 21:03:13 IST (UTC+05:30)
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
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	int L = 1, R = n + 1;
  	
  	while(L + 1 < R) {
  		int m = L + ((R - L) >> 1);
  		vi t(n);
  		for(int i = 0; i < n; i++) {
  			t[i] = (v[i] >= m) ? 1 : -1;
  		}
  		
  		for(int i = 1; i < n; i++) t[i] += t[i-1];
  		
  		int mx = t[k-1];
  		int mn = 0;
  		
  		for(int i = k; i < n; i++) {
  			mn = min(mn, t[i-k]);
  			mx = max(mx, t[i] - mn);
  		}
  		
  		if(mx > 0) L = m;
  		else R = m;
  	}
  	
  	cout << L << "\n";
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