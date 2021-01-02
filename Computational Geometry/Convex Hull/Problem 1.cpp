// Problem: B. Polygons
// Contest: Codeforces - Codeforces Round #113 (Div. 2)
// URL: https://codeforces.com/problemset/problem/166/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 02-01-2021 23:09:45 IST (UTC+05:30)
// Author: kapil_choudhary

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
	ll x, y;
	
	bool operator < (point &P) {
		return (x < P.x) || (x == P.x && y < P.y);
	}
	
	bool operator == (point &P) {
		return (x == P.x) && (y == P.y);
	}
};

bool cw(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(point a, point b, point c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull(vector<point> &p) {
	if(p.size() <= 2) return;
	
	ll n = p.size();
	point p1 = p[0], p2 = p[n - 1];
	
	vector<point> up, down;
	up.pb(p1); down.pb(p1);
	
	for(ll i = 1; i < n; i++) {
		if(i == (n - 1) || !ccw(p1, p[i], p2)) {
			while(up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i])) {
				up.pop_back();
			}
			
			up.pb(p[i]);
		}
		
		if(i == (n - 1) || !cw(p1, p[i], p2)) {
			while(down.size() >= 2 && cw(down[down.size() - 2], down[down.size() - 1], p[i])) {
				down.pop_back();
			}
			
			down.pb(p[i]);
		}
	}
	
	p.clear();
	for(ll i = 0; i < up.size(); i++) p.pb(up[i]);
	for(ll i = 0; i < down.size(); i++) p.pb(down[i]);
	
	sort(p.begin(), p.end());
	p.resize(unique(p.begin(), p.end()) - p.begin());
}

void solve()
{
  	vector<point> p;
  	ll n; cin >> n;
  	for(ll i = 0; i < n; i++) {
  		point pt;
  		cin >> pt.x >> pt.y;
  		p.pb(pt);
  	}
  	
  	map<pll, ll> MAP;
  	ll m; cin >> m;
  	for(ll i = 0; i < m; i++) {
  		point pt;
  		cin >> pt.x >> pt.y;
  		p.pb(pt);
  		MAP[{pt.x, pt.y}]++;
  	}
  	
  	sort(p.begin(), p.end());
  	convex_hull(p);
  	
  	for(auto pt: p) {
  		if(MAP.count({pt.x, pt.y})) {
  			cout << "NO\n";
  			return;
  		}
  	}
  	
  	cout << "YES\n";
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