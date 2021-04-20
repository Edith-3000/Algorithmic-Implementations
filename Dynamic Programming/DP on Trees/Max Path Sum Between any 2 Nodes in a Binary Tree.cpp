/*PROBLEM: Given a binary tree, find the maximum path sum. The path may start and end at any 
           node in the tree.
           NOTE: The value of a node can be any integer.
  Link: https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/
*/

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

ll maxPathSumBwAnyTwoNodes(TreeNode *root, ll &res) {
  // base condition
    if(root == NULL) return 0LL;
    
    // hypothesis
    ll l = maxPathSumBwAnyTwoNodes(root->left, res);
    ll r = maxPathSumBwAnyTwoNodes(root->right, res);
    
    // induction
    // remember temp is used whenever the current node wants to pass it's
    // constribution to it's parent node
    ll temp = max(max(l, r) + root->val, (ll)root->val); // taken in consideration the case 
                                                         // when l & r both can be -ve
    
    // l + r + root->val indicates the current nodes want's the result to pass
    // through it
    ll ans = max(temp, l + r + root->val);
    
    // updating the final result
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
  maxPathSumBwAnyTwoNodes(root, res);
  
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
     In the main() fⁿ res is initialised as res= LLONG_MIN;
   # Time Complexity: O(n), since we must visit each node, where n are the #nodes in binary tree.
   # Auxiliary Space Complexity: O(1)
   # Space complexity of the internal call stack: O(h), where h is the height of the binary tree,
                                                  h may be O(log(n)), if a balanced tree or
                                                  h maye be O(n), otherwise.
*/