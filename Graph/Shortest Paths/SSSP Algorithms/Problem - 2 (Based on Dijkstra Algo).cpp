// References: https://atcoder.jp/contests/abc192/editorial/764
//             https://www.youtube.com/watch?v=UgXSqN82P-A
/************************************************************************************************************/

// Problem: E - Train
// Contest: AtCoder - AtCoder Beginner Contest 192
// URL: https://atcoder.jp/contests/abc192/tasks/abc192_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Parsed on: 22-02-2021 20:19:24 IST (UTC+05:30)
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

const ll INF = LLONG_MAX;
const int mod = 1e9+7;

struct Edge {
	ll source, destination, time, interval;
	Edge(ll s, ll d, ll t, ll i) 
		: source(s), destination(d), time(t), interval(i) { }
};

vector<vector<Edge>> g;
ll n, m, x, y;

ll dijkstra() {
	vll distance(n, INF);
	distance[x] = 0;
	
	priority_queue<pll, vpll, greater<pll>> q;
	q.emplace(0, x);
	
	while(!q.empty()) {
		const auto [closest_distance, closest_vertex] = q.top();
		if(closest_vertex == y) {
			return closest_distance;
		}
		
		q.pop();
		
		if(closest_distance < INF) {
			if(distance[closest_vertex] == closest_distance) {
				for(const auto &[source, adjacent, edge_length, interval]: g[closest_vertex]) {
					ll time = ((closest_distance + interval - 1) / interval) * interval + edge_length;
					
					if(distance[adjacent] > time) {
						distance[adjacent] = time;
						q.emplace(distance[adjacent], adjacent);
					}
				}
			}
		}
		
		else break;
	}
	
	return -1;
}

void solve()
{
  	g.clear();  	
  	cin >> n >> m >> x >> y;
  	--x; --y;
  	g.resize(n);
  	
  	for(ll i = 0; i < m; i++) {
  		ll source, destination, time, interval;
  		cin >> source >> destination >> time >> interval;
  		--source; --destination;
  		g[source].emplace_back(source, destination, time, interval);
  		g[destination].emplace_back(destination, source, time, interval);
  	}
  	
  	cout << dijkstra() << "\n";
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

// Time complexity: O(N + M * log(N)) 