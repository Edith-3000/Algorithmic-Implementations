// Reference(s): https://www.techiedelight.com/find-pair-with-given-sum-array/

/**********************************************************************************************************/

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

// Function to find all unique pairs with the given sum in an array.
// This method handles duplicates in the array
void find_pairs(vi &v, int n, int k) {
	sort(v.begin(), v.end());
	vpii res;
	
	int i = 0, j = n - 1;
	while(i < j) {
		// to avoid printing duplicates
		while((i + 1) < n and v[i] == v[i+1]) i++;
		while((j - 1) >= 0 and v[j] == v[j-1]) j--;
		
		// decrement j if the current summation is more than the
        // desired summation
		if(v[i] + v[j] > k) j--;
		
		// increment i if the current summation is less than the
        // desired summation
		if(v[i] + v[j] < k) i++;
		
		// store the pair and increment i & decrement j if the current
        // sum is the same as the desired sum
		else {
			res.pb({v[i], v[j]});
			i++; j--;
		}
	}
	
	return res;
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vpii res = find_pairs(v, n, k);

  	cout << res.size() << "\n";
	for(auto x: res) cout << x.F << " " << x.S << "\n";	

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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}