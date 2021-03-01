// Problem: High Score
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1673
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 01-03-2021 09:35:07 IST (UTC+05:30)
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

// const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

const ll INF = 1e17;
const ll NINF = (-1) * INF;

struct triplet {
	ll first;
	ll second;
	ll third;
};

vector<triplet> edges;
vll d;

int n, m;

void bellman_ford() {
	// I. Bellman-Ford::Propagation phase
	for(int i = 1; i < n; i++) {
		for(auto ed: edges) {
			ll u = ed.first;
			ll v = ed.second;
			ll wt = ed.third;
			
			if(d[u] == INF) continue;
			d[v] = min(d[v], d[u] + wt);
			d[v] = max(d[v], NINF);
		}
	}
	
	// II. Bellman-Ford::Negative cycle resolution phase,
	//     to find out the vertices which are affected by -ve cycles
	for(int i = 1; i < n; i++) {
		for(auto ed: edges) {
			ll u = ed.first;
			ll v = ed.second;
			ll wt = ed.third;
			
			if(d[u] == INF) continue;
			d[v] = max(d[v], NINF);
			if(d[u] + wt < d[v]) d[v] = NINF;
		}
	} 
}

void solve()
{
  	cin >> n >> m;
  	edges.resize(m);
  	d.resize(n + 1);
  	
  	for(int i = 0; i < m; i++) {
  		struct triplet x;
  		cin >> x.first >> x.second >> x.third;
  		
  		// since we have to find "Single Source LONGEST  Path" from
  		// "Single Source SHORTEST Path" algorithm, we multiply edge
  		// weight by -1
  		x.third *= (-1);
  		
  		edges.pb(x);
  	}
  	
  	d[1] = 0;
  	for(int i = 2; i <= n; i++) d[i] = INF;
  	
  	bellman_ford();
  	
  	if(d[n] == NINF) cout << -1 << "\n";
  	else cout << d[n] * (-1) << "\n";
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