// Ref: https://www.youtube.com/watch?v=ECsHcfiP6iU&t=1757s
/*****************************************************************************************************/

// EASIER VERSION

// Problem: F1. Guess the K-th Zero (Easy version)
// Contest: Codeforces - Codeforces Round #719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/F1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 06-05-2021 17:37:30 IST (UTC+05:30)
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

int query_to_judge(int i, int j) {
	cout << "? " << i << " " << j << endl;
	int sum; cin >> sum;
	return sum;
}

void solve()
{
  	int n, t; cin >> n >> t;
  	int k; cin >> k;
  	
  	int L = 0, R = n + 1;
  	
  	while((L + 1) < R) {
  		int m = L + ((R - L) >> 1);
  		int sum = query_to_judge(1, m);
  		int zer = m - sum;
  		if(zer < k) L = m;
  		else R = m;
  	}
  	
  	cout << "! " << R << endl;
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

/*******************************************************************************************************/

// HARD VERSION

// Problem: F2. Guess the K-th Zero (Hard version)
// Contest: Codeforces - Codeforces Round #719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/F2
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// Parsed on: 06-05-2021 18:21:25 IST (UTC+05:30)
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

int query_to_judge(int i, int j) {
	cout << "? " << i << " " << j << endl;
	int sum; cin >> sum;
	return sum;
}

void solve()
{
  	int n, t; cin >> n >> t;
  	vi v(n + 1, -1);
  	
  	while(t--) {
  		int k; cin >> k;
  		int L = 0, R = n + 1;
  		
  		while((L + 1) < R) {
  			int m = L + ((R - L) >> 1);
  			int sum;
  			
  			if(v[m] != -1) sum = v[m];
  			else {
  				sum = query_to_judge(1, m);
  				v[m] = sum;
  			}
  			
  			int zer = m - sum;
  			if(zer < k) L = m;
  			else R = m;
  	    }
  	    
  	    cout << "! " << R << endl;
  	    for(int i = R; i <= n; i++) {
  	    	if(v[i] != -1) v[i] += 1;
  	    }
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}