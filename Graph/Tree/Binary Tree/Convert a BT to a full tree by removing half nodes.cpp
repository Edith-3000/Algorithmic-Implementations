// Link: https://www.techiedelight.com/convert-given-binary-tree-to-full-tree-removing-half-nodes/
/**************************************************************************************************/

/* # The idea is to use post-order traversal to solve this problem efficiently.
   # We first process the left children, then right children, and finally the node itself.
   # So we form the new tree bottom up, starting from the leaves towards the root.
   # By the time we process the current node, both its left and right subtrees were already processed.
*/

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

class TreeNode {
	public:
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(): val(0), left(NULL), right(NULL) {}
		TreeNode(int data): val(data), left(NULL), right(NULL) {}
		TreeNode(int data, TreeNode *left, TreeNode *right): val(data), left(left), right(right) {}
};

// Function to check if a given node is a leaf node or not
bool is_leaf(TreeNode *root) {
	if(root == NULL) return 0;
	return (root->left == NULL and root->right == NULL);
}

// Function to convert a binary tree into a full tree by 
// removing half nodes
TreeNode* truncate(TreeNode *root) {
	// base case: empty tree
	if(root == NULL) return root;
	
	// recursively truncate the left subtree and right subtree first
	root->left = truncate(root->left);
	root->right = truncate(root->right);
	
	// do nothing if the current node is a leaf node or has 
	// two children
	if((root->left and root->right) or is_leaf(root)) {
		return root;
	}
	
	// if the current node has exactly one child, then delete the current
	// node and replace it with the child node
	TreeNode *child = (root->left) ? root->left : root->right;
	delete root;
	return child;
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
	
	root = truncate(root);
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

// TC: O(n)