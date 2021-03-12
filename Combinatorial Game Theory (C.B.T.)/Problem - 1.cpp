// Ref: https://www.youtube.com/watch?v=tooKfDF6Wfo&list=PLVi2hvR1g9YYeTxArGAtxS7hPCWOLKoFq&index=4
//      https://www.youtube.com/watch?v=X8G-_gwSfQY
/**************************************************************************************************/

// Problem: D. Let's Go Hiking
// Contest: Codeforces - Codeforces Round #706 (Div. 2)
// URL: https://codeforces.com/contest/1496/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 12-03-2021 15:21:29 IST (UTC+05:30)
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
  	
  	vi left(n, 0); // to find out the longest monotone(increasing) segment from left
  	vi right(n, 0); // to find out the longest monotone(increasing) segment from right
  	
  	int mx = 0;
  	for(int i = 1; i < n; i++) {
  		if(v[i] > v[i-1]) {
  			left[i] = left[i-1] + 1;
  			mx = max(mx, left[i]);
  		}
  	}
  	
  	for(int i = n - 2; i >= 0; i--) {
  		if(v[i] > v[i+1]) {
  			right[i] = right[i+1] + 1;
  			mx = max(mx, right[i]);
  		}
  	}
  	
  	int peaks = 0;
  	for(int i = 0; i < n; i++) {
  		if(left[i] == mx) peaks++;
  		if(right[i] == mx) peaks++;
  	}
  	
  	if(peaks > 2) cout << 0 << "\n";
  	else {
  		int res = 0;
  		
  		for(int i = 0; i < n; i++) {
  			if(left[i] == mx and right[i] == mx and mx % 2 == 0) res++;
  		}
  		
  		cout << res << "\n";
  	}
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