// Problem: D. a-Good String
// Contest: Codeforces - Codeforces Round #656 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1385/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 25-01-2021 16:04:48 IST (UTC+05:30)
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

int freq[131072][26];

void prep(string &s, int n) {
	for(char ch = 'a'; ch <= 'z'; ch++) {
		if(s[0] == ch) freq[0][ch - 'a'] = 1;
		else freq[0][ch - 'a'] = 0;
	}
	
	for(int i = 1; i < n; i++) {
		for(char ch = 'a'; ch <= 'z'; ch++) {
			if(s[i] == ch) freq[i][ch - 'a'] = freq[i-1][ch - 'a'] + 1;
			else freq[i][ch - 'a'] = freq[i-1][ch - 'a'];
		}
	}
}

int get_cost(int i, int pow, char good) {
	int j = i + (1 << pow) - 1;
	return freq[j][good - 'a'] - ((i == 0) ? 0 : freq[i-1][good - 'a']);
}

int driver(int start, int k, char good, string &s) {
	// base case
	if(k == 0) return s[start] != good;
	
	int half1 = (1 << (k - 1)) - get_cost(start, k - 1, good);
	int half2 = (1 << (k - 1)) - get_cost(start + (1 << (k - 1)), k - 1, good);
	
	return min(half1 + driver(start + (1 << (k - 1)), k - 1, good + 1, s), 
			   half2 + driver(start, k - 1, good + 1, s));
}

void solve()
{
  	int n; string s;
  	cin >> n >> s;
  	prep(s, n);
  	
  	int k = 0, x = 1;
  	while(x != n) ++k, x *= 2;
  	
  	cout << driver(0, k, 'a', s) << "\n";
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