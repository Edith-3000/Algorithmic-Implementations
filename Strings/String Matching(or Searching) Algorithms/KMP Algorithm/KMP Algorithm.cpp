// PROBLEM STATEMENT: Given a text and a pattern, find all occurrences of pattern in text.

// Ref: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
//      https://www.youtube.com/watch?v=ziteu2FpYsA
//      https://cp-algorithms.com/string/prefix-function.html
//      https://towardsdatascience.com/pattern-search-with-the-knuth-morris-pratt-kmp-algorithm-8562407dba5b

/*****************************************************************************************************************************************************************/

/*
   # The most important difference between KMP & Rabin-Karp is how reliable they are in finding a match. 

   # KMP guarantees 100% reliability. You cannot guarantee 100% with Rabin Karp because of a chance of collision 
     during hash table lookup. 
    
   # But with good hash generation algorithms that do exist today, it is possible that Rabin Karp can yield very 
     close to 100% reliability in finding a match. And both have complexity of O(n + m). Also Rabin Karp is easier 
     to implement than KMP it works based on a rolling hash whereas KMP works based on a failure function.


   # The KMP matching algorithm uses degenerating property (pattern having the same sub-patterns appearing more than once in the pattern)
     of the pattern and improves the worst-case complexity to O(n). 

   # The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of the characters
     in the text of the next window. We take advantage of this information to avoid matching the characters that we know will anyway match. 
*/

/*****************************************************************************************************************************************************************/

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

vi prefix_function_optimized(string &s) {
    int n = sz(s);
    
    // lps[i] = the length of the longest proper prefix which
    //          is also a suffix of the string s[0...i]
    vi lps(n);
    
    // since proper prefix of a string of length 1 can be of length 0
    lps[0] = 0;
 
    // traverse the string
    for (int i = 1; i < n; i++) {
        int prev_ind = lps[i - 1];
 
        while (prev_ind > 0 and s[i] != s[prev_ind]) {
            prev_ind = lps[prev_ind - 1];
        }
        
        if(s[prev_ind] == s[i]) prev_ind += 1;

        // update the lps size for string [0....i]
        lps[i] = prev_ind;
    }
 
    // return lps array calculated
    return lps;
}

// return 0-based indices
vi KMP(string &txt, string &pat) {
	int n = sz(txt);
	int m = sz(pat);
	
	// impossible case
	if(n < m) return vi();
	
	// calculating the lps for pattern
	vi lps = prefix_function_optimized(pat);
	
	// for storing the result
	vi res;
	
	// i = iterator for the text, j = iterator for pattern
	// such that i & j are indices of the next char to be matched with the each other 
	int i = 0, j = 0;
	
	while(i < n) {
		if(txt[i] == pat[j]) {
			i++; j++;
		}
		
		else {
			if(j == 0) i++;
			else j = lps[j-1];
		}
		
		if(j == m) {
			res.pb(i - m);
			j = lps[j-1];
		}
	}
	
	return res;
}

void solve()
{
  	string txt, pat;
  	cin >> txt >> pat;
  	
  	vi res = KMP(txt, pat);
  	
  	if(sz(res) == 0) cout << "Not found.\n";
  	else {
  		cout << "Found at indices ===>\n";
  		for(auto x: res) cout << x << " ";
  		cout << "\n";
  	}
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

// Time complexity: O(n + m)
// Space complexity: O(m)

/*****************************************************************************************************************************************************************/

// Following is a very simple & short implementation of the above method by making use of prefix function
// only on the concatenated string i.e. on pattern + "$" + text

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

vi prefix_function_optimized(string &s) {
	int n = sz(s);
	
	// lps[i] = the length of the longest proper prefix which
    //          is also a suffix of the string s[0...i]
    vi lps(n);
    
    // since proper prefix of a string of length 1 can be of length 0
    lps[0] = 0;
 
    // traverse the string
    for (int i = 1; i < n; i++) {
        int prev_ind = lps[i - 1];
 
        while (prev_ind > 0 and s[i] != s[prev_ind]) {
            prev_ind = lps[prev_ind - 1];
        }
 
        // update the lps size for string [0....i]
        lps[i] = prev_ind + (s[i] == s[prev_ind] ? 1 : 0);
    }
 
    // return lps array calculated
    return lps;
}

// return 0-based indices
vi KMP(string &txt, string &pat) {
	int n = sz(txt);
	int m = sz(pat);
	
	// impossible case
	if(n < m) return vi();
	
	string good = pat + "$" + txt;
	
	// calculating the lps for string "good"
	vi lps = prefix_function_optimized(good);
	
	// for storing the result
	vi res;
	
	for(int i = (m + 1); i < sz(good); i++){
    	if(lps[i] == m){
    		res.pb((i - m + 1) - (m + 1));
    	}
    }
	
	return res;
}

void solve()
{
  	string txt, pat;
  	cin >> txt >> pat;
  	
  	vi res = KMP(txt, pat);
  	
  	if(sz(res) == 0) cout << "Not found.\n";
  	else {
  		cout << "Found at indices ===>\n";
  		for(auto x: res) cout << x << " ";
  		cout << "\n";
  	}
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

// Reference: https://cp-algorithms.com/string/prefix-function.html
// Time complexity: O(n + m)
// Space complexity: O(m)