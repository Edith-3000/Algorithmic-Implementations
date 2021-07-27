// METHOD - 1 (Using extra space)

// Refer: https://www.youtube.com/watch?v=LY5hbvFSJqM&list=PLDdcY4olLQk0NJOWhs4PB3DWpjnuUESbk&index=12
//        https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/
/**********************************************************************************************************/

// METHOD - 2 (Using constant extra space)

// Time complexity: O((n + m) x log(n + m))
// Space complexity:  As recursion is involved, the space used by the call stack is O(x + y), where x 
//                    is the height of the first tree, and y is the height of the second tree.


// Ref: https://www.techiedelight.com/in-place-merge-two-height-balanced-bsts/
//      Method - 3 of the page: https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

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

void inorder(TreeNode *root) {
	if(root == NULL) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

// function to convert a BST (here balanced) to a DLL
void bst_to_DLL(TreeNode *root, TreeNode* &head, TreeNode* &tmp, bool &fst_node) {
	// base case
	if(root == NULL) return;
	
	bst_to_DLL(root->left, head, tmp, fst_node);
	
	if(fst_node == 0) {
		head = tmp = root;
		fst_node = 1;
	}
	
	else {
		tmp->right = root;
		root->left = tmp;
		tmp = tmp->right;
	}
	
	bst_to_DLL(root->right, head, tmp, fst_node);
}

// function to merge 2 sorted DLL
TreeNode* merge_2_sorted_DLL(TreeNode *t1, TreeNode *t2) {
	if(t1 == NULL) return t2;
	if(t2 == NULL) return t1;
	
	TreeNode *head;
	if(t1->val <= t2->val) {
		head = t1;
		t1 = t1->right;
	}
	
	else {
		head = t2;
		t2 = t2->right;
	}
	
	TreeNode *tmp = head;
	
	while(t1 and t2) {
		if(t1->val <= t2->val) {
			tmp->right = t1;
			t1->left = tmp;
			t1 = t1->right;
			tmp = tmp->right;
	    }
	    
	    else {
	    	tmp->right = t2;
			t2->left = tmp;
			t2 = t2->right;
			tmp = tmp->right;
	    }
	}
	
	if(t1) tmp->right = t1, t1->left = tmp;
	if(t2) tmp->right = t2, t2->left = tmp;
	
	return head;
}

// function to return the middle node of a DLL, if #nodes = even, it
// will return the 1st one in the pair
TreeNode* find_mid(TreeNode *head) {
	// base case(s)
	if(head == NULL or head->right == NULL) return head;
	
	TreeNode *slow = head, *fast = head;
	
	while(fast->right and fast->right->right) {
		slow = slow->right;
		fast = fast->right->right;
	}
	
	return slow;
}

// function to convert a DLL to a balanced BST
// this method explained well in the video --->
// https://www.youtube.com/watch?v=Knynb5QOSMg

TreeNode* sorted_DLL_to_balanced_bst(TreeNode *head) {
	// base case
	if(head == NULL or head->right == NULL) return head;
	
	TreeNode *mid = find_mid(head);
	TreeNode *prev = mid->left, *next = mid->right;
	
	mid->left = mid->right = next->left = NULL;
	if(prev) prev->right = NULL;
	
	TreeNode *lf_part = (prev != NULL) ? head : NULL;
	TreeNode *rg_part = next;
	TreeNode *root = mid;
	
	root->left = sorted_DLL_to_balanced_bst(lf_part);
	root->right = sorted_DLL_to_balanced_bst(rg_part);
	
	return root;
}

TreeNode* merge_balanced_bst(TreeNode *root1, TreeNode *root2) {
	// base case(s)
	if(root1 == NULL) return root2;
	if(root2 == NULL) return root1;
	
	TreeNode *head1 = NULL, *head2 = NULL;
	TreeNode *tmp1 = NULL, *tmp2 = NULL;
	bool fst_node1 = 0, fst_node2 = 0;
	
	bst_to_DLL(root1, head1, tmp1, fst_node1);
	bst_to_DLL(root2, head2, tmp2, fst_node2);
	
	TreeNode *head = merge_2_sorted_DLL(head1, head2);
	
	TreeNode *root = sorted_DLL_to_balanced_bst(head);
	return root;
}

void solve()
{
  	TreeNode *root1 = new TreeNode(20);
    root1->left = new TreeNode(10);
    root1->right = new TreeNode(30);
    root1->right->left = new TreeNode(25);
    root1->right->right = new TreeNode(100);
    
    TreeNode *root2 = new TreeNode(50);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(70);
    
    // inorder(root1); cout << "\n";
    // inorder(root2); cout << "\n";
    
    TreeNode *root = merge_balanced_bst(root1, root2);
    
    // inorder(root); cout << "\n";
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

/********************************************************************************************************/

// METHOD - 3 (Using constant extra space)

// Time complexity: O(n + m)
// In METHOD - 2, it was the sorted_DLL_to_balanced_bst() function which lead to complexity of 
// O((n + m) x log(n + m)), so in this method the sorted_DLL_to_balanced_bst() is slightly tweaked.

// Space complexity:  As recursion is involved, the space used by the call stack is O(x + y), where x 
//                    is the height of the first tree, and y is the height of the second tree.


// Ref: https://www.techiedelight.com/in-place-merge-two-height-balanced-bsts/
//      Method - 3 of the page: https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

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

void inorder(TreeNode *root) {
	if(root == NULL) return;
	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

// function to convert a BST (here balanced) to a DLL
void bst_to_DLL(TreeNode *root, TreeNode* &head, TreeNode* &tmp, bool &fst_node) {
	// base case
	if(root == NULL) return;
	
	bst_to_DLL(root->left, head, tmp, fst_node);
	
	if(fst_node == 0) {
		head = tmp = root;
		fst_node = 1;
	}
	
	else {
		tmp->right = root;
		root->left = tmp;
		tmp = tmp->right;
	}
	
	bst_to_DLL(root->right, head, tmp, fst_node);
}

// function to merge 2 sorted DLL
TreeNode* merge_2_sorted_DLL(TreeNode *t1, TreeNode *t2) {
	if(t1 == NULL) return t2;
	if(t2 == NULL) return t1;
	
	TreeNode *head;
	if(t1->val <= t2->val) {
		head = t1;
		t1 = t1->right;
	}
	
	else {
		head = t2;
		t2 = t2->right;
	}
	
	TreeNode *tmp = head;
	
	while(t1 and t2) {
		if(t1->val <= t2->val) {
			tmp->right = t1;
			t1->left = tmp;
			t1 = t1->right;
			tmp = tmp->right;
	    }
	    
	    else {
	    	tmp->right = t2;
			t2->left = tmp;
			t2 = t2->right;
			tmp = tmp->right;
	    }
	}
	
	if(t1) tmp->right = t1, t1->left = tmp;
	if(t2) tmp->right = t2, t2->left = tmp;
	
	return head;
}

// function to count the #nodes in a DLL
int cnt_nodes(TreeNode *head) {
	// base case(s)
	if(head == NULL) return 0;
	
	TreeNode *tmp = head;
	int cnt = 0;
	
	while(tmp) {
		cnt += 1;
		tmp = tmp->right;
	}
	
	return cnt;
}

// function to convert a DLL to a balanced BST
TreeNode* sorted_DLL_to_balanced_bst(TreeNode* &head, int n) {
	// base case
    if (n <= 0) return NULL;
 
    // recursively convert the left subtree
    TreeNode* leftSubTree = sorted_DLL_to_balanced_bst(head, n/2);
 
    // head now points to the middle node of the sorted list
 
    // make the middle node of the sorted list the root node of the BST
    TreeNode* root = head;
 
    // update left child of the root node
    root->left = leftSubTree;
 
    // update the head reference of the doubly linked list
    head = head->right;
 
    // recursively convert the right subtree with the remaining nodes
    // The number of nodes in right subtree is =
    // total nodes - nodes in left subtree - 1 (for root)
    root->right = sorted_DLL_to_balanced_bst(head, n - n/2 - 1);
 
    // return the root node
    return root;
}

TreeNode* merge_balanced_bst(TreeNode *root1, TreeNode *root2) {
	// base case(s)
	if(root1 == NULL) return root2;
	if(root2 == NULL) return root1;
	
	TreeNode *head1 = NULL, *head2 = NULL;
	TreeNode *tmp1 = NULL, *tmp2 = NULL;
	bool fst_node1 = 0, fst_node2 = 0;
	
	bst_to_DLL(root1, head1, tmp1, fst_node1);
	bst_to_DLL(root2, head2, tmp2, fst_node2);
	
	TreeNode *head = merge_2_sorted_DLL(head1, head2);
	
	int n = cnt_nodes(head);
	TreeNode *root = sorted_DLL_to_balanced_bst(head, n);
	return root;
}

void solve()
{
  	TreeNode *root1 = new TreeNode(20);
    root1->left = new TreeNode(10);
    root1->right = new TreeNode(30);
    root1->right->left = new TreeNode(25);
    root1->right->right = new TreeNode(100);
    
    TreeNode *root2 = new TreeNode(50);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(70);
    
    // inorder(root1); cout << "\n";
    // inorder(root2); cout << "\n";
    
    TreeNode *root = merge_balanced_bst(root1, root2);
    
    // inorder(root); cout << "\n";
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