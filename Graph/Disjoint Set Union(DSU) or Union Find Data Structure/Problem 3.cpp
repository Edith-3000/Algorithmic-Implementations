// Method 1 --->

// Problem: A. Learning Languages
// Contest: Codeforces - Codeforces Round #170 (Div. 1)
// URL: https://codeforces.com/problemset/problem/277/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 08-03-2021 17:17:34 IST (UTC+05:30)
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

vi parent, Rank;

int find(int v) {
	if(parent[v] == -1) return v;
	return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
	int s1 = find(a);
	int s2 = find(b);
	
	if(s1 != s2) {
		if(Rank[s1] < Rank[s2]) swap(s1, s2);
		parent[s2] = s1;
		Rank[s1] += Rank[s2];
	}
}

void solve()
{
  	int n, m; cin >> n >> m;
  	
  	parent.resize(n + 1, -1);
  	Rank.resize(n + 1, 1);
  	
  	vvi v(n + 1);
  	bool all_zero = 1;
  	
  	for(int i = 1; i <= n; i++) {
  		int k; cin >> k;
  		all_zero &= (k == 0);
  		
  		for(int j = 0; j < k; j++) {
  			int x; cin >> x;
  			v[i].pb(x);
  		}
  	}
  	
  	if(all_zero) { cout << n << "\n"; return; } 
  	
  	for(int i = 1; i <= n; i++) {
  		for(auto langI: v[i]) {
  			for(int j = i + 1; j <= n; j++) {
  				for(auto langJ: v[j]) {
  					if(langI == langJ) Union(i, j);
  				}
  			}
  		}
  	}
  	
  	int comp = 0;
  	for(int i = 1; i <= n; i++) {
  		if(parent[i] == -1) comp++;
  	}
  	
  	cout << comp - 1 << "\n";
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

/**************************************************************************************************/

// Method 2 --->

// Problem: A. Learning Languages
// Contest: Codeforces - Codeforces Round #170 (Div. 1)
// URL: https://codeforces.com/problemset/problem/277/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 08-03-2021 17:17:34 IST (UTC+05:30)
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

vi parent, Rank;
vi freq;

int Find(int v) {
	if(parent[v] == v) return v;
	return parent[v] = Find(parent[v]);
}

void Union(int a, int b) {
	int s1 = Find(a);
	int s2 = Find(b);
	
	if(s1 != s2) {
		if(Rank[s1] < Rank[s2]) swap(s1, s2);
		parent[s2] = s1;
		Rank[s1] += Rank[s2];
	}
}

void solve()
{
  	int n, m; cin >> n >> m;
  	
  	parent.resize(m + 1);
  	iota(begin(parent), end(parent), 0);
  	
  	Rank.resize(m + 1, 0);
  	freq.resize(m + 1, 0);
  	
  	int goonga = 0;
  	
  	for(int i = 1; i <= n; i++) {
  		int k; cin >> k;
  		if(k == 0) {
  			goonga++;
  			continue;
  		}
  		
  		int x; cin >> x;
  		freq[x]++;
  		
  		for(int j = 1; j < k; j++) {
  			int y; cin >> y;
  			freq[y]++;
  			Union(x, y);
  		}
  	}
  	
  	int cnt = 0, comp = 0;
  	for(int i = 1; i <= m; i++) {
  		if(freq[i] == 0) cnt++;
  		else if(parent[i] == i) comp++;
  	}
  	
  	if(cnt == m) cout << n << "\n";
  	else cout << comp - 1 + goonga << "\n";
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