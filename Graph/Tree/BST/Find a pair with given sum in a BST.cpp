// Problem: https://www.interviewbit.com/problems/2sum-binary-tree/
//          https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Ref: https://www.youtube.com/watch?v=nNwTWOhrffo&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=4
//      https://www.youtube.com/watch?v=ssL3sHwPeb4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=53&ab_channel=takeUforward

/***************************************************************************************************************************************************************/

// METHOD - 1 (Implementation without making Class)

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

bool two_sum(TreeNode *root, int k) {
	TreeNode *cur = root;
	stack<TreeNode*> sleft, sright;
	
	while(cur) {
		sleft.push(cur);
		cur = cur->left;
	}
	
	cur = root;
	while(cur) {
		sright.push(cur);
		cur = cur->right;
	}
	
	while(!sleft.empty() and !sright.empty()) {
		TreeNode *ltop = sleft.top();
		TreeNode *rtop = sright.top();
		
		int sum = ltop->val + rtop->val;
		if(sum == k and ltop != rtop) return 1;
		
		else if(sum > k) {
			sright.pop();
			rtop = rtop->left;
			while(rtop) {
				sright.push(rtop);
				rtop = rtop->right;
			}
		}
		
		else {
			sleft.pop();
			ltop = ltop->right;
			while(ltop) {
				sleft.push(ltop);
				ltop = ltop->left;
			}
		}
	}
	
	return 0;
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
  	
  	int target; cin >> target;
  	if(two_sum(b.root, target)) cout << "YES\n";
  	else cout << "NO\n";
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
// SC: O(Height of BST)

/***************************************************************************************************************************************************************/

// METHOD - 2 (Implementation by making Class)
// Implementation is done by creating a Class "BstIterator" similar to "BST Iterator.cpp".

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

class BstIterator {
	private:
		stack<TreeNode*> stk;
		bool normal;
		
	public:
		BstIterator(TreeNode* root, bool direction) {
			normal = direction;
			push_all(root);
		}
		
		int next() {
			TreeNode* tmp = stk.top();
			stk.pop();
			if(normal) push_all(tmp->right);
			else push_all(tmp->left);
			return tmp->val;
		}
		
		void push_all(TreeNode* node) {
			while(node) {
				stk.push(node);
				if(normal) node = node->left;
				else node = node->right;
			}
		}
};

bool two_sum(TreeNode* root, int target) {
	// if tree is empty
	if(root == NULL) return 0;
	
	BstIterator l(root, true);
	BstIterator r(root, false);
	
	int i = l.next(), j = r.next();
	
	while(i < j) {
		int sum = i + j;
		if(sum == target) return 1;
		
		if(sum < target) i = l.next();
		else j = r.next();
	}
	
	return 0;
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
  	
  	int target; cin >> target;
  	
  	if(two_sum(b.root, target)) cout << "YES\n";
  	else cout << "NO\n";
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

// TC: O(n)
// SC: O(Height of BST)