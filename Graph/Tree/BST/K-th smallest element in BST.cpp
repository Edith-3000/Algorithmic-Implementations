// Problem: https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
// Ref: https://www.youtube.com/watch?v=5R9_qgIV98s&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=3
/***************************************************************************************************/

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

class BinarySearchTree {
	public:
		// data member
		TreeNode *root;
		
		// member functions
		BinarySearchTree(): root(NULL) {}
		
		// A utility function to insert a new node with given key in BST 
		TreeNode* insert(TreeNode *node, int key) {
			// If the tree is empty, return a new node
			if(node == NULL) {
				TreeNode *new_node = new TreeNode(key);
				return new_node;
			}
			
			// Otherwise, recur down the tree
			else if(key > node->val) {
				node->right = insert(node->right, key);
			}
			
			else {
				node->left = insert(node->left, key);
			}
			
			// return the (unchanged) node pointer
			return node;
		}
		
		// A utility function to do inorder traversal of BST 
		void inorder(TreeNode *root) {
			if(root == NULL) return;
			inorder(root->left);
			cout << root->val << " ";
			inorder(root->right);	
		}
};

int count_nodes(TreeNode *root) {
	if(root == NULL) return 0;
	return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int kth_smallest(TreeNode *root, int k) {
	int cnt = count_nodes(root->left);
	if(cnt + 1 == k) return root->val;
	else if(cnt + 1 > k) return kth_smallest(root->left, k);
	else return kth_smallest(root->right, k - cnt - 1);
}

void solve()
{	
	int n; cin >> n;
  	BinarySearchTree b;
  	
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		b.root = b.insert(b.root, x);
  	}
  	
  	b.inorder(b.root);
  	cout << "\n";
  	
  	cout << kth_smallest(b.root, 7) << "\n"; 
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

// TC: O(n^2)

/*******************************************************************************************************/

// METHOD - 2 O(n)

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

class BinarySearchTree {
	public:
		// data member
		TreeNode *root;
		
		// member functions
		BinarySearchTree(): root(NULL) {}
		
		// A utility function to insert a new node with given key in BST 
		TreeNode* insert(TreeNode *node, int key) {
			// If the tree is empty, return a new node
			if(node == NULL) {
				TreeNode *new_node = new TreeNode(key);
				return new_node;
			}
			
			// Otherwise, recur down the tree
			else if(key > node->val) {
				node->right = insert(node->right, key);
			}
			
			else {
				node->left = insert(node->left, key);
			}
			
			// return the (unchanged) node pointer
			return node;
		}
		
		// A utility function to do inorder traversal of BST 
		void inorder(TreeNode *root) {
			if(root == NULL) return;
			inorder(root->left);
			cout << root->val << " ";
			inorder(root->right);	
		}
};

// pass k and res by reference
void kth_smallest(TreeNode *root, int &k, int &res) {
	// base case
	if(root == NULL) return;
	
	kth_smallest(root->left, k, res);
	
	k--;
	if(k == 0) {
		res = root->val;
		return;
	}
	
	kth_smallest(root->right, k, res);
}

void solve()
{	
	int n; cin >> n;
  	BinarySearchTree b;
  	
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		b.root = b.insert(b.root, x);
  	}
  	
  	b.inorder(b.root);
  	cout << "\n";
  	
  	int k; cin >> k;
  	int res = INT_MAX;
  	
  	kth_smallest(b.root, k, res);
  	cout << res << "\n"; 
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