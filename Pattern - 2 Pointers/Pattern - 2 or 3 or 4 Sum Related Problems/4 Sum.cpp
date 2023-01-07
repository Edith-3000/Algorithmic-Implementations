// Problem: https://www.interviewbit.com/problems/4-sum/
//          https://leetcode.com/problems/4sum/description/

// Ref: https://www.youtube.com/watch?v=4ggF3tXIAp0
/********************************************************************************************************************************/

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

vvi _4_sum(vi &v, ll target) {
	vvi res;
	int n = (int)v.size();
	if(n == 0) return res;
	
	sort(v.begin(), v.end());
	set<vi> s;
	
	for(int i = 0; i + 3 < n; i++) {
		for(int j = i + 1; j + 2 < n; j++) {
			for(int k = j + 1; k + 1 < n; k++) {
				ll sum = v[i] + v[j] + v[k]; 
				if(binary_search(v.begin() + k + 1, v.end(), target - sum)) {
					vi tmp(4);
					tmp[0] = v[i]; tmp[1] = v[j]; tmp[2] = v[k]; tmp[3] = target - sum;
					s.insert(tmp);
				}
			}
		}
	}
	
	for(auto vec: s) res.pb(vec);
	return res;
}

void solve()
{
  	int n; ll k;
  	cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vvi res = _4_sum(v, k);
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

// TC: O(n^3 x log(n))
// SC: O(n)

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

vvi _4_sum(vi &v, ll target) {
	vvi res;
	int n = (int)v.size();
	if(n == 0) return res;
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i + 3 < n; i++) {
		// to avoid duplicacy
		if(i and v[i] == v[i-1]) continue;
		
		for(int j = i + 1; j + 2 < n; j++) {
			// to avoid duplicacy
			if((i + 1) < j and v[j] == v[j-1]) continue;
			
			int lo = j + 1, hi = n - 1;
			while(lo < hi) {
				int req = target - (v[i] + v[j]);
				if(v[lo] + v[hi] == req) {
					vi tmp(4);
					tmp[0] = v[i]; tmp[1] = v[j]; tmp[2] = v[lo]; tmp[3] = v[hi];
					res.pb(tmp);
					
					// to avoid duplicacy
					while(lo < hi and v[lo] == v[lo+1]) lo++;
					while(lo < hi and v[hi] == v[hi-1]) hi--;
					lo++; hi--;
				}
				
				else if(v[lo] + v[hi] < req) lo++;
				else hi--;
			}
		}
	}
	
	return res;
}

void solve()
{
  	int n; ll k;
  	cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vvi res = _4_sum(v, k);
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

// TC: O(n x log(n)) + O(n^3)
// SC: O(m), where m are the possible triplets

// The same can also be implemented in this manner ===>
// https://pastebin.com/cQqjyaUe