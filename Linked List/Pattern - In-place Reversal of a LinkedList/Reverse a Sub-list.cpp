/*Problem Statement: Given the head of a LinkedList and two positions ‘k’ and ‘l’, reverse the 
                     LinkedList from position ‘k’ to ‘l’.
                     https://leetcode.com/problems/reverse-linked-list-ii/
*/

// Method 1

/*UNDERLYING CONCEPT: ---->
  # The problem follows the In-place Reversal of a LinkedList pattern. 
  # We can use a similar approach as discussed in Reverse a LinkedList. Here are the steps we need to 
    follow:
    1). Skip the first k-1 nodes, to reach the node at position k.
    2). Remember the node at position k-1 to be used later to connect with the reversed sub-list.
    3). Next, reverse the nodes from k to q using the same approach discussed in Reverse a LinkedList.
    4). Connect the k-1 and l+1 nodes to the reversed sub-list.
*/

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

node* reverseSubList(node* head, long long k, long long l) 
{
    if(k==l || !head || !head->next)
       return head;

    node *p=head;
    node *prev=nullptr;
    
    //after skipping 'k-1' nodes, pointer p will point to kᵗʰ node
    for(long long i=0; i<(k-1) && p!=nullptr; i++)
    {
       prev=p;
       p=p->next;
    }
    
    //we are interested in three parts of the LinkedList: 
    //part before index 'k', part between 'k' and 'l', and
    //the part after index 'l'

    //pOfSubList points to the node at index 'k' (1 based indexing) &
    //it also points the node that we will be processing
    node *pOfSubList=p; 
    //points previous node that we have processed
    node *prevOfSubList=prev; 
    
    //reverse nodes between 'k' and 'l'
    for(long long i=0; i<(l-k+1) && pOfSubList!=nullptr; i++)
    {
       node *next=pOfSubList->next;
       pOfSubList->next=prevOfSubList;
       prevOfSubList=pOfSubList;
       pOfSubList=next;
    }
    
    //connect with the first part
    //prev points to the (k-1)ᵗʰ node(last node of 1ˢᵗ part)
    if(prev!=nullptr)
       prev->next=prevOfSubList; 

    //the case when k=1 i.e., we are changing 
    //the first node (head) of the LinkedList
    else
       head=prevOfSubList; 
    
    //connect with the last part
    p->next=pOfSubList;

    return head;    
}

/*Time complexity: O(n), where ‘n’ is the total number of nodes in the LinkedList.
  Space complexity: O(1).
*/

/*****************************************************************************************************/

// Method 2 
// Ref: https://www.youtube.com/watch?v=ZS9jlUW5DoY&list=PL7JyMDSI2BfbQZQIFfD7Hep2e6kzUZd7L&index=18

// Crux of this method ===>
// Agar current par process karna hai to bas uske piche wale node par pahunch jao, kaam khatam.
// Translation: If you want to work on some node then just reach the node just prior to it and 
//              the work is done.

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

// Here it is assumed 1 =< L =< R =< length of list. 
ListNode* reverse_from_L_to_R(ListNode *head, int L, int R) {
  if(L == R or head == NULL or head->next == NULL) {
    return head;
  }
  
  ListNode *new_node = new ListNode;
  new_node->val = 0;
  new_node->next = head;
  
  head = new_node;
  ListNode *tmp = head;
  
  while(tmp != NULL) {
    if(L == 1) {
      ListNode *prv = NULL, *cur = tmp->next, *nxt = tmp->next;
      ListNode *end_of_sublist = tmp->next;
      
      while(R > 0) {
        nxt = nxt->next;
        cur->next = prv;
        prv = cur;
        cur = nxt;
        R--;
      }
      
      tmp->next = prv;
      end_of_sublist->next = nxt;
    }
    
    tmp = tmp->next;
    L--;
    R--;
  }
  
  return head->next;  
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
    
    int L, R; cin >> L >> R;
    ListNode *tmp = reverse_from_L_to_R(l.head, L, R);
    
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

// TC: O(n)
// CS: O(1)