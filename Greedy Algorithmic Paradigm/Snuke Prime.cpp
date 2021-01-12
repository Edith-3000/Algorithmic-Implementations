// Links: https://atcoder.jp/contests/abc188/editorial/556
//        https://www.youtube.com/watch?v=omeabboF9oU

/***************************************************************************************************************/

// METHOD 1 (using std::map)

// Problem: D - Snuke Prime
// Contest: AtCoder - AtCoder Beginner Contest 188
// URL: https://atcoder.jp/contests/abc188/tasks/abc188_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Parsed on: 12-01-2021 19:10:14 IST (UTC+05:30)
// Author: kapil_choudhary

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
  	ll N, C; cin >> N >> C;
  	map<int, ll> m;
  	for(int i = 0; i < N; i++) {
  		int a, b, c; 
  		cin >> a >> b >> c;
  		m[a] += c;
  		m[b + 1] -= c;
  	}
  	
  	// making prefix sum types of map now
  	auto it = m.begin();
  	ll prev = it->S;
  	it++;
  	while(it != m.end()) {
  		prev += it->S;
  		it->S = prev;
  		it++;
  	}
  	
  	// finding the result
  	ll res = 0;
  	it = m.begin();
  	ll day = it->F, val = it->S;
  	it++;
  	while(it != m.end()) {
  		res += (it->F - day) * min(C, val);
  		day = it->F;
  		val = it->S;
  		it++;
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

/***********************************************************************************************************/

// METHOD  (using std::vector)

// Problem: D - Snuke Prime
// Contest: AtCoder - AtCoder Beginner Contest 188
// URL: https://atcoder.jp/contests/abc188/tasks/abc188_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Parsed on: 12-01-2021 19:10:14 IST (UTC+05:30)
// Author: kapil_choudhary

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
  	ll N, C; cin >> N >> C;
  	vpll events;
  	for(ll i = 0; i < N; i++) {
  		ll a, b, c;
  		cin >> a >> b >> c;
  		events.emplace_back(a, c);
  		events.emplace_back(b + 1, -c);
  	}
  	
  	sort(events.begin(), events.end());
  	ll res = 0, val = 0, day = 0;
  	for(auto [x, y]: events) {
  		if(x != day) {
  			res += (x - day) * min(C, val);
  			day = x;
  		}
  		
  		val += y;
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