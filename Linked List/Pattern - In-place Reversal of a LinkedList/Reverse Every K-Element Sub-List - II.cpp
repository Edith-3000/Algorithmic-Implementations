// Prob: Given a singly linked list, reverse the nodes of the linked list k at a time and return the head
//       of the modified list. k is a positive integer and is less than or equal to the length of the 
//       linked list. If, in the end, you are left with a sub-list with less than ‘k’ elements, DON'T 
//       reverse it 

// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

/******************************************************************************************************************************************************************/

// ITERATIVE APPROACH

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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
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

int cnt_nodes(ListNode *head) {
	// base case
	if(head == NULL) return 0;
	
	int res = 0;
	ListNode *tmp = head;
	
	while(tmp != NULL) {
		res += 1;
		tmp = tmp->next;
	}
	
	return res;
}

ListNode* k_reverse_list(ListNode *head, int k) {
    // base case(s)
    if(head == NULL or k == 1) return head;
	
	int len = cnt_nodes(head);
	int grps = len / k;
	
    ListNode *prevtail = head, *currhead = head;
    ListNode *prv = NULL, *cur = head, *nxt = head;
    bool is_start = true;
  
    while(nxt != NULL and grps > 0) {
        currhead = nxt;
        prv = NULL;
        int cnt = 0;
    
        while(cnt < k and nxt) {
            nxt = nxt->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
            cnt += 1;
        }
    
        if(is_start) {
            head = prv;
            is_start = false;
        }
    
        else {
            prevtail->next = prv;
            prevtail = currhead;
        }
        
        grps -= 1;
        
        if(grps == 0) {
        	prevtail->next = nxt;
        }
    }
    
    return head; 
}

void solve()
{
    int n, k; cin >> n >> k;
    LinkedList l;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        l.insert(x);
    }
    
    l.display();
    l.head = k_reverse_list(l.head, k); 
    l.display();
  
    cout << "\n";
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

/******************************************************************************************************************************************************************/

// RECURSIVE APPROACH
// https://leetcode.com/problems/reverse-nodes-in-k-group/solutions/3118913/using-recursion/