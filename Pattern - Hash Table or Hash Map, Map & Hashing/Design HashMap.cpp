// Main ref: https://www.youtube.com/watch?v=2ijH5vcKIxQ

// Some other useful links related to the code below:--- >

// https://www.youtube.com/watch?v=xVEGczCJCHs
// https://www.youtube.com/watch?v=ISir207RuKQ
// https://www.youtube.com/watch?v=7mUKGHznpfg

// https://leetcode.com/problems/design-hashmap/

// https://www.geeksforgeeks.org/c-program-hashing-chaining/
// https://www.geeksforgeeks.org/templates-cpp/
// https://www.geeksforgeeks.org/list-cpp-stl/
// https://www.geeksforgeeks.org/stdhash-class-in-c-stl/
// https://www.geeksforgeeks.org/destructors-c/
// https://www.quora.com/What-is-the-difference-between-HashMap-and-Map-in-C
// https://www.fullstack.cafe/blog/hash-tables-interview-questions

/**************************************************************************************************************/

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

template<class K, class V>
class HashMapNode {
	public:
		// data members
		K key;
		V value;
		
		// constructor
		HashMapNode(K key, V value) {
			this->key = key;
			this->value = value;
		}
};

template<class K, class V>
class HashMap {
	private:
		// data members
		int hm_size, total_buckets;
		double lambda, threshold;
		list<HashMapNode<K, V>> *buckets;
		
		// function to return the bucket index for the passed key
		int hash_function(K key) {
			hash<K> my_hash;

			// DATA TYPE OF "x" MIGHT BE REQUIRED TO CHANGE 
			int x = my_hash(key); 

			// abs(x) is required as x may come out to be -ve and % is also required since
			// my_hash() can return any value
			return (abs(x) % total_buckets);
		}
		
		// function to find the index of key in bucket numbered bi, if key 
		// not present it returns -1
		int get_index_within_bucket(K key, int bi) {
			int ki = -1;
			
			for(HashMapNode node: buckets[bi]) {
				ki += 1;
				if(node.key == key) return ki;
			}
			
			return -1;
		}
		
		// rehash function so as to bring lamda <= threshold
		void rehash() {
			int old_total_buckets = total_buckets;
			list<HashMapNode<K, V>> *old_buckets = buckets;
			
			total_buckets *= 2;
			hm_size = 0;
			
			buckets = new list<HashMapNode<K, V>>[total_buckets];
			
			for(int i = 0; i < old_total_buckets; i++) {
				for(auto node: old_buckets[i]) {
					put(node.key, node.value);
				}
			}
			
			delete [] old_buckets;
		}
		
	public:
		// default constuctor
		HashMap() {
			hm_size = 0;
			total_buckets = 16;
			buckets = new list<HashMapNode<K, V>>[total_buckets];
			lambda = 0.0;
			threshold = 2.0;
		}
		
		// parameterised constuctor
		HashMap(int initial_buckets) {
			hm_size = 0;
			total_buckets = initial_buckets;
			buckets = new list<HashMapNode<K, V>>[initial_buckets];
			lambda = 0.0;
			threshold = 2.0;
		}
		
		// inserts the key with value, if key is already present the value is updated
		void put(K key, V value) {
			// key 'K' is passed into the hash function so as to get the bucket index
			int bi = hash_function(key);
			
			// to find the index of key in bucket bi
			int ki = get_index_within_bucket(key, bi);
			
			// if key already present, just update it's value
			if(ki != -1) {
				int cnt = 0;
				
				for(auto it = buckets[bi].begin(); it != buckets[bi].end(); it++) {
					if(cnt == ki) {
						it->value = value;
						break;
					}
					
					cnt += 1;
				} 
			}
			
			// else if key is inserted for the first time
			else {
				HashMapNode<K, V> node(key, value);
				buckets[bi].push_back(node);
				hm_size += 1;
				
				lambda = (hm_size * 1.0) / total_buckets;
				
				if(lambda > threshold) {
					rehash();
				} 
			}
		}
		
		// function to return the value of key if present, else return null
		V get(K key) {
			int bi = hash_function(key);
			int ki = get_index_within_bucket(key, bi);
			
			// if key is present
			if(ki != -1) {
				int cnt = 0;
				
				for(auto it = buckets[bi].begin(); it != buckets[bi].end(); it++) {
					if(cnt == ki) return it->value;
					cnt += 1;
				}
			}
			
			// if key is not present
			else {
				cout << "Key " << key << " not found\n";
				return V();
			}
			
			// added so as to remove warning
			return V();
		}
		
		// remove the (key, value) pair if present
		void remove(K key) {
			int bi = hash_function(key);
			int ki = get_index_within_bucket(key, bi);
			
			if(ki != -1) {
				int cnt = 0;
				hm_size -= 1;
				
				for(auto it = buckets[bi].begin(); it != buckets[bi].end(); it++) {
					if(cnt == ki) {
						buckets[bi].erase(it);
						return;
					}
					
					cnt += 1;
				}
			}
		}
		
		// return true if key present, else returns false
		bool contains_key(K key) {
			int bi = hash_function(key);
			int ki = get_index_within_bucket(key, bi);
			
			if(ki != -1) return 1;
			else return 0;
		}
		
		// returns all the keys present in Hash Map
		vector<K> key_set() {
			vector<K> keys;
			
			for(int i = 0; i < total_buckets; i++) {
				for(auto node: buckets[i]) keys.push_back(node.key);
			}
			
			return keys;
		}
		
		// returns the total #keys present in Hash Map
		int hash_map_size() {
			return hm_size;
		}
		
		// display all the content of Hash Map
		void display() {
			for(int i = 0; i < total_buckets; i++) {
				cout << "Bucket " << i << ": ";
				
				for(auto node: buckets[i]) {
					cout << "(" << node.key << ", " << node.value << ") ";
				}
				
				cout << "\n";
			}
		}
		
		// destructor
		~HashMap() {
			delete [] buckets;
		}
};

void solve()
{
  	HashMap<string, int> hm;
  	
  	// total #operations which are to be performed on the Hash Map
  	int q; cin >> q;
  	
  	for(int i = 0; i < q; i++) {
  		// 0 = put() | 1 = get() | 2 = remove() | 3 = contains_key() 
  		// 4 = key_set() | 5 = hash_map_size() | 6 = display()
  		int typ; cin >> typ;
  		
  		if(typ == 0) {
  			string k; int v; cin >> k >> v;
  			hm.put(k, v);
  		}
  		
  		else if((typ >= 1) and (typ <= 3)) {
  			string k; cin >> k;
  			if(typ == 1) cout << hm.get(k) << "\n";
  			else if(typ == 2) hm.remove(k);
  			else {
  				if(hm.contains_key(k)) cout << "Key " << k << "present\n";
  				else cout << "Key " << k << " absent\n";
  			}
  		}
  		
  		else if(typ == 4) {
  			// CHANGE THE DATA TYPE OF v[] ACCORDING TO THE TYPE OF "k"
  			vector<string> v = hm.key_set();
  			for(auto x: v) cout << x << " ";
  			cout << "\n";
  		}
  		
  		else if(typ == 5) {
  			cout << "Size of Hash Map = " << hm.hash_map_size() << "\n";
  		}
  		
  		else hm.display();
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

// TC: for all the methods it's been clearly mentioned in the Main ref. video.