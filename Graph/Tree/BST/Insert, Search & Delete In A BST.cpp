// Problems: https://leetcode.com/problems/insert-into-a-binary-search-tree/
//           https://leetcode.com/problems/search-in-a-binary-search-tree/
//           https://leetcode.com/problems/delete-node-in-a-bst/

// Ref: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
//      https://www.youtube.com/watch?v=KcNt6v_56cc&ab_channel=takeUforward
//      https://www.youtube.com/watch?v=FiFiNvM29ps&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=45&ab_channel=takeUforward
//      https://www.youtube.com/watch?v=gcULXE7ViZw&ab_channel=mycodeschool
//      https://www.techiedelight.com/deletion-from-bst/
/***************************************************************************************************************************/

// NOTE: 1. The deletion of a node concept has been explained very beautifully in the "mycodeschool" video.

/***************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

/*******************************************************************************************************************************************************************/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

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
		TreeNode* insert(TreeNode*, int);
		TreeNode* search(TreeNode*, int);
		TreeNode* delete_(TreeNode*, int);
		TreeNode* in_predecessor(TreeNode*);
		void inorder(TreeNode*);
};

// A utility function to do inorder traversal of BST 
void BinarySearchTree::inorder(TreeNode *root) {
	if(root == NULL) return;
	inorder(root->left);
	cout << (root->val) << " ";
	inorder(root->right);	
}

// A utility function to find inorder predecessor of a given node
TreeNode* BinarySearchTree::in_predecessor(TreeNode *root) {
	while(root->right != NULL) root = root->right;
	return root;
}

// A utility function to insert a new node with given key in BST 
TreeNode* BinarySearchTree::insert(TreeNode *root, int key) {
	// If the tree is empty, return a new node
	if(root == NULL) {
		TreeNode *new_node = new TreeNode(key);
		return new_node;
	}
	
	// Otherwise, recur down the tree
	if(key > root->val) {
		root->right = insert(root->right, key);
	}
	
	else {
		root->left = insert(root->left, key);
	}
	
	// return the root pointer
	return root;
}

// A utility function to search a given key in BST 
TreeNode* BinarySearchTree::search(TreeNode *root, int key) {
	// base case
	if(root == NULL or root->val == key) return root;
	
	// Otherwise, recur down the tree
	if(key > root->val) return search(root->right, key);
	else return search(root->left, key);
}

// LEGACY CONTENT for delete_() :---> https://pastebin.com/cWTLiKGh

// A utility function to delete a given key in BST 
TreeNode* BinarySearchTree::delete_(TreeNode* root, int key) {
	// base case(s)
	if(root == NULL) return NULL;
	
	// if the given key is less than the root node, recur for the left subtree
	if(key < root->val) root->left = delete_(root->left, key);
	
	// if the given key is greater than the root node, recur for the right subtree
	else if(key > root->val) root->right = delete_(root->right, key);
	
	// wohoo.....key found
	else {
		// Case 1: node to be deleted has no children (it is a leaf node)
		if((root->left == NULL) and (root->right == NULL)) {
			delete root;
			root = NULL;
		}
		
		// Case 2.1: node to be deleted has only one child (i.e right child)
		else if(root->left == NULL) {
			TreeNode* tmp = root;
			root = root->right;
			delete tmp;
			tmp = NULL;
		}
		
		// Case 2.2: node to be deleted has only one child (i.e left child)
		else if(root->right == NULL) {
			TreeNode* tmp = root;
			root = root->left;
			delete tmp;
			tmp = NULL;
		}
		
		// Case 3: node to be deleted has two children
		// whenever Case 3 occurs we try to reduce it to Case 1 or Case2
		else {
			// find its inorder predecessor node
			TreeNode *pred = in_predecessor(root->left);
			
			// swap the values of the predecessor node & the current node
			swap(root->val, pred->val);
			
			// recursively delete the predecessor. Note that the
            // predecessor will have at most one child (left child)
			root->left = delete_(root->left, key);
		}
	}
	
	// return the updated root in the end
	return root;
}

void solve()
{
  	/*int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];*/
  	
  	BinarySearchTree b;
  	
  	// #queries
  	int q; cin >> q;
  	while(q--) {
  		// 1 = insert, 2 = search, 3 = delete
  		int typ; cin >> typ;
  		int key; cin >> key;
  		
  		if(typ == 1) {
  			b.root = b.insert(b.root, key);
  		}
  		
  		else if(typ == 2) {
  			if(b.search(b.root, key)) cout << "Key found.\n";
  			else cout << "Key not found.\n";
  		}
  		
  		else {
  			b.root = b.delete_(b.root, key);
  		}
  	}
  	
  	b.inorder(b.root);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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

/*******************************************************************************************************/

// NOTE: A slightly longer implementation of the delete_() function can be found here --->
//       https://www.techiedelight.com/deletion-from-bst/

/*******************************************************************************************************/