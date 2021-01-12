/* Problem description --->

For a given number n, form a list and insert the following pattern into the list at the same position sequentially.
{floor(n/2) , n%2 , floor(n/2) }
Until every element in the list is either 1 or 0. Now, calculate number of 1s in from l to r (1-indexed).

EXPLAINATION: Start from n. Then make a list with the following elements.i.e. {floor(n/2) , n%2 , floor(n/2) }. 
Now this list has three elements. Now further break down each of those 3 elements considering the new n to be 
floor(n/2) , n%2 and floor(n/2) respectively for those three elements respectively INPLACE. And this process 
will go on until the n reduces down to 1 or 0. So it will basically form a tree with 3 branches coming out of 
every node at every level starting from 1 node (n) at the root.

Input Format --->
Three integers n, l, r

Constraints --->
0 ≤ n < 10^12
0 ≤ r - l ≤ 10^6
1 ≤ l ≤ r

Output Format --->
Single line containing number of 1s in the given range.

Sample Input --->
9 6 9

Sample Output --->
3

Explanation--->
9 will have the sequence : 101010111010101

*/

// CAUTION: In this problem even the DP solution will give MLE(Memory Limit Exceeded) as string generated
//          corresponding to numbers such as 10^10 will be containing huge number of 0's and 1's.

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

ll size_count(ll n) {
	// base case
	if(n == 0 || n == 1) return 1;
	
	// recursive case
	return (size_count(n/2) * 2) + 1;
}

ll driver(ll n, ll l, ll r, ll start, ll end) {
	// no overlap case
	if((start > r) || (end < l) || (start > end)) return 0;
	
	ll res = 0;
	ll mid = end + (start - end)/2;
	if(mid >= l && mid <= r && (n % 2 == 1)) res = 1;
	res += driver(n/2, l, r, start, mid - 1);
	res += driver(n/2, l, r, mid + 1, end);
	
	return res;
}

void solve()
{
  	ll n, l, r; 
  	cin >> n >> l >> r;
  	
  	cout << driver(n, l, r, 1, size_count(n));
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