// Problem: https://www.interviewbit.com/problems/recover-binary-search-tree/
//          https://leetcode.com/problems/recover-binary-search-tree/

// Ref: https://www.youtube.com/watch?v=HsSSUSckMns&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=7
//      https://www.techiedelight.com/fix-binary-tree-one-swap-bst/
//      https://www.youtube.com/watch?v=ZWGW7FminDM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=54&ab_channel=takeUforward
/****************************************************************************************************************************/

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

// remember to pass pointer x, y and prev by reference
void inorder(TreeNode* root, TreeNode* &x, TreeNode* &y, TreeNode* &prev) {
	// base case
	if(root == NULL) return;
	
	// recur for the left subtree
	inorder(root->left, x, y, prev);
	
	// if the current node is less than the previous node
	if((prev != NULL) and (root->val < prev->val)) {
		if(x == NULL) x = prev;
		y = root;
	}
	
	// update the previous node
	prev = root;

	// recur for the right subtree
	inorder(root->right, x, y, prev);
}

// Fix given binary tree that is only one swap away from becoming a BST
void correctBST(TreeNode *root) {
	// x and y stores node to be swapped
	TreeNode *x = NULL, *y = NULL;
	
	// stores previously processed node in the inorder traversal
    // initialize it to NULL
	TreeNode *prev = NULL;
	
	inorder(root, x, y, prev);
	
	// swap the nodes
	if(x and y) swap(x->val, y->val);
}

void solve()
{
  	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(26);
	root->right->left->left = new TreeNode(5);
	root->right->left->right = new TreeNode(10);
	root->right->left->right->left = new TreeNode(8);
	root->right->left->right->right = new TreeNode(9);
	
	correctBST(root);
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