// For lambda functions refer: https://www.youtube.com/watch?v=wd2LyLfvkVw
// Editorial: https://codeforces.com/blog/entry/76352
/************************************************************************************************************/

// Problem: C. Alternating Subsequence
// Contest: Codeforces - Codeforces Round #636 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1343/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 21-02-2021 18:34:35 IST (UTC+05:30)
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

vi v;
int n;

// Lambda function
auto sgn = [](int x) {
	if(x > 0) return 1;
	else return -1;
};

void solve()
{
  	cin >> n;
  	v.resize(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	  	
  	ll res = 0;
  	
  	for(int i = 0; i < n; i++) {
  		int mx = v[i];
  		int j = i;
  		
  		while(j < n and sgn(v[i]) == sgn(v[j])) {
  			mx = max(mx, v[j]);
  			j++;
  		}
  		
  		res += mx;
  		i = j - 1;
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