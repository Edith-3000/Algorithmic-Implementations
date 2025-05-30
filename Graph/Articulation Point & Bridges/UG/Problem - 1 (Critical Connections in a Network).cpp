// Problem: https://leetcode.com/problems/critical-connections-in-a-network/description

/*********************************************************************************************************/

#define pb push_back
#define F first
#define S second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

class Solution {
public:
    vvi g;
    vi tin, low, vis;
    vpii bridges;
    int timer;
    int n, m;

    void dfs(int cur, int par) {
        vis[cur] = 1;
        tin[cur] = low[cur] = timer++;
        
        for(auto x: g[cur]) {
            if(vis[x] == 0) {
                dfs(x, cur);
                low[cur] = min(low[cur], low[x]);
                if(low[x] > tin[cur]) bridges.pb({cur, x});
            }
            
            else {
                if(x == par) continue;
                else low[cur] = min(low[cur], tin[x]);
            }
        }
    }

    // tin[i] = the entry time of each vertex in the DFS Tree.

    // low[i] = it is the minimum of entry(or discovery) times of all the vertices that are pointed by a 
    //          backedge from any of the vertex present in the subtree (rooted at 'i') of the vertex 'i'.
    //          If vertex 'i' has no children or there is no backedge present in the subtree, then low[i] = entry[i]. 

    // vis[i] = to keep track whether i has been visited or not.

    // timer is used to store the running time, in last after dfs traversal timer will be = (2 * n + 1).

    // Function to find all the bridges in an undirected graph
    // NOTE: this implementation malfunctions if the graph has multiple edge(s), for details
    //       refer: https://cp-algorithms.com/graph/bridge-searching.html
    void find_bridges() {
        tin.clear(); tin.resize(n + 1, 0);
        low.clear(); low.resize(n + 1, 0);
        vis.clear(); vis.resize(n + 1, 0);
        bridges.clear();
        timer = 1;
        
        for(int i = 1; i <= n; i++) {
            if(vis[i] == 0) dfs(i, -1);
        }
    }

    vector<vector<int>> criticalConnections(int nodes, vector<vector<int>>& connections) {
        n = nodes;
        m = connections.size();

        g.clear();
        g.resize(n + 1);

        for (int i = 0; i < m; i++) {
            int x = connections[i][0] + 1;
            int y = connections[i][1] + 1;

            g[x].pb(y);
            g[y].pb(x);
        }

        find_bridges();

        vvi res;

        for (auto bridge: bridges) {
            res.pb({bridge.F - 1, bridge.S - 1});
        }

        return res;
    }
};