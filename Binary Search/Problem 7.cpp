// Problem: D - Base n
// Contest: AtCoder - AtCoder Beginner Contest 192
// URL: https://atcoder.jp/contests/abc192/tasks/abc192_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Parsed on: 22-02-2021 17:04:48 IST (UTC+05:30)
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
 
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
 
bool possible(ll base, vi &v, ll m) {
  ll val = 0;
  for(int i = 0; i < (int)v.size(); i++) {
    if(val > (m - v[i]) / base) return 0;
    val = val * base + v[i];
    if(val > m) return 0;
  }
  
  return 1;
}
 
void solve()
{
    string x; ll m;
    cin >> x >> m;
    
    vi v;
    for(int i = 0; i < (int)x.length(); i++) {
      v.pb(x[i] - '0');
    }
    
    int d = *max_element(v.begin(), v.end());
    
    if(v.size() == 1) {
      if(d > m) cout << 0 << "\n";
      else cout << 1 << "\n";
      return;
    }
    
    ll L = d + 1, R = m + 1;
    while(L + 1 < R) {
      ll mid = L + ((R - L) >> 1);
      if(possible(mid, v, m)) L = mid;
      else R = mid;
    }
    
    if(possible(L, v, m)) cout << L - d << "\n";
    else cout << 0 << "\n";
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