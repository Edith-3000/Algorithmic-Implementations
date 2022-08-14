// Ref: https://www.scaler.com/topics/data-structures/shortest-path-in-directed-acyclic-graph/
//      https://www.youtube.com/watch?v=CrxG4WJotgg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=16&ab_channel=takeUforward
//      https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/

// Intuition:--->
// # See the first "Highlighted comment" in https://www.youtube.com/watch?v=CrxG4WJotgg&lc=UgxxsI2V_oSbqfKUpxB4AaABAg
// # https://www.youtube.com/watch?v=BNpWnXUhMC4&ab_channel=5MinutesEngineering
// # https://stackoverflow.com/questions/37253739/intuition-behind-the-algorithm-to-compute-single-source-shortest-path-for-every
/********************************************************************************************************************************/

/* # NOTE: This algorithm is valid for +ve as well as -ve edge weights in a DAG.
   
   # In the below algorithm we are not checking if the graph has cycle or not before finding topological ordering,
     since it's mentioned that the i/p graph is a DAG.
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

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// stores the input graph
vector<vpii> g;

// to keep track of visited vertices
vb vis;

// n = #vertices, m = #edges in the i/p graph
int n, m;

// function which returns topological ordering of the component of which cur is a part
void top_sort_util(int cur, stack<int> &res) {
    // marking a node visited as soon as it is pushed in internal call stack
    vis[cur] = 1;
        
    for(auto x: g[cur]) {
        if(!vis[x.F]) top_sort_util(x.F, res);
    }
    
	// in the returning phase push cur to resolve all the dependencies
    res.push(cur);
}

stack<int> top_sort() {	
	for(int i = 0; i < n; i++) vis[i] = 0;
	
	// to store the topological ordering
	stack<int> res;
	
	// taking care of multiple components in the graph
	for(int i = 0; i < n; i++) {
		if(!vis[i]) top_sort_util(i, res);
	}
	
	return res;
}

vi sssp_in_DAG(int src) {
	stack<int> stk = top_sort();
	
	// to store the distance of all vertices from src vertex
    vi d(n);
    
    // initialising the distances of all nodes from src as infinity (i.e. very large)
    for(int i = 0; i < n; i++) d[i] = INF;
    
    // the minimum distance of src from itself = 0
    d[src] = 0;
    
    while(!stk.empty()) {
    	int cur = stk.top();
    	stk.pop();
    	
    	if(d[cur] != INF) {
    		for(auto x: g[cur]) {
    			if((d[cur] + x.S) < d[x.F]) {
    				d[x.F] = d[cur] + x.S;
    			}
    		}
    	}
    }
    
    return d;
}

void solve()
{
  	cin >> n >> m;
    
    g.clear(); g.resize(n);
    vis.clear(); vis.resize(n, 0);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y, wt; cin >> x >> y >> wt;
        g[x].pb({y, wt});
    }
        
    // source from which shortest path to each node to be calculated
    int src; cin >> src;
    
    vi res = sssp_in_DAG(src);
    
    for(int i = 0; i < n; i++) {
    	cout << "Shortest distance of " << i << " from " << src << ": " << res[i] << "\n";
    }
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

/*

Sample i/p :--->

6 8
0 2 5
0 5 7
1 0 5
1 4 2
2 3 -2
4 5 4
4 0 2
5 2 -1
4

Sample o/p :--->

Shortest distance of 0 from 4: 2
Shortest distance of 1 from 4: 1061109567
Shortest distance of 2 from 4: 3
Shortest distance of 3 from 4: 1
Shortest distance of 4 from 4: 0
Shortest distance of 5 from 4: 4

*/