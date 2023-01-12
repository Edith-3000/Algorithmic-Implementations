// Problem: https://leetcode.com/problems/valid-parentheses/
// Ref: https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
/*****************************************************************************************************************************************/

// If there are only 1 type of brackets in the input string just use this short code below --->

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

// function to check if brackets are balanced in the string s
bool is_balanced(string &s) {
	int n = (int)s.size();
	int cnt = 0;
	
	for(int i = 0; i < n; i++) {
        if(s[i] == '(') cnt++;
        else {
            if(cnt <= 0) return 0;
            else cnt--;
        }
    }
    
    return cnt == 0;
}

void solve()
{
  	int n; string s; 
  	cin >> n >> s;
  	
  	if(is_balanced(s)) cout << "YES\n";
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

// TC: O(n)

/*****************************************************************************************************************************************************/

// However if the types of brackets in the input string are more use the code below --->

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

// function to check if brackets are balanced in the string s
bool is_balanced(string &s) {
	int n = (int)s.size();
	stack<char> stk;
	char x;
	
	// traversing the Expression
	for(int i = 0; i < n; i++) {
		// push opening brackets in the stack
		if(s[i] == '(' or s[i] == '{' or s[i] == '[') {
			stk.push(s[i]);
		}
		
		else {
			// if current current character is not opening bracket, then 
			// it must be closing. So stack cannot be empty at this point.
			if(stk.empty()) return 0;
			
			switch(s[i]) {
				case ')':
					x = stk.top();
					stk.pop();
					if(x == '{' or x == '[') return 0;
					break;
					
				case '}':
					x = stk.top();
					stk.pop();
					if(x == '[' or x == '(') return 0;
					break;
					
				case ']':
					x = stk.top();
					stk.pop();
					if(x == '(' or x == '{') return 0;
					break;
			}
		}
	}
	
	// check Empty Stack
	return stk.empty();
}

void solve()
{
  	int n; string s; 
  	cin >> n >> s;
  	
  	if(is_balanced(s)) cout << "YES\n";
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

// TC: O(n)