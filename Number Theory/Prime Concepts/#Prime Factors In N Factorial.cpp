/* # Problem based on this concept --->
     https://codeforces.com/problemset/problem/546/D

   # Counting prime factors for a single number is easy, you can refer here --->
     https://www.geeksforgeeks.org/no-factors-n/
   
   # But the task becomes complicated when there are a #queries, so this can be achieved by some 
     precomputations and prefix sum technique. Refer the algorithm below --->
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

const int N = 100000;

// cnt[i] = #primes factors in i!
vll cnt;

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

// A O(log n) function returning #prime factors of a no. n by dividing the no. 
// by it's smallest prime factor at every step, the precomputations for this function
// have been done in the SPF() function
ll prime_factors(ll n) {
	// to store the result
	ll res = 0LL;
	
	while(n > 1) {
		ll s = spf[n];
		ll cnt = 0LL;
		while(spf[n] == s) cnt += 1, n /= s;
		res += cnt;
	}

	return res;
}

// Function to calculate the #prime factors in the factorials of all
// numbers from [1 to n]
void cnt_primes_in_factorial(int n) {
	// firstly calculate the SPF for every number
	SPF(n);
	
	cnt.clear();
	cnt.resize(n + 1, 0LL);
	
	// now compute #prime factors for every number
	for(int i = 2; i <= n; i++) {
		cnt[i] = prime_factors(i);
	}
	
	// for calculating #prime factors in i!, just do a cumulative sum
	// of the #prime factors of all nos. from (2 to i)
	for(int i = 3; i <= n; i++) cnt[i] += cnt[i-1];
}

void solve()
{
  	int q; cin >> q;

  	while(q--) {
  		ll n; cin >> n;
  		cout << "#prime factors in " << n << "! = ";
  		cout << cnt[n] << "\n";
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
    
    // doing precomputations
    cnt_primes_in_factorial(100000);
    
    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}