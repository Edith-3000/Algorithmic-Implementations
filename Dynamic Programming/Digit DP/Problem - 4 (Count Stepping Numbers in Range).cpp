// Problem: https://leetcode.com/problems/count-stepping-numbers-in-range/description/

// Reference: https://www.youtube.com/watch?v=ypPHL72ch4Q&t=763s

/*****************************************************************************************************************************************************************/

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

int dp[100][2][10][2];

void initDP() {
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 10; k++) {
                for(int l = 0; l < 2; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}

string subtractOne(string &t) {
    int n = t.length();
    int idx = n - 1;

    while(idx >= 0) {
        if(t[idx] != '0') break;
        idx -= 1;
    }

    assert (idx >= 0);

    string res = t;
    res[idx] = (char) (res[idx] - 1);

    for(int i = idx + 1; i < n; i++) {
        res[i] = '9';
    }

	idx = 0;
	while(idx < n) {
		if(res[idx] != '0') break;
		idx += 1;
	}
	
	if(idx < n) res = res.substr(idx);
	else res = "0";

    return res;
}

int countGoodNumbers(int idx, int tight, int lastDigit, int nonZeroUsed, string &str) {
    // base case(s)
    if(idx == str.length()) {
        if(nonZeroUsed == 1) return 1;
        else return 0;
    }

    // check if already calculated
    int res = dp[idx][tight][lastDigit][nonZeroUsed];
    if(res != -1) return res;

    res = 0;

    int start = 0, end = 9;
    if(tight == 1) end = str[idx] - '0';

    for(int i = start; i <= end; i++) {    
        if((nonZeroUsed == 1) and (abs(lastDigit - i) != 1)) continue; 

        int newTight = ((tight == 1) && (i == end)) ? 1 : 0;

        // For better explanation of value assignment to newTight refer below code
        // int newTight;
        // if(tight == 0) newTight = 0;
        // else {
        //     if(i == end) newTight = 1;
        //     else newTight = 0;
        // }

        int newNonZeroUsed = 0;
        if((nonZeroUsed == 1) || (i != 0)) newNonZeroUsed = 1;

        res = (res + countGoodNumbers(idx + 1, newTight, i, newNonZeroUsed, str)) % mod;
    }

    return dp[idx][tight][lastDigit][nonZeroUsed] = res;
}

int countSteppingNumbers(string &L, string &R) {	
	initDP();
	int x = countGoodNumbers(0, 1, 0, 0, R);
	
	string s = subtractOne(L);
	
	initDP();
	int y = countGoodNumbers(0, 1, 0, 0, s);
	
	int res = (x - y + mod) % mod;
	return res;
}

void solve()
{
  	string L, R; 
  	cin >> L >> R;
  	
  	int res = countSteppingNumbers(L, R);
  	
  	cout << res << "\n";
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