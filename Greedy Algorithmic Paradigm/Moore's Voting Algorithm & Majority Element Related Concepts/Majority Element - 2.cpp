// Problem: https://www.interviewbit.com/problems/n3-repeat-number/
//          https://leetcode.com/problems/majority-element-ii/description/

// Ref: https://www.youtube.com/watch?v=yDbkQd9t2ig
/****************************************************************************************************************************/

// NOTE: In this problem there can be maximum 2 and minimum 0 majority elements.
// For more explanation on this see in the comment section of the above video link.

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

// this algorithm always return the majority element(s) if present, 
// otherwise it returns any candidates which have to be validated 
pii moores_voting_algo(vi &v) {
	int n = (int)v.size();
	int cnt1 = 0, candidate1 = INT_MAX;
	int cnt2 = 0, candidate2 = INT_MAX;
	
	for(int i = 0; i < n; i++) {
		if(v[i] == candidate1) cnt1 += 1;
		else if(v[i] == candidate2) cnt2 += 1;
		else if(cnt1 == 0) {
			cnt1 = 1;
			candidate1 = v[i];
		}
		
		else if(cnt2 == 0) {
			cnt2 = 1;
			candidate2 = v[i];
		}
		
		else cnt1 -= 1, cnt2 -= 1;
	}
	
	return {candidate1, candidate2};
}

bool validated(vi &v, int candidate) {
	int n = (int)v.size();
	int cnt = 0;
	
	for(int i = 0; i < n; i++) {
		if(v[i] == candidate) cnt += 1;
	}
	
	return cnt > (n / 3);
}

int find_majority(vi &v) {
	int n = (int)v.size();
	if(n == 0) return INT_MAX;
	if(n == 1) return v[0];
	
	pii candidates = moores_voting_algo(v);
	
	if(validated(v, candidates.F)) return candidates.F;
	if(validated(v, candidates.S)) return candidates.S;
	
	return INT_MAX;
}

void solve()
{
 	int n; cin >> n;
 	vi v(n);
 	for(int i = 0; i < n; i++) cin >> v[i];
 	
 	int res = find_majority(v);
 	if(res == INT_MAX) cout << "No majority element\n";
 	else cout << res << "\n";
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