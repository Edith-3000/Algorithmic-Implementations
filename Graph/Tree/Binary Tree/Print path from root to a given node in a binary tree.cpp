// Problem: https://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/
// Ref: https://www.youtube.com/watch?v=OJMIa90B7Vc&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=10
/****************************************************************************************************/

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

bool preorder(TreeNode *root, int k, vi &res) {
	if(root == NULL) return 0;
	if(root->val == k) {
		res.pb(root->val);
		return 1;
	}
	
	if(preorder(root->left, k, res)) {
		res.pb(root->val);
		return 1;
	}
	
	if(preorder(root->right, k, res)) {
		res.pb(root->val);
		return 1;
	}
	
	return 0;
}

bool is_path(TreeNode *root, int k, vi &res) {
	bool ok = preorder(root, k, res);
	reverse(res.begin(), res.end());
	return ok;
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
	
	int k; cin >> k;
	
	vi res;
	
	if(is_path(root, k, res)) {
		cout << "YES\n";
		for(auto x: res) cout << x << " ";
		cout << "\n";
	}
	
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

// NOTE: The preorder function can be simply be made 2 liner as follows --->
/* bool preorder(TreeNode *root, int k, vi &res) {
   	if(root == NULL) return 0;
	
	if(root->val == k or preorder(root->left, k, res) or preorder(root->right, k, res)) {
		res.pb(root->val);
		return 1;
	}
	
	return 0;
  }
*/