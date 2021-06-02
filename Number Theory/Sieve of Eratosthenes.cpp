/* Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment [1;n] 
   using O(n*log₂(log₂n) operations.
   Sieve of eratosthenes is primarily used when there are multiple queries asked to check primality 
   of given nos.
   Multiple of a prime no. cannot be a prime no.
*/

/***************************************************************************************************/

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

vi is_prime;

void SOE(int n) {
	// n is the max no. for which we have to check primality
	is_prime.clear();
	is_prime.resize(n + 1, 0); 
	
	// all odd nos. are potential prime numbers
	for(int i = 3; i <= n; i += 2) is_prime[i] = 1; 
	
	// 2 is a prime number
	is_prime[2] = 1; 

	for(ll i = 3; i * i <= (ll)n; i += 2) {
		// if the current element i is prime
		if(is_prime[i]) {
	    	for(ll j = i * i; j <= n; j += i)  {
	        	// marking all the proper multiples of 
	         	// the current prime i as non primes
	         	is_prime[j] = 0;
	        }
	    }
	} 
}

void solve()
{
  	int n; cin >> n;
  	SOE(n);
  	for(int i = 0; i <= n; i++) cout << is_prime[i] << "\n";
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

// CAUTION: 𝑨𝒍𝒘𝒂𝒚𝒔 𝒖𝒔𝒆 𝒕𝒉𝒆 𝒅𝒂𝒕𝒂 𝒕𝒚𝒑𝒆 𝒐𝒇 𝒗 𝒂𝒔 𝒃𝒐𝒐𝒍/𝒃𝒊𝒕𝒔𝒆𝒕 𝒊𝒇 𝒕𝒊𝒎𝒆 𝒄𝒐𝒏𝒔𝒕𝒓𝒂𝒊𝒏𝒕 𝒊𝒔 𝒗𝒆𝒓𝒚 𝒍𝒆𝒔𝒔 𝒊𝒏 𝒕𝒉𝒆 𝒑𝒓𝒐𝒃𝒍𝒆𝒎 
//          𝒔𝒕𝒂𝒕𝒆𝒎𝒆𝒏𝒕.

// Limitation of Sieve: Only numbers upto 10⁷ can be stored in the sieve.

// Time complexity analysis: Preprocessing time - O(n x log₂(log₂n))
//                           Answers a single query in: O(1)
//                           Auxiliary space: O(n)