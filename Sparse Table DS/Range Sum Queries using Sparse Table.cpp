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
	}
	
	void build(vi &a) {
		for(int i = 0; i < n; i++) mat[i][0] = a[i];
		
		for(int j = 1; j < m; j++) {
			for(int i = 0; i + (1 << j) <= n; i++) {
				mat[i][j] = mat[i][j - 1] + mat[i + (1 << (j - 1))][j - 1];
			}
		}
	}
	
	// l & r are 0-based indexed
	int query(int l, int r) {
		int res = 0; // to store the sum
		for(int j = m; j >= 0; j--) {
			if((1 << j) <= (r - l + 1)) {
				res += mat[l][j];
				l += (1 << j);
			}
		}
		
		return res;
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
  		cout << "Sum of element(s) in the range [" << l << ", " << r << "] = ";
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

Sum of element(s) in the range [4, 8] = 35
Sum of element(s) in the range [0, 9] = 55
Sum of element(s) in the range [3, 7] = 30
Sum of element(s) in the range [1, 8] = 44
Sum of element(s) in the range [5, 5] = 6

*/

// Time complexity of build() = O(n x m) = O(n x log2(n))
// Time complexity of query() = O(m) = O(log2(n)), as it is Range Sum Query.
// where n = size of input array.