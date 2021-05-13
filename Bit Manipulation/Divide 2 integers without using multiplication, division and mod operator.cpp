// Problem: https://www.interviewbit.com/problems/divide-integers/
// Ref: https://www.geeksforgeeks.org/divide-two-integers-without-using-multiplication-division-mod-operator/
/**************************************************************************************************************/

// Time complexity : O(log(a)) 
// Auxiliary space : O(1)

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

ll divide(int x, int y) {
	ll a = x, b = y;
	
	int sign = 1;
	if(a < 0 and b < 0) sign = 1;
	else if(a < 0 or b < 0) sign = -1;
	
	ll res = 0, tmp = 0;
	
	for(int i = 31; i >= 0; i--) {
		if((tmp + (b << i)) <= a) {
			tmp += (b << i);
			res |= (1LL << i);
		}
	}
	
	res *= sign;
	return res;
}

void solve()
{
  	int a, b; cin >> a >> b;  	
  	cout << divide(a, b) << "\n";
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

// Remember: res |= (1LL << i) is same as res += (1LL << i);