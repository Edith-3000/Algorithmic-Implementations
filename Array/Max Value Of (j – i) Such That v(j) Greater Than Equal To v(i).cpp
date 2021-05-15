// Problem: https://www.interviewbit.com/problems/max-distance/
/*******************************************************************************************************/

// METHOD - 1 O(n x log(n))
// Ref: https://www.youtube.com/watch?v=yKITDmQm0D4

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

int find_max(vi &v) {
	int n = (int)v.size();
	if(n == 0 or n == 1) return 0;
	
	vpii tmp(n);
	for(int i = 0; i < n; i++) {
		tmp[i] = {v[i], i};
	}
	
	sort(tmp.begin(), tmp.end());
	int res = 0, mn = INT_MAX;
	
	for(int i = 0; i < n; i++) {
		mn = min(mn, tmp[i].S);
		res = max(res, tmp[i].S - mn);
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << find_max(v) << "\n";
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

/*****************************************************************************************************/

// METHOD - 2 O(n)
// Ref: https://www.youtube.com/watch?v=Zyhxzg0WLWA&list=PL7JyMDSI2BfbGWRSJeKv0Dwt4txIa8AV-&index=22

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

int find_max(vi &v) {
	int n = (int)v.size();
	if(n == 0 or n == 1) return 0;
	
	vi lf(n), rg(n);
	lf[0] = v[0];
	for(int i = 1; i < n; i++) lf[i] = min(lf[i-1], v[i]);
	
	rg[n-1] = v[n-1];
	for(int i = n - 2; i >= 0; i--) rg[i] = max(rg[i+1], v[i]);
	
	int res = 0, i = 0, j = 0;
	while(i < n and j < n) {
		if(rg[j] >= lf[i]) {
			res = max(res, j - i);
			j++;
		}
		
		else i++;
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << find_max(v) << "\n";
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