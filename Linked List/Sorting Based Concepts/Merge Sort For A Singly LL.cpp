// Problem: https://www.interviewbit.com/problems/sort-list/
//          https://leetcode.com/problems/sort-list/

// Ref: https://www.youtube.com/watch?v=KEoYzfOUF3o&list=PL7JyMDSI2BfbQZQIFfD7Hep2e6kzUZd7L&index=16
/***************************************************************************************************************************************************/

/* # NOTE: The below algorithm is similar to the Merge Sort.

   # Lets look at merge sort. Traverse the linked list to find the mid point of the list. 
     Now sort the first half and second half separatly by calling the function on them. 
     Then merge the 2 sorted lists into a single list.
*/

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

ListNode* find_mid(ListNode *head) {
	ListNode *fast = head;
	ListNode *slow = head;
	
	while(fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow;
}

ListNode* merge_2_sorted_lists(ListNode *t1, ListNode *t2) {
	if(t1 == NULL) return t2;
	if(t2 == NULL) return t1;
	
	ListNode *head;
	
	if(t1->val <= t2->val) {
		head = t1;
		t1 = t1->next;
	}
	
	else {
		head = t2;
		t2 = t2->next;
	}
	
	ListNode *tmp = head;
	
	while(t1 and t2) {
		if(t1->val <= t2->val) {
			tmp->next = t1;
			t1 = t1->next;
			tmp = tmp->next;
	    }
	    
	    else {
	    	tmp->next = t2;
			t2 = t2->next;
			tmp = tmp->next;
	    }
	}
	
	if(t1) tmp->next = t1;
	if(t2) tmp->next = t2;
	
	return head;
}

ListNode* sort_list(ListNode *head) {
	// base case(s)
	if(!head or !head->next) return head;
	
	ListNode *mid = find_mid(head);
	ListNode *tmp = mid->next;
	
	mid->next = NULL;
	
	ListNode *t1 = sort_list(head);
	ListNode *t2 = sort_list(tmp);
	
	head = merge_2_sorted_lists(t1, t2);
	return head;
}

void solve()
{
  	int n; cin >> n;
  	LinkedList l;
  	
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		l.insert(x);
  	}
  	  	
  	l.display();
  	ListNode *tmp = sort_list(l.head);
  	
  	while(tmp != NULL) {
		cout << tmp->val;
		tmp = tmp->next;
		if(tmp != NULL) cout << "->";
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

// Time Complexity: O(n x log(n))
// Space Complexity (Recursive call stack): O(log(n))