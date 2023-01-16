// Problem: https://www.geeksforgeeks.org/job-sequencing-problem/

// Ref: https://www.youtube.com/watch?v=LjPx4wQaRIs&list=PLgUwDviBIf0pmWCl2nepwGDO05a0-7EfJ&index=3

/*****************************************************************************************************************************************************************/

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

struct Job {
	int id, dead, profit;
};

bool cmp(const Job &j1, const Job &j2) {
	if(j1.profit == j2.profit) {
		if(j1.dead == j2.dead) return j1.id < j2.id;
		else return j1.dead > j2.dead;
	}
	
	else return j1.profit > j2.profit;
}

void job_sequencing(vector<Job> &v) {
	int n = sz(v);

	if(n == 0) {
		cout << 0 << "\n";
		return;
	}
	
	sort(v.begin(), v.end(), cmp);
	
	int mx = v[0].dead;

	for(int i = 1; i < n; i++) {
		mx = max(mx, v[i].dead);
	}
	
	vi vis(mx + 1, 0);
	
	ll mx_prof = v[0].profit;
	vis[v[0].dead] = v[0].id;
	
	for(int i = 1; i < n; i++) {
		for(int j = v[i].dead; j >= 1; j--) {
			if(!vis[j]) {
				mx_prof += v[i].profit;
				vis[j] = v[i].dead;
				break;
			}
		}
	}
	
	cout << "Max Profit = " << mx_prof << "\n";

	cout << "Following jobs with IDs must be performed on incremental days --->\n";
	for(int i = 1; i <= mx; i++) {
		if(vis[i]) cout << vis[i] << " ";
	}
	
	cout << "\n";
}

void solve()
{
  	int n; cin >> n;
  	vector<Job> v(n);
  	
  	for(int i = 0; i < n; i++) {
  		cin >> v[i].id >> v[i].dead >> v[i].profit;
  	}
  	
  	job_sequencing(v);
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

// Time complexity: O(n x log(n)) + O(n x m)
// Space complexity: O(m), where m = maximum deadline present

// NOTE: The time complexity of O(n x m) can be reduced by using the concept similar to the one used
//       in this problem: https://www.spoj.com/problems/CLFLARR/