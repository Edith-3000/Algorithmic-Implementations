/* Prob.: Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may 
          exist one celebrity. 
          The definition of a celebrity is that all the other (n - 1) people know him/her but he/she 
          does not know any of them.
          Now you want to find out who the celebrity is or verify that there is not one. 
          The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get 
          information whether A knows B. 
          You need to find out the celebrity (or verify there is not one) by asking as few questions 
          as possible (in the asymptotic sense).
          
          You are given a 2 D matrix, v[][] of size (n x n), v[i][j] = 0 if i doesn't know j and 
          v[i][j] = 1, if i knows j.
          
          # Note: There will be exactly one celebrity if he/she is in the party. 
                  Return the celebrity's label if there is a celebrity in the party. 
                  If there is no celebrity, return -1. 
*/

/*UNDERLYING CONCEPT ------->
  # So basically, celebrity is the person who is: • known by everyone
  												                        • knows nobody.
  # Ref: https://www.youtube.com/watch?v=CiiXBvrX-5A
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

int find_celebrity(vvi &v) {
	int n = sz(v);
	if(n == 0) return -1;
	
	stack<int> st;
	
	// pushing all the persons in the stack
	for(int i = 0; i < n; i++) st.push(i);

	while(sz(st) >= 2) {
		// taking out 2 persons at a time
		int i = st.top(); st.pop();
		int j = st.top(); st.pop();

		// if i knows j, then it implies i can't be a celebrity
		// therefore pushed back j
		if(v[i][j]) st.push(j);

		// if i does not knows j, then it implies j can't be a celebrity
		// therefore pushed back i
		else st.push(i);
	}

    // stack top can be the potential celebrity but not guaranteed
	int candidate = st.top();

	for(int i = 0; i < n; i++) {
		if(i != candidate) {
			if(v[i][candidate] == 0 or v[candidate][i] == 1) return -1;
		}
	}

	return candidate;
}

void solve()
{
  	int n; cin >> n;
  	vvi v(n, vi(n, 0));
  	
  	for(int i = 0; i < n; i++) {
  		for(int j = 0; j < n; j++) cin >> v[i][j];
  	}
  	
  	cout << find_celebrity(v) << "\n";
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
// Space Complexity: O(n), where 'n' are the total #peope in the party.											 