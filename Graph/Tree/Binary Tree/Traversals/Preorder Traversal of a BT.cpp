// Problem: https://www.interviewbit.com/problems/preorder-traversal/
// Ref: https://www.geeksforgeeks.org/morris-traversal-for-preorder/
//      https://www.youtube.com/watch?v=BxwRZ1BSfvo&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=20
/****************************************************************************************************/

// METHOD 1 (Using Recursion)

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

void preorder(TreeNode *root, vi &v) {
	if(root == NULL) return;
	v.pb(root->val);
	preorder(root->left, v);
	preorder(root->right, v);
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
	
	vi res;
	preorder(root, res); 
	
	for(auto x: res) cout << x << " ";
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

// TC: O(n)

/*******************************************************************************************************/

// METHOD 2 (Using std::stack)

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

vi preorder(TreeNode *root) {
	vi res;
	if(root == NULL) return res;
	
	stack<TreeNode*> stk;
	stk.push(root);
	
	while(!stk.empty()) {
		TreeNode *tmp = stk.top();
		stk.pop();
		res.pb(tmp->val);
		if(tmp->right) stk.push(tmp->right);
		if(tmp->left) stk.push(tmp->left);
	}
	
	return res;
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
	
	vi res = preorder(root); 
	
	for(auto x: res) cout << x << " ";
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

// TC: O(n)
// SC: O(n), as the space required is proportional to the height of the tree, which
//     can be equal to the total number of nodes in the tree in worst-case for skewed trees.

/*************************************************************************************************/

// METHOD 3 (Using MORRIS TRAVERSAL)
// Preorder traversal without recursion and without stack
// Morris Traversal uses the concept of Threaded Binary Tree.
// https://takeuforward.org/data-structure/morris-inorder-traversal-of-a-binary-tree/

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

vi preorder(TreeNode *root) {
	vi res;
	
	while(root) {
		// If left child is null, print the current node data. Move to 
        // right child. 
		if(root->left == NULL) {
			res.pb(root->val);
			root = root->right;
		}
		
		else {
			// Find inorder predecessor of root
			TreeNode *tmp = root->left;
			while(tmp->right and tmp->right != root) tmp = tmp->right;
			
			// If the right child of inorder predecessor already points to 
            // this node 
			if(tmp->right == root) {
				tmp->right = NULL;
				root = root->right;
			}
			
			// If right child of inorder predecessor doesn't point to this node, 
			// then push this node in res and make right child of inorder predecessor 
			// point to this node (root)
			else {
				tmp->right = root;
				res.pb(root->val);
				root = root->left;
			}
		}
	}
	
	return res;
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
	
	vi res = preorder(root); 
	
	for(auto x: res) cout << x << " ";
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

// Limitations: Morris traversal modifies the tree during the process. It establishes the right links 
// while moving down the tree and resets the right links while moving up the tree. So the algorithm 
// cannot be applied if write operations are not allowed.

// Time Complexity : O(n).
// Since every edge of the tree is traversed at most two times. And in the worst case, the same number 
// of extra edges (as input tree) are created and removed.

// Space Complexity: O(1)