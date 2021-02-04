// Reference(s): https://codeforces.com/blog/entry/79107
//				 https://www.youtube.com/watch?v=OWhmH4W_CJs&list=PL2q4fbVm1Ik5Z3xcF-D0OgHv7QOvlokSm&index=2
/**************************************************************************************************************/

// Problem: D. Odd-Even Subsequence
// Contest: Codeforces - Codeforces Round #651 (Div. 2)
// URL: https://codeforces.com/contest/1370/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 04-02-2021 20:02:29 IST (UTC+05:30)
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

int a[200001];
int n, k;

bool chk_even(int val) {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(cnt % 2 == 0) cnt++;
		else if(a[i] <= val) cnt++;
	}
	
	return cnt >= k;
}

bool chk_odd(int val) {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(cnt % 2 == 0) {
			if(a[i] <= val) cnt++;
		}
		
		else cnt++;
	}
	
	return cnt >= k;
}

int binsearch(int L, int H) {
	while(L < H) {
		int mid = L + ((H - L) >> 1);
		if(chk_odd(mid) || chk_even(mid)) H = mid;
		else L = mid + 1;
	}
	
	return L;
}

void solve()
{
  	cin >> n >> k;
  	for(int i = 1; i <= n; i++) cin >> a[i];
  	
  	cout << binsearch(1, 1e9);
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