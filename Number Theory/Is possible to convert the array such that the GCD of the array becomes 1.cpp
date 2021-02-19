/* Problem --->
   Given an array of positive elements and a positive integer k, the task is to convert the GCD of the 
   array to 1. To make it possible, only one operation is allowed any number of times i.e. choose any element 
   of the array & divide with a number d where d <= k.
   Source: https://www.geeksforgeeks.org/convert-array-gcd-array-becomes-1/#:~:text=gcd%201.,then%20the%20answer%20is%20Yes.
*/

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

bool is_possible(vi &v, int n, int k) {
	int gcd = v[0];
  	for(int i = 1; i < n; i++) gcd = __gcd(gcd, v[i]);
  	
  	int mx = 1;
  	for(int i = 2; i * i <= gcd; i++) {
  		if(gcd % i == 0) {
  			mx = max(mx, i);
  			while(gcd % i == 0) gcd /= i;
  		}
  	}
  	
  	if(gcd > 1) mx = max(mx, gcd);
  	return mx <= k;
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	if(is_possible(v, n, k)) cout << "YES\n";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}