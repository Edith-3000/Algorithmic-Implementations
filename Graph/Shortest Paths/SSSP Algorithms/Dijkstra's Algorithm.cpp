/* # Reference: https://cp-algorithms.com/graph/dijkstra.html
   				https://brilliant.org/wiki/dijkstras-short-path-finder/
                https://www.youtube.com/watch?v=jbhuqIASjoM&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=18

   # This algorithm is Greedy based.
   
   # This algorithm is used for finding the shortest path(as well as their costs) from a starting node to all 
     other nodes in a weighted & UG/DG.
   # The edges of the graph can be unidirectional/bidirectional.

   # Dijkstra’s algorithm doesn't work for graphs with -𝒗𝒆 𝒘𝒆𝒊𝒈𝒉𝒕 𝒄𝒚𝒄𝒍𝒆𝒔, it 𝑴𝑨𝒀 give correct results for a 
     graph with -𝒗𝒆 𝒆𝒅𝒈𝒆𝒔. 
   # For graphs with negative weight edges and cycles, 𝑩𝒆𝒍𝒍𝒎𝒂𝒏–𝑭𝒐𝒓𝒅 𝒂𝒍𝒈𝒐𝒓𝒊𝒕𝒉𝒎 can be used.
     
   # This algorithm basically creates a tree of shortest paths from the starting vertex, the source, to all 
     other points in the graph.
*/

/*********************************************************************************************************/

// IMPLEMENTATION USING std::priority_queue

/* FEW INSIGHTS :--->
   
   Que. Instead of using a std::priority_queue can the algorithm be implemented with a simple std::queue?
   Ans. Yes, but it will make unnecessary computations, refer the "Highlighted comment" of :--->
        https://www.youtube.com/watch?v=jbhuqIASjoM&lc=UgxjfXWwmeIUYm37Jwl4AaABAg

   Que. Why can't we use the similar technique used in "SSSP By BFS (For Unweighted Graph).cpp"? 
   Ans. It can be done but then the implementation becomes very difficult also the time complexity will be more 
        because suppose you updated all neighbours of node 'x' using the distance of 'x, but later you find a 
        better path to reach node 'x, so now you not only have to update distance of node 'x, but also all the 
        nodes previously relaxed by node 'x.
        For more info refer the "Highlighted comment" of :--->
        https://www.youtube.com/watch?v=jbhuqIASjoM&lc=UgzrAoo_qEqds1ZvX8B4AaABAg
        
*/

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

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// to store the input graph
vector<vpii> g;

// n = #vertices, m = #edges in the input graph
int n, m;

void dijkstra(int src) {
    // d[i] stores the minimum distance of ith node from given src
    vi d(n);
      
    // parent[i] stores the immediate parent of ith node in the 
    // shortest path from src to this node
    vi parent(n, -1);
    
    // to keep track of visited nodes
    vb vis(n, 0);
    
    // initialising the distances of all nodes from src as infinity
    for(int i = 0; i < n; i++) d[i] = INT_MAX;
    
    // the minimum distance of src from itself = 0
    d[src] = 0;
    
    // priority queue (min heap) to repeatedly find out the node having 
    // minimum distance from src
    priority_queue<pii, vector<pii>, greater<pii>> q;
    
    // inserting the src to initialise the process
    q.push({0, src});
    
    while(!q.empty()) {
        // extract the node which is currently at minimum distance from src
        int v = q.top().S;
        int mn = q.top().F;
        q.pop();
        
        if(vis[v] or mn == INT_MAX) continue;
        vis[v] = true;
        
        for(auto x: g[v]) {
            if(mn + x.S < d[x.F]) {
                d[x.F] = mn + x.S;
                q.push({d[x.F], x.F});
                parent[x.F] = v;
            }
        }
    }
        
    // in case you need the shortest path for each node
    vvi path;
    
    for(int i = 0; i < n; i++) {
        vi tmp;
        int cur = i;
        
        while(cur != -1) {
            tmp.pb(cur);
            cur = parent[cur];
        }
        
        reverse(tmp.begin(), tmp.end()); 
        path.pb(tmp);
    }
}

void solve()
{
    cin >> n >> m;

    g.clear(); 
    g.resize(n);
    
    // 0-based vertices
    for(int i = 0; i < m; i++) {
        int x, y, wt; 
        cin >> x >> y >> wt;
        g[x].pb({y, wt});
        g[y].pb({x, wt});
    }
    
    // source from which shortest path to each node to be calculated
    int src; cin >> src;
    
    dijkstra(src);
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

// Time complexity: O(|V| + (|E| x log(|V|)))
// https://cs.stackexchange.com/questions/104566/dijkstra-complexity-analysis-using-adjacency-list-and-priority-queue#:~:text=1%20Answer&text=Dijkstra's%20algorithm%20visits%20every%20node,in%20O(logV).

// NOTE: Similar implementation ===>
// Problem: https://www.interviewbit.com/problems/useful-extra-edges/
// Sol: https://pastebin.com/HjLpaXyf

/*******************************************************************************************************/

// IMPLEMENTATION USING std::set

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
    // data member
    unordered_map<T, list<pair<T, int>>> mp;
    
    public:
        // memebr functions
        void addEdge(T u, T v, int wt, bool isBidir) {
            mp[u].push_back({v, wt});
            if(isBidir) mp[v].push_back({u, wt});
        }
        
        void printGraph() {
            for(auto p: mp)
            {
                cout<<p.first<<" ---- ";
                for(auto nbr: p.second){
                    cout<<"("<<nbr.first<<", "<<nbr.second<<") ";
                }
                
                cout<<"\n";
            }
        }
        
        void dijkstraSSSP(T src) {
            // dist[key] stores the minimum distance 
            // of key from given src
            unordered_map<T, int> dist;
            
            // parent[key] stores the immediate parent of key
            // in the shortest path from src to key
            unordered_map<T, T> par;
            

            // initialising the distances of all nodes 
            // from src as infinity
            for(auto p: mp){
                dist[p.first] = INT_MAX;
                par[p.first] = p.first;
            }
            
            // the minimum distance of sc from itself = 0
            dist[src] = 0;
            
            // set to repeatedly find out the node having 
            // minimum distance from src
            set<pair<int, T>> s;

            // inserting the src to initialise the process
            s.insert({0, src});
            
            while(!s.empty()) {
                // extract the node which is currently at 
                // minimum distance from src
                auto p = *(s.begin());

                // marking this node as processed(visited)
                // by removing from the set
                s.erase(s.begin());
                
                int d = p.first;
                T curr = p.second;
                
                // iterate over the neighbours of the extracted node
                for(auto nbr: mp[curr]) {
                    // for edge(u, v) if dist[u] + edge_weight(u, v) < dist[v], 
                    // then update dist[v] to (dist[u] + edge_weight(u, v))
                    if((d + nbr.second) < dist[nbr.first]) {
                        // in std::set updation of a inserted value is not allowed
                        // therefore, we've to remove the old pair and insert the new 
                        // pair to simulate updation
                        auto it = s.find({dist[nbr.first], nbr.first});
                        if(it != s.end()){
                            s.erase(it);
                        }
                        
                        // insert new pair(updated)
                        s.insert({d + nbr.second, nbr.first});

                        // update the distance of nbr from src
                        dist[nbr.first] = (d + nbr.second);
                        
                        // update the parent of nbr
                        par[nbr.first] = curr;
                    }
                }
            }
            
            // print length of shortest distances of all nodes from src
            for(auto p: dist) {
                cout<<"Shortest distance of "<<p.first<<" from "<<src<<" = "<<p.second;
                cout<<"\n"; 
            }
            
            cout<<"\n";
            
            // print shortest path of all nodes from src
            for(auto p: par) {
                T node = p.first;
                
                if(node != src) {
                    cout<<node<<" <-- ";
                    while(par[node] != src){
                        cout<<par[node]<<" <-- ";
                        node=par[node];
                    }
                }
                
                cout<<src;
                cout<<"\n";
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

  /*Graph<int> g;
    g.addEdge(1, 2, 1, true);
    g.addEdge(1, 3, 4, true);
    g.addEdge(2, 3, 1, true);
    g.addEdge(3, 4, 2, true);
    g.addEdge(1, 4, 7, true);*/

    Graph<string> g;
    g.addEdge("Amritsar", "Delhi", 1, true);
    g.addEdge("Amritsar", "Jaipur", 4, true);
    g.addEdge("Jaipur", "Delhi", 2, true);
    g.addEdge("Jaipur", "Mumbai", 8, true);
    g.addEdge("Bhopal", "Agra", 2, true);
    g.addEdge("Mumbai", "Bhopal", 3, true);
    g.addEdge("Agra", "Delhi", 1, true);
    
    g.printGraph(); 
    cout<<"\n";
    //g.dijkstraSSSP(3);
    g.dijkstraSSSP("Delhi");
    
    return 0;
}

/*Sample o/p:

Agra ---- (Bhopal, 2) (Delhi, 1) 
Delhi ---- (Amritsar, 1) (Jaipur, 2) (Agra, 1) 
Amritsar ---- (Delhi, 1) (Jaipur, 4) 
Jaipur ---- (Amritsar, 4) (Delhi, 2) (Mumbai, 8) 
Bhopal ---- (Agra, 2) (Mumbai, 3) 
Mumbai ---- (Jaipur, 8) (Bhopal, 3) 

Shortest distance of Mumbai from Delhi = 6
Shortest distance of Delhi from Delhi = 0
Shortest distance of Agra from Delhi = 1
Shortest distance of Amritsar from Delhi = 1
Shortest distance of Jaipur from Delhi = 2
Shortest distance of Bhopal from Delhi = 3

Mumbai <-- Bhopal <-- Agra <-- Delhi
Delhi
Agra <-- Delhi
Amritsar <-- Delhi
Jaipur <-- Delhi
Bhopal <-- Agra <-- Delhi

*/

/**********************************************************************************************************************************************************************************************************/