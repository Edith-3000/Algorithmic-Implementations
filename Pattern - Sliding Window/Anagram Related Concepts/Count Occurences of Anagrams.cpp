/* # Problem: https://www.geeksforgeeks.org/count-occurrences-of-anagrams/
   # Practice: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1#
               https://leetcode.com/problems/find-all-anagrams-in-a-string/           

   # Approach explanation: https://www.youtube.com/watch?v=MW4lJ8Y0xXk
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

vector<string> find_all_anagrams(string &text, string &pattern) {
	int n = (int)text.size();
	int k = (int)pattern.size();
	
	map<char, int> m;
	for(int i = 0; i < k; i++) m[pattern[i]]++;
	
	// to store all the anagrams
	vector<string> res;
	
	int i = 0; // start index of sliding window
	int j = 0; // end index of sliding window
	
	// #unique characters in the pattern
	int count = m.size();
	
	while(j < n) {
		if(m.find(text[j]) != m.end()) {
			m[text[j]]--;
			if(m[text[j]] == 0) count -= 1;
		}
		
		if((j - i + 1) < k) j++;
		
		else if((j - i + 1) == k) {
			// if count = 0 => we've used up all the characters 
			//                 in the current window
			if(count == 0) res.pb(text.substr(i, j - i + 1));
			
			// make suitable changes for for the next window
			if(m.find(text[i]) != m.end()) {
				m[text[i]]++;
				if(m[text[i]] == 1) count += 1;
			}
			
			i++; j++;
		}
	}
	
	return res;
}

void solve()
{
  	string text, pattern;
  	cin >> text >> pattern;
  	
  	vector<string> res = find_all_anagrams(text, pattern);
  	
  	cout << res.size() << "\n";
  	for(auto x: res) cout << x << " ";
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

// TC: O(n + k), if we just find out the count of anagrams.