/* Problem description --->

A group of hackers want hack a network connecting n cities. The network is such that there may or may not be a 
direct communication between two cities. But there is always a way to communicate from any city u to any other 
city v through a series of connections(For example, if the city 1 is directly connected to city 2 and city 2 is
directly connected to city 3, then city 1 can communicate with city 3 through city 2). There is a hacker in each
of the n cities. They wanted to block some of the connections for hacking, also they want to remain connected 
through network, i.e. after blocking some connections, still there should be a way of communication from every 
city of every other city so that hackers can communicate.
Hackers know that there is a cost associated with each direct connection. Since they have a limited amount of
money, s, they want block as many connections as they can. Help them find the number of connections they can 
block.

Input Format --->
First line contains n, m and s, denoting the number of cities, number of direct connections, and the amount of 
money hackers have. Next m lines contains 3 integers each, u, v and c, denoting that there is a direct connection 
between node u and node v and the cost of breaking this connection is c.

Constraints --->
1 <= s
c <= 10^12 
1 <= n <= 50000, 1<=m<=100000 
1 <= u, v <= n, edges are unique, and there is no self loop.

Output Format --->
On the first line, print the number of connections hackers can block, w and the minimum cost of blocking, c. 
Note that there can be multiple possible sets of w connections, which can be removed within the sum of costs, s. 
Consider that set, S, such that the total cost of blocking is minimum.

Sample Input --->
6 7 10
1 2 3
1 3 3
2 3 3
3 4 1
4 5 5
5 6 4
4 6 5

Sample Output --->
2 7

Explanation --->
After blocking the edge between node 1 and node 2, and node 5 and node 6, the cities are still connected, and 
the cost of blocking is minimum and less than the value of s.

*/

/* # The main idea is not to find the edges of "Minimum" Spanning Tree but to find the edges of the 
     "Maximum" Spanning Tree such that the cities still remain connected & sort the remaining edges of
     the graph in ascending order (according to their associated weight) & add weight of the edges till
     the sum of weight is <= s.

   # So basically in this problem we have to remove as many edges as we can such that the total cost of 
     removal is <= s and after removal of those edges the graph still remain connected. 
*/

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

vvll g; // edge list representation of graph (along with weight) i.e.{u, v, w}
ll n, m, s;

vll dsu_parent; // for DSU data structure
vll dsu_rank; // for DSU data structure

ll dsu_find(ll v) {
	if(dsu_parent[v] == -1) return v;
	return dsu_parent[v] = dsu_find(dsu_parent[v]);
}

void dsu_union(ll a, ll b) {
	ll s1 = dsu_find(a);
	ll s2 = dsu_find(b);
	
	if(s1 != s2) {
		if(dsu_rank[s1] < dsu_rank[s2]) swap(s1, s2);
		dsu_parent[s2] = s1;
		dsu_rank[s1] += dsu_rank[s2]; 
	}
}

// custom comparator function to sort vector of vectors
bool myComparator(const vll &v1, const vll &v2) {
	return v1[0] > v2[0];
}

void kruskal_algo() {
	sort(g.begin(), g.end(), myComparator);
	
	// don't use range based for loop here, as it will not
	// change the edge wt to -1 in the original graph g
	for(int i = 0; i < g.size(); i++) {
		ll s1 = dsu_find(g[i][1]);
		ll s2 = dsu_find(g[i][2]);
		
		if(s1 != s2) {
			dsu_union(g[i][1], g[i][2]);
			
			// now to indicate that this edge has been included in the MST
			// we make the weight of this edge as -1
			g[i][0] = -1; 
		}
	}
}

void solve()
{
  	cin >> n >> m >> s;
  	dsu_parent.assign(n + 1, -1);
  	dsu_rank.assign(n + 1, 1);
  	for(int i = 0; i < m; i++) {
  		ll u, v, w; cin >> u >> v >> w;
  		g.pb({w, u, v});
  	}
  	
  	kruskal_algo();
  	
  	ll cnt = 0, sum = 0;
  	for(int i = g.size() - 1; i >= 0; i--) {
  		if(g[i][0] == -1) continue;
  		if((sum + g[i][0]) <= s) {
  			cnt++; 
  			sum += g[i][0];
  		}
  	}
  	
  	cout << cnt << " " << sum << "\n";
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