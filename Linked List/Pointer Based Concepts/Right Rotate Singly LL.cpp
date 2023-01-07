// Problem: https://www.interviewbit.com/problems/rotate-list/
//          https://leetcode.com/problems/rotate-list/

// Ref: https://takeuforward.org/data-structure/rotate-a-linked-list/
/*************************************************************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())

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
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

/*******************************************************************************************************************************************************************/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

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

ListNode* right_rotate(ListNode *head, int k) {
    if(!head or !head->next or k == 0) {
        return head;
    }
    
    ListNode *tmp = head;
    int len = 1;
    
    while(tmp->next) {
        len += 1;
        tmp = tmp->next;
    }
    
    tmp->next = head;
    k %= len;
    k = len - k;
    
    while(k > 0) {
        tmp = tmp->next;
        k -= 1;
    }
    
    head = tmp->next;
    tmp->next = NULL;
    
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
    l.head = right_rotate(l.head, k); 
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