// Prob: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#
// Ref: https://www.youtube.com/watch?v=bzF9Ia1XISQ&list=PLDdcY4olLQk1-yJxgljSQ4ykbI2Bw1CqS&index=13
/*****************************************************************************************************/

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

void left_boundary(TreeNode *root, vi &Lf) {
	// base case
	if(root == NULL) return;
	
	if(root->left) {
		Lf.pb(root->val);
		left_boundary(root->left, Lf);
	}
	
	else if(root->right) {
		Lf.pb(root->val);
		left_boundary(root->right, Lf);
	}
	
	else return;
}

void leaf_boundary(TreeNode *root, vi &Lv) {
	// base case
	if(root == NULL) return;
	
	leaf_boundary(root->left, Lv);
	if(!root->left and !root->right) Lv.pb(root->val);
	leaf_boundary(root->right, Lv);
}

void right_boundary(TreeNode *root, vi &Rg) {
	// base case
	if(root == NULL) return;
	
	if(root->right) {
		Rg.pb(root->val);
		right_boundary(root->right, Rg);
	}
	
	else if(root->left) {
		Rg.pb(root->val);
		right_boundary(root->left, Rg);
	}
	
	else return;
}

vi boundary_traversal(TreeNode *root) {
	if(root == NULL) return vi();
	
	vi res;
	res.pb(root->val);
	
	// left boundary function
	vi Lf;
	left_boundary(root->left, Lf);
	
	// leaf generating function
	vi Lv;
	leaf_boundary(root, Lv);
	
	// right boundary function
	vi Rg;
	right_boundary(root->right, Rg);
	reverse(Rg.begin(), Rg.end());
	
	for(auto x: Lf) res.pb(x);
	for(auto x: Lv) res.pb(x);
	for(auto x: Rg) res.pb(x);
	
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
	
	vi res = boundary_traversal(root); 
	
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