// Prob: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
// Ref: https://www.youtube.com/watch?v=UoKGRTIZvM0
//      https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/discuss/2121935/C-%2B%2B-Meet-in-Middle-but-no-TLE-faster-than-50
//      https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/discuss/1919930/Meet-in-the-middle-Solution
//      https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/discuss/2072571/Meet-in-the-Middle-or-C%2B%2B-or-Standard-Implementation
/*************************************************************************************************************************************************************************/


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

const int INF = INT_MAX;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

vvi generate_subsets(int l, int r, vi &v) {
	int len = r - l + 1;
	vvi res(len + 1);
	
	for(int mask = 0; mask < (1 << len); mask++) {
		int sum = 0, cnt = 0;
		
		for(int i = 0; i < len; i++) {
			if(mask & (1 << i)) {
				sum += v[l + i];
				cnt += 1;
			}
		}
		
		res[cnt].pb(sum);
	}
	
	for(int i = 0; i <= len; i++) {
		sort(res[i].begin(), res[i].end());
	}
	
	return res;
}

int find_ans(vi &v) {
	int n = sz(v);
	n /= 2;
	
	int tot = 0;
	
	for(int i = 0; i < (2 * n); i++) {
		tot += v[i];
	}
	
	vvi lf = generate_subsets(0, n - 1, v);
	vvi rg = generate_subsets(n, 2 * n - 1, v);
	
	int res = INF;
	
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < sz(lf[i]); j++) {
			int taken = i, req = n - taken;
			int lf_sum = lf[i][j], desired = (tot / 2) - lf_sum;
			
			int idx = lower_bound(rg[req].begin(), rg[req].end(), desired) - rg[req].begin();
			
			if(idx < sz(rg[req])) {
				lf_sum += rg[req][idx];
				res = min(res, abs(tot - (2 * lf_sum)));
				lf_sum -= rg[req][idx];
			}
			
			if(idx != 0) {
				idx -= 1;
				lf_sum += rg[req][idx];
				res = min(res, abs(tot - (2 * lf_sum)));
				lf_sum -= rg[req][idx];
			}
		}
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	
  	vi v(2 * n);
  	for(int i = 0; i < (2 * n); i++) cin >> v[i];
  	
  	cout << find_ans(v) << "\n";
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
    cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}