// Problem: https://www.interviewbit.com/problems/sorted-permutation-rank/
// Ref: https://www.geeksforgeeks.org/lexicographic-rank-of-a-string/
//      https://www.techiedelight.com/calculate-rank-lexicographically-sorted-permutations/
/*****************************************************************************************************/

// METHOD - 1

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
const ll mod = 1e9+7;

// Function to find the lexicographic rank of a string using
// std::next_permutation
ll find_rank(string &s) {
	int n = s.size();
	if(n == 0) return -1;
	
	string tmp = s;
	
	// sort the string in ascending order
	sort(tmp.begin(), tmp.end());
	
	ll rank = 1;
	while(1) {
		// if the current permutation is equal to the s, return its rank
		if(tmp == s) return rank;
		
		 // find next lexicographically ordered permutation
		if(!next_permutation(tmp.begin(), tmp.end())) break;
		
		// increment result
		rank = (rank + 1) % mod;
	}
}

void solve()
{
  	string s; cin >> s;
  	cout << find_rank(s) << "\n";
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

// TC: O(n x n!)

/********************************************************************************************************/

// METHOD - 2

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
const ll mod = 1e9+7;

ll mod_exp(ll a, ll b) {
	a %= mod;
	if(a == 0) return 0;
	ll res = 1LL;
	
	while(b > 0) {
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	
	return res;
}

ll mod_inv(ll a) {
	return mod_exp(a, mod - 2);
}

// A utility function to find factorial of n
ll factorial(int n) {
	if(n == 0 or n == 1) return 1;
	ll res = 1;
	for(int i = 2; i <= n; i++) {
		res = (res * i) % mod;
	}
	
	return res;
}

// A utility function to count smaller characters on right
// of s[k]
int find_smallers(int k, string &s) {
	int cnt = 0;
	
	for(int i = k + 1; i < (int)s.size(); i++) {
		if(s[i] < s[k]) cnt += 1;
	}
	
	return cnt;
}

// Function to find the lexicographic rank of a string
ll find_rank(string &s) {
	int n = s.size();
	if(n == 0) return -1;
	
	ll rank = 1;
	ll x = factorial(n);
	
	for(int i = 0; i < n; i++) {
		// count number of chars smaller than s[i] from s[i+1] to s[n-1]
		int cnt = find_smallers(i, s);
		
		// update x
		x = (x * mod_inv(n - i)) % mod;
		
		// update rank
		rank = (rank + ((x * cnt) % mod)) % mod;
	}
	
	return rank;
}

void solve()
{
  	string s; cin >> s;
  	cout << find_rank(s) << "\n";
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

// TC: O(n^2 x log(n))

/***************************************************************************************************/

// METHOD - 3

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
const int MAX_CHAR = 256;
const ll mod = 1e9+7;

ll mod_exp(ll a, ll b) {
	a %= mod;
	if(a == 0) return 0;
	ll res = 1LL;
	
	while(b > 0) {
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	
	return res;
}

ll mod_inv(ll a) {
	return mod_exp(a, mod - 2);
}

// A utility function to find factorial of n
ll factorial(int n) {
	if(n == 0 or n == 1) return 1;
	ll res = 1;
	for(int i = 2; i <= n; i++) {
		res = (res * i) % mod;
	}
	
	return res;
}

void init_cnt(vi &cnt, string &s) {
	int n = (int)s.size();
	for(int i = 0; i < n; i++) cnt[s[i]]++;
	for(int i = 1; i < MAX_CHAR; i++) cnt[i] += cnt[i-1];
} 

void update_cnt(char ch, vi &cnt) {
	for(int i = (int)ch; i < MAX_CHAR; i++) cnt[i]--;
}

// Function to find the lexicographic rank of a string
ll find_rank(string &s) {
	int n = s.size();
	if(n == 0) return -1;
	
	vi cnt(MAX_CHAR, 0);
	init_cnt(cnt, s);
	
	ll rank = 1;
	ll x = factorial(n);
	
	for(int i = 0; i < n; i++) {
		// count number of chars smaller than s[i] from s[i+1] to s[n-1]
		int cnt_ele = cnt[s[i] - 1];
		
		// update x
		x = (x * mod_inv(n - i)) % mod;
		
		// update rank
		rank = (rank + ((x * cnt_ele) % mod)) % mod;
		
		// reduce count of characters greater than s[i]
		update_cnt(s[i], cnt);
	}
	
	return rank;
}

void solve()
{
  	string s; cin >> s;
  	cout << find_rank(s) << "\n";
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

// TC: O(n x log(n))