// Explanation: https://www.youtube.com/watch?v=PT-QBZByYwA&list=PL2q4fbVm1Ik6WB7SKtjEhwbQiLaD186OS&index=1
/************************************************************************************************************/

// Problem: C. RationalLee
// Contest: Codeforces - Codeforces Round #652 (Div. 2)
// URL: https://codeforces.com/contest/1369/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 04-02-2021 23:52:43 IST (UTC+05:30)
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

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n + 1);
  	for(int i = 1; i <= n; i++) cin >> v[i];
  	
  	vi w(k + 1);
  	for(int i = 1; i <= k; i++) cin >> w[i];
  	
  	sort(v.begin() + 1, v.end());
  	sort(w.begin() + 1, w.end());
  	
  	ll res = 0;
  	int L = 1, R = n, pos = 1;
  	while(pos <= k and w[pos] == 1) {
  		res += 2 * v[R], --R, ++pos;
  	}
  	
  	for(int i = k; i >= pos; i--) {
  		res += v[R] + v[L];
  		--R; ++L; w[i] -= 2;
  		while(w[i] > 0) { L++; w[i] -= 1; }
  	}
  	
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}