// Problem: C. Fox And Names
// Contest: Codeforces - Codeforces Round #290 (Div. 2)
// URL: https://codeforces.com/problemset/problem/510/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 05-06-2021 12:03:51 IST (UTC+05:30)
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

vvi g;
vs v;
vb vis;
vi sorted;
int n;
bool possible;

void topSort(int curr, set<int> &ancestors) {
	vis[curr] = 1;
	ancestors.insert(curr);
	
	for(auto child: g[curr]) {
		if(ancestors.find(child) != ancestors.end()) {
			possible = false;
			return;
		}
		
		if(!vis[child]) topSort(child, ancestors);
	}
	
	ancestors.erase(curr);
	sorted.pb(curr);
}

int get_id(char c) {
	return c - 'a';
}

void solve()
{
  	cin >> n;
  	
  	v.clear(); v.resize(n);
  	g.clear(); g.resize(26);
  	vis.clear(); vis.resize(26, false);
  	sorted.clear();
  	
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	for(int i = 0; i + 1 < n; i++) {
  		int pos = -1, j = 0, k = 0;
  		for(; j < sz(v[i]) and k < sz(v[i+1]); j++, k++) {
  			if(v[i][j] != v[i+1][k]) { pos = j; break; }
  		}
  		
  		if(pos == -1 and j < sz(v[i]) and k == sz(v[i+1])) {
  			cout << "Impossible\n";
  			return;
  		}
  		
  		if(pos != -1) g[get_id(v[i][pos])].pb(get_id(v[i+1][pos]));
  	}
  	
  	possible = true;
  	
  	for(int i = 0; i < 26; i++) {
  		if(!vis[i]) {
  			set<int> ancestors;
  			topSort(i, ancestors);
  		}
  	}
  	
  	if(!possible) { 
  		cout << "Impossible\n";
  		return;
  	}
  	
  	reverse(sorted.begin(), sorted.end());
  	
  	for(int i = 0; i < 26; i++) {
  		cout << char(sorted[i] + 'a');
  	}
  	
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