// Prob: https://leetcode.com/problems/copy-list-with-random-pointer/

// Ref: https://www.youtube.com/watch?v=VNf6VynfpdM&list=PLgUwDviBIf0r47RKH7fdWN54AbWFgGuii&index=14
/*****************************************************************************************************************************************************************/

// METHOD - 1
// O(n^2) time and O(n) space.

// Ref: https://pastebin.com/1yH6FGvK

/*****************************************************************************************************************************************************************/

// METHOD - 2
// O(n) time and space.

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

// Linked List Node
class Node {
    public:
    	int val;
    	Node* next, *random;
    
    	Node(int _val) {
        	val = _val;
        	next = random = NULL;
    	}
};
 
// linked list class
class LinkedList {
    public:
    Node *head; // Linked list head reference
 
    LinkedList(Node *head) {
        this->head = head;
    }
 
    // push method to put data always at
    // the head in the linked list.
    void push(int data) {
        Node *node = new Node(data);
        node->next = head;
        head = node;
    }
};

// Method to print the list.
void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        Node *random = temp->random;
        int randomData = (random != NULL) ? random->val : -1;
        cout << "Data = " << temp->val << ", ";
        cout << "Random Data = " << randomData << endl;
        temp = temp->next;
    }
        
    cout << endl;
}

Node* clone(Node *head) {
	// Initialize two references, one with original list's head.
    Node *origCurr = head;
    Node *cloneCurr = NULL;
 
    // Hash map which contains node to node mapping of original
    // and clone linked list.
    unordered_map<Node*, Node*> mymap;
 
    // Traverse the original list and make a copy of that in the clone linked list.
    while (origCurr != NULL) {
        cloneCurr = new Node(origCurr->val);
        mymap[origCurr] = cloneCurr;
        origCurr = origCurr->next;
    }
 
    // Adjusting the original list reference again.
    origCurr = head;
 
    // Traversal of original list again to adjust the next and random
    // references of clone list using hash map.
    while (origCurr != NULL) {
        cloneCurr = mymap[origCurr];
        cloneCurr->next = mymap[origCurr->next];
        cloneCurr->random = mymap[origCurr->random];
        origCurr = origCurr->next;
    }
 
    // return the head reference of the clone list.
    return mymap[head];
}

void solve()
{
  	LinkedList *mylist = new LinkedList(new Node(5));
    mylist->push(4);
    mylist->push(3);
    mylist->push(2);
    mylist->push(1);
 
    // Setting up random references.
    mylist->head->random = mylist->head->next->next;
 
    mylist->head->next->random = mylist->head->next->next->next;
 
    mylist->head->next->next->random = mylist->head->next->next->next->next;
 
    mylist->head->next->next->next->random = mylist->head->next->next->next->next->next;
 
    mylist->head->next->next->next->next->random = mylist->head->next;
 
    // Making a clone of the original linked list.
    Node *clone_head = clone(mylist->head);
 
    // Print the original and cloned linked list.
    cout << "Original linked list\n";
    print(mylist->head);
    
    cout << "\nCloned linked list\n";
    print(clone_head);
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

/*****************************************************************************************************************************************************************/

// METHOD - 3
// O(n) time and O(1) space.

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

// Linked List Node
class Node {
    public:
    	int val;
    	Node* next, *random;
    
    	Node(int _val) {
        	val = _val;
        	next = random = NULL;
    	}
};
 
// linked list class
class LinkedList {
    public:
    Node *head; // Linked list head reference
 
    LinkedList(Node *head) {
        this->head = head;
    }
 
    // push method to put data always at
    // the head in the linked list.
    void push(int data) {
        Node *node = new Node(data);
        node->next = head;
        head = node;
    }
};

// Method to print the list.
void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        Node *random = temp->random;
        int randomData = (random != NULL) ? random->val : -1;
        cout << "Data = " << temp->val << ", ";
        cout << "Random Data = " << randomData << endl;
        temp = temp->next;
    }
        
    cout << endl;
}

Node* clone(Node *head) {
	Node *iter = head, *front = head;
	
	// Step 1: make copy of each node, & link them together side-by-side in a single list.
	while(iter != NULL) {
		front = iter->next;
		
		Node *deep_copy_node = new Node(iter->val);
		iter->next = deep_copy_node;
		deep_copy_node->next = front;
		
		iter = front;
	}
	
	// Step 2: assign random pointers for the copy nodes.
	iter = head;
	
	while(iter != NULL) {
		if(iter->random != NULL) {
			iter->next->random = iter->random->next;
		}
		
		iter = iter->next->next;
	}
	
	// Step 3: assign next pointers for the original & deep copy list,
	//         i.e. restore the original list, and extract the copy list.
	Node *pseudo_head = new Node(0);
	Node *tmp = pseudo_head;
	iter = head;
	
	while(iter != NULL) {
		front = iter->next->next;
		
		// extract the copy
		tmp->next = iter->next;
		tmp = tmp->next;
		
		// restore the original list
		iter->next = front;
		iter = front;
	}
	
	return pseudo_head->next;
}

void solve()
{
  	LinkedList *mylist = new LinkedList(new Node(5));
    mylist->push(4);
    mylist->push(3);
    mylist->push(2);
    mylist->push(1);
 
    // Setting up random references.
    mylist->head->random = mylist->head->next->next;
 
    mylist->head->next->random = mylist->head->next->next->next;
 
    mylist->head->next->next->random = mylist->head->next->next->next->next;
 
    mylist->head->next->next->next->random = mylist->head->next->next->next->next->next;
 
    mylist->head->next->next->next->next->random = mylist->head->next;
 
    // Making a clone of the original linked list.
    Node *clone_head = clone(mylist->head);
 
    // Print the original and cloned linked list.
    cout << "Original linked list\n";
    print(mylist->head);
    
    cout << "\nCloned linked list\n";
    print(clone_head);
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