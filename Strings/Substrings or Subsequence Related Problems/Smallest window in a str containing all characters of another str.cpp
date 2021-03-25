// Ref: https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
// Ques. based on this concept: https://codeforces.com/problemset/problem/701/C
/**********************************************************************************************************************/

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
const int max_chars = 256;

// Function to find smallest window in 'txt' containing
// all characters of 'pat'
void find_window(string &txt, string &pat) {
	int n = (int)txt.length();
	int m = (int)pat.length();
	
	// check if txt length is less than pattern's length. 
	// If yes then no such window can exist
	if(n < m) {
		cout << "No such window exists\n";
		return;
	}
	
	int hash_txt[max_chars] = { 0 };
	int hash_pat[max_chars] = { 0 };
	
	// Store occurrence ofs characters of pattern 'pat'
	for(int i = 0; i < m; i++) {
		hash_pat[pat[i]]++;
	}
	
	int start = 0;
	int count = 0, start_idx = -1, mn_len = INT_MAX;
	
	for(int i = 0; i < n; i++) {
		// count occurrence of characters of string
		hash_txt[txt[i]]++;
		
		// if string's char matches with pattern's char
        // then increment count
		if(hash_txt[txt[i]] <= hash_pat[txt[i]]) count += 1;
		
		 // if all the characters are matched
		if(count == m) {
			while(hash_txt[txt[start]] > hash_pat[txt[start]] or hash_pat[txt[start]] == 0) {
			      hash_txt[txt[start]]--;
			      start++;
			}
			
			// update window size
			if(mn_len > (i - start + 1)) {
				mn_len = i - start + 1;
				start_idx = start;
			}
		}
	}
	
	// if no window found
	if(start_idx == -1) cout << "Not found\n";
	
	// if window found
	else {
		cout << mn_len << "\n";
		cout << txt.substr(start_idx, mn_len) << "\n"; 
	}
}

void solve()
{
  	int n; cin >> n;
  	string txt; cin >> txt;
  	
  	set<char> s;
  	for(int i = 0; i < n; i++) s.insert(txt[i]);
  	
  	string pat = "";
  	for(auto ch: s) pat += ch;
  	
  	find_window(txt, pat);
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