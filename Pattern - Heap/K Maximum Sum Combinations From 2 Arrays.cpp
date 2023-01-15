// Problem: https://www.interviewbit.com/problems/n-max-pair-combinations/
// Similar problem: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

// Ref: https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/
/***************************************************************************************************************************************************/

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

vi max_k_sum_pairs(vi &v1, vi &v2, int k) {
	int n = (int)v1.size();
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	// max heap which contains tuple of the format (sum, (i, j)) i and j are the
	// indices of the elements from vector v1 and vector v2 which make up the sum.
	priority_queue<pair<int, pii>> q;
	q.push({v1[n-1] + v2[n-1], {n - 1, n - 1}});
	
	// set is used to store the indices of the  pair(i, j) to make sure the indices 
	// doe not repeat inside max heap.
	set<pii> s;
	s.insert({n - 1, n - 1});
	
	// to store the final result
	vi res;
	
	// iterate upto k
	for(int cnt = 0; cnt < k; cnt++) {
		pair<int, pii> p = q.top();
		q.pop();
		
		res.pb(p.F);
		int i = p.S.F;
		int j = p.S.S;
		
		 // insert only if the pair (i, j - 1) is not already present inside the set 
		 // i.e. no repeating pair should be present inside the heap.
		if(i >= 0 and j > 0 and s.find({i, j - 1}) == s.end()) {
			q.push({v1[i] + v2[j-1], {i, j - 1}});
			s.insert({i, j - 1});
		}
		
		// insert only if the pair (i - 1, j) is not present inside the heap.
		if(i > 0 and j >= 0 and s.find({i - 1, j}) == s.end()) {
			q.push({v1[i-1] + v2[j], {i - 1, j}});
			s.insert({i - 1, j});
		}
	}
	
	return res;
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v1(n), v2(n);
  	
  	for(int i = 0; i < n; i++) cin >> v1[i];
  	for(int i = 0; i < n; i++) cin >> v2[i];
  	
  	vi res = max_k_sum_pairs(v1, v2, k);
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