// Explanation ---> https://www.youtube.com/watch?v=pg-8pXQ6M9A&list=PL2q4fbVm1Ik71hmKyay-GkU6J9GTXCe5g&index=3

/**************************************************************************************************************/

// Problem: C. Longest Regular Bracket Sequence
// Contest: Codeforces - Codeforces Beta Round #5
// URL: https://codeforces.com/problemset/problem/5/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 27-01-2021 12:55:10 IST (UTC+05:30)
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
  	string s; cin >> s;
  	int n = s.length();
  	
  	vi first(n, -1);
  	vi extension(n, -1);
  	vi dp(n + 1, 0);
  	stack<int> stk;
  	
  	for(int i = 0; i < n; i++) {
  		if(s[i] == '(') stk.push(i);
  		else if(!stk.empty()) {
  			int pos = stk.top();
  			stk.pop();
  			first[i] = pos;
  			extension[i] = pos;
  			if(pos - 1 >= 0 && s[pos-1] == ')' && first[pos-1] != -1) {
  				extension[i] = extension[pos-1];
  			}
  			
  			int len = i - extension[i] + 1;
  			dp[len]++;
  		}
  	}
  	
  	for(int i = n; i >= 1; i--) {
  		if(dp[i]) {
  			cout << i << " " << dp[i] << "\n";
  			return;
  		}
  	}
  	
  	cout << 0 << " " << 1 << "\n";
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