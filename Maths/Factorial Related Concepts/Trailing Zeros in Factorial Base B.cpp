/* Ref: https://www.geeksforgeeks.org/number-of-trailing-zeroes-in-base-b-representation-of-n/
        https://www.youtube.com/watch?v=1Ohlg5alglQ

   Prob. based on this concept :--->
   https://codeforces.com/problemset/problem/1114/C
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

// For any number n and prime number p, this function returns the 
// largest power of p, which divides n!
ll legendre_formula(ll n, ll p) {
	// initialising result
	ll res = 0LL;
	
	// calculating res = n/p + n/(p^2) + n/(p^3) + ....
	while(n > 0) {
		n /= p;
		res += n;
	}
	
	return res;
}
 
// Function which returns the prime factorization of 'n', in the form of ==>
// {prime factor, it's power}
vpll prime_factors(ll n) {
	// to store the result
	vpll res;
	
	for(ll i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			ll cnt = 0LL;
			// while i divides n, increment count by 1 and divide n by i 
			while(n % i == 0) cnt += 1, n /= i;
			res.pb({i, cnt});
		}
	}
	
	// this condition is to handle the case when either n was initially a 
	// prime no. or it has become a prime after coming out of the for loop
	if(n > 1) res.pb({n, 1});
	
	return res;
}
 
// Function which returns the largest power of k that divides n!, 
// where k may not necessarily be a prime number.
// NOTE: k must be > 1
ll largest_power(ll n, ll k) {
	// initialising result
	ll res = LLONG_MAX;
	
	// calculating prime factors of k with their count
	vpll pf = prime_factors(k);
	
	for(auto x: pf) {
		res = min(res, legendre_formula(n, x.F) / x.S);
	}
	
	return res;
}

// Function to find the #trailing 0's in n! represented in base b number system
ll find_trailing(ll n, ll b) {
	return largest_power(n, b);
}
 
void solve()
{
  	ll n, b; cin >> n >> b;
  	
  	ll res = find_trailing(n, b);  	
  	cout << res << "\n";
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