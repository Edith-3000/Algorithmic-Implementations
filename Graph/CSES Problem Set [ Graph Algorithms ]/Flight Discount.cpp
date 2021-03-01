// Problem: Flight Discount
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1195
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 01-03-2021 13:39:17 IST (UTC+05:30)
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

const ll INF = 1e17;
const int mod = 1e9+7;

// input graph
vector<vpll> g;

// disc[i] = the minimum cost to reach city i, given we
// have used the coupon before reaching this city
vll disc;

// full[i] = the minimum cost to reach city i, given we
// have not used the coupon before reaching this city
vll full;

int n, m;

void dijkstra() {
	priority_queue<pair<ll, pair<int, bool>>,
				   vector<pair<ll, pair<int, bool>>>,
				   greater<pair<ll, pair<int, bool>>>> q;
				   
	for(int i = 2; i <= n; i++) {
		disc[i] = INF;
		full[i] = INF;
	}
	
	// initially in any case we are at city 1, so no cost
	// to reach there
	disc[1] = full[1] = 0;
	
	q.push({0, {1, 0}});
	
	while(!q.empty()) {
		ll d = q.top().F;
		ll cur = q.top().S.F;
		bool is_used = q.top().S.S;
		q.pop();
		
		if(is_used and disc[cur] != d) continue;
		if(!is_used and full[cur] != d) continue;
		
		for(auto x: g[cur]) {
			int nbr = x.F;
			ll w = x.S;
			
			// if coupon is already availed
			if(is_used) {
				if(d + w < disc[nbr]) {
					disc[nbr] = d + w;
					q.push({disc[nbr], {nbr, 1}});
				}
			}
			
			// if coupon is not availed yet
			// So, 2 choices: 1. avail it now 
			//                2. save it for future
			else {
				// try to save coupon for future
				if(d + w < full[nbr]) {
					full[nbr] = d + w;
					q.push({full[nbr], {nbr, 0}});
				}
				
				// availing the coupon now
				if(d + (w / 2) < disc[nbr]) {
					disc[nbr] = d + (w / 2);
					q.push({disc[nbr], {nbr, 1}});
				}
			}
		}		
	}
	
}

void solve()
{
  	cin >> n >> m;
  	
  	g.resize(n + 1);
  	disc.resize(n + 1);
  	full.resize(n + 1);
  	
  	for(int i = 0; i < m; i++) {
  		int u, v, wt; cin >> u >> v >> wt;
  		g[u].pb({v, wt});
  	}
  	
  	dijkstra();
  	
  	cout << disc[n] << "\n";
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