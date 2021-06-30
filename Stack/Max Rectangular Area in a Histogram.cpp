/* Link: https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

   PROBLEM STATEMENT: Find the largest rectangular area possible in a given histogram where the largest 
                      rectangle can be made of a number of contiguous bars. For simplicity, assume that all 
                      bars have same width and the width is 1 unit.
                      For example, consider the following histogram with 7 bars of heights 
                      {6, 2, 5, 4, 5, 1, 6}. The largest possible rectangle possible is 12.
*/

// METHOD - 1 (BRUTE FORCE APPROACH: O(n^2))

/* One by one consider all bars as starting points and calculate area of all rectangles starting with every
   bar. Finally return maximum of all possible areas.
*/

/********************************************************************************************************/

// METHOD - 2 O(n)
// The solution is based on such a simple observation that the height of an optimum rectangle will be equal 
// to that of at least one of the histograms. Then find the max area you can get assuming height equal to 
// that of a particular histogram. Iterate over all to find maximum result.

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

// Function which return the 0-based indices of the NSL elements 
// for every array element
vector<int> nsl_indices(vector<int> &v) {
	int n = (int)v.size();
	if(n <= 0) return v;

	// to store the final result
	vector<int> res(n);

	stack<pair<int, int>> st; 
	int pseudo_idx = -1;

	for(int i = 0; i < n; i++) {
		if(st.empty()) res[i] = pseudo_idx;
		else if(st.top().F < v[i]) res[i] = st.top().S;

		else {
			while(!st.empty() && st.top().F >= v[i]) st.pop();

			if(st.empty()) res[i] = pseudo_idx;
			else res[i] = st.top().S;
		}

		st.push({v[i], i});
	}

	// return the final res vector
	return res;
}

// Function which return the 0-based indices of the NSR elements 
// for every array element
vector<int> nsr_indices(vector<int> &v) {
	int n = (int)v.size();
	if(n <= 0) return v;

	// to store the final result
	vector<int> res(n);

	stack<pair<int, int>> st; 
	int pseudo_idx = n;

	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) res[i] = pseudo_idx;
		else if(st.top().F < v[i]) res[i] = st.top().S;

		else {
			while(!st.empty() && st.top().F >= v[i]) st.pop();

			if(st.empty()) res[i] = pseudo_idx;
			else res[i] = st.top().S;
		}

		st.push({v[i], i});
	}

	// return the final res vector
	return res;
}

int max_rect_in_hist(vi &v) {
	int n = (int)v.size();
	if(n == 0) return 0;
	
	vi nsl = nsl_indices(v);
	vi nsr = nsr_indices(v);
	
	vi area(n);
	for(int i = 0; i < n; i++) {
		area[i] = (nsr[i] - nsl[i] - 1) * v[i];
	}
	
	int res = *max_element(area.begin(), area.end());
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << max_rect_in_hist(v) << "\n";
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

// Time Complexity: O(n)
// Space Complexity: O(n), where n is v.size()