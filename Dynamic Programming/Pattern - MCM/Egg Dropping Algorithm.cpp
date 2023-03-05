/* Link: https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
         https://datagenetics.com/blog/july22012/index.html
         https://www.interviewbit.com/problems/egg-drop-problem/

   PROBLEM: There are n number of eggs and a building which has k floors. 
            Write an algorithm to find the minimum number of drops required to find the 
            critical or threshold floor.
            Critical/Threshold floor -> The highest floor from which if the egg is dropped
                                        it won't break.

Note: # One trial is ===> dropping an egg once from the particular floor.
      # If egg does not break after dropping, will be used again.
      # If egg breaks when dropped from some floor then it will break if dropped from any 
        higher floor.
      # If egg does not break when dropped from some floor then it will not break if dropped
        from any lower floor.
*/

/*****************************************************************************************************************************************************************/

/* Few Important points regarding this algorithm ⇒
   ● Egg dropping refers to a class of problems in which it is important to find the correct 
     response without exceeding a (low) number of certain failure states. 

   ● In a toy example, there is a tower of n floors, and an egg dropper with k ideal eggs. The 
     physical  properties of the ideal egg is such that it will not shatter if it is dropped from 
     floor n* or below and will get completely damaged  if it is dropped from floor (n* + 1)
     or above.

   ● The problem is to find a strategy such that the egg dropper can determine the floor 
     n*(critical or threshold floor) in as few egg drops as possible. 

   ● This problem has many applications in the real world such as avoiding a call out to the 
     slow HDD, or attempting to minimize cache misses, or running a large number of expensive 
     queries on a database.
*/

/*****************************************************************************************************************************************************************/

/* ● So basically: For the 𝙬𝙤𝙧𝙨𝙩 𝙘𝙖𝙨𝙚, using the 𝙗𝙚𝙨𝙩 𝙩𝙚𝙘𝙝𝙣𝙞𝙦𝙪𝙚 we have to 𝙢𝙞𝙣𝙞𝙢𝙞𝙨𝙚 𝙩𝙝𝙚 𝙩𝙤𝙩𝙖𝙡 
                   #𝙖𝙩𝙩𝙚𝙢𝙥𝙩𝙨 to find the 𝙘𝙧𝙞𝙩𝙞𝙘𝙖𝙡/𝙩𝙝𝙧𝙚𝙨𝙝𝙤𝙡𝙙 𝙛𝙡𝙤𝙤𝙧.

                   https://youtu.be/S49zeUjeUL0?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&t=572

   ● The solution is to try dropping an egg from every floor(from 1 to k) and recursively 
     calculate the minimum number of droppings needed in the worst case. The floor which gives
     the minimum value in the 𝙬𝙤𝙧𝙨𝙩 𝙘𝙖𝙨𝙚 is going to be part of the solution.

   ● Meaning of a 𝙬𝙤𝙧𝙨𝙩-𝙘𝙖𝙨𝙚 𝙨𝙘𝙚𝙣𝙖𝙧𝙞𝙤: 𝙬𝙤𝙧𝙨𝙩-𝙘𝙖𝙨𝙚 𝙨𝙘𝙚𝙣𝙖𝙧𝙞𝙤 gives the user the 𝙨𝙪𝙧𝙚𝙩𝙮 of the 
     threshold floor. For example - If we have ‘1’ egg and ‘k’ floors, we will start dropping 
     the egg from the first floor till the egg breaks suppose on the ‘kth’ floor so the number 
     of tries to give us 𝙨𝙪𝙧𝙚𝙩𝙮 is ‘k’.

   ● Another example for 𝙬𝙤𝙧𝙨𝙩-𝙘𝙖𝙨𝙚 𝙨𝙘𝙚𝙣𝙖𝙧𝙞𝙤 ----->
     Let there be ‘2’ eggs and ‘2’ floors then-:

     If we try throwing from ‘1st’ floor:
      # Number of tries in worst case= 1 + max(0, 1)
      # 0 => If the egg breaks from first floor then it is threshold floor (best case possibility).
      # 1 => If the egg does not break from first floor we will now have ‘2’ eggs and 1 floor to 
        test which will give answer as ‘1’ (worst case possibility).
      # We take the worst case possibility in account, so 1 + max(0, 1) = 2.

     If we try throwing from ‘2nd’ floor:
      # Number of tries in worst case= 1 + max(1, 0).
      # 1 => If the egg breaks from second floor then we will have 1 egg and 1 floor to find 
        threshold floor.(Worst Case).
      # 0 => If egg does not break from second floor then it is threshold floor.(Best Case)
      # We take worst case possibility for surety, so 1 + max(1, 0) = 2.

     Now, The final answer is min(1st, 2nd, 3rd….., kth floor)
     So answer here(for f = 2) is ‘2’.
*/

/*****************************************************************************************************************************************************************/

// RECURSIVE IMPLEMENTATION
// Ref: https://www.youtube.com/watch?v=S49zeUjeUL0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=42

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

/*******************************************************************************************************************************************************************/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

int egg_drop(int floors, int eggs) {
    // base case(s)
    
    // if floors = 0 then no drops are required 
    // if floors = 1 then 1 drop is required
    if(floors == 0 or floors == 1) return floors;
    
    // if only one egg is there then min #drops in order
    // to surely find the critical floor = #floors
    if(eggs == 1) return floors;
    
    // initialising result
    int res = INT_MAX;
    
    // choice diagram code
    // check dropping from all the floors i.e. [1 to floors] and pick 
    // the minimum among those.
    // for every drop there are 2 scenarios - 
    // a) either egg will break b) or egg will not break

    // "k for loop scheme""
    for(int k = 1; k <= floors; k++) {
        // calculating temporary answer
        // for the worst case pick the maximum among a) and b)
        int tmp = 1 + max(egg_drop(k - 1, eggs - 1), 
                          egg_drop(floors - k, eggs));
        
        // calculation of res from temporary answers              
        res = min(res, tmp);
    }
    
    return res;
}

void solve()
{
    int floors, eggs; 
    cin >> floors >> eggs;
    
    if(eggs == 0 and floors != 0) cout << -1 << "\n";
    else cout << egg_drop(floors, eggs) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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

// Time Complexity: Exponential
// Auxiliary Space :O(1) ∵ There was no use of any data structure for storing values.
//                         Although recursion uses stack internally.

/*******************************************************************************************************************************************************************/

// MEMOIZED IMPLEMENTATION
// https://www.youtube.com/watch?v=gr2NtY-2QUY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=43

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

/*******************************************************************************************************************************************************************/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

vvi dp;

int egg_drop(int floors, int eggs) {
    // base case(s)
    
    // if floors = 0 then no drops are required 
    // if floors = 1 then 1 drop is required
    if(floors == 0 or floors == 1) return floors;
    
    // if only one egg is there then min #drops in order
    // to surely find the critical floor = #floors
    if(eggs == 1) return floors;
    
    // check if already calculated or not
    if(dp[floors][eggs] != -1) return dp[floors][eggs];
    
    // initialising result
    int res = INT_MAX;
    
    // choice diagram code
    // check dropping from all the floors 1 to floors and pick 
    // the minimum among those.
    // for every drop there are 2 scenarios - 
    // a) either egg will break b) or egg will not break

    // "k for loop scheme""
    for(int k = 1; k <= floors; k++) {
        // calculating temporary answer
        // for the worst case pick the maximum among a) and b)
        int tmp = 1 + max(egg_drop(k - 1, eggs - 1), 
                          egg_drop(floors - k, eggs));
        
        // calculation of res from temporary answers              
        res = min(res, tmp);
    }
    
    return dp[floors][eggs] = res;
}

void solve()
{
    int floors, eggs; 
    cin >> floors >> eggs;
    
    dp.clear();
    dp.resize(floors + 1);
    for(int i = 0; i <= floors; i++) dp[i].resize(eggs + 1, -1);
    
    if(eggs == 0 and floors != 0) cout << -1 << "\n";
    else cout << egg_drop(floors, eggs) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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

// dp[][] is a 2 D global matrix/vector of vectors, with size (floors + 1) x (eggs + 1) 
// and initialized with -1, memset(dp, -1, sizeof(dp));

// Time Complexity: O(floors^2 x eggs) 
// Auxiliary Space : O(floors x eggs) 

/*******************************************************************************************************************************************************************/

// SLIGHTLY OPTIMIZED MEMOIZED IMPLEMENTATION
// NOTE: Although the asymptotic complexity of this and above approach is same.
// Ref: https://www.youtube.com/watch?v=jkygQmOiCCI&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=44

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

/*******************************************************************************************************************************************************************/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

vvi dp;

int egg_drop(int floors, int eggs) {
    // base case(s)
    
    // if floors = 0 then no drops are required 
    // if floors = 1 then 1 drop is required
    if(floors == 0 or floors == 1) return floors;
    
    // if only one egg is there then min #drops in order
    // to surely find the critical floor = #floors
    if(eggs == 1) return floors;
    
    // check if already calculated or not
    if(dp[floors][eggs] != -1) return dp[floors][eggs];
    
    // initialising result
    int res = INT_MAX;
    
    // choice diagram code
    // check dropping from all the floors 1 to floors and pick 
    // the minimum among those.
    // for every drop there are 2 scenarios - 
    // a) either egg will break b) or egg will not break

    // "k for loop scheme""
    for(int k = 1; k <= floors; k++) {
        int down;

        if(dp[k-1][eggs - 1] != -1) down = dp[k-1][eggs - 1];
        else {
            down = egg_drop(k - 1, eggs - 1);
            dp[k-1][eggs - 1] = down;
        }
        
        int up;

        if(dp[floors - k][eggs] != -1) up = dp[floors - k][eggs];
        else {
            up = egg_drop(floors - k, eggs);
            dp[floors - k][eggs] = up;
        }
        
        // calculating temporary answer
        // for the worst case pick the maximum among a) and b)
        int tmp = 1 + max(down, up);
        
        // calculation of res from temporary answers              
        res = min(res, tmp);
    }
    
    return dp[floors][eggs] = res;
}

void solve()
{
    int floors, eggs; 
    cin >> floors >> eggs;
    
    dp.clear();
    dp.resize(floors + 1);
    for(int i = 0; i <= floors; i++) dp[i].resize(eggs + 1, -1);
    
    if(eggs == 0 and floors != 0) cout << -1 << "\n";
    else cout << egg_drop(floors, eggs) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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

// dp[][] is a 2 D global matrix/vector of vectors, with size (floors + 1) x (eggs + 1) 
// and initialized with -1, memset(dp, -1, sizeof(dp));

// Time Complexity: O(floors^2 x eggs) 
// Auxiliary Space : O(floors x eggs) 

/*******************************************************************************************************************************************************************/

// TABULATION IMPLEMENTATION
// Ref: https://www.youtube.com/watch?v=UvksR0hR9nA&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=43

// LEGACY CONTENT: https://pastebin.com/j525Nxrf

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }

/*******************************************************************************************************************************************************************/

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

int egg_drop(int floors, int eggs) {
    vvi dp(eggs + 1, vi(floors + 1));

    // initialisation of dp matrix
    
    // if eggs = 0, then no answer
    // if eggs = 1, then ans = #floors
    for(int j = 0; j <= floors; j++) dp[0][j] = -1, dp[1][j] = j;
    
    // if floors = 0, then ans = 0
    // if floors = 1, then ans = 1
    for(int i = 2; i <= eggs; i++) dp[i][0] = 0, dp[i][1] = 1;
    
    for(int i = 2; i <= eggs; i++) {
        for(int j = 2; j <= floors; j++) {
            int ans = INT_MAX;

            for(int k = 1; k <= j; k++) {
                int tmp = 1 + max(dp[i][j - k], dp[i - 1][k - 1]);
                ans = min(ans, tmp);
            }
            
            dp[i][j] = ans;
        }
    }
    
    return dp[eggs][floors];
}

void solve()
{
    int floors, eggs; 
    cin >> floors >> eggs;
    
    if(eggs == 0 and floors != 0) cout << -1 << "\n";
    else cout << egg_drop(floors, eggs) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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

// dp[][] is a 2 D global matrix/vector of vectors, with size (eggs + 1) x (floors + 1)

// Time Complexity: O(floors^2 x eggs) 
// Auxiliary Space : O(floors x eggs) 

/***************************************************************************************************************************************************************************************/

// BINARY SEARCH OPTIMIZATIONS OF ABOVE APPROACHES

/* The methods having TC: O(floors^2 x eggs) will give TLE verdict in LeetCode:--->
   https://leetcode.com/problems/super-egg-drop/
    
   So, the below approach uses binary search for the "K loop scheme"
*/

// Ref: https://leetcode.com/problems/super-egg-drop/discuss/792736/CPP-Explained-Recursive-greatermemoization-greateroptimization-greaterDP-oror-Well-Explained-oror-Easy-to-unserstand
//      https://www.youtube.com/watch?v=dakViFo0CM0&ab_channel=ForAllEpsilon (BEAUTIFUL EXPLANATION)
//      https://www.youtube.com/watch?v=fiW8EvvpmI0&ab_channel=ForAllEpsilon

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define sz(x) ((int)(x).size())
#define vset(v, n, val) v.clear(); v.resize(n, val)

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vull> vvull;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vs> vvs;

/************************************************** DEBUGGER *******************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector <vector<T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T> void _print(queue <T> v);
template <class T> void _print(priority_queue <T> v);
template <class T> void _print(stack <T> s);

// modify it's definition below as per need such as it can be used for STL containers with custom args passed
template <class T> void _print(T v); 

template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}"; }
template <class T> void _print(vector <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(vector <vector<T>> v) { cerr << "==>" << endl; for (vector<T> vec : v) { for(T i : vec) {_print(i); cerr << " "; } cerr << endl; } }
template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(multimap <T, V> v) { cerr << "[ "; for (auto i : v) {_print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.front()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(priority_queue <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(stack <T> v) { cerr << "[ "; while(!v.empty()) {_print(v.top()); v.pop(); cerr << " "; } cerr << "]"; }
template <class T> void _print(T v) {  }

/*******************************************************************************************************************************************************************/

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

vvi dp;

int egg_drop(int floors, int eggs) {
    // base case(s)
    
    // if floors = 0 then no drops are required 
    // if floors = 1 then 1 drop is required
    if(floors == 0 or floors == 1) return floors;
    
    // if only one egg is there then min #drops in order
    // to surely find the critical floor = #floors
    if(eggs == 1) return floors;
    
    // check if already calculated or not
    if(dp[floors][eggs] != -1) return dp[floors][eggs];
    
    // initialising result
    int res = INT_MAX;
    
    // initiating binary search bounds
    int L = 1, R = floors;
    
    while(L <= R) {
        int mid = L + ((R - L) >> 1);
        
        int egg_breaks = egg_drop(mid - 1, eggs - 1);
        int egg_not_breaks = egg_drop(floors - mid, eggs);
        
        // calculating temporary answer
        // for the worst case pick the maximum among a) egg_breaks and b) egg_not_breaks
        int tmp = 1 + max(egg_breaks, egg_not_breaks);
        
        // calculation of res from temporary answers
        res = min(res, tmp);
        
        // since we need to find best result for worst case
        if(egg_breaks >= egg_not_breaks) R = mid - 1;
        else L = mid + 1;
    }
    
    return dp[floors][eggs] = res;
}

void solve()
{
    int floors, eggs; 
    cin >> floors >> eggs;
    
    dp.clear();
    dp.resize(floors + 1);
    for(int i = 0; i <= floors; i++) dp[i].resize(eggs + 1, -1);
    
    if(eggs == 0 and floors != 0) cout << -1 << "\n";
    else cout << egg_drop(floors, eggs) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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

// Time Complexity: O(floors x eggs x log(floors)) 
// Auxiliary Space : O(floors x eggs)

/*******************************************************************************************************/