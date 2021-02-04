// Problem: B. Ternary String
// Contest: Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1354/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 04-02-2021 22:54:37 IST (UTC+05:30)
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
string s;

// This function will return true if there exists a subarray of length
// exactly 'k' such that there is atleast one occurrence of each of the
// elements 1, 2 and 3.
// This func. is monotonic: bcoz if there exists such subarray as claimed
// by this func. then there will surely exist such a subarray of size (k + 1) also
bool is_valid(int k) {
	int cnt[4] = {0};
	for(int i = 0; i < (k - 1); i++) {
		int ele = s[i] - '0';
		cnt[ele]++;
	}
	
	for(int i = k - 1; i < (int)s.length(); i++) {
		int ele = s[i] - '0';
		cnt[ele]++;
		
		if(cnt[1] > 0 and cnt[2] > 0 and cnt[3] > 0) return true;
		
		ele = s[i - k + 1] - '0';
		cnt[ele]--;
	}
	
	return false;
}

int binsearch() {
	int res = INF;
	int L = 3, H = s.length();
	
	while(L <= H) {
		int mid = L + ((H - L) >> 1);
		if(is_valid(mid)) {
			res = min(res, mid);
			H = mid - 1;
		}
		
		else L = mid + 1;
	}
	
	return (res == INF) ? 0 : res;
}

void solve()
{
  	cin >> s;
  	cout << binsearch() << "\n";
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