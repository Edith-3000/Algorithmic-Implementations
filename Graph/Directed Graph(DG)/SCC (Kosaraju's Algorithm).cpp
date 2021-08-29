/* # The term 𝑺𝑻𝑹𝑶𝑵𝑮𝑳𝒀 is always used in reference with 𝑫𝑰𝑹𝑬𝑪𝑻𝑬𝑫 𝑮𝑹𝑷𝑨𝑯(𝑫𝑮).
   # A DG is strongly connected graph if there is a path between all the pairs of vertices.
   # A strongly connected component (SCC) of a DG is a 𝒎𝒂𝒙𝒊𝒎𝒂𝒍 𝒔𝒕𝒓𝒐𝒏𝒈𝒍𝒚 𝒄𝒐𝒏𝒏𝒆𝒄𝒕𝒆𝒅 𝒔𝒖𝒃𝒈𝒓𝒂𝒑𝒉.
     * Here the term "𝒎𝒂𝒙𝒊𝒎𝒂𝒍" means that it is the largest possible subgraph: you could not find another 
       node anywhere in the graph such that it could be added to the subgraph and all the nodes in the 
       subgraph would still be connected.
   # Thus it can be said that if a DG has exactly 1 SCC, then it is a strongly connected graph.
   # In a DAG (Directed Acyclic Graph) #SCC (Strongly Connected Components) = #vertices in the DAG.
*/

// Kosaraju's is an easy-to-implement algorithm based on two series of depth first search, and working 
// for O(|V| + |E|) time.

// Ref: https://cp-algorithms.com/graph/strongly-connected-components.html

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

const int N = 100005;

vi g[N]; // adjacency list representation of graph
vi rg[N]; // to store the reverse graph
vi vis(N); // visited array
vi color(N); // to store the component of each vertex

// if there exists a path from vertex 'x' to 'y' of the original 
// graph then in the order vector 'y' must come before 'x'
vi order;

void dfs(int curr) {
    vis[curr] = 1;
    for(auto x: g[curr]) {
        if(!vis[x]) dfs(x);
    }
    
    order.pb(curr);
}

void dfs_reverse(int curr, int col) {
    vis[curr] = 1;
    color[curr] = col; // mark it with color
    for(auto x: rg[curr]) {
        if(!vis[x]) dfs_reverse(x, col);
    }
}

void solve()
{
    // n = #vertices, m = #edges
    int n, m; cin >> n >> m;
    
    // vertices are 1-based indexed
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y); // store in graph
        rg[y].pb(x); // store in reverse graph
    }
    
    // mark all vertices as not visited initially
    fill(vis.begin(), vis.end(), 0);
    
    // perform dfs on the original graph so as 
    // to construct the order vector
    for(int vertex = 1; vertex <= n; vertex++) {
        if(!vis[vertex]) {
            dfs(vertex);
        }
    }
    
    // again perform dfs on the reverse graph to 
    // find out the strongly connected components
    fill(vis.begin(), vis.end(), 0);
    
    // to mark the vertices belonging to the same SCC with
    // the same color
    int col = 1;
    
    // start from the last vertex of order vector
    for(int i = n - 1; i >= 0; i--) {
        if(!vis[order[i]]) {
            dfs_reverse(order[i], col);
            col++;
        }
    }
  
    // to find the #SCC
    set<int> s;
    for(int vertex = 1; vertex <= n; vertex++) {
        s.insert(color[vertex]);
    }
    
    cout << "SCC in the DG = " << s.size() << "\n";
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

/*

Sample i/p --->

6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 4

Sample o/p --->

SCC in the DG = 2

*/

// Time complexity: O(|V| + |E|)
// NOTE ---> It is worth mentioning the fact that the order vector represents reversed topological sort 
//           (vertices' sort by exit time) of the vertices of condensation graph.
//           For more details of this statement, visit: https://cp-algorithms.com/graph/strongly-connected-components.html


/**********************************************************************************************************/

// Another implementation to store the vertices of same SCC together
// Below code is exactly same as above except the use of in_comp[] instead of color vector

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

const int N = 100005;

vi g[N]; // adjacency list representation of graph
vi rg[N]; // to store the reverse graph
vi vis(N); // visited array

// to store the component of each vertex
// in_comp[i] stores all the vertices in the ith component
vi in_comp[N]; 

// if there exists a path from vertex 'x' to 'y' in the DFS tree generated
// of the original graph then in the order vector 'y' must come before 'x'
vi order;

void dfs(int curr) {
    vis[curr] = 1;
    for(auto x: g[curr]) {
        if(!vis[x]) dfs(x);
    }
    
    order.pb(curr);
}

void dfs_reverse(int curr, int col) {
    vis[curr] = 1;
    in_comp[col].pb(curr); // put it in the component
    for(auto x: rg[curr]) {
        if(!vis[x]) dfs_reverse(x, col);
    }
}

void solve()
{
    // n = #vertices, m = #edges
    int n, m; cin >> n >> m;
    
    // vertices are 1-based indexed
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y); // store in graph
        rg[y].pb(x); // store in reverse graph
    }
    
    // mark all vertices as not visited initially
    fill(vis.begin(), vis.end(), 0);
    
    // perform dfs on the original graph so as 
    // to construct the order vector
    for(int vertex = 1; vertex <= n; vertex++) {
        if(!vis[vertex]) {
            dfs(vertex);
        }
    }
    
    // again perform dfs on the reverse graph to 
    // find out the strongly connected components
    fill(vis.begin(), vis.end(), 0);
    
    // to mark the vertices belonging to the same SCC with
    // the same color
    int col = 1;
    
    // start from the last vertex of order vector
    for(int i = n - 1; i >= 0; i--) {
        if(!vis[order[i]]) {
            dfs_reverse(order[i], col);
            
            if(in_comp[col].size() > 0) { 
                cout << "Vertices in the same SCC = ";
                for(auto it = in_comp[col].begin(); it != in_comp[col].end(); it++) {
                    cout << *it << " ";
                }
                
                cout << "\n";
            }
            
            col++;
        }
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

/*

Sample i/p --->

6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 4

Sample o/p --->

Vertices in the same SCC = 1 3 2 
Vertices in the same SCC = 4 6 5 

*/

/* # Code for finding out all the vertices of all SSC can also be found here:
     https://cp-algorithms.com/graph/strongly-connected-components.html

   # Another interesting question on this topic: 
     https://cses.fi/problemset/task/1682/
*/