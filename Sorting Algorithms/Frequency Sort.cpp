/* Ref: https://www.geeksforgeeks.org/sort-elements-by-frequency/
        https://www.educative.io/edpresso/the-frequency-sort-algorithm

   Question based on this concept --->
   https://leetcode.com/problems/sort-array-by-increasing-frequency/
   https://leetcode.com/problems/sort-characters-by-frequency/
*/

/* The frequency sort algorithm is used to output elements of an array in descending order of their 
   frequencies.
   NOTE: If two elements have the same frequencies, then the element that occurs first in the input is
         printed first.
*/

// The frequency sort algorithm can be implemented in many ways. 
// Below implementation uses a hash table.

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

class cmp {
	public: 
		bool operator() (const pair<int, pii> &p1, const pair<int, pii> &p2) {
			if(p1.S.F == p2.S.F) return p1.S.S < p2.S.S;
			return p1.S.F > p2.S.F;
	    }
};

vi frequency_sort(vi &v, int n) {
	if(n <= 0) return vi();
	
	unordered_map<int, pii> hash;
	
	for(int i = 0; i < n; i++) {
		if(hash.find(v[i]) != hash.end()) hash[v[i]].F++;
		else hash[v[i]] = {1, i};
	}
	
	vector<pair<int, pii>> t;
	for(auto it = hash.begin(); it != hash.end(); it++) {
		t.pb({it->F, it->S});
	}
	
	sort(t.begin(), t.end(), cmp());	
	
	vi res;
	for(int i = 0; i < (int)t.size(); i++) {
		int cnt = t[i].S.F;
		while(cnt--) res.pb(t[i].F);
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vi res = frequency_sort(v, n);
  	for(auto x: res) cout << x << " ";
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

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}