// Reference(s): https://www.youtube.com/watch?v=TSUvGqRFlug
//               https://codeforces.com/blog/entry/76352
/************************************************************************************************************/

// Problem: D. Constant Palindrome Sum
// Contest: Codeforces - Codeforces Round #636 (Div. 3)
// URL: https://codeforces.com/contest/1343/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 03-02-2021 23:22:09 IST (UTC+05:30)
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
  	
  	vpii pairs(n/2);
  	for(int i = 0; i < n/2; i++) {
  		pairs[i].F = min(v[i], v[n-i-1]);
  		pairs[i].S = max(v[i], v[n-i-1]);	
  	}
  	
  	// map is used to store the #pairs with sum = 'key' of map
  	unordered_map<int, int> mp; 
  	
  	// pre[i] stores #pairs which require 0 or 1 change to make 
  	// their sum = i and we know this sum can range from i = 2 to i = 2 * k
  	vi pre(2 * k + 2, 0);
  	for(auto p: pairs) {
  		int l = p.F + 1;
  		int r = p.S + k;
  		mp[p.F + p.S]++;
  		pre[l] += 1;
  		pre[r+1] -= 1;
  	}
  	
  	for(int i = 2; i <= 2 * k; i++) {
  		pre[i] += pre[i-1];
  	}
  	
  	// max #changes we could need to change in worst case
  	int res = n;
  	
  	// traversing over all the possible values which
  	// 'x' can attain, finding the changes required in that
  	// 'x' and taking overall minimum
  	for(int x = 2; x <= 2 * k; x++) {
  		// cnt0 = #pairs which require 0 change to make their sum = x
  		int cnt0 = mp[x];
  		
  		// cnt1 = #pairs which require 1 change to make their sum = x
  		int cnt1 = pre[x] - cnt0;
  		
  		// cnt2 = #pairs which require 2 changes to make their sum = x
  		int cnt2 = (n/2) - cnt0 - cnt1;
  		
  		// cnt = #elements which require to be changeed to make
  		// the pairs sum = x
  		int cnt = cnt1 + (2 * cnt2);
  		
  		// taking overall minimum
  		res = min(res, cnt);
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