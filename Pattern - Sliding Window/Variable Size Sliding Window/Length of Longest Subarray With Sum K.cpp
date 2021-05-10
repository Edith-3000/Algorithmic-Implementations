/* Problem: Given an array containing N POSITIVE integers and an integer K. Your task is to find the length 
            of the longest Sub-Array with sum of the elements equal to the given value K.

		    For Input:
			7 5
			4 1 1 1 2 3 5
			
			output is: 
			4

// Ref: https://www.youtube.com/watch?v=cyu_nuW5utA
//      https://www.youtube.com/watch?v=TfQPoaRDeMQ

*/

// CAUTION: This approach works only when the array elements are POSITIVE
//          For finding answer for NEGATIVE numbers as well, refer file "Longest Subarray With Sum K.cpp"
//          in the folder "Pattern - Hash Table or Hash Map & Hashing"

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

int longest_subarr(vi &v, ll k) {
	int n = (int)v.size();
	if(n == 0) return 0;
	
	int i = 0, j = 0, res = 0;
	ll sum = 0LL;
	
	while(j < n) {
		sum += v[j];
		if(sum < k) j++;
		
		else if(sum == k) {
			res = max(res, j - i + 1);
			j++;
		}
		
		else {
			while(sum > k) {
				sum -= v[i];
				i++;
			}
			
			j++;
		}
	}
	
	return res;
}

void solve()
{
  	int n; ll k;
  	cin >> n >> k;
  	
  	vi v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << longest_subarr(v, k) << "\n";
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