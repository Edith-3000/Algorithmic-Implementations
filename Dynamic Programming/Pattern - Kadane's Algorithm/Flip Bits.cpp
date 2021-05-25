// Problem: https://www.interviewbit.com/problems/flip/
// Ref: https://www.youtube.com/watch?v=bF5XDdjneDk
//      https://www.interviewbit.com/problems/flip/ 
/*******************************************************************************************************/

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

vi find_ans(string s) {
	int n = s.size();
	int st = -1, ed = -1;
	int ans = -1, sum = 0;
	int tst = 0;
	
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') sum += 1;
		else sum -= 1;
		
		if(sum >= 0) {
			if(sum > ans) {
				ans = sum;
				st = tst;
				ed = i;
			}
		}
		
		else {
			sum = 0;
			tst = i + 1;
		}
	}
	
	vi res;
	if(ans > 0) {
		res.pb(st + 1);
		res.pb(ed + 1);
	}
	
	return res;
}

void solve()
{
  	string s; cin >> s;
  	
  	vi res = find_ans(s);
  	for(auto x: res) cout << x << " ";
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
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}