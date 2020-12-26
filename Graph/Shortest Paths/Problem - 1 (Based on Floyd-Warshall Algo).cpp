/* # This problem could also have been solved by simply applying FLoyd-Warshall Algorithm but it could
     give TLE as well as MLE in some of the cases where n is very large.

   # Therefore 2 conditions have been used to avoid TLE & MLE.
*/

// Problem: F. K-th Path
// Contest: Codeforces - Codeforces Round #575 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1196/F
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// Parsed on: 26-12-2020 15:54:17 IST (UTC+05:30)
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

const ll INF = 1e18;
const int mod = 1e9+7;

ll n, m, k;

void solve()
{
  	cin >> n >> m >> k;
  	
  	// Case 1: if (k <= m), then definitely we'll get the kth shortest
  	// path from the first 'k' edges out of the total 'm' edges (sorted
  	// in ascending order of weight)
  	// in this case max number of unique vertices which we will be considering
  	// are (2 * k), there max nodes on which floyd warshall will run = 2 * 400 = 800
  	// Hence worst case operation will be (800)^3 = 512 * 10^6
  	if(k <= m) {
  		vector<pair<ll, pll>> v; // to store the edges & their weight
  		
  		// taking edges as input
  		for(ll i = 0; i < m; i++) {
  			ll x, y, w; cin >> x >> y >> w;
  			v.pb({w, {x, y}});
  		} 
  		
  		// sort edges acco. to weight
  		sort(v.begin(), v.end());
  		
  		// map to store which vertices are present in the 
  		// first 'k' edges
  		map<ll, ll> mp;
  		
  		for(ll i = 0; i < k; i++) {
  			mp[v[i].S.F] = 1;
  			mp[v[i].S.S] = 1;
  		}
  		
  		// co-ordinate compression of the vertices present in
  		// mp so that the d[][] matrix doesn't become of very
  		// large size, leading to Memory Limit Exceeded
  		ll id = 0;
  		for(auto p: mp) mp[p.F] = ++id;
  		
  		n = mp.size(); // no of vertices to be considered
  		
  		// initialisation of floyd warshall algo
  		ll d[n + 1][n + 1];
  		for(ll i = 1; i <= n; i++) {
  			for(ll j = 1; j <= n; j++) {
  				if(i == j) d[i][j] = 0; // dist of a vertex from itself
  				else d[i][j] = INF;
  			}
  		}
  		
  		// filling the actual distances of available edge
  		for(ll i = 0; i < k; i++) {
  			ll x = v[i].S.F, y = v[i].S.S;
  			if(mp.count(x) && mp.count(y)) {
  				d[mp[x]][mp[y]] = v[i].F;
  				d[mp[y]][mp[x]] = v[i].F;
  			}
  		}
  		
  		// running the floyd warshall algo
  		for(ll k = 1; k <= n; k++) {
  			for(ll i = 1; i <= n; i++) {
  				for(ll j = 1; j <= n; j++) {
  					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  				}
  			}
  		}
  		
  		vll t; // to store the shortest paths acco. to condition given in ques
  		for(ll i = 1; i <= n; i++) {
  			for(ll j = 1; j <= n; j++) {
  				if(i < j) t.pb(d[i][j]);
  			}
  		}
  		
  		sort(t.begin(), t.end());
  		// print the (k - 1)th path length (0-based indexing)
  		cout << t[k - 1] << "\n";
  	}
  	
  	// Case 2: if (k > m) => m < 400 => (n - 1) <= 400 => n <= 401
  	// therefore we can easily run floyd warshall as in this case n^3 =~ 64 * 10^6
  	else {
  		ll d[n + 1][n + 1];
  		for(ll i = 1; i <= n; i++) {
  			for(ll j = 1; j <= n; j++) {
  				if(i == j) d[i][j] = 0; // dist of a vertex from itself
  				else d[i][j] = INF;
  			}
  		}
  		
  		for(ll i = 0; i < m; i++) {
  			ll u, v, w; cin >> u >> v >> w;
  			d[u][v] = w;
  			d[v][u] = w;
  		}
  		
  		for(ll k = 1; k <= n; k++) {
  			for(ll i = 1; i <= n; i++) {
  				for(ll j = 1; j <= n; j++) {
  					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  				}
  			}
  		}
  		
  		vll t;
  		for(ll i = 1; i <= n; i++) {
  			for(ll j = 1; j <= n; j++) {
  				if(i < j) t.pb(d[i][j]);
  			}
  		}
  		
  		sort(t.begin(), t.end());
  		// print the (k - 1)th path length (0-based indexing)
  		cout << t[k - 1] << "\n";
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