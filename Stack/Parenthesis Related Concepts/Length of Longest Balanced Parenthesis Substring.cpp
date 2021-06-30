// Ref: https://www.techiedelight.com/find-length-longest-balanced-parenthesis-string/
//      https://www.youtube.com/watch?v=qC5DGX0CPFA
/********************************************************************************************************/

// METHOD - 1 (O(n^2))
// Check every substring if it's valid and update the maximum length.

/*******************************************************************************************************/

// METHOD - 2 (O(n) time and space)

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

// Function to return the length of Longest Valid Parenthesis Substring
int LLVPS(string &s) {
	int n = (int)s.size();
	
	// create a stack of integers for storing an index of parenthesis 
	// in the string
	stack<int> stk;
	
	// initialize the stack by -1
	stk.push(-1);
	
	// initialize result
	int res = 0;
	
	// iterate over the characters of the string
	for(int i = 0; i < n; i++) {
		// if the current character is an opening parenthesis, push its index 
		// in the stack, as till now it is a problem parenthesis (since we have
		// not got it's corresponding pair so far)
		if(s[i] == '(') stk.push(i);
		
		// if the current character is a closing parenthesis
		else {
			// pop the top index from the stack, as current char is matched with
			// this stk.top() index char
			stk.pop();
			
			// if the stack becomes empty, push the current index into the stack
			// as now the current closing char is a problem parenthesis
			if(stk.empty()) {
				stk.push(i);
				continue;	
			}
			
			// get length of the longest balanced parenthesis ending
            // at current character
			int tmp = i - stk.top();
			
			// update the length of the longest balanced parenthesis
			res = max(res, tmp);
		}
	}
	
	return res; 
}

void solve()
{
  	string s; cin >> s;
  	cout << LLVPS(s) << "\n";
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

// TC: O(n)
// SC: O(n)

/*****************************************************************************************************/

// METHOD - 3 (O(n) time and space)
// Refer GfG article.