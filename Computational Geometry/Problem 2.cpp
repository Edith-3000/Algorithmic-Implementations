// Explanation: https://www.youtube.com/watch?v=WMZp0XzkhyQ

/**********************************************************************************************************/

// Problem: E - Rotate and Flip
// Contest: AtCoder - AtCoder Beginner Contest 189
// URL: https://atcoder.jp/contests/abc189/tasks/abc189_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Parsed on: 26-01-2021 00:31:54 IST (UTC+05:30)
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

class Point {
	public:
		ll x, y;
		Point() { x = 0; y = 0; }
		~Point() {}
};

class Coefficients {
	public:
		ll a, b, c;
		Coefficients() { a = 0; b = 0; c = 0; }
		Coefficients(ll i, ll j, ll k) { a = i; b = j; c = k; }
		~Coefficients() {}
		void negative() { a = -a; b = -b; c = -c; }
		void add(ll k) { c += k; }
		ll evaluate(Point p) { return (a * p.x) + (b * p.y) + c; }
};

void solve()
{
  	ll n, m, q;
  	cin >> n;
  	vector<Point> v(n); 
  	for(ll i = 0; i < n; i++) {
  		cin >> v[i].x >> v[i].y;
  	}
  	
  	cin >> m;
  	vll op(m), par(m);
  	for(ll i = 0; i < m; i++) {
  		cin >> op[i];
  		if(op[i] > 2) cin >> par[i];
  	}
  	
  	vector<pair<Coefficients, Coefficients>> coeff(m + 1);
  	coeff[0] = {Coefficients(1, 0, 0), Coefficients(0, 1, 0)};
  	
  	for(ll i = 1; i <= m; i++) {
  		switch(op[i-1]) {
  			case 1:
  				coeff[i] = { coeff[i-1].S, coeff[i-1].F };
  				coeff[i].S.negative();
  				break;
  				
  			case 2:
  				coeff[i] = { coeff[i-1].S, coeff[i-1].F };
  				coeff[i].F.negative();
  				break;
  				
  			case 3:
  				coeff[i] = coeff[i-1];
  				coeff[i].F.negative();
  				coeff[i].F.add(2 * par[i-1]);
  				break;
  				
  			case 4:
  				coeff[i] = coeff[i-1];
  				coeff[i].S.negative();
  				coeff[i].S.add(2 * par[i-1]);
  				break; 			
  		}
  	}
  	
  	cin >> q;
  	for(ll i = 0; i < q; i++) {
  		ll opr, pt;
  		cin >> opr >> pt;
  		cout << coeff[opr].F.evaluate(v[pt-1]) << " "
  			 << coeff[opr].S.evaluate(v[pt-1]) << "\n";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}