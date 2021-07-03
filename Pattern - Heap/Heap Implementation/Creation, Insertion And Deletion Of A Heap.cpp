// Ref: https://www.udemy.com/course/datastructurescncpp/
/********************************************************************************************************/

// In the below algorithm operations for binary max heap have been implemented, binary min heap can also
// be created similarly.

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

// it is the position where the last element in the heap is present
int pos;

int delete_heap(vi &v) {
	if(pos == -1) {
		cout << "Heap empty! ";
		return INT_MAX;
	}
	
	int x = v[0];
	v[0] = v[pos];
	pos -= 1;
	
	// i => to store the index of parent
	// j => to store the index of left child of i
	int i = 0, j = 1;	
	
	while(j <= pos) {
		// compare the left and right childs of i
		if(j + 1 <= pos and v[j+1] > v[j]) j += 1;
		
		// compare the parent i, with the max(left child, right child)
		if(v[j] > v[i]) {
			swap(v[j], v[i]);
			i = j;
			j = 2 * i + 1;
		}
		
		else break;
	}
	
	return x;
}

// insertion is being done in-place
void insert_heap(vi &v, int n) {
	int tmp = v[n], i = n;
	
	// the parent index can also be found by ceil(i/2) - 1
	while(i > 0 and v[(i % 2 == 0) ? (i / 2 - 1) : (i / 2)] < tmp) {
		v[i] = v[(i % 2 == 0) ? (i / 2 - 1) : (i / 2)];
        i = (i % 2 == 0) ? (i / 2 - 1) : (i / 2);
	}
	
	v[i] = tmp;
}

void create_heap(vi &v) {
	int n = sz(v);
	
	for(int i = 0; i < n; i++) {
		insert_heap(v, i);
	}
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	pos = -1;
  	create_heap(v);
  	pos = n - 1;
  
  	cout << delete_heap(v) << "\n";
  	cout << delete_heap(v) << "\n";
  	cout << delete_heap(v) << "\n";
  	cout << delete_heap(v) << "\n";
  	cout << delete_heap(v) << "\n";
  	cout << delete_heap(v) << "\n";
  	cout << delete_heap(v) << "\n";
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