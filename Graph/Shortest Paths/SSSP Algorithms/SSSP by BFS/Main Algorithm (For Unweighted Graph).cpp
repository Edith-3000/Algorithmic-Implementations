// Ref: https://www.geeksforgeeks.org/shortest-path-unweighted-graph/

/* UNDERLYING CONCEPT:
   # The idea is to use a slightly modified version of Breadth-first search.

   # 𝑭𝒐𝒓 𝒂𝒏 𝑼𝑵𝑾𝑬𝑰𝑮𝑯𝑻𝑬𝑫 𝑮𝑹𝑨𝑷𝑯(𝒊.𝒆. 𝒂𝒍𝒍 𝒆𝒅𝒈𝒆𝒔 𝒉𝒂𝒗𝒊𝒏𝒈 𝒕𝒉𝒆 𝑺𝑨𝑴𝑬 𝒘𝒆𝒊𝒈𝒉𝒕/𝒄𝒐𝒔𝒕) 𝒕𝒉𝒆 𝒍𝒆𝒗𝒆𝒍 𝒐𝒓𝒅𝒆𝒓 𝒕𝒓𝒂𝒗𝒆𝒓𝒔𝒂𝒍
     (𝑩𝑭𝑺) 𝒈𝒊𝒗𝒆𝒔 𝒕𝒉𝒆 𝒔𝒉𝒐𝒓𝒕𝒆𝒔𝒕 𝒑𝒂𝒕𝒉.
*/

// # The Analysis of SSSP Algorithm using BFS ≡ Analysis of breadth-first search

/**************************************************************************************************************/

// METHOD - 1
// It gives only the distance array, for find the path also, refer METHOD - 2

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

void solve()
{
  	cin >> n >> m;
  	
    g.clear(); 
    g.resize(n);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    // source from which shortest path to each node to be calculated
    int src; cin >> src;
    
    vi res = sssp_by_bfs(src);
    
    for(int i = 0; i < n; i++) {
    	cout << "Shortest distance of " << i << " from " << src << ": " << res[i] << "\n";
    }
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

/**********************************************************************************************************/

// METHOD - 2
// Gives the distance array, as well as return the paths also.

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

// n = #vertices, m = #edges
int n, m;

vi sssp_by_bfs(int src) {
    // to store the distance of all vertices from src vertex, it'll also be used to
    // check if a vertex is already visited or not
    vi d(n);
    
    // parent[i] stores the immediate parent of ith node in the 
    // shortest path from src to this node
    vi parent(n, -1);
    
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
             	
             	// mark the immediate parent of nbr as cur
             	parent[nbr] = cur;
        	}
		}
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
        
    return d;
}

void solve()
{
  	cin >> n >> m;
  	
    g.clear(); 
    g.resize(n);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    
    // source from which shortest path to each node to be calculated
    int src; cin >> src;
    
    vi res = sssp_by_bfs(src);
    
    for(int i = 0; i < n; i++) {
    	cout << "Shortest distance of " << i << " from " << src << ": " << res[i] << "\n";
    }
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