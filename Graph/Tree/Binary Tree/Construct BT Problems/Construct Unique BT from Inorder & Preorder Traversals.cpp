// Problem: https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
//          https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Ref: https://www.youtube.com/watch?v=wv4XfOcIQWg&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=28
//      https://takeuforward.org/data-structure/construct-a-binary-tree-from-inorder-and-preorder-traversal/

/****************************************************************************************************************************************************************/

// NOTE: Both the below methods assume that duplicates do not exist in the tree.

/****************************************************************************************************************************************************************/

// METHOD - 1 O(N^2) 

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

void preorder(TreeNode *root) {
	if(root == NULL) return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

// Function to construct binary tree from given inorder & preorder traversals
// The function doesn't do any error checking for cases where inorder and preorder
// do not form a tree

// Here is = inorder start, ie = inorder end
//      ps = preorder start, pe = preorder end
TreeNode* build_tree(vi &in, vi &pre, int is, int ie, int ps, int pe) {
	if((is > ie) or (ps > pe)) return NULL;
	
	int root_data = pre[ps];
	int idx = -1;
	
	for(int i = is; i <= ie; i++) {
		if(in[i] == root_data) { idx = i; break; }
	}
	
	int len_left = idx - is;
	
	TreeNode *root = new TreeNode(root_data);
	root->left = build_tree(in, pre, is, idx - 1, ps + 1, ps + len_left);
	root->right = build_tree(in, pre, idx + 1, ie, ps + len_left + 1, pe);
	
	return root;
}

void solve()
{
  	int n; cin >> n;
  	vi in(n), pre(n);
  	
  	for(int i = 0; i < n; i++) cin >> in[i];
  	for(int i = 0; i < n; i++) cin >> pre[i];
  	 
  	TreeNode *root = build_tree(in, pre, 0, n - 1, 0, n - 1);
  	
  	inorder(root); cout << "\n";
  	preorder(root); cout << "\n";
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

// TC: (O^2)

/****************************************************************************************************************************************************************/

// METHOD - 2 O(N)

// Only change b/w Method 1 and Method 2 is that in this Method 2 std::unordered_map has been used
// for searching the indices of roots in inorder vector.

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

void preorder(TreeNode *root) {
	if(root == NULL) return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

// Function to construct binary tree from given inorder & preorder traversals
// The function doesn't do any error checking for cases where inorder and preorder
// do not form a tree

// Here is = inorder start, ie = inorder end
//      ps = preorder start, pe = preorder end
TreeNode* build_tree(unordered_map<int, int> &m, vi &in, vi &pre, int is, int ie, int ps, int pe) {
	if((is > ie) or (ps > pe)) return NULL;
	
	int root_data = pre[ps];
	int idx = m[root_data];
		
	int len_left = idx - is;
	
	TreeNode *root = new TreeNode(root_data);
	root->left = build_tree(m, in, pre, is, idx - 1, ps + 1, ps + len_left);
	root->right = build_tree(m, in, pre, idx + 1, ie, ps + len_left + 1, pe);
	
	return root;
}

void solve()
{
  	int n; cin >> n;
  	vi in(n), pre(n);
  	
  	for(int i = 0; i < n; i++) cin >> in[i];
  	for(int i = 0; i < n; i++) cin >> pre[i];
  	
  	unordered_map<int, int> m;
  	for(int i = 0; i < n; i++) m[in[i]] = i;
  	 
  	TreeNode *root = build_tree(m, in, pre, 0, n - 1, 0, n - 1);
  	
  	inorder(root); cout << "\n";
  	preorder(root); cout << "\n";
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

// TC: O(N)