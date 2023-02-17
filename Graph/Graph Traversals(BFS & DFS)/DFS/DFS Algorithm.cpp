// Ref: https://cp-algorithms.com/graph/depth-first-search.html
//      https://brilliant.org/wiki/depth-first-search-dfs/

/******************************************************************************************************************************************************************/

/* # DFS is a recursive graph traversal technique (although it can be implemented iteratively as well).

   # DFS utilizes the “go deep, head first” philosophy in its implementation.

   # It is similar to preorder order traversal of a tree.

   # Stack data structure is used to implement DFS (∵ recursion uses internal call stack).

   # Depth-first search is used in topological sorting, scheduling problems, cycle detection in graphs, 
     and solving puzzles with only one solution, such as a maze or a sudoku puzzle.

   # Other applications involve analyzing networks, for example, testing if a graph is bipartite. 
     Depth-first search is often used as a subroutine in network flow algorithms such as the Ford-Fulkerson 
     algorithm.

   # DFS is also used as a subroutine in matching algorithms in graph theory such as the Hopcroft–Karp 
     algorithm.

   # Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree. 
     The only catch here is, unlike trees, graphs may contain cycles, a node may be visited twice. 
     To avoid processing a node more than once, use a boolean visited array.

   # Depth-first searches are used in mapping routes, scheduling, and finding spanning trees.

   # It employs the following rules ----->

     Rule 1 − Visit the adjacent unvisited vertex. Push it in a stack. Mark it as visited. Display it.
              (𝑻𝑯𝑰𝑺 𝑶𝑹𝑫𝑬𝑹 𝑰𝑵 𝑹𝑼𝑳𝑬 1 𝑰𝑺 𝑽𝑬𝑹𝒀 𝑰𝑴𝑷𝑶𝑹𝑻𝑨𝑵𝑻, 𝑺𝑳𝑰𝑮𝑯𝑻𝑳𝒀 𝑽𝑨𝑹𝑰𝑬𝑺 𝑭𝑹𝑶𝑴 𝑻𝑯𝑬 𝑹𝑼𝑳𝑬 1 𝑶𝑭
               𝑩𝑭𝑺 𝑨𝑳𝑮𝑶𝑹𝑰𝑻𝑯𝑴)

     Rule 2 − If no adjacent vertex is found, pop up a vertex from the stack. (It will pop up all the 
              vertices from the stack, which do not have adjacent vertices.)

     Rule 3 − Repeat Rule 1 and Rule 2 until the stack is empty.
*/

/******************************************************************************************************************************************************************/

// LEGACY CONTENT: https://pastebin.com/2kuhBdS7

/******************************************************************************************************************************************************************/

// RECURSIVE IMPLEMENTATION OF DFS 

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

// stores the input graph
vvi g;

// to keep track of visited vertices
vb vis;

int n, m;

void dfs_helper(int cur, vi &res) {
    // marking a node visited as soon as it is pushed in internal call stack
    vis[cur] = 1;

    // push src in the result
    res.pb(cur);
    
    // go to all the unvisited nodes of the current node, but one by one
    for(auto x: g[cur]) {
        // check if already visited or not
        if(!vis[x]) {
            // push it in the stack(internal call stack is used)
            dfs_helper(x, res);
        }
    }
}

vi dfs() {
    // to store one of the many possible dfs traversal
    vi res;
    
    // marking all nodes as unvisited initially
    for(int i = 0; i < n; i++) vis[i] = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs_helper(i, res);
        }
    }

    // return the final result of traversal
    return res;
}

void solve()
{
    cin >> n >> m;
    
    g.clear(); g.resize(n);
    vis.clear(); vis.resize(n, 0);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
        
    vi res = dfs();
    
    for(auto x: res) cout << x << " ";
    cout << "\n";
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

/******************************************************************************************************************************************************************/

// ITERATIVE IMPLEMENTATION OF DFS 

/* The non-recursive iterative implementation is similar to breadth-first search but differs from 
   it in two ways:
   1). It uses a stack instead of a queue.
   2). 𝑰𝒕 𝒅𝒆𝒍𝒂𝒚𝒔 𝒄𝒉𝒆𝒄𝒌𝒊𝒏𝒈 𝒘𝒉𝒆𝒕𝒉𝒆𝒓 𝒂 𝒗𝒆𝒓𝒕𝒆𝒙 𝒉𝒂𝒔 𝒃𝒆𝒆𝒏 𝒅𝒊𝒔𝒄𝒐𝒗𝒆𝒓𝒆𝒅 (𝒂𝒍𝒓𝒆𝒂𝒅𝒚 𝒗𝒊𝒔𝒊𝒕𝒆𝒅 𝒐𝒓 𝒏𝒐𝒕) 𝒖𝒏𝒕𝒊𝒍 𝒕𝒉𝒆 
       𝒗𝒆𝒓𝒕𝒆𝒙 𝒊𝒔 𝒑𝒐𝒑𝒑𝒆𝒅 𝒇𝒓𝒐𝒎 𝒕𝒉𝒆 𝒔𝒕𝒂𝒄𝒌 𝒓𝒂𝒕𝒉𝒆𝒓 𝒕𝒉𝒂𝒏 𝒎𝒂𝒌𝒊𝒏𝒈 𝒕𝒉𝒊𝒔 𝒄𝒉𝒆𝒄𝒌 𝒃𝒆𝒇𝒐𝒓𝒆 𝒂𝒅𝒅𝒊𝒏𝒈 𝒕𝒉𝒆 𝒗𝒆𝒓𝒕𝒆𝒙.
*/

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

// stores the input graph
vvi g;

// to keep track of visited vertices
vb vis;

int n, m;

void dfs_helper(int src, vi &res) {
    // stack to remember which vertex to visit next in case of dead end in iteration
    stack<int> s;

    // initialisation of the dfs process pushing the src in stack
    s.push(src);

    // iterative process
    while(!s.empty()) {
        // taking out vertex from q
        int cur = s.top();

        // popping out this vertex from stack
        s.pop();
       
        // stack may contain same vertex twice. So we need to
        // print the popped item only if it is not visited.
        // If facing difficulty in understanding this, take the sample i/p example and
        // run this code w/o the if() condition, you'll get it.
        if(!vis[cur]) {
            vis[cur] = 1;  // mark it visited
            res.pb(cur); // push cur in the result
        }

        // visiting all the adjacent vertices of cur
        for(auto x: g[cur]) {
            // check if already visited or not
            if(!vis[x]) {
                s.push(x); // push it in the stack
            }
        }
    }
}

vi dfs() {
    // to store one of the many possible dfs traversal
    vi res;
    
    // marking all nodes as unvisited initially
    for(int i = 0; i < n; i++) vis[i] = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs_helper(i, res);
        }
    }

    // return the final result of traversal
    return res;
}

void solve()
{
    cin >> n >> m;
    
    g.clear(); g.resize(n);
    vis.clear(); vis.resize(n, 0);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
        
    vi res = dfs();
    
    for(auto x: res) cout << x << " ";
    cout << "\n";
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

Sample i/p :--->

4 4
0 1
1 2
2 0
1 3

Sample o/p :--->

0 2 1 3 

*/

/******************************************************************************************************************************************************************/

/* # HANDLING DISCONNECTED GRAPH
   • The above code handles disconnected graph as well.

   • All the vertices may not be reachable from a given vertex as in the case of a 𝑫𝒊𝒔𝒄𝒐𝒏𝒏𝒆𝒄𝒕𝒆𝒅 𝒈𝒓𝒂𝒑𝒉. 
     To do complete DFS traversal of such graphs, run DFS from all unvisited nodes after a DFS.
     i.e. Run a loop from through all the vertices and check if the vertex is unvisited in previous DFS then 
     call the dfs fⁿ with current node.
*/

// The Analysis of depth-first search ≡ Analysis of breadth-first search

/* # Iterative DFS v/s Recursive DFS and different elements order ------>

   * Both are valid DFS algorithms. A DFS does not specify which node you see first. It is not important 
     because the order between edges is not defined [remember: edges are a set usually]. The difference is 
     due to the way you handle each node's children.

   * In the iterative approach: You first insert all the elements into the stack of the current node
     and then handle the head(top) of the stack [which is the last node inserted] - thus the first 
     node you handle is the last child (last adjacent neighbour) of the current node.
   * While in the recursive approach: You handle each node when you see it. Thus the first node you handle 
     is the first child (first adjacent neighbour).
   
   * These two variations of DFS visit the neighbors of each vertex in the opposite order from each other: 
     the first neighbor of v(current node) visited by the recursive variation is the first one in the list 
     of adjacent edges, 
     while in the iterative variation the first visited neighbor is the last one in the list of adjacent 
     edges.

   # To make the iterative DFS yield the same result as the recursive one - you need to add elements to 
     the stack in reverse order [for each node, insert its last child first and its first child last]
*/

/* HOW DO YOU SOLVE A MAZE?

Depth-first search is a common way that many people naturally approach solving problems like mazes. 
First, we select a path in the maze (for the sake of the example, let's choose a path according to some 
rule we lay out ahead of time) and we follow it until we hit a dead end or reach the finishing point of 
the maze. If a given path doesn’t work, we backtrack and take an alternative path from a past junction, 
and try that path. Below is an animation of a DFS approach to solving this maze.

# Very nice pictorial representation given - https://brilliant.org/wiki/depth-first-search-dfs/

*/

/* Difference b/w DFS and BACKTRACKING ---->

   https://stackoverflow.com/questions/1294720/whats-the-difference-between-backtracking-and-depth-first-search

   https://www.baeldung.com/cs/backtracking-vs-dfs

   https://leetcode.com/discuss/general-discussion/136503/What-is-difference-between-backtracking-and-depth-first-search/601135
*/