// Problem: https://www.interviewbit.com/problems/longest-common-prefix/
/*******************************************************************************************************/

// METHOD - 1 (NAIVE APPROACH)
// Ref: https://www.geeksforgeeks.org/longest-common-prefix-using-character-by-character-matching/

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

string find_ans(vector<string> &v) {
	string res = "";
	int n = v.size();
	if(n == 0) return res;
	
	int mn = INT_MAX;
	for(int i = 0; i < n; i++) {
		mn = min(mn, (int)v[i].size());
	}
	
	for(int j = 0; j < mn; j++) {
		bool ok = 1;
		for(int i = 1; i < n; i++) {
			ok &= (v[i][j] == v[i-1][j]);
		}
		
		if(ok) res += v[0][j];
		else return res;
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vector<string> v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << find_ans(v);
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

// TC: O(n x m), where n = #strings in input vector
//                     m = length of longest common common prefix

/******************************************************************************************************/

// METHOD - 2 (SORTING APPROACH)
// Ref: https://www.geeksforgeeks.org/longest-common-prefix-using-sorting/

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

string find_ans(vector<string> &v) {
	string res = "";
	int n = v.size();
	if(n == 0) return res;
	if(n == 1) return v[0];
	
	sort(v.begin(), v.end());	
	
	int mn = min(v[0].size(), v[n-1].size());
	int i = 0;
	
	while(i < mn and v[0][i] == v[n-1][i]) {
		res += v[0][i];
		i += 1;
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vector<string> v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << find_ans(v);
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

// Time Complexity: O(MAX x n x log n ), where n  = n = #strings in input vector 
//                                             MAX = length of the longest string 
// This is because the comparison of two strings would take at most O(MAX) time and for sorting n 
// strings, we would need O(MAX x n x log n ) time.

/***************************************************************************************************/