/*Problem Statement: Given a singly linked list, reverse the nodes of the linked list k at a time and 
                     return the head of the modified list.
                     k is a positive integer and is less than or equal to the length of the linked list. 
                     If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it 
                     too.
                     Example: Given this linked list: 1->2->3->4->5
                              For k = 2, you should return: 2->1->4->3->5
                              For k = 3, you should return: 3->2->1->5->4
                              
                     NOTE: # Only constant extra memory is allowed.
                           # You may not alter the values in the list’s nodes, only nodes itself may 
                             be changed. 
*/

/*The problem follows the In-place Reversal of a LinkedList pattern and is quite similar to Reverse 
  a Sub-list. The only difference is that we have to reverse all the sub-lists. We can use the same 
  approach, starting with the first sub-list from 1 to k and keep reversing all the sublists of 
  size ‘k’.
*/

/*
 * Definition for singly-linked list.
 * struct node {
 *     int val;
 *     node *next;
 *     node() : val(0), next(nullptr) {}
 *     node(int x) : val(x), next(nullptr) {}
 *     node(int x, Node *next) : val(x), next(next) {}
 * };
 */

//RECURSIVE IMPLEMENTATION

node* reverseEveryKNodes(node* head, long long k)
{
	node *p=head;
	node *prev=nullptr;
	node *next=nullptr;
	long long count=0;
    
    //reverse first k nodes of the linked list 
	while(p!=nullptr && count<k)
	{
	   next=p->next;
	   p->next=prev;
	   prev=p;
	   p=next
	}
    
    //next is now a pointer to (k+1)ᵗʰ node.
    //Recursively call for the list starting from next  
    //and make rest of the list as next of first node
	if(!next)
	   head->next=reverseEveryKNodes(next, k);
    
    //prev is new head of the input list 
    return prev;
}

/*Time complexity: O(n), where ‘n’ is the total number of nodes in the LinkedList.
  Space complexity: O(1),
  Space Complexity of internal call stack(due to recursion overhead)-------->
   # For every k nodes, we are supposed to recursively call the function for once. So the total number 
     of recursive calls are (n/k).
   # Within each function, we are using a couple of pointers, but they are constant cost. 
     Thus, the total space complexity is O((n/k)*(some constant)) = O(n/k).
*/

*****************************************************************************************************************

//ITERATIVE IMPLEMENTATION

/*ALGORITHM ------>
1). Bring p upto the node from where we have to start changing links,
    prev is pointing at the node just behind the node being pointed by p.
2). p and prev are now on hold, from here pOfSubList & prevOfSubList takes the lead,
    the internal links for group of k nodes will be changed by pOfSubList & prevOfSubList.
    p & prev will connect the k nodes sublist to it's previous part and next part(but right now both are on 
    hold).
3). pOfSubList & prevOfSubList has done their work & changed the internal links.
    Now, pOfSubList is either pointing to null or (k+1)ᵗʰ node, while
    prevOfSubList is just right behind pOfSubList.
4). prev will help in establishing a link for the sublist of k nodes with its's previous part.
5). Similary p will help in establishing a link for the sublist of k nodes with its's next part.
6). Now, to start the whole process again for the next group of k nodes the values of p & prev are updated,
    prev is updated by p & p points to p->next.
7). And the history repeats until pOfSubList reaches end of Linked List. 😈 😈 😈
*/

node* reverseEveryKNodes(node* head, long long k) 
{
    if(k<=1 || !head || !head->next)
       return head;

    node *p=head;
    node *prev=nullptr;
    
    while(true)
    {
       //pOfSubList points to the node at index 'k' (1 based indexing) &
       //it also points the node that we will be processing
       node *pOfSubList=p; 
       //points previous node that we have processed
       node *prevOfSubList=prev; 
    
       //reverse a group of 'k' nodes
       for(long long i=0; i<k && pOfSubList!=nullptr; i++)
       {
	       node *next=pOfSubList->next;
	       pOfSubList->next=prevOfSubList;
	       prevOfSubList=pOfSubList;
	       pOfSubList=next;
       }
    
	   //connect with the previous part
	   //prev points to the (k-1)ᵗʰ node(last node of 1ˢᵗ part)
	   if(prev!=nullptr)
	      prev->next=prevOfSubList; 

       //the case when k=1 i.e., we are changing 
       //the first node (head) of the LinkedList
       else
          head=prevOfSubList; 
    
       //connect with the next part
       p->next=pOfSubList;

       //break if the loop reached the end of linked list
       if(!pOfSubList) 
          break;
       
       //prepare for the next sub-list
       prev=p;
       p=p->next;
   }
    
   return head;    
}

/*Time complexity: O(n), where ‘n’ is the total number of nodes in the LinkedList.
  Space complexity: O(1).
*/

/*****************************************************************************************************************/

/*If the same question would have asked that if in the end, you are left with a sub-list with less than 
 ‘k’ elements, DON'T reverse it.
*/

//Just add the below fⁿ at the start of while loop

/*
  node *it=p;
  long long count=0; 
  for(long long i=0; i<k && it!=nullptr; i++)
  {
     count++;
     it=it->next; 
  }
  if(count!=k) break; 
*/

/****************************************************************************************************/

// Ref: https://www.youtube.com/watch?v=oyZzgEy5WAQ&list=PL7JyMDSI2BfbQZQIFfD7Hep2e6kzUZd7L&index=7
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

ListNode* k_reverse_list(ListNode *head, int k) {
  ListNode *prevtail = head, *currhead = head;
  ListNode *prv = NULL, *cur = head, *nxt = head;
  bool is_start = true;
  
  while(nxt != NULL) {
    currhead = cur;
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

/*****************************************************************************************************/

// Ref: https://www.youtube.com/watch?v=oyZzgEy5WAQ&list=PL7JyMDSI2BfbQZQIFfD7Hep2e6kzUZd7L&index=7
// RECURSIVE APPROACH

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

ListNode* k_reverse_list(ListNode *head, int k) {
    ListNode *prv = NULL, *cur = head, *nxt = head;
    int cnt = 0;
    
    while(cnt < k and nxt) {
        nxt = nxt->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
        cnt += 1;
    }
    
    if(nxt != NULL) {
        head->next = k_reverse_list(nxt, k);
    }
    
    return prv;
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