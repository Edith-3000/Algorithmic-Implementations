// Approach Ref: https://www.youtube.com/watch?v=8IQgU95iZ58
/**************************************************************************************************/

// Problem: 3xN Tiling
// Contest: CodeChef - Past INOI Problems
// URL: https://www.codechef.com/INOIPRAC/problems/INOI2002
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 30-04-2021 15:34:16 IST (UTC+05:30)
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
const ll mod = 1e9+7;
const int N = 1e6;

ll dp2[N+1];
ll dp3[N+1][4];

void solve()
{
  	int k, n; cin >> k >> n;
  	if(k == 1) {
  		if(n % 3 == 0) cout << 1 << "\n";
  		else cout << 0 << "\n";
  	}
  	
  	else if(k == 2) {
  		memset(dp2, 0, sizeof dp2);
  		dp2[2] = dp2[3] = 1;
  		
  		for(int i = 4; i <= n; i++) {
  			dp2[i] = (dp2[i-2] + dp2[i-3]) % mod;
  		}
  		
  		cout << dp2[n] << "\n";
  	}
  	
  	else {
  		memset(dp3, 0, sizeof dp3);
  		dp3[1][1] = 1;
  		dp3[1][2] = 0;
  		dp3[1][3] = 0;
  		
  		dp3[2][1] = 1;
  		dp3[2][2] = 0;
  		dp3[2][3] = 0;
  		
  		dp3[3][1] = 2;
  		dp3[3][2] = 0;
  		dp3[3][3] = 1;
  		
  		for(int i = 4; i <= n; i++) {
  			dp3[i][1] = ((dp3[i-1][1] + dp3[i-3][1]) % mod + (2 * dp3[i-2][2]) % mod) % mod;
  			dp3[i][2] = (dp3[i-1][3] + dp3[i-3][2]) % mod;
  			dp3[i][3] = (dp3[i-3][1] + dp3[i-3][3]) % mod;
  		}
  		
  		cout << dp3[n][1] << "\n";
    }
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
    cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}