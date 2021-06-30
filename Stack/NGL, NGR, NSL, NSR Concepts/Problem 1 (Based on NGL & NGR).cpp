// Ref: https://www.youtube.com/watch?v=Cpnw2n75w7A&list=PLQXZIFwMtjoxxYaCwkBDpvcKBHPd5pNhB&index=6
/****************************************************************************************************/

// Here the NGL and NGR functions have been slightly modified according to the need of the question, 
// as given in the above video editorial.

// Problem: Lunchtime
// Contest: CodeChef - March Lunchtime 2021 Division 2
// URL: https://www.codechef.com/LTIME94B/problems/LUNCHTIM
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 31-03-2021 16:06:28 IST (UTC+05:30)
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

vi helper_left(vi &v, int n) {
	vi res;
	stack<pii> stk;
	
	stk.push({INF, 0});
	for(int i = 0; i < n; i++) {
		while(stk.top().F < v[i]) stk.pop();
		if(stk.top().F != v[i]) stk.push({v[i], 0});
		res.pb(stk.top().S);
		stk.top().S += 1;
	}
	
	return res;
}

vi helper_right(vi &v, int n) {
	vi res;
	stack<pii> stk;
	
	stk.push({INF, 0});
	for(int i = n - 1; i >= 0; i--) {
		while(stk.top().F < v[i]) stk.pop();
		if(stk.top().F != v[i]) stk.push({v[i], 0});
		res.pb(stk.top().S);
		stk.top().S += 1;
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vi left = helper_left(v, n);
  	vi right = helper_right(v, n);
  	reverse(right.begin(), right.end());
  	
  	for(int i = 0; i < n; i++) {
  		cout << left[i] + right[i] << " ";
  	}
  	
  	cout << "\n";
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
    cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}