// Prob: https://leetcode.com/problems/is-graph-bipartite/

/************************************************************************************************************************************************************/

/* # A bipartite graph also called a bi-graph, is a set of graph vertices, i.e, points where multiple 
     lines meet, decomposed into two 𝒅𝒊𝒔𝒋𝒐𝒊𝒏𝒕 sets, meaning they have no element in common, such that no 
     two graph vertices within the same set are 𝒂𝒅𝒋𝒂𝒄𝒆𝒏𝒕.

   # Adjacent nodes are any two nodes that are connected by an edge.
   
   # A bipartite graph is a special case of a 𝒌-𝒑𝒂𝒓𝒕𝒊𝒕𝒆 𝒈𝒓𝒂𝒑𝒉 with k = 2.

   # Bipartite graphs are equivalent to 𝒕𝒘𝒐-𝒄𝒐𝒍𝒐𝒓𝒂𝒃𝒍𝒆 𝒈𝒓𝒂𝒑𝒉𝒔 i.e. coloring of the vertices using two 
     colors in such a way that vertices of the same color are never adjacent along an edge. 

   # All 𝑨𝒄𝒚𝒄𝒍𝒊𝒄 𝒈𝒓𝒂𝒑𝒉𝒔 are bipartite. 
     • As a tree is an acyclic graph, ∴ Bi-partite.
       To put the vertices of a tree in 2 disjoint sets just put the vertices of the all the levels 
       alternately in Set 1 and Set 2, no other possibility exist.

   # A 𝑪𝒚𝒄𝒍𝒊𝒄 graph is bipartite iff all its cycles are of even length. 
   # Some common examples of a bipartite graph include star graphs, grid graphs and gear graphs.

   # Applications of bipartite graphs ⟶
     • Bipartite graph can be used in the medical field in the detection of lung cancer, throat cancer, etc.
     • Used in search advertising and e-commerce for similarity ranking.
     • Predict movie preferences of a person.
     • Stable marriage and other matching problems.

   # For more info visit: https://www.educative.io/edpresso/what-is-a-bipartite-graph

   # So in conclusion, if a graph contains odd length cycle, then it is not bi-partite, else it is.
*/

/************************************************************************************************************************************************************/

// METHOD - 1 (USING DFS)
// Refer: https://www.youtube.com/watch?v=-vu34sct1g8&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=18&ab_channel=takeUforward
//        https://takeuforward.org/graph/bipartite-graph-dfs-implementation/

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
vvi g;

// to keep track of color of visited nodes,
// works as a visited array as well
vi color;

int n, m;

// function which returns whether the subtree rooted at the current node is bipartite or not
bool dfs(int cur, int col) {
    // marking a node visited (color it) as soon as it is pushed in internal call stack
    color[cur] = col;
    
    // now there can be 2 cases ===>
    // case 1. either the neighbour of the cur vertex is not visited yet, in 
    //         such a case recursively visit the neighbours & check for bipartiteness
    // case 2. the neighbour is visited and if color[nbr] == color[cur] ==> not bipartite
    //         i.e. it contains an odd length cycle
    
    for(auto x: g[cur]) {
        // case 1
        if(color[x] == -1) {
            if(!dfs(x, 1 - col)) return 0;
        }
        
        // case 2
        else if(color[x] == color[cur]) return 0;
    }
    
    // if the above 2 cases fails then bipartite
    return 1;
}

bool is_bipartite() {
    for(int i = 0; i < n; i++) color[i] = -1;
    
    // taking care of multiple components in the graph
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            if(!dfs(i, 0)) return 0;
        }
    }
    
    return 1;
}

void solve()
{
    cin >> n >> m;
    
    g.clear(); g.resize(n);
    color.clear(); color.resize(n, -1);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
        
    if(is_bipartite()) cout << "YES\n";
    else cout << "NO\n";
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

// Time Complexity ≡ DFS traversal

/************************************************************************************************************************************************************/

// METHOD - 2 (USING BFS)

// Refer: https://www.youtube.com/watch?v=uC884ske2uQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=11&ab_channel=takeUforward
//        https://www.youtube.com/watch?v=nbgaEu-pvkU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=11

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
vvi g;

// to keep track of color of visited nodes,
// works as a visited array as well
vi color;

int n, m;

// function which returns whether the subtree rooted at the current node is bipartite or not
bool bfs(int src) {
    // queue to remember which vertex to visit next in case of dead end in iteration
    queue<int> q;
    
    // initialisation of the bfs process pushing the src in queue
    q.push(src);
    
    // marking a node visited (colored with some color) as soon as it is pushed in q
    color[src] = 0;
    
    // iterative process
    while(!q.empty()) {
        // taking out vertex from q
        int cur = q.front();
        
        // popping out this vertex from q
        q.pop();
        
        // now there can be 2 cases ===>
        // case 1. either the neighbour of the cur vertex is not visited yet
        // case 2. the neighbour is visited and if color[nbr] == color[cur] ==> not bipartite
        //         i.e. it contains an odd length cycle
        
        for(auto x: g[cur]) {
            // case 1
            if(color[x] == -1) {
                color[x] = 1 - color[cur]; // mark it visited (color with the opposite color of it's parent)
                q.push(x); // push it in the queue
            }
            
            // case 2
            else if(color[x] == color[cur]) return 0;
        }
    }
    
    return 1;
}

bool is_bipartite() {
    for(int i = 0; i < n; i++) color[i] = -1;
    
    // taking care of multiple components in the graph
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            if(!bfs(i)) return 0;
        }
    }
    
    return 1;
}

void solve()
{
    cin >> n >> m;
    
    g.clear(); g.resize(n);
    color.clear(); color.resize(n, -1);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
        
    if(is_bipartite()) cout << "YES\n";
    else cout << "NO\n";
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