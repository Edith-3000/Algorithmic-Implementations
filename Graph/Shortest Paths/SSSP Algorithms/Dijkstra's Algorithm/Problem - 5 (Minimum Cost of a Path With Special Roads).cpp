// Prob: https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/description/

// Ref: https://www.youtube.com/watch?v=9HL7x4_AaHA&ab_channel=PrakharAgrawal

/*******************************************************************************************************************************************************************/

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

struct node {
    int x, y, d;
};

class cmp {
    public:
        bool operator() (const node &n1, const node &n2) {
            return n1.d > n2.d;
        }
};

int manhattan_distance(node n1, node n2) {
    return abs(n1.x - n2.x) + abs(n1.y - n2.y);
}

int minimum_cost(vector<int>& start, vector<int>& target, vector<vector<int>>& special_roads) {
    node start_node = {start[0], start[1], 0};
    node end_node = {target[0], target[1], INF};

    map<pair<int, int>, int> dist;

    priority_queue<node, vector<node>, cmp> pq;

    pq.push(start_node);
    dist[{start_node.x, start_node.y}] = 0;

    int res = INT_MAX;

    while(!pq.empty()) {
        node cur_node = pq.top();
        pq.pop();

        if(cur_node.d > dist[{cur_node.x, cur_node.y}]) continue;

        res = min(res, cur_node.d + manhattan_distance(cur_node, end_node));

        for(auto vec: special_roads) {
            node road_start_node = {vec[0], vec[1], INF};
            node road_end_node = {vec[2], vec[3], INF};
			
			int cost_to_road_start_node = cur_node.d + manhattan_distance(cur_node, road_start_node);
			
			if((dist.count({road_start_node.x, road_start_node.y}) == 1) and (dist[{road_start_node.x, road_start_node.y}] <= cost_to_road_start_node)) {}
			else {
				dist[{road_start_node.x, road_start_node.y}] = cost_to_road_start_node;
	            road_start_node.d = cost_to_road_start_node;
	            pq.push(road_start_node);	
			}
			
            int cost_to_road_end_node = cur_node.d + manhattan_distance(cur_node, road_start_node) + vec[4];

            if((dist.count({road_end_node.x, road_end_node.y}) == 1) and (dist[{road_end_node.x, road_end_node.y}] <= cost_to_road_end_node)) {}
			else {
				dist[{road_end_node.x, road_end_node.y}] = cost_to_road_end_node;
	            road_end_node.d = cost_to_road_end_node;
	            pq.push(road_end_node);	
			}
        }
    }

    return res;
}

void solve()
{
  	vi start(2), target(2);
  	
  	cin >> start[0] >> start[1];
  	cin >> target[0] >> target[1];
  	
  	int k; cin >> k;
  	vvi special_roads(k, vi(5));
  	
  	for(int i = 0; i < k; i++) {
  		for(int j = 0; j < 5; j++) cin >> special_roads[i][j];
  	}
  	
  	int res = minimum_cost(start, target, special_roads);
  	
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