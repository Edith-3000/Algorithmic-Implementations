/* PROBLEM STATEMENT: There is a dictionary containing words from an alien language for which we don’t
                      know the ordering of the characters. Write a method to find the correct order of 
                      characters in the alien language.

                      NOTE: The words are sorted lexicographically by the rules of the alien language
                            as it is given that a dictionary is containing the words.

                      Input: Words: ["cab", "aaa", "aab"]
					  Output: cab

					  Explanation: From the given words we can conclude the following ordering among 
					  its characters:
						 
					  1. From "cab" and "aaa", we can conclude that 'c' comes before 'a'.
					  2. From "aaa" and "aab", we can conclude that 'a' comes before 'b'
						 
					  From the above two points, we can conclude that the correct character order is: "cab"

  Prob Links: https://www.educative.io/courses/grokking-the-coding-interview/R8AJWOMxw2q
              https://leetcode.com/problems/alien-dictionary/
		      https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
			  https://practice.geeksforgeeks.org/problems/alien-dictionary/1
*/

/* UNDERLYING CONCEPT ------>

   # Since the given words are sorted lexicographically by the rules of the alien language, we can 
     always compare two adjacent words to determine the ordering of the characters. 

   1. Take the first two words for eg. “ba” and “bc”. Starting from the beginning of the words, find the first 
      character that is different in both words: it would be ‘a’ from “ba” and ‘c’ from “bc”. Because of 
      the sorted order of words (i.e. the dictionary!), we can conclude that ‘a’ comes before ‘c’ in the 
      alien language.

   2. Similarly, from “bc” and “ac”, we can conclude that ‘b’ comes before ‘a’.

   # These two points tell us that we are actually asked to find the topological ordering of the characters, 
     and that the ordering rules should be inferred from adjacent words from the alien dictionary.

   # This makes the current problem similar to Tasks Scheduling Order, the only difference being that we need 
     to build the graph of the characters by comparing adjacent words first, and then perform the topological 
     sort for the graph to determine the order of the characters.
*/

/****************************************************************************************************************/

// LEGACY CONTENT: https://pastebin.com/YLErydMh

/****************************************************************************************************************/

// METHOD - 1 (USING std::map to represent graph)

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

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// stores the input graph
map<char, vector<char>> g;

// to store the indegree of vertices
map<char, int> indegree;

int n;

// function which returns topological ordering of the graph
string top_sort() {
    // to process nodes one by one
    queue<char> q;
    
    // find all sources i.e., all vertices with 0 in-degrees
    for(auto x: indegree) {
        if(x.S == 0) q.push(x.F); 
    }
    
    // to store the topological ordering
    string res = "";
    
    while(!q.empty()) {
        char cur = q.front();
        q.pop();
        res.pb(cur);
        
        for(auto x: g[cur]) {
            indegree[x] -= 1;
            if(indegree[x] == 0) q.push(x);
        }   
    }
    
    // topological sort is not possible if the graph has a cycle
    if(sz(res) != n) res.clear();
    
    return res;
}

string alien_dictionary(vs &v) {
	if(sz(v) == 0) return "";
		
	for(auto str: v) {
		for(auto ch: str) {
			g[ch] = vector<char>();
			indegree[ch] = 0;
		}
	}
	
	n = sz(g);
	
	for(int i = 0; i + 1 < sz(v); i++) {
		for(int j = 0; j < min(sz(v[i]), sz(v[i + 1])); j++) {
			char x = v[i][j], y = v[i + 1][j];
			
			if(x == y) continue;
			
			g[x].pb(y);
			indegree[y] += 1;
			
			break;
		}
	}
	
	string res = top_sort();
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vs v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	string res = alien_dictionary(v);
  	
  	if(sz(res) == 0) cout << "Either input empty or invalid input.\n";
  	else cout << res << "\n";
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
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}

/* Time Complexity ---->

   # The time complexity of the above algorithm will be O(V+E), where ‘V’ is the total number of different
     characters and ‘E’ is the total number of the rules in the alien language. 
   # ∵ at most, each pair of words can give us one rule, therefore, we can conclude that the upper bound for   
     the rules is O(N) where ‘N’ is the number of words in the input. 
   # So, the time complexity of our algorithm is O(V+N).

   Space Complexity ----->

   # The space complexity will be O(V+N), ∵ we are storing all of the rules for each character in an 
     adjacency list.
*/

/*****************************************************************************************************************/

// METHOD - 2 (USING std::vector<vector> to represent graph)

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

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

// stores the input graph
vvi g;

// to store the indegree of vertices
vi indegree;

int n;

// function which returns topological ordering of the graph
vi top_sort() {
    // to process nodes one by one
    queue<int> q;
    
    // find all sources i.e., all vertices with 0 in-degrees
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i); 
    }
    
    // to store the topological ordering
    vi res;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        res.pb(cur);
        
        for(auto x: g[cur]) {
            indegree[x] -= 1;
            if(indegree[x] == 0) q.push(x);
        }   
    }
    
    // topological sort is not possible if the graph has a cycle
    if(sz(res) != n) res.clear();
    
    return res;
}

string alien_dictionary(vs &v) {
	if(sz(v) == 0) return "";
	
	map<char, int> id;
	map<int, char> rid;
	
	for(auto str: v) {
		for(auto ch: str) {
			id[ch] = -1;
		}
	}
	
	int num = 0;
	
	// CAUTION: x must be used with "&" in order to change something
	for(auto &x: id) {
		x.S = num;
		rid[num] = x.F;
		num += 1;
	}
	
	n = sz(id);
	
	g.clear(); g.resize(n);
	indegree.clear(); indegree.resize(n, 0);
	
	for(int i = 0; i + 1 < sz(v); i++) {
		for(int j = 0; j < min(sz(v[i]), sz(v[i + 1])); j++) {
			int x = id[v[i][j]], y = id[v[i + 1][j]];
			
			if(x == y) continue;
			
			g[x].pb(y);
			indegree[y] += 1;
			
			break;
		}
	}
	
	vi ordering = top_sort();
	
	if(sz(ordering) == 0) return "";
	
	string res = "";
	
	for(int i = 0; i < n; i++) {
		res.pb(rid[ordering[i]]);
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vs v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	string res = alien_dictionary(v);
  	
  	if(sz(res) == 0) cout << "Either input empty or invalid input.\n";
  	else cout << res << "\n";
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
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}