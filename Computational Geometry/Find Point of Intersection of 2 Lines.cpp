// Link to know when 2 lines are identical & when they are parallel --->
// https://www.youtube.com/watch?v=wXcxmC7z6AI

// CAUTION: While doing division always be extra careful that there might be a possibility that the
//          divisor may be 0 which may lead to Runtime Error or NaN 

// The below algorithm works fine for LINES but, but if we are given LINE SEGMENTS instead of lines, we have 
// to also recheck that the point so computed actually lies on both the line segments.
// For more info visit: https://www.geeksforgeeks.org/program-for-point-of-intersection-of-two-lines/

/************************************************************************************************************/

// Problem: 378 - Intersecting Lines
// Contest: UVa Online Judge
// URL: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=314
// Memory Limit: 32 MB
// Time Limit: 3000 ms
// Parsed on: 03-01-2021 18:34:59 IST (UTC+05:30)
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
	double x, y;
};

void solve()
{
  	struct point A, B, C, D;
  	cin >> A.x >> A.y >> B.x >> B.y;
  	cin >> C.x >> C.y >> D.x >> D.y;
  	
  	double a1 = B.y - A.y;
  	double b1 = A.x - B.x;
  	double c1 = (a1 * A.x) + (b1 * A.y); 
  	
  	double a2 = D.y - C.y;
  	double b2 = C.x - D.x;
  	double c2 = (a2 * C.x) + (b2 * C.y);
  	
  	double det = (a1 * b2) - (a2 * b1);
  	double dx = (b2 * c1) - (b1 * c2);
  	double dy = (a1 * c2) - (a2 * c1);
  	
    // det == 0 implies (a1/a2) == (b1/b2)
    // dx == 0 implies (b1/b2) == (c1/c2)
    // dy == 0 implies (c1/c2) == (a1/a2)

  	if(!det && (dx || dy)) cout << "NONE\n";
  	else if(!det && !dx && !dy) cout << "LINE\n";
  	else {
  		double X = dx/det, Y = dy/det;
  		if(X == -0.0) X = 0.0;
  		if(Y == -0.0) Y = 0.0;
  		cout << fixed << setprecision(2) <<"POINT " << X << " " << Y << "\n";
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
	
	cout << "INTERSECTING LINES OUTPUT\n";
    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }
	
	cout << "END OF OUTPUT\n";
    return 0;
}