// Problem: G. Path Queries
// Contest: Codeforces - Codeforces Round #582 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1213/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Parsed on: 26-12-2020 13:17:56 IST (UTC+05:30)
// Author: kapil_choudhary

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
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
const ll inf = 1e18;

vector<pair<ll, pll>> g; // edge list representation of graph
vll dsu_parent(200001); // for DSU
vll dsu_size(200001); // for DSU
// map[key] will store the count of all such pairs (u, v) such that
// the among all the edges in the path from u to v there will be at least 
// 1 edge with weight = key & all other edges will have weight <= key
map<ll, ll> cnt;
ll n, m; 

void init_dsu() {
	for(ll i = 1; i <= n; i++) {
		dsu_parent[i] = i;
		dsu_size[i] = 1;
	}
}

ll dsu_find(ll v) {
	if(dsu_parent[v] == v) return v;
	return dsu_parent[v] = dsu_find(dsu_parent[v]);
}

// slightly modified this according to our need
ll dsu_union(ll a, ll b) {
	ll s1 = dsu_find(a);
	ll s2 = dsu_find(b);
	
	ll tmp = 0;
	if(s1 != s2) {
		tmp = dsu_size[s1] * dsu_size[s2];
		if(dsu_size[s1] < dsu_size[s2]) swap(s1, s2);
		dsu_parent[s2] = s1;
		dsu_size[s1] += dsu_size[s2];
	}
	
	return tmp;
}

void solve()
{
  	cin >> n >> m;
  	for(ll i = 0; i < (n - 1); i++) {
  		ll u, v, w; cin >> u >> v >> w;
  		g.pb({w, {u, v}});
  	}
  	
  	init_dsu();
  	
  	sort(g.begin(), g.end());
  	for(auto edge: g) {
  		 ll s1 = dsu_find(edge.S.F);
  		 ll s2 = dsu_find(edge.S.S);
  		
  		if(s1 != s2) {
  			cnt[edge.F] += dsu_union(edge.S.F, edge.S.S);
  		}
  	}
  	
  	// doing prefix sum
  	ll prev_val = 0;
  	vpll v;
  	for(auto p: cnt) {
  		v.pb({p.F, p.S + prev_val});
  		prev_val += p.S;
  	}
  	
  	while(m--) {
  		ll q; cin >> q;
  		pll tmp = {q, inf};
  		
  		auto it = upper_bound(v.begin(), v.end(), tmp);
  		if(it == v.begin()) cout << 0 << " ";
  		else --it, cout << it->S << " ";
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