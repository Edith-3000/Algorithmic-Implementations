// NOTE: THIS PROBLEM IS MARKED AS "HIDDEN" ON SPOJ (DESPITE BEING COMPLETELY CORRECT THE BELOW CODE 
//       IS NOT BEING ACCEPTED ON THE JUDGE).

/******************************************************************************************************/

// BOTTOM UP DP

// Problem: Is he smart or is he smart
// Contest: SPOJ - Tutorial
// URL: https://www.spoj.com/problems/EINST/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// Parsed on: 01-12-2020 22:36:26 IST (UTC+05:30)
// Author: kapil_choudhary

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
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

const int mod = 1e9+7;

void solve()
{
  	int x, n; cin >> x >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	vi dp(x + 1, 0);
  	
  	for(int i = 1; i <= x; i++){
  		int tmp = INT_MAX;
  		for(int d = 0; d < n; d++){
  			if(i - (v[d]) >= 0) tmp = min(tmp, dp[i - v[d]]);
  		}
  		
  		if(tmp != INT_MAX) dp[i] = 1 + tmp;
  	}
  	
  	if(x == 0) cout << 0 << "\n";
  	else if(dp[x] == 0) cout << "No solution\n";
  	else cout << dp[x] << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

// Time complexity: O(x * n), where x is the amount to be changed & n are the #denominations
// Space complexity: O(x)