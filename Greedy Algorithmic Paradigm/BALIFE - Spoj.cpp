// Problem: Load Balancing
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/BALIFE/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// Parsed on: 16-11-2020 17:50:46 IST (UTC+05:30)
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

void solve(ll n)
{
  	ll sum = 0;
  	vll v(n);
  	for(ll i = 0; i < n; i++){
  		cin >> v[i];
  		sum += v[i];
  	}
  	
  	if((sum % n) != 0){
  		cout << -1 << '\n';
  		return;
  	}
  	
  	vll pre(n); pre[0] = v[0];
  	for(ll i = 1; i < n; i++){
  		pre[i] = pre[i - 1] + v[i];
  	}
  	
  	ll res = LLONG_MIN;
  	ll f = sum/n;
  	
  	for(ll i = 0; i <= (n - 2); i++){
  		ll curr_left = pre[i];
  		ll req_left = f * (i + 1);
  		res = max(res, abs(curr_left - req_left));
  	}  	  	
  	
  	cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // int t = 1;
    // cin >> t;
    while(1) {
      ll n; cin >> n;
      if(n == -1) break;
      solve(n);
    }

    return 0;
}

/**************************************************************************************************************/

// Implementation w/o using Prefix array

// Problem: Load Balancing
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/BALIFE/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// Parsed on: 16-11-2020 17:50:46 IST (UTC+05:30)
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

const int mod = 1e9+7;

void solve(ll n)
{
    ll sum = 0;
    vll v(n);
    for(ll i = 0; i < n; i++){
      cin >> v[i];
      sum += v[i];
    }
    
    if((sum % n) != 0){
      cout << -1 << '\n';
      return;
    }
    
    ll res = LLONG_MIN;
    ll f = sum/n;
    ll diff = 0; // to maintain running diff
    
    for(ll i = 0; i < (n - 1); i++){
      diff += (v[i] - f);
      res = max(res, abs(diff));
    }       
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // int t = 1;
    // cin >> t;
    while(1) {
      ll n; cin >> n;
      if(n == -1) break;
      solve(n);
    }

    return 0;
}