// Ref: https://www.geeksforgeeks.org/count-unimodal-and-non-unimodal-permutations-of-first-n-natural-numbers/
// Ques. based on this: https://codeforces.com/problemset/problem/1391/C
/**************************************************************************************************************/

/* Problem --->
   Given an integer n, the task is to count the total number of unimodal and non-unimodal permutations of 
   integers [1, n] possible.
   Note: Since the total count can be very large, so print modulo 10^9+7.

   # A unimodal permutation is a permutation which increases up to a certain point following which it 
     starts decreasing. 
   # All other permutations excluding unimodal permutations are non-unimodal permutations.
*/

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

ll mod_expo(ll a, ll b) {
	a %= mod;
	if(a == 0) return 0;
	
	ll res = 1;
	while(b > 0) {
		if(b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	
	return res;
}

ll factorial(ll n) {
	vll fact(n + 1, 0);
	fact[0] = 1;
	
	for(ll i = 1; i <= n; i++) {
		fact[i] = (fact[i-1] * i) % mod;
	}
	
	return fact[n];
}

pll cnt_uni_nonuni_permu(ll n) {
	ll total = factorial(n);
	ll uni = mod_expo(2, n - 1);
	ll nonuni = total - uni;
	return {uni, nonuni};
}

void solve()
{
  	ll n; cin >> n;
  	pll res = cnt_uni_nonuni_permu(n);
	cout << "#unimodal permutation % 10^9 + 7 = " << res.F << "\n";
	cout << "#non-unimodal permutation % 10^9 + 7 = " << res.S << "\n";
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

// Time Complexity: O(n) 
// Auxiliary Space: O(n)