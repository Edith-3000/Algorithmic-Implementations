/* # Problem: https://www.techiedelight.com/group-anagrams-together-given-list-words/
   # Ref: https://www.youtube.com/watch?v=0I6IL3TnIZs
   # Practice: https://leetcode.com/problems/group-anagrams/
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

vector<vector<string>> group_anagrams(vector<string> &v, int n) {
	unordered_map<string, vi> m;
	
	for(int i = 0; i < n; i++) {
		string tmp = v[i];
		sort(tmp.begin(), tmp.end());
		m[tmp].pb(i);
	}
	
	vector<vector<string>> res;
	unordered_map<string, vi>::iterator it;
	
	for(it = m.begin(); it != m.end(); it++) {
		vector<string> tmp;
		for(int i = 0; i < (int)it->S.size(); i++) {
			tmp.pb(v[it->S[i]]);
		}
		
		res.pb(tmp);
	}
	
	return res;
}

void solve()
{
  	int n; cin >> n;
  	vector<string> v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	vector<vector<string>> res = group_anagrams(v, n);
  	
  	for(auto v: res) {
  		for(auto s: v) cout << s << " ";
  		cout << "\n";
  	}
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

// TC: O(n x m x log2(m)), where n is the total number of words and m
//     is the size of the longest word in the list of input words(strings).
