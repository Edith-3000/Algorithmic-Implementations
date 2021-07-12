/* # Caution: This problem can't be solved greedily always.
   # Approach ---> 
     In the usual Dijkstra’s algorithm we set the distance to the source initially to 0 and the distance to all 
     other vertices to infinity, and we repeatedly select the best edge such that its weight plus the distance 
     to its source is as MINIMUM as possible.
     For this problem, you set the probability to the source initially to 1 (since there is 100% probability of 
     reaching the source without getting caught), the probability to all other vertices to DBL_MIN, and 
     repeatedly select the best edge such that its probability times the probability of reaching its source is 
     as MAXIMUM as possible. All other details go as usual.
*/

// A similar approach but slightly different implementation of the idea can be found at ---->
// https://ide.codingblocks.com/s/187184?_ga=2.201122214.922549758.1608786049-317025203.1608553080

// Problem: 106 miles to Chicago
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/CHICAGO/
// Memory Limit: 1536 MB
// Time Limit: 5000 ms
// Parsed on: 29-12-2020 12:25:06 IST (UTC+05:30)
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

unordered_map<int, list<pair<int, double>>> g;
set<pair<double, int>, greater<pair<double, int>>> s;
unordered_map<int, double> dis;
int n, m;

void modified_dijkstra() {
	for(int i = 1; i <= n; i++) dis[i] = DBL_MIN;
	dis[1] = 1.0; // 1 is the source 
	s.insert({dis[1], 1});
	
	while(!s.empty()) {
		int curr = s.begin()->S;
		double d = s.begin()->F;
		s.erase(s.begin());
		
		for(auto x: g[curr]) {
			if((d * x.S) > dis[x.F]) {
				auto it = s.find({dis[x.F], x.F});
				if(it != s.end()) s.erase(it);
				s.insert({d * x.S, x.F});
				dis[x.F] = d * x.S;
			}
		}
	}
}

void solve()
{
  	g.clear(); // clear the graph of previous test case
  	for(int i = 0; i < m; i++) {
  		int u, v, p; cin >> u >> v >> p;
  		// converting p into double & <= 1 (as p is given in percentage)
  		g[u].pb({v, (p * 1.0)/100}); 
  		g[v].pb({u, (p * 1.0)/100});
  	}
  	
  	modified_dijkstra();
  	dis[n] *= 100;
  	cout << fixed << setprecision(6) << dis[n] << " percent\n";
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
    while(true) {
      cin >> n; 
      if(n == 0) break;
      cin >> m;
      solve();
    }

    return 0;
}