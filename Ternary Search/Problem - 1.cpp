// Problem: C. Mixing Water
// Contest: Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1359/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 13-02-2021 15:00:54 IST (UTC+05:30)
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
ll H, C, T;

double num1(ll x) {
	double res = (H + C) * x;
	res /= (2 * x);
	return abs(res - T);
}

double num2(ll x) {
	double res = (H * x) + (C * (x - 1));
	res /= (2 * x - 1);
	return abs(res - T);
}

ll ternary1(ll L, ll R) {
	while(L < R - 2) {
		ll mid1 = L + (R - L)/3;
		ll mid2 = R - (R - L)/3;
		
		if(num1(mid1) <= num1(mid2)) R = mid2;
		else L = mid1;
	}
	
	ll res = L;
	double diff = 1e12;
	
	for(ll i = L; i <= R; i++) {
		if(diff > num1(i)) {
			res = i;
			diff = num1(i);
		}
	}
	
	return res;
}

ll ternary2(ll L, ll R) {
	while(L < R - 2) {
		ll mid1 = L + (R - L)/3;
		ll mid2 = R - (R - L)/3;
		
		if(num2(mid1) <= num2(mid2)) R = mid2;
		else L = mid1;
	}
	
	ll res = L;
	double diff = 1e12;
	
	for(ll i = L; i <= R; i++) {
		if(diff > num2(i)) {
			res = i;
			diff = num2(i);
		}
	}
	
	return res;
}

void solve()
{
  	cin >> H >> C >> T;

  	ll cnt1 = ternary1(1, 1e12);
  	ll cnt2 = ternary2(1, 1e12);
  	
  	if(num1(cnt1) < num2(cnt2)) cout << 2 * cnt1 << "\n";
  	else cout << (2 * cnt2) - 1 << "\n";
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}