// Problem: https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
//          https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/
//          https://leetcode.com/problems/shortest-palindrome/

// Reference(s): https://bit.ly/3vFvsHM
//               https://www.youtube.com/watch?v=c4akpqTwE5g

/******************************************************************************************************************************************************************/

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

// This variant of prefix_function_optimized() function returns lps of the complete string 's', 
// instead of returning the whole lps[] array 
int prefix_function_optimized(string &s) {
    int n = sz(s);
    
    // lps[i] = the length of the longest proper prefix which
    //          is also a suffix of the string s[0...i]
    vi lps(n);
    
    // since proper prefix of a string of length 1 can be of length 0
    lps[0] = 0;
 
    // traverse the string
    for (int i = 1; i < n; i++) {
        int prev_ind = lps[i - 1];
 
        while (prev_ind > 0 and s[i] != s[prev_ind]) {
            prev_ind = lps[prev_ind - 1];
        }
        
        if(s[prev_ind] == s[i]) prev_ind += 1;

        // update the lps size for string [0....i]
        lps[i] = prev_ind;
    }
 
    // return lps[n - 1] calculated
    return lps[n - 1];
}

// returns the length of the longest prefix palindrome which is also a suffix in string 's', 
// such that prefix and suffix do not overlap
int longest_prefix_palindrome(string &s) {
    // append a character to separate the string (i.e to avoid overlap)
    string tmp = s + '?';
    
    // append the reverse of the string
    reverse(s.begin(), s.end());
    tmp += s;
    
    // reverting back string 's'
    reverse(s.begin(), s.end());
    
    return prefix_function_optimized(tmp);
}

int min_chars_add(string &s) {
    int n = s.size();
    return n - longest_prefix_palindrome(s);
}

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    
    int res = min_chars_add(s);
    string tmp = s;
    reverse(tmp.begin(), tmp.end());    
    
    cout << res << "\n";
    cout << "The palindromic string after adding characters in the front is --->\n";
    cout << tmp.substr(0, res) + s << "\n";
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
    cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}