// USING FENWICK TREE(BIT) + BINARY SEARCH [TC = O(q x (log2(n))^2]

// Problem: D. Multiset
// Contest: Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1354/problem/D
// Memory Limit: 28 MB
// Time Limit: 1500 ms
// Parsed on: 16-01-2021 16:24:28 IST (UTC+05:30)
// Author: kapil_choudhary

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

vi bit;
int n, q;

void bit_update(int i, int val) {
	while(i <= n) {
		bit[i] += val;
		i += (i & -i);
	}
}

int bit_query(int i) {
	int res = 0;
	while(i > 0) {
		res += bit[i];
		i -= (i & -i);
	}
	
	return res;
}

void solve()
{
  	cin >> n >> q;
  	bit.assign(n + 1, 0);
  	for(int i = 1; i <= n; i++) {
  		int x; cin >> x;
  		bit_update(x, 1);
  	}
  	
  	while(q--) {
  		int k; cin >> k;
  		if(k > 0) bit_update(k, 1);
  		else {
  			k = abs(k);
  			int low = 1, high = n;
  			while(low < high) {
  				int mid = low + ((high - low) >> 1);
  				int val = bit_query(mid);
  				if(k <= val) high = mid;
  				else low = mid + 1;
  			}
  			
  			bit_update(low, -1);
  		}
  	}
  	
  	int res = bit_query(n);
  	if(res == 0) { cout << 0 << "\n"; return; }
  	
  	int low = 1, high = n;
  	while(low < high) {
  		int mid = low + ((high - low) >> 1);
  		int val = bit_query(mid);
  		if(res <= val) high = mid;
  		else low = mid + 1;
  	}
  	
  	cout << low << "\n";
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

/***************************************************************************************************************/

// Link for Binary lifting on Fenwick Tree --->
// https://www.youtube.com/watch?v=nuUspQ7ORXE

// USING FENWICK TREE(BIT) + BINARY LIFTING [TC = O(q x log2(n)]

// Problem: D. Multiset
// Contest: Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1354/problem/D
// Memory Limit: 28 MB
// Time Limit: 1500 ms
// Parsed on: 16-01-2021 16:24:28 IST (UTC+05:30)
// Author: kapil_choudhary

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

vi bit;
int n, q;

void bit_update(int i, int val) {
  while(i <= n) {
    bit[i] += val;
    i += (i & -i);
  }
}

int bit_query(int i) {
  int res = 0;
  while(i > 0) {
    res += bit[i];
    i -= (i & -i);
  }
  
  return res;
}

// Binary lifting on Fenwick tree, it returns the lower bound of 
// prefix sum of the passed parameter 'k'
int bit_lb(int k) {
  int curr = 0, res = 0, prev_sum = 0;
  // This loop will find the index such the the prefix sum
  // upto that index is strictly less than 'k'
  for(int i = log2(n); i >= 0; i--) {
    if((curr + (1 << i) <= n) && (bit[curr + (1 << i)] + prev_sum < k)) {
      res = curr + (1 << i);
      curr = res;
      prev_sum += bit[curr];
    }
  }
  
  // Now we add 1 to return lower bound of 'k'
  return res + 1;
}

void solve()
{
    cin >> n >> q;
    bit.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) {
      int x; cin >> x;
      bit_update(x, 1);
    }
    
    while(q--) {
      int k; cin >> k;
      if(k > 0) bit_update(k, 1);
      else {
        k = abs(k);
        int val = bit_lb(k);
        bit_update(val, -1);
      }
    }
    
    int res = bit_query(n);
    if(res == 0) { cout << 0 << "\n"; return; }
    
    for(int i = 1; i <= n; i++) {
      int val = bit_query(i);
      if(val >= 1) {
        cout << i << "\n";
        return;
      }
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