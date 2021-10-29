/* # Ref: https://cp-algorithms.com/graph/cutpoints.html
          https://www.youtube.com/watch?v=T1AhBniNIUk&list=PLb3g_Z8nEv1hr9Cf2wIQaHGOF5ROPLohd&index=4
          https://codeforces.com/blog/entry/68138
*/

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

vvi g;
vi tin, low, vis;
set<int> points; // set is used so as to avoid putting same vertex as cut vertex multiple times
int timer;
int n, m;

void dfs(int cur, int par) {
    vis[cur] = 1;
    tin[cur] = low[cur] = timer++;
    int children = 0;
    
    for(auto x: g[cur]) {
        if(vis[x] == 0) {
            dfs(x, cur);
            low[cur] = min(low[cur], low[x]);
            if(low[x] >= tin[cur] and par != -1) points.insert(cur);
            children += 1;
        }
        
        else {
            if(x == par) continue;
            else low[cur] = min(low[cur], tin[x]);
        }
    }
    
    // separate case for the root of the DFS TREE of the graph to be a cut vertex
    if(par == -1 and children > 1) {
        points.insert(cur);
    }
}

// tin[i] = the entry time of each vertex in the DFS Tree.

// low[i] = it is the minimum of entry(or discovery) times of all the vertices that are pointed by a 
//          backedge from any of the vertex present in the subtree (rooted at 'i') of the vertex 'i'.
//          If vertex 'i' has no children or there is no backedge present in the subtree, then low[i] = entry[i]. 

// vis[i] = to keep track whether i has been visited or not.

// timer is used to store the running time, in last after dfs traversal timer will be = (2 * n + 1).

// Function to find all the articulation points (cut vertices) in an undirected graph
void find_cutpoints() {
    tin.clear(); tin.resize(n + 1, 0);
    low.clear(); low.resize(n + 1, 0);
    vis.clear(); vis.resize(n + 1, 0);
    points.clear();
    timer = 1;
    
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) dfs(i, -1);
    }
}

void solve()
{
    cin >> n >> m;
    
    vset(g, n + 1, vi(0));
    
    // 1-based indexed vertices
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; 
        g[x].pb(y);
        g[y].pb(x);
    }
    
    find_cutpoints();
    
    cout << "#points = " << sz(points) << "\n";
    for(auto x: points) cout << x << "\n";
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