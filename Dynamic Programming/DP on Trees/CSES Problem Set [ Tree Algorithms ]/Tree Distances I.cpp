// Naive approach: Initiate BFS from every node of the tree and find the maximum distance achieved for every 
//                 node. Time complexity of this approach = O(n^2), hence inefficient.

/***************************************************************************************************************/

// Tip: WHENEVER WE ARE TRYING TO SOLVE A PROBLEM USING DP ON TREES APPROACH, IT IS ADVISABLE TO TRY TO
//      ROOT THE TREE AT ANY ARBITRARY NODE. 
// Reference: https://www.youtube.com/watch?v=N7e4CTfimkU&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=4

/**************************************************************************************************************/

// DP Method

// Problem: Tree Distances I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1132
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Parsed on: 06-02-2021 10:04:21 IST (UTC+05:30)
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
int depth[200001];
int res[200001];
int n;

void eval_depth(int curr, int par) {
	int dep = 0;
	bool is_leaf = 1;
	
	for(int child: tree[curr]) {
		if(child != par) {
			is_leaf = 0;
			eval_depth(child, curr);
			dep = max(dep, depth[child]);
		}
	}
	
	if(is_leaf) depth[curr] = 0;
	else depth[curr] = 1 + dep;
}

// par_ans = the partial answer of par(parent) wrt curr (child of par)
void driver(int curr, int par, int par_ans) {
	vi prefixMax, suffixMax;
	for(int child: tree[curr]) {
		if(child == par) continue;
		prefixMax.pb(depth[child]);
		suffixMax.pb(depth[child]); 
	}
	
	int pz = (int)prefixMax.size(), sz = (int)suffixMax.size();
	
	for(int i = 1; i < pz; i++) prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
	for(int i = sz - 2; i >= 0; i--) suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);
	
	int ch_no = 0;
	
	// evaluate res for every child c_no
	for(int child: tree[curr]) {
		if(child != par) {
			int op1 = (ch_no == 0) ? -INF : prefixMax[ch_no - 1];
			int op2 = (ch_no == sz - 1) ? -INF : suffixMax[ch_no + 1];
			
			// partial answer of curr(parent) wrt child (ch_no), because we need to 
			// know the partial answer of the parent of every child before calculating
			// the answer for the child, that's why we calculate it here.
			int partial_ans = 1 + max(par_ans, max(op1, op2));
			
			driver(child, curr, partial_ans);
			ch_no++;
		}
	}
	
	// evaluate res for curr
	res[curr] = 1 + max(par_ans, (pz == 0) ? -INF : prefixMax[pz - 1]);
}

void solve()
{
  	cin >> n;
  	for(int i = 1; i < n; i++) {
  		int u, v; cin >> u >> v;
  		tree[u].pb(v);
  		tree[v].pb(u);
  	}
  	
  	eval_depth(1, 0);
  	driver(1, 0, -1);
  	
  	for(int i = 1; i <= n; i++) cout << res[i] << " ";
  	cout << '\n';
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