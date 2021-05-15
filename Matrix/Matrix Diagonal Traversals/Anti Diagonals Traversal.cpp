// Problem: https://www.interviewbit.com/problems/anti-diagonals/
/*******************************************************************************************************/

// METHOD - 1 (Slightly long in terms of lines of code)

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

vvi anti_diagonals(vvi &v) {
	int n = (int)v.size();
	if(n == 0) return vvi();
	int m = (int)v[0].size();
	
	vvi res;
	for(int col = 0; col < m; col++) {
		int i = 0, j = col;
		vi tmp;
		while(i < n and j >= 0) {
			tmp.pb(v[i][j]);
			i += 1;
			j -= 1;
		}
		
		res.pb(tmp);	
	}
	
	for(int row = 1; row < n; row++) {
		int i = row, j = m - 1;
		vi tmp;
		while(i < n and j >= 0) {
			tmp.pb(v[i][j]);
			i += 1;
			j -= 1;
		}
		
		res.pb(tmp);	
	}
	
	return res;
}

void solve()
{
  	int n, m; cin >> n >> m;
    vvi v(n, vi(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> v[i][j];
    }
    
    vvi res = anti_diagonals(v);
    
    for(auto vec: res) {
    	for(auto ele: vec) cout << ele << " ";
    	cout << "\n";
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

/**************************************************************************************************/

// METHOD - 2 (Short in terms of lines of code)

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

vvi anti_diagonals(vvi &v) {
	int n = (int)v.size();
	if(n == 0) return vvi();
	int m = (int)v[0].size();
	
	vvi res(n + m - 1);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) res[i+j].pb(v[i][j]);
	}
	
	return res;
}

void solve()
{
  	int n, m; cin >> n >> m;
    vvi v(n, vi(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> v[i][j];
    }
    
    vvi res = anti_diagonals(v);
    
    for(auto vec: res) {
    	for(auto ele: vec) cout << ele << " ";
    	cout << "\n";
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}