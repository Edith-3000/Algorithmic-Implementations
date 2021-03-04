// Problem: Road Construction
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1676
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 03-03-2021 21:53:48 IST (UTC+05:30)
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

vi dsu_parent;
vi dsu_rank;
int n, m;

int dsu_find(int v) {
	if(dsu_parent[v] == -1) return v;
	return dsu_parent[v] = dsu_find(dsu_parent[v]);
}

void dsu_union(int a, int b, int &comp, int &maxi) {
	int s1 = dsu_find(a);
	int s2 = dsu_find(b);
	
	if(s1 != s2) {
		if(dsu_rank[s1] < dsu_rank[s2]) swap(s1, s2);
		dsu_parent[s2] = s1;
		dsu_rank[s1] += dsu_rank[s2];
		
		maxi = max(maxi, dsu_rank[s1]);
		comp -= 1;
	}
}

void solve()
{
	cin >> n >> m;
	
	dsu_parent.assign(n + 1, -1);
	dsu_rank.assign(n + 1, 1);
	
	int comp = n, maxi = 1;
	
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		dsu_union(u, v, comp, maxi);
		cout << comp << " " << maxi << "\n";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}