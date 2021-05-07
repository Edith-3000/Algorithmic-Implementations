// Problem: https://www.interviewbit.com/problems/multiply-strings/
// Ref: https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
/******************************************************************************************************/

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

string multiply(string &s1, string &s2) {
	int sign = 1;
	if((s1[0] == '-' or s2[0] == '-') and (s1[0] != '-' or s2[0] != '-')) sign = -1;
	if(s1[0] == '-') s1 = s1.substr(1);
	if(s2[0] == '-') s2 = s2.substr(1);
	
	int n1 = (int)s1.size();
	int n2 = (int)s2.size();
	
	if(n1 == 0) return s2;
	if(n2 == 0) return s1;
	
	vi v(n1 + n2, 0);
	int carry = 0, ii = 0, jj = 0;
	
	for(int i = n1 - 1; i >= 0; i--) {
		int d1 = s1[i] - '0';
		jj = 0; carry = 0;
		
		for(int j = n2 - 1; j >= 0; j--) {
			int d2 = s2[j] - '0';
			carry += (d1 * d2) + v[ii + jj];
			v[ii + jj] = carry % 10;
			carry /= 10;
			jj += 1;	
		}
		
		if(carry > 0) v[ii + jj] += carry;
		ii += 1;
	}
	
	int i = v.size() - 1;
	while(i >= 0 and v[i] == 0) i--;
	
	if(i == -1) return "0";
	
	string res = "";
	if(sign == -1) res.pb('-');
	
	while(i >= 0) {
		res.pb((char)('0' + v[i]));
		i--;
	}
	
	return res;
}

void solve()
{
  	string s1, s2; cin >> s1 >> s2;
  	cout << multiply(s1, s2) << "\n";
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

// Time Complexity: O(n1 x n2), where n1 & n2 are length of two number that need to be multiplied. 