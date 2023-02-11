// Prob: https://leetcode.com/problems/shortest-path-with-alternating-colors/description/

// Ref: https://www.youtube.com/watch?v=95RzMmDl4m4&ab_channel=DeepCodes

/********************************************************************************************************************************************************************/

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

vi shortest_alternating_path_lengths(int n, vvi &red_edges, vvi &blue_edges) {
	vector<vpii> g(n);
	
	// 0 ==> denotes a red edge
	for(int i = 0; i < sz(red_edges); i++) {
		int x = red_edges[i][0], y = red_edges[i][1];
		g[x].pb({y, 0});
	}
	
	// 1 ==> denotes a blue edge
	for(int i = 0; i < sz(blue_edges); i++) {
		int x = blue_edges[i][0], y = blue_edges[i][1];
		g[x].pb({y, 1});
	}
	
	vi res(n, -1);
	res[0] = 0;
	
	// a queue element stores {node_id, it's shortest path length, color of edge via which it was visited}
	queue<vi> q;
	q.push({0, 0, -1});
	
	// visited[i][0] = to check if node i has been visited via a red edge
	// visited[i][1] = to check if node i has been visited via a blue edge
	vvb visited(n, vb(2, 0));	
	visited[0][0] = visited[0][1] = 1;
	
	while(!q.empty()) {
		int cur = q.front()[0], length = q.front()[1], color = q.front()[2];
		q.pop();
		
		for(auto [nbr, edg_color]: g[cur]) {
			if(!visited[nbr][edg_color] and edg_color != color) {
				visited[nbr][edg_color] = 1;
				q.push({nbr, length + 1, edg_color});
				
				if(res[nbr] == -1) res[nbr] = length + 1;
			}
		}
	}
	
	return res;
}

void solve()
{
  	int n, m, o; cin >> n >> m >> o;
  	
  	vvi red_edges(m, vi(2));
  	
  	for(int i = 0; i < m; i++) {
  		cin >> red_edges[i][0] >> red_edges[i][1];
  	}
  	
  	vvi blue_edges(o, vi(2));
  	
  	for(int i = 0; i < o; i++) {
  		cin >> blue_edges[i][0] >> blue_edges[i][1];
  	}
  	
  	vi res = shortest_alternating_path_lengths(n, red_edges, blue_edges);
  	
  	for(int i = 0; i < n; i++) {
  		cout << res[i] << " ";
  	}
  	
  	cout << "\n";
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