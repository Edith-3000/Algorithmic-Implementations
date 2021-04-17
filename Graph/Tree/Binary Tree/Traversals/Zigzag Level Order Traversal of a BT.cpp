// Problem: https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/
// Ref: https://www.youtube.com/watch?v=7CgoELweXHM&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=25
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

// Function to return the zigzag level order traversal of a given binary tree
vvi zig_zag(TreeNode *root) {
	vvi res;
	if(root == NULL) return res;
	
	// create an empty queue and enqueue the root node
	queue<TreeNode*> q;
	q.push(root);
	
	bool flag = 1;
	
	// loop till queue is empty
	while(!q.empty()) {
		// calculate the total number of nodes at the current level
		int sz = q.size();
		
		// to store the current level
		vi level;
				
		// find the first node of a level and push it into result
		while(sz--) {
			TreeNode *cur = q.front();
			q.pop();
			
			level.pb(cur->val);
			
			// enqueue the non-empty left and right child of current node
			if(cur->left) q.push(cur->left);
			if(cur->right) q.push(cur->right);
		}
		
		if(!flag) reverse(level.begin(), level.end());
		res.pb(level);
		
		flag = !flag;
	}
	
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
	
	vvi res = zig_zag(root);
	for(auto v: res) {
		for(auto ele: v) cout << ele << " ";
		cout << "\n";
	} 
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