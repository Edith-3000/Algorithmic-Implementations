// Ref: https://www.geeksforgeeks.org/longest-palindromic-string-formed-by-concatenation-of-prefix-and-suffix-of-a-string/#:~:text=The%20concatenation%20of%20string%20%E2%80%9Crombob,which%20is%20a%20palindromic%20string.
//      https://www.youtube.com/watch?v=oEZQGSLHi-E
/****************************************************************************************************************************************************************************************************************************/

// NOTE: The easier version of the problem can be done in O(n^2) time.
// Easier version: https://codeforces.com/problemset/problem/1326/D1

/************************************************************************/

/* Approach: 
   # The idea is to use KMP Algorithm to find the longest proper prefix which is a palindrome of the 
     suffix of the given string str in O(n) time.  
   
   Step 1. Find the longest prefix of length = len (say s[0, len - 1]) which makes a palindrome with the 
           suffix(say s[n-l, n-1]) of the string str. Prefix and Suffix don’t overlap.

   Step 2. Out of the remaining substring (s[len+1, n-len-1]), find the longest palindromic 
           substring(say ans) which is either a suffix or prefix of the remaining string.
   
   Step 3. The concatenation of s[0, len-1], ans and s[n-len, n-len-1] is the longest palindromic substring.
*/

// Problem: D2. Prefix-Suffix Palindrome (Hard version)
// Contest: Codeforces - Codeforces Global Round 7
// URL: https://codeforces.com/contest/1326/problem/D2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Parsed on: 19-03-2021 13:30:27 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

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

// Function to find the longest palindromic string formed from 
// concatenation of prefix and suffix of a given string s
string longest_prefix_suffix_palin(string s) {
	int n = (int)s.length();
	
	// Calculating the length for which prefix is reverse of suffix
	int len = 0;
  	for(int i = 0, j = n - 1; i < j; i++, j--) {
  		if(s[i] == s[j]) len++;
  		else break;
  	}
  	
  	// Initializing the result
  	string res = s.substr(0, len);
  	
  	// Store the remaining string
  	string rem = s.substr(len, n - 2 * len);
  	
  	// If the remaining string is not empty that means that there can 
  	// be a palindromic prefix or suffix which can be added to res
  	
  	if(rem.size()) {
  		// Calculate the length of longest prefix palindromic 
  		int longest_prefix = longest_prefix_palindrome(rem);
  		
  		 // Reverse the given string to find the longest suffix palindrome
  		reverse(rem.begin(), rem.end());
  		int longest_suffix = longest_prefix_palindrome(rem);
  		
  		// If the length of prefix palindrome is >= the length of 
  		// suffix palindrome
  		if(longest_prefix >= longest_suffix) {
  			reverse(rem.begin(), rem.end());
  			res += rem.substr(0, longest_prefix);
  		}
  		
  		// If the length of suffix palindrome is > the length of 
  		// prefix palindrome
  		else res += rem.substr(0, longest_suffix);
  	}
  	
  	res += s.substr(n - len, len);
  	return res;
}

void solve()
{
  	string s; cin >> s;  	
  	cout << longest_prefix_suffix_palin(s) << "\n";
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
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

// TC: O(n), where n is the length of the given string.