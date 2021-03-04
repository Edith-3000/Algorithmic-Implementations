// Problem: Road Reparation
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1675
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Parsed on: 03-03-2021 20:51:48 IST (UTC+05:30)
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
vi dsu_parent;
vi dsu_rank;
int n, m;

int dsu_find(int v) {
	if(dsu_parent[v] == -1) return v;
	return dsu_parent[v] = dsu_find(dsu_parent[v]);
}

void dsu_union(int a, int b) {
	int s1 = dsu_find(a);
	int s2 = dsu_find(b);
	
	if(s1 != s2) {
		if(dsu_rank[s1] < dsu_rank[s2]) swap(s1, s2);
		dsu_parent[s2] = s1;
		dsu_rank[s1] += dsu_rank[s2];
	}
}

bool cmp(const vi &v1, const vi &v2) {
	return v1[0] < v2[0];
}

ll kruskals() {
	sort(g.begin(), g.end(), cmp);
	ll res = 0;
	
	for(int i = 0; i < m; i++) {
		int s1 = dsu_find(g[i][1]);
		int s2 = dsu_find(g[i][2]);
		
		if(s1 != s2) {
			res += g[i][0];
			dsu_union(g[i][1], g[i][2]);
		}
	}
	
	return res;
}

void solve()
{
  	cin >> n >> m;
  	
  	dsu_parent.assign(n + 1, -1);
  	dsu_rank.assign(n + 1, 1);
  	
  	for(int i = 0; i < m; i++) {
  		int u, v, wt; 
  		cin >> u >> v >> wt;
  		g.pb({wt, u, v});
  	}
  	
  	ll res = kruskals();
  	
  	int cnt = 0;
  	for(int i = 1; i <= n; i++) {
  		if(dsu_parent[i] == -1) cnt++;
  	}
  	
  	if(cnt != 1) {
  		cout << "IMPOSSIBLE\n";
  		return;
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