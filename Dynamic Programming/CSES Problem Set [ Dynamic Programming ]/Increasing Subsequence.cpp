// Both the below approaches are O(n x log2(n))

/*********************************************************************************************************/

// Method 1 - using inbuild C++ stl lower_bound() function 

// Problem: Increasing Subsequence
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1145
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 03-02-2021 20:24:25 IST (UTC+05:30)
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

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	// t[i] is defined as the smallest integer that ends 
  	// the longest increasing subsequence of length (i+1)
  	vi t;
  	t.pb(v[0]);
  	for(int i = 1; i < n; i++) {
  		if(v[i] > t.back()) t.pb(v[i]);
  		else {
  			int idx = lower_bound(t.begin(), t.end(), v[i]) - t.begin();
  			t[idx] = v[i];
  		}
  	}
  	
  	cout << t.size() << "\n";
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

/***********************************************************************************************************/

// Method 2 - using self implemented lower_bound() function 

// Problem: Increasing Subsequence
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1145
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 03-02-2021 20:24:25 IST (UTC+05:30)
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

int lower_bound(vi &v, int key) {
  int l = 0, h = v.size() - 1;
  while(l < h) {
    int mid = l + ((h - l) >> 1);
    if(key <= v[mid]) h = mid;
    else l = mid + 1;
  }
  
  return l;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    // t[i] is defined as the smallest integer that ends 
    // the longest increasing subsequence of length (i+1)
    vi t;
    t.pb(v[0]);
    for(int i = 1; i < n; i++) {
      if(v[i] > t.back()) t.pb(v[i]);
      else {
        int idx = lower_bound(t, v[i]);
        t[idx] = v[i];
      }
    }
    
    cout << t.size() << "\n";
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

/***********************************************************************************************************/

/* EXTRAS --->
   # Just as the self implemented lower_bound() function, upper bound function ca also be implemented
     for eg.

     int upper_bound(vi &v, int key) {
        int l = 0, h = v.size() - 1;
        while(l < h) {
          int mid = l + ((h - l) >> 1);
          if(key >= v[mid]) l = mid + 1;
          else h = mid;
        }
        
        return l;
     }

   # Reference: https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c/
*/