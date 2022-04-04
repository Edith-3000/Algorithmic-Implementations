// Explanation: https://www.youtube.com/watch?v=ws98ud9uxl4
//              https://www.youtube.com/watch?v=LPFhl65R7ww
//              https://takeuforward.org/data-structure/median-of-two-sorted-arrays-of-different-sizes/
//              https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/share-my-ologminmn-solution-with-explanation

// Problem: https://www.interviewbit.com/problems/median-of-array/
//          https://leetcode.com/problems/median-of-two-sorted-arrays/
/****************************************************************************************************/

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

double find_median(vi &v1, vi &v2) {
	int n = sz(v1);
	int m = sz(v2);
	
	// Ensuring that v1.length() <= v2.length()
	if(n > m) return find_median(v2, v1);
	
	// In left half of the the merged array of v1[] and v2[], v1[] can contribute
	// #elements ranging from [0, n], that's why lo & hi are taken like this.
	int lo = 0, hi = n;
		
	while(lo <= hi) {
		int partition1 = lo + ((hi - lo) >> 1);
		int partition2 = (n + m + 1) / 2 - partition1;
		
		int max1 = (partition1 == 0) ? INT_MIN : v1[partition1 - 1];
		int min1 = (partition1 == n) ? INT_MAX : v1[partition1];
		
		int max2 = (partition2 == 0) ? INT_MIN : v2[partition2 - 1];
		int min2 = (partition2 == m) ? INT_MAX : v2[partition2];
			
		if((max1 <= min2) and (max2 <= min1)) {
			if((n + m) % 2 == 0) {
				return ((double)max(max1, max2) + min(min1, min2)) / 2.0;
			}
				
			else return (double)max(max1, max2);
		}
			
		else if(max1 > min2) hi = partition1 - 1;
		else lo = partition1 + 1;
	} 
	
	// Only we we can come here is if input arrays were not sorted.
	return 0.0; 
}

void solve()
{
  	int n, m; cin >> n >> m;
  	vi v1(n), v2(m);
  	
  	for(int i = 0; i < n; i++) cin >> v1[i];
  	for(int i = 0; i < m; i++) cin >> v2[i];
  	
  	cout << find_median(v1, v2);
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

// Time complexity: O(log(min(m,n))
// Space complexity: O(1)

/***************************************************************************************************/

// LEGACY CONTENT - https://pastebin.com/aYxS7gRP