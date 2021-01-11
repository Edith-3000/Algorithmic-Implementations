// Problem: Little Elephant and T-Shirts
// Contest: CodeChef - Practice(Medium)
// URL: https://www.codechef.com/problems/TSHIRTS
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 06-01-2021 12:10:17 IST (UTC+05:30)
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

ll dp[100][1 << 10];
bool has[10][100];
int n;

ll driver(int shirt, int mask) {
	// base case(s)
	if(mask == 0) return 1;
	if(shirt >= 100) return 0;
	
	// check if already calculated or not
	if(dp[shirt][mask] != -1) return dp[shirt][mask];
	
	ll res = 0;
	
	// Option 1
	res = (res + driver(shirt + 1, mask)) % mod;
	
	// Option 2
	for(int i = 0; i < n; i++) {
		if((mask & (1 << i)) == 0) continue;
		if(has[i][shirt]) {
			res = (res + driver(shirt + 1, mask ^ (1 << i))) % mod;
		} 
	}
	
	return dp[shirt][mask] = res;
}

void solve()
{
  	memset(dp, -1, sizeof(dp));
  	memset(has, 0, sizeof(has));
  	
  	cin >> n; 
  	cin.ignore();
  	for(int i = 0; i < n; i++) {
  		string str;
  		getline(cin, str);
  		stringstream ss(str);
  		int x;
  		while(ss >> x) has[i][x-1] = true;
  	}
  	
  	cout << driver(0, (1 << n) - 1) << "\n";
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