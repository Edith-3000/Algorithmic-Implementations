/* Link: https://www.techiedelight.com/longest-increasing-subsequence-using-dynamic-programming/

   PROBLEM: The Longest Increasing Subsequence (LIS) problem is to find the length of the longest 
            subsequence of a given sequence such that all elements of the subsequence are sorted in 
            increasing order(i.e. monotically increasing subsequence). 
            For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and 
                         LIS is {10, 22, 33, 50, 60, 80}.
*/

// NOTE: IN THE BELOW ALGORITHMS ELEMENTS IN THE LIS ARE STRICTLY INCREASING.
/****************************************************************************************************/

// RECURSIVE IMPLEMENTATION 

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

int len_LIS(vi &v, int n, int prev) {
	// base case
	if(n == 0) return 0;
	
	// choice diagram code
	// for each element of v[], we have 2 choices ==>
	// Choice 1: exclude the current element and process the remaining elements
	// Choice 2: include the current element if it is smaller than prev element in LIS
	
	int exclude = len_LIS(v, n - 1, prev);
	
	int include = 0;
	if(v[n-1] < prev) include = 1 + len_LIS(v, n - 1, v[n-1]);
	
	// return maximum of above two choices
	return max(exclude, include);
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << len_LIS(v, n, INT_MAX) << "\n";
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

/* # prev is initialised with INT_MAX in the main() fⁿ
   # Time Complexity: The time complexity of this recursive approach is exponential (O(2ⁿ)) as there 
                      is a case of overlapping subproblems.
   # Auxiliary Space: O(1). No external space used for storing values apart from the internal 
                            stack space.
*/

/****************************************************************************************************/

// TABULATION IMPLEMENTATION (Real DP ;)) O(n^2)

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

// dp[i] = LIS length ending at index i of the vector v[]
vi dp;

int len_LIS(vi &v, int n) {
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
	
	int res = dp[0];
	for(int i = 1; i < n; i++) res = max(res, dp[i]);
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << len_LIS(v, n) << "\n";
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

/* # dp[] is a 1 D global matrix or vector of size (n) to store sub-problem solution.
     dp[i] for each 0 <= i <= (n-1) stores the length of the longest increasing subsequence 
     of subarray/subvector v[0...i] 𝙬𝙝𝙞𝙘𝙝 𝙚𝙣𝙙𝙨 𝙬𝙞𝙩𝙝 𝙫[𝙞].
 
   # Time Complexity: O(n^2)
   # Auxiliary Space: O(n)
*/ 

/*******************************************************************************************************/

// NON DP IMPLEMENTATION (O(n x log₂(n)))

/*Underlying concept: 
  # Let s[] be a vector & s[i] be defined as the smallest integer that ends an increasing sequence of 
    length (i+1). Now iterate through every integer of the input set v[] and do the following: --->
    ● If x is more than the last element in s, then append x to the end of s. This essentially means we 
      have found a new largest LIS.
    ● Otherwise find the smallest element in s, which is more than or equal to x, and replace it with x.
      Because s is sorted at any time, the element can be found using binary search in log₂(n)time.
  # Let’s illustrate this with the help of an example. Consider below array of integers –>
    {2, 6, 3, 4, 1, 2, 9, 5, 8}
    Below are the steps followed by the algorithm –
    Initialize to an empty set S = {}
    Inserting 2 —- S = {2} – New largest LIS
    Inserting 6 —- S = {2, 6} – New largest LIS
    Inserting 3 —- S = {2, 3} – Replaced 6 with 3
    Inserting 4 —- S = {2, 3, 4} – New largest LIS
    Inserting 1 —- S = {1, 3, 4} – Replaced 2 with 1
    Inserting 2 —- S = {1, 2, 4} – Replaced 3 with 2
    Inserting 9 —- S = {1, 2, 4, 9} – New largest LIS
    Inserting 5 —- S = {1, 2, 4, 5} – Replaced 9 with 5
    Inserting 8 —- S = {1, 2, 4, 5, 8} – New largest LIS

    So, the length of the LIS is 5 (the size of s[]). Please note that here s[i] is defined as the 
    smallest integer that ends an increasing sequence of length (i+1). Therefore, S does not represent 
    an actual sequence but the size of s[] represents the length of the LIS.
*/

/*Some extra points ----->
  Q. Difference between front(), back() and begin(), end() function for std::vector ?
  A. begin() and end() function return an iterator(like a pointer) initialized to the first or 
     the last element of the container that can be used to iterate through the collection, while 
     front() and back() function just return a reference to the first or the last element of the 
     container.
*/

long long lisLength(vector<long long> &v)
{
    //size of i/p array
	long long n=v.size();
    
    //when i/p is empty
    if(n==0) 
       return 0;

	vector<long long> s;
	s.push_back(v[0]);

	for(long long i=1; i<n; i++)
	{
	   if(s.back()<v[i])
	      s.push_back(v[i]);

	   else
	   {
	      //here lower_bound works exactly same as binary_search
	      long long index= lower_bound(s.begin(), s.end(), v[i]) - s.begin();
	      s[index]=v[i];
	   }
	}

	return s.size();
}

/* # Time Complexity: O(n*log₂(n)) [assuming we need to perform binary search for each element].
   # Space Complexity(worst case): O(n).
           Worst case: when v[] is already sorted in increasing order i.e. v[] itself as a whole
                       is the LIS.
*/

****************************************************************************************************************

//IMPLEMENTATION BY MAKING USE OF LCS CONCEPT

# LIS can be reduced to LCS. All we need to do is sort the copy of the original sequence, remove all 
  the duplicates and do LCS of them. In pseudocode it is:
  
  LIS(s):
     t = sort(s)
     t = removeDuplicates(t)
     return LCS(s, t)