// PROBLEM STATEMENT: Problem: Given two strings - a pattern and a text, determine if the pattern appears 
//                             in the text and if it does, enumerate all its occurrences in O(|n|+|m|) time.
//                             n = text length, m = pattern length.

/***********************************************************************************************************************************************************/

/*
   # 𝑹𝒂𝒃𝒊𝒏-𝑲𝒂𝒓𝒑 𝒊𝒔 𝒆𝒂𝒔𝒊𝒆𝒓 𝒕𝒐 𝒊𝒎𝒑𝒍𝒆𝒎𝒆𝒏𝒕 𝒊𝒇 𝒘𝒆 𝒂𝒔𝒔𝒖𝒎𝒆 𝒕𝒉𝒂𝒕 𝒂 𝒄𝒐𝒍𝒍𝒊𝒔𝒊𝒐𝒏 𝒘𝒊𝒍𝒍 𝒏𝒆𝒗𝒆𝒓 𝒉𝒂𝒑𝒑𝒆𝒏, 𝒃𝒖𝒕 𝒊𝒇 𝒕𝒉𝒆 𝒑𝒓𝒐𝒃𝒍𝒆𝒎 
     𝒚𝒐𝒖 𝒉𝒂𝒗𝒆 𝒊𝒔 𝒂 𝒕𝒚𝒑𝒊𝒄𝒂𝒍 𝒔𝒕𝒓𝒊𝒏𝒈 𝒔𝒆𝒂𝒓𝒄𝒉𝒊𝒏𝒈 𝒕𝒉𝒆𝒏 𝑲𝑴𝑷 𝒘𝒊𝒍𝒍 𝒃𝒆 𝒎𝒐𝒓𝒆 𝒔𝒕𝒂𝒃𝒍𝒆 𝒏𝒐 𝒎𝒂𝒕𝒕𝒆𝒓 𝒘𝒉𝒂𝒕 𝒊𝒏𝒑𝒖𝒕 𝒚𝒐𝒖 𝒉𝒂𝒗𝒆. 
     𝑯𝒐𝒘𝒆𝒗𝒆𝒓, 𝑹𝒂𝒃𝒊𝒏-𝑲𝒂𝒓𝒑 𝒉𝒂𝒔 𝒎𝒂𝒏𝒚 𝒐𝒕𝒉𝒆𝒓 𝒂𝒑𝒑𝒍𝒊𝒄𝒂𝒕𝒊𝒐𝒏𝒔, 𝒘𝒉𝒆𝒓𝒆 𝑲𝑴𝑷 𝒊𝒔 𝒏𝒐𝒕 𝒂𝒏 𝒐𝒑𝒕𝒊𝒐𝒏.

   # Reference: https://stackoverflow.com/questions/23336807/when-to-use-rabin-karp-or-kmp-algorithms#:~:text=
                Rabin%2DKarp%20is%20easier%20to,KMP%20is%20not%20an%20option.
*/

/***********************************************************************************************************************************************************/

// LEGACY CONTENT: https://pastebin.com/jyyz7aGX

/***********************************************************************************************************************************************************/

// METHOD 1

// Reference: https://cp-algorithms.com/string/rabin-karp.html
//            https://cp-algorithms.com/string/string-hashing.html

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
// const int mod = 1e9+7;

// ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
//                          while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
// ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

void precomputing(int n, string &text, ll p, ll mod, vll &p_pow, vll &pref_hash) {
    // precomputing powers of p modulo mod
    p_pow[0] = 1LL;
    
    for(int i = 1; i < sz(p_pow); i++) {
        p_pow[i] = (p_pow[i - 1] * p) % mod;
    }
    
    // precomputing prefix hashes of text
    for(int i = 0; i < n; i++) {
        ll contri = ((text[i] - 'a' + 1) * p_pow[i]) % mod;
        pref_hash[i] = contri;
        if(i > 0) pref_hash[i] = (pref_hash[i] + pref_hash[i - 1]) % mod;
    }
}

// Rabin-Karp Algorithm which return the indices(0-based) of all occurrences of pat in text

// NOTE: in the below algo, hash(string) is calculated using polynomial rolling hash function, 
//       although many other hash functions exist
vi rabin_karp_algo(string &text, string &pat) {
    int n = sz(text), m = sz(pat);
    
    // base case
    if(n < m) return vi();
    
    // it is reasonable to make p a prime number roughly equal to the number of unique characters 
    // in the input alphabet
    ll p = 31;
    
    // mod should be a large prime number, such that chances of generated hashes' collisions are reduced,
    // and also shouldn't be that large that we aren't able to make calculations
    ll mod = 1e9 + 9;
    
    // doing precomputations
    vll p_pow(max(n, m)), pref_hash(n);
    precomputing(n, text, p, mod, p_pow, pref_hash);
    
    // calculating hash of pattern string
    ll pat_hash = 0LL;
    
    for(int i = 0; i < m; i++) {
        ll contri = ((pat[i] - 'a' + 1) * p_pow[i]) % mod;
        pat_hash = (pat_hash + contri) % mod;
    }
    
    // store the indices of all occurrences of pattern in text
    vi res;
    
    for(int i = 0; i <= (n - m); i++) {
        ll txt_hash = pref_hash[i + m - 1];
        if(i > 0) txt_hash = (txt_hash - pref_hash[i - 1] + mod) % mod;
        
        if(txt_hash == (pat_hash * p_pow[i]) % mod) {
            res.pb(i);
        }
    }
    
    return res;
}

void solve()
{
    cout << "Enter the text(haystack): ";
    string text; cin >> text; cout << text <<"\n";

    cout << "Enter the pattern to be searched(needle): ";
    string pat; cin >> pat; cout << pat <<"\n";
    
    vi res = rabin_karp_algo(text, pat);
    
    for(auto x: res) {
        cout << x << " ";
    }
    
    cout << "\n";
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

/*

Sample i/p:

aabsgksaabsghaabs
aabs

Sample o/p:

Enter the text(haystack): aabsgksaabsghaabs
Enter the pattern to be searched(needle): aabs
0 7 13 

*/

// Time complexity: O(n + m)

/***********************************************************************************************************************************************************/

// METHOD 2 (Using Prefix Sum)

// "Strings/String Matching(or Searching) Algorithms/Rabin-Karp Algorithm/Rabin-Karp Algorithm using Prefix Sum.cpp"