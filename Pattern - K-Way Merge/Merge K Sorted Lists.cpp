// Prob: https://leetcode.com/problems/merge-k-sorted-lists/
/**************************************************************************************************************/

/* UNDERLYING CONCEPT ------>
   # A brute force solution could be to add all elements of the given ‘K’ lists to one list and sort it.

   # If there are a total of ‘N’ elements in all the input lists, then the brute force solution will have a 
	 time complexity of O(N * log₂N) as we will need to sort the merged list. 

   # A better approach can be followed by utilizing 𝒕𝒉𝒆 𝒇𝒂𝒄𝒕 𝒕𝒉𝒂𝒕 𝒕𝒉𝒆 𝒊𝒏𝒑𝒖𝒕 𝒍𝒊𝒔𝒕𝒔 𝒂𝒓𝒆 𝒊𝒏𝒅𝒊𝒗𝒊𝒅𝒖𝒂𝒍𝒍𝒚 𝒔𝒐𝒓𝒕𝒆𝒅.

   # If we have to find the smallest element of all the input lists, we have to compare 𝒐𝒏𝒍𝒚 𝒕𝒉𝒆 𝒔𝒎𝒂𝒍𝒍𝒆𝒔𝒕 
	 𝒊.𝒆. 𝒕𝒉𝒆 𝒇𝒊𝒓𝒔𝒕) 𝒆𝒍𝒆𝒎𝒆𝒏𝒕 𝒐𝒇 𝒂𝒍𝒍 𝒕𝒉𝒆 𝒍𝒊𝒔𝒕𝒔. 

   # Once we have the smallest element, we can put it in the merged list. 

   # Following a similar pattern, we can then find the next smallest element of all the lists to add it to 
	 the merged list.

   # 𝑻𝑯𝑬 𝑩𝑬𝑺𝑻 𝑫𝑨𝑻𝑨 𝑺𝑻𝑹𝑼𝑪𝑻𝑼𝑹𝑬 𝑻𝑯𝑨𝑻 𝑪𝑶𝑴𝑬𝑺 𝑻𝑶 𝑴𝑰𝑵𝑫 𝑻𝑶 𝑭𝑰𝑵𝑫 𝑻𝑯𝑬 𝑺𝑴𝑨𝑳𝑳𝑬𝑺𝑻 𝑵𝑼𝑴𝑩𝑬𝑹 𝑹𝑬𝑷𝑬𝑨𝑻𝑬𝑫𝑳𝒀 
	 𝑨𝑴𝑶𝑵𝑮 𝑨 𝑺𝑬𝑻 𝑶𝑭 ‘𝑲’ 𝑵𝑼𝑴𝑩𝑬𝑹𝑺 𝑰𝑺 𝑨 𝑯𝑬𝑨𝑷. 

   # Let’s see how can we use a heap to find a better algorithm.
	 * We can insert the first element of each array in a Min Heap.
	 * After this, we can take out the smallest (top) element from the heap and add it to the merged 
	   list.
	 * After removing the smallest element from the heap, we can insert the next element of the 𝒔𝒂𝒎𝒆 list 
	   into the heap.
	 * We can repeat steps 2 and 3 to populate the merged list in sorted order.
*/

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

// Making a node class containing the value and a pointer
// to next available node
class ListNode {
	public:
		int val;
		ListNode *next;
};

class LinkedList {
	public:
		// head and tail pointers
		ListNode *head, *tail;
		
		// default constructor. Initializing head and tail pointers
		LinkedList() {
			head = NULL;
			tail = NULL;
		}
		
		// inserting elements (at the end of the list)
		void insert(int data) {
			// make a new node
			ListNode *new_node = new ListNode;
			new_node->val = data;
			new_node->next = NULL;
			
			// If list is empty, make the new node, the head
			// initialise tail also as new node
			if(head == NULL) {
				head = new_node;
				tail = new_node;
			}
			
			else {
				tail->next = new_node;
				tail = tail->next;
			}
		}
		
		void display() {
			ListNode *tmp = head;
			while(tmp != NULL) {
				cout << tmp->val;
				tmp = tmp->next;
				if(tmp != NULL) cout << "->";
			}
			
			cout << "\n";
		}		
};

struct comparator {
    bool operator() (ListNode* &p, ListNode* &q) {
        return (p->val) > (q->val);
    }  
};

ListNode* merge_k_sorted_lists(vector<ListNode*> &v) {
	int k = sz(v);
            
    priority_queue<ListNode*, vector<ListNode*>, comparator> pq;
    
    for(int i = 0; i < k; i++) {
        if(v[i] != nullptr) pq.push(v[i]);
    }
    
    ListNode *dummy = new ListNode;
    ListNode *itr = dummy;
    
    while(!pq.empty()) {
        ListNode *cur = pq.top();
        pq.pop();
        
        itr->next = cur;
        itr = itr->next;
        
        if(cur->next != nullptr) {
            pq.push(cur->next);
        }
    }
    
    return dummy->next;
}

void solve()
{
  	int k; cin >> k;
  	
  	vector<ListNode*> v(k);
  	
  	for(int i = 0; i < k; i++) {
  		LinkedList l;
  		
  		int n; cin >> n;
  		for(int j = 0; j < n; j++) {
  			int x; cin >> x;
  			l.insert(x);	
  		}
  		
  		l.display();
  		
  		v[i] = l.head;
  	}
  	
  	ListNode *tmp = merge_k_sorted_lists(v);
  	
  	while(tmp != NULL) {
		cout << tmp->val;
		tmp = tmp->next;
		if(tmp != NULL) cout << "->";
	}
			
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

// TC: O(n * log(k)), where n = total #elements in all the lists.