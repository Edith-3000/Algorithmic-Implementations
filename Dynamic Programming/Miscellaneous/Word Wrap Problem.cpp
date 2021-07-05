/* Ref: https://www.geeksforgeeks.org/word-wrap-problem-dp-19/
        https://www.youtube.com/watch?v=FVWAEzHSbRo
        https://www.tutorialspoint.com/Word-Wrap-Problem

   NOTE: Nice explanation given on GfG.
*/

/* Problem --->
   Given a sequence of words, and a limit on the number of characters that can be put in one line
   (line width). Put line breaks in the given sequence such that the lines are printed neatly. 
   Assume that the length of each word is smaller than the line width.
   
   The word processors like MS Word do task of placing line breaks. The idea is to have balanced 
   lines. In other words, not have few lines with lots of extra spaces and some lines with small 
   amount of extra spaces.

   The extra spaces includes spaces put at the end of every line except the last one.  
   The problem is to minimize the following total cost.
   Cost of a line = (Number of extra spaces in the line)^3
   Total Cost = Sum of costs for all lines

   For example, consider the following string and line width M = 15
   "Geeks for Geeks presents word wrap problem" 
     
   Following is the optimized arrangement of words in 3 lines
   Geeks for Geeks
   presents word
   wrap problem 

   The total extra spaces in line 1, line 2 and line 3 are 0, 2 and 3 respectively. 
   So optimal value of total cost is 0 + 2*2 + 3*3 = 13
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

// A utility function to print the solution  
int print_solution(vi &solution, int n) {
	int k;
	if(solution[n] == 1) k = 1;
	else k = print_solution(solution, solution[n] - 1) + 1;
	
	cout << "Line number " << k << ": Word number: " << solution[n] << " to " << n << "\n";
	return k;
}

// v[] represents lengths of different words in input sequence.  
// For example, v[] = {3, 2, 2, 5} is for a sentence like  
// "aaa bb cc ddddd". 
// n is size of v[] and m is line width i.e maximum #characters 
// that can fit in a line

void word_wrap(vi &v, int n, int w) {
	// extra_space[i][j] stores the #extra spaces if words from i  
    // to j are put in a single line  
	vvi extra_space(n + 1, vi(n + 1));
	
	// line_cost[i][j] will have cost which indicates cost of putting 
	// words from word number i to j in a single line, which will be 
	// calculated from extra_space array
	vvi line_cost(n + 1, vi(n + 1));
	
	// min_cost[i] will have total cost of optimal arrangement of 
	// words v[1.......i]  
	vi min_cost(n + 1);
	
	// it is used to print the solution.  
	vi solution(n + 1);
	
	for(int i = 1; i <= n; i++) {
		extra_space[i][i] = w - v[i];
		for(int j = i + 1; j <= n; j++) {
			extra_space[i][j] = extra_space[i][j-1] - v[j] - 1;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			if(extra_space[i][j] < 0) line_cost[i][j] = INF;
			else if(j == n and extra_space[i][j] >= 0) line_cost[i][j] = 0;
			else line_cost[i][j] = extra_space[i][j] * extra_space[i][j];
		}
	}
	
	min_cost[0] = 0;
	
	for(int i = 1; i <= n; i++) {
		min_cost[i] = INF;
		for(int j = 1; j <= i; j++) {
			if(min_cost[j-1] != INF and line_cost[j][i] != INF and 
			  (min_cost[j-1] + line_cost[j][i] < min_cost[i])) {
			  	// Update the answer 
				min_cost[i] = min_cost[j-1] + line_cost[j][i];
				solution[i] = j;
			}
		}
	}
	
	cout << min_cost[n] << "\n";
	print_solution(solution, n);
}

void solve()
{
  	int n, w; cin >> n >> w;
  	
  	vi v(n + 1);
  	for(int i = 1; i <= n; i++) cin >> v[i];
  	
  	word_wrap(v, n, w);
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

// Time Complexity: O(n^2) 
// Auxiliary Space: O(n^2)