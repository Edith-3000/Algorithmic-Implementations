// Link for explanation: https://www.youtube.com/watch?v=bbTqI0oqL5U

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
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
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

struct point {
	int x, y;
};

// Given three collinear points a, b and c, the function checks if 
// point b lies on line segment 'ab' 
bool on_segment(point a, point b, point c) {
	return (b.x >= min(a.x, c.x) && b.x <= max(a.x, b.x)) && 
	       (b.y >= min(a.y, c.y) && b.y <= max(a.y, b.y));
}

// To find orientation of ordered triplet (a, b, c). 
// The function returns following values 
// 0 --> if a, b and c are collinear 
// 1 --> if a, b and c are clockwise 
// 2 --> if a, b and c are anti clockwise 
int orientation(point a, point b, point c) {
	int tmp = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
	if(tmp == 0) return 0;
	return (tmp > 0) ? 1 : 2;
}

// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool do_intersect(point p1, point q1, point p2, point q2) {
	// Find the four orientations needed for general and 
	// special cases 
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);
	
	// General case 
	if((o1 != o2) && (o3 != o4)) return true;
	
	// Special Cases 
	// p1, q1 and p2 are collinear and p2 lies on segment p1q1 
	if(o1 == 0 && on_segment(p1, p2, q1)) return true;
	
	// p1, q1 and q2 are collinear and q2 lies on segment p1q1 
	if(o2 == 0 && on_segment(p1, q2, q1)) return true;
	
	// p2, q2 and p1 are collinear and p1 lies on segment p2q2 
	if(o3 == 0 && on_segment(p2, p1, q2)) return true;
	
	// p2, q2 and q1 are collinear and q1 lies on segment p2q2 
	if(o4 == 0 && on_segment(p2, q1, q2)) return true;
	
	// Doesn't fall in any of the above cases 
	return false;	
}

void solve()
{	
	// one line is b/w p1, q1
	// other line betweeen p2, q2
  	struct point p1 = {1, 1}, q1 = {10, 1};
  	struct point p2 = {1, 2}, q2 = {10, 2};
  	
  	// Yes ==> Lines intersect
  	// No ==> Lines do not intersect
  	do_intersect(p1, q1, p2, q2) ? cout << "Yes\n" : cout << "No\n";
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

// Sample o/p ---> No