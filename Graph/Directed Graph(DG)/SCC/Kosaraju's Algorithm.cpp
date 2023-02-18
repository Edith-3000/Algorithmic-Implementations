// Ref: https://cp-algorithms.com/graph/strongly-connected-components.html
//      https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/
//      https://www.youtube.com/watch?v=V8qIqJxCioo&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=27&ab_channel=takeUforward

/******************************************************************************************************************************************************************/

/* # The term 𝑺𝑻𝑹𝑶𝑵𝑮𝑳𝒀 is always used in reference with 𝑫𝑰𝑹𝑬𝑪𝑻𝑬𝑫 𝑮𝑹𝑷𝑨𝑯(𝑫𝑮).

   # A DG is strongly connected graph if there is a path between all the pairs of vertices.

   # A strongly connected component (SCC) of a DG is a 𝒎𝒂𝒙𝒊𝒎𝒂𝒍 𝒔𝒕𝒓𝒐𝒏𝒈𝒍𝒚 𝒄𝒐𝒏𝒏𝒆𝒄𝒕𝒆𝒅 𝒔𝒖𝒃𝒈𝒓𝒂𝒑𝒉.

     * Here the term "𝒎𝒂𝒙𝒊𝒎𝒂𝒍" means that it is the largest possible subgraph: you could not find another 
       node anywhere in the graph such that it could be added to the subgraph and all the nodes in the 
       subgraph would still be connected.

   # Thus it can be said that if a DG has exactly 1 SCC, then it is a strongly connected graph.

   # In a DAG (Directed Acyclic Graph) ===> #SCC (Strongly Connected Components) = #vertices in the DAG.
*/

/******************************************************************************************************************************************************************/

// LEGACY CONTENT: https://pastebin.com/rY1fX5ya

/******************************************************************************************************************************************************************/

// Kosaraju's is an easy-to-implement algorithm based on two series of depth first search, and working 
// for O(|V| + |E|) time.

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

// g = to store the input graph
// rg = to store the reverse of the input graph
vvi g, rg;

// to check if a vertex has been visited or not
vi vis;

// to store the component of each vertex
// in_comp[i] stores all the vertices in the ith component
vvi in_comp; 

// if there exists a path from vertex 'x' to 'y' in the DFS tree generated
// of the original graph then in the order vector 'y' must come before 'x'
vi order;

// n = #vertices, m = #edges in input graph
int n, m;

void dfs(int cur) {
    vis[cur] = 1;
    
    for(auto x: g[cur]) {
        if(!vis[x]) dfs(x);
    }
    
    order.pb(cur);
}

void dfs_reverse(int cur, int col) {
    vis[cur] = 1;
    
    // put current node in the component number 'col'
    in_comp[col].pb(cur);
    
    for(auto x: rg[cur]) {
        if(!vis[x]) dfs_reverse(x, col);
    }
}

void kosaraju_algorithm() {
    vis.clear(); vis.resize(n);
    
    // mark all vertices as not visited initially
    for(int i = 0; i < n; i++) vis[i] = 0;
    
    order.clear();
    
    // perform dfs on the original graph so as to construct the order vector
    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i);
    }
    
    // there can be at most n SCC in a DG
    in_comp.clear(); in_comp.resize(n);
    
    // marking the vertices as unvisited again
    for(int i = 0; i < n; i++) vis[i] = 0;
        
    // to mark the vertices belonging to the same SCC with the same color
    int col = 0;
    
    // again perform dfs on the reverse graph to find out the strongly connected components
    for(int i = n - 1; i >= 0; i--) {
        if(!vis[order[i]]) {
            dfs_reverse(order[i], col);
            col += 1;
        }
    }
    
    cout << "The directed graph has " << col << " SCC(s)\n\n";
    
    for(int i = 0; i < col; i++) {
        cout << "Vertices in the same SCC = ";
        for(auto it = in_comp[i].begin(); it != in_comp[i].end(); it++) {
            cout << *it << " ";
        }
        
        cout << "\n";
    }
}

void solve()
{
    cin >> n >> m;
    
    g.clear(); g.resize(n);
    rg.clear(); rg.resize(n);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        rg[y].pb(x);
    }
    
    kosaraju_algorithm();
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

The directed graph has 2 SCC(s)

Vertices in the same SCC = 0 2 1 
Vertices in the same SCC = 3 5 4 

*/

/* # Code for finding out all the vertices of all SSC can also be found here:
     https://cp-algorithms.com/graph/strongly-connected-components.html

   # Another interesting question on this topic: 
     https://cses.fi/problemset/task/1682/
*/