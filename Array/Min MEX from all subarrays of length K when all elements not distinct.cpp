// Problem: E - Mex Min
// Contest: AtCoder - AtCoder Beginner Contest 194
// URL: https://atcoder.jp/contests/abc194/tasks/abc194_e
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// Parsed on: 11-03-2021 13:43:48 IST (UTC+05:30)
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

int min_MEX(vi &v, int n, int k) {
	set<int> s;
	for(int i = 0; i <= k; i++) s.insert(i);
	vi f(k + 1, 0);
	
	int min_mex = k;
	for(int i = 0; i < n; i++) {
		if(v[i] <= k) {
			s.erase(v[i]);
			f[v[i]]++; 
		}
		
		if(i >= k) {
			if(v[i-k] <= k) {
				--f[v[i-k]];
				if(f[v[i-k]] == 0) s.insert(v[i-k]);
			}
		}
		
		if(i >= k - 1) {
			min_mex = min(min_mex, *s.begin());
		}
	}
	
	return min_mex;
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(auto &x: v) cin >> x;
  	
  	cout << min_MEX(v, n, k) << "\n";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}