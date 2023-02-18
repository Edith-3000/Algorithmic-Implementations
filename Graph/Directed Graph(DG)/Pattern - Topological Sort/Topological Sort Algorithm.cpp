// Ref: https://www.youtube.com/watch?v=5lZ0iJMrUMk&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=24&ab_channel=takeUforward

/***************************************************************************************************************************************************************/

/* UNDERLYING CONCEPT ------>

   # The basic idea behind the topological sort is to provide a partial ordering among the vertices of the
     graph such that if there is an edge from U to V then U ≤ V i.e., U comes before V in the ordering. 
     Here are a few fundamental concepts related to topological sort:
 
 	* Source: Any node that has no incoming edge and has only outgoing edges is called a source.
 	* Sink: Any node that has only incoming edges and no outgoing edge is called a sink.
 
   # So, we can say that a topological ordering starts with one of the sources and ends at one of the sinks.
 
   # 𝑨 𝒕𝒐𝒑𝒐𝒍𝒐𝒈𝒊𝒄𝒂𝒍 𝒐𝒓𝒅𝒆𝒓𝒊𝒏𝒈 𝒊𝒔 𝒑𝒐𝒔𝒔𝒊𝒃𝒍𝒆 𝒐𝒏𝒍𝒚 𝒘𝒉𝒆𝒏 𝒕𝒉𝒆 𝒈𝒓𝒂𝒑𝒉 𝒉𝒂𝒔 𝒏𝒐 𝒅𝒊𝒓𝒆𝒄𝒕𝒆𝒅 𝒄𝒚𝒄𝒍𝒆𝒔, 𝒊.𝒆. 𝒊𝒇 𝒕𝒉𝒆 𝒈𝒓𝒂𝒑𝒉 𝒊𝒔 
     𝒂 𝑫𝒊𝒓𝒆𝒄𝒕𝒆𝒅 𝑨𝒄𝒚𝒄𝒍𝒊𝒄 𝑮𝒓𝒂𝒑𝒉 (𝑫𝑨𝑮). 
     
     If the graph has a cycle, some vertices will have cyclic dependencies which makes it impossible to find 
     a linear ordering among vertices.
*/

/***************************************************************************************************************************************************************/

// METHOD - 1.1 (USING DFS)

// First validating that the DG has no cycle.
// Then finding the topological ordering.

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

// function which returns topological ordering of the component of which cur is a part
void top_sort_util(int cur, vi &res) {
    // marking a node visited as soon as it is pushed in internal call stack
    vis[cur] = 1;
        
    for(auto x: g[cur]) {
        if(!vis[x]) top_sort_util(x, res);
    }
    
	// in the returning phase push cur to resolve all the dependencies
    res.pb(cur);
}

vi top_sort() {
	// firstly check the presence of cycle in the graph
	if(contains_cycle()) return vi();
	
	for(int i = 0; i < n; i++) vis[i] = 0;
	
	// to store the topological ordering
	vi res;
	
	// taking care of multiple components in the graph
	for(int i = 0; i < n; i++) {
		if(!vis[i]) top_sort_util(i, res);
	}
	
	// reverse the result vector to obtain top sort in correct order
	reverse(res.begin(), res.end());
	
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
        
    vi res = top_sort();
    
    if(sz(res) == 0) cout << "Top Sort not possible due to presence of cycle.\n";
    
    else {
    	for(auto x: res) cout << x << " ";
    	cout << "\n";
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

/***************************************************************************************************************************************************************/

// METHOD - 1.2 (USING DFS)

// This method simultaneously validates if the graph has cycle or not and find the topological 
// ordering as well.

// This method is shorter than METHOD - 1.1 and similar to the one used in the file --->
// "𝑷𝒓𝒐𝒃𝒍𝒆𝒎 - 1 (𝑩𝒂𝒔𝒆𝒅 𝒐𝒏 𝑻𝒐𝒑𝒐𝒍𝒐𝒈𝒊𝒄𝒂𝒍 𝑺𝒐𝒓𝒕).𝒄𝒑𝒑".

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

// function which returns topological ordering of the component of which cur is a part
void top_sort_util(int cur, vi &res, set<int> &ancestors, bool &possible) {
    // marking a node visited as soon as it is pushed in internal call stack
    vis[cur] = 1;
    
    // now this node becomes part of the current path
    ancestors.insert(cur);
      
    for(auto x: g[cur]) {
    	if(!vis[x]) top_sort_util(x, res, ancestors, possible);
    	
    	else if(ancestors.find(x) != ancestors.end()) {
			possible = 0;
			return;
		}
    }
    
    // remove cur from the current path
    ancestors.erase(cur);
    
	// in the returning phase push cur to resolve all the dependencies
    res.pb(cur);
}

vi top_sort() {
	for(int i = 0; i < n; i++) vis[i] = 0;
	
	// to store the topological ordering in reverse order
	vi res;
	
	// initially assuming that it is possible to find top sort
	// i.e. assuming DG has no cycle 
	bool possible = 1;
	
	// taking care of multiple components in the graph
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			set<int> ancestors;
			top_sort_util(i, res, ancestors, possible);
		}
	}
	
	// reverse the result vector to obtain top sort in correct order
	reverse(res.begin(), res.end());
	
    if(!possible) res.clear();

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
    }
        
    vi res = top_sort();
    
    if(sz(res) == 0) cout << "Top Sort not possible due to presence of cycle.\n";
    
    else {
    	for(auto x: res) cout << x << " ";
    	cout << "\n";
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

/***************************************************************************************************************************************************************/

// METHOD - 2 (USING BFS)

// Based on "Kahn’s algorithm"

// Ref: https://www.youtube.com/watch?v=73sneFXuTEg&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=23&ab_channel=takeUforward 
//      https://www.youtube.com/watch?v=rZv_jHZva34&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=14

/* # ALGORITHM ==============>

   # To find the topological sort of a graph we can traverse the graph in a Breadth First Search (BFS) way. 
     We will start with all the sources, and in a stepwise fashion, save all sources to a sorted list. 
     We will then remove all sources and their edges from the graph. After the removal of the edges, 
     we will have new sources, so we will repeat the above process until all vertices are visited.

    # Algorithmic steps --------->
     a. 𝑰𝒏𝒊𝒕𝒊𝒂𝒍𝒊𝒛𝒂𝒕𝒊𝒐𝒏
        1. We will store the graph in Adjacency Lists, which means each parent vertex will have a list 
           containing all of its children.
        2. To find the sources, we will keep a vector or hash map to count the in-degrees i.e., count 
           of incoming edges of each vertex. Any vertex with '0' in-degree will be a source.
     
     b. 𝑩𝒖𝒊𝒍𝒅 𝒕𝒉𝒆 𝒈𝒓𝒂𝒑𝒉 𝒂𝒏𝒅 𝒇𝒊𝒏𝒅 𝒊𝒏-𝒅𝒆𝒈𝒓𝒆𝒆𝒔 𝒐𝒇 𝒂𝒍𝒍 𝒗𝒆𝒓𝒕𝒊𝒄𝒆𝒔
        We will build the graph from the input and populate the in-degrees vector or hash map.

     c. 𝑭𝒊𝒏𝒅 𝒂𝒍𝒍 𝒔𝒐𝒖𝒓𝒄𝒆𝒔
        All vertices with ‘0’ in-degrees will be our sources and we will store them in a Queue.

     d. 𝑺𝒐𝒓𝒕
        For each source, do the following things:
        1. Add it to the sorted list.
        2. Get all of its children from the graph.
        3. Decrement the in-degree of each child by 1.
        4. If a child’s in-degree becomes ‘0’, add it to the sources Queue.
        5. Repeat step 1, until the source Queue is empty.
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
        
    vi res = top_sort();
    
    if(sz(res) == 0) cout << "Top Sort not possible due to presence of cycle.\n";
    
    else {
        for(auto x: res) cout << x << " ";
        cout << "\n";
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