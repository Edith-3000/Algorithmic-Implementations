// Problem: Projects
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1140
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 04-02-2021 15:35:51 IST (UTC+05:30)
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

struct project {
	int start, end, reward;
};

int find_best(vi &end_points, int val) {
	auto it = lower_bound(end_points.begin(), end_points.end(), val);
	
	// corner case handling
	if(it == end_points.begin()) return 0;
	
	// else 
	--it;
	// 1 is added to result as we have used 1-based indexing in v[]
	return distance(end_points.begin(), it) + 1;
}

bool my_comp(const project &p1, const project &p2) {
	if(p1.end == p2.end) return p1.start < p2.start;
	return p1.end < p2.end;
}

void solve()
{
  	int n; cin >> n;
  	vector<project> v(n + 1);
  	for(int i = 1; i <= n; i++) {
  		cin >> v[i].start >> v[i].end >> v[i].reward;
  	}
  	
  	// sorting projects on the basis of end date
  	sort(v.begin() + 1, v.end(), my_comp);
  	
  	// storing the end dates of projects in sorted form
  	vi end_points;
  	for(int i = 1; i <= n; i++) end_points.pb(v[i].end);
  	
  	ll dp[n+1];
  	dp[0] = 0; // if no projects ==> no profit
  	
  	for(int i = 1; i <= n; i++) {
  		// Choice 1: leave this project
  		ll op1 = dp[i-1];
  		
  		// Choice 2: take this project
  		ll op2 = v[i].reward;
  		int idx = find_best(end_points, v[i].start);
  		op2 += dp[idx];
  		
  		dp[i] = max(op1, op2);
  	}
  	
  	cout << dp[n] << "\n";
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

// TIme complexity: O(n x log2(n))