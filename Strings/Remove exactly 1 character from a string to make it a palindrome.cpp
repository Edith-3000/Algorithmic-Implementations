// Problem: https://www.interviewbit.com/problems/convert-to-palindrome/
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

bool is_palindrome(int i, int j, string &s) {
	while(i < j) {
	    if(s[i] != s[j]) return 0;
	    i++; j--;
	}
	
	return 1;
}

bool possible(string &s) {
	int n = s.size();
    if(n == 1) return 1;
    
    int i = 0, j = n - 1;
    while(i < j) {
        if(s[i] == s[j]) i++, j--;
        else {
            if(is_palindrome(i + 1, j, s)) return 1;
            if(is_palindrome(i, j - 1, s)) return 1;
            return 0;
        }
    }
    
    return 0;
}

void solve()
{
  	int n; cin >> n;
  	string s; cin >> s;
  	
  	if(possible(s)) cout << "YES\n";
  	else cout << "NO\n";
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