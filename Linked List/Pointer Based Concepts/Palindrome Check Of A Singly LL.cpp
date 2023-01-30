// Prob: https://leetcode.com/problems/palindrome-linked-list/description/

// Ref: https://www.youtube.com/watch?v=J0dLiObC_0E&list=PL7JyMDSI2BfbQZQIFfD7Hep2e6kzUZd7L&index=1
//      https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/

/*********************************************************************************************************************************************************************/

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
	if(head == NULL) return NULL;

	ListNode *fast = head;
	ListNode *slow = head;
	
	while(fast->next != NULL and fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	
	return slow;
}

ListNode* reverse(ListNode *head) {
	ListNode *prv = NULL;
	ListNode *cur = head;
	ListNode *nxt = head;
	
	while(nxt != NULL) {
		nxt = nxt->next;
		cur->next = prv;
		prv = cur;
		cur = nxt;
	}
	
	return prv;
}

bool is_palindrome(ListNode *head) {
	if((head == NULL) or (head->next == NULL)) return 1;

	ListNode *middle = find_mid(head);
	ListNode *tmp = middle->next;
	middle->next = NULL;
	tmp = reverse(tmp);
	
	while(head != NULL and tmp != NULL) {
		if(head->val != tmp->val) return 0;
		head = head->next;
		tmp = tmp->next;
	}
	
	return 1;
}

void solve()
{
  	int n; cin >> n;
  	LinkedList l;
  	
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		l.insert(x);
  	}
  	
  	if(is_palindrome(l.head)) cout << "YES\n";
  	else cout << "NO\n";
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

// TC: O(n), where n = #elements in the linked list
// SC: O(1)