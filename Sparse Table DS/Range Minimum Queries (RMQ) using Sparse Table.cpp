#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
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

struct sparse_table {
	// data members
	int n, m;
	vvi mat; // 2D matrix
	// to store the power of 2 such that (1 << p2[i]) <= i 
	// log2 function could be used also but it's slow & lead to TLE
	vi p2; 
	
	// member functions
	void init(int _n) {
		n = _n;
		m = ceil(log2(n)) + 1;
		mat.resize(n);
		for(int i = 0; i < n; i++) mat[i].resize(m);
		
		p2.resize(n+1);
		for(int i = 2; i <= n; i++) {
			// log2(n) = log2(n/2) + 1
			p2[i] = p2[i/2] + 1;
		}
	}
	
	void build(vi &a) {
		for(int i = 0; i < n; i++) mat[i][0] = a[i];
		
		for(int j = 1; j < m; j++) {
			for(int i = 0; i + (1 << j) <= n; i++) {
				mat[i][j] = min(mat[i][j - 1], mat[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	
	// l & r are 0-based indexed
	int query(int l, int r) {
		int pw = p2[r - l];
		return min(mat[l][pw], mat[r - (1 << pw) + 1][pw]);
	} 
};

void solve()
{
  	vi a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  	int n = a.size(); 
  	
  	sparse_table st;
  	st.init(n);
  	st.build(a);
  	
  	// #queries
  	int q; cin >> q;
  	for(int i = 1; i <= q; i++) {
  		int l, r; cin >> l >> r; // use 0-based indexing
  		cout << "Minimum element in the range [" << l << ", " << r << "] = ";
  		cout << st.query(l, r) << "\n";
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

/*

Sample i/p ---->

5
4 8
0 9
3 7
1 8
5 5

Sample o/p ---->

Minimum element in the range [4, 8] = 5
Minimum element in the range [0, 9] = 1
Minimum element in the range [3, 7] = 4
Minimum element in the range [1, 8] = 2
Minimum element in the range [5, 5] = 6

*/

// Time complexity of build() = O(n x m) = O(n x log2(n))
// Time complexity of query() = O(1), as it is Range Minimum Query (idempotent function).
// where n = size of input array.