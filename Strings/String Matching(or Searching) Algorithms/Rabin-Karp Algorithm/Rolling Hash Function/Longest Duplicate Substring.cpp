// Prob: https://leetcode.com/problems/longest-duplicate-substring/description/

// Reference for few calculations taken from: https://cp-algorithms.com/string/string-hashing.html#applications-of-hashing

/*********************************************************************************************************************************************************************/

// METHOD - 1

// NOTE: THIS METHOD WILL GIVE "TLE" IF THE TESTCASES ARE GODD.

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

void precomputing(int n, string &s, ll p, ll mod, vll &p_pow, vll &pref_hash) {
	// precomputing powers of p modulo mod
	p_pow[0] = 1LL;
	
	for(int i = 1; i < sz(p_pow); i++) {
		p_pow[i] = (p_pow[i - 1] * p) % mod;
	}
	
	// precomputing prefix hashes of s
	for(int i = 0; i < n; i++) {
		ll contri = ((s[i] - 'a' + 1) * p_pow[i]) % mod;
		pref_hash[i] = contri;
		if(i > 0) pref_hash[i] = (pref_hash[i] + pref_hash[i - 1]) % mod;
	}
}

string longest_dup_substr(string &s) {
	int n = sz(s);
	
	// base case
	if(n == 0) return "";
	
	// it is reasonable to make p a prime number roughly equal to the number of unique characters 
	// in the input alphabet
	ll p = 31;
	
	// mod should be a large prime number, such that chances of generated hashes' collisions are reduced,
	// and also shouldn't be that large that we aren't able to make calculations
	ll mod = 1e9 + 9;
	
	// doing precomputations
	vll p_pow(n), pref_hash(n);
	precomputing(n, s, p, mod, p_pow, pref_hash);
	
	int mx_len = 0, idx = -1;
	
	for(int len = 1; len <= n; len++) {
		map<ll, int> cnt;
		
		for(int i = 0; i <= (n - len); i++) {
			ll cur_hash = pref_hash[i + len - 1];
			if(i > 0) cur_hash = (cur_hash - pref_hash[i - 1] + mod) % mod;
			cur_hash = (cur_hash * p_pow[n - i - 1]) % mod;
			
			cnt[cur_hash] += 1;
			
			if(cnt[cur_hash] >= 2) {
				mx_len = len;
				idx = i;
				break;
			}
		}
	}
	
	if(mx_len == 0) return "";
	else return s.substr(idx, mx_len);
}

void solve()
{
  	string s; cin >> s;
  	
  	string res = longest_dup_substr(s);
  	
  	if(sz(res) == 0) cout << "No duplicate substring present.\n";
  	else cout << res << "\n";
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

/*********************************************************************************************************************************************************************/

// METHOD - 2

// NOTE: BELOW ALGORITHM IS NOT GETTING AC ON LEETCODE

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
// const int mod = 1e9+7;

// ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         // while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
//                          
// ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

int good(int len, ll mod, int n, vll &p_pow, vll &pref_hash) {
	if(len == 0) return -1;
	
	set<ll> st;
	
	for(int i = 0; i <= (n - len); i++) {
		ll cur_hash = pref_hash[i + len - 1];
		if(i > 0) cur_hash = (cur_hash - pref_hash[i - 1] + mod) % mod;
		cur_hash = (cur_hash * p_pow[n - i - 1]) % mod;
		
		if(st.find(cur_hash) != st.end()) {
			return i;
		}
		
		else st.insert(cur_hash);
	}
	
	return -1;
}

void precomputing(int n, string &s, ll p, ll mod, vll &p_pow, vll &pref_hash) {
	// precomputing powers of p modulo mod
	p_pow[0] = 1LL;
	
	for(int i = 1; i < sz(p_pow); i++) {
		p_pow[i] = (p_pow[i - 1] * p) % mod;
	}
	
	// precomputing prefix hashes of s
	for(int i = 0; i < n; i++) {
		ll contri = ((s[i] - 'a' + 1) * p_pow[i]) % mod;
		pref_hash[i] = contri;
		if(i > 0) pref_hash[i] = (pref_hash[i] + pref_hash[i - 1]) % mod;
	}
}

string longest_dup_substr(string &s) {
	int n = sz(s);
	
	// base case
	if(n == 0) return "";
	
	// it is reasonable to make p a prime number roughly equal to the number of unique characters 
	// in the input alphabet
	ll p = 31;
	
	// mod should be a large prime number, such that chances of generated hashes' collisions are reduced,
	// and also shouldn't be that large that we aren't able to make calculations
	ll mod = 1e9 + 9;
	
	// doing precomputations
	vll p_pow(n), pref_hash(n);
	precomputing(n, s, p, mod, p_pow, pref_hash);
		
	int mx_len = 0, idx = -1;
	
	int L = 0, R = n;
	
	while(L <= R) {
		int mid = L + ((R - L) >> 1);
		
		int x = good(mid, mod, n, p_pow, pref_hash);
		
		if(x != -1) {
			mx_len = mid;
			idx = x;
			L = mid + 1; 
		}
		
		else R = mid - 1;
	}
	
	if(mx_len == 0) return "";
	else return s.substr(idx, mx_len);
}

void solve()
{
  	string s; cin >> s;
  	
  	string res = longest_dup_substr(s);
  	
  	if(sz(res) == 0) cout << "No duplicate substring present.\n";
  	else cout << res << "\n";
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