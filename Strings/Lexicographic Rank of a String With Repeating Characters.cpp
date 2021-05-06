// Problem: https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/
// Ref: https://www.geeksforgeeks.org/lexicographic-rank-string-duplicate-characters/
/******************************************************************************************************/

// METHOD - 1 O(n^2)

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

// A utility function to find factorials
void init_fact(vll &fact) {
	ll n = fact.size();
	fact[0] = fact[1] = 1;
	for(int i = 2; i < n; i++) {
		fact[i] = (i * fact[i-1]) % mod;
	}
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

ll helper(int k, string &s, vll &fact) {
	int n = (int)s.size();
	
	// to count frequency of duplicate characters.
	vi cnt(56, 0);
	
	for(int i = k; i < n; i++) {
		// check whether the character is upper or lower case & 
		// then increase the specific element of the array.
		if(s[i] >= 'A' and s[i] <= 'Z') cnt[s[i] - 'A']++;
		else cnt[s[i] - 'a' + 26]++;
	}
	
	// compute the product of the factorials of frequency of characters.
	ll res = 1LL;
	for(int i = 0; i < 56; i++) res = (res * fact[cnt[i]]) % mod;
	
	return res;
}

// Function to find the lexicographic rank of a string
ll find_rank(string &s) {
	int n = s.size();
	if(n == 0) return -1;
	
	ll rank = 1;
	vll fact(n + 1, 0);
	init_fact(fact);
	
	for(int i = 0; i < n; i++) {
		// count number of chars smaller than s[i] from s[i+1] to s[n-1]
		int cnt = find_smallers(i, s);
		
		// taking into account repeating characters
		ll tmp = helper(i, s, fact);
		
		ll x = (cnt * fact[n-i-1]) % mod;
		x = (x * mod_inv(tmp)) % mod;
		
		// update rank
		rank = (rank + x) % mod;
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

// TC: O(n^2)

/**************************************************************************************************/