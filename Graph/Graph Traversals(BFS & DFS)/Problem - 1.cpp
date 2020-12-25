/* Problem description --->

Vivek and Birthday Celebration --->

Vivek Sharma is an extremely miser person. He hates spending money on things, be it for his own good or bad. 
But this time his friends have caught up with him, and are demanding a huge birthday treat. 
But, Vivek is… well, Vivek.

He figured out that there is no way for him to save himself and his money now. So, he decided to treat as many 
friends as he can. But, he still thought that he could skip inviting those friends who don't have any dependency. 
That is to say that, let's say that he has N friends, and a friend Ai wouldn't come to the party if Aj is not 
invited. But, it's not necessary that the vice-versa is true.

Vivek wants to invite minimum number of friends to celebrate his birthday party to save money - help Vivek 
figure out the minimum number of friends he can invite while fulfilling their demands. He cannot have a 
party without any friend, so he HAS to take one friend with him, at least to celebrate his birthday, by the way.

Input Format --->
The first line will contain two integers, N and D, where N denotes the number of friends, while D denotes the
number of dependency relations. The next D lines will contain two integers, a and b - which would represent 
that friend a wouldn't come to the party until and unless friend b is also invited.

Constraints --->
1 <= N <= 1000 
1 <= D <= 1000 
1 <= a, b <= N, where a is NOT equal to b.

Output Format --->
Print the minimal number - minimum number of friends Vivek can invite while handling the demands and celebrating 
his birthday still.

Sample Input --->
3 3
1 2
2 3
3 1

Sample Output --->
3

*/

/* Main idea to solve the problem --->
   # For each pair (a, b), we add a connection from a to b i.e. we insert ‘b’ to the node[a]. Thus if ‘a’ is 
     selected ‘b’ would automatically be selected.
   
   # Now we take each node[i] and traverse through the connections till all the leaf nodes and count the total 
     nodes directly/indirectly connected to that particular node[i].

   # We find that node[i] which has the minimum number of connections.
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

vvi g;
vector<bool> vis;
int n, m, child, res;

void dfs(int curr) {
	vis[curr] = 1;
	for(auto x: g[curr]) {
		if(!vis[x]) {
			child++;
			dfs(x);
		}
	}
} 		

void solve()
{
  	cin >> n >> m;
  	g.clear(); 
  	g.resize(n + 1);

  	for(int i = 0; i < m; i++) {
  		int u, v;
  		cin >> u >> v;
  		g[u].pb(v); 
  	}
  	
  	res = INT_MAX;
  	for(int i = 1; i <= n; i++) {
  		child = 0;
  		vis.assign(n + 1, 0);
  		dfs(i);
  		res = min(res, child + 1);
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