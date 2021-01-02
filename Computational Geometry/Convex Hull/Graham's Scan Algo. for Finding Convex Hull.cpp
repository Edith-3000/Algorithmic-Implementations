// Reference: https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html

// OBJECTIVE: Given N points given on a plane, the objective is to generate a convex hull, i.e. the smallest 
//            convex polygon that contains all the given points.

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
	// data members
	int x, y;
	
	// overloading the < operator of this struct
	// to be used by std::sort() function
	bool operator < (point &P) {
		if(x == P.x) return y < P.y;
		return x < P.x;
	}
	
	// overloading the == operator of this struct
	// to be used by std::unique() function
	bool operator == (point &P) {
		return (x == P.x) && (y == P.y);
	}
};

// function to check if movement from pt. a to pt. b 
// to pt. c is clockwise or not
bool cw(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

// function to check if movement from pt. a to pt. b 
// to pt. c is counter(anti) clockwise or not
bool ccw(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

// function to check collinearity of 3 points
bool coll(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) == 0;
}

void convex_hull(vector<point> &p) {
	// if size <= 2, then it is already a convex hull
	if(p.size() <= 2) return;
	
	sort(p.begin(), p.end());
	int n = p.size();
	
	// p1 & p2 both will definitely be a part of the convex hull
	point p1 = p[0]; // it is the leftmost bottom point
	point p2 = p[n - 1]; // it is the rightmost top point
	
	// vector up & down will work as a stack for upper & lower
	// half respectively
	vector<point> up, down; 
	up.pb(p1); down.pb(p1);
	
	// now for each point check if it lies in the upper half
	// or lower half
	for(int i = 1; i < n; i++) {
		// condition for p[i] to lie in upper half
		// considering the case of collinearity as well
		// i == (n - 1) is for p2 (since p1 & p2 must be in both the sets)
		if(i == (n - 1) || !ccw(p1, p[i], p2)) {
			while(up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i])) {
				up.pop_back();
			}
			
			up.pb(p[i]);
		}
		
		// condition for p[i] to lie in lower half
		// considering the case of collinearity as well
		// i == (n - 1) is for p2 (since p1 & p2 must be in both the sets)
		if(i == (n - 1) || !cw(p1, p[i], p2)) {
			while(down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], p[i])) {
				down.pop_back();
			}
			
			down.pb(p[i]);
		}
	}
	
	// now up & down contain all the points on the boundary of the convex hull
	// there will be AT LEAST 2 repeating points in both of them (i.e. p1 & p2)
	
	p.clear();
	for(int i = 0; i < up.size(); i++) p.pb(up[i]);
	for(int i = 0; i < down.size(); i++) p.pb(down[i]);
	
	// now vector p contains all the points of convex hull (including some
	// repeated ones too)
	
	// to remove duplicate points
	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());	
}

void solve()
{
	int n; cin >> n;
  	vector<point> p(n);
  	for(int i = 0; i < n; i++) {
  		cin >> p[i].x >> p[i].y;
  	}
  	
  	convex_hull(p);
  	
  	// print convex hull boundary points
  	for(auto pt: p) cout << pt.x << " " << pt.y << "\n";
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

/*

Sample i/p --->

6
0 0 
0 1
1 0
0 2
1 1
1 2

Sample o/p --->

0 0
0 1
0 2
1 0
1 1
1 2

*/

// Time complexity for construction of a convex hull: O(N x log2(N))
// where N are the #points given on a plane