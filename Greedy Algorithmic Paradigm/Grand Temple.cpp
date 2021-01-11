/* Problem --->

A religious king wants to build the largest temple in his kingdom . To build the largest temple he needs to 
find the area of the largest suitable land . Given co-ordinates which denotes rivers flowing through the point 
horizontally as well as vertically , find the largest area possible to make the grand temple.
Consider 2 rivers flowing across x-axis as well as y-axis. The temple must be enclosed by rivers on all 4 sides.

Input Format --->
An integer n denoting number of co-ordinates followed by n co-ordinates

Constraints --->
1 <= N <= 10^5
|Ai| <= 10^9

Output Format --->
Largest possible area to build the grand temple.

Sample Input --->
3
1 1
2 4
5 2

Sample Output --->
2

Explanation --->
Area between (2,2), (2,4), (5,2), (5,4)
(For the largest possible region found the area will be calculated from the edge next to the left edge, the 
edge above the bottom edge, the topmost edge and the rightmost edge i.e for the region (2,2), (2,4), (5,2), (5,4) 
the actual area will be considered from (3,2), (3,4), (5,2), (5,4) respectively. Try to draw the diagram and 
you will realize the modified picture of the area)

*/

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
  	ll n; cin >> n;
  	vll x(n), y(n);
  	for(ll i = 0; i < n; i++) {
  		cin >> x[i] >> y[i];
  	}
  	
  	if(n <= 1) {
  		cout << 0 << "\n";
  		return;
  	}
  	
  	sort(x.begin(), x.end());
  	sort(y.begin(), y.end());
  	ll dx = LLONG_MIN, dy = LLONG_MIN;
  	for(ll i = 1; i < n; i++) {
  		dx = max(dx, x[i] - x[i - 1] - 1);
  		dy = max(dy, y[i] - y[i - 1] - 1);
  	}
  	
  	cout << dx * dy << "\n";
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