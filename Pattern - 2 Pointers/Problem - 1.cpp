// Approach Ref: https://www.youtube.com/watch?v=Qq5j-bhdwE0
/********************************************************************************************************/

// Problem: C. Berland Regional
// Contest: Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1519/problem/C#
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 30-04-2021 17:28:59 IST (UTC+05:30)
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

bool cmp(const pii &p1, const pii &p2) {
	if(p1.F == p2.F) return p1.S > p2.S;
	return p1.F < p2.F;
}

void solve()
{
  	int n; cin >> n;
  	vpii v(n + 1);
  	for(int i = 1; i <= n; i++) cin >> v[i].F;
  	for(int i = 1; i <= n; i++) cin >> v[i].S;
  	
  	sort(v.begin() + 1, v.end(), cmp);
  	
  	map<int, int> m;
  	vll cs(n + 1, 0);
  	
  	for(int i = 1; i <= n; i++) {
  		cs[i] += cs[i-1] + v[i].S;
  		if(m.find(v[i].F) == m.end()) m[v[i].F] = i;
  	}
  	
  	for(int k = 1; k <= n; k++) {
  		ll res = 0LL;
  		int i = 1, j = 1 + k;
  		
  		while(j <= n) {
  			if(v[j-1].F != v[i].F) {
  				i = m[v[j-1].F];
  				j = i + k;
  			}
  			
  			else {
  				res += cs[j-1] - cs[i-1];
  				i += k; j += k;
  			}
  		}
  		
  		if(i <= n and (j - 1) <= n and v[j-1].F == v[i].F) {
  			res += cs[j-1] - cs[i-1];
  		}
  		
  		cout << res << " ";
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
    cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

// Time complexity: --->
// = n + (n/2) + (n/3) + (n/4) + ......
// = n x (1 + (1/2) + (1/3) + (1/4) + .....)
// = n x log(n) [approximately]