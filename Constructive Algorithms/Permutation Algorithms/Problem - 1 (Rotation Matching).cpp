// Reference(s): https://codeforces.com/blog/entry/78504
//               https://www.youtube.com/watch?v=LrcbXJdqKuE&list=PL2q4fbVm1Ik5HC7D3gUwc8cqwDtvOaqke&index=9

/************************************************************************************************************/

// Problem: C. Rotation Matching
// Contest: Codeforces - Codeforces Round #648 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1365/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 02-02-2021 21:15:27 IST (UTC+05:30)
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
  	int a[n+1], b[n+1], pos[n+1];
  	for(int i = 1; i <= n; i++) {
  		cin >> a[i];
  		pos[a[i]] = i;
  	}
  	
  	for(int i = 1; i <= n; i++) cin >> b[i];
  	
  	// the key of the map is the #cyclic shifts
  	// value of the map are the #elements which require 'key' cyclic shifts
  	// to be at their correct position
  	map<int, int> offset;
  	
  	for(int i = 1; i <= n; i++) {
  		int p = pos[b[i]];
  		offset[(p - i + n) % n]++;
  	}
  	
  	int res = 0;
  	for(auto x: offset) res = max(res, x.S);
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