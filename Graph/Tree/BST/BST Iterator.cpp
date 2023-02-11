// Problem: https://www.interviewbit.com/problems/bst-iterator/
//          https://leetcode.com/problems/binary-search-tree-iterator/

// Ref: https://www.youtube.com/watch?v=4L5seG1d2dA&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=6
//      https://www.youtube.com/watch?v=D2jMcmxU4bs&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=52&ab_channel=takeUforward

/*********************************************************************************************************************************************************************/

// In this problem there is just iterative implementation of inorder traversal of the BST.

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

class BSTIterator {
	private:
		stack<TreeNode*> stk;
	
	public:
		BSTIterator(TreeNode*);
		void push_all(TreeNode*);
		bool hasNext();
		int next();
};

BSTIterator::BSTIterator(TreeNode *root) {
	while(!stk.empty()) stk.pop();
	push_all(root);
}

void BSTIterator::push_all(TreeNode *root) {
	while(root != NULL) {
		stk.push(root);
		root = root->left;
	}
}

bool BSTIterator::hasNext() {
	return !stk.empty();
}

int BSTIterator::next() {
	TreeNode *tmp = stk.top();
	stk.pop();
	push_all(tmp->right);
	return tmp->val;
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
	
	BSTIterator i(root);
	
	while(i.hasNext()) {
		cout << i.next() << "\n";
	}
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