// Approach: https://www.youtube.com/watch?v=kZfm68XKC58&list=PL2S6Mj7iLqEjNVq0e-pZ9rSnpAacHzVm3&index=18
//           https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html
/*********************************************************************************************************/

// Problem: Cycle Finding
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1197
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 01-03-2021 21:50:02 IST (UTC+05:30)
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

struct triplet {
	ll first;
	ll second;
	ll third;
};

vector<triplet> edges;
vll d;
vi relaxant;
int n, m;

void bellman_ford() {
	// the vertex which was relaxed last in a relaxation iteration
	int x;
	
	for(int i = 1; i <= n; i++) {
		x = -1;
		for(auto ed: edges) {
			ll u = ed.first;
			ll v = ed.second;
			ll wt = ed.third;
			
			if(d[u] + wt < d[v]) {
				d[v] = d[u] + wt;
				relaxant[v] = u;
				x = v;
			}
		}
	}
	
	// If in the nth relaxation iteration, no vertex was relaxed,
	// then no cycle present
	if(x == -1) cout << "NO\n";
	
	else {
		for(int i = 1; i <= n; i++) {
			x = relaxant[x];
		}
		
		vector<int> cycle;
		for(int v = x; ; v = relaxant[v]) {
			cycle.pb(v);
			if(v == x and cycle.size() > 1) break;
		}
		
		reverse(cycle.begin(), cycle.end());
		
		cout << "YES\n";
		for(auto v: cycle) cout << v << " ";
		cout << "\n"; 
	}
}

void solve()
{
  	cin >> n >> m;
  	
  	edges.resize(m);
  	d.resize(n + 1);
  	
  	relaxant.resize(n + 1);
  	for(int i = 0; i <= n; i++) relaxant[i] = -1;
  	
  	for(int i = 0; i < m; i++) {
  		struct triplet x;
  		cin >> x.first >> x.second >> x.third;
  		edges.pb(x);
  	}
  	
  	// In this algorithm, 0 (a vertex not present in the graph)
  	// is taken as source & it's initial distance from all other
  	// vertices is taken = 0
  	// This concept is beautifully explained in this video --->
  	// https://www.youtube.com/watch?v=kZfm68XKC58&list=PL2S6Mj7iLqEjNVq0e-pZ9rSnpAacHzVm3&index=18
  	for(int i = 0; i <= n; i++) d[i] = 0LL;
  	
  	bellman_ford();
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