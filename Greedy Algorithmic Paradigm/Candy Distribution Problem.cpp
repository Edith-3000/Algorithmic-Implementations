// Problem: https://leetcode.com/problems/candy/
/******************************************************************************************************/

// METHOD - 1 O(n) Time & Space

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

int distribute(vi &v) {
	int n = (int)v.size();
	if(n <= 1) return n;
	
	vi lf(n, 1), rg(n, 1);
		
	for(int i = 1; i < n; i++) {
		if(v[i] > v[i-1]) lf[i] = lf[i-1] + 1;
	}
	
	for(int i = n - 2; i >= 0; i--) {
		if(v[i] > v[i+1]) rg[i] = rg[i+1] + 1;
	}
	
	int res = 0;
	for(int i = 0; i < n; i++) res += max(lf[i], rg[i]);
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << distribute(v) << "\n";
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

// METHOD - 2 O(n) Time & O(1) Space
// Ref: https://medium.com/javarevisited/how-to-solve-the-minimum-candy-distribution-problem-4c868740f16a

// NOTE: If finding problem in understanding this algorithm, just dry run it for the case in the 
//       mentioned link: https://pasteboard.co/K1GKRF2.jpg

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

int distribute(vi &v) {
	int n = (int)v.size();
	if(n <= 1) return n;
	
	int upSlopeLength = 0;
	int upSlope = 0;
	int downSlope = 0;
	
	int res = 1;
	
	for(int i = 1; i < n; i++) {
		if(v[i] == v[i-1]) {
			upSlopeLength = 0;
			upSlope = 0;
			downSlope = 0;
			res += 1;
		}
		
		else if(v[i] > v[i-1]) {
			upSlope = (upSlope == 0) ? 1 : upSlope;
			upSlope += 1;
			upSlopeLength = upSlope;
			downSlope = 0;
			res += upSlope;
		}
		
		else {
			upSlope = 0;
			downSlope += 1;
			int slopeDiff = ((downSlope + 1 - upSlopeLength) > 0) ? 1 : 0;
			res += downSlope + slopeDiff;
		}
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << distribute(v) << "\n";
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