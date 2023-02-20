// Ref: https://www.youtube.com/watch?v=DMnDM_sxVig&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=48&ab_channel=takeUforward
//      https://www.youtube.com/watch?v=1KRmCzBl_mQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=25&ab_channel=takeUforward

/* # UNDERLYING CONCEPTS ===>

   # Kruskal's algorithm to find the minimum cost spanning tree uses the greedy approach. 

   # This algorithm treats the graph as a forest and every node it has as an individual tree
     (i.e. n connected components initially). 

   # A tree connects to another only and only if, it has the least cost among all available options and 
     does not violate MST properties.

   # Algorithm ---->

     1. Remove all loops and Parallel Edges.
        (In case of parallel edges, keep the one which has the least cost associated and remove all others.)

     2. Sort all edges in their increasing order of weight.

     3. Repeatedly add the first (n-1) edges which have the least weightage, iff it does not form a cycle
        i.e. add the least cost edge one by one whose vertices are present in 2 different connected components.
*/

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

// to store the input edges
vvi edges;

// n = #vertices, m = #edges in input graph
int n, m;

// CAUTION : use 0-based indexing for the nodes
struct dsu {
    vi parent, siz;
    
    dsu(int n) {
        parent.clear(); parent.resize(n);
        siz.clear(); siz.resize(n);
    }
    
    void make_set(int n) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            siz[i] = 1; 
        }
    }

    int find_set(int v) {
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        int s1 = find_set(a);
        int s2 = find_set(b);

        if(s1 != s2) {
            if(siz[s1] < siz[s2]) swap(s1, s2);
            parent[s2] = s1;
            siz[s1] += siz[s2];
        }
    }
};

bool cmp(const vi &v1, const vi &v2) {
    return v1[2] < v2[2];
}

// NOTE: the below algorithm assumes that the input graph is undirected connected,
//       since MST doesn't exist for a disconnected graph

// function to print and return the weight of MST
ll kruskals_algo() {
    // initialising DSU structure
    struct dsu d(n);
    d.make_set(n);
    
    // sorting on the basis of edge weight
    sort(edges.begin(), edges.end(), cmp);
    
    // in case you need the actual MST
    vvi MST;
    
    ll res = 0LL;  
   
    for(auto edg: edges) {
        int s1 = d.find_set(edg[0]);
        int s2 = d.find_set(edg[1]);
        
        // include the edge in MST iff it does not form a cycle (i.e. include in
        // MST if both the vertices of the edge belong to different sets)
        if(s1 != s2) {
            res += edg[2];
            MST.pb(edg);
            d.union_sets(s1, s2);
        }
    }
    
    return res; 
}

void solve()
{
    cin >> n >> m;

    edges.clear(); 
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y, wt; 
        cin >> x >> y >> wt;
        edges.pb({x, y, wt});
    }
    
    cout << kruskals_algo() << "\n";
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

// Time Complexity: O(|E| x log|E|) which in turn = O(|E| x log|V|)
// Refer: https://stackoverflow.com/questions/20432801/time-complexity-of-the-kruskal-algorithm