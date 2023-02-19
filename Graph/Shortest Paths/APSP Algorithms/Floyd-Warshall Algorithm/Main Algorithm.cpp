/* # Ref: https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html#description-of-the-algorithm
          https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html
          https://www.geeksforgeeks.org/finding-shortest-path-between-any-two-nodes-using-floyd-warshall-algorithm/
          https://www.youtube.com/watch?v=nV_wOZnhbog
		  https://www.youtube.com/watch?v=YbY8cVwWAvw&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=43&ab_channel=takeUforward

   # This algorithm is DP based as it breaks the problem down into smaller subproblems, then combines 
     the answers to those subproblems to solve the big, initial problem.
	
   # The idea is this: Either the quickest path from A to C is the quickest path found so far from 
                       A to C, or it's the quickest path from A to B plus the quickest path from B to C.

   # Takes O(|V|^3) time.

   # All pairs shortest path algorithm.
   # Works with -ve edges as well.
   # Works for both weighted DG and UG.

   # Can detect -ve weight cycle, with one extra step in the main algorithm i.e. --->
     * THE GRAPH HAS A NEGATIVE CYCLE IF AT THE END OF THE ALGORITHM, THE 
       DISTANCE FROM A VERTEX 'v' TO ITSELF IS -VE.

   # As we need to find the shortest path from each node to all other nodes, it is better to represent 
     the graph using adjacency matrix.
*/

/***************************************************************************************************************************************************************/

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

// const int INF = 0x3f3f3f3f;
const int INF = INT_MAX;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// adjacency matrix representation of graph
vvi g;

// d[i][j] => shortest path length b/w vertices i & j
vvi d; 

// nxt[][] is used to retrieve the actual path
// nxt[i][j] => vertex which is just next to vertex 'i' in the
//              shortest path from i to j
vvi nxt;

// it will be true if there is -ve weight cycle in the graph
bool neg_cycle;

// #vertices
int n;

// function to retrive the shortest paths (if exist) betweeen each pair of vertices
// ref: https://www.geeksforgeeks.org/finding-shortest-path-between-any-two-nodes-using-floyd-warshall-algorithm/
void retrieve_paths() {	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << "For " << i << " to " << j << ": \n";
			// no shortest path exist if i and j part of -ve wt cycle 
			if(d[i][j] == -INF) {
				cout << "No shortest path exists\n\n";
				continue;
			}
			
			// if path exist retrieve it
			int x = i, y = j;
			cout << x;
			if(x == y) {
				cout << "\n\n";
				continue;
			}
			
			cout << " -> ";
			
			while(x != y) {
				x = nxt[x][y];
				cout << x;
				if(x != y) cout << " -> ";
			}
			
			cout << "\n\n";
		}
	}
} 

// If required use long long instead of int data type,
// 0-based indexing of vertices is used
void floyd_warshall() {
	// initialisation of d[][] and nxt[][] arrays
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) d[i][j] = 0, nxt[i][j] = -1;
			else {
				if(g[i][j] == INF) d[i][j] = INF, nxt[i][j] = -1;
				else d[i][j] = g[i][j], nxt[i][j] = j;
			}
		}
	}
	
	// running main logic of the algorithm
	for(int k = 0; k < n; k++) {
    	for(int i = 0; i < n; i++) {
        	for(int j = 0; j < n; j++) {
        		if(d[i][k] == INF or d[k][j] == INF) continue;
            	if(d[i][k] + d[k][j] < d[i][j]) {
            		d[i][j] = d[i][k] + d[k][j];
            		nxt[i][j] = nxt[i][k];
            	}
            }
        }
    }
   
    neg_cycle = 0;
    
    // to check if there is -ve weight cycle in the graph, 
    // therefore if d[i][j] == -INF, then pairs [i][j] don't have a shortest path between them
    // ref: https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++) {
        	for(int k = 0; k < n; k++) {
            	if(d[i][k] < INF and d[k][k] < 0 and d[k][j] < INF) {
            		d[i][j] = -INF; 
            		neg_cycle = 1;
            	}
            }
        }
    }
    
    retrieve_paths();
}

void solve()
{
  	cin >> n;

  	vset(g, n, vi(n));
  	vset(d, n, vi(n));
  	vset(nxt, n, vi(n));
  	
  	// if g[i][j] == INF, then it denotes that there is no
  	// direct edge b/w them
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < n; j++) cin >> g[i][j];
  	}
  	
  	floyd_warshall();
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

/* CAUTION: The 3 nested for() loops which form the main logic of the floyd_warshall() algorithm
            cannot be executed in the following manner, as given in link :--->
	        https://pastebin.com/e9QpaJ2i

	        It gave WA while submission for the following problem :--->
	        https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

			WA verdict code :--->
			https://pastebin.com/ZSUVLEiU
*/

// Time complexity: O(|V|^3)
// Space complexity: O(|V|^2), where |V| = #vertices in graph