// Prob: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

// Ref: https://www.youtube.com/watch?v=bzF9Ia1XISQ&list=PLDdcY4olLQk1-yJxgljSQ4ykbI2Bw1CqS&index=13

/************************************************************************************************************************************************************/

// METHOD - 1

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
	if(root->left or root->right) res.pb(root->val);
	
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

/************************************************************************************************************************************************************/

// METHOD - 2
// https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/
// No change in logic, only implementation is slightly different.

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())
#define vset(v, n, val) v.clear(); v.resize(n, val)

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(queue <T> v);
template <class T> void _print(priority_queue <T> v);
template <class T> void _print(stack <T> s);

// modify it's definition below as per need such as it can be used for STL containers with custom args passed
template <class T> void _print(T v); 

template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(multimap <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.front()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(priority_queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(stack <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(T v) {  }

/*******************************************************************************************************************************************************************/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

class TreeNode {
	public:
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(): val(0), left(NULL), right(NULL) {}
		TreeNode(int data): val(data), left(NULL), right(NULL) {}
		TreeNode(int data, TreeNode *left, TreeNode *right): val(data), left(left), right(right) {}
};

bool is_leaf(TreeNode *node) {
	if(node == NULL) return 0;
	return ((node->left == NULL) and (node->right == NULL));
}

void left_boundary(TreeNode *node, vi &Lf) {
	while(node) {
		if(!is_leaf(node)) Lf.pb(node->val);
		if(node->left) node = node->left;
		else node = node->right;
	}
}

void leaf_boundary(TreeNode *node, vi &Lv) {
	if(node == NULL) return;
	if(is_leaf(node)) Lv.pb(node->val);
	
	leaf_boundary(node->left, Lv);
	leaf_boundary(node->right, Lv);
}

void right_boundary(TreeNode *node, vi &Rg) {
	while(node) {
		if(!is_leaf(node)) Rg.pb(node->val);
		if(node->right) node = node->right;
		else node = node->left;
	}
}

vi boundary_traversal(TreeNode *root) {
	if(root == NULL) return vi();
	
	vi res;
	if(!is_leaf(root)) res.pb(root->val);
	
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
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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