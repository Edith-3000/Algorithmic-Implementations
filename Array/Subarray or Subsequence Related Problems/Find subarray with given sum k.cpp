/* Reference(s): https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/
   Problem ---> Given an unsorted array of integers, find a subarray which adds to a given number. If there 
                are more than one subarrays with the sum as the given number, print any of them.
*/

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

// Function to print subarray with sum as given sum = k
void find_subarr(vll &v, ll n, ll k) {
	map<ll, ll> m;
	
	// Maintains sum of elements so far 
	ll cur_sum = 0;
	
	for(ll i = 0; i < n; i++) {
		// add current element to curr_sum 
		cur_sum += v[i];
		
		// if curr_sum = target sum we found a subarray starting 
		// from index 0 and ending at index i 
		if(cur_sum == k) {
			for(ll j = 0; j <= i; j++) cout << v[j] << " ";
			return;
		}
		
		 // If curr_sum - sum already exists in map we have found a 
		 // subarray with target sum 
		if(m.find(cur_sum - k) != m.end()) {
			for(ll j = m[cur_sum - k] + 1; j <= i; j++) cout << v[j] << " ";
			return;
		}
		
		m[cur_sum] = i;
	}
}

void solve()
{
  	ll n, k; cin >> n >> k;
  	vll v(n);
  	for(ll i = 0; i < n; i++) cin >> v[i];
  	
  	find_subarr(v, n, k);
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

// Time complexity: O(n x log(n))