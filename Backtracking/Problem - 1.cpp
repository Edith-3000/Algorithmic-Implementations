// Ref: https://atcoder.jp/contests/abc196/editorial/954
//      https://www.youtube.com/watch?v=vKAEtmbT_9I
/****************************************************************************************************/

// Problem: D - Hanjo
// Contest: AtCoder - AtCoder Beginner Contest 196
// URL: https://atcoder.jp/contests/abc196/tasks/abc196_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Parsed on: 23-03-2021 16:33:00 IST (UTC+05:30)
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

int a[16][16];
ll res;

bool valid(int H, int W) {
	bool ok = 1;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			ok &= (a[i][j] == 1);
		}
	}
	
	return ok;
}

void find_ways(int H, int W, int A, int B) {
	if(A == 0 and B == 0) {
		if(valid(H, W)) res += 1;
		return;
	}
	
	int i, j;
	bool flag = 0;
	
	for(int ii = 0; ii < H; ii++) {
		for(int jj = 0; jj < W; jj++) {
			if(a[ii][jj] == -1) {
				i = ii;
				j = jj;
				flag = 1;
				break;
			}
		}
		
		if(flag) break;
	}
	
	if(flag == 0) return;
	
	if(A > 0 and a[i][j] == -1 and (j + 1) < W and a[i][j+1] == -1) {
		a[i][j] = 1;
		a[i][j+1] = 1;
		find_ways(H, W, A - 1, B);

		a[i][j] = -1;
		a[i][j+1] = -1;
	}
	
	if(A > 0 and a[i][j] == -1 and (i + 1) < H and a[i+1][j] == -1) {
		a[i][j] = 1;
		a[i+1][j] = 1;
		find_ways(H, W, A - 1, B);

		a[i][j] = -1;
		a[i+1][j] = -1;
	}
	
	if(B > 0 and a[i][j] == -1) {
		a[i][j] = 1;
		find_ways(H, W, A, B - 1);

		a[i][j] = -1;
	}
	
	return;
}

void solve()
{
  	int H, W, A, B;
  	cin >> H >> W >> A >> B;
  	
  	memset(a, -1, sizeof a);
  	res = 0LL;
  	
  	find_ways(H, W, A, B);
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}