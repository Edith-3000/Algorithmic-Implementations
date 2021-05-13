// Problem: https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
/*****************************************************************************************************/

// METHOD - 1 (Using extra space)
// Ref: https://www.youtube.com/watch?v=FYvqyXYnDHo&list=PL7JyMDSI2BfZugpAjdWc8ES_mYMz2F9Qo&index=26

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
		TreeNode *next;
		TreeNode(): val(0), left(NULL), right(NULL), next(NULL) {}
		TreeNode(int data): val(data), left(NULL), right(NULL), next(NULL) {}
		TreeNode(int data, TreeNode *left, TreeNode *right, TreeNode *next): val(data), left(left), right(right), next(next) {}
};

void lvl_order(TreeNode *root) {
	if(!root or (!root->left and !root->right)) {
		return;
	} 
	
	queue<TreeNode*> q;
	q.push(root);
	
	while(!q.empty()) {
		int sz = q.size();
		while(sz--) {
			TreeNode *x = q.front();
			q.pop();
			
			if(x->left) q.push(x->left);
			if(x->right) q.push(x->right);
			
			TreeNode *y = NULL;
			if(sz != 0) y = q.front();
			x->next = y;
		}
	}
}

void populate(TreeNode *root) {
	lvl_order(root);
}

void solve()
{
  	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(26);
	root->right->left->left = new TreeNode(5);
	root->right->left->right = new TreeNode(10);
	root->right->left->right->left = new TreeNode(8);
	root->right->left->right->right = new TreeNode(9);
	
	populate(root);
	cout << root->right->left->right->left->next << "\n";
	cout << root->right->left->right->left->next->val;
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

/*****************************************************************************************************/

// METHOD - 2 (Using constant space)
// Ref: https://www.geeksforgeeks.org/connect-nodes-at-same-level-with-o1-extra-space/

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
		TreeNode *next;
		TreeNode(): val(0), left(NULL), right(NULL), next(NULL) {}
		TreeNode(int data): val(data), left(NULL), right(NULL), next(NULL) {}
		TreeNode(int data, TreeNode *left, TreeNode *right, TreeNode *next): val(data), left(left), right(right), next(next) {}
};

TreeNode* get_next_right(TreeNode *p) {
	TreeNode *res = p->next;
	while(res != NULL) {
		if(res->left) return res->left;
		if(res->right) return res->right;
		res = res->next;
	}
	
	return res;
} 

void populate(TreeNode *root) {
	if(!root) return;
	root->next = NULL;
	
	while(root != NULL) {
		TreeNode *tmp = root;
		while(tmp != NULL) {
			if(tmp->left) {
				if(tmp->right) tmp->left->next = tmp->right;
				else tmp->left->next = get_next_right(tmp);
			}
			
			if(tmp->right) tmp->right->next = get_next_right(tmp);
			tmp = tmp->next;
		}
		
		if(root->left) root = root->left;
		else if(root->right) root = root->right;
		else root = get_next_right(root); 
	}
}

void solve()
{
  	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(26);
	root->right->left->left = new TreeNode(5);
	root->right->left->right = new TreeNode(10);
	root->right->left->right->left = new TreeNode(8);
	root->right->left->right->right = new TreeNode(9);
	
	populate(root);
	cout << root->right->left->right->left->next << "\n";
	cout << root->right->left->right->left->next->val;
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