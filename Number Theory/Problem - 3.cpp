// Reference: https://www.youtube.com/watch?v=9EUSdYj7aqs
/************************************************************************************************************/

// Problem: A. Orac and LCM
// Contest: Codeforces - Codeforces Round #641 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1349/A
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// Parsed on: 08-02-2021 10:39:43 IST (UTC+05:30)
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

map<ll, vll> M;
ll n;
vll v;

ll pow(ll a, ll b) {
	ll res = 1;
	while(b > 0) {
		if(b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	
	return res;
}

void prime_factorize(ll n) {
	for(ll i = 2; (i * i) <= n; i++) {
		if(n % i == 0) {
			ll cnt = 0;
			while(n % i == 0) {
				cnt++;
				n /= i;
			}
			
			M[i].pb(cnt);
		}
	}
	
	if(n > 1) M[n].pb(1);
}

void solve()
{
  	M.clear(); 
  	ll n; cin >> n;
  	v.resize(n);
  	
  	for(ll i = 0; i < n; i++) {
  		cin >> v[i];
  		prime_factorize(v[i]);
  	}
  	
  	// OBSERVATIONS: ==>
  	// 1. If a prime num P appears in <= (n - 2) times of all the primes factorizations n of numbers,
  	//    then it will contribute nothing in the final result
  	// 2. If a prime num P appears in exactly (n - 1) times of all the primes factorizations of n numbers,
  	//    then it will contribute (P ^ k) in the final result, where k is the smallest occurred power of P
  	// 3. If a prime num P appears in exactly (n) times of all the primes factorizations n of numbers,
  	//    then it will contribute (P ^ k) in the final result, where k is the second smallest occurred power of P
  	
  	ll res = 1;
  	for(auto x: M) {
  		if(x.S.size() <= n - 2) continue;
  		sort(x.S.begin(), x.S.end());
  		if(x.S.size() == n - 1) res = (res * pow(x.F, x.S[0]));
  		else res = (res * pow(x.F, x.S[1]));
  	}
  	
  	cout << res << "\n";
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