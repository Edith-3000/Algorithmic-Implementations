// Editorial: https://codeforces.com/blog/entry/72132
/***************************************************************************************************/

// Problem: E. Nearest Opposite Parity
// Contest: Codeforces - Codeforces Round #605 (Div. 3)
// URL: https://codeforces.com/contest/1272/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 24-03-2021 10:23:31 IST (UTC+05:30)
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

int n;
vi v;
vvi g;
vi odd, even;
vi res;

void multi_src_bfs(const vi &start, const vi &end) {
	vi d(n, INF);
	queue<int> q;
	
	for(auto x: start) {
		d[x] = 0;
		q.push(x);
	}
	
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		
		for(auto to: g[v]) {
			if(d[to] == INF) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
	
	for(auto x: end) {
		if(d[x] != INF) {
			res[x] = d[x];
		}
	}
}

void solve()
{
  	cin >> n;
  	v = vi(n);
  	for(int i = 0; i < n; i++) {
  		cin >> v[i];
  		if(v[i] & 1) odd.pb(i);
  		else even.pb(i);
  	}
  	
  	g = vvi(n);
  	for(int i = 0; i < n; i++) {
  		int lf = i - v[i];
  		int rg = i + v[i];
  		if(lf >= 0) g[lf].pb(i);
  		if(rg < n) g[rg].pb(i);
  	}
  	
  	res = vi(n, -1);
  	
  	multi_src_bfs(odd, even);
  	multi_src_bfs(even, odd);
  	
  	for(auto x: res) cout << x << " ";
  	cout << "\n";
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