// Source(s): https://atcoder.jp/contests/abc190/editorial/639

// NOTE: I tried to the problem using Method 1 (based on similar concept of Merge Sort), but it gave 
//       TLE on some of the cases, but when I calculated inversions using Method 2 (PBDS), it passed all cases.
//       Don't know why it happened as both methods to find #inversion counts work in O(n x log2(n)) time.

/************************************************************************************************************/ 

// Method 1

// Problem: F - Shift and Inversions
// Contest: AtCoder - AtCoder Beginner Contest 190
// URL: https://atcoder.jp/contests/abc190/tasks/abc190_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Parsed on: 01-02-2021 14:26:11 IST (UTC+05:30)
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

vi v;
int n;

ll cross_inv(int l, int h) {
	int mid = l + ((h - l) >> 1);
	vi tmp(n);
	
	ll cnt = 0;
	int i = l, j = mid + 1, k = l;
	while(i <= mid && j <= h) {
		if(v[i] <= v[j]) tmp[k++] = v[i++];
		else {
			cnt += (mid - i + 1);
			tmp[k++] = v[j++];
		}
	}
	
	while(i <= mid) tmp[k++] = v[i++];
	while(j <= h) tmp[k++] = v[j++];
	
	for(int ii = l; ii <= h; ii++) v[ii] = tmp[ii];
	
	return cnt;
}

ll inv_cnt(int l, int h) {
	if(l >= h) return 0LL;
	
	int mid = l + ((h - l) >> 1);
	ll res = inv_cnt(l, mid) + inv_cnt(mid + 1, h);
	res += cross_inv(l, h);
	
	return res;
}

void solve()
{
  	cin >> n;
  	v.resize(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vi t = v;
  	ll inv = inv_cnt(0, n - 1);
  	
  	for(int k = 0; k < n; k++) {
  		cout << inv << "\n";
  		inv -= t[k];
  		inv += (n - 1 - t[k]); 
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

/**********************************************************************************************************/

// Method 2

// Problem: F - Shift and Inversions
// Contest: AtCoder - AtCoder Beginner Contest 190
// URL: https://atcoder.jp/contests/abc190/tasks/abc190_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Parsed on: 01-02-2021 15:12:23 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// pair<int, int> is taken so as to take care of array containing
// duplicate elements
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
		tree_order_statistics_node_update> PBDS;

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

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	PBDS st;
	ll inv = 0; // for storing the result
	
	for(int i = 0; i < n; i++){
		inv += (st.size() - st.order_of_key({v[i], i}));
		st.insert({v[i], i});
	}
	
	for(int k = 0; k < n; k++) {
		cout << inv << "\n";
		inv -= v[k];
		inv += (n - 1 - v[k]);
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