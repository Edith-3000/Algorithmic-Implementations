// Problem: https://www.interviewbit.com/problems/palindromic-binary-representation/
// Ref: https://www.youtube.com/watch?v=QYoWR8hDCyQ
/*****************************************************************************************************/

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

int get_reverse(int n) {
	int res = 0;
	while(n > 0) {
		int k = n & 1;
		n >>= 1;
		
		res |= k;
		res <<= 1;
	}
	
	res >>= 1;
	return res;
}

int nth_binary_palin(int n) {
	// the smallest binary palindrome has length = 1
	int len = 1;
	
	// it stores the total #binary palindromes upto length = [1, len]
	int cnt = 1;
	
	while(cnt < n) {
		len += 1;
		
		// x = total #binary palindromes in length = len
		int x = 1 << ((len - 1) / 2);
		
		// taking cumulative sum
		cnt += x;
	}
	
	cnt -= (1 << ((len - 1) / 2));
	int offset = n - cnt - 1;
	
	int res = 1 << (len - 1);
	res |= (offset << (len / 2));
	
	int val_for_rev = res >> (len / 2);
	int rev = get_reverse(val_for_rev);
	
	res |= rev;
	return res; 
}

void solve()
{
  	int n; cin >> n;
  	cout << nth_binary_palin(n) << "\n";
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