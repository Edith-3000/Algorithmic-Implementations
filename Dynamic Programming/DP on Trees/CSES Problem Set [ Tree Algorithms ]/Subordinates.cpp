// Problem: Subordinates
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1674
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 05-02-2021 18:03:46 IST (UTC+05:30)
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

vi tree[200001];
vi res(200001);
int n;

void dfs(int curr, int par) {
	int subs = 0;
	for(auto x: tree[curr]) {
		if(x != par) {
			dfs(x, curr);
			subs += (1 + res[x]);
		}
	}
	
	res[curr] = subs;
}

void solve()
{
  	cin >> n;
  	for(int i = 2; i <= n; i++) {
  		int x; cin >> x;
  		tree[x].pb(i);
  		tree[i].pb(x);
  	}
  	
  	res.clear();
  	dfs(1, 0);
  	for(int i = 1; i <= n; i++) cout << res[i] << " ";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}