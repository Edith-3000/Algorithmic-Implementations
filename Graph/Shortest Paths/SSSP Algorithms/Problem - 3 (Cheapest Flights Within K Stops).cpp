// Prob: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Ref: https://www.youtube.com/watch?v=vWgoPTvQ3Rw&ab_channel=ShiranAfergan
/*******************************************************************************************************************/

/* NOTE: For more info on the else if() condition in cheapest_flight_within_k_stops() see the "Highlighted comment"
         of the video below :--->
         https://www.youtube.com/watch?v=vWgoPTvQ3Rw&lc=Ugzxf54tT2SPzaMDSmx4AaABAg.9ajr2x-meUV9e0X9teipFN
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

// n = #vertices, m = #edges in the i/p graph
int n, m;

int cheapest_flight_within_k_stops(int src, int dst, int k) {
	// d[i] stores the minimum distance of ith node from given src
    vi d(n);
        
    // initialising the distances of all nodes from src as infinity
    for(int i = 0; i < n; i++) d[i] = INF;
    
    // stops[i] stores the minimum #stops required to reach ith node while taking minimum 
    // distance route from src
    vi stops(n);
    
    // initialising the stops of all nodes from src as infinity
    for(int i = 0; i < n; i++) stops[i] = INF;
    
    // stores the {distance, node, #stops}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    
    d[src] = 0;
    stops[src] = 0;
    pq.push(make_tuple(0, src, 0));
    
    while(!pq.empty()) {
    	int cur_node = get<1>(pq.top());
    	int cur_dis = get<0>(pq.top());
    	int cur_stops = get<2>(pq.top());
    	
    	pq.pop();
    	
    	if(cur_stops > (k + 1)) continue;
    	if(cur_node == dst) return cur_dis;
    	
    	for(auto x: g[cur_node]) {
    		int nxt_node = x.F;
    		int nxt_dis = cur_dis + x.S;
    		int nxt_stops = cur_stops + 1;
    		
    		if(nxt_dis < d[nxt_node]) {
    			d[nxt_node] = nxt_dis;
    			stops[nxt_node] = nxt_stops;
    			pq.push(make_tuple(nxt_dis, nxt_node, nxt_stops));
    		}
    		
    		// the below else if() condition sets this algorithm apart from normal dijkstra()
    		// adding this route with longer distance but lesser #stops to the min heap so that if we find a 
    		// shorter route through that path in future we could change it.
    		else if(nxt_stops < stops[nxt_node]) {
    			pq.push(make_tuple(nxt_dis, nxt_node, nxt_stops));
    		}
    	}
    }
    
	return -1;
}

void solve()
{
  	cin >> n >> m;
    
    g.clear(); g.resize(n);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y, wt; cin >> x >> y >> wt;
        g[x].pb({y, wt});
    }
    
    int src, dst, k;
    cin >> src >> dst >> k;
    
    cout << cheapest_flight_within_k_stops(src, dst, k) << "\n";
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