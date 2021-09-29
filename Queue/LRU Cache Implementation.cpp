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

   # The underlying data structures used for implementing data structure is a "Doubly Linked List"
     and an "Unordered Map".

   # The below algorithm is written in such a manner such that the "LEAST" recently used node is always
     at tail->prev and the "LAST or MOST" recently used node is at head->next. 
*/

// Ref: https://www.youtube.com/watch?v=xDEuM5qa0zg&list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj&index=10
//      https://www.youtube.com/watch?v=Xc4sICC8m4M&list=PLgUwDviBIf0oSO572kQ7KCSvCUh1AdILj&index=11

/*******************************************************************************************************/

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
	// have someoneback and front to avoid writing multiple cases to check for NULL 
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