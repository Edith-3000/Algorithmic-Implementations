// Problem: https://www.interviewbit.com/problems/valid-bst-from-preorder/
// Ref: https://medium.com/@PherricOxide/coding-question-could-a-given-array-of-integers-represent-a-pre-order-traversal-of-a-binary-6871eaa8d1e1
//		https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
/*************************************************************************************************************************************************/

// METHOD - 1 O(n^2) 

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

// In the below function, the following definition of BST is assumed:
// For any given node in the binary tree, all nodes to the left of it have equal 
// or smaller keys & all nodes to the right of it have keys greater than it.

// function to check whether the given input vector v is a valid
// pre-order traversal of a BST or not.
// If it return false, then it indicates that the tree either isn’t a BST or 
// it wasn’t traversed with pre-order traversal.
bool is_preorder(vi &v, int start, int end) {
	// Base case: Return true if there's one or no keys in the given range.
	if(start >= end) return 1;
	
	// The first element in the range should be the root of our current subtree.
	int root = v[start];
	
	// Find the first value larger than root, which should be the 
	// start of the right subtree.
	// rs_tree stores the index of the root of right subtree
	int rs_root = -1;
	
	for(int i = start + 1; i <= end; i++) {
		if(v[i] > root) {
			rs_root = i;
			break;
		}
	}
	
	if(rs_root == -1) rs_root = end + 1;
	
	// Verify all values in the right subtree are larger than the root
	for(int i = rs_root + 1; i <= end; i++) {
		if(v[i] <= root) return 0;
	}
	
	// Invoke ourselves on the left and then right subtrees
	return is_preorder(v, start + 1, rs_root - 1) and
	       is_preorder(v, rs_root, end);
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	if(is_preorder(v, 0, n - 1)) cout << "YES\n";
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

/**************************************************************************************************/

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

// In the below function, the following definition of BST is assumed:
// For any given node in the binary, all nodes to the left of it have equal 
// or smaller keys & all nodes to the right of it have keys greater than it.

// function to check whether the given input vector v is a valid
// pre-order traversal of a BST or not.
// If it return false, then it indicates that the tree either isn’t a BST or 
// it wasn’t traversed with pre-order traversal.
bool is_preorder(vi &v) {
	// Create an empty stack
	stack<int> s;
	int n = v.size();
	
	// Initialize current root as minimum possible value
	int root = INT_MIN;
	
	for(int i = 0; i < n; i++) {
		// If we find a node who is on right side & smaller than
		// or equal to root, return false
		if(v[i] <= root) {
			return 0;
		}
		
		// If v[i] is in right subtree of stack top, keep removing 
		// items smaller than v[i] & make the last removed item as new root.
		while(!s.empty() and v[i] > s.top()) {
			root = s.top();
			s.pop();
		}
		
		// At this point either stack is empty or v[i] is smaller than 
		// or equal to root, push v[i]
		s.push(v[i]);
	}
	
	return 1;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	if(is_preorder(v)) cout << "YES\n";
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