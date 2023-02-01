// Prob: https://www.hackerrank.com/challenges/min-max-riddle/problem

// Ref: https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/
//      https://www.youtube.com/watch?v=CK8PIAF-m2E

/*****************************************************************************************************************************************************************/

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

const int INF = 1e9+1;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// Function which return the 0-based indices of the NSL elements 
// for every array element
vector<int> nsl_indices(vector<int> &v) {
    int n = (int)v.size();
    if(n <= 0) return v;

    // to store the final result
    vector<int> res(n);

    stack<pair<int, int>> st; 

    for(int i = 0; i < n; i++) {
    	while(!st.empty() && st.top().F >= v[i]) st.pop();
    	
	    if(st.empty()) res[i] = -1;
		else res[i] = st.top().S;

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

	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && st.top().F >= v[i]) st.pop();
		
		if(st.empty()) res[i] = n;
		else res[i] = st.top().S;

		st.push({v[i], i});
	}

	// return the final res vector
	return res;
}

// Function to return the maximum of the minimum(s) of every window size in the array. 
// The window size varies from 1 to n.
// NOTE: in the last it returns a vector[] of size n, where 0th element corresponds 
//       to result for window size = 1, 1st for window size = 2, so on.
vi max_of_min(vi &v) {
    int n = sz(v);
    if(n == 0) return vi();
    
    vi nsl = nsl_indices(v);
    vi nsr = nsr_indices(v);
    
    // to store the final result
    vi res(n + 1, -INF);
    
    // fill result array by comparing minimums of all lengths 
    // computed using nsr[] and nsl[]
    for(int i = 0; i < n; i++) {
    	// length of the window size in which v[i] is the minimum element
        int len = nsr[i] - nsl[i] - 1;
        
        // v[i] is the candidate answer for window length = len
        res[len] = max(res[len], v[i]);
    }
    
    // some entries in res[] may not be filled yet (i.e. still are -INF), 
    // fill them by taking  values from right side of res[] and for the 
    // already filled values the result can be made better, because
    // res[i] will always be >= res[i+1]
    for(int i = n; i >= 1; i--) {
        if(i != n) res[i] = max(res[i], res[i+1]);
    }
    
    for(int i = 0; i < n; i++) res[i] = res[i+1];
    res.ppb();
    
    return res;    
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vi res = max_of_min(v);
      
    for(auto x: res) {
    	cout << x << " ";
    }
      
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