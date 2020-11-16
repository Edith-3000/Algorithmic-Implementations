// Problem: E. XOR Guessing
// Contest: Codeforces - Educational Codeforces Round 71 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1207/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 16-11-2020 11:01:52 IST (UTC+05:30)
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

ll query_to_judge(vll &v)
{
	cout << "? ";
	for(auto x: v) cout << x << " ";
	cout << endl;
	
	ll n; cin >> n;
	return n; 
}

void solve()
{
  	ll res = 0;
  	vll v(100);
  	for(ll i = 0; i < 100; i++) v[i] = i;
  	ll left_bits = query_to_judge(v);
  	
  	for(ll i = 7; i < 14; i++){
  		if((left_bits >> i) & 1){
  			res |= (1 << i);
  		}
  	}
  	
  	for(ll i = 0; i < 100; i++) v[i] = (i + 1) << 7;
  	ll right_bits = query_to_judge(v);
  	
  	for(ll i = 0; i < 7; i++){
  		if((right_bits >> i) & 1){
  			res |= (1 << i);
  		}
  	}
  	
  	cout << "! " << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}