// Link: https://www.geeksforgeeks.org/find-the-original-array-using-xor-values-of-all-adjacent-elements/
/********************************************************************************************************/

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

int compute_xor_from_1_to_n(const int n) {
	// Modulus operator are expensive on most of the  
    // computers. n & 3 will be equivalent to n % 4.    
    
    // (n % 4) similar to (n & 3)  
    switch(n & 3) {  
        case 0: return n;      // if n is multiple of 4 
        case 1: return 1;      // If n % 4 gives remainder 1   
        case 2: return n + 1;  // If n % 4 gives remainder 2     
        case 3: return 0;      // If n % 4 gives remainder 3   
    } 

    return EXIT_SUCCESS; //it's just to avoid warning
}

vi find_ans(vi &v) {
	int n = (int)v.size();
	vi res;
	
	int xor_all = compute_xor_from_1_to_n(n + 1);
	int xor_adj = 0;
	
	for(int i = 0; i < n; i += 2) {
		xor_adj ^= v[i];
	}
	
	int last_element = xor_all ^ xor_adj;
	res.pb(last_element);
	
	for(int i = (n - 1); i >= 0; i--) {
		last_element = last_element ^ v[i];
		res.pb(last_element);
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vi res = find_ans(v);
  	
  	cout << res.size() << "\n";
  	for(int i = res.size() - 1; i >= 0; i--) {
  		cout << res[i] << " ";
  	}
  	
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