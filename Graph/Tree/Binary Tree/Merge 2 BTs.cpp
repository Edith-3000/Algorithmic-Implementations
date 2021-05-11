// Problem: https://www.interviewbit.com/problems/merge-two-binary-tree/
// Ref: https://www.youtube.com/watch?v=ndEO0V10aS8&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=13
/*****************************************************************************************************/

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

void inorder(TreeNode *root) {
	if(root == NULL) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

TreeNode* merge_trees(TreeNode *root1, TreeNode *root2) {
	if(root1 == NULL) return root2;
	if(root2 == NULL) return root1;
	
	root1->val = root1->val + root2->val;
	root1->left = merge_trees(root1->left, root2->left);
	root1->right = merge_trees(root1->right, root2->right);
	
	return root1;
}

void solve()
{
  	TreeNode* root1 = new TreeNode(1);
	root1->right = new TreeNode(3);
	root1->right->left = new TreeNode(4);
	root1->right->right = new TreeNode(5);
	root1->right->left->left = new TreeNode(6);
	root1->right->left->right = new TreeNode(7);
	root1->right->left->right->left = new TreeNode(8);
	
	TreeNode* root2 = new TreeNode(1);
	root2->left = new TreeNode(2);
	root2->right = new TreeNode(3);
	root2->right->left = new TreeNode(4);
	root2->right->left->left = new TreeNode(6);
	root2->right->left->right = new TreeNode(7);
	root2->right->left->right->left = new TreeNode(8);
	root2->right->left->right->right = new TreeNode(9);
	
	root1 = merge_trees(root1, root2);
	inorder(root1);
	cout << "\n";
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