// Problems: https://leetcode.com/problems/base-7/
//           https://leetcode.com/problems/sum-of-digits-in-base-k/
//           https://leetcode.com/problems/convert-a-number-to-hexadecimal/

// Ref: https://www.geeksforgeeks.org/convert-a-number-from-base-a-to-base-b/
/******************************************************************************************************************/

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

// function to return ASCII value of a character
int value(char c) {
	if (c >= '0' and c <= '9') {
		return (int)(c - '0');
	}
	
    else {
    	return (int)(c - 'A' + 10);
    }
}

// function to convert a number (represented in the form of string 's') in base "base"
// to a number in base 10 (return the number in form of an int)
int convert_to_decimal(string &s, int base) {
	int n = sz(s);
	
	// initialize power of base
	int power = 1;
	
	// initialize result
	int res = 0;
	
	// decimal equivalent is (s[n-1] * base^0) + (s[n-2] * base^1) + (s[n-3] * base^2) + ...
	for(int i = n - 1; i >= 0; i--) {
		// a digit in input number must be less than number's base
		if(value(s[i]) >= base) {
			cout << "Invalid number\n";
			return INT_MAX;
		}
		
		// update result
		res += (value(s[i]) * power);
		
		// update power
		power *= base;
	}
	
	// return the final result
	return res;
}

// function to return equivalent character of a given value
char re_value(int x) {
	if (x >= 0 and x <= 9) {
		return (char)(x + '0');
	}
	
    else {
    	return (char)(x - 10 + 'A');
    }
}

// function to convert a number (represented in the form of an integer) in base 10
// to a number in base "base" (return the number in form of a string)
string convert_from_decimal(int num, int base) {		
	// initialize result
	string res = "";
	
	if(num == 0) {
		res.pb('0');
		return res;
	}

	// repeatedly divide num by base and take remainder
	while(num > 0) {
		// update result
		res.pb(re_value(num % base));
		
		// update num
		num /= base;
	}
	
	// reverse result
	reverse(res.begin(), res.end());
	
	// return the final result
	return res;
}

// function to convert a number (represented in the form of string 's') in base b1
// to a number in base b2 (return the number in form of a string)
string convert_number(string &s, int b1, int b2) {
	// base case
	if(sz(s) == 0) return "";
	
	// convert the number from base b1 to decimal
	int num = convert_to_decimal(s, b1);
	
	// convert the number from decimal to base b2
	string res = convert_from_decimal(num, b2);
	
	// return the final result
	return res;
}

void solve()
{
  	string s; cin >> s;
  	int b1, b2; cin >> b1 >> b2;
  	
  	string res = convert_number(s, b1, b2);
  	
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