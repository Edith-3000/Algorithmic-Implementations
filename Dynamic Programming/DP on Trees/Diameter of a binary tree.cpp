/*PROBLEM: The diameter of a tree (sometimes called the width) is the number of nodes on the 
           longest path between two end nodes OR the number of edges on the longest path between 
           two end nodes (depends on what the question is asking).
           This path may or may not pass through the root.
           # NOTE: in the below algorithm we are considering the 1st definition for diameter
                   of a binary tree.
*/

// METHOD - 1 O(n^2)

/* # Consider every node as root node, find the height of it's left and right subtree.
   # Add 1 to the answer to include the current node
   # Update the final result in every iteration.
*/

/****************************************************************************************************/

// METHOD - 2 O(n)

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

ll diaOfBinaryTree(TreeNode *root, ll &res) {
  // base condition
  if(root == nullptr) return 0;

  // hypothesis
  ll l = diaOfBinaryTree(root->left, res);
  ll r = diaOfBinaryTree(root->right, res);

  // induction
  ll temp = 1 + max(l, r);
  ll ans = max(temp, 1 + l + r);
  res = max(res, ans);

  return temp;
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
  
    ll res = LLONG_MIN;
    diaOfBinaryTree(root, res);
  
    cout << res << "\n";
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

/* # The final answer is stored in res variable, which is passed by reference in every fⁿ call.
     In the main() fⁿ res is initialised as res = LLONG_MIN;
   # Time Complexity: O(n), since we must visit each node, where n are the #nodes in binary tree.
   # Auxiliary Space Complexity: O(1)
   # Space complexity of the internal call stack: O(h), where h is the height of the binary tree,
                                                  h may be O(log(n)), if a balanced tree or
                                                  h maye be O(n), otherwise.
*/