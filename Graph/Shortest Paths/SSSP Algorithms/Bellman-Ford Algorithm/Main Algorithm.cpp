/* # Reference: https://brilliant.org/wiki/bellman-ford-algorithm/
			    https://cp-algorithms.com/graph/bellman_ford.html
                https://www.youtube.com/watch?v=0vVofAhAYjc&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=42&ab_channel=takeUforward

     Intuition: https://www.youtube.com/watch?v=75yC1vbS8S8&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=29
   
   # This algorithm is DP based.

   # It is a graph search algorithm that finds the shortest path between a given source vertex and all other
     vertices in the graph. This algorithm can be used on both weighted and unweighted graphs and also on 
     DG & UG.

   # Like Dijkstra's shortest path algorithm, the Bellman-Ford algorithm is also guaranteed to find the 
     shortest path in a graph. 
   # Though it is slower than Dijkstra's algorithm (Time Complexity: O(V + (E x log(V))), Bellman-Ford 
     (Time Complexity: O(V x E)) is capable of handling graphs that contain negative edge weights, so it is 
     more versatile. 

   # It is worth noting that if there exists a negative cycle in the graph, then there is no shortest path. 
     As Going around the negative cycle an infinite number of times would continue to decrease the cost of the 
     path (even though the path length is increasing). 
     Because of this, Bellman-Ford can also detect negative cycles which is a useful feature.

   # AN UG CAN BE CONVERTED IN A DG, AND SO IF AN UG CONTAINS A -VE WEIGHT EDGE, THEN BASICALLY WE CAN SAY THAT
     IT'S A -VE WEIGHT CYCLE AND HENCE NO SHORTEST PATH EXISTS.

   # Simple algorithm ---->
     1. Mark the dist[src] = 0 (from itself) 
        and dist[all other vertices from src] = infinity
     
     2. If we consider the #vertices = n and #edges = m
        then we just have to relax m edges (n-1) times for worst case.

        i.e. for(int i = 1; i <= n-1; i++) {
                 for(int j = 1; j <= m; j++) {
                     relax the jth edge
                 }
             }
        
        NOTE: The edges can be taken in any order.

   # Unlike many other graph algorithms, for Bellman-Ford algorithm, it is more convenient to represent the 
     graph using a single list of all edges (instead of n lists of edges - edges from each vertex) i.e. 
     edge list representation.

   # Bellman-Ford algorithm returns SSSP (Single Source Shortest Path) in ((|V| - 1) x |E|) operations,
     when no negative cycles present in graph.

   # Bellman-Ford algorithm resolves negative cycle SSSP (Single Source Shortest Path) in (2 x (|V| - 1) x |E|) 
     operations, when negative cycles are present in graph.
*/

/*************************************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())

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
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

/*******************************************************************************************************************************************************************/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// to store the input edges
vvi edges;

// n = #nodes, m = #edges in the input graph
int n, m;

void bellman_ford(int src) {
    // d[i] stores the minimum distance of ith node from given src
    vi d(n);
      
    // parent[i] stores the immediate parent of ith node in the 
    // shortest path from src to this node
    vi parent(n, -1);
    
    // initialising the distances of all nodes from src as infinity
    for(int i = 0; i < n; i++) d[i] = INT_MAX;
    
    // the minimum distance of src from itself = 0
    d[src] = 0;
    
    // relax all the m edges (n-1) times
    for(int i = 1; i < n; i++) {
        for(auto edg: edges) {
            int u = edg[0], v = edg[1], w = edg[2];
          
            // to avoid overflow check d[u] != INT_MAX
            if((d[u] != INT_MAX) and ((d[u] + w) < d[v])) {
                d[v] = d[u] + w;
                parent[v] = u;
            }
        }
    }
    
    // to check if there is -ve weight cycle in the graph, 
    // (if after (n-1) iterations any relaxation is performed, then -ve weight cycle is present)
    bool neg_cycle = 0;
    
    for(auto edg: edges) {
        int u = edg[0], v = edg[1], w = edg[2];
        
        // to avoid overflow check d[u] != INT_MAX
        if((d[u] != INT_MAX) and ((d[u] + w) < d[v])) {
            neg_cycle = 1;
            break;
        }
    }
    
    if(neg_cycle) {
        cout << "-ve weight cycle present.\n";
        return;
    }
    
    // in case you need the shortest path for each node
    vvi path;
    
    for(int i = 0; i < n; i++) {
        vi tmp;
        int cur = i;
        
        while(cur != -1) {
            tmp.pb(cur);
            cur = parent[cur];
        }
        
        reverse(tmp.begin(), tmp.end()); 
        path.pb(tmp);
    }
}

void solve()
{
    cin >> n >> m;
    
    edges.clear(); 
    
    // 0-based vertices
    // NOTE: here input is taken for a directed graph, but an undirected graph can
    //       also be taken in form of a directed graph
    
    for(int i = 0; i < m; i++) {
        int x, y, wt; 
        cin >> x >> y >> wt;
        edges.pb({x, y, wt});
    }
    
    // source from which shortest path to each node to be calculated
    int src; cin >> src;
    
    bellman_ford(src);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

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

// Time Complexity: O(|V| x |E|)