// Ref: https://www.geeksforgeeks.org/periodic-binary-string-with-minimum-period-and-a-given-binary-string-as-subsequence/
/**************************************************************************************************************************/

// Problem: B. Binary Period
// Contest: Codeforces - Educational Codeforces Round 86 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1342/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 26-02-2021 13:00:58 IST (UTC+05:30)
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
    string t; cin >> t;
    int n = (int)t.length();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(t[i] == '1') cnt++;
    }

    if(cnt == n || cnt == 0) {
        cout << t << "\n";
        return;
    }

    char res[2 * n];
    for(int i = 0; i < 2 * n; i += 2) {
        res[i] = '1';
        res[i+1] = '0';
    }

    for(int i = 0; i < 2 * n; i++) cout << res[i];
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}