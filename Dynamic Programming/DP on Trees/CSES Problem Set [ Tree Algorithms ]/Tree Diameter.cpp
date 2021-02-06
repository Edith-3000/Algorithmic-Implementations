// Another approach other than below: 
// https://stackoverflow.com/questions/20010472/proof-of-correctness-algorithm-for-diameter-of-a-tree-in-graph-theory#:~:text=Proof%20of%20correctness%3A%20Algorithm%20for%20diameter%20of%20a%20tree%20in%20graph%20theory,-algorithm%20tree%20graph&text=In%20order%20to%20find%20the,BFS%20will%20yield%20the%20diameter

/****************************************************************************************************************************************************************************************************************************************************************************************************************************/

// Problem: Tree Diameter
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1131
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 06-02-2021 00:23:11 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

// to store the i/p tree
vi tree[200001];

// downPath[i] = length of the longest path in the subtree rooted
// at node 'i' s.t. path starts at node 'i' OR simply it is the height
// or depth of the subtree rooted at node 'i'
int downPath[200001];

// diameter[i] = diameter of the tree if tree assumed to be rooted 
// at node 'i' 
// WLOG (Without Loss Of Generality) here, we assume the tree to be 
// rooted at node 1.
int diameter[200001];

// the #vertices
int n;

void evaluate_downPaths(int curr, int par) {
	int downPath_len = 0;
	bool is_leaf = 1;
	
	for(auto child: tree[curr]) {
		if(child != par) {
			is_leaf = 0;
			evaluate_downPaths(child, curr);
			downPath_len = max(downPath_len, downPath[child]);
		}
	}
	
	if(is_leaf) downPath[curr] = 0;
	else downPath[curr] = 1 + downPath_len;
}

void evaluate_diameter(int curr, int par) {
	// to store the answer if the diameter does not passes
	// through 'curr'
	int ans = 0; 
	vi children_downPaths;
	
	for(auto child: tree[curr]) {
		if(child != par) {
			evaluate_diameter(child, curr);
			ans = max(ans, diameter[child]);
			children_downPaths.pb(downPath[child]);
		}
	}
	
	int num_of_children = children_downPaths.size();
	sort(children_downPaths.begin(), children_downPaths.end());
	
	if(num_of_children == 0) diameter[curr] = 0;
	else if(num_of_children == 1) diameter[curr] = 1 + children_downPaths[0];
	else diameter[curr] = 2 + children_downPaths[num_of_children - 1] + children_downPaths[num_of_children - 2];
	
	// final diameter
	diameter[curr] = max(ans, diameter[curr]);
}

void solve()
{
  	cin >> n;
  	for(int i = 1; i < n; i++) {
  		int u, v; cin >> u >> v;
  		tree[u].pb(v);
  		tree[v].pb(u);
  	}
  	
  	evaluate_downPaths(1, 0);
  	evaluate_diameter(1, 0);
  	cout << diameter[1] << "\n";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}