// Problem: https://www.interviewbit.com/problems/clone-graph/
//          https://leetcode.com/problems/clone-graph/

// Ref: https://www.geeksforgeeks.org/clone-an-undirected-graph/
//      https://www.youtube.com/watch?v=f2EfGComRKM

/**********************************************************************************************************************************************************/

// https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/
// https://www.geeksforgeeks.org/what-is-dynamic-memory-allocation/

/**********************************************************************************************************************************************************/

// METHOD - 1 [USING DFS]

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

class Node {
    public:
    	int val;
    	vector<Node*> neighbours;
    	
    	Node() {
    		val = 0;
    		neighbours = vector<Node*> ();
    	}
    	
    	Node(int _val) {
    		val = _val;
    		neighbours = vector<Node*> ();
    	}
    	
    	Node(int _val, vector<Node*> _neighbours) {
    		val = _val;
    		neighbours = _neighbours;
    	}
};

void dfs(Node *curr, Node *node, unordered_map<Node*, Node*> &vis) {
	vis[curr] = node;
	
	for(auto x: curr->neighbours) {
		if(vis.count(x) == 0) {
			Node *new_node = new Node(x->val);
			(node->neighbours).pb(new_node);
			dfs(x, new_node, vis);
		}
		
		else (node->neighbours).pb(vis[x]);
	}
}

Node* clone_graph(Node *node) {
	// base case
	if(node == NULL) return NULL;
	
	unordered_map<Node*, Node*> vis;
	
	Node *copy = new Node(node->val);
	vis[node] = copy;
	
	for(auto curr: node->neighbours) {
		if(vis.count(curr) == 0) {
			Node *new_node = new Node(curr->val);
			(copy->neighbours).pb(new_node);
			dfs(curr, new_node, vis);
		}
		
		else (copy->neighbours).pb(vis[curr]);
	}
	
	return copy;
}

Node* build() {
    Node *node1 = new Node();
    node1->val = 1;
    Node *node2 = new Node();
    node2->val = 2;
    Node *node3 = new Node();
    node3->val = 3;
    Node *node4 = new Node();
    node4->val = 4;
    vector<Node *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbours = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbours = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbours = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbours = v;
    return node1;
}

// A simple bfs traversal of a graph to check for proper cloning of the graph
void bfs(Node *src) {
    vector<bool> vis(1000);
    vis[src->val] = true;

    queue<Node*> q;
    q.push(src);
   
    while (!q.empty()) {
        Node *u = q.front();

        cout << "Value of Node: " << u->val << "\n";
        cout << "Address of Node: " << u << "\n";

        q.pop();

        vector<Node*> v = u->neighbours;

        int n = v.size();

        for(int i = 0; i < n; i++) {
            if (!vis[v[i]->val]) {
                vis[v[i]->val] = true;
                q.push(v[i]);
            }
        }
    }
    
    cout << endl;
}

void solve()
{
  	Node *node = build();
  	cout << "BFS Traversal before cloning\n";
    bfs(node);
  	
  	Node *clone = clone_graph(node);
  	cout << "BFS Traversal after cloning\n";
    bfs(clone);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
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
  
Output of the above program:

BFS Traversal before cloning
Value of Node: 1
Address of Node: 0x60000018d160
Value of Node: 2
Address of Node: 0x60000018d180
Value of Node: 4
Address of Node: 0x60000018d1c0
Value of Node: 3
Address of Node: 0x60000018d1a0

BFS Traversal after cloning
Value of Node: 1
Address of Node: 0x60000018d1e0
Value of Node: 2
Address of Node: 0x60000018d220
Value of Node: 4
Address of Node: 0x60000018d2a0
Value of Node: 3
Address of Node: 0x60000018d260

*/

/**********************************************************************************************************************************************************/

// METHOD - 2 [USING DFS]
// Just a tweak in implementation (logically both are same)

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

class Node {
    public:
        int val;
        vector<Node*> neighbours;
        
        Node() {
            val = 0;
            neighbours = vector<Node*> ();
        }
        
        Node(int _val) {
            val = _val;
            neighbours = vector<Node*> ();
        }
        
        Node(int _val, vector<Node*> _neighbours) {
            val = _val;
            neighbours = _neighbours;
        }
};

void dfs(Node* node, unordered_map<Node*, Node*> &vis) {
    Node *cloned_node = new Node(node->val);
    vis[node] = cloned_node;

    for(auto nbr: node->neighbours) {
        if(vis.find(nbr) != vis.end()) {
            cloned_node->neighbours.push_back(vis[nbr]);
            continue;
        }

        dfs(nbr, vis);
        
        cloned_node->neighbours.push_back(vis[nbr]);
    }

    return;
}

Node* clone_graph(Node *node) {
    // base case
    if(node == NULL) return NULL;
    
    unordered_map<Node*, Node*> vis;
    
    dfs(node, vis);
    
    return vis[node];
}

Node* build() {
    Node *node1 = new Node();
    node1->val = 1;
    Node *node2 = new Node();
    node2->val = 2;
    Node *node3 = new Node();
    node3->val = 3;
    Node *node4 = new Node();
    node4->val = 4;
    vector<Node *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbours = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbours = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbours = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbours = v;
    return node1;
}

// A simple bfs traversal of a graph to check for proper cloning of the graph
void bfs(Node *src) {
    vector<bool> vis(1000);
    vis[src->val] = true;

    queue<Node*> q;
    q.push(src);
   
    while (!q.empty()) {
        Node *u = q.front();

        cout << "Value of Node: " << u->val << "\n";
        cout << "Address of Node: " << u << "\n";

        q.pop();

        vector<Node*> v = u->neighbours;

        int n = v.size();

        for(int i = 0; i < n; i++) {
            if (!vis[v[i]->val]) {
                vis[v[i]->val] = true;
                q.push(v[i]);
            }
        }
    }
    
    cout << endl;
}

void solve()
{
    Node *node = build();
    cout << "BFS Traversal before cloning\n";
    bfs(node);
    
    Node *clone = clone_graph(node);
    cout << "BFS Traversal after cloning\n";
    bfs(clone);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
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
  
Output of the above program:

BFS Traversal before cloning
Value of Node: 1
Address of Node: 0x60000018d160
Value of Node: 2
Address of Node: 0x60000018d180
Value of Node: 4
Address of Node: 0x60000018d1c0
Value of Node: 3
Address of Node: 0x60000018d1a0

BFS Traversal after cloning
Value of Node: 1
Address of Node: 0x60000018d1e0
Value of Node: 2
Address of Node: 0x60000018d220
Value of Node: 4
Address of Node: 0x60000018d2a0
Value of Node: 3
Address of Node: 0x60000018d260

*/