// Ref: https://www.youtube.com/watch?v=EBTku_aIPXk
//      https://takeuforward.org/data-structure/top-view-of-a-binary-tree/

/*************************************************************************************************************************************************************/

// ITERATIVE IMPLEMENTATION

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

// Function to return the top view of a given binary tree
// Done with the help of level order traversal
vi top_view(TreeNode *root) {
	vi res;
	if(root == NULL) return res;
	
	// to store first node encountered with given vertical level
	map<int, int> m;
	
	// create an empty queue and enqueue the root node and it's vertical level
	// with respect to the root of tree
	queue<pair<TreeNode*, int>> q;
	q.push({root, 0});
	
	// loop till queue is empty
	while(!q.empty()) {
		TreeNode *cur = q.front().F;
		int ver = q.front().S;
		q.pop();
		
		// if the vertical level is seen for the first time, update the map
		if(m.count(ver) == 0) {
			m[ver] = cur->val;
		}
		
		// enqueue the non-empty left and right child of current node
		if(cur->left) q.push({cur->left, ver - 1});
		if(cur->right) q.push({cur->right, ver + 1});
	}
	
	for(auto x: m) res.pb(x.S);	
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
	
	vi res = top_view(root);
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

// TC: O(n x log(n))
// SC: O(n)

// NOTE: Time complexity can be made linear by using std::unordered_map instead of a std::map

/*************************************************************************************************************************************************************/

// RECURSIVE IMPLEMENTATION

// Ref: https://gist.github.com/Edith-3000/a4ebbb1d37055c00e392d64431792ebf