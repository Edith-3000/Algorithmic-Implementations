// Problem: https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
// Ref: https://www.youtube.com/watch?v=Lav6St0W_pQ
/*****************************************************************************************************************/

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

int LLSKU(string &s, int k) {
	int n = (int)s.size();
	if(n == 0) return 0;
	
	int res = 0, i = 0, j = 0;
	map<char, int> cnt;
	
	while(j < n) {
		cnt[s[j]] += 1;
		
		if((int)cnt.size() < k) j++;
		
		else if((int)cnt.size() == k) {
			res = max(res, j - i + 1);
			j++;
		}
		
		else {
			while((int)cnt.size() > k) {
				cnt[s[i]] -= 1;
				if(cnt[s[i]] == 0) cnt.erase(s[i]);
				i++;
			}
			
			j++;
		}
	}
	
	return res;
}

void solve()
{
  	int k; cin >> k;
  	string s; cin >> s;
  	
  	cout << LLSKU(s, k) << "\n";
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

// TC: O(n x log(n))
// NOTE: This complexity can be reduced to O(n), by taking a MAX_CHAR vector of size 256, as given in
//       the GfG article.