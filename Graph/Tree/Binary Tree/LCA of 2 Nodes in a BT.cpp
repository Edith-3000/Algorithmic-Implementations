// Problem: https://www.interviewbit.com/problems/least-common-ancestor/
// Ref: https://www.youtube.com/watch?v=T6Jr-Q6bvSU&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=39
//      https://www.educative.io/edpresso/how-to-find-the-lowest-common-ancestor-in-binary-tree
/****************************************************************************************************/

// METHOD - 1

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

bool is_present(TreeNode *root, int key) {
	if(root == NULL) return 0;
	if(root->val == key) return 1;
	return is_present(root->left, key) or is_present(root->right, key);
}

TreeNode* LCA_helper(TreeNode *root, int x, int y) {
	if(!root) return NULL;
	if(root->val == x or root->val == y) return root;
	
	TreeNode *lft = LCA_helper(root->left, x, y);
	TreeNode *rgt = LCA_helper(root->right, x, y);
	
	if(lft and rgt) return root;
	else if(lft) return lft;
	else if(rgt) return rgt;
	else return NULL; 
}

TreeNode* LCA(TreeNode *root, int x, int y) {
	if(!is_present(root, x) or !is_present(root, y)) {
		return NULL;
	}
	
	return LCA_helper(root, x, y);
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
	
	int x, y; 
	cin >> x >> y;
	
	TreeNode *lca = LCA(root, x, y);
	if(lca == NULL) cout << "NO\n";
	else cout << "YES\n" << lca->val << "\n";
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