// Prob: https://leetcode.com/problems/longest-common-subpath/

/***************************************************************************************************************/

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

const ll p = 165131LL;
const ll mod = 1e9 + 7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

class cmp {
	public:
		bool operator() (const vi &v1, const vi &v2) {
			return sz(v1) < sz(v2);
		}
};

bool is_valid(ll len, vvi &v) {
	map<ll, ll> cnt;
	
	 // to store the hash value of vector
    ll hash = 0LL;
    
    // since p^0 = 1
    ll p_power = 1LL;
	
	for(ll i = 0; i < len; i++) {
		hash = (hash + ((p_power * v[0][i]) % mod) % mod);
        p_power = (p_power * p) % mod;
	}
	
	cnt[hash] = 1LL;
	
	// precompute the mod_mul_inv of p under modulo mod
    ll x = mod_inv(p);
	
	for(ll i = 1; i <= (sz(v[0]) - len); i++) {
		ll curr_hash = hash;
	    
	    // Step 1: remove the contribution of the first character 
	    // from the hash value of previous window
	    curr_hash = (curr_hash - (v[0][i-1]) + mod) % mod;
	    
	    // Step 2: divide the hash value by p
	    // as division is under modulo mod, therefore we can calculate
	    // mod_mul_inv of p under modulo mod
	    curr_hash = (curr_hash * x) % mod;
	    
	    // Step 3: inculcate the contribution of the last character of the
	    // current window 
	    curr_hash = (curr_hash + ((mod_exp(p, len-1) * (v[0][i + len - 1])) % mod)) % mod;
	    
	    // update for next iteration
        hash = curr_hash;
        
        cnt[hash] = 1LL;
	}
	
	for(ll idx = 1; idx < sz(v); idx++) {
		hash = 0LL;
		p_power = 1LL;
		
		for(ll i = 0; i < len; i++) {
			hash = (hash + ((p_power * v[idx][i]) % mod) % mod);
	        p_power = (p_power * p) % mod;
		}
		
		if(cnt.count(hash) > 0 and cnt[hash] == idx) {
	    	cnt[hash] += 1LL;
	    }
		
		for(ll i = 1; i <= (sz(v[idx]) - len); i++) {
			ll curr_hash = hash;
		    
		    // Step 1: remove the contribution of the first character 
		    // from the hash value of previous window
		    curr_hash = (curr_hash - (v[idx][i-1]) + mod) % mod;
		    
		    // Step 2: divide the hash value by p
		    // as division is under modulo mod, therefore we can calculate
		    // mod_mul_inv of p under modulo mod
		    curr_hash = (curr_hash * x) % mod;
		    
		    // Step 3: inculcate the contribution of the last character of the
		    // current window 
		    curr_hash = (curr_hash + ((mod_exp(p, len-1) * (v[idx][i + len - 1])) % mod)) % mod;
		    
		    // update for next iteration
	        hash = curr_hash;
	        
	        if(cnt.count(hash) > 0 and cnt[hash] == idx) {
	        	cnt[hash] += 1LL;
	        }
		}
	}
	
	for(auto pr: cnt) {
		if(pr.S == sz(v)) return 1;
	}
	
	return 0;
}

int longest_common_subpath(vvi &v) {
	int n = sz(v);
	
	sort(v.begin(), v.end(), cmp());
	
	ll res = 0LL;
	ll L = 0LL, R = sz(v[0]);
	
	while(L <= R) {
		ll mid = L + ((R - L) >> 1LL);
		
		if(is_valid(mid, v)) {
			res = mid; 
			L = mid + 1;	
		}
		
		else R = mid - 1;
	}
	
	return (int)res;
}

void solve()
{
	int n; cin >> n;
	vvi v(n);
	
	for(int i = 0; i < n; i++) {
		int m; cin >> m;
		v[i].resize(m);
		
		for(int j = 0; j < m; j++) cin >> v[i][j];
	}
	
	cout << longest_common_subpath(v) << "\n";
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