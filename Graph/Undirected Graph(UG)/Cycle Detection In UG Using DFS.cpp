// 𝑨𝒏 𝑼𝒏𝒅𝒊𝒓𝒆𝒄𝒕𝒆𝒅 𝑮𝒓𝒂𝒑𝒉(𝑼𝑮) 𝒄𝒐𝒏𝒕𝒂𝒊𝒏𝒔 𝒂 𝒄𝒚𝒄𝒍𝒆 𝒊𝒇 𝒕𝒉𝒆𝒓𝒆 𝒊𝒔 𝑴𝑶𝑹𝑬 𝑻𝑯𝑨𝑵 1 𝒘𝒂𝒚 𝒕𝒐 𝒗𝒊𝒔𝒊𝒕 𝒂 𝒏𝒐𝒅𝒆/𝒗𝒆𝒓𝒕𝒆𝒙.
/****************************************************************************************************/

// METHOD - 1 (USING DFS)

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

// to keep track of visited nodes
vi vis;

int n, m;

// function which returns whether the subtree rooted at the current node contains 
// cycle or not
bool is_cycle(int cur, int par) {
	// marking a node visited as soon as it is pushed in internal call stack
	vis[cur] = 1;
	
	// now there can be 2 cases ===>
	// case 1. either the neighbour of the cur vertex is not visited yet, in 
	//         such a case recursively visit the neighbours check for cycle.
	// case 2. the neighbour is visited and != parent(cur), (i.e backedge is present)
	//         then the graph contains cycle
	
	for(auto x: g[cur]) {
		// case 1
		if(!vis[x]) {
			if(is_cycle(x, cur)) return 1;
		}
		
		// case 2
		else if(x != par) return 1;
	}
	
	// if the above 2 cases fails then no cycle present
	return 0;
}

bool contains_cycle() {
	for(int i = 0; i < n; i++) vis[i] = 0;
	
	// taking care of multiple components in the graph
	for(int i = 0; i < n; i++) {
  		if(!vis[i]) {
  			if(is_cycle(i, -1)) return 1;
  		}
  	}
  	
  	return 0;
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

// Time Complexity ≡ DFS traversal
// Here n is the number of vertices in the UG.

/*****************************************************************************************************/

// METHOD - 2 (USING BFS)
// Ref: https://www.youtube.com/watch?v=A8ko93TyOns&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=8