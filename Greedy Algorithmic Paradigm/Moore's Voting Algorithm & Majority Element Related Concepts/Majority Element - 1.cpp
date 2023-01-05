// Problem: https://www.interviewbit.com/problems/majority-element/
//          https://leetcode.com/problems/majority-element/

// Ref: https://www.youtube.com/watch?v=bg6r_fgtpMQ
/***********************************************************************************************************************/

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

// this algorithm always return the majority element i present, 
// otherwise it returns any candidate which has to be validated 
int moores_voting_algo(vi &v) {
	int n = (int)v.size();
	int cnt = 1, candidate = v[0];
	
	for(int i = 1; i < n; i++) {
		if(v[i] == candidate) cnt += 1;
		else cnt -= 1;
		if(cnt == 0) {
			cnt = 1;
			candidate = v[i];
		}
	}
	
	return candidate;
}

int find_majority(vi &v) {
	int n = (int)v.size();
	if(n == 0) return INT_MAX;
	
	int candidate = moores_voting_algo(v);
	return candidate;
}

void solve()
{
 	int n; cin >> n;
 	vi v(n);
 	for(int i = 0; i < n; i++) cin >> v[i];
 	
 	int res = find_majority(v);
 	cout << res << "\n";
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
// Auxiliary Space: O(1). 