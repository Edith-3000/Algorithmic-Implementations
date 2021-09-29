// Prob: https://leetcode.com/problems/lfu-cache/
/***********************************************************************************************************/

// Ref: https://www.youtube.com/watch?v=0PSB9y8ehbk
//      https://www.youtube.com/watch?v=mzqHlAW7jeE
/**********************************************************************************************************/

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

// Doubly Linked List Node class begins
class DLL_node {
	public:
		int key, val, cnt;
		DLL_node *prev, *next;
	
		DLL_node(int key_, int val_, int cnt_) {
			key = key_;
			val = val_;
			cnt = cnt_;
			prev = next = NULL;
        }
};
// Doubly Linked List Node class ends

// Doubly Linked List class and it's associated functions begin
class DLL {	
	public:
		int list_size;
		DLL_node *head;
		DLL_node *tail;
	
		DLL();
		void addnode(DLL_node*);
		void deletenode(DLL_node*);
		void display();
};

DLL::DLL() {
	list_size = 0;
	head = new DLL_node(-1, -1, 0);
	tail = new DLL_node(-1, -1, 0);
	head->next = tail;
	tail->prev = head;
}

void DLL::addnode(DLL_node *add) {
	DLL_node *tmp = head->next;
	head->next = add;
	add->prev = head;
	add->next = tmp;
	tmp->prev = add;
	list_size += 1;
}

void DLL::deletenode(DLL_node *del) {
	del->prev->next = del->next;
	del->next->prev = del->prev;
	list_size -= 1;
	// delete del; // uncommenting it may cause problems
}

void DLL::display() {
	DLL_node *tmp = head->next;
	
	while(tmp != tail) {
		cout << "(" << tmp->key << ", " << tmp->val << ", " << tmp->cnt << ")\n";
		tmp = tmp->next;
	}
}
// Doubly Linked List class and it's associated functions end

// LFU Cache class and it's associated functions begin
class LFU_Cache {
	int capacity, cur_size, min_freq;
	map<int, DLL_node*> key_node_map;
	map<int, DLL*> freq_list_map;
	
	public:
		LFU_Cache(int n);
		int get(int K);
		void set(int K, int V);
		
		void upd_freq_list_map(DLL_node*);
		void display();
};

LFU_Cache::LFU_Cache(int n) {
	capacity = n;
	cur_size = 0;
	min_freq = 0;
	
	key_node_map.clear();
	freq_list_map.clear();
}

int LFU_Cache::get(int K) {
	if(key_node_map.find(K) != key_node_map.end()) {
		DLL_node *node = key_node_map[K];
		int val = node->val;
		upd_freq_list_map(node);
		return val;
	}
	
	else return -1;
}

void LFU_Cache::set(int K, int V) {
	if(capacity == 0) return;
	
	if(key_node_map.find(K) != key_node_map.end()) {
		DLL_node *node = key_node_map[K];
		node->val = V;
		upd_freq_list_map(node);
	}
	
	else {
		if(cur_size == capacity) {
			DLL *list = freq_list_map[min_freq];
			key_node_map.erase(list->tail->prev->key);
			list->deletenode(list->tail->prev);
			cur_size -= 1;
		}
		
		cur_size += 1;
		min_freq = 1;
		
		DLL *list = new DLL();
		
		if(freq_list_map.find(min_freq) != freq_list_map.end()) {
			list = freq_list_map[min_freq];
		}
		
		DLL_node *node = new DLL_node(K, V, 1);
		list->addnode(node);
		
		freq_list_map[node->cnt] = list;
		key_node_map[K] = node; 
	}	
}

void LFU_Cache::upd_freq_list_map(DLL_node *node) {
	key_node_map.erase(node->key);
	freq_list_map[node->cnt]->deletenode(node);
	
	if(node->cnt == min_freq and freq_list_map[node->cnt]->list_size == 0) {
		min_freq += 1;
	}
	
	DLL *next_higher_freq_list = new DLL();
	
	if(freq_list_map.find(node->cnt + 1) != freq_list_map.end()) {
		next_higher_freq_list = freq_list_map[node->cnt + 1];
	}
	
	node->cnt += 1;
	next_higher_freq_list->addnode(node);
	freq_list_map[node->cnt] = next_higher_freq_list;
	key_node_map[node->key] = node;
}

void LFU_Cache::display() {
	for(auto it = freq_list_map.begin(); it != freq_list_map.end(); it++) {
		int fq = it->F;
		DLL *list = it->S;
		
		if(list->list_size == 0) continue;
		
		cout << fq << "->\n";
		list->display();
	}
	
	cout << "********************\n";
}
// LFU Cache class and it's associated functions end

void solve()
{
  	// capacity of cache
	int n; cin >> n;
	
	// object instantiated
  	LFU_Cache lfu(n);
  	
  	// #operations to be performed
  	int q; cin >> q;
  	
  	for(int i = 0; i < q; i++) {
  		// 1 = get(K), 2 = set(K, V), 3 = display()
  		int type; cin >> type;
  		if(type == 1) {
  			int K; cin >> K;
  			cout << lfu.get(K) << "\n";
  		}
  		
  		else if(type == 2) {
  			int K, V; cin >> K >> V;
  			lfu.set(K, V);
  		}
  		
  		else {
  			lfu.display();
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