// Problem: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
//          https://www.geeksforgeeks.org/m-coloring-problem/

// Ref: https://takeuforward.org/data-structure/m-coloring-problem/

/****************************************************************************************************************************************************************/

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

vvi g;
vi color;

// nodes from 0 to (n - 1)
// colors from 1 to m
// cnt stores the total possible configurations
int n, m, cnt;

bool is_safe(int curr, int col) {
	for(int i = 0; i < n; i++) {
		if(i != curr and g[curr][i] == 1 and color[i] == col) {
			return false;
		}
	}
	
	return true;
}

bool m_coloring(int curr) {
	// base case(s)
	// just tweaked the base case to print all configurations i.e.
	// returned false even though a valid configuration was found
	if(curr == n) {
		cnt += 1;
		for(int i = 0; i < n; i++) cout << color[i] << " ";
		cout << "\n";
		return false; 
	}
	
	for(int col = 1; col <= m; col++) {
		if(is_safe(curr, col)) {
			color[curr] = col;
			bool next_node_mein_color_kar_paye = m_coloring(curr + 1);
			
			if(next_node_mein_color_kar_paye == true){
				return true;
			}
			
			else color[curr] = 0;
		}
	}
	
	return false;
}

void solve()
{
  	cin >> n >> m;
  	
  	g.clear();
  	g.resize(n, vi(n));
  	
  	color.clear();
  	color.resize(n, 0);
  	
  	cnt = 0;
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < n; j++) cin >> g[i][j];
  	}
  	
  	m_coloring(0);
  	if(cnt == 0) cout << "Not possible\n";
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

// Time Complexity: O(m^n).
// Auxiliary Space: O(n).
// Refer: https://www.geeksforgeeks.org/m-coloring-problem/