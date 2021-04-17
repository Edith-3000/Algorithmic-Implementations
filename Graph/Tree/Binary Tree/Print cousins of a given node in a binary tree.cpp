// Problem: https://www.techiedelight.com/print-cousins-of-given-node-binary-tree/
/*****************************************************************************************************/

// Method - 1

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

TreeNode* find(queue<pair<TreeNode*, TreeNode*>> q, int k) {
	while(!q.empty()) {
		TreeNode *cur = q.front().F;
		TreeNode *par = q.front().S;
		q.pop();
		if(cur->val == k) return par;
	}
	
	return NULL;
}

// Function to return the cousins of a node
vi cousins(TreeNode *root, int k) {
	vi res; 
	if(root == NULL) return res;
	if(root->val == k) return res;
	
	// create an empty queue and enqueue the root node
	queue<pair<TreeNode*, TreeNode*>> q;
	q.push({root, NULL});
	
	// loop till queue is empty
	while(!q.empty()) {		 
		// find if node is present in this level or not
		TreeNode* k_par = find(q, k);
		
		// calculate the total number of nodes at the current level
		int sz = q.size();
			
		while(sz--) {
			TreeNode *cur = q.front().F;
			TreeNode *par = q.front().S;
			q.pop();
			
			if(k_par != NULL) { 
				if(par != k_par) res.pb(cur->val);
			}
			
			// enqueue the non-empty left and right child of current node
			if(cur->left) q.push({cur->left, cur});
			if(cur->right) q.push({cur->right, cur});
		}
		
		if(k_par != NULL) break;		
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
	
	int k; cin >> k;	
	vi res = cousins(root, k);
	
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

/****************************************************************************************************/

// Method - 2
// Can be found here: https://www.techiedelight.com/print-cousins-of-given-node-binary-tree/

/****************************************************************************************************/