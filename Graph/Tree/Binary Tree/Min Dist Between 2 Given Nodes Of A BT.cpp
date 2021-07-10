// Prob: https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/
// Ref: https://www.youtube.com/watch?v=6DraIPN_0no&list=PLDdcY4olLQk1-yJxgljSQ4ykbI2Bw1CqS&index=26
/******************************************************************************************************/

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

class TreeNode {
  public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int data): val(data), left(NULL), right(NULL) {}
    TreeNode(int data, TreeNode *left, TreeNode *right): val(data), left(left), right(right) {}
};

bool is_present(TreeNode *root, int key) {
	if(root == NULL) return 0;
	if(root->val == key) return 1;
	return is_present(root->left, key) or is_present(root->right, key);
}

TreeNode* LCA_helper(TreeNode *root, int x, int y) {
	if(!root) return NULL;
	if(root->val == x or root->val == y) return root;
	
	TreeNode *lft = LCA_helper(root->left, x, y);
	TreeNode *rgt = LCA_helper(root->right, x, y);
	
	if(lft and rgt) return root;
	else if(lft) return lft;
	else if(rgt) return rgt;
	else return NULL; 
}

// function to find the number of nodes in the path from root to key
int cnt_of_nodes(TreeNode *root, int key) {
	if(!root) return 0;
	if(root->val == key) return 1;
	
	int a = cnt_of_nodes(root->left, key);
	int b = cnt_of_nodes(root->right, key);
	
	// if both a and b are zero, then key not present
	if(!a and !b) return 0;
	
	// else one of them will be 0 and other non-zero
	else return a + b + 1;
}

int find_min_dist(TreeNode *root, int x, int y) {
	if(!is_present(root, x) or !is_present(root, y)) {
		return -1;
	}
	
	TreeNode *lca = LCA_helper(root, x, y);
	
	int d1 = cnt_of_nodes(lca, x);
	int d2 = cnt_of_nodes(lca, y);
	
	return d1 + d2 - 2;
}

void solve()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);
    root->right->left->right->left = new TreeNode(8);
    root->right->left->right->right = new TreeNode(9);
  	
  	int x, y; cin >> x >> y;
  	int res = find_min_dist(root, x, y);
  	
  	if(res == -1) cout << "Either both or one of the node absent.\n";
  	else cout << res << "\n";
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