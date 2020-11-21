// Problem: Inversion Count
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/INVCNT/
// Memory Limit: 1536 MB
// Time Limit: 3599 ms
// Parsed on: 21-11-2020 22:19:45 IST (UTC+05:30)
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

const int mod = 1e9+7;

void bit_update(vll &bit, int i, int change)
{
	ll n = bit.size();
	
	while(i <= n){
		bit[i] += change;
		i += (i & (-i));
	}
}

ll bit_query(vll &bit, ll k)
{
	ll res = 0;
	
	while(k > 0){
		res += bit[k];
		k -= (k & (-k));
	}
	
	return res;
}

void solve()
{
  	ll n; cin >> n;
  	vll v(n + 1);
  	for(ll i = 1; i <= n; i++) cin >> v[i];
  	
  	vll bit(10000001, 0);
  	ll res = 0;
  	for(ll i = n; i >= 1; i--){
  		res += bit_query(bit, v[i] - 1);
  		bit_update(bit, v[i], 1);
  	}
  	
  	cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t; 
    while(t--) {
      solve();
    }

    return 0;
}