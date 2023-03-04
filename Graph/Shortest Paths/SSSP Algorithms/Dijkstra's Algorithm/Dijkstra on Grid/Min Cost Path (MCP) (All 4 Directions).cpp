// Prob: https://www.geeksforgeeks.org/minimum-cost-path-left-right-bottom-moves-allowed/

/*****************************************************************************************************************************************************************/

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

vi dx = {-1, 0, 1, 0};
vi dy = {0, 1, 0, -1};

struct node {
	int row, col, dist;
};

// BE SLIGHTLY CAUTIOUS WHILE WRITING CUSTOM COMPARATOR FUNCTIONS FOR std::set
// In case use want to use struct instead of class for cmp, refer ===>
// https://gist.github.com/Edith-3000/04f4ece8d5036bfcc457c9294bea2eda
class cmp {
	public:
		bool operator() (const node &n1, const node &n2) const {
			if(n1.dist == n2.dist) {
				if(n1.row != n2.row) return n1.row < n2.row;
				else return n1.col < n2.col;
			}
			
			else return n1.dist < n2.dist;
		}
};

bool is_valid(int x, int y, int n, int m) {
    return (x >= 0) and (x < n) and (y >= 0) and (y < m);
}

int dijkstra(int src_row, int src_col, vvi &v) {
	int n = sz(v), m = sz(v[0]);
	
    vvi d(n, vi(m));

    // to keep track of visited nodes
    vvb vis(n, vb(m, 0));
    
    // initialising the distances of all nodes from src as infinity
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < m; j++) d[i][j] = INT_MAX;
    }
    
    // the minimum distance of src from itself = 0
    d[src_row][src_col] = v[src_row][src_col];
    
    // set to repeatedly find out the node having 
    // minimum distance from src
    set<node, cmp> st;
    
    // inserting the src to initialise the process
    st.insert({src_row, src_col, d[src_row][src_col]});
    
    while(!st.empty()) {
        // extract the node which is currently at minimum distance from src
        auto [row, col, dist] = *(st.begin());
        
        st.erase(st.begin());
        
        if(vis[row][col] or dist == INT_MAX) continue;
        vis[row][col] = true;
        
        for(int k = 0; k < 4; k++) {
            int nx = row + dx[k], ny = col + dy[k];
            
            if(is_valid(nx, ny, n, m) == 0) continue;
            
            if((dist + v[nx][ny]) < d[nx][ny]) {
            	if(d[nx][ny] != INT_MAX) {
            		st.erase({nx, ny, d[nx][ny]});
            		// st.erase(st.find({nx, ny, d[nx][ny]}));
            	}
            	
            	d[nx][ny] = dist + v[nx][ny];
            	st.insert({nx, ny, d[nx][ny]});
            }
        }
    }
        
    return d[n - 1][m - 1];
}

// Function to compute minimum cost path from cell (0, 0) to cell (n - 1, m - 1),
// if left, right, upward or downward movement is allowed
int mcp(vvi &v) {
    int n = sz(v);
    if(n == 0) return 0;
    
    int m = sz(v[0]);
    
    return dijkstra(0, 0, v);
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vvi v(n, vi(m));
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cin >> v[i][j];
  	}
  	
  	int res = mcp(v);
  	
  	cout << res << "\n";
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