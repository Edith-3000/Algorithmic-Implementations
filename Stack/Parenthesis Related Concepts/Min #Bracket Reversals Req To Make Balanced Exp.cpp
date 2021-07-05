// Prob: https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/
/*****************************************************************************************************************/

// METHOD - 1 
// O(n) time and space

/* UNDERLYING CONCEPT ===>
   # Steps : 
   1. As we want to swap the brackets to make it balanced, therefore, the balanced subportions won't 
      be helpful. Let's just remove them.
   2. We are left with only the unbalanced paranthesis in the stack. 
      After removing balanced part, we always end up with an expression of the form }}…}{{…{, an 
      expression that contains 0 or more number of closing brackets followed by 0 or more numbers of 
      opening brackets. 
      Also, note that the stack size has to even if we want to balance the "unbalanced subportions".

   # As we are given only two characters ( '{' & '}' ) therefore, we can boil down our logic to simple
     mathematical observation : 
     * even + even = even;
     * odd + odd = even;

   # Case 1 : When e + e = e i.e. even no of open brackets + even no of close brackets 
     eg : } } { {

     We have to make a balanced pair, so total swaps = open / 2 + close / 2; 
     which can also be written as : (open + close)/2  => stack.size()/2;l
     Note : Note that, in case of even open and even close brackets, every bracket will be paired and 
            balanced.

   # Case 2 : When o + o = e i.e. odd no of open brackets + odd no of close brackets
     eg : } } } { { {
     Note : an odd number can be written as even + 1 ( eg : 5 = 4 + 1 ) i.e. 5 open =  4 open + 1 open
     bracket. This 4 open can be solved using earlier logic. The remaining 1 open will be paired up 
     with the 1 close so, we have 1 more pair. See below : 
     We have to make a balanced pair, so 

     swaps to make open balanced = open / 2 + 1 
     swaps to make close balanced = close / 2 + 1 

     total swaps = open/2 + 1 + close/2 + 1 = (open+close)/2 + 2 => stack.size()/2 + 1.

     Why stack.size() + 1 ? Why we did +1 is because we have 1 open unbalanced bracket and 1 close 
     unbalanced bracket, which can be used to form 1 pair i.e. 1 swap.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())

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
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

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

int min_swaps(string &s) {
	int n = sz(s);
	if(n == 0) return 0;

	// length of expression must be even to make it balanced by using reversals.
	if(n & 1) return -1;
	
	// after this loop, stack contains unbalanced part of expression, i.e., 
	// expression of the form "}}..}{{..{""
	stack<int> stk;
	for(int i = 0; i < n; i++) {
		if(s[i] == '{') stk.push(s[i]);
		else {
			if(stk.empty() or stk.top() != '{') stk.push(s[i]);
			else stk.pop();
		}
	}
	
	int tot = stk.size();
	int open = 0;
	
	// count opening brackets at the end of stack
	while(!stk.empty() and stk.top() == '{') {
		open += 1;
		stk.pop();
	}
	
	int close = tot - open;
	
	return (close + 1) / 2 + (open + 1) / 2;
}

void solve()
{
  	string s; cin >> s;
  	cout << min_swaps(s) << "\n";
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

/*****************************************************************************************************/

// METHOD - 2 
// O(n) time and O(1) space

// Concept is same as above METHOD but here stack is not used.

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())

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
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

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

int min_swaps(string &s) {
	int n = sz(s);
	if(n == 0) return 0;

	// length of expression must be even to make it balanced by using reversals.
	if(n & 1) return -1;
	
	int open = 0, close = 0;
	
	// after this loop, open and close contains count of unbalanced part of expression
	for(int i = 0; i < n; i++) {
		if(s[i] == '{') open += 1;
		else {
			if(open == 0) close += 1;
			else open -= 1;
		}
	}
		
	return (close + 1) / 2 + (open + 1) / 2;
}

void solve()
{
  	string s; cin >> s;
  	cout << min_swaps(s) << "\n";
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