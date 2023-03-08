// Prob: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/

// Ref: https://www.youtube.com/watch?v=s62a0uxeRkE&ab_channel=codingMohan

/*******************************************************************************************************************************************************************/

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

int count_nodes(TreeNode *root) {
    if(root == NULL) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

void euler_tour(TreeNode *root, int &timer, vi &st, vi &ed) {
    st[root->val] = timer;
    
    if(root->left) {
        timer += 1;
        euler_tour(root->left, timer, st, ed);
    }
    
    if(root->right) {
        timer += 1;
        euler_tour(root->right, timer, st, ed);
    }
    
    ed[root->val] = timer;
}

void calc_depth(TreeNode *root, int dep, vi &depth, vi &st) {
    if(root == NULL) return;
    
    // why I did not use depth[root->val] = dep, refer highlighted comment:
    // https://www.youtube.com/watch?v=s62a0uxeRkE&lc=Ugxj4PZ8ZRpQ93bT2eh4AaABAg&ab_channel=codingMohan
    depth[st[root->val]] = dep;
    
    if(root->left) calc_depth(root->left, dep + 1, depth, st);
    if(root->right) calc_depth(root->right, dep + 1, depth, st);
}

vi tree_queries(TreeNode* root, vi &queries) {
    if(root == NULL) return vi();
    
    int n = count_nodes(root);
    
    // st[i] and ed[i] denotes the start time and end time of a node i while DFS traversal
    vi st(n + 1), ed(n + 1);
    
    int timer = 1;
    euler_tour(root, timer, st, ed);
    
    vi depth(n + 1);
    calc_depth(root, 0, depth, st);

    vi pref_max(n + 2, 0), suff_max(n + 2, 0);
    
    for(int i = 1; i <= n; i++) {
        pref_max[i] = max(depth[i], pref_max[i - 1]);
    }
    
    for(int i = n; i >= 1; i--) {
        suff_max[i] = max(depth[i], suff_max[i + 1]);
    }

    int q = sz(queries);
    
    vi res(q);
    
    for(int i = 0; i < q; i++) {
        int L = st[queries[i]], R = ed[queries[i]];
        res[i] = max(pref_max[L - 1], suff_max[R + 1]);
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
	
	int q; cin >> q;
	vi queries(q);
	
	for(int i = 0; i < q; i++) {
		cin >> queries[i];
	}
	
	vi res = tree_queries(root, queries);
	
	for(auto x: res) {
		cout << x << " ";
	}
	
	cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
    // #endif
    
    int t = 1;
    // int test = 1;
    cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}