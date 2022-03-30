// METHOD - 1 (Using user defined functions)

// Explanation source: https://www.youtube.com/watch?v=8RErc0VXAo8

/* Problem description --->
   1. You are given a number n, representing the size of array a.
   2. You are given n numbers, representing elements of array a.
   3. You are given a number k.
   4. Rotate the array a, k times to the right (for positive values of k), and to
      the left for negative values of k.
*/

/* Important points --->
   # A left cyclic shift is the same as (n − 1) right cyclic shifts and vice versa. 
     So we only need to perform shifts of one type, say right i.e. only right rotation of the array.

   # Array after K cyclic shifts is same as array after (K % N) cyclic shifts.  
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef vector<ll> vll;

// vector should be passed by reference
void reverse(ll i, ll j, vll &v) {
    if(i >= j) return;
    while(i < j) {
        ll tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
        i++; j--;
    }
}

// vector should be passed by reference
void rotate(vll &v, ll k) {
    ll n = v.size();
    k = k % n;
    if(k < 0) k = n + k;
    
    // reverse part 1
    reverse(0, n - k - 1, v);
    
    // reverse part 2
    reverse(n - k, n - 1, v);
    
    // reverse entire array
    reverse(0, n - 1, v);
}

void solve()
{
    ll n, k; cin >> n >> k;
    vll v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    
    rotate(v, k);
    for(auto x: v) cout << x << " ";
    cout << "\n";
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

// METHOD - 2 (Using inbuilt C++ STL function)
// https://www.geeksforgeeks.org/rotate-in-cpp-stl/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef vector<ll> vll;

// function to right rotate vector v by k times
// NOTE: vector should be passed by reference
void right_rotate(vll &v, ll k) {
    ll n = v.size();
    k = k % n;
    
    rotate(v.begin(), v.begin() + n - k, v.end());
}

// function to left rotate vector v by k times
// NOTE: vector should be passed by reference
void left_rotate(vll &v, ll k) {
    ll n = v.size();
    k = k % n;
    
    rotate(v.begin(), v.begin() + k, v.end());
}

void solve()
{
    ll n, k; cin >> n >> k;
    vll v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    
    // typ = 0 => left rotate, typ = 1 => right rotate
    ll typ; cin >> typ;
    
    if(typ == 0) left_rotate(v, k);
    else right_rotate(v, k);
    
    for(auto x: v) cout << x << " ";
    cout << "\n";
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