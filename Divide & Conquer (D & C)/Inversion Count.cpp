// Link ---> https://www.techiedelight.com/inversion-count-array/
//           https://www.youtube.com/watch?v=kQ1mJlwW-c0

/* 
Problem description --->

You are given an array A find out number of pairs (i,j) in array A such that A[i] > A[j] and i < j.

Input Format --->
The first line consists of number of test cases t. Each test case consists of integer N followed by N space
separated integers.

Constraints --->
1 <= N <= 100000 
1 <= t <= 20 
0 <= A[i] <= 100000000

Output Format --->
The number of inversions in array

Sample Input --->
2
4
1 2 4 3
3
3 2 1

Sample Output ---> 
1
3

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

// Pass the vector v[] by reference
ll merge_procedure(vi &v, int start, int end, int n) {
	// temporary vector to store the sorted result 
	vi tmp(n);
	int mid = start + (end - start)/2;
	
	// i = iterator for the first half
	// j = iterator for the second half
	// k = iterator fot the tmp[] vector
	int i = start, j = mid + 1, k = start;
	
	// to store the #cross inversion pairs
	ll cnt = 0; 
		
	while(i <= mid && j <= end) {
		if(v[i] <= v[j]) tmp[k++] = v[i++];
		else {
			cnt += (mid - i + 1);
			tmp[k++] = v[j++];
		}
	}
	
	// fill the array if some of the elements are still left
	while(i <= mid) tmp[k++] = v[i++];
	while(j <= end)	tmp[k++] = v[j++];
	
	// copying back the sorted elements of the 2 parts
	// in the original array
	for(int x = start; x <= end; x++) v[x] = tmp[x];
	
	return cnt;
}

// function which will give the #inversion pairs in the range [start, end]
ll inversion_count(vi &v, int start, int end, int n) {
	// base case
	if(start >= end) return 0;
	
	int mid = start + (end - start)/2;
	
	// function which will give the #inversion pairs in the range [start, mid]
	ll left = inversion_count(v, start, mid, n);
	
	// function which will give the #inversion pairs in the range [mid + 1, end]
	ll right = inversion_count(v, mid + 1, end, n);
	
	// function which will give the #cross inversion b/w the left and right subpart
	// Remember: sorting won't affect the #cross inversions as the relative ordering 
	//           of elements in left & right subpart will stay the same
	ll cross_cnt = merge_procedure(v, start, end, n);
	
	// return the total #inversions
	return left + right + cross_cnt;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << inversion_count(v, 0, n - 1, n) << "\n";
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
    cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}

// Time complexity: O(n x log2(n)) [same as that of Merge Sort Algo]
// Space complexity: O(n)