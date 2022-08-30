// Prob: https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/
// Ref: https://www.youtube.com/watch?v=ZdIrKO7gqok&list=PLDdcY4olLQk1-yJxgljSQ4ykbI2Bw1CqS&index=22
/*****************************************************************************************************/

// METHOD - 1
// Exponential time complexity

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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
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

ll sum(TreeNode *root) {
	// base condition
  	if(!root) return 0LL;

  	// if current node included
  	ll inc = root->val;
  	if(root->left) {
  		inc += sum(root->left->left);
  		inc += sum(root->left->right);
    }
  	
  	if(root->right) {
  		inc += sum(root->right->left);
  		inc += sum(root->right->right);
    }
  	
  	// if current node excluded
  	ll exc = sum(root->left) + sum(root->right);
  	
  	return max(inc, exc);
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
  
    cout << sum(root) << "\n";
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

/******************************************************************************************************/

// METHOD - 2

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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
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

map<TreeNode*, ll> dp;

ll sum(TreeNode *root) {
	// base condition
  	if(!root) return 0LL;
	
	// check if already calculated or not
	if(dp.find(root) != dp.end()) return dp[root];
	
  	// if current node included
  	ll inc = root->val;
  	if(root->left) {
  		inc += sum(root->left->left);
  		inc += sum(root->left->right);
    }
  	
  	if(root->right) {
  		inc += sum(root->right->left);
  		inc += sum(root->right->right);
    }
  	
  	// if current node excluded
  	ll exc = sum(root->left) + sum(root->right);
  	
  	return dp[root] = max(inc, exc);
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
  	
  	dp.clear();
    cout << sum(root) << "\n";
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