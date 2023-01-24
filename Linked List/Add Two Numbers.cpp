// Problem: https://leetcode.com/problems/add-two-numbers/

// Ref: https://www.youtube.com/watch?v=fThpzrA0vGc&list=PL7JyMDSI2BfbQZQIFfD7Hep2e6kzUZd7L&index=11

/************************************************************************************************************************************************************/

// Method 1 (Using Auxuliary Space)

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

ListNode* reverse(ListNode *head) {
	ListNode *prv = NULL, *cur = head, *nxt = head;
	while(nxt != NULL) {
		nxt = nxt->next;
		cur->next = prv;
		prv = cur;
		cur = nxt;
	}
	
	return prv;
}

ListNode* add_2_numbers(ListNode *h1, ListNode *h2) {
	ListNode *tmp_head = new ListNode;
	tmp_head->val = -1;
	tmp_head->next = NULL;
	
	ListNode *tmp = tmp_head;
	int carry = 0;
	int nodes = 0;
	
	while(h1 or h2 or carry) {
		int num = 0;
		if(h1) num += h1->val;
		if(h2) num += h2->val;
		if(carry) num += carry;
		
		ListNode *new_node = new ListNode;
		new_node->val = num % 10;
		new_node->next = NULL;
		
		tmp->next = new_node;
		tmp = new_node;
		nodes += 1;
		
		carry = (num / 10);
		if(h1) h1 = h1->next;
		if(h2) h2 = h2->next;
	}
	
	tmp = reverse(tmp_head->next);
	if(nodes > 1) while(tmp and tmp->val == 0) tmp = tmp->next;
	tmp = reverse(tmp);
	
	return tmp;
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
  	
  	ListNode *tmp = add_2_numbers(l1.head, l2.head);
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

// Time Complexity: O(m + n), where m and n are number of nodes in first and second lists respectively. 
//                  The lists needs to be traversed only once.

// Space Complexity: O(m + n). 
// 					A temporary linked list is needed to store the output number.

/************************************************************************************************************************************************************/

// Method 2 (Using less space than Method 1)

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

ListNode* reverse(ListNode *head) {
	ListNode *prv = NULL, *cur = head, *nxt = head;
	while(nxt != NULL) {
		nxt = nxt->next;
		cur->next = prv;
		prv = cur;
		cur = nxt;
	}
	
	return prv;
}

int cnt_nodes(ListNode *head) {
	int res = 0;
	while(head != NULL) {
		res += 1;
		head = head->next;
	}
	
	return res;
}

ListNode* add_2_numbers(ListNode *h1, ListNode *h2) {
	int carry = 0;
	int total = 0;
	int cnt1 = cnt_nodes(h1);
	int cnt2 = cnt_nodes(h2);
	
	// to use as less space as we can
	if(cnt2 > cnt1) {
		swap(cnt1, cnt2);
		swap(h1, h2);
	}
	
	ListNode *head = h1, *tmp = h1;
	
	while(cnt1 > 0 or cnt2 > 0 or carry) {
		int num = 0;
		if(cnt1 > 0) num += h1->val;
		if(cnt2 > 0) num += h2->val;
		if(carry) num += carry;
		
		if(cnt1 > 0) {
			tmp->val = num % 10;
			if(tmp->next) tmp = tmp->next;
		}
		
		else {
			ListNode *new_node = new ListNode;
			new_node->val = num % 10;
			new_node->next = NULL;
			tmp->next = new_node;
			tmp = new_node;
		}
		
		total += 1;
		
		carry = (num / 10);
		if(cnt1 > 0) h1 = h1->next, cnt1 -= 1;
		if(cnt2 > 0) h2 = h2->next, cnt2 -= 1;
	}
	
	tmp = reverse(head);
	if(total > 1) while(tmp and tmp->val == 0) tmp = tmp->next;
	tmp = reverse(tmp);
	
	return tmp;
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
  	
  	l1.head = add_2_numbers(l1.head, l2.head);
  	l1.display();
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

/************************************************************************************************************************************************************/

// METHOD - 3 
// Same as METHOD - 1, just slightly different implementation.

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

ListNode* add_2_numbers(ListNode *l1, ListNode *l2) {
	ListNode *head = l1, *cur = l1;
    int carry = 0;
        
    while(l1 and l2) {
        carry += (l1->val) + (l2->val);
        cur->val = carry % 10;
        carry /= 10;
        l1 = l1->next;
        l2 = l2->next;
        if(l1) cur->next = l1, cur = l1;
        else if(l2) cur->next = l2, cur = l2;
        else if(carry != 0) {
            ListNode *tmp = new ListNode();
            cur->next = tmp;
            cur = tmp;
        }
    }
        
    while(l1) {
        carry += (l1->val);
        cur->val = carry % 10;
        carry /= 10;
        l1 = l1->next;
        if(l1) cur->next = l1, cur = l1;
        else {
            if(carry == 0) cur->next = l1, cur = l1;
            else {
                ListNode *tmp = new ListNode();
                cur->next = tmp;
                cur = tmp;
            }
        }
    }
        
    while(l2) {
        carry += (l2->val);
        cur->val = carry % 10;
        carry /= 10;
        l2 = l2->next;
        if(l2) cur->next = l2, cur = l2;
        else {
            if(carry == 0) cur->next = l2, cur = l2;
            else {
                ListNode *tmp = new ListNode();
                cur->next = tmp;
                cur = tmp;
            }
        }
    }
        
    while(carry) {
        cur->val = carry % 10;
        carry /= 10;
        if(carry != 0) {
            ListNode *tmp = new ListNode();
            cur->next = tmp;
            cur = tmp;
        }
    }
        
    return head;
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
  	
  	l1.head = add_2_numbers(l1.head, l2.head);
  	l1.display();
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

/************************************************************************************************************************************************************/

// METHOD - 4
// Same as METHOD - 1, just slightly different implementation.

// https://pastebin.com/GY7nDi0V