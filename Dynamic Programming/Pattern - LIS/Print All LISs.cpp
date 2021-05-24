// Problem: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/lis-re-official/ojquestion
// Ref: https://www.youtube.com/watch?v=3mD20VSib5E&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=11
/********************************************************************************************************************************************/

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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;

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

struct path {
	int len, idx, ele;
	vi stg;
};

// dp[i] = LIS length ending at index i of the vector v[]
vi dp;

vvi print_all_LIS(vi &v, int n) {
    dp.clear();
	dp.resize(n, 0);
	
	// initialisation of dp matrix 
	// LIS ending with v[0] has length = 1
	dp[0] = 1;
	
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(v[j] < v[i] and dp[j] > dp[i]) dp[i] = dp[j];
		}
		
		dp[i] += 1;
	}
	
	int mx_len = dp[0];
	for(int i = 1; i < n; i++) mx_len = max(mx_len, dp[i]);
	
	queue<path> q;
	for(int i = 0; i < n; i++) {
		if(dp[i] == mx_len) {
			struct path p;
			p.len = dp[i]; p.idx = i; p.ele = v[i];
			vi tmp = {v[i]};
			p.stg = tmp;
			q.push(p);
		}
	}
	
	vvi res;
	
	while(!q.empty()) { 
		auto curr = q.front();
		q.pop();
		
		if(curr.len == 1) {
			reverse(curr.stg.begin(), curr.stg.end());
			res.pb(curr.stg);
		}
		
		for(int i = 0; i < curr.idx; i++) {
			if(v[i] < curr.ele and dp[i] == curr.len - 1) {
				struct path p;
				p.len = dp[i]; p.idx = i; p.ele = v[i];
				vi tmp = curr.stg;
				tmp.pb(v[i]);
				p.stg = tmp;
				q.push(p);
			}
		}
	}
	
	return res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vvi res = print_all_LIS(v, n);
    
    for(auto vec: res) {
    	for(auto x: vec) cout << x << " ";
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

// Time complexity: O(n^2 + (m x n))
// O(n^2) for forming the dp[] array and (m x n) for finding all the LISs, where m is the total #LIS