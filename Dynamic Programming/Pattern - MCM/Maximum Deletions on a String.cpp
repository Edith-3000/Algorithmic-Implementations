// Prob: https://leetcode.com/problems/maximum-deletions-on-a-string/

// Ref: https://www.youtube.com/watch?v=EWqHdeTz5Tc&ab_channel=codingMohan

/*******************************************************************************************************************************************************/

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
const ll mod = 1e9+7;

const ll p = 31;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

void pre_compute_hashes(string &s, vvll &hash) {
	int n = sz(s);
	
	for(int i = 0; i < n; i++) {
		// to store the hash value of string
    	ll hash_val = 0LL;
    
    	// since p^0 = 1
    	ll p_power = 1LL;
		
		for(int j = i; j < n; j++) {
			hash_val = (hash_val + ((p_power * (s[j] - 'a' + 1)) % mod) % mod);
        	p_power = (p_power * p) % mod;
        	
        	hash[i].pb(hash_val);
		}
	}
}

int helper(int idx, int n, string &s, vvll &hash, vi &dp) {
	// base case(s)
    if(idx == n) return 0;
    if(idx == n - 1) return 1;
    
    // check if already calculated or not
    if(dp[idx] != -1) return dp[idx];
    
    int res = 1;
    
    // 'k' loop scheme
    for(int k = idx; k + 1 < n; k++) {
    	int len = k - idx + 1;
    	
    	int l1 = idx, r1 = l1 + len - 1;
    	int l2 = r1 + 1, r2 = l2 + len - 1;
    	
        if((r1 >= n) or (r2 >= n)) break;
       
        if(hash[l1][len - 1] == hash[l2][len - 1]) {
            int tmp_ans = 1 + helper(l2, n, s, hash, dp);
            res = max(res, tmp_ans);
        }
    }
    
    return dp[idx] = res;
}

int cnt_max_deletions(string &s) {
	int n = sz(s);
	if(n == 0) return 0;
	
	// hash[i][j] will store hash of the substring starting at index 'i' and of length (j + 1)
	vvll hash(n);
	
	pre_compute_hashes(s, hash);
	
	vi dp(n, -1);
	
	return helper(0, n, s, hash, dp);
}

void solve()
{
  	string s; cin >> s;
  	cout << cnt_max_deletions(s) << "\n";
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