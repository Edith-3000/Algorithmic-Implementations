// Problem: https://www.geeksforgeeks.org/largest-area-rectangular-sub-matrix-equal-number-1s-0s/
/*******************************************************************************************************/

// Idea of the problem is derived from "Largest Rect Sub-Matrix With Sum 0.cpp".
// Every '0' in the matrix as is replaced with '-1' and then we try to find the largest rectangel with
// sum = 0.

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

// Function to find length of the longest subarray with sum given = k
ll find_subarr(vll &v, ll n, ll k) {
	map<ll, ll> m;
	
	// Maintains sum of elements so far 
	ll cur_sum = 0;
	
	ll res = 0;
	
	for(ll i = 0; i < n; i++) {
		// add current element to curr_sum 
		cur_sum += v[i];
		
		// if curr_sum = target sum we found a subarray starting 
		// from index 0 and ending at index i 
		if(cur_sum == k) res = max(res, i + 1);
		
		 // If curr_sum - sum already exists in map we have found a 
		 // subarray with target sum 
		if(m.find(cur_sum - k) != m.end()) {
			res = max(res, i - m[cur_sum - k]);
		}
		
		if(m.find(cur_sum) == m.end()) {
			m[cur_sum] = i;
		}
	}
	
	return res;
}

ll eql_0_and_1_rect(vvi &v) {
	int n = sz(v);
	if(n == 0) return 0LL;
	int m = sz(v[0]);
	
	ll res = 0;
	
	if(((ll)n * n * m) <= ((ll)m * m * n)) {
		for(int i = 0; i < n; i++) {
			vll tmp(m, 0LL);
			for(int j = i; j < n; j++) {
				for(int col = 0; col < m; col++) {
					tmp[col] += (v[j][col] ? 1 : -1);
			    }
			
				res = max(res, find_subarr(tmp, m, 0LL) * (j - i + 1));
		    }
	    }
	}
	
	else {
		for(int i = 0; i < m; i++) {
			vll tmp(n, 0LL);
			for(int j = i; j < m; j++) {
				for(int row = 0; row < n; row++) {
					tmp[row] += (v[row][j] ? 1 : -1);
			    }
			
				res = max(res, find_subarr(tmp, n, 0LL) * (j - i + 1));
		    }
	    }
	}
	
	return res;
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vvi v(n, vi(m));
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < m; j++) cin >> v[i][j];
  	}
  	
  	cout << eql_0_and_1_rect(v) << "\n";
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

// Time complexity: min(O(n x n x m x log(m)), O(m x m x n x log(n)))