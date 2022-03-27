// Problem: https://www.interviewbit.com/problems/postorder-traversal/
// Ref: https://www.youtube.com/watch?v=ymIjzhVvNFg&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=19
//      https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/
/***************************************************************************************************/

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

void postorder(TreeNode *root, vi &v) {
	if(root == NULL) return;
	postorder(root->left, v);
	postorder(root->right, v);
	v.pb(root->val);
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
	postorder(root, res); 
	
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
// Remember: POSTORDER TRAVERSAL IS SAME AS LEVEL ORDER TRAVERSAL WITH std::stack

// Logic behind this method :--->

// Postorder is  (left -> right -> root).
// But you do traversal in this way - (root -> right -> left) and in the last just reverse the result
// obtained i.e. reverse_of(root -> right -> left) = (left -> right -> root). 

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

vi postorder(TreeNode *root) {
	vi res;
	if(root == NULL) return res;
		
	stack<TreeNode*> stk;
	stk.push(root);
	
	while(!stk.empty()) {
		TreeNode *tmp = stk.top();
		stk.pop();
		res.pb(tmp->val);
		if(tmp->left) stk.push(tmp->left);
		if(tmp->right) stk.push(tmp->right);
	}
	
	reverse(res.begin(), res.end());
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
	
	vi res = postorder(root); 
	
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

// METHOD - 3
// An approach with the help of 2 stacks can be found here :--->
// https://takeuforward.org/data-structure/post-order-traversal-of-binary-tree/

/**************************************************************************************************/

// METHOD 4 (Using MORRIS TRAVERSAL)
// Postorder traversal without recursion and without stack
// Morris Traversal uses the concept of Threaded Binary Tree.

// Logic behind this method :--->

// Postorder is  (left -> right -> root).
// But you do traversal in this way - (root -> right -> left) and in the last just reverse the result
// obtained i.e. reverse_of(root -> right -> left) = (left -> right -> root). 

// For more info on this see the comment by "Shwetank Singh" in the comment box of the video :--->
// https://www.youtube.com/watch?v=80Zug6D1_r4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=39

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

vi postorder(TreeNode *root) {
	vi res;
	
	while(root) {
		// If right child is null, print the current node data. Move to 
        // left child. 
		if(root->right == NULL) {
			res.pb(root->val);
			root = root->left;
		}
		
		else {
			// Find inorder successor of root
			TreeNode *tmp = root->right;
			while(tmp->left and tmp->left != root) tmp = tmp->left;
			
			// If the left child of inorder predecessor already points to 
            // this node 
			if(tmp->left == root) {
				tmp->left = NULL;
				root = root->left;
			}
			
			// If left child of inorder successor doesn't point to this node, 
			// then push this node in res and make left child of inorder successor 
			// point to this node (root)
			else {
				tmp->left = root;
				res.pb(root->val);
				root = root->right;
			}
		}
	}
	
	reverse(res.begin(), res.end());	
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
	
	vi res = postorder(root); 
	
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