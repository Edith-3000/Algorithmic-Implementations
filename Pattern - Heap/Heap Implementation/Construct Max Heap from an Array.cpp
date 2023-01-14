// Ref: https://www.youtube.com/watch?v=cuL8gXCSA58&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=4
//      https://www.youtube.com/watch?v=VkKmmwzfIG4&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=5
//      https://www.youtube.com/watch?v=YJa3GpNUrNs
//      https://www.youtube.com/watch?v=VFLNBh0bK2A&list=PL-Jc9J83PIiHq5rMZasunIR19QG3E-PAA&index=24
//      For some other general info also refer "Heapify.cpp"
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

// To heapify a subtree rooted with node i which is
// an index in v[] and n is size of heap
void heapify(vi &v, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left child = 2 * i + 1
    int r = 2 * i + 2; // right = 2 * i + 2
 
    // If left child is larger than root
    if (l < n and v[l] > v[largest]) largest = l;
 
    // If right child is larger than largest so far
    if (r < n and v[r] > v[largest]) largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(v[i], v[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(v, n, largest);
    }
}

// Function to transfrom v[] into a max heap
void construct_max_heap(vi &v) {
	// size of heap 
	int n = sz(v);
	
	// Considering 0-based indexing, if heap size is of 'n', the the leaf nodes will be in the range
    // [floor(n/2), n - 1] and internal nodes will be in the range [0, floor(n/2) - 1].
    
    // We know to heapify a node it's left and right subtree must be a heap, so all the leaves
    // are already a heap, therefore start heapifying from internal nodes.
    
    for (int i = (n / 2 - 1); i >= 0; i--) {
    	heapify(v, n, i);
    }
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	construct_max_heap(v);
  	
  	for(auto x: v) cout << x << " ";
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

// Time complexity to build heap from heapify() operation is O(n), not O(n * log(n)), for formal proof
// refer: https://www.youtube.com/watch?v=VkKmmwzfIG4&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=5
//        https://www.quora.com/How-do-you-evaluate-the-sum-of-n-2-n-from-n-1-to-infinity

/* # Proof which has been explained in the video ===>
     https://www.youtube.com/watch?v=VkKmmwzfIG4&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28&index=5

     can also be found here ===> 
     https://gist.github.com/Edith-3000/40b1c16d85340e712218ab177d264266?permalink_comment_id=4436653#gistcomment-4436653

   # Another variation of proof according to this highlighted comment ===>
     https://www.youtube.com/watch?v=VkKmmwzfIG4&lc=UgzNaRD2xKhskc_B22F4AaABAg&ab_channel=TECHDOSE

     or somewhat according to this video ===>
     https://youtu.be/VFLNBh0bK2A?list=PL-Jc9J83PIiHq5rMZasunIR19QG3E-PAA&t=578

     can be found here ===>
     https://gist.github.com/Edith-3000/40b1c16d85340e712218ab177d264266?permalink_comment_id=4436654#gistcomment-4436654
*/