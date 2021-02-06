// Naive approach: Initiate BFS from every node of the tree and find the sum of distances from every node.
//                 Time complexity of this approach = O(n^2), hence inefficient.

/**************************************************************************************************************/

// Tip: WHENEVER WE ARE TRYING TO SOLVE A PROBLEM USING DP ON TREES APPROACH, IT IS ADVISABLE TO TRY TO
//      ROOT THE TREE AT ANY ARBITRARY NODE. 

/*************************************************************************************************************/

// DP Method
// Source(s): https://www.youtube.com/watch?v=nGhE4Ekmzbc&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=5

// Problem: Tree Distances II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1133
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 06-02-2021 14:21:53 IST (UTC+05:30)
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

// sub_tree_sz[i] = the #nodes in the subtree rooted at 
// at node i (including i itself)
int sub_tree_sz[200001];

// sub_tree_ans[i] = the sum of the distances from the node i 
// to all other nodes in the subtree rooted at i
ll sub_tree_ans[200001];

// to store the final result for each vertex
ll res[200001];

// total #vertices(nodes)
int n;

void prep(int curr, int par) {
	int num_of_nodes = 1; 
	ll ans_for_subtree = 0;
	
	for(auto child: tree[curr]) {
		if(child != par) {
			prep(child, curr);
			num_of_nodes += sub_tree_sz[child];
			ans_for_subtree += sub_tree_ans[child] + sub_tree_sz[child];
		}
	}
	
	sub_tree_sz[curr] = num_of_nodes;
	sub_tree_ans[curr] = ans_for_subtree;
}

// In this driver() fn. rerooting technique is used
// For more info visit links at the bottom of page
void driver(int curr, int par, ll par_ans) {
	// final result for the current node
	res[curr] = sub_tree_ans[curr] + par_ans + (n - sub_tree_sz[curr]);
	
	for(auto child: tree[curr]) {
		if(child != par) {
			driver(child, curr, res[curr] - (sub_tree_ans[child] + sub_tree_sz[child]));
		}
	}
}

void solve()
{
  	cin >> n;
  	for(int i = 1; i < n; i++) {
  		int u, v; cin >> u >> v;
  		tree[u].pb(v);
  		tree[v].pb(u);
  	}
  	
  	prep(1, 0);
  	driver(1, 0, 0);
  	for(int i = 1; i <= n; i++) cout << res[i] << " ";
  	cout << '\n';
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

// Rerooting technique links --->
// https://codeforces.com/blog/entry/68142
// https://codeforces.com/blog/entry/68142?#comment-590195
// https://codeforces.com/blog/entry/68139