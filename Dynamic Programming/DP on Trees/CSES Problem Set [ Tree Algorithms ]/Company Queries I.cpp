// Ref: https://www.youtube.com/watch?v=FAfSArGC8KY&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=7
/***************************************************************************************************/

// Problem: Company Queries I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1687
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 02-03-2021 23:10:09 IST (UTC+05:30)
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
int up[200001][20];
int n, q;

void binary_lifting(int src, int par) {
	up[src][0] = par;
	
	for(int i = 1; i < 20; i++) {
		if(up[src][i-1] != -1) {
			up[src][i] = up[up[src][i-1]][i-1];
		}
		
		else up[src][i] = -1;
	}
	
	for(auto child: tree[src]) {
		if(child != par) {
			binary_lifting(child, src);
		}
	}
}

int process_query(int node, int jump_required) {
	if(node == -1 || jump_required == 0) {
		return node;
	}
	
	for(int i = 19; i >= 0; i--) {
		if(jump_required >= (1 << i)) {
			return process_query(up[node][i], jump_required - (1 << i));
		}
	}
}

void solve()
{
  	cin >> n >> q;
  	for(int i = 2; i <= n; i++) {
  		int x; cin >> x;
  		tree[i].pb(x);
  		tree[x].pb(i);
  	}
  	
  	binary_lifting(1, -1);
  	
  	while(q--) {
  		int x, k; cin >> x >> k;
  		cout << process_query(x, k) << "\n";
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