// Ref: https://cp-algorithms.com/graph/depth-first-search.html

/********************************************************************************************************************************************************************/

// LEGACY CONTENT: https://gist.github.com/Edith-3000/5f49c125697032239ef21c07ca398971

/********************************************************************************************************************************************************************/

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

// stores the input graph
vvi g;

// tin[i] = entry time of vertex 'i' while dfs traversal
// tout[i] = exit time of vertex 'i' while dfs traversal
vi tin, tout;

// we will color all vertices with the color 0, if we haven't visited them, 
// with the color 1 if we visited them, and with the color 2, if we already exited the vertex.
vi color;

// timer is used to store the running time while traversal, 
// in last after dfs traversal completion, timer will be = (2 * n).
int dfs_timer;

// n = #nodes, m = #edges in i/p graph
int n, m;

void dfs_helper(int cur) {
    color[cur] = 1;
    tin[cur] = dfs_timer++;
    
    for(auto x: g[cur]) {
        if(color[x] == 0) dfs_helper(x);
    }
    
    tout[cur] = dfs_timer++;
    color[cur] = 2;
} 

void dfs() {
    // initialisations
    tin.clear(); tin.resize(n, 0);
    tout.clear(); tout.resize(n, 0);
    
    color.clear(); color.resize(n, 0);
    
    dfs_timer = 0;
    
    for(int i = 0; i < n; i++) {
        if(color[i] == 0) dfs_helper(i);
    }
}

void solve()
{
    cin >> n >> m;
    
    vset(g, n, vi(0));
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
        
    dfs();
    
    cout << dfs_timer << "\n";
    
    for(int i = 0; i < n; i++) {
        cout << i << "-> (" << tin[i] << ", " << tout[i] << ")\n";
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