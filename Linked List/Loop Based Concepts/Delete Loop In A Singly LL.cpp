// Problem: https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
/******************************************************************************************************/

// Method used in this can also be used ===>
// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

// This method makes use of Floyd's Cycle finding algorithm.

// Very beautiful explanation of O(n) time complexity of this approach ===>
// https://stackoverflow.com/a/47203425

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

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

// function to return the node pointer where the cycle begins. 
// if there is no cycle, return NULL.
ListNode* find_first_cycle_node(ListNode *head) {
	// If list is empty or has only one node without loop
	if(head == NULL or head->next == NULL) {
		return NULL;
	}
	
	ListNode *slow = head, *fast = head;
	
	// Search for loop using slow and fast pointers
	while(fast) {
		slow = slow->next;
		fast = fast->next;
		if(fast == NULL) return NULL;
		fast = fast->next;
		if(slow == fast) break;
	} 
	
	// If loop does not exist
	if(slow != fast) return NULL;
	
	// If loop exists. Start slow from head and fast from meeting point.
	slow = head;
	while(slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	
	return slow;
}

void delete_loop(ListNode *head) {
	ListNode *res = find_first_cycle_node(head);

	// no loop present
	if(res == NULL) return;

	bool seen = 0;
    ListNode *tmp = head;
            
    while(tmp) {
    	if(seen and tmp->next == res) {
            tmp->next = NULL;
            break;
        }
                
        else {
            if(tmp == res) seen = 1;
            tmp = tmp->next;
        }
    } 
}

void solve()
{
  	int n; cin >> n;
  	LinkedList l;
  	
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		l.insert(x);
  	}
  	
  	l.tail->next = l.head->next->next;
  	delete_loop(l.head);
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