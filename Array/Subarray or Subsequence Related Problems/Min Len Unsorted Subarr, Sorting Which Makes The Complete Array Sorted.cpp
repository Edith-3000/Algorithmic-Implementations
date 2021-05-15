// Problem: https://www.interviewbit.com/problems/maximum-unsorted-subarray/
// Ref: https://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/
//      https://www.youtube.com/watch?v=Hg03KTli9co
/********************************************************************************************************************/

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

vi find_ans(vi &v) {
	int n = (int)v.size();
	
	// base case
	if(n <= 1) {
		vi res = {-1};
		return res;	
	}
	
	// if array is already sorted
	bool ok = 1;
	for(int i = 1; i < n; i++) {
		ok &= (v[i] >= v[i-1]); 
	}
	
	if(ok) {
		vi res = {-1};
		return res;
	}
	
	// Main algorithm ===>
	// 1. from the beginning of the array find the index upto which array is sorted
	int start = -1, end = n;
	for(int i = 0; i + 1 < n; i++) {
		if(v[i] <= v[i+1]) start = i;
		else break;
	}
	
	start += 1;
	
	// 2. from the end of the array find the index upto which array is sorted
	for(int i = (n - 1); i >= start + 1; i--) {
		if(v[i] >= v[i-1]) end = i;
		else break;
	}
	
	end -= 1;
	
	// 3. find the minimum and maximum in the subarray from [start, end]
	int mx = *max_element(v.begin() + start, v.begin() + end + 1);
	int mn = *min_element(v.begin() + start, v.begin() + end + 1);
	
	int mn_idx = -1, mx_idx = -1;
	
	// 4. find the correct position of the minimum in the subarr [0, start]
	for(int i = 0; i <= start; i++) {
		if(v[i] > mn) { mn_idx = i; break; } 
	}
	
	if(mn_idx == -1) mn_idx = start;
	
	// 5. find the correct position of the maximum in the subarr [end, n-1]
	for(int i = (n - 1); i >= end; i--) {
		if(v[i] < mx) { mx_idx = i; break; } 
	}
	
	if(mx_idx == -1) mx_idx = end;
	
	// 6. required subarray is the subarray [mn_idx, mx_idx]
	vi res(2);
	res[0] = mn_idx, res[1] = mx_idx;
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vi res = find_ans(v);
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)