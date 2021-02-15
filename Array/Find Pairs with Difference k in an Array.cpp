// Reference(s): https://www.techiedelight.com/find-pairs-given-difference-k-array-constant-space-solution/
//               https://www.techiedelight.com/find-pairs-with-given-difference-array/

/*************************************************************************************************************/

// Method 1 (Constant Space)

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

// Function to find all unique pairs with the given difference in an array.
// This method handles duplicates in the array
void find_pairs(vi &v, int n, int k) {
	sort(v.begin(), v.end());
	vpii res;
	
	int i = 0, j = 0;
	while(i < n and j < n) {
		// to avoid storing duplicates
		while((i + 1) < n and v[i] == v[i+1]) i++;
		while((j + 1) < n and v[j] == v[j+1]) j++;
		
		// increment i if the current difference is more than the
        // desired difference
		if(v[j] - v[i] > k) i++;
		
		// increment j if the current difference is less than the
        // desired difference
		else if(v[j] - v[i] < k) j++;
		
		// store the pair and increment both i & j if the current
        // difference is the same as the desired difference
		else {
			res.pb({v[i], v[j]});
			i++; j++;
		}
	}
	
	cout << res.size() << "\n";
	for(auto x: res) cout << x.F << " " << x.S << "\n";	
}

void solve()
{
  	int n, k; cin >> n >> k;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	find_pairs(v, n, k);
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

// Time complexity: O(n x log2(n))

/*************************************************************************************************************/