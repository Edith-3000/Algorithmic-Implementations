// Ref: https://www.youtube.com/playlist?list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28
//      https://www.codingninjas.com/codestudio/library/implementation-of-heap
/*************************************************************************************************************/

// LEGACY CONTENT: https://pastebin.com/zv54FRTs

/*************************************************************************************************************/

// In the below algorithm operations for binary max heap have been implemented, binary min heap can also
// be created similarly.

/*************************************************************************************************************/

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

// NOTE: 0-based indexing is followed
class MaxHeap {
	private:
		// data members ===>
		
		// maximum #elements that can be placed in the heap
		int max_size;
	
		// size of heap at any given point of time
		int heap_size;
	
		// underlying vector[] used to store heap elements
		vi v;
		
		// member functions ===>
		
		// returns the index of left child of idx
		int left(int idx) {
			return (2 * idx + 1);
		}
		
		// returns the index of right child of idx
		int right(int idx) {
			return (2 * idx + 2);
		}
		
		// returns the index of parent of idx = ceil(idx / 2) - 1
		int parent(int idx) {
			return (idx + 1) / 2 - 1;
		}
		
		// to heapify the subtree root at index i in v[] (RECURSIVE IMPLEMENTATION)
		void heapify(int i) {
			int largest = i; // Initialize largest as root
    		int l = left(i); // left child = 2 * i + 1
    		int r = right(i); // right = 2 * i + 2
			
			// If left child is larger than root
			if((l < heap_size) and (v[l] > v[largest])) largest = l;
			
			// If right child is larger than largest so far
			if((r < heap_size) and (v[r] > v[largest])) largest = r;
			
			// If largest is not root
			if(largest != i) {
				swap(v[i], v[largest]);
				
				// Recursively heapify the affected sub-tree
				heapify(largest);
			}
		}
		
		// to heapify the subtree root at index i in v[] (ITERATIVE IMPLEMENTATION)
		/*void heapify(int i) {
			// j => to store the index of left child of i
			int j = left(i);
			
			while(j < heap_size) {
				// compare the left and right childs of i
				if((j + 1 < heap_size) and (v[j + 1] > v[j])) j += 1;
				
				// compare the parent i, with the max(left child, right child)
				if(v[j] > v[i]) {
					swap(v[i], v[j]);
					i = j;
					j = left(i);
				}
				
				else break;
			}
		}*/
		
	public:
		// member functions ===>
		
		// default constructor
		MaxHeap() {
			max_size = 1e5;
			heap_size = 0;
			v.clear();
			v.resize(max_size);
		}
		
		// parameterized constructor
		MaxHeap(int val) {
			max_size = val;
			heap_size = 0;
			v.clear();
			v.resize(max_size);
		}
		
		// to insert a key in the heap
		void insert_key(int key) {
			if(heap_size == max_size) {
				cout << "Overflow: Could not insert key: " << key << "\n";
				return;	
			}
			
			heap_size += 1;
			int i = heap_size - 1;
		    v[i] = key;
		
		    // The max heap property is checked and if violation occurs, it is restored.
		    while ((i > 0) and (v[parent(i)] < v[i])) {
		        swap(v[i], v[parent(i)]);
		        i = parent(i);
		    }
		}
		
		// no key is passed because heap supports only deletion of the root element efficiently
		void delete_root() {
			if(heap_size == 0) {
				cout << "Underflow: Heap already empty\n";
				return;	
			}
			
			int i = heap_size - 1;
			heap_size -= 1;
			v[0] = v[i];
			
			heapify(0);
		}
		
		// to return the maximum element of heap i.e. top-most element
		int heap_top() {
			if(heap_size == 0) {
				cout << "Heap empty: No top element\n";
				return -INF;	
			}
			
			return v[0];
		}
		
		// to return the #keys present in heap at any point of time
		int cur_size() {
			return heap_size;
		}		
};

void solve()
{	
	int n; cin >> n;
	
  	MaxHeap mxh(n);
  	
  	int q; cin >> q;
  	
  	while(q--) {
  		// 0 = insert_key() | 1 = delete_root() | 2 = heap_top() | 3 = cur_size
  		int typ; cin >> typ;
  		
  		if(typ == 0) {
  			int key; cin >> key;
			mxh.insert_key(key);
  		}
  		
  		else if(typ == 1) mxh.delete_root();
  		
  		else if(typ == 2) {
  			int x = mxh.heap_top();
  			if(x != -INF) cout << "Heap's top element: " << x << "\n";
  		}
  		
  		else {
  			cout << "Current heap size: " << mxh.cur_size() << "\n";
  		}
  	}
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

// The time complexities have been thoroughly discussed in the reference videos.

/* 

Sample i/p :--->

50
19
0 30
0 28
0 25
0 13
0 -1
0 15
0 16
0 6
0 9
2
3
1
2
1
3
2
0 79
2
3

Sample o/p :--->

Heap's top element: 30
Current heap size: 9
Heap's top element: 28
Current heap size: 7
Heap's top element: 25
Heap's top element: 79
Current heap size: 8

*/
