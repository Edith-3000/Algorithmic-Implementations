// Prob: https://leetcode.com/problems/shortest-cycle-in-a-graph/description/

/******************************************************************************************************************************************************************/

/* # One point to note in this problem is that, we can't find length of all the cycles in the given graph and then 
     take the minimum length. This is because finding out length of all cycles cannot be solved in polynomial time.

     https://stackoverflow.com/questions/12367801/finding-all-cycles-in-undirected-graphs
*/

/******************************************************************************************************************************************************************/

// METHOD - 1
// Ref: https://www.youtube.com/watch?v=_OMkeb3oTks&ab_channel=codingMohan

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())
#define vset(v, n, val) v.clear(); v.resize(n, val)

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(queue <T> v);
template <class T> void _print(priority_queue <T> v);
template <class T> void _print(stack <T> s);

// modify it's definition below as per need such as it can be used for STL containers with custom args passed
template <class T> void _print(T v); 

template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(multimap <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.front()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(priority_queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(stack <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(T v) {  }

/*******************************************************************************************************************************************************************/

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// to store the input graph
vector<set<int>> g;

// n = #vertices, m = #edges
int n, m;

vi sssp_by_bfs(int src) {
    // to store the distance of all vertices from src vertex, it'll also be used to
    // check if a vertex is already visited or not
    vi d(n);
    
    // initialising the distances of all nodes from src as infinity (i.e. very large)
    for(int i = 0; i < n; i++) d[i] = INF;
    
    // the minimum distance of src from itself = 0
    d[src] = 0;
    
    // queue to remember which vertex to visit next in case of dead end in iteration
    queue<int> q;
    
    // initialisation of the bfs process pushing the src in queue
	q.push(src);
    
    // iterative process
	while(!q.empty()) {
		// taking out vertex from q
	    int cur = q.front();
	    
	    // popping out this vertex cur from q
    	q.pop();
       
		// visiting all the adjacent vertices of v
       	for(auto nbr: g[cur]) {
        	// check if nbr is visited for the first time or not
        	if(d[nbr] == INF) {
        		// update the distance from src i.e. d[child] = d[parent] + 1
        		d[nbr] = d[cur] + 1;
        		
        		// push it in the queue
             	q.push(nbr);
        	}
		}
	}
        
    return d;
}

int shortest_cycle_length(vvi &edges) {
	// base case(s)
	if(m == 0) return -1;
	
	g.clear();
	g.resize(n);
	
	for(auto e: edges) {
		int x = e[0], y = e[1];
		g[x].insert(y);
		g[y].insert(x);
	}
	
	int res = INF;
	
	for(auto e: edges) {
		int x = e[0], y = e[1];
		
		// remove the current edge
		g[x].erase(y);
		g[y].erase(x);
		
		vi dist = sssp_by_bfs(x);
		
		res = min(res, dist[y] + 1);
		
		// stitch back the removed edge
		g[x].insert(y);
		g[y].insert(x);
	}
	
	if(res == INF) res = -1;
	
	return res;
}

void solve()
{
  	cin >> n >> m;
  	
  	vvi edges(m, vi(2));
  	for(int i = 0; i < m; i++) {
  		cin >> edges[i][0] >> edges[i][1];
  	}
  	
  	int res = shortest_cycle_length(edges);
  	
  	cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
    // #endif
    
    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}

/******************************************************************************************************************************************************************/

// METHOD - 2

// Ref: https://www.geeksforgeeks.org/shortest-cycle-in-an-undirected-unweighted-graph/