// Ref: https://www.geeksforgeeks.org/smallest-number-greater-than-n-that-can-be-represented-as-a-sum-of-distinct-power-of-k/
// Easier version of below problem: https://codeforces.com/contest/1249/problem/C1
/****************************************************************************************************************************/

// Problem: C2. Good Numbers (hard version)
// Contest: Codeforces - Codeforces Round #595 (Div. 3)
// URL: https://codeforces.com/contest/1249/problem/C2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 24-03-2021 23:17:32 IST (UTC+05:30)
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

// Driver function to find the smallest number greater than or 
// equal to n represented as the sum of distinct powers of k
ll calc(ll n, ll k) {
	// vector p to store the base k representation of the number
	// n, v.front() is the LSB and v.back() is the MSB
	vll p;
	
	// temporarily making copy of n
	ll x = n;
	while(x > 0) {
		p.pb(x % k);
		x /= k;
	}
	
	ll idx = 0;
	for(ll i = 0; i < p.size() - 1; i++) {
		// if the representation is >=2, then this power of k has to
		// be added once again and then increase the next power of k 
		// and make the current power and all the lower powers = 0, as
		// we need to find the smallest number >= n
		if(p[i] >= 2) {
			p[i] = 0;
			p[i+1]++;
			
			// reduce all the lower powers of k to 0
			for(ll j = idx; j < i; j++) p[j] = 0;
			idx = i + 1;
		}
		
		if(p[i] == k) {
			p[i] = 0;
			p[i+1]++;
		}
	}
	
	// check if the most significant bit also satisfy the 
    // conditions mentioned
	if(p[p.size() - 1] >= 2) {
		// reduce all the lower powers of k to 0
		for(auto &i: p) i = 0;
		p.pb(1);
	}
	
	ll res = 0LL;
	
	// converting back from the k-nary representation to
    // decimal form.
	for(ll i = p.size() - 1; i >= 0; i--) {
		res *= k;
		res += p[i];
	}
	
	return res;
}

void solve()
{
  	ll n; cin >> n;
  	cout << calc(n, 3LL) << "\n";
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
    cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}