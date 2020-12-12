// Problem: Mixtures
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/MIXTURES/
// Memory Limit: 1536 MB
// Time Limit: 3000 ms
// Parsed on: 12-12-2020 17:12:04 IST (UTC+05:30)
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

int sum(int i, int j, vi &v){
	int sum = 0;
	for(int k = i; k <= j; k++) sum = (sum + v[k]) % 100;
	return sum;
}

void solve(int n)
{
  	vi v(n+1);
  	for(int i = 1; i <= n; i++) cin >> v[i];
  	
  	vvi dp(n+1, vi(n+1, 0));
  	
  	for(int i = 2; i <= n; i++){
  		int r = 1, c = i;
  		
  		while(c <= n){
  			int tmp = INT_MAX;
  			for(int pivot = r; pivot < c; pivot++){
  				tmp = min(tmp, dp[r][pivot] + dp[pivot+1][c] + sum(r, pivot, v) * sum(pivot+1, c, v));
  			}
  			
  			dp[r][c] = tmp;
  			r++; c++;
  		}
  	}
  	
  	cout << dp[1][n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // int t = 1;
    // cin >> t;
    int n;
    while(cin >> n) {
      solve(n);
    }

    return 0;
}