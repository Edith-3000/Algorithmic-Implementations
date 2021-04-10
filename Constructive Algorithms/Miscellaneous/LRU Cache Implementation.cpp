// Ref: https://www.geeksforgeeks.org/lru-cache-implementation/
/****************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

class LRU_Cache {
	// maximum capacity of cache
	int capacity;
	
	// store keys of cache
	list<int> dq;
	
	// store references of key in cache (in the list "dq", our cache)
	unordered_map<int, list<int>::iterator> hash;
	
	public:
		LRU_Cache(int n);
		void refer(int page);
		void display();
};

// https://www.includehelp.com/cpp-tutorial/defining-member-function-outside-of-the-class-in-cpp.aspx
// Constructor of the class
LRU_Cache::LRU_Cache(int n) {
	capacity = n;
}

// Refers page with in the LRU cache
void LRU_Cache::refer(int page) {
	// page not present in cache (i.e. page fault)
	if(hash.find(page) == hash.end()) {
		// if cache is already full
		if((int)dq.size() == capacity) {
			// delete least recently used page
			int least_recently_used_page = dq.back();
			dq.pop_back();
			
			// also delete it's address as it is swapped out
			// of the cache
			hash.erase(least_recently_used_page);
		}
	}
	
	// present in cache (we erase it as we always keep the 
	// most recently used page at the front of dq and the least
	// recently used one at the end of dq)
	else dq.erase(hash[page]);
	
	// update reference of the page
	dq.push_front(page);
	hash[page] = dq.begin();
}

// Function to display contents of cache
void LRU_Cache::display() {
	for(auto it = dq.begin(); it != dq.end(); it++) {
		cout << *it << " ";
	}
	
	cout << "\n";
} 

void solve()
{
	cout << "Capacity of cache: ";
	int n; cin >> n;
	cout << n << "\n";
	
  	LRU_Cache lru(n);
  	
  	cout << "#operations to be performed: ";
  	int q; cin >> q;
  	cout << q << "\n";
  	
  	for(int i = 0; i < q; i++) {
  		int type; cin >> type;
  		if(type == 1) {
  			int page; cin >> page;
  			lru.refer(page);
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

    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

/* Sample i/p: 4
			   7
			   1 1
			   1 2
			   1 3
			   1 1
			   1 4
			   1 5
			   2

   Sample o/p: Capacity of cache: 4
			   #operations to be performed: 7
			   5 4 1 3 
*/