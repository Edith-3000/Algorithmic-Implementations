// Problem: https://www.interviewbit.com/problems/identical-binary-trees/
//          https://leetcode.com/problems/same-tree/

// Ref: https://takeuforward.org/data-structure/check-if-two-trees-are-identical/

/*********************************************************************************************************************************************************************/

// RECURSIVE IMPLEMENTATION

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

bool are_identical(TreeNode *root1, TreeNode *root2) {
	if(!root1 and !root2) return 1;
	if(!root1 or !root2) return 0;
	if(root1->val != root2->val) return 0;
	
	bool x = are_identical(root1->left, root2->left);
	bool y = are_identical(root1->right, root2->right);
	
	return x && y;
}

void solve()
{
  	TreeNode* root1 = new TreeNode(1);
	root1->left = new TreeNode(2);
	root1->right = new TreeNode(3);
	root1->right->left = new TreeNode(4);
	root1->right->right = new TreeNode(5);
	root1->right->left->left = new TreeNode(6);
	root1->right->left->right = new TreeNode(7);
	root1->right->left->right->left = new TreeNode(8);
	root1->right->left->right->right = new TreeNode(9);
	
	TreeNode* root2 = new TreeNode(1);
	root2->left = new TreeNode(2);
	root2->right = new TreeNode(3);
	root2->right->left = new TreeNode(4);
	root2->right->right = new TreeNode(5);
	root2->right->left->left = new TreeNode(6);
	root2->right->left->right = new TreeNode(7);
	root2->right->left->right->left = new TreeNode(8);
	root2->right->left->right->right = new TreeNode(9);
	
	if(are_identical(root1, root2)) cout << "YES\n";
	else cout << "NO\n";
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

/*********************************************************************************************************************************************************************/

// ITERATIVE IMPLEMENTATION

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

bool are_identical(TreeNode *root1, TreeNode *root2) {
	if(!root1 and !root2) return 1;
	if(!root1 or !root2) return 0;
	
	queue<TreeNode*> q;
	q.push(root1);
	q.push(root2);
	
	while(!q.empty()) {
		TreeNode* cur1 = q.front();
		q.pop();
		
		TreeNode* cur2 = q.front();
		q.pop();
		
		if(cur1->val != cur2->val) return 0;
		
		if(cur1->left or cur2->left) {
			if(cur1->left == NULL or cur2->left == NULL) return 0;
			q.push(cur1->left);
			q.push(cur2->left);
		}
		
		if(cur1->right or cur2->right) {
			if(cur1->right == NULL or cur2->right == NULL) return 0;
			q.push(cur1->right);
			q.push(cur2->right);
		}
	}
	
	return 1;	
}

void solve()
{
  	TreeNode* root1 = new TreeNode(1);
	root1->left = new TreeNode(2);
	root1->right = new TreeNode(3);
	root1->right->left = new TreeNode(4);
	root1->right->right = new TreeNode(5);
	root1->right->left->left = new TreeNode(6);
	root1->right->left->right = new TreeNode(7);
	root1->right->left->right->left = new TreeNode(8);
	root1->right->left->right->right = new TreeNode(9);
	
	TreeNode* root2 = new TreeNode(1);
	root2->left = new TreeNode(2);
	root2->right = new TreeNode(3);
	root2->right->left = new TreeNode(4);
	root2->right->right = new TreeNode(5);
	root2->right->left->left = new TreeNode(6);
	root2->right->left->right = new TreeNode(7);
	root2->right->left->right->left = new TreeNode(8);
	root2->right->left->right->right = new TreeNode(9);
	
	if(are_identical(root1, root2)) cout << "YES\n";
	else cout << "NO\n";
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
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}