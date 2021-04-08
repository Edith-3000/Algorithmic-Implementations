// Problem: https://leetcode.com/problems/max-consecutive-ones-iii/
/********************************************************************************************************/

// NOTE: The below code also gives the start and end indices of the segment, which is in accordance with
//       the question: https://www.interviewbit.com/problems/max-continuous-series-of-1s/
//       Other things in both the questions are same.

/********************************************************************************************************/

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

vi max_consec_1s(vi &v, int k) {
	int n = (int)v.size();
	
	int i = 0, j = 0, cnt0 = 0;
	int L = 0, R = 0, len = 0;
	
	while(j < n) {
		if(v[j] == 0) cnt0++;
		
		if(cnt0 > k) {
			if(v[i] == 0) cnt0--;
			i++;
			if(i > j) { j++; continue; }
		}
		
		if(len < (j - i + 1)) {
			len = j - i + 1;
			L = i;
			R = j;
		}
		
		j++;
	}
	
	vi res;
	for(int i = L; i <= R; i++) res.pb(i);
	
	return res;
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vi res = max_consec_1s(v, k);
  	
  	cout << res.size() << "\n";
  	for(int i = 0; i < (int)res.size(); i++) {
  		cout << res[i] << " ";
  	}
  	
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