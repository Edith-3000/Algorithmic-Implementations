// Problem: https://www.interviewbit.com/problems/sliding-window-maximum/
// Ref: https://www.youtube.com/watch?v=xFJXtB5vSmM
/*****************************************************************************************************/

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

vi max_of_all_subarr(vi &v, int k) {
	int n = (int)v.size();
	vi res;
	
	if(k > n) {
		res.pb(*max_element(v.begin(), v.end()));
		return res;
	}
	
	if(n == 0) return res;
	
	int i = 0, j = 0;
	deque<int> dq;
	
	while(j < n) {
		// removing all those elements which are to the left and also less 
		// than current element (v[j]), since these elements can't be candidates
		// for future answer 
		while(!dq.empty() and dq.back() < v[j]) dq.pop_back();
		
		// taking into consideration the current element
		dq.push_back(v[j]);
		
		// if window size not reached increment j
		if((j - i + 1) < k) j++;
		
		// if window size has been reached
		else {
			// the maximum element for the current window will always be at front
			res.pb(dq.front());
			
			// removing the calculation done for the ith element i.e. v[i]
			if(dq.front() == v[i]) dq.pop_front();
			
			// sliding the window
			i++; j++;
		}
	}
	
	return res; 
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vi res = max_of_all_subarr(v, k);
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

// Time Complexity: O(n). 
// It seems more than O(n) at first look. It can be observed that every element of array is added and 
// removed at most once. So there are total 2n operations.

// Auxiliary Space: O(k). 
// Elements stored in the dequeue take O(k) space.