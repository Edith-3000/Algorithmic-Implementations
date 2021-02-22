// Approach: https://www.geeksforgeeks.org/maximum-count-of-pairs-having-equal-sum-based-on-the-given-conditions/
/*************************************************************************************************************/

// Problem: C. Boats Competition
// Contest: Codeforces - Codeforces Round #661 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1399/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 22-02-2021 11:27:16 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

void solve()
{
  	int n; cin >> n;
  	vi v(n), freq(n + 1, 0);
  	
  	for(auto &x: v) {
  		cin >> x;
  		freq[x]++;
  	}
  	
  	int mini = *min_element(v.begin(), v.end());
  	int maxi = *max_element(v.begin(), v.end());
  	
  	int res = 0;
  	
  	for(int sum = 2 * mini; sum <= 2 * maxi; sum++) {
  		int tmp = 0;
  		for(int i = 1; i < (sum + 1)/2; i++) {
  			if(sum - i <= maxi) tmp += min(freq[i], freq[sum - i]);
  		}
  		
  		if(sum % 2 == 0) tmp += freq[sum/2] / 2;
  		res = max(res, tmp);
  	}
  	
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}