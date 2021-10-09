/* # In combinatorial mathematics, the Catalan numbers form a sequence of natural 
     numbers that occur in various counting problems, often involving recursively-defined objects.
   
   # 𝑪𝒂𝒕𝒂𝒍𝒂𝒏 𝒔𝒆𝒓𝒊𝒆𝒔: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, .....

   # nᵗʰ Catalan Number(direct formula) = (²ⁿCₙ)/(n+1) (indexing is 0 based i.e. for n = 0, 1, 2, 3, ...).
   # nᵗʰ Catalan Number(recursive relation)= f(n) = Σ(f(i-1)*f(n-i)), where i goes from 1 to n (for n>=1)
   											 f(0) = 1

   											 OR
    
   	(n+1)ᵗʰ Catalan Number(recursive relation)=	f(n+1) = Σ(f(i)*f(n-i)), where i goes from 0 to n (for n>=0)
   											    f(0) = 1

   											   Now, replacing n ⟶ n-1
   	∴ nᵗʰ Catalan Number(recursive relation)=  f(n) = Σ(f(i)*f(n-1-i)), where i goes from 0 to (n-1) (for n>=1)
   											   f(0) = 1
   
   # Applications ---->
     • #BST possible with n nodes = nᵗʰ Catalan Number = (²ⁿCₙ)/(n+1)
     • #BT possible with n nodes = (nᵗʰ Catalan Number) * n! = ((²ⁿCₙ)/(n+1)) * n!
     • For more visit: # https://cp-algorithms.com/combinatorics/catalan-numbers.html
                       # Wikipedia
*/

/**********************************************************************************************************************/

//RECURSIVE IMPLEMENTATION

long long nth_catalan_recursive(long long n)
{
	// base condition(s)
	if(n==0) return 1;
	if(n<0) return -1; // catalan no. for -ve nos. isn't defined
    
    long long res=0; // initialize result
	for(long long i=0; i<n; i++)
	  res+=nth_catalan_recursive(i) * nth_catalan_recursive((n-1)-i);

	return res;  
}  

/*In the above recursive algorithm the 2nd formula is used to calculate nᵗʰ Catalan nuumber, ∴ for finding the 
  nᵗʰ term (n-1) is used in place of 'n' in the recurrence relation.
*/

// Time Complexity: O(2ⁿ) ∵ Time complexity of above implementation is equivalent to nᵗʰ catalan number & the 
//                          value of nᵗʰ catalan number is exponential that makes the time complexity exponential.

/**********************************************************************************************************************/

// DYNAMIC PROGRAMMING IMPLEMENTATION (by BOTTOM UP APPROACH)

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

// n is 0-based
ll nth_catalan_no(ll n) {
	// base condition
	// catalan no. for -ve nos. isn't defined
	if(n < 0) return -1; 
	
	vll dp(n + 1);
	dp[0] = 1;
	
	for(ll i = 1; i <= n; i++) {
		dp[i] = 0; // initializing result for each ith catalan no.
		for(ll j = 0; j < i; j++) dp[i] += (dp[j] * dp[i-1-j]);
	}
	
	return dp[n];
}

void solve()
{	
  	ll n; cin >> n;
  	cout << nth_catalan_no(n) << "\n";
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

// Here dp is a vector of size (n+1) to store the the nth catalan no.
// Time Complexity of DP APPROACH: O(n²)

/**********************************************************************************************************************/

// USING BINOMIAL COEFFICIENT IMPLEMENTATION

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

ll nCr(ll n, ll r) {
	if(r > n) return 0;
	if(r == n or r == 0) return 1;
	
	// since C(n, r) = C(n, n-r) 
	// it is done so as to reduce the #iterations
	if(r > (n - r)) r = n - r;	
	
	ll res = 1; //initialize result
	
	for(ll i = 0; i < r; i++) {
		res *= (n - i);
		res /= (i + 1);
	}
	
	return res;
}

// n is 0-based
ll nth_catalan_no(ll n) {
	// base condition
	// catalan no. for -ve nos. isn't defined
	if(n < 0) return -1; 
	
	ll res = nCr(2 * n, n);
	res /= (n + 1);
	
	return res;
}

void solve()
{	
  	ll n; cin >> n;
  	cout << nth_catalan_no(n) << "\n";
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

// Time Complexity of BINOMIAL COEFFICIENT APPROACH: O(n)