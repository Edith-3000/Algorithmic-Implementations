/* Link: https://www.interviewbit.com/problems/repeat-and-missing-number-array/

   PROBLEM: You are given an array of n integers from 1 to n.
            Each integer appears exactly once except A which appears twice and B which is missing.
            Array need not be sorted.
            Return A and B.
            NOTE: Your algorithm should have a linear runtime complexity. 
            Could you implement it without using extra memory?
*/

/* SIDE TIPS ----->
   # There are certain problems which are asked in the interview to also check how you take care of 
     overflows in your problem.
   # This is one of those problems.
     Take extra care to make sure that you are type-casting your ints to long properly and at all places. 
     Try to verify if your solution works if number of elements is as large as 10⁵.

   # Food for thought :
     Even though it might not be required in this problem, in some cases, you might be required to order 
     the operations cleverly so that the numbers do not overflow.
     For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate 
     factorial(n), factorial(k) and then divide them.
     Another approach is to only multiple numbers from (k+1)....n to calculate the result.
     Obviously approach 1 is more susceptible to overflows.
*/

/*****************************************************************************************************/

// METHOD - 1 (Using Sorting)
// This method mutates(changes) the original array
// Ref: https://www.youtube.com/watch?v=5nMGY4VUoRY
//      https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

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

vi rep_and_miss(vi &v) {
    int n = (int)v.size();
    if(n == 0 or n == 1) return vi();
    
    sort(v.begin(), v.end());
    
    vi res;
    int rep, miss;
    
    for(int i = 1; i < n; i++) {
        if(v[i] == v[i-1]) { rep = v[i]; break; }
    }
    
    if(v[0] != 1) miss = 1;
    else if(v[n-1] != n) miss = n;
    else {
        for(int i = 1; i < n; i++) {
            if(v[i] - v[i-1] == 2) { miss = v[i] - 1; break; }
        }
    }
    
    res.pb(rep);
    res.pb(miss);
    
    return res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vi res = rep_and_miss(v);
    for(auto x: res) cout << x << " ";
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

// Time complexity: O(n x log(n))
// Space complexity: O(n)

/******************************************************************************************************/

// METHOD - 2 (Using Count Array)
// This method do not mutates(changes) the original array
// Ref: https://www.youtube.com/watch?v=5nMGY4VUoRY
//      https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

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

vi rep_and_miss(vi &v) {
    int n = (int)v.size();
    if(n == 0 or n == 1) return vi();
    
    vi res;
    int rep, miss;
    
    vi cnt(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cnt[v[i]] += 1;
    }
    
    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 2) rep = i;
        else if(cnt[i] == 0) miss = i;
    }
    
    res.pb(rep);
    res.pb(miss);
    
    return res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vi res = rep_and_miss(v);
    for(auto x: res) cout << x << " ";
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

/*****************************************************************************************************/

// METHOD - 2 (Using Basic Maths)
// This method do not mutates(changes) the original array

/* UNDERLYING CONCEPT:
   ● Let the i/p array be of size = 4 be vᵢ = {a, a, c, d}
     Let vᵢ = v(input)
         vₒ = v(original)
     Note: a, b, c, d are integral values.

   ● Now, ∑(vₒ) - ∑(vᵢ) = (a + b + c + d) - ( a + a + c + d)
                     c1 = b - a -------------------------------------------- eqⁿ(1)
        
         Squaring each term of vₒ & adding them = a² + b ² + c² + d²
         Squaring each term of vᵢ & adding them = a² + a² + c² + d²

         Now, a² + b² + c² + d² - (a² + a² + c² + d²) = b² - a²
                                                   c2 = (b + a) * (b - a)
                                            c2 / (b - a) = b + a
                                                 c2 / c1 = b + a
                                                      c3 = b + a ------------ eqⁿ(2)
         * c1, c2 and c3 are constants.

         Using eqⁿ(1) & eqⁿ(2),
         b = (c1 + c3) / 2
         a = b - c1
   ● Beware of overflow in this approach.
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

vi rep_and_miss(vi &v) {
    int n = (int)v.size();
    if(n == 0 or n == 1) return vi();
    
    vi res;
    int rep, miss;
    
    // try to handle overflow as much as we can
    ll sum = (n & 1) ? ((n + 1) / 2) * n : (n / 2) * (n + 1);
    ll sqsum = (n * (n + 1) * (2 * n + 1)) / 6;
    
    ll vsum = 0LL;
    for(int i = 0; i < n; i++) vsum += v[i];
    
    ll vsqsum = 0LL;
    for(int i = 0; i < n; i++) vsqsum += ((ll)v[i] * v[i]);
    
    ll c1 = sum - vsum;
    ll c2 = sqsum - vsqsum;
    ll c3 = c2 / c1;
    
    miss = (c1 + c3) / 2;
    rep = miss - c1;
    
    res.pb(rep);
    res.pb(miss);
    
    return res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vi res = rep_and_miss(v);
    for(auto x: res) cout << x << " ";
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

/*****************************************************************************************************/

// METHOD - 4 (Using xor)
// This method do not mutates(changes) the original array
// Ref: https://www.youtube.com/watch?v=5nMGY4VUoRY
//      https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

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

vi rep_and_miss(vi &v) {
    int n = (int)v.size();
    if(n == 0 or n == 1) return vi();
    
    vi res;
    int rep, miss;
    
    // will hold xor of all elements of v[] and numbers from 1 to n 
    // such that in the last it stores ===> rep ^ miss
    ll XOR = 0LL;
    for(int i = 1; i <= n; i++) XOR ^= i;
    for(int i = 0; i < n; i++) XOR ^= v[i];
    
    // set is the number with only single set bit of XOR (it can be any bit),
    // here I have chosen the number with rightmost set bit
    ll set = XOR & ~(XOR - 1);
    ll bucket1 = 0LL, bucket2 = 0LL;
    
    // now divide elements into two buckets by comparing a rightmost set
    // bit of XOR with the bit at the same position in each element. 
    for(int i = 0; i < n; i++) {
        if(v[i] & set) bucket1 ^= v[i];
        else bucket2 ^= v[i];
    }
    
    // again dividing the numbers from 1 to n to divide them into the two
    // buckets so as to nullify the effect of other numbers ans get the desired
    // repeating and missing numbers 
    for(int i = 1; i <= n; i++) {
        if(i & set) bucket1 ^= i;
        else bucket2 ^= i;
    }
    
    // find which one is repeating and which one is missing among result
    // of bucket1 and bucket2
    bool ok = false;
    for(int i = 0; i < n; i++) {
        if(v[i] == bucket1) { ok = true; break; }
    }
    
    if(ok) rep = bucket1, miss = bucket2;
    else rep = bucket2, miss = bucket1;
    
    res.pb(rep);
    res.pb(miss);
    
    return res;
}

void solve()
{
    int n; cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    vi res = rep_and_miss(v);
    for(auto x: res) cout << x << " ";
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

/******************************************************************************************************/

// OTHER IMPLEMENTATIONS

// OPTIMIZED IMPLEMENTATION USINIG Swap Sort
// REf: https://i.ytimg.com/vi/KOsS5-1q9rU/hq720.jpg?sqp=-oaymwEcCOgCEMoBSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDK-vZ6OnFP4j8hUGXEmQVM6jV0lw

/* # The method using maths is not scalable i.e. it will be very much complicated if multiple missing and 
     multiple duplicates occur.
   # This method(by swap sort) is only applicable if the given array is mutable(i.e. it can be changed).
   # If the array is immutable(read only), then this method is not applicable.
*/

void swap(long long &x, long long &y)
{
   long long temp=x;
   x=y;
   y=temp;
}

pair<long long, long long> repeatAndMissing(vector<long long> &v)
{
   long long n=v.size();
   
   long long i=0; //array traverser
   long long m, r; //for storing the missing & repeating character

   for(long long i=0; i<n; i++)
   {
      while(i!=(v[i]-1))
      {
         //if the current element at i i.e. v[i] != should be 
         //element at i 
         if(v[i]!=v[v[i]-1])
            swap(v[i], v[v[i]-1]);

         else 
         {
            r=v[i];
            m=i+1;
            break;
         }
      }
   }
   
   pair<long long, long long> p; //for returning final result
   p=make_pair(m, r);
   return p;
}

//Time complexity: O(n)
//Space complexity: O(1)

/******************************************************************************************************/

/*Slightly different code from above code, although no difference in logic*/

void swap(long long &x, long long &y)
{
   long long temp=x;
   x=y;
   y=temp;
}

pair<long long, long long> repeatAndMissing(vector<long long> &v)
{
   long long n=v.size();
   
   long long i=0; //array traverser
   
   //preprocessing the array
   while(i<n)
   {
      if(v[i]!=v[v[i]-1])
         swap(v[i], v[v[i]-1]);

      else i++;
   }  
   
   int r, m;
   //extracting result
   for(long long i=0; i<n; i++)
   {
      if(i!=v[i]-1)
      {
         r=v[i];
         m=i+1;
         break;
      }
   }

   pair<long long, long long> p; //for returning final result
   p=make_pair(m, r);
   return p;
}

//Time complexity: O(n)
//Space complexity: O(1)