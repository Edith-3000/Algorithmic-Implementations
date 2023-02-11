// Problem: https://www.interviewbit.com/problems/kth-smallest-element-in-tree/
//          https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Ref: https://www.youtube.com/watch?v=5R9_qgIV98s&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=3
//      https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree/
//      https://leetcode.com/problems/kth-smallest-element-in-a-bst/solutions/284145/official-solution/

/***************************************************************************************************************************************************************/

// METHOD - 1 (O(Height * n))

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

// TC: (O(Height * n)), in the worst case when Height is O(n), it can be O(n^2).
//     where Height = height of the BST.

/***************************************************************************************************************************************************************/

// METHOD - 2 O(H + k)

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

/***************************************************************************************************************************************************************/

// METHOD - 3 O(Height of BST)
// Ref: https://youtu.be/KqMm81Y7j9M?t=447

/* # This method is just an optimization of "METHOD 1", instead of counting nodes present in the left subtree
     of a particular, we modified the TreeNode struct to store the same in a new data member "cnt_nodes".
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())
#define vset(v, n, val) v.clear(); v.resize(n, val)

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
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(queue <T> v);
template <class T> void _print(priority_queue <T> v);
template <class T> void _print(stack <T> s);

// modify it's definition below as per need such as it can be used for STL containers with custom args passed
template <class T> void _print(T v); 

template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(multimap <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.front()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(priority_queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(stack <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(T v) {  }

/*******************************************************************************************************************************************************************/

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
		int cnt_nodes;
		TreeNode *left;
		TreeNode *right;
		TreeNode(): val(0), cnt_nodes(0), left(NULL), right(NULL) {}
		TreeNode(int data): val(data), cnt_nodes(0), left(NULL), right(NULL) {}
		TreeNode(int data, TreeNode *left, TreeNode *right): val(data), cnt_nodes(0), left(left), right(right) {}
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
				node->cnt_nodes += 1;
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

int kth_smallest(TreeNode *root, int k) {
	int cnt = root->cnt_nodes;
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