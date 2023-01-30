// Problem: https://leetcode.com/problems/intersection-of-two-linked-lists/

// Ref: https://www.youtube.com/watch?v=u4FWXfgS8jw&list=PLgUwDviBIf0r47RKH7fdWN54AbWFgGuii&index=7

/******************************************************************************************************************************************************************/

// NOTE: Brute forces techniques have been discussed in the reference video, here the most optimal 
//       approach is written.

/******************************************************************************************************************************************************************/

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

ListNode* intersect(ListNode *head1, ListNode *head2) {
	if(head1 == NULL or head2 == NULL) return NULL;
	
	ListNode *h1 = head1, *h2 = head2;
	
	while(h1 != h2) {
		h1 = (h1 == NULL) ? head2 : h1->next;
		h2 = (h2 == NULL) ? head1 : h2->next;
	}
	
	return h1; // or h2
}

void solve()
{
  	int n, m; cin >> n >> m;
  	LinkedList l1, l2;
  	
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		l1.insert(x);
  	}
  	
  	for(int i = 0; i < m; i++) {
  		int x; cin >> x;
  		l2.insert(x);
  	}
  	
  	l1.display();
  	l2.display();
  	
  	ListNode *res = intersect(l1.head, l2.head);
  	if(res == NULL) cout << "No intersetion.\n"; 
  	else cout << res->val << "\n";
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