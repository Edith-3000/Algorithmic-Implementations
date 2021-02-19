// Although this problem could have been easily solved by Method - 2, but I'vs deliberately solved it by 
// Ternary Search in Method - 1
/**************************************************************************************************************/

// Method 1

// Problem: C. Similar Arrays
// Contest: Codeforces - Unofficial Div 4 Round #2 by ssense  SlavicG
// URL: https://codeforces.com/gym/102873/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Parsed on: 19-02-2021 14:03:44 IST (UTC+05:30)
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

vi v;
int n;

ll dist(int x) {
	ll d = 0;
	for(int i = 0; i < n; i++) d += abs(v[i] - x);
	return d;
}

int ternary(int L, int R) {
	while(L < R - 2) {
		int mid1 = L + (R - L)/3;
		int mid2 = R - (R - L)/3;
		
		if(dist(mid1) <= dist(mid2)) R = mid2;
		else L = mid1;
	}
	
	int res = L;
	ll d = dist(L);
	
	for(int i = L; i <= R; i++) {
		if(d > dist(i)) {
			res = i;
			d = dist(i);
		}
	}
	
	return res;
}

void solve()
{
  	cin >> n;
  	v.resize(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	int x = ternary(*min_element(v.begin(), v.end()), *max_element(v.begin(), v.end()));
  	ll res = 0;
  	for(int i = 0; i < n; i++) res += abs(v[i] - x);
  	cout << res << "\n";
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

/*********************************************************************************************************/

// Method - 2
// Explanation of approach: https://codeforces.com/blog/entry/84184

// Problem: C. Similar Arrays
// Contest: Codeforces - Unofficial Div 4 Round #2 by ssense  SlavicG
// URL: https://codeforces.com/gym/102873/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// Parsed on: 19-02-2021 16:09:05 IST (UTC+05:30)
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

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(auto &x: v) cin >> x;
  	
  	sort(v.begin(), v.end());
  	int median = v[n/2];
  	
  	ll res = 0;
  	for(int i = 0; i < n; i++) res += abs(v[i] - median);
  	
  	cout << res << "\n";
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