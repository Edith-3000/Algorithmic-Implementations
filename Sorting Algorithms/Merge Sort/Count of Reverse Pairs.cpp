// Prob: https://leetcode.com/problems/reverse-pairs/
// Ref: https://takeuforward.org/data-structure/count-reverse-pairs/
/**************************************************************************************************************/

// Main idea is to just do some twist and tweaks in the Merge Sort Algorithm.

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

void merge_procedure(vi &v, int start, int end, int n) {
	// temporary vector to store the sorted result 
	vi tmp(end - start + 1);
	int mid = start + (end - start)/2;
	
	// i = iterator for the first half
	// j = iterator for the second half
	// k = iterator fot the tmp[] vector
	int i = start, j = mid + 1, k = 0;
			
	while(i <= mid && j <= end) {
		if(v[i] <= v[j]) tmp[k++] = v[i++];
		else tmp[k++] = v[j++];
	}
	
	// fill the array if some of the elements are still left
	while(i <= mid) tmp[k++] = v[i++];
	while(j <= end)	tmp[k++] = v[j++];
	
	// copying back the sorted elements of the 2 parts
	// in the original array
	for(int x = start; x <= end; x++) v[x] = tmp[x - start];
}

int find_cross_count(vi &v, int start, int end, int n) {
    int mid = start + (end - start)/2;
    int i = start, j = mid + 1, cnt = 0;
    
    // for a particular 'i' increment 'j' as long as v[i] > (2 * v[j]), & if 
    // it's not add to cnt
    while(i <= mid and j <= end) {
        if((ll)v[i] > (2 * (ll)v[j])) j++;
        else {
            cnt += (j  - 1 - mid);
            i++;
        }
    }
        
    while(i <= mid) {
        cnt += (j - 1 - mid); 
        i++;
    }
        
    return cnt;
}

// Function similar to merge sort
int helper(vi &v, int start, int end, int n) {
	// base case
	if(start >= end) return 0;
	
	int mid = start + (end - start)/2;
	
	// function which will give the #reverse pairs in the range [start, mid]
	int left = helper(v, start, mid, n);
	
	// function which will give the #reverse pairs in the range [mid + 1, end]
	int right = helper(v, mid + 1, end, n);
	
	// function which will give the #cross reverse pairs b/w the left and right subpart
	// Remember: sorting won't affect the #cross reverse pairs as the relative ordering 
	//           of elements in left & right subpart will stay the same
	int cross_cnt = find_cross_count(v, start, end, n);
	
	// merging the left and right subparts
	merge_procedure(v, start, end, n);
	
	// return the total #inversions
	return left + right + cross_cnt;
}

// Function to count all reverse pairs in v[].
// A reverse pair is a pair (i, j) where 0 <= i < j < v.length and v[i] > 2 * v[j].
int count_reverse_pairs(vi &v) {
	int n = sz(v);
	if(n == 0) return 0;
	
	return helper(v, 0, n - 1, n);
}

void solve()
{
  	int n; cin >> n; 
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	int res = count_reverse_pairs(v);
  	cout << res << "\n";
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