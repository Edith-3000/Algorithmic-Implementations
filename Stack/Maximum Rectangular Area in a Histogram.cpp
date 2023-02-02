/* Link: https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
         https://leetcode.com/problems/largest-rectangle-in-histogram/

   PROBLEM STATEMENT: Find the largest rectangular area possible in a given histogram where the largest 
                      rectangle can be made of a number of contiguous bars. For simplicity, assume that all 
                      bars have same width and the width is 1 unit.
                      For example, consider the following histogram with 7 bars of heights 
                      {6, 2, 5, 4, 5, 1, 6}. The largest possible rectangle possible is 12.
*/

/****************************************************************************************************************************************************************/

// METHOD - 1 (BRUTE FORCE APPROACH: O(n^2))

/* One by one consider all bars as starting points and calculate area of all rectangles starting with every
   bar. Finally return maximum of all possible areas.
*/

/****************************************************************************************************************************************************************/

// METHOD - 2 O(n)
// The solution is based on such a simple observation that the height of an optimum rectangle will be equal 
// to that of at least one of the histograms. Then find the max area you can get assuming height equal to 
// that of a particular histogram. Iterate over all to find maximum result.

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

// Function which return the 0-based indices of the NSL elements 
// for every array element
vector<int> nsl_indices(vector<int> &v) {
    int n = (int)v.size();
	if(n <= 0) return v;

	// to store the final result
	vector<int> res(n);

	stack<pair<int, int>> st; 
	int pseudo_idx = -1;

    for(int i = 0; i < n; i++) {
	    if(st.empty()) res[i] = pseudo_idx;
		else if(st.top().F < v[i]) res[i] = st.top().S;

		else {
		    while(!st.empty() && st.top().F >= v[i]) st.pop();

		    if(st.empty()) res[i] = pseudo_idx;
		    else res[i] = st.top().S;
		}

	    st.push({v[i], i});
    }

    // return the final res vector
	return res;
}

// Function which return the 0-based indices of the NSR elements 
// for every array element
vector<int> nsr_indices(vector<int> &v) {
	int n = (int)v.size();
	if(n <= 0) return v;

	// to store the final result
	vector<int> res(n);

	stack<pair<int, int>> st; 
	int pseudo_idx = n;

	for(int i = n - 1; i >= 0; i--) {
	    if(st.empty()) res[i] = pseudo_idx;
		else if(st.top().F < v[i]) res[i] = st.top().S;

		else {
			while(!st.empty() && st.top().F >= v[i]) st.pop();

			if(st.empty()) res[i] = pseudo_idx;
			else res[i] = st.top().S;
		}

		st.push({v[i], i});
	}

	// return the final res vector
	return res;
}

int max_rect_in_hist(vi &v) {
	int n = (int)v.size();
	if(n == 0) return 0;
	
	vi nsl = nsl_indices(v);
	vi nsr = nsr_indices(v);
	
	vi area(n);

	for(int i = 0; i < n; i++) {
		area[i] = (nsr[i] - nsl[i] - 1) * v[i];
	}
	
	int res = *max_element(area.begin(), area.end());

	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << max_rect_in_hist(v) << "\n";
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

// Time Complexity: O(n)
// Space Complexity: O(n), where n is v.size()

/****************************************************************************************************************************************************************/

// METHOD - 3
// A single pass approach can be viewed at :--->
// https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/

// Although the below algorithm can be made as a single pass.
// https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-using-stack/

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

int max_rect_in_hist(vi &v) {
	int n = (int)v.size();
	if(n == 0) return 0;
	
	int res = 0;
	
	stack<int> stk;
	int i = 0;
	
	while(i < n) {
		if((stk.empty()) or (v[i] >= v[stk.top()])) {
			stk.push(i);
			i += 1;
		}
		
		else {
			int idx = stk.top();
			stk.pop();
			
			int L = stk.empty() ? -1 : stk.top();
			int R = i;
			
			int area = v[idx] * (R - L - 1);
			res = max(res, area); 
		}
	}
	
	while(!stk.empty()) {
		int idx = stk.top();
		stk.pop();
		
		int L = stk.empty() ? -1 : stk.top();
		int R = i;
		
		int area = v[idx] * (R - L - 1);
		res = max(res, area); 
	}

	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << max_rect_in_hist(v) << "\n";
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

// Time Complexity: O(n)
// Space Complexity: O(n), where n is v.size()