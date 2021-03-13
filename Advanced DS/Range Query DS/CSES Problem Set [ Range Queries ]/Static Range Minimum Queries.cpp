// Method 1 (Using segment tree constructed by me)

// Problem: Static Range Minimum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1647
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 13-03-2021 09:44:05 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

int n, q;
vi v, t;

int query_seg_tree(int tl, int tr, int ql, int qr, int ind) {
	if(ql <= tl and qr >= tr) return t[ind];
	if(tr < ql || tl > qr) return INT_MAX;
	
	int mid = (tl + tr) / 2;
	int left = query_seg_tree(tl, mid, ql, qr, 2 * ind);
	int right = query_seg_tree(mid + 1, tr, ql, qr, 2 * ind + 1);
	
	return min(left, right);
}

void build_seg_tree(int tl, int tr, int ind) {
	if(tl == tr) {
		t[ind] = v[tl];
		return;
	}
	
	int mid = (tl + tr) / 2;
	build_seg_tree(tl, mid, 2 * ind);
	build_seg_tree(mid + 1, tr, 2 * ind + 1);
	
	t[ind] = min(t[2 * ind], t[2 * ind + 1]);
	return;
}

void solve()
{
  	cin >> n >> q;
  	v.resize(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	t.resize(4 * n + 1);
  	build_seg_tree(0, n - 1, 1);
  	
  	while(q--) {
  		int ql, qr; cin >> ql >> qr;
  		ql--, qr--;
  		cout << query_seg_tree(0, n - 1, ql, qr, 1) << "\n";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

/********************************************************************************************************/

// Method 2 (Using segment tree library contributed by Kartik Arora)

// Problem: Static Range Minimum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1647
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 13-03-2021 09:44:05 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

#define left(i) (2*i + 1)
#define right(i) (2*i + 2)
#define parent(i) ((i-1)/2)
#include <vector>

template<class T>
class SegmentTree
{
    public:
        //tree constructors.
        SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
        SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2));
        
        //query the range l to r, 0 based array indexing.
        T query(int l, int r);
        
        //update the element at index idx to val.
        void update(int idx, T val);
        ///TODO lazy propagation
    private:
        //represents the segment tree.
        T *tree;
    
        //builds the segment tree.
        void buildTree(std::vector<T> data);
        
        //size of the segment tree array.
        int segTreeSize;
    
        //extra nodes must be added to array to make its size a power of 2
        //this is the value to be filled for the those nodes.
        T valueForExtraNodes;
    
        //specifies how to combine child node results to form parent node result.
        T (*combine)(T obj1, T obj2);
    
        //used to calculate the size of array needed to store the tree.
        int calculateSize(int n);
    
        //helps to solve a range query.
        T queryHelper(int l,int r, int st, int ed, int node);
};

template<class T> SegmentTree<T>::SegmentTree(std::vector<T> data,
                                                T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(data.size());
   buildTree(data);
}

template<class T> SegmentTree<T>::SegmentTree(T ar[], int n,
                                            T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   valueForExtraNodes = value;
   segTreeSize = calculateSize(n);

   std::vector<T> data;
   for(int i = 0; i < n; i++)
         data.push_back(ar[i]);

   buildTree(data);
}


template<class T> int SegmentTree<T>::calculateSize(int n)
{
    int pow2 = 1;
    while( pow2 < n)
    {
        pow2 = pow2 << 1;
    }
    return 2*pow2 - 1;
}

template<class T> T SegmentTree<T>::query(int l, int r)
{
    int st = 0, ed = segTreeSize/2;
    return queryHelper(l, r, st, ed, 0);
}

template<class T> T SegmentTree<T>::queryHelper(int l,int r, int st, int ed, int node)
{
    if( (r < st) || (l > ed) || (l > r) )
        return valueForExtraNodes;
    if(st >= l && ed <= r)
        return tree[node];
    T leftVal = queryHelper(l, r, st, (st + ed)/2, left(node));
    T rightVal = queryHelper(l, r, (st+ed)/2 + 1, ed, right(node));
    return combine(leftVal, rightVal);
}

template<class T> void SegmentTree<T>::buildTree(std::vector<T> data)
{
   int n = data.size();
   tree = new T[segTreeSize];
   int extraNodes = (segTreeSize/2 + 1) - n;
   for(int i = segTreeSize - 1; i >= 0; i--)
   {
       if(extraNodes>0)
           {
               tree[i] = valueForExtraNodes;
               extraNodes--;
           }
       else if(n>0)
           {
               tree[i] = data[n-1];
               n--;
           }
       else
           tree[i] = combine(tree[left(i)], tree[right(i)]);
   }
}

template<class T> void SegmentTree<T>::update(int idx, T val)
{
    int segTreeIdx = (segTreeSize/2) + idx;
    tree[segTreeIdx] = val;
    while(parent(segTreeIdx) >= 0)
    {
        segTreeIdx = parent(segTreeIdx);
        if(right(segTreeIdx) < segTreeSize)
          tree[segTreeIdx] = combine(tree[left(segTreeIdx)], tree[right(segTreeIdx)]);
        if(segTreeIdx == 0)
            break;
    }
}

int n, q;
vi v;

int mini(int x, int y) {
  return min(x, y);
}

void solve()
{
    cin >> n >> q;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    SegmentTree<int> mySegmentTree(v, INT_MAX, mini);
    
    while(q--) {
      int ql, qr; cin >> ql >> qr;
      ql--, qr--;
      cout << mySegmentTree.query(ql, qr) << "\n";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}