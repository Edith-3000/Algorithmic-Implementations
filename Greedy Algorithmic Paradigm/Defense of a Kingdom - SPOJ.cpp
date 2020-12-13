// Problem: Defense of a Kingdom
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/DEFKIN/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// Parsed on: 13-12-2020 14:25:12 IST (UTC+05:30)
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
  	int w, h, n; cin >> w >> h >> n;
  	vi x(n), y(n);
  	for(int i = 0; i < n; i++){
  		cin >> x[i] >> y[i];
  	}
  	
  	if(n == 0){
  		cout << (w * h) << "\n";
  		return;
  	}
  	
  	sort(x.begin(), x.end());
  	sort(y.begin(), y.end());
  	
  	int dx = x[0] - 1;
  	int dy = y[0] - 1;
  	
  	for(int i = 1; i < n; i++){
  		dx = max(dx, x[i]-x[i-1]-1);
  		dy = max(dy, y[i]-y[i-1]-1);
  	}
  	
  	dx = max(dx, w-x[n-1]);
  	dy = max(dy, h-y[n-1]);
  	
  	cout << (dx * dy) << "\n";
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