// Ref: https://www.geeksforgeeks.org/count-of-pairs-in-an-array-whose-product-is-a-perfect-square/
/***************************************************************************************************/

/* Problem --->
   Given an array arr[] of n integers, the task is to find the number of pairs (arr[i], arr[j]) 
   such that arr[i]*arr[j] is a perfect square.
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
const int N = 1e6;

vi prime(N+1);

// Every number can be expressed in the form (k * x)          
// k is not divisible by any perfect square other than 1,
// and x = perfect square
vi k(N+1);

void SOE() {
	// vector k[] to store the value of k for each element in v[] 
	for(int i = 1; i <= N; i++) k[i] = i;
	
	// For find if i is a prime or not
	for(int i = 3; (i * i) <= N; i += 2) prime[i] = 1;
	prime[2] = 1;
	
	for(int i = 2; (i * i) <= N; i++) {
		if(prime[i]) {
			for(int j = i; j <= N; j += i) {
				// Mark j as not prime
				prime[j] = 0;
				
				// Remove all square divisors i.e. if k[j] is divisible 
                // by (i * i) then divide it by (i * i) 
				while(k[j] % (i * i) == 0) {
					k[j] /= (i * i);
				}
			}
		}
	}
}

// Function that return total count of pairs with pefect square product 
ll count_pairs(vi &v, int n) {
	// map used to store the frequency of k value for every value in v[] 
	unordered_map<int, int> freq;
	for(int i = 0; i < n; i++) freq[k[v[i]]]++;
	
	ll res = 0LL;
	for(auto x: freq) {
		res += (x.S * (x.S - 1)) / 2;
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << count_pairs(v, n);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
	
	SOE();
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

// Time Complexity: O(n * log2(log2(n)))