// Problem: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#

// Ref: https://takeuforward.org/data-structure/rat-in-a-maze/

/**************************************************************************************************************************************************************/

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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;

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

// to store all the paths
vector<string> res;

// this is required so that a cell is included only once for a particular path
vvb vis;

string dir = "DLRU";

// directions are taken in such a manner so that the results come out in a lexicographical order
vi dx = {1, 0, 0, -1};
vi dy = {0, -1, 1, 0};

bool is_safe(int i, int j, vvi &maze, int n, int m) {
	if(i >= 0 and i < n and j >= 0 and j < m and maze[i][j] == 1 and vis[i][j] == 0) return 1;
	return 0;
}

void rat_in_maze(vvi &maze, int i, int j, int n, int m, string &path) {
	// base case(s)
	if(i == (n - 1) and j == (m - 1)) {
		res.pb(path);
		return;
	}
	
	vis[i][j] = 1;
	
	for(int d = 0; d < 4; d++) {
		int nx = i + dx[d], ny = j + dy[d];
		if(is_safe(nx, ny, maze, n, m)) {
			path.pb(dir[d]);
			rat_in_maze(maze, nx, ny, n, m, path);
			path.ppb();
		}
	}
		
	vis[i][j] = 0;
	
	return;
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vvi maze(n, vi(m));
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cin >> maze[i][j];
  	}
  	
  	res.clear();
  	vis.clear();
  	vis.resize(n, vb(m, false));
  	
  	string path = "";
  	
  	if(maze[0][0] == 1) rat_in_maze(maze, 0, 0, n, m, path);
  	
  	for(auto str: res) cout << str << "\n";
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

// Time Complexity: O(4^(n * m)) (Not sure if this is correct).
// Space Complexity for recursion overhead: O(n * m), since at a time there could be at most O(n * m) function
//                                          calls in the recursive call stack. (Not sure if this is correct).