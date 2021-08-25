// Problem: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bf4ed
/*********************************************************************************************************/

// Problem: Longest Arithmetic
// Contest: Google Coding Competitions - Round E 2020 - Kick Start 2020
// URL: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff47/00000000003bf4ed
// Memory Limit: 1024 MB
// Time Limit: 20000 ms
// Parsed on: 19-04-2021 23:40:19 IST (UTC+05:30)
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

int LLAP(vi &v) {
	int n = (int)v.size();
	if(n <= 2) return n;
	
	int res = 2;
	for(int i = 0; (i + 1) < n; i++) {
		int diff = v[i+1] - v[i];
		int j = i + 1;
		while(j < n and v[j] - v[j-1] == diff) j++;
		res = max(res, j - i);
		i = j - 2; 
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << LLAP(v) << "\n";
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
    int test = 1;
    cin >> t;
    while(t--) {
      cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}