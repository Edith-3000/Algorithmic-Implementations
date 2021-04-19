// Problem: https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/
// Ref: https://www.youtube.com/watch?v=rRn1vBH-L-8
/*****************************************************************************************************/

// METHOD - 1

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

vi find_ans(int a, int b, int c, int n) {
	vi res;
	if(n == 0) return res;
	
	res.pb(1);
	
	// v[i], v[j] and v[k] are the minimum numbers in res which has not been 
	// multiplied with the corresponding prime number yet.
	int i = 0, j = 0, k = 0;
	
	while(n--) {
		int x = min(res[i] * a, min(res[j] * b, res[k] * c));
		res.pb(x);
		if(x == res[i] * a) i++;
		if(x == res[j] * b) j++;
		if(x == res[k] * c) k++;
	}
	
	res.erase(res.begin());
	return res;
}

void solve()
{
  	int a, b, c, n;
  	cin >> a >> b >> c >> n;
  	
  	vi res = find_ans(a, b, c, n);
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

/********************************************************************************************************/

// METHOD - 2
// Ref: https://github.com/mnpal/InterviewBit/blob/master/Graph%20Data%20Structure%20%26%20Algorithms/Smallest%20sequence%20with%20given%20Primes.cpp

/*****************************************************************************************************************************************************/