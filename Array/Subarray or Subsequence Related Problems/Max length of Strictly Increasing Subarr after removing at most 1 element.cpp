// Ref: https://codeforces.com/blog/entry/72132
//      https://www.geeksforgeeks.org/maximum-length-of-strictly-increasing-sub-array-after-removing-at-most-one-element/
/*************************************************************************************************************************/

// Problem: D. Remove One Element
// Contest: Codeforces - Codeforces Round #605 (Div. 3)
// URL: https://codeforces.com/contest/1272/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 24-03-2021 10:58:04 IST (UTC+05:30)
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
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	if(n == 1) {
  		cout << 1 << "\n";
  		return;
  	}
  	
  	int res = 1;
  	
  	// rg[i] = the maximum length of the strictly increasing continuous 
  	//         sequence starting in the position i
  	vi rg(n, 1);
  	
  	for(int i = n - 2; i >= 0; i--) {
  		if(v[i+1] > v[i]) rg[i] = rg[i+1] + 1;
  		res = max(res, rg[i]);
  	}
  	
  	// lf[i] = the maximum length of the strictly increasing continuous 
  	//         sequence ending in the position i  	
  	vi lf(n, 1);
  	
  	for(int i = 1; i < n; i++) {
  		if(v[i] > v[i-1]) lf[i] = lf[i-1] + 1;
  		res = max(res, lf[i]);
  	}
  	
  	// If we remove the i-th element (where i = 1 to n−2), then we can 
  	// update the answer with the value lf[i-1] + rg[i+1], if v[i-1] < v[i+1].
  	for(int i = 1; i < (n - 1); i++) {
  		if(v[i-1] < v[i+1]) {
  			res = max(res, lf[i-1] + rg[i+1]);
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}