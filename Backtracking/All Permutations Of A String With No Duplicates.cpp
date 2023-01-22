// Problem: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
//          https://leetcode.com/problems/permutations/

/***************************************************************************************************************************************************************/

// NOTE: The below solutions prints duplicate permutations if there are repeating characters in input string.

/***************************************************************************************************************************************************************/

// METHOD - 1
// https://www.youtube.com/watch?v=YK78FU5Ffjw

/***************************************************************************************************************************************************************/

// METHOD - 2
// Ref: https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0rQ6cnlaHRMuOp4H_D-7hwP&index=8

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

// here string must be passed by reference
void permute(int i, string &s, vs &res) {
	// base case
	if(i == sz(s)) {
		res.pb(s);
		return;
	}
	
	for(int j = i; j < sz(s); j++) {
		// swapping done 
		swap(s[i], s[j]);

		// recurse for smaller subproblem
		permute(i+1, s, res);

		// as string is passed by reference therefore in 
		// the returning phase again place back the swapped
		// chars at their original position
		// i.e. while backtracking we are restoring the 
		// original string
		swap(s[i], s[j]);
	}
}

void solve()
{
  	string s; cin >> s;
    
    vs res;
    permute(0, s, res);
    
    for(auto x: res) cout << x << "\n";
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

/* # Time Complexity: O(n * n!) 
     As there are n! permutations and it requires O(n) time to print a a permutation.
   # Note : The above solution prints duplicate permutations if there are repeating characters in input string. 
   # Refer: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/

/* 
Sample i/p:

abc

Sample o/p:

Enter string: abc
abc
acb
bac
bca
cba
cab

*/

/***************************************************************************************************************************************************************/

// CODE TO GENERATE ONLY UNIQUE PERMUTATION AND ALSO IN LEXOGRAPHICALLY SORTED ORDER

// Just make use of a set to store the result

/***************************************************************************************************************************************************************/

// METHOD - 3

// USING C++ STL FUNCTION (next_permutation())

#include<bits/stdc++.h>
using namespace std;

void permute(string s) {
	// sort the string in lexicographically
    // ascennding order
	sort(s.begin(), s.end());
	
	// keep printing next permutation while there
    // is next permutation
	do{
		cout << s << "\n";
	} while(next_permutation(s.begin(), s.end()));
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter string: ";
    string s; cin >> s;
    cout << s<<"\n";
    
    permute(s);
    
    return 0;
}

// Time complexity: O(n * n!)
// As there are n! permutations and next_permutation() requires O(n) time to find lexicographically
// next permutation