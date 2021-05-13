// Problem: https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
// Ref: https://www.youtube.com/watch?v=zcnVaVJkLhY
/****************************************************************************************************/

// Method - 1

// This method can be implemented using queue data structure, as given in GfG article
// Time complexity: O(n)
// Space complexity: O(n)

/****************************************************************************************************/

// METHOD - 2

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

// The function returns starting point (0-based indexed) if there is a possible 
// solution, otherwise returns -1
int find_index(vi &gas, vi &req) {
	int n = (int)gas.size();
	if(n == 0) return -1;
	if(n == 1) return 0;
	
	// consider first gas station as a starting point
	// end is the next gas station to be visited
	int start = 0, end = 1;
	
	// current amount of gas left
	int curr_gas = gas[start] - req[start];
	
	// run a loop while all gas stations are not visited.
    // or current gas < 0
	while(start != end or curr_gas < 0) {
		// if curremt amount of gas in vehicle becomes less than 0, then
        // remove the starting gas station from tour
		while(start != end and curr_gas < 0) {
			// Remove starting petrol pump. and making the start = next circular index
			curr_gas -= gas[start] - req[start];
			
			// if 0 is being considered as start again, then there is no possible result
			start = (start + 1) % n;
			if(start == 0) return -1;
		}
		
		// visit next gas station to the current tour
		curr_gas += gas[end] - req[end];
		
		// update the next gas station to be visited
		end = (end + 1) % n;
	}
	
	// return minimum start index if found
	return start;
}

void solve()
{
  	int n; cin >> n;
  	vi gas(n), req(n);
  	for(int i = 0; i < n; i++) cin >> gas[i];
  	for(int i = 0; i < n; i++) cin >> req[i];
  	
  	cout << find_index(gas, req) << "\n";
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

// Time complexity: O(n), since every element is visited at most 2 times.
// Space complexity: O(1)