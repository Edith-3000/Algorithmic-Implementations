// Problem: C. Searching Local Minimum
// Contest: Codeforces - Codeforces Round #700 (Div. 2)
// URL: https://codeforces.com/contest/1480/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Parsed on: 09-02-2021 22:51:40 IST (UTC+05:30)
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

int query_to_judge(int ind) {
	cout << "? " << ind << endl;
	int res; cin >> res;
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n + 2);
  	v[0] = v[n+1] = n + 1;
  	
  	int L = 1, R = n;
  	while(L < R) {
  		int m = L + ((R - L) >> 1);
  		v[m] = query_to_judge(m);
  		v[m+1] = query_to_judge(m+1);
  		
  		if(v[m] < v[m+1]) R = m;
  		else L = m + 1;
  	}
  	
  	cout << "! " << L << endl;
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