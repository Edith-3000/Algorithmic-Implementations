// Ref: https://cp-algorithms.com/graph/breadth-first-search.html
//      https://brilliant.org/wiki/breadth-first-search-bfs/

/*****************************************************************************************************************************************************************/

/* # BFS is an iterative graph traversal technique.

   # It follows the “go wide, bird’s eye-view” philosophy.

   # It is similar to level order traversal of a tree.

   # Queue data structure is used to implement BFS.

   # The algorithm traverses the graph in the smallest number of iterations and the shortest possible 
     time.

   # BFS iterations are seamless, and there is no possibility of this algorithm getting caught up in 
     an infinite loop problem.

   # The result of the BFS algorithm holds a high level of accuracy in comparison to other algorithms.

   # Due to high precision and robust implementation, BFS is used in multiple real-life solutions like 
     P2P networks, Web Crawlers, and Network Broadcasting.

   # BREADTH-FIRST SEARCH CAN BE USED TO SOLVE GAMES WHERE A SERIES OF CHOICES RESULT IN EITHER A 
     WINNING OR LOSING STATE. FOR EXAMPLE, BFS CAN HELP A PLAYER DETERMINE A WINNING SEQUENCE OF MOVES 
     FOR SOLVING A RUBIK'S CUBE.

   # This algorithm traverses a graph in a breadthward motion and uses a queue to remember to get the 
     next vertex to start a search, when a dead end occurs in any iteration.

   # It employs the following rules ----->
   
     Rule 1 − Visit the adjacent unvisited vertex. Mark it as visited. Insert it in a queue. Display it.
              (Remember as soon as a node is mark as visited push it into the queue).

     Rule 2 − If no adjacent vertex is found, remove the first vertex from the queue.

     Rule 3 − Repeat Rule 1 and Rule 2 until the queue is empty.
*/

/*****************************************************************************************************************************************************************/

// LEGACY CONTENT: https://pastebin.com/baRLV8dt

/*****************************************************************************************************************************************************************/

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

void bfs_helper(int src, vi &res) {    
    // queue to remember which vertex to visit next in case of dead end in iteration
    queue<int> q;

    // initialisation of the bfs process pushing the src in queue
    q.push(src);

    // marking a node visited as soon as it is pushed in q
    vis[src] = 1;

    // iterative process
    while(!q.empty()) {
        // taking out vertex from q
        int cur = q.front();

        // popping out this vertex from q
        q.pop();
       
        // push v in the result
        res.pb(cur);

       // visiting all the adjacent vertices of cur
       for(auto x: g[cur]) {
            // check if already visited or not
            if(!vis[x]) {
                vis[x] = 1; // mark it visited
                q.push(x); // push it in the queue
            }
        }
    }
}

vi bfs() {
    // to store one of the many possible bfs traversal
    vi res;
    
    // marking all nodes as unvisited initially
    for(int i = 0; i < n; i++) vis[i] = 0;

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            bfs_helper(i, res);
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
        
    vi res = bfs();
    
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

# Analysis of breadth-first search ---->
  * How long does breadth-first search takes for a graph with vertex set V and edge set E? 
    The answer is O(|V|+|E|) time. 
  * Let's see what O(|V|+|E|), time means - 
  * For a graph there can be 2 possible cases.
  * CASE 1: Assume for the moment that |E|≥∣V∣, which is the case for most graphs, especially those 
            for which we run breadth-first search. Then,
            |V|+|E| ≤ |E|+|E| =>  |V|+|E| ≤ 2*|E|. 
            Because we ignore constant factors in asymptotic notation, we see that when |E| ≥ ∣V∣, 
            O(|V|+|E|) really means O(|E|). 

  * CASE 2: If, however, we have |E|<|V|, then
            |V|+|E| ≤ |V|+|V| =>  |V|+|E| ≤ 2*|V| and so O(|V|+|E|) really means O(|V|).

  * We can put both cases together by saying that O(|V|+|E|) really means O(max(|V|,|E|). 
  * In general, if we have parameters x and y, then O(x+y) really means O(max(x,y)).
  
  * How is it that breadth-first search runs in O(|V|+|E|) time ?
    Since every vertex and every edge will be explored in the worst case.
  * |V| = the number of vertices and |E| is the number of edges in the graph. 
    Note that O(|E|) may vary between O(1) and O(|V|²), depending on how sparse the input graph is.

  * When the number of vertices in the graph is known ahead of time, and additional data structures 
    are used to determine which vertices have already been added to the queue, the space complexity 
    can be expressed as O(|V|), where. This is in addition to the space required for the graph itself, 
    which may vary depending on the graph representation used by an implementation of the algorithm.
  
  * When working with graphs that are too large to store explicitly (or infinite), it is more practical 
    to describe the complexity of breadth-first search in different terms: ---->
    To find the nodes that are at distance d from the start node (measured in number of edge traversals), 
    BFS takes O(bᵈ) time and memory, 
    where b is the "branching factor" of the graph (the average out-degree).

-------------------------------------------------------------------------------------------------------------

#  SIDE NOTEs ----->
   
#  A graph is connected if there is a path from every vertex to all other vertices. The minimum number
   of edges that a graph can have and still be connected is |V|-1. 
   A graph in which |E| = |V|-1 is called a free tree.

#  In graph theory, the basic definition of a tree is that it is a connected graph without cycles. 
   This definition does not use any specific node as a root for the tree. A rooted tree introduces a 
   parent — child relationship between the nodes and the notion of depth in the tree.
#  Roughly and visually, adding a root to a tree just corresponds to grabbing one of the nodes of the 
   tree and hanging the tree with this node. Once the tree is hanged, each node has a depth related to 
   its height, a parent to which it is suspended and several children which hang from this node.
#  In a free tree there's no designated root vertex.
   A free tree can be converted into a rooted one by choosing any of its vertices to be the root.

*/