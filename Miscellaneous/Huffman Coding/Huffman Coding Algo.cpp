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
#define vset(v, n, val) v.clear(); v.resize(n, val)

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

// Huffman tree (which in turn is a binary tree only) node structure
struct node {
	// data members ===>
	char ch;
	int freq;
	node *left, *right;
	
	// member functions ===>
	node() {
		ch = '\0';
		freq = 0;
		left = right = nullptr;
	}
	
	node(char ch, int freq) {
		this->ch = ch;
		this->freq = freq;
		left = right = nullptr;
	}
	
	node(char ch, int freq, struct node *left, struct node *right) {
		this->ch = ch;
		this->freq = freq;
		this->left = left;
		this->right = right;
	}
};

// comparison function to be used to define the order in the heap
struct comparator {
	// the lowest frequency character has highest priority 
	bool operator() (const struct node *n1, const struct node *n2) {
		return n1->freq > n2->freq;
	}
};

// structure for Huffman Coding algorithm implementation
struct huffman_coding {
	// data members ===>
	
	// text = string which is to be encoded
	// cnt = map to store the frequency of all characters in text
	// mn_heap = priority queue to store the huffman tree nodes while tree build
	// encoding = map to store the huffman encoding of each character in text
	// root = pointer to the root node of the huffman tree build upon the string text
	// encoded_text = string which stores the encoding of text
	
	string text;
	map<char, int> cnt;
	priority_queue<node*, vector<node*>, comparator> mn_heap;
	map<char, string> encoding;
	struct node *root;
	string encoded_text;
	
	// member functions ===>
	
	// parameterized constructor
	huffman_coding(string text) {
		this->text = text;
		cnt.clear();
		while(!mn_heap.empty()) mn_heap.pop();
		encoding.clear();
		root = nullptr;
		encoded_text = "";
	}
	
	// function to build up the huffman tree (which is a binary tree)
	void build_huffman_tree() {
		// size of the input text
		int n = (int)text.size();
		
		// check for empty string
		if(n == 0) return;
		
		for(int i = 0; i < n; i++) {
			cnt[text[i]] += 1;
	    }
	   
	    // create a leaf node for each character and add it to the priority queue
	    for(auto x: cnt) {
	    	struct node *new_node = new node(x.F, x.S);
	    	mn_heap.push(new_node);
	    }
	    
	    // loop till there are more than one nodes in the queue
	    while(mn_heap.size() > 1) {
	    	// remove the two nodes of the highest priority (the lowest frequency) from the queue
	    	struct node *n1 = mn_heap.top();
	    	mn_heap.pop();
	    	
	    	struct node *n2 = mn_heap.top();
	    	mn_heap.pop();
	    	
	    	// create a new internal node with these two nodes as children and with a frequency
	    	// equal to the sum of the two nodes' frequencies & also add new node to the queue.
	    	struct node *new_node = new node('\0', n1->freq + n2->freq, n1, n2);
	    	mn_heap.push(new_node);
	    }
	    
	    root = mn_heap.top();
	    
	    // traverse the huffman tree and store huffman codes for each character
	    encode_text(root, "");
	    print_encodings();
	    print_encoded_text();
	    print_decoded_text();
	}
	
	bool is_leaf(struct node *it) {
		return (it->left == nullptr) and (it->right == nullptr);
	}
	
	void encode_text(struct node *it, string code) {
		// base case
		if(it == nullptr) return;
		
		if(is_leaf(it)) {
			encoding[it->ch] = (!code.empty()) ? code : "0";
			return;
		}
		
		encode_text(it->left, code + "0");
		encode_text(it->right, code + "1");
	}
	
	void print_encodings() {
		cout << "Huffman codes for the characters are :\n";
		for(auto x: encoding) cout << x.F << " " << x.S << "\n";
		cout << "\n";
	}
	
	void print_encoded_text() {
		cout << "Encoded text is :\n";
		for(int i = 0; i < (int)text.size(); i++) {
			encoded_text += encoding[text[i]];
		}
	
		cout << encoded_text << "\n\n";
	}
	
	void print_decoded_text() {
		cout << "Decoded text is :\n";
		
		// special case: for input like a, aa, aaa, etc.
		if(is_leaf(root)) {
			for(int i = 0; i < root->freq; i++) cout << root->ch;
			cout << "\n";
			return;
		}
		
		int idx = 0;
		
		while(idx < (int)encoded_text.size()) {
			decode_helper(root, idx);
		}
	}
	
	void decode_helper(struct node *it, int &idx) {
		if(it == nullptr) return;
		
		if(is_leaf(it)) {
			cout << it->ch;
			return;
		}
		
		if(encoded_text[idx] == '0') idx += 1, decode_helper(it->left, idx);
		else idx += 1, decode_helper(it->right, idx);
	}
};

void solve()
{
  	string text;
  	getline(cin, text);
  	  	
  	struct huffman_coding hc(text);
  	hc.build_huffman_tree();
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