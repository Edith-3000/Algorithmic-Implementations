// Approach: https://www.youtube.com/watch?v=NMSiu-VNfYU
/********************************************************************************************************/

// Problem: G. Maximize the Remaining String
// Contest: Codeforces - Codeforces Round #710 (Div. 3)
// URL: https://codeforces.com/contest/1506/problem/G
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// Parsed on: 29-03-2021 12:33:09 IST (UTC+05:30)
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

int distinct(string s) {
	sort(s.begin(), s.end());
	return unique(s.begin(), s.end()) - s.begin();
}

void solve()
{
  	string s; cin >> s;
  	int n = int(s.size());
  	
  	vector<int> last_pos(26, -1);
  	for(int i = 0; i < n; i++) {
  		last_pos[s[i] - 'a'] = i;
  	}
  	
  	stack<char> stk;
  	vector<bool> taken(26, false);
  	
  	for(int i = 0; i < n; i++) {
  		if(taken[s[i] - 'a']) continue;
  		
  		if(stk.empty()) {
  			stk.push(s[i]);
  			taken[s[i] - 'a'] = true;
  		}
  		
  		else {
  			while(!stk.empty() and stk.top() < s[i] and last_pos[stk.top() - 'a'] > i) {
  				taken[stk.top() - 'a'] = false;
  				stk.pop();
  			}
  			
  			stk.push(s[i]);
  			taken[s[i] - 'a'] = true;
  		}
  	}
  	
  	assert((int)stk.size() == distinct(s));
  	
  	string res = "";
  	while(!stk.empty()) {
  		res += stk.top();
  		stk.pop();
  	}
  	
  	reverse(res.begin(), res.end());
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
    // int test = 1;
    cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}