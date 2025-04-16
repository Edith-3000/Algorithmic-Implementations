// NOTE: THIS PROBLEM IS NOT UNDERSTOOD BY ME COMPLETELY

/* Problem description --->

Sakshi & Art --->
Sakshi is an artist. She is given a task to draw a figure with some basic specifications on a sheet. 
Specifications of the figure is given by m lines. Each line contains four integers, x1, y1, x2, y2, denoting 
that there is a line to be drawn between points (x1, y1), (x2, y2). She can add some more specifications according
to her needs. Sakshi wants to draw it in a creative manner. She wants to draw the whole figure in one stroke of 
her pen, i.e. if the pen is at point (x1, y1) and she wants to reach point (x2, y2), then there must be a series 
of lines(or a single line) connecting points (x1, y1) and (x2, y2).
Origin is the bottom left corner of the sheet. Find out the minimum number of lines to be added in the 
specifications of the figure in order to draw the figure in a single stroke of her pen.

Note: Drawing a line which is already drawn, doubles the width of line and thus it can be added to specifications, 
      i.e. if a line is drawn again, it is treated as a distinct line in the specifications. 
      Also, in the given specifications, no three points are collinear.

Input Format --->
First line contains contains a single integer m, denoting the number of basic specifications. 
Next m lines contains four integers, x1, y1, x2, y2 each, denoting that there is a line between points 
(x1, y1), (x2, y2).

Constraints --->
1 <= m <= 10^5 
1 <= x1, y1, x2, y2 <= 10^9

Output Format --->
Print a single integer denoting the minimum number of lines to be added in the specifications of the figure.

Sample Input --->

2
1 1 2 1
2 2 1 2

Sample Output --->
1

Explanation --->
Sakshi can add the line between point (2,2) and (1,1). Sakshi will now start at point (2,1). She will draw lines 
in the following way: (2,1)->(1,1) (1,1)->(2,2) (2,2)->(1,2) In this way figure is complete.

*/

// Explanation link: https://discuss.codingblocks.com/t/one-test-case-not-passing/27949/2

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

map<int, list<int>> g;
map<int, int> vis;

int dfs(int curr) {
	vis[curr] = 1;
	int count = g[curr].size() % 2;
	for(auto x: g[curr]) {
		if(!vis[x]) {
			count += dfs(x);
		}
	}
	
	return count;
}

void solve()
{
  	int m; cin >> m;
  	for(int i = 0; i < m; i++) {
  		int u, v;
  		cin >> u >> v;
  		g[u].pb(v);
  		g[v].pb(u);
  	}
  	
  	int comp = 0; // to count the #connected components
  	int odd = 0; // to count the total vertices with odd degree in all the components
  	
  	for(auto x: g) {
  		if(!vis[x.F]) {
  			comp++;
  			odd += dfs(x.F);
  		}
  	}
  	
  	cout << max(comp - 1, (odd - 1) / 2) << "\n";
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