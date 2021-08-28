// USING NAIVE or BRUTE FORCE APPROACH

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

// Function which returns the prime factorization of 'n', in the form of ==>
// {prime factor, it's power}
vpll prime_factors(ll n) {
	// to store the result
	vpll res;
	
	for(ll i = 2; i <= n; i++) {
		if(n % i == 0) {
			ll cnt = 0LL;
			// while i divides n, increment count by 1 and divide n by i 
			while(n % i == 0) cnt += 1, n /= i;
			res.pb({i, cnt});
		}
	}
	
	return res;
}

void solve()
{
  	ll n; cin >> n;
  	
  	vpll res = prime_factors(n);
  	for(auto x: res) cout << "(" << x.F << "^" << x.S << ") ";
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

// Time Complexity: O(n)

/******************************************************************************************************/
// OPTIMIZED APPROACH than NAIVE METHOD
// MAIN IDEA: 𝑰𝒇 𝒏 𝒊𝒔 𝒂 𝒄𝒐𝒎𝒑𝒐𝒔𝒊𝒕𝒆 𝒏𝒐. 𝒕𝒉𝒆𝒏 𝒕𝒉𝒆𝒓𝒆 𝒊𝒔 𝒂𝒕 𝒍𝒆𝒂𝒔𝒕 1 𝒑𝒓𝒊𝒎𝒆 𝒅𝒊𝒗𝒊𝒔𝒐𝒓 𝒐𝒇 𝒏 𝒘𝒉𝒊𝒄𝒉 𝒊𝒔 𝒍𝒆𝒔𝒔 𝒕𝒉𝒂𝒏 𝒐𝒓 
//            𝒆𝒒𝒖𝒂𝒍 𝒕𝒐 𝒔𝒒𝒓𝒕(𝒏).

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

void solve()
{
  	ll n; cin >> n;
  	
  	vpll res = prime_factors(n);
  	for(auto x: res) cout << "(" << x.F << "^" << x.S << ") ";
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

// Time Complexity: O(sqrt(n))

/*****************************************************************************************************/

// USING SIEVE FOR "MULTIPLE QUERIES"
// Ref: https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/

/* # We can calculate the prime factorization of a number 'n' in O(sqrt(n)) as discussed above. 
     But O(sqrt n) method times out when we need to answer multiple queries regarding prime factorization.

   # Here is the efficient method to calculate the prime factorization using O(n) auxiliary space 
     (by creating a spf array) and O(log₂n) time complexity with PRECOMPUTATIONS ALLOWED. 
     The precomputation involves forming a spf with time complexity O(n x log₂(log₂n))
   
   # Key Concept used in the algorithm: ==>
     Main idea is to store the Smallest Prime Factor(spf) for every number in a spf vector. 
     Then to calculate the prime factorization of the given number by dividing the given number 
     repeatedly with its smallest prime factor till it becomes 1.
*/  

// 𝑵𝒐𝒕𝒆: 𝑻𝒉𝒆 𝒂𝒃𝒐𝒗𝒆 𝒄𝒐𝒅𝒆 𝒘𝒐𝒓𝒌𝒔 𝒘𝒆𝒍𝒍 𝒇𝒐𝒓 𝒏 𝒖𝒑𝒕𝒐 𝒕𝒉𝒆 𝒐𝒓𝒅𝒆𝒓 𝒐𝒇 10^7. 𝑩𝒆𝒚𝒐𝒏𝒅 𝒕𝒉𝒊𝒔 𝒘𝒆 𝒘𝒊𝒍𝒍 𝒇𝒂𝒄𝒆 𝒎𝒆𝒎𝒐𝒓𝒚 
//       𝒊𝒔𝒔𝒖𝒆𝒔.

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

const int N = 1e7;

// spf[i] stores the smallest prime factor for i 
vi spf;

void SPF(int n) {
	// n is the max no. for which we have to calculate the 
	// Smallest Prime Factor
	spf.clear();
	spf.resize(n + 1);
	
	// marking smallest prime factor for every number to be itself initially 
	for(int i = 0; i <= n; i++) spf[i] = i; 
	
	// separately marking spf for every even number as 2 
	for(int i = 4; i <= n; i += 2) spf[i] = 2;
	
	for(ll i = 3; i * i <= (ll)n; i += 2) {
		// checking if i is prime or not as only a prime no. can be it's own spf
		if(spf[i] == i) {
			// marking spf for all numbers divisible by i as i 
	    	for(ll j = i * i; j <= n; j += i)  {
	         	if(spf[j] == j) spf[j] = i;
	        }
	    }
	} 
}

// A O(log n) function returning primefactorization of a no. n by dividing the no. 
// by it's smallest prime factor at every step, the precomputations for this function
// have been done in the SPF() function
// It returns result in the form of ==> {prime factor, it's power}

vpll prime_factors(ll n) {
	// to store the result
	vpll res;
	
	while(n > 1) {
		ll s = spf[n];
		ll cnt = 0LL;
		while(spf[n] == s) cnt += 1, n /= s;
		res.pb({s, cnt});
	}

	return res;
}

void solve()
{
  	ll n; cin >> n;
  	
  	vpll res = prime_factors(n);
  	for(auto x: res) cout << "(" << x.F << "^" << x.S << ") ";
  	
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
    
    SPF(N);
    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}

// Time Complexity: Mentioned in the approach discussed above.