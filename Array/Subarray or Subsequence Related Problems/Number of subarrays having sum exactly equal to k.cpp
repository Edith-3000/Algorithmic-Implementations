// Link(s): https://www.youtube.com/watch?v=HbbYPQc-Oo4
//          https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/

/****************************************************************************************************************/

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

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

int cnt_subarr(vll &v, ll k) {
  int n = (int)v.size();
  
  vll cs(n, 0);
  for(int i = 0; i < n; i++) {
    cs[i] += v[i];
    if(i) cs[i] += cs[i-1];
  }
  
  unordered_map<ll, ll> M;
  int res = 0;
    
  for(int i = 0; i < n; i++) {
    if(cs[i] == k) res++;
    if(M.find(cs[i] - k) != M.end()) res += M[cs[i] - k];
    M[cs[i]]++;
  }
    
  return res;
}

void solve()
{
    int n, k; cin >> n >> k;
    vll v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    cout << cnt_subarr(v, k) << "\n";
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

// Time complexity: O(n)
// Space complexity: O(n)

/****************************************************************************************************/

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

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

int cnt_subarr(vll &v, ll k) {
  int n = (int)v.size();
  
  unordered_map<ll, ll> M;
    int res = 0, curr_sum = 0;
    
    for(int i = 0; i < n; i++) {
      curr_sum += v[i];
      if(curr_sum == k) res++;
      if(M.find(curr_sum - k) != M.end()) res += M[curr_sum - k];
      M[curr_sum]++;
    }
    
    return res;
}

void solve()
{
    int n, k; cin >> n >> k;
    vll v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    cout << cnt_subarr(v, k) << "\n";
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

// Time complexity: O(n)
// Space complexity: O(1)