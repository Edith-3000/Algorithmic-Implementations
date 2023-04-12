// Prob: https://leetcode.com/problems/minimum-reverse-operations/description/

// Ref: https://www.youtube.com/watch?v=UbeM9YI4Mlg&t=1817s&ab_channel=codingMohan

/******************************************************************************************************************************************************************/

// METHOD - 1 [O(n x k)]

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

vi min_reverse_operations(int n, int p, vi &banned, int k) {
	vi res(n, -1);
	res[p] = 0;
	
	if(k == 1) return res;
	
	// Modified version of BFS
	
	vi vis(n, 0);
	vis[p] = 1;
	
	// Since we don't want to process banned indices, we make them visited at the start
	for(auto x: banned) {
		vis[x] = 1;
	}
	
	queue<int> q;
	q.push(p);
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		// first_L = start index of the first subarray of size k, of which 'cur' is a part of
		// first_R = end index of the first subarray of size k, of which 'cur' is a part of
		// L = index at which the '1' at cur will go if we reverse the subarray from [first_L, first_R]
		int first_L = max(0, cur - k + 1);
		int first_R = first_L + k - 1;
		int L = first_L + (first_R - cur);
		
		// last_L = start index of the last subarray of size k, of which 'cur' is a part of
		// last_R = end index of the last subarray of size k, of which 'cur' is a part of
		// R = index at which the '1' at cur will go if we reverse the subarray from [last_L, last_R]
		int last_R = min(n - 1, cur + k - 1);
		int last_L = last_R - k + 1;
		int R = last_L + (last_R - cur);
		
		// exploring all the neighbours of node 'cur'
		for(int nbr = L; nbr <= R; nbr += 2) {
			if(vis[nbr]) continue;
			
			vis[nbr] = 1;
			q.push(nbr);
			
			res[nbr] = res[cur] + 1;
		}
	}
	
	return res;
}

void solve()
{
  	int n, p, k;
  	cin >> n >> p >> k;
  	
  	int m; cin >> m;
  	vi banned(m);
  	
  	for(int i = 0; i < m; i++) {
  		cin >> banned[i];
  	}
  	
  	vi res = min_reverse_operations(n, p, banned, k);
  	
  	for(auto x: res) {
  		cout << x << " ";
  	}
  	
  	cout << "\n";
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

/******************************************************************************************************************************************************************/

// METHOD - 2 [O(n x log₂(n))]

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

vi min_reverse_operations(int n, int p, vi &banned, int k) {
	vi res(n, -1);
	res[p] = 0;
	
	if(k == 1) return res;
	
	// Modified version of BFS
	
	// to store the nodes which are unvisited
	set<int> unvisited_odd_node, unvisited_even_node;
	
	for(int i = 0; i < n; i++) {
		if(i == p) continue;
		
		if(i & 1) unvisited_odd_node.insert(i);
		else unvisited_even_node.insert(i);
	}
	
	// Since we don't want to process banned indices, we make them visited at the start
	for(auto x: banned) {
		if(x & 1) unvisited_odd_node.erase(x);
		else unvisited_even_node.erase(x);
	}
	
	queue<int> q;
	q.push(p);
	
	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		
		// first_L = start index of the first subarray of size k, of which 'cur' is a part of
		// first_R = end index of the first subarray of size k, of which 'cur' is a part of
		// L = index at which the '1' at cur will go if we reverse the subarray from [first_L, first_R]
		int first_L = max(0, cur - k + 1);
		int first_R = first_L + k - 1;
		int L = first_L + (first_R - cur);
		
		// last_L = start index of the last subarray of size k, of which 'cur' is a part of
		// last_R = end index of the last subarray of size k, of which 'cur' is a part of
		// R = index at which the '1' at cur will go if we reverse the subarray from [last_L, last_R]
		int last_R = min(n - 1, cur + k - 1);
		int last_L = last_R - k + 1;
		int R = last_L + (last_R - cur);
		
		// Exploring all the neighbours of node 'cur'
		
		// if L is odd, then all neighbours of x will be also be odd (since they are alternating)
		if(L & 1) {
			// To store the neighbours which should be marked as visited
			vi to_be_erased;
			
			for(
				auto it = unvisited_odd_node.lower_bound(L);
				(it != unvisited_odd_node.end()) and (*it <= R);
				it++
			) {
				to_be_erased.pb(*it);
				q.push(*it);
				res[*it] = res[cur] + 1;
			}
			
			for(auto nbr: to_be_erased) {
				unvisited_odd_node.erase(nbr);
			}
		}
		
		// if L is even, then all neighbours of x will be also be even (since they are alternating)
		else {
			// To store the neighbours which should be marked as visited
			vi to_be_erased;
			
			for(
				auto it = unvisited_even_node.lower_bound(L);
				(it != unvisited_even_node.end()) and (*it <= R);
				it++
			) {
				to_be_erased.pb(*it);
				q.push(*it);
				res[*it] = res[cur] + 1;
			}
			
			for(auto nbr: to_be_erased) {
				unvisited_even_node.erase(nbr);
			}
		}
	}
	
	return res;
}

void solve()
{
  	int n, p, k;
  	cin >> n >> p >> k;
  	
  	int m; cin >> m;
  	vi banned(m);
  	
  	for(int i = 0; i < m; i++) {
  		cin >> banned[i];
  	}
  	
  	vi res = min_reverse_operations(n, p, banned, k);
  	
  	for(auto x: res) {
  		cout << x << " ";
  	}
  	
  	cout << "\n";
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