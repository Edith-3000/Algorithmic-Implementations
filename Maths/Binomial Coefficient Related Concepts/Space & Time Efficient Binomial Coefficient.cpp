// Ref: https://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient/
/***************************************************************************************************/

/* A binomial coefficient nCr gives number of r-element subsets (or r-combinations) 
   of an n-element set.
   * ⁿCᵣ = ⁽ⁿ⁻¹⁾Cᵣ + ⁽ⁿ⁻¹⁾C₍ᵣ₋₁₎
   * ⁿCᵣ = ⁿC₍ₙ₋ᵣ₎
   * C(n, r) = [n * (n-1) * .... * (n-r+1)] / [r * (r-1) * .... * 1]
             = [(n/r) * (n-1)/(r-1) * .....* (n-r+1)/1] ---> total r terms
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

ll nCr(ll n, ll r) {
    if(r > n) return -1;
    if(r == n or r == 0) return 1;
    
    // since C(n, r) = C(n, n-r) 
    // it is done so as to reduce the #iterations
    if(r > (n - r)) r = n - r;  
    
    ll res = 1; // initialize result
    
    for(ll i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    
    return res;
}

void solve()
{
    ll n, r; cin >> n >> r;
    cout << nCr(n, r) << "\n";
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


/* Complexity Analysis: Time Complexity: O(r) since a loop has to be run from 0 to r.
                        So, the time complexity is O(r).
                        Auxiliary Space: O(1) as no extra space is required.
*/

/*******************************************************************************************************/

// Snippet to calculate nCr(n, r) % mod

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
const ll mod = 1e9+7;

ll mod_exp(ll a, ll b) {
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

// mod inverse can be calculate by this method only if
// 'b' is a prime number
ll mod_inv(ll a, ll b) {
    return mod_exp(a, b - 2);
}

ll nCr(ll n, ll r) {
    if(r > n) return -1;
    if(r == n or r == 0) return 1;
  
    // since C(n, r) = C(n, n-r) 
    // it is done so as to reduce the #iterations
    if(r > (n - r)) r = n - r;
  
    ll res = 1; // initialize result
  
    for(int i = 0; i < r; i++) {
        res = (res * (n - i)) % mod;
        res = (res * mod_inv(i + 1, mod)) % mod;
    }
  
    return res;
}

void solve()
{
    ll n, r; cin >> n >> r;
    cout << nCr(n, r) << "\n";
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