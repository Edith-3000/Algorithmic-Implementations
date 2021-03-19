// Ref: https://codeforces.com/blog/entry/82817
/*****************************************************************************************************/

// NOTE: The below algorithm can be modified to solve similar problems, most of the time the idea
//       will remain the same.

/****************************************************************************************************/

// Problem: D2. Sage's Birthday (hard version)
// Contest: Codeforces - Codeforces Round #671 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1419/D2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 18-03-2021 11:09:25 IST (UTC+05:30)
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
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	sort(v.begin(), v.end());
  	int L = 0, R = n + 1;
  	
  	while(L + 1 < R) {
  		int m = L + ((R - L) >> 1);
  		bool ok = true;
  		
  		if(2 * m + 1 > n) ok = false;
  		else {
  			vi res;
  			int pos_a = 0, pos_b = n - (m + 1);
  			
  			for(int i = 0; i < (2 * m + 1); i++) {
  				if(i % 2 == 0) {
  					res.emplace_back(v[pos_b]);
  					pos_b++;
  				}
  				
  				else {
  					res.emplace_back(v[pos_a]);
  					pos_a++;
  				}
  			}
  			
  			for(int i = 1; i < (2 * m + 1); i += 2) {
  				if(res[i] >= res[i-1] or res[i] >= res[i+1]) ok = false;
  			}
  		}
  		
  		if(ok) L = m;
  		else R = m;
  	}
  	
  	vi res;
  	int pos_a = 0, pos_b = n - (L + 1);
  	
  	for(int i = 0; i < (2 * L + 1); i++) {
  		if(i % 2 == 0) {
  			res.emplace_back(v[pos_b]);
  			pos_b++;
  		}
  		
  		else {
  			res.emplace_back(v[pos_a]);
  			pos_a++;
  		}
  	}
  	
  	for(int i = pos_a; i < (n - (L + 1)); i++) {
  		res.emplace_back(v[i]);
  	}
  	
  	cout << L << "\n";
  	for(int i = 0; i < n; i++) {
  		cout << res[i] << ((i == n - 1) ? "\n" : " ");
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