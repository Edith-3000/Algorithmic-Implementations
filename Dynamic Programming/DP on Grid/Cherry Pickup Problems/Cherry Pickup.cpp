// Prob: https://leetcode.com/problems/cherry-pickup/

// Ref: https://www.youtube.com/watch?v=juJ0j-Otgko&ab_channel=Pepcoding
//      https://www.youtube.com/watch?v=ZV0sUzfA7Eg&ab_channel=Pepcoding
/******************************************************************************************************************/

// METHOD - 1.1 (RECURSIVE APPROACH)

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

    int res = -INF, cherry = v[i][j];
    v[i][j] = 0;

    for(int d = 0; d < 4; d++) {
        if((d == 1) or (d == 2)) continue;

        int nx = i + dx[d], ny = j + dy[d];
        if(!is_valid(nx, ny, n, m, v)) continue;

        int tmp_ans = helper_2(nx, ny, n, m, v);
        if(tmp_ans != -INF) tmp_ans += cherry;

        res = max(res, tmp_ans);
    }
    
    v[i][j] = cherry;
   
    return res;
}

int helper_1(int i, int j, int n, int m, vvi &v) { 
    // base case(s)
    if((i == n - 1) and (j == m - 1)) { 
        if(v[i][j] == -1) return -INF;
        else return helper_2(i, j, n, m, v);
    }

    if(v[i][j] == -1) return -INF;

    int res = -INF, cherry = v[i][j];
    v[i][j] = 0;

    for(int d = 0; d < 4; d++) {
        if((d == 0) or (d == 3)) continue;

        int nx = i + dx[d], ny = j + dy[d];
        if(!is_valid(nx, ny, n, m, v)) continue;

        int tmp_ans = helper_1(nx, ny, n, m, v);
        if(tmp_ans != -INF) tmp_ans += cherry;
        
        res = max(res, tmp_ans); 
    }

    v[i][j] = cherry;
    
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

// CAUTION: The above recursive solution when converted into a DP solution like this:--->
//          https://pastebin.com/epueSNUR
//          Won't give correct result.

// THINK WHY!

/****************************************************************************************************************/

// METHOD - 1.2 (RECURSIVE APPROACH)

/* # Main concept of this algorithm ===>

     STATEMENT 1: Starting a person from (0, 0) to reach (n - 1, m - 1) and again starting from (n - 1, m - 1) 
                  to reach (0, 0) to collect cherries.

	 STATEMENT 2: Starting 2 persons from (0, 0) to reach (n - 1, m - 1) to collect cherries..
	 
	 In context of this problem STATEMENT 1 is equivalent to STATEMENT 2.
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

const int INF = 1e8;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

vi dx = {0, 1};
vi dy = {1, 0};

bool is_valid(int x, int y, int n, int m, vvi &v) {
    return ((x >= 0) and (x < n) and (y >= 0) and (y < m) and (v[x][y] != -1));
}

// cherry_pickup() helper function
int helper(int r1, int c1, int r2, int c2, int n, int m, vvi &v) {
	// base case(s)
	if((r1 == n - 1) and (c1 == m - 1) and (r2 == n - 1) and (c2 == m - 1)) {
		if(v[r1][c1] == -1) return -INF;
		else return v[r1][c1];
	}
	
	if((v[r1][c1] == -1) or (v[r2][c2] == -1)) return -INF;
	
	int res = -INF;
	int cherry1 = v[r1][c1], cherry2 = v[r2][c2], cherries;
	
	if((r1 == r2) and (c1 == c2)) cherries = cherry1;
	else cherries = cherry1 + cherry2;
	
	v[r1][c1] = v[r2][c2] = 0;
	
	for(int d1 = 0; d1 < 2; d1++) {
		int nx1 = r1 + dx[d1], ny1 = c1 + dy[d1];
		
		for(int d2 = 0; d2 < 2; d2++) {
			int nx2 = r2 + dx[d2], ny2 = c2 + dy[d2];
			
			bool ok1 = is_valid(nx1, ny1, n, m, v);
			bool ok2 = is_valid(nx2, ny2, n, m, v);
			
			int tmp_ans = -INF;
			
			if(ok1 and ok2) {
				tmp_ans = helper(nx1, ny1, nx2, ny2, n, m, v);
			}
			
			if(tmp_ans != -INF) tmp_ans += cherries;
			
			res = max(res, tmp_ans);			
		}
	}
	
	v[r1][c1] = cherry1;
	v[r2][c2] = cherry2;
	
	return res;
}

int cherry_pickup(vvi &v) {
	int n = sz(v);
	if(n == 0) return 0;
	
	int m = sz(v[0]);
	
	int res = helper(0, 0, 0, 0, n, m, v);
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

// METHOD - 2.1 (TOP DOWN DP APPROACH)

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

vi dx = {0, 1};
vi dy = {1, 0};

int dp[50][50][50][50];

bool is_valid(int x, int y, int n, int m, vvi &v) {
    return ((x >= 0) and (x < n) and (y >= 0) and (y < m) and (v[x][y] != -1));
}

// cherry_pickup() helper function
int helper(int r1, int c1, int r2, int c2, int n, int m, vvi &v) {
	// base case(s)
	if((r1 == n - 1) and (c1 == m - 1) and (r2 == n - 1) and (c2 == m - 1)) {
		if(v[r1][c1] == -1) return -INF;
		else return v[r1][c1];
	}
	
	if((v[r1][c1] == -1) or (v[r2][c2] == -1)) return -INF;
	
	// check if already calculated
	if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
	
	int res = -INF;
	int cherry1 = v[r1][c1], cherry2 = v[r2][c2], cherries;
	
	if((r1 == r2) and (c1 == c2)) cherries = cherry1;
	else cherries = cherry1 + cherry2;
	
	v[r1][c1] = v[r2][c2] = 0;
	
	for(int d1 = 0; d1 < 2; d1++) {
		int nx1 = r1 + dx[d1], ny1 = c1 + dy[d1];
		
		for(int d2 = 0; d2 < 2; d2++) {
			int nx2 = r2 + dx[d2], ny2 = c2 + dy[d2];
			
			bool ok1 = is_valid(nx1, ny1, n, m, v);
			bool ok2 = is_valid(nx2, ny2, n, m, v);
			
			int tmp_ans = -INF;
			
			if(ok1 and ok2) {
				tmp_ans = helper(nx1, ny1, nx2, ny2, n, m, v);
			}
			
			if(tmp_ans != -INF) tmp_ans += cherries;
			
			res = max(res, tmp_ans);			
		}
	}
	
	v[r1][c1] = cherry1;
	v[r2][c2] = cherry2;
	
	return dp[r1][c1][r2][c2] = res;
}

int cherry_pickup(vvi &v) {
	int n = sz(v);
	if(n == 0) return 0;
	
	int m = sz(v[0]);
	
	memset(dp, -1, sizeof dp);
	
	int res = helper(0, 0, 0, 0, n, m, v);
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

// METHOD - 2.2 (Space Optimization of METHOD 2.1)

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

vi dx = {0, 1};
vi dy = {1, 0};

int dp[50][50][50];

bool is_valid(int x, int y, int n, int m, vvi &v) {
    return ((x >= 0) and (x < n) and (y >= 0) and (y < m) and (v[x][y] != -1));
}

// cherry_pickup() helper function
int helper(int r1, int c1, int r2, int n, int m, vvi &v) {
	// find c2 from the equation (r1 + c1) = (r2 + c2)
	int c2 = (r1 + c1) - r2;
	
	// base case(s)
	if((r1 == n - 1) and (c1 == m - 1) and (r2 == n - 1) and (c2 == m - 1)) {
		if(v[r1][c1] == -1) return -INF;
		else return v[r1][c1];
	}
	
	if((v[r1][c1] == -1) or (v[r2][c2] == -1)) return -INF;
	
	// check if already calculated
	if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
	
	int res = -INF;
	int cherry1 = v[r1][c1], cherry2 = v[r2][c2], cherries;
	
	if((r1 == r2) and (c1 == c2)) cherries = cherry1;
	else cherries = cherry1 + cherry2;
	
	v[r1][c1] = v[r2][c2] = 0;
	
	for(int d1 = 0; d1 < 2; d1++) {
		int nx1 = r1 + dx[d1], ny1 = c1 + dy[d1];
		
		for(int d2 = 0; d2 < 2; d2++) {
			int nx2 = r2 + dx[d2], ny2 = c2 + dy[d2];
			
			bool ok1 = is_valid(nx1, ny1, n, m, v);
			bool ok2 = is_valid(nx2, ny2, n, m, v);
			
			int tmp_ans = -INF;
			
			if(ok1 and ok2) {
				tmp_ans = helper(nx1, ny1, nx2, n, m, v);
			}
			
			if(tmp_ans != -INF) tmp_ans += cherries;
			
			res = max(res, tmp_ans);			
		}
	}
	
	v[r1][c1] = cherry1;
	v[r2][c2] = cherry2;
	
	return dp[r1][c1][r2] = res;
}

int cherry_pickup(vvi &v) {
	int n = sz(v);
	if(n == 0) return 0;
	
	int m = sz(v[0]);
	
	memset(dp, -1, sizeof dp);
	
	int res = helper(0, 0, 0, n, m, v);
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