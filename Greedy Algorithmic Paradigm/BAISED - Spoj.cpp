// Problem: Biased Standings
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/BAISED/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// Parsed on: 16-11-2020 15:47:49 IST (UTC+05:30)
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

void solve()
{
  	ll n; cin >> n;
  	vector<ll> v(n);
  	for(ll i = 0; i < n; i++){
  		string s; ll r; cin >> s >> r;
  		v[i] = r;
  	}
  	
  	sort(v.begin(), v.end());
  	ll res = 0;
  	for(ll i = 0; i < n; i++){
  		res += abs(v[i] - (i + 1));
  	}
  	
  	cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      cout << "\n";
      solve();
    }

    return 0;
}

// greedily we've assigned a rank to a team which is nearest available to it's preferred rank.
// Time complexity: O(n x log(n))

/**************************************************************************************************************/

// O(n) approach using COUNTING SORT

// Problem: Biased Standings
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/BAISED/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// Parsed on: 16-11-2020 15:47:49 IST (UTC+05:30)
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

void solve()
{
    ll n; cin >> n;
    vector<ll> v(n+1, 0);
    for(ll i = 0; i < n; i++){
      string s; ll r; cin >> s >> r;
      v[r]++;
    }
    
    ll res = 0, actual_rank = 1;
    for(ll i = 1; i <= n; i++){
      while(v[i] > 0){
        res += abs(actual_rank - i);
        actual_rank++;
        v[i]--;
      }
    }
    
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      cout << "\n";
      solve();
    }

    return 0;
}

// Time complexity: O(n x log(n))