// Problem: https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
//          https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/
/***********************************************************************************************************/

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

// https://bit.ly/3vFvsHM
// https://www.youtube.com/watch?v=c4akpqTwE5g

// This variant of KMP algo. returns the length of the longest proper prefix 
// that matches a proper suffix of the string s
int kmp(string s) {
    // lps[i] = the length of the longest proper prefix of the string s[0...i]
    //          that matches a proper suffix of the string s[0...i]
    vector<int> lps(s.size(), 0);
 
    // Traverse the string
    for (int i = 1; i < (int)s.size(); i++) {
        int previous_index = lps[i - 1];
 
        while (previous_index > 0 && s[i] != s[previous_index]) {
            previous_index = lps[previous_index - 1];
        }
 
        // Update the lps size
        lps[i] = previous_index + (s[i] == s[previous_index] ? 1 : 0);
    }
 
    // Returns size of lps
    return lps[lps.size() - 1];
}

int longest_prefix_palindrome(string s) {
	// Append a character to separate the string (i.e to avoid overlap)
	string tmp = s + '?';
	
	// Append the reverse of the string
	reverse(s.begin(), s.end());
	tmp += s;
	
	return kmp(tmp);
}

int min_chars_add(string &s) {
	int n = s.size();
	return n - longest_prefix_palindrome(s);
}

void solve()
{
  	int n; cin >> n;
  	string s; cin >> s;
  	
  	int res = min_chars_add(s);
	string tmp = s;
	reverse(tmp.begin(), tmp.end());	
	
	cout << res << "\n";
  	cout << "The palindromic string after adding characters in the front is --->\n";
  	cout << tmp.substr(0, res) + s << "\n";
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