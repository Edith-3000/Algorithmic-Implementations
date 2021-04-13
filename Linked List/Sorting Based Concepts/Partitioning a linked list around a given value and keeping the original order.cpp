// Problem: https://www.interviewbit.com/problems/partition-list/
// Ref: https://www.youtube.com/watch?v=yLL168YObrI&list=PL7JyMDSI2BfbQZQIFfD7Hep2e6kzUZd7L&index=14
/****************************************************************************************************/

// Method 1 

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

ListNode* partition_list(ListNode *head, int x) {
	ListNode *hs = NULL, *ts = NULL;
	ListNode *hg = NULL, *tg = NULL;
	
	while(head != NULL) {
		if(head->val < x) {
			if(hs == NULL) {
				hs = head;
				ts = head;
			}
			
			else {
				ts->next = head;
				ts = head;
			}
		}
		
		else {
			if(hg == NULL) {
				hg = head;
				tg = head;
			}
			
			else {
				tg->next = head;
				tg = head;
			}
		}
		
		head = head->next;
	}
	
	if(hs == NULL) return hg;
	if(hg == NULL) return hs;
	
	ts->next = hg;
	tg->next = NULL;
	
	return hs;
}

void solve()
{
  	int n, x; cin >> n >> x;
  	LinkedList l;
  	
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		l.insert(x);
  	}
  	
  	l.display();
  	ListNode *tmp = partition_list(l.head, x);
  	l.display();
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

/*************************************************************************************************/

// Method 2 (less lines of codes than Method 2 :))

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

ListNode* partition_list(ListNode *head, int x) {
	ListNode *hs = new ListNode;
	hs->val = 0; hs->next = NULL;
	ListNode *ts = hs;
	
	ListNode *hg = new ListNode;
	hg->val = 0; hg->next = NULL;
	ListNode *tg = hg;
	
	while(head != NULL) {
		if(head->val < x) {
			ts->next = head;
			ts = head;
		}
		
		else {
			tg->next = head;
			tg = head;
		}
		
		head = head->next;
	}
	
	ts->next = hg->next;
	tg->next = NULL;
	
	return hs->next;
}

void solve()
{
  	int n, x; cin >> n >> x;
  	LinkedList l;
  	
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		l.insert(x);
  	}
  	
  	l.display();
  	ListNode *tmp = partition_list(l.head, x);
  	l.display();
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