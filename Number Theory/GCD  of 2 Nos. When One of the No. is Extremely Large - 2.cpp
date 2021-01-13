/* # If you need to calculate GCD(X, Y) where X is a very huge number but Y is smaller then we would find 
     potential GCD candidates and apply modulo arithmetic to find GCD.

   # In this case applying Basic Eucledian Algorithm won't help, therefore we would find GCD candidates, 
     as such a huge number can't be stored in int or long long int.

   # So the potential candidates will be the divisors of the smaller number (Y), and maximum of them
     which divides the larger number (X) will be the answer.

   # Approach link: https://www.youtube.com/watch?v=rXnS4nf0T0M
*/

// Problem: Modular GCD
// Contest: CodeChef - Practice(Easy)
// URL: https://www.codechef.com/problems/GCDMOD
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 13-01-2021 17:05:22 IST (UTC+05:30)
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
const ll mod = 1e9+7;

ll A, B, N;

ll mod_expo(ll a, ll b, ll p = mod) {
	a %= p;
	if(a == 0) return 0;
	
	ll res = 1;
	while(b > 0) {
		if(b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	
	return res;
}

void solve()
{
  	cin >> A >> B >> N;
  	
  	// Special case
  	if(A == B) {
  		cout << (mod_expo(A, N) + mod_expo(B, N)) % mod << "\n";
  		return;
  	}
  	
  	ll candidate = 1;
  	ll num = abs(A - B);
  	for(ll i = 1; (i * i) <= num; i++) {
  		if(num % i == 0) {
  			ll tmp = (mod_expo(A, N, i) + mod_expo(B, N, i)) % i;
  			if(tmp == 0) candidate = max(candidate, i);
  			
  			tmp = (mod_expo(A, N, num/i) + mod_expo(B, N, num/i)) % (num/i);
  			if(tmp == 0) candidate = max(candidate, num/i);
  		}
  	}
  	
  	cout << candidate % mod << "\n";
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}