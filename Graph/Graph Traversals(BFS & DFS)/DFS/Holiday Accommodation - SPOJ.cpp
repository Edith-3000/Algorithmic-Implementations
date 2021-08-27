/* # Brute force approach may give TLE in this problem.
   # The main idea is to maximize the distance that is travelled through every edge in order to get 
     the answer.
   # In a way we have also used "Pigeon Hole Principle in this approach", although it may not be 
     clearly seen.

   # IMP NOTE: in the below code cnt[] vector is declared globally, had it been named count[], then
     this error will be encountered: error: reference to ‘count’ is ambiguous
     Reason of this error: https://stackoverflow.com/questions/11271889/global-variable-count-ambiguous
*/

// Problem: Holiday Accommodation
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/HOLI/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// Parsed on: 29-12-2020 21:56:45 IST (UTC+05:30)
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

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

vector<vpll> g;
vll cnt; // cnt[i] will store the #nodes in the subtree rooted at i (including itself)
ll n, res;

// this type of DFS will work in this problem i.e. instead of using
// a visited array, parent variable is passed, as we know it is a
// connected ACYCLIC graph or a tree. 
ll dfs(ll curr, ll par) {
	cnt[curr] = 1;
	for(auto x: g[curr]) {
		if(x.F != par) {
			cnt[curr] += dfs(x.F, curr);
			ll part_1 = cnt[x.F]; // #nodes in one part
			ll part_2 = n - part_1; // #nodes in the other part
			res += (2 * min(part_1, part_2) * x.S);
		}
	}
	
	return cnt[curr];
}

void solve(int test)
{
  	cin >> n;
  	g.clear(); g.resize(n + 1);
  	cnt.assign(n + 1, 0);
  	res = 0;
  	
  	for(ll i = 1; i <= (n - 1); i++) {
  		ll u, v, w; cin >> u >> v >> w;
  		g[u].pb({v, w});
  		g[v].pb({u, w});
  	}
  	
  	dfs(1, 0);
  	cout << "Case #" << test << ": " << res << "\n";
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
    for(int test = 1; test <= t; test++) {
      solve(test);
    }

    return 0;
}

// Time complexity: O(|V| + |E|)