// Prob: https://leetcode.com/problems/cherry-pickup/
/******************************************************************************************************************/

// NOTE: TILL NOW ALL THE BELOW ALGORITHMS ARE NOT COMPLETELY TESTED

// METHOD - 1 (RECURSIVE APPROACH)

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

const int INF = 1e8;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

vi dx = {-1, 0, 1, 0};
vi dy = {0, 1, 0, -1};

bool is_valid(int x, int y, int n, int m, vvi &v) {
	return ((x >= 0) and (x < n) and (y >= 0) and (y < m) and (v[x][y] != -1));
}

int helper_2(int i, int j, int n, int m, vvi &v) {
	// base case(s)
	if((i == 0) and (j == 0)) {
		if(v[i][j] == -1) return -INF;
		else if(v[i][j] == 0) return 0;
		else return 1;
	}
	
	if(v[i][j] == -1) return -INF;
	
	int mx = -INF, curr_cell_contri = 0;
	bool flag = 0;
	
	if(v[i][j] == 1) {
		flag = 1;
		curr_cell_contri = 1;
		v[i][j] = 0;
	}
	
	for(int d = 0; d < 4; d++) {
		if((d == 1) or (d == 2)) continue;
		
		int nx = i + dx[d], ny = j + dy[d];
		if(!is_valid(nx, ny, n, m, v)) continue;
		
		int tmp_ans = helper_2(nx, ny, n, m, v);
		
		mx = max(mx, tmp_ans);
	}
	
	if(flag) v[i][j] = 1;
	
	int res;
	
	if(mx == -INF) res = mx;
	else res = mx + curr_cell_contri;
	
	return res;
}

int helper_1(int i, int j, int n, int m, vvi &v) { 
	// base case(s)
	if((i == n - 1) and (j == m - 1)) { 
		if(v[i][j] == -1) return -INF;
		else if(v[i][j] == 0) return helper_2(i, j, n, m, v);
		else {
			int res = helper_2(i, j, n, m, v);
			if(res == -INF) res = 0;			
			return res;
		}
	}
	
	if(v[i][j] == -1) return -INF;
	
	int mx = -INF, curr_cell_contri = 0;
	bool flag = 0;
	
	if(v[i][j] == 1) {
		flag = 1;
		curr_cell_contri = 1;
		v[i][j] = 0;
	}
	
	for(int d = 0; d < 4; d++) {
		if((d == 0) or (d == 3)) continue;
		
		int nx = i + dx[d], ny = j + dy[d];
		if(!is_valid(nx, ny, n, m, v)) continue;
		
		int tmp_ans = helper_1(nx, ny, n, m, v);
		
		mx = max(mx, tmp_ans); 
	}
	
	if(flag) v[i][j] = 1;
	
	int res;
	
	if(mx == -INF) res = mx; 
	else res = mx + curr_cell_contri;
	
	return res;
}

int cherry_pickup(vvi &v) {
	int n = sz(v);
	if(n == 0) return 0;
	
	int m = sz(v[0]);
	
	int res = helper_1(0, 0, n, m, v);
	if(res == -INF) res = 0;
	
	return res;
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vvi v(n, vi(m));
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cin >> v[i][j];
  	}
  	
  	cout << cherry_pickup(v) << "\n";
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

/****************************************************************************************************************/

// METHOD - 2 (TOP DOWN DP APPROACH)

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

const int INF = 1e8;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

vi dx = {-1, 0, 1, 0};
vi dy = {0, 1, 0, -1};

bool is_valid(int x, int y, int n, int m, vvi &v) {
	return ((x >= 0) and (x < n) and (y >= 0) and (y < m) and (v[x][y] != -1));
}

int helper_2(int i, int j, int n, int m, vvi &v, vvi &dp_2) {
	// base case(s)
	if((i == 0) and (j == 0)) {
		if(v[i][j] == -1) return -INF;
		else if(v[i][j] == 0) return 0;
		else return 1;
	}
	
	if(v[i][j] == -1) return -INF;
	
	// check if already calculated or not
	if(dp_2[i][j] != -1) return dp_2[i][j];
	
	int mx = -INF, curr_cell_contri = 0;
	bool flag = 0;
	
	if(v[i][j] == 1) {
		flag = 1;
		curr_cell_contri = 1;
		v[i][j] = 0;
	}
	
	for(int d = 0; d < 4; d++) {
		if((d == 1) or (d == 2)) continue;
		
		int nx = i + dx[d], ny = j + dy[d];
		if(!is_valid(nx, ny, n, m, v)) continue;
		
		int tmp_ans = helper_2(nx, ny, n, m, v, dp_2);
		
		mx = max(mx, tmp_ans);
	}
	
	if(flag) v[i][j] = 1;
	
	int res;
	
	if(mx == -INF) res = mx;
	else res = mx + curr_cell_contri;
	
	return dp_2[i][j] = res;
}

int helper_1(int i, int j, int n, int m, vvi &v, vvi &dp_1, vvi &dp_2) { 
	// base case(s)
	if((i == n - 1) and (j == m - 1)) { 
		if(v[i][j] == -1) return -INF;
		else if(v[i][j] == 0) return helper_2(i, j, n, m, v, dp_2);
		else {
			int res = helper_2(i, j, n, m, v, dp_2);
			if(res == -INF) res = 0;			
			return res;
		}
	}
	
	if(v[i][j] == -1) return -INF;
	
	// check if already calculated or not
	if(dp_1[i][j] != -1) return dp_1[i][j];
	
	int mx = -INF, curr_cell_contri = 0;
	bool flag = 0;
	
	if(v[i][j] == 1) {
		flag = 1;
		curr_cell_contri = 1;
		v[i][j] = 0;
	}
	
	for(int d = 0; d < 4; d++) {
		if((d == 0) or (d == 3)) continue;
		
		int nx = i + dx[d], ny = j + dy[d];
		if(!is_valid(nx, ny, n, m, v)) continue;
		
		int tmp_ans = helper_1(nx, ny, n, m, v, dp_1, dp_2);
		
		mx = max(mx, tmp_ans); 
	}
	
	if(flag) v[i][j] = 1;
	
	int res;
	
	if(mx == -INF) res = mx; 
	else res = mx + curr_cell_contri;
	
	return dp_1[i][j] = res;
}

int cherry_pickup(vvi &v) {
	int n = sz(v);
	if(n == 0) return 0;
	
	int m = sz(v[0]);
	
	vvi dp_1(n, vi(m, -1)), dp_2(n, vi(m, -1));
	
	int res = helper_1(0, 0, n, m, v, dp_1, dp_2);
	if(res == -INF) res = 0;
	
	return res;
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vvi v(n, vi(m));
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cin >> v[i][j];
  	}
  	
  	cout << cherry_pickup(v) << "\n";
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
