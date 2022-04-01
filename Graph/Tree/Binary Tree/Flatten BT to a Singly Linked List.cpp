// Problem: https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/
// Ref: http://www.crazyforcode.com/flatten-binary-tree-linked-list-in-place/
/***************************************************************************************************/

// METHOD - 1

/* A brute approach to solve this problem is by iterating over the tree in pre-order fashion.
   While traversing, store the values of the nodes in a list.
   Create the required linked list using the stored values.
   But this method is not in-place.

   Visit code: https://pastebin.com/eR6Xqajz
*/

/********************************************************************************************************/

// METHOD - 2 (RECURSIVE IN-PLACE)
// https://www.youtube.com/watch?v=NOKVBiJwkD0

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

void flatten(TreeNode *root) {
	if(root == NULL) return;
	
	flatten(root->left);
	flatten(root->right);
	
	TreeNode *tmp_left = root->left;
	TreeNode *tmp_right = root->right;

	root->left = NULL;
	root->right = tmp_left;
	
	TreeNode *tmp = root;
	while(tmp->right != NULL) tmp = tmp->right;
	tmp->right = tmp_right;
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
	
	flatten(root);
	inorder(root);
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

// TC: O(n^2)
// SC: O(n), due to internal call stack

/********************************************************************************************************/

// METHOD - 3 (ITERATIVE IN-PLACE) 

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

TreeNode* flatten(TreeNode *root) {
	if(root == NULL) return root;
	
	TreeNode *cur = root;
	while(cur != NULL) {
		if(cur->left != NULL) {
			if(cur->right != NULL) {
				TreeNode *tmp = cur->left;
				while(tmp->right != NULL) tmp = tmp->right;
				tmp->right = cur->right; 
			}
			
			cur->right = cur->left;
			cur->left = NULL;
		}
		
		cur = cur->right;
	}
	
	return root;
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
	
	root = flatten(root);
	inorder(root);
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
// SC: O(1)