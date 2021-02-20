/* References(s) --->
   Editorial: https://codeforces.com/blog/entry/87849
   
   NOTE: In the algorithm I have used binary search with half-interval, this technique always works as
         mentioned in the comment --->
         https://codeforces.com/blog/entry/87849?#comment-763558
         https://codeforces.com/blog/entry/87849?#comment-763573
*/

// Problem: C1. Guessing the Greatest (easy version)
// Contest: Codeforces - Codeforces Round #703 (Div. 2)
// URL: https://codeforces.com/contest/1486/problem/C1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 20-02-2021 12:05:00 IST (UTC+05:30)
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

int query_to_judge(int L, int R) {
	if(L >= R) return -1;
	cout << "? " << L << " " << R << endl;
	int res; cin >> res;
	return res; 
}

void solve()
{
  	int n; cin >> n;
  	int L = 1, R = n + 1;
  	
  	while(L + 1 < R) {
  		int m = (L + R) / 2;
  		int smax = query_to_judge(L, R - 1);
  		if(smax < m) {
  			if(query_to_judge(L, m - 1) == smax) R = m;
  			else L = m;
  		}
  		
  		else {
  			if(query_to_judge(m, R - 1) == smax) L = m;
  			else R = m;
  		}
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