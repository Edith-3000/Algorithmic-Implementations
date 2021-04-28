// Explanation Link: https://www.geeksforgeeks.org/sum-of-minimum-elements-of-all-subarrays/

/*********************************************************************************************************/

// Problem: B - Minimum Sum
// Contest: AtCoder - AtCoder Grand Contest 005
// URL: https://atcoder.jp/contests/agc005/tasks/agc005_b
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 23-01-2021 18:57:13 IST (UTC+05:30)
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
  	ll n; cin >> n;
  	vll v(n);
  	for(ll i = 0; i < n; i++) cin >> v[i];
  	
  	vll left(n, 0), right(n, 0);
  	stack<pll> st1, st2;
  	
  	// Filling left[]
  	for(ll i = 0; i < n; i++) {
  		ll cnt = 1;
  		while(!st1.empty() && st1.top().F > v[i]) {
  			cnt += st1.top().S;
  			st1.pop();
  		}
  		
  		st1.push({v[i], cnt});
  		left[i] = cnt;
  	}
  	
  	// Filling right[]
  	for(ll i = (n - 1); i >= 0; i--) {
  		ll cnt = 1;
  		while(!st2.empty() && st2.top().F >= v[i]) {
  			cnt += st2.top().S;
  			st2.pop();
  		}
  		
  		st2.push({v[i], cnt});
  		right[i] = cnt;
  	}
  	
  	vll tmp(n);
  	for(ll i = 0; i < n; i++) tmp[i] = left[i] * right[i] * v[i];
  	
  	cout << accumulate(tmp.begin(), tmp.end(), 0LL) << "\n";
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