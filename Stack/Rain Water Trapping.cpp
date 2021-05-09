/*PROBLEM STATEMENT: Given n non-negative integers representing an elevation map where the width of each
                     bar is 1, compute how much water it is able to trap after raining.
                     Input: arr[]   = {3, 0, 2, 0, 4}
                     Output: 7
                     Explanation: We can trap "3 units" of water between 3 and 2,
                                  "1 unit" on top of bar 2 and "3 units" between 2 and 4.
*/

// METHOD - 1 (BRUTE FORCE APPROACH O(n^2))

/*
  # The idea is to traverse every array element and find the highest bars on left and right sides. 
  # Take the smaller of two heights. 
  # The difference between the smaller height and height of the current element is the amount of water that
    can be stored in this array element.
  # Time Complexity: O(n^2)
    Space COmplexity: O(1)
*/

/*********************************************************************************************************/

// METHOD - 2 O(n) 

/* UNDERLYING CONCEPT ----->
   • Total units of water trapped = ∑(Water trapped on each building).
   • Water trapped on each building w[i] = min(max(v[0]...v[i-1]), max(v[i+1]...v[n-1])) - v[i]
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

ll rain_water_trap(vi &v) {
    int n = (int)v.size();
    if(n == 0) return 0LL;
    
    // mx_left[i] contains height of tallest bar to the 
    // left of ith bar including itself 
    vi mx_left(n);

    // mx_right[i] contains height of tallest bar to the
    // right of ith bar including itself 
    vi mx_right(n);

    int mxl = INT_MIN, mxr = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        mxl = max(mxl, v[i]);
        mx_left[i] = mxl;
    }

    for(int i = (n - 1); i >= 0; i--) {
        mxr = max(mxr, v[i]);
        mx_right[i] = mxr;
    }
    
    ll res = 0LL;
    for(int i = 0; i < n; i++) {
        res += min(mx_left[i], mx_right[i]) - v[i];
    }
    
    return res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    cout << rain_water_trap(v) << "\n";
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

// Time Complexity: O(n): Only one traversal of the array is needed, So time Complexity is O(n).
// Space Complexity: O(n): Two extra vectors are needed each of size n.

/*****************************************************************************************************/

// METHOD - 3 (MOST OPTIMAL - O(n) time & O(1) Space)
// Ref: https://www.youtube.com/watch?v=m18Hntz4go8
//      https://www.geeksforgeeks.org/trapping-rain-water/ 

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

ll rain_water_trap(vi &v) {
    int n = (int)v.size();
    if(n == 0) return 0LL;
    
    int mx_left = 0, mx_right = 0;
    int lo = 0, hi = n - 1;

    ll res = 0LL;
    while(lo <= hi) {
        if(v[lo] <= v[hi]) {
            if(v[lo] >= mx_left) mx_left = v[lo];
            else res += mx_left - v[lo];
            lo++; 
        }
        
        else {
            if(v[hi] >= mx_right) mx_right = v[hi];
            else res += mx_right - v[hi];
            hi--;
        }
    }
    
    return res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    cout << rain_water_trap(v) << "\n";
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

// Time Complexity: O(n): Only one traversal of the array is needed, So time Complexity is O(n).
// Space Complexity: O(1).