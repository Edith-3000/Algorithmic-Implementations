// Ref: https://www.youtube.com/watch?v=if40LxQ8_Xo&list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f&index=7&ab_channel=Pepcoding
//      https://www.youtube.com/watch?v=kdO5Q0nmPjU&list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f&index=7&ab_channel=Pepcoding

/***************************************************************************************************************************************************************/

/* 
   # IT IS A DIVIDE & CONQUER SORTING ALGORITHM.
   # It's average case TC is O(n x log2(n)), while worst case TC is O(n^2), which can be fixed using Randomized Quick Sort
*/

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

// function to partition v[lo, hi] such that all element <= pivot_element lie on one side
// and all elements > pivot_element lie on other side, also it returns the position of pivot_element, 
// had v[] been sorted
// ref: https://www.youtube.com/watch?v=if40LxQ8_Xo&list=PL-Jc9J83PIiFc7hJ5eeCb579PS8p-en4f&index=7&ab_channel=Pepcoding
int partition(int lo, int hi, int pivot_element, vi &v) {
	// base case
	if(lo > hi) return INT_MAX;
	
	// dividing v[lo, hi] into 3 regions as follows ===>
	// v[lo, i - 1] = contains all elements <=  pivot_element
	// v[i, j - 1] = contains all elements >  pivot_element
	// v[j, hi] = contains all unexplored elements
	int i = lo, j = lo;
	
	while(j <= hi) {
		if(v[j] <= pivot_element) {
			swap(v[i], v[j]);
			i += 1;
			j += 1;	
		}
		
		else j += 1;
	}
	
	return (i - 1);
}

void quick_sort(int lo, int hi, vi &v) {
	// base case
	if(lo >= hi) return;
	
	// passing v[hi] as the pivot element
	int pivot_idx = partition(lo, hi, v[hi], v);
	
	// recursively sort the left subpart and right subpart, after placing the pivot_element
	// at it's correct position
	quick_sort(lo, pivot_idx - 1, v);
	quick_sort(pivot_idx + 1, hi, v);
	
	return;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	quick_sort(0, n - 1, v);
  	
  	for(int i = 0; i < n; i++) {
  		cout << v[i] << " ";
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