// Problem: Course Schedule
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1679
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 02-03-2021 09:11:35 IST (UTC+05:30)
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

vvi g;
vector<bool> vis;
set<int> ancestors;
vector<int> sorted;

bool possible;
int n, m;

void top_sort(int cur) {
	vis[cur] = 1;
	ancestors.insert(cur);
	
	for(auto x: g[cur]) {
		if(!vis[x]) top_sort(x);
		if(ancestors.find(x) != ancestors.end()) {
			possible = false;
			return;
		}
	}
	
	ancestors.erase(cur);
	sorted.pb(cur);
}

void visit_all() {
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
  			ancestors.clear();
  			top_sort(i);
		}
	}
}

void solve()
{
  	cin >> n >> m;
  	
  	g.resize(n + 1);
  	vis.assign(n + 1, 0);
  	possible = true;
  	
  	for(int i = 0; i < m; i++) {
  		int u, v; cin >> u >> v;
  		g[u].pb(v);
  	}
  	
  	visit_all();
  	
  	if(!possible) {
  		cout << "IMPOSSIBLE\n";
  		return;
  	}
  	
  	reverse(begin(sorted), end(sorted));
  	for(int i = 0; i < (int)sorted.size(); i++) {
  		cout << sorted[i] << " ";
  	}
  	
  	cout <<"\n";
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