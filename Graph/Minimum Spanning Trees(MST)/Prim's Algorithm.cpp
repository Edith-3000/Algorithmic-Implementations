// Ref: https://www.youtube.com/watch?v=mJcZjjKzeqk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=45&ab_channel=takeUforward

/**************************************************************************************************************************************************************/

/* # UNDERLYING CONCEPTS ===>

   # Like Kruskal's algorithm, Prim's algorithm is also a Greedy algorithm.

   # Prim's algorithm is very similar to Kruskal's: whereas Kruskal's "grows" a forest of trees, Prim's algorithm 
     grows a single tree until it becomes the minimum spanning tree. 

   # Both algorithms use the greedy approach - they add the cheapest edge that will not cause a cycle. 
     But rather than choosing the cheapest edge that will connect any pair of trees together, Prim's algorithm 
     only adds edges that join nodes to the existing tree. (In this respect, Prim's algorithm is very similar to 
     Dijkstra's algorithm for finding shortest paths.)
     * Reference: [Given at the last].

   # Few terms which will be used in the algorithm ---->
     * V = set of all the vertices of the graph.
     * MST Set = set of all the vertices which have been included in the MST so far.
	 * Active Edge = An edge between a vertex in MST Set and V.
	 * MST Edge = An edge which have been included in the MST so far.

   # Algorithm ---->

     1. Remove all loops and Parallel Edges.
        (In case of parallel edges, keep the one which has the least cost associated and remove all others.)

     2. Choose any vertex as the starting vertex and include it in MST Set and exclude it from V set.

     3. Out of all the active edges choose the one with minimum weight and add it to result.
        * Include the other vertex (say 'Y') of this active edge in MST Set & exclude it from V set.
        * Add edges starting from 'Y' in the Active Edge list.
        * NOTE: No need to consider the edge between 'Y' and previously visited vertex.

     4. Repeat step 3 until MST Set doesn't contain all the vertices or V set is empty.
*/

/**************************************************************************************************************************************************************/

// METHOD - 1 O(n^2)
// Ref: https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
//      https://www.youtube.com/watch?v=oNTsS8lGDHw&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=21

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

// to store the input graph
vector<vpii> g;

// n = #vertices, m = #edges in input graph
int n, m;

// NOTE: the below algorithm assumes that the input graph is undirected connected,
//       since MST doesn't exist for a disconnected graph

// function to print and return the weight of MST
ll prims_algo() {
	// vector to store constructed MST 
    vi parent(n); 
      
    // key values used to pick minimum weight edge every time 
    vi key(n); 
      
    // to represent set of vertices included in MST so far 
    vb mst(n); 
  
    // initialize all keys as INFINITE, not present in MST & no parents
    for(int i = 0; i < n; i++) {
    	key[i] = INT_MAX, mst[i] = 0, parent[i] = -1; 
    }
  
    // starting the MST with a single vertex. 
    // make key 0 so that this vertex is picked as first vertex. 
    key[0] = 0; 
    parent[0] = -1; 
    
    // as MST will have (n - 1) edges so run loop for (n- 1) times
	for(int count = 0; count < n - 1; count++) { 
        // pick the minimum key vertex from the set of vertices not yet included in MST yet 
        int mn = INT_MAX, u;
        
        for(int i = 0; i < n; i++) {
        	if(mst[i] == 0 and key[i] < mn) {
        		mn = key[i], u = i;
        	}
        }
  
        // add the picked vertex to the MST set 
        mst[u] = 1; 
  
        // update key value and parent index of the adjacent vertices of the picked vertex, by 
        // considering only those vertices which are not yet included in MST 
     	for(auto x: g[u]) {
     		int v = x.F, wt = x.S;
     		if(mst[v] == 0 and wt < key[v]) {
     			key[v] = wt;
     			parent[v] = u;
     		}
     	}   
    }
    
    // in case you need the actual MST
    vvi MST; // {u, v, wt}
    for(int i = 1; i < n; i++) {
    	vi edg(3);
    	edg[0] = parent[i], edg[1] = i, edg[2] = key[i];
    	MST.pb(edg);
    }
   
    ll res = 0LL;
    for(int i = 0; i < n; i++) res += key[i];
    
    return res; 
}

void solve()
{
  	cin >> n >> m;

    g.clear(); g.resize(n);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y, wt; 
        cin >> x >> y >> wt;
        g[x].pb({y, wt});
        g[y].pb({x, wt});
    }
    
    cout << prims_algo() << "\n";
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

/**************************************************************************************************************************************************************/

// METHOD - 2 
// Ref: https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/
//      https://www.youtube.com/watch?v=oNTsS8lGDHw&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=21
//      https://github.com/striver79/StriversGraphSeries/blob/main/primsAlgoCppEfficient

// Time complexity is also discussed in the video.

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

// to store the input graph
vector<vpii> g;

// n = #vertices, m = #edges in input graph
int n, m;

// NOTE: the below algorithm assumes that the input graph is undirected connected,
//       since MST doesn't exist for a disconnected graph

// function to print and return the weight of MST
ll prims_algo() {
    // vector to store constructed MST 
    vi parent(n); 
      
    // key values used to pick minimum weight edge every time 
    vi key(n); 
      
    // to represent set of vertices included in MST so far 
    vb mst(n); 
  
    // initialize all keys as INFINITE, not present in MST & no parents
    for(int i = 0; i < n; i++) {
        key[i] = INT_MAX, mst[i] = 0, parent[i] = -1; 
    }
    
    priority_queue<pii, vpii, greater<pii>> q;
    
    // starting the MST with a single vertex.
    // make key 0 so that this vertex is picked as first vertex. 
    key[0] = 0; 
    parent[0] = -1; 
    q.push({0, 0}); // {weight, vertex}
    
    while(!q.empty()) {
        // pick the minimum key vertex from the set of vertices not yet included in MST yet 
        int u = q.top().S;
        q.pop();
        
        // if picked vertex is alread in MST set, then continue
        if(mst[u] == 1) continue;

        // else add the picked vertex to the MST set 
        mst[u] = 1; 
        
        // update key value and parent index of the adjacent vertices of the picked vertex, by 
        // considering only those vertices which are not yet included in MST 
        for(auto x: g[u]) {
            int v = x.F, wt = x.S;
            if(mst[v] == 0 and wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                q.push({key[v], v});
            }
        }   
    }
    
    // in case you need the actual MST
    vvi MST; // {u, v, wt}

    for(int i = 1; i < n; i++) {
        vi edg(3);
        edg[0] = parent[i], edg[1] = i, edg[2] = key[i];
        MST.pb(edg);
    }
   
    ll res = 0LL;
    for(int i = 0; i < n; i++) res += key[i];
    
    return res; 
}

void solve()
{
    cin >> n >> m;
    g.clear(); g.resize(n);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y, wt; 
        cin >> x >> y >> wt;
        g[x].pb({y, wt});
        g[y].pb({x, wt});
    }
    
    cout << prims_algo() << "\n";
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

/* # NOTE: # In case you wanted to calculate the MST weight on the go while exploring the priority_queue, the implementation given in the link below
             would give WA (since in that implementation the edge weight is blindly added. There might be a possibility that a node is occurring more
             than once in the priority queue and it was already a part of MST).

             https://gist.github.com/Edith-3000/291e836732df19cdefe0f79d7417c478

           # Previously the while() loop of the algorithm was like this --->
             https://gist.github.com/Edith-3000/8055f30225dd747c9b76e55b922246df 
*/

// Time Complexity: O(|E| x log|E|) which in turn = O(|E| x log|V|), same as Kruskal's algorithm.
// However, Prim's algorithm can be improved using Fibonacci Heaps to O(|E| + log|V|).
// Reference: https://www.cs.auckland.ac.nz/software/AlgAnim/prim.html#:~:text=The%20time%20complexity%20is%20O,O(E%20%2B%20logV).