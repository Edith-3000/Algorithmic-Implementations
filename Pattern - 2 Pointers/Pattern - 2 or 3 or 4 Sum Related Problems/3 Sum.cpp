// Problem: https://leetcode.com/problems/3sum/

// Ref: https://www.youtube.com/watch?v=onLoX6Nhvmg
//      https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/
/************************************************************************************************************************************/

// METHOD - 1 (Using Hashing)

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
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

vvi _3_sum(vi &v) {
	vvi res;
	int n = (int)v.size();
	if(n == 0) return res;
	
	map<int, int> m;
	for(int i = 0; i < n; i++) m[v[i]]++;
	
	set<vi> s;
	for(int i = 0; i < n; i++) {
		m[v[i]]--;
		for(int j = i + 1; j < n; j++) {
			m[v[j]]--;
			int x = v[i] + v[j];
			x = -x;
			if(m[x] > 0) {
				vi tmp(3);
				tmp[0] = v[i]; tmp[1] = v[j]; tmp[2] = x;
				sort(tmp.begin(), tmp.end());
				s.insert(tmp);
			}
			
			m[v[j]]++;			
		}
		
		m[v[i]]++;
	}
	
	for(auto vec: s) res.pb(vec);
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vvi res = _3_sum(v);
  	for(auto vec: res) {
  		for(auto x: vec) cout << x << " ";
  		cout << "\n";
  	}
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

// TC: O(n^2 x log(m))
// SC: O(n + m), where m are the possible triplets

/*****************************************************************************************************/

// METHOD - 2 (Using 2 Pointers)

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
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

vvi _3_sum(vi &v) {
	vvi res;
	int n = (int)v.size();
	if(n == 0) return res;
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i + 2 < n; i++) {
		// to avoid duplicacy
		if(i and v[i] == v[i-1]) continue;
		
		// from here it is normal 2 sum problem
		int lo = i + 1, hi = n - 1, sum = 0 - v[i];
		
		while(lo < hi) {
			if(v[lo] + v[hi] == sum) {
				vi tmp(3);
				tmp[0] = v[i]; tmp[1] = v[lo]; tmp[2] = v[hi];
				res.pb(tmp);
				
				// to avoid duplicacy
				while(lo < hi and v[lo] == v[lo+1]) lo++;
				while(lo < hi and v[hi] == v[hi-1]) hi--;
				lo++; hi--;
			}
			
			else if(v[lo] + v[hi] < sum) lo++;
			else hi--;
		}
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vvi res = _3_sum(v);
  	for(auto vec: res) {
  		for(auto x: vec) cout << x << " ";
  		cout << "\n";
  	}
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

// TC: O(n^2)
// SC: O(m), where m are the possible triplets