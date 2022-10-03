// NOTE: Do not know why the same code was not getting an AC when the loop for binary search was using the ((R - L) > eps) condition as in this link:--->
//       https://pastebin.com/q2bhsu8n

/**************************************************************************************************************************************************************/

// Problem: B. Meeting on the Line
// Contest: Codeforces - Codeforces Round #823 (Div. 2)
// URL: https://codeforces.com/contest/1730/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 03-10-2022 07:13:28 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

const double eps = 1e-9;

ll mod_exp(ll a, ll b) { a %= mod; if(a == 0) return 0LL; ll res = 1LL; 
                         while(b > 0) { if(b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
                         
ll mod_inv(ll a) { return mod_exp(a, mod - 2); } // works only for prime value of "mod"
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }

/******************************************************************************************************************************/

pair<bool, pair<double, double>> intersect(pair<double, double> cur_rng, pair<double, double> cur_person_range) {
	if((cur_rng.F > cur_person_range.S) or (cur_rng.S < cur_person_range.F)) {
		return {0, {-1, -1}};
	}
	
	cur_rng.F = max(cur_rng.F, cur_person_range.F);
	cur_rng.S = min(cur_rng.S, cur_person_range.S);
	
	return {1, cur_rng};
}

bool good(double T, pair<double, double> &cur_rng, ll n, vll &x, vll &t) {
	for(ll i = 0; i < n; i++) {
		if(t[i] > T) return false;
		
		double time_left = T - t[i];
		
		pair<double, double> cur_person_range = {x[i] - time_left, x[i] + time_left};
		
		pair<bool, pair<double, double>> p = intersect(cur_rng, cur_person_range);
		if(p.F == false) return false;
		else cur_rng = p.S;
	}
	
	return true;
}

// https://www.youtube.com/watch?v=JpItlEPYrao&ab_channel=CompetitiveCoding-NewtonSchool
// https://codeforces.com/blog/entry/107293
void solve()
{
  	ll n; cin >> n;
  	
  	vll x(n), t(n);
  	
  	for(ll i = 0; i < n; i++) cin >> x[i];
  	for(ll i = 0; i < n; i++) cin >> t[i];
  	
  	double res;
  	
  	pair<double, double> rng;
  	
  	double L = 0, R = 1e14;
  	
  	ll iterations = 100;
  	
  	while(iterations--) {
  		double mid = L + ((R - L) / 2.0);
  		
  		// check function begins
  		pair<double, double> cur_rng = {0, 1e8};
  		if(good(mid, cur_rng, n, x, t)) {
  			rng = cur_rng;
  			R = mid;
  			res = (cur_rng.F + cur_rng.S) / 2.0;
  		}
  		
  		else L = mid;
  	}
  	
  	cout << fixed << setprecision(6) << res << "\n";
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