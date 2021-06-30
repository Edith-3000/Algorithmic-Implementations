// Problem: C - Mandarin Orange
// Contest: AtCoder - AtCoder Beginner Contest 189
// URL: https://atcoder.jp/contests/abc189/tasks/abc189_c
// Memory Limit: 1024 MB
// Time Limit: 1500 ms
// Parsed on: 25-01-2021 10:15:02 IST (UTC+05:30)
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

void nsl(vi &left, vi &v, int n) {
	stack<pii> st;
	for(int i = 0; i < n; i++) {
		if(st.empty()) left[i] = -1;
		else if(st.top().F < v[i]) left[i] = st.top().S;
		else {
			while(!st.empty() && st.top().F >= v[i]) st.pop();
			if(st.empty()) left[i] = -1;
			else left[i] = st.top().S;
		}
		
		st.push({v[i], i});
	}
}

void nsr(vi &right, vi &v, int n) {
	stack<pii> st;
	for(int i = (n - 1); i >= 0; i--) {
		if(st.empty()) right[i] = n;
		else if(st.top().F < v[i]) right[i] = st.top().S;
		else {
			while(!st.empty() && st.top().F >= v[i]) st.pop();
			if(st.empty()) right[i] = n;
			else right[i] = st.top().S;
		}
		
		st.push({v[i], i});
	}
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vi left(n), right(n);
  	nsl(left, v, n);
  	nsr(right, v, n);
  	
  	ll res = LLONG_MIN;
  	for(int i = 0; i < n; i++) {
  		ll tmp = v[i] * (right[i] - left[i] - 1);
  		res = max(res, tmp);
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}