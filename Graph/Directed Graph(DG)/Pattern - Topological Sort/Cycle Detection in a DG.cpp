// Ref: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

/*******************************************************************************************************************************************************************/

// METHOD - 1 (USING DFS)
// https://www.youtube.com/watch?v=9twcmtQj4DU&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=20&ab_channel=takeUforward
// https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12&ab_channel=takeUforward

/* # The reason why the method used in "Graph/Undirected Graph(UG)/Cycle Detection in an UG.cpp" can't be used here is very well
     explained in the below video link.

   # https://www.youtube.com/watch?v=9twcmtQj4DU&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=20&ab_channel=takeUforward
*/

/* USEFUL TIPs ⟶
   # 𝑨𝒏 𝑼𝒏𝒅𝒊𝒓𝒆𝒄𝒕𝒆𝒅 𝑮𝒓𝒂𝒑𝒉(𝑼𝑮) 𝒄𝒐𝒏𝒕𝒂𝒊𝒏𝒔 𝒂 𝒄𝒚𝒄𝒍𝒆 𝒊𝒇 𝒕𝒉𝒆𝒓𝒆 𝒊𝒔 𝑴𝑶𝑹𝑬 𝑻𝑯𝑨𝑵 1 𝒘𝒂𝒚 𝒕𝒐 𝒗𝒊𝒔𝒊𝒕 𝒂 𝒏𝒐𝒅𝒆/𝒗𝒆𝒓𝒕𝒆𝒙, 
     but the same is not the case with 𝑫𝒊𝒓𝒆𝒄𝒕𝒆𝒅 𝑮𝒓𝒂𝒑𝒉(𝑫𝑮), for eg. consider the following DG: 
     							1 ----> 2
     							1 ----> 3
     							2 ----> 3
     • in this graph there are 2 ways to visit vertex 3:
       1). from 1 to 3
       2). from 1 to 2 to 3

       But it does not contain a cycle.
   # ∴ the same algo used in "Cycle Detection in an UG.cpp" can't be used.

   # 𝑨 𝑩𝑨𝑪𝑲𝑬𝑫𝑮𝑬 𝑰𝑺 𝑨𝑵 𝑬𝑫𝑮𝑬 𝑭𝑹𝑶𝑴 𝑨 𝑮𝑰𝑽𝑬𝑵 𝑵𝑶𝑫𝑬 𝑻𝑶 𝑨𝑵 𝑨𝑵𝑪𝑬𝑺𝑻𝑶𝑹 𝑶𝑭 𝑻𝑯𝑨𝑻 𝑵𝑶𝑫𝑬 𝑰𝑵 𝑻𝑯𝑬 𝑺𝑨𝑴𝑬 𝑷𝑨𝑻𝑯 
     𝑰𝑵 𝑨 𝑫𝑮.

   # So to check cycle in a DG we maintain a 𝒔𝒕𝒂𝒄𝒌 𝑨𝑹𝑹𝑨𝒀(it is also a bool array) in addition to 
     the visited array.

     • As we know visited[] array basically keeps a check abput whether a given vertex has already 
       been visited at some poit of time or not.

     • But here the extra data structure used which is the stack array (remember it is an array only, 
       only the name stack is used to convey the message that it will work almost similar to stack, 
       but in order to have a constant lookup time for a vertex an array is used in place of stack).

     • The stack[i] will be true for a vertex 'i' if the vertex is 𝒂 𝒑𝒂𝒓𝒕 𝒐𝒇 𝒕𝒉𝒆 𝒄𝒖𝒓𝒓𝒆𝒏𝒕 𝒑𝒂𝒕𝒉.
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

// to keep track, whether any vertex 'i' is part of the current stack
vb stk_flag;

// to keep track of visited vertices
vb vis;

int n, m;

// function which returns whether the subtree rooted at the current node contains 
// cycle or not
bool is_cycle(int cur) {
    // marking a node visited as soon as it is pushed in internal call stack
    vis[cur] = 1;
    
    // cur now becomes a part of the current path
    stk_flag[cur] = 1;
    
    // now there can be 2 cases ===>
    // case 1. either the neighbour of the cur vertex is not visited yet, in 
    //         such a case recursively visit the neighbours check for cycle.
    // case 2. the neighbour is visited and is also a part of the current path,
    //         then the graph contains cycle
    
    for(auto x: g[cur]) {
        // case 1
        if(!vis[x]) {
            if(is_cycle(x)) return 1;
        }
        
        // case 2
        else if(stk_flag[x]) return 1;
    }
    
    // removing the current vertex i.e. cur from the current path
    // when recursion moves in backward direction
    stk_flag[cur] = 0;
    
    // if the above 2 cases fails then no cycle present
    return 0;
}

bool contains_cycle() {
    for(int i = 0; i < n; i++) {
        vis[i] = stk_flag[i] = 0;
    }
    
    bool res = 0;
    
    // taking care of multiple components in the graph
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            bool tmp = is_cycle(i);
            res |= tmp;
        }
    }
    
    return res;
}

void solve()
{
    cin >> n >> m;
    
    g.clear(); g.resize(n);
    vis.clear(); vis.resize(n, 0);
    stk_flag.clear(); stk_flag.resize(n, 0);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
    }
        
    if(contains_cycle()) cout << "YES\n";
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

// NOTE: Instead of using 2 separate vectors "vis" and "stk_flag", the algorithm can also be implemented using a single vector.

/****************************************************************************************************************************************************************/

// METHOD - 2 (USING BFS, by making use of Kahn's algorithm)
// Ref: https://www.youtube.com/watch?v=iTBaI90lpDQ&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=24&ab_channel=takeUforward

/* UNDERLYING CONCEPT ------>

   # If we can't determine the topological ordering of all the vertices of a DG, the graph has a cycle
     in it i.e. for a directed cyclic graph : res.size() != #vertices.
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

// to store the indegree of vertices
vi indegree;

int n, m;

// function which returns topological ordering of the graph
vi top_sort() {
    // to process nodes one by one
    queue<int> q;
    
    // find all sources i.e., all vertices with 0 in-degrees
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i); 
    }
    
    // to store the topological ordering
    vi res;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        res.pb(cur);
        
        for(auto x: g[cur]) {
            indegree[x] -= 1;
            if(indegree[x] == 0) q.push(x);
        }   
    }
    
    // topological sort is not possible if the graph has a cycle
    if(sz(res) != n) res.clear();
    
    return res;
}

bool contains_cycle() {
    vi topo = top_sort();
    
    // if topological ordering not possible <===> cycle present
    return (sz(topo) != n);
}

void solve()
{
    cin >> n >> m;
    
    g.clear(); g.resize(n);
    indegree.clear(); indegree.resize(n, 0);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        indegree[y] += 1;
    }
   
    if(contains_cycle()) cout << "YES\n";
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