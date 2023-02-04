// Ref: https://www.educative.io/edpresso/how-to-use-a-vertical-order-traversal-of-a-binary-tree
//      https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree/

/*****************************************************************************************************************************************************************/

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

vvi verticalOrderTraversal(TreeNode *root) {
	vvi res;
	if(root == NULL) return res;
	
	map<int, vi> m;
	queue<pair<TreeNode*, int>> q;
	q.push({root, 0});
	
	while(!q.empty()) {
		TreeNode *node = q.front().F;
		int ver = q.front().S;
		q.pop();
		
		m[ver].pb(node->val);
		if(node->left) q.push({node->left, ver - 1});
		if(node->right) q.push({node->right, ver + 1});
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
	
	vvi res = verticalOrderTraversal(root); 
	
	for(auto v: res) {
		for(auto x: v) cout << x << " ";
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

// TC: O(n x log(n))
// SC: O(n)

// NOTE: Time complexity can be made linear by using std::unordered_map instead of a map, as 
//       given in the link --->
//       https://www.educative.io/edpresso/how-to-use-a-vertical-order-traversal-of-a-binary-tree

/*****************************************************************************************************************************************************************/

// A very slight modification of the problem --->
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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

class cmp {
	public:
		bool operator()(const pii &p1, const pii &p2) {
			if(p1.S == p2.S) return p1.F <= p2.F;
			return p1.S < p2.S; 
		}
};

class TreeNode {
	public:
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(): val(0), left(NULL), right(NULL) {}
		TreeNode(int data): val(data), left(NULL), right(NULL) {}
		TreeNode(int data, TreeNode *left, TreeNode *right): val(data), left(left), right(right) {}
};

vvi verticalOrderTraversal(TreeNode *root) {
	vvi res;
	if(root == NULL) return res;
	
	unordered_map<int, vpii> m;
	queue<pair<TreeNode*, pii>> q;
	
	q.push({root, {0, 0}});
	
	while(!q.empty()) {
		TreeNode *node = q.front().F;
		int ver = q.front().S.F;
		int hor = q.front().S.S;
		q.pop();
		
		m[ver].pb({node->val, hor});
		if(node->left) q.push({node->left, {ver - 1, hor + 1}});
		if(node->right) q.push({node->right, {ver + 1, hor + 1}});
	}
	
	int mx = INT_MIN, mn = INT_MAX;
	for(auto &x: m) {
		mx = max(mx, x.F);
		mn = min(mn, x.F);
		sort(x.S.begin(), x.S.end(), cmp());
	}
	
	for(int i = mn; i <= mx; i++) {
		vi tmp;
		for(auto x: m[i]) tmp.pb(x.F);
		res.pb(tmp);
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
	
	vvi res = verticalOrderTraversal(root); 
	
	for(auto v: res) {
		for(auto x: v) cout << x << " ";
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