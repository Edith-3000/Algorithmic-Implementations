// Prob: https://practice.geeksforgeeks.org/problems/lru-cache/1
/****************************************************************************************************/

/* # LRU Cache is about removing the element that was accessed longest time ago if the size of the 
     cache is full and incoming element is to be inserted or in any other case.

   # In the below algorithm, The LRU_Cache class has two methods get() and set() which are defined 
     as follows.
     1. get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
     2. set(key, value): if the key is already present, update its value. If not present, add the 
                         key-value pair to the cache. 
                         If the cache reaches its capacity it should invalidate the least recently used 
                         item before inserting the new item.

     3. In the constructor of the class the capacity of the cache should be intitialized.

   # The underlying data structures used for implementing LRU Cache data structure is a 
     "Doubly Linked List" and an "Unordered Map".

   # The below algorithm is written in such a manner such that the "LEAST" recently used node is always
     at tail->prev and the "LAST or MOST" recently used node is at head->next. 
*/

// Ref: https://www.youtube.com/watch?v=xDEuM5qa0zg&list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj&index=10
//      https://www.youtube.com/watch?v=Xc4sICC8m4M&list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj&index=11

/*******************************************************************************************************/

// METHOD - 1

#include<bits/stdc++.h>
using namespace std;

class DLL_node {
	public:
		int key, val;
		DLL_node *prev, *next;
		
		DLL_node(int key_, int val_) {
			key = key_;
			val = val_;
			prev = next = NULL;
		}
};

class LRU_Cache {
	// maximum capacity of cache
	int capacity;
	
	DLL_node *head;
	DLL_node *tail;
	
	// store references of key in cache (in the linked list, i.e. our cache)
	unordered_map<int, DLL_node*> hash;
	
	public:
		LRU_Cache(int n);
		int get(int K);
		void set(int K, int V);
		
		void addnode(DLL_node*);
		void deletenode(DLL_node*);
		void display();
};

// https://www.includehelp.com/cpp-tutorial/defining-member-function-outside-of-the-class-in-cpp.aspx
// Constructor of the class
LRU_Cache::LRU_Cache(int n) {
	capacity = n;
	
	// head and tail node are initialized which act as dummy nodes so that we always
	// have someone back and front to avoid writing multiple cases to check for NULL 
	head = new DLL_node(-1, -1);
	tail = new DLL_node(-1, -1);
	head->next = tail;
	tail->prev = head;
	
	hash.clear();
}

// if a node is added that means it is the "LAST or MOST" (note it's LAST not LEAST) 
// recently used node and in our convention we always keep it at head->next
void LRU_Cache::addnode(DLL_node *add) {
	DLL_node *tmp = head->next;
	head->next = add;
	add->prev = head;
	add->next = tmp;
	tmp->prev = add;
}

void LRU_Cache::deletenode(DLL_node *del) {
	del->prev->next = del->next;
	del->next->prev = del->prev;
}

void LRU_Cache::set(int K, int V) {
	// if already present delete from current address and bring that
	// node in front of head, so that it becomes the last recently used node
	if(hash.find(K) != hash.end()) {
		DLL_node *existingnode = hash[K];
		hash.erase(K);
		deletenode(existingnode);
	}
	
	// if cache is full, then delete the "LEAST" recently used node, which in our
	// convention present at just previous to tail node
	if((int)hash.size() == capacity) {
		hash.erase(tail->prev->key);
		deletenode(tail->prev);
	}
	
	// from a new node 
	addnode(new DLL_node(K, V));
	hash[K] = head->next;
}

int LRU_Cache::get(int K) {
	// if already present delete from current address and bring that
	// node in front of head, so that it becomes the last recently used node
	if(hash.find(K) != hash.end()) {
		DLL_node *resnode = hash[K];
		int res = resnode->val;
		hash.erase(K);
		deletenode(resnode);
		addnode(resnode);
		hash[K] = head->next;
		return res;
	}
	
	else return -1;
}

// Function to display contents of cache
void LRU_Cache::display() {
	DLL_node *tmp = head->next;
	
	while(tmp != tail) {
		cout << "(" << tmp->key << ", " << tmp->val << ")\n";
		tmp = tmp->next;
	}
} 

void solve()
{
	// capacity of cache
	int n; cin >> n;
	
	// object instantiated
  	LRU_Cache lru(n);
  	
  	// #operations to be performed
  	int q; cin >> q;
  	
  	for(int i = 0; i < q; i++) {
  		// 1 = get(K), 2 = set(K, V), 3 = display()
  		int type; cin >> type;
  		if(type == 1) {
  			int K; cin >> K;
  			cout << lru.get(K) << "\n";
  		}
  		
  		else if(type == 2) {
  			int K, V; cin >> K >> V;
  			lru.set(K, V);
  		}
  		
  		else {
  			lru.display();
  		}
  	}
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

// Time complexity of get() and set() = O(1), approximately.

/********************************************************************************************************/

// METHOD - 2
// THe logic of both the methods is same, just the implementation is different.

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

class DLL_node { 
    public:
        int ky, val;
        DLL_node *prv, *nxt;
    
        DLL_node() {
            ky = val = -1;
            prv = nxt = NULL;
        }
    
        DLL_node(int k, int v) {
            ky = k;
            val = v;
            prv = nxt = NULL;
        }
};

class LRUCache {
    int mx_cap;
    DLL_node *head, *tail;
    unordered_map<int, DLL_node*> mp;
    
public:
    LRUCache(int capacity) {
        mx_cap = capacity;
        head = new DLL_node();
        tail = new DLL_node();
        head->nxt = tail;
        tail->prv = head;
        mp.clear();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        
        DLL_node *pos = mp[key];
        upd_pos(pos);
        
        return pos->val;
    }
    
    void set(int key, int value) {
        if(mp.find(key) == mp.end()) {
            if((int)mp.size() == mx_cap) {
                DLL_node *tmp = tail->prv;
                tmp->prv->nxt = tail;
                tail->prv = tmp->prv;
                mp.erase(tmp->ky);
                delete tmp;
            }
            
            DLL_node *new_node = new DLL_node(key, value);
            mp[key] = new_node;
            
            new_node->nxt = head->nxt;
            head->nxt->prv = new_node;
            head->nxt = new_node;
            new_node->prv = head;
        }
        
        else {
            DLL_node *pos = mp[key];
            pos->val = value;
            upd_pos(pos);
        }
    }
    
    void upd_pos(DLL_node *pos) {
        pos->prv->nxt = pos->nxt;
        pos->nxt->prv = pos->prv;
        
        pos->nxt = head->nxt;
        head->nxt->prv = pos;
        head->nxt = pos;
        pos->prv = head;
    }
    
    void display() {
		DLL_node *tmp = head->nxt;
	
		while(tmp != tail) {
			cout << "(" << tmp->ky << ", " << tmp->val << ")\n";
			tmp = tmp->nxt;
	    }
    } 
};

void solve()
{
  	// capacity of cache
	int n; cin >> n;
	
	// object instantiated
  	LRUCache lru(n);
  	
  	// #operations to be performed
  	int q; cin >> q;
  	
  	for(int i = 0; i < q; i++) {
  		// 1 = get(K), 2 = set(K, V), 3 = display()
  		int type; cin >> type;
  		if(type == 1) {
  			int K; cin >> K;
  			cout << lru.get(K) << "\n";
  		}
  		
  		else if(type == 2) {
  			int K, V; cin >> K >> V;
  			lru.set(K, V);
  		}
  		
  		else {
  			lru.display();
  		}
  	}
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

// Time complexity of get() and set() = O(1), approximately.