/* # Ref: https://www.youtube.com/watch?v=2NaaM_z_Jig
          https://www.techiedelight.com/word-break-problem/
          https://www.geeksforgeeks.org/word-break-problem-dp-32/
*/

/* Problem --->
   Word Break Problem: Given a string and a dictionary of words, determine if the string can be 
   segmented into a space-separated sequence of one or more dictionary words.
*/

/************************************************************************************************/

// Method 1 (Recursive approach, it can print each segment as well).

#include<bits/stdc++.h>
using namespace std;

// Function to segment a given string into a space-separated
// sequence of one or more dictionary words

void word_break(vector<string> &dict, string str, string res) {
	// base case, if the end of the string str is reached,
    // print the output string
	if(str.size() == 0) {
		cout << res << "\n";
		return;
	}
	
	// consider all length prefixes of the current string str
	for(int i = 1; i <= str.length(); i++) {
		// prefix of length = i
		string prefix = str.substr(0, i);
		
		 // if the prefix is present in the dictionary, add it to the
        // output string and recur for the remaining string str
		if(find(dict.begin(), dict.end(), prefix) != dict.end()) {
			word_break(dict, str.substr(i), res + " " + prefix);
		}
	}
}

void solve()
{
	// to input dictionary size
  	int n; cin >> n;
  	
  	// vector of strings to represent a dictionary
    // we can also use a Trie or a set to store a dictionary
  	vector<string> dict(n);
  	for(int i = 0; i < n; i++) cin >> dict[i];
  	
  	// to input the string which is to be segmented
  	string str; 
  	cin >> str;
  	
  	word_break(dict, str, "");
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

/*

Sample i/p --->

16
this 
th 
is
famous 
Word 
break
b 
r 
e 
a 
k 
br 
bre 
brea 
ak 
problem
Wordbreakproblem

Sample o/p --->

 Word b r e a k problem
 Word b r e ak problem
 Word br e a k problem
 Word br e ak problem
 Word bre a k problem
 Word bre ak problem
 Word brea k problem
 Word break problem

*/

// TC: Exponential

/************************************************************************************************/

// Method 1.1 (alight variation of Method 1)

/* In this version only have to determine if a string can be segmented into a space-separated 
   sequence of one or more dictionary words or not, and not actually print all sequences.
*/

#include<bits/stdc++.h>
using namespace std;

// Function to tell if it is possible segment a given string into 
// a space-separated sequence of one or more dictionary words

bool word_break(vector<string> &dict, string str) {
	// base case, if the end of the string str is reached,
    // return true
	if(str.size() == 0) {
		return true;
	}
	
	// consider all length prefixes of the current string str
	for(int i = 1; i <= str.length(); i++) {
		// prefix of length = i
		string prefix = str.substr(0, i);
		
		 // if the prefix is present in the dictionary, recur 
		 // for the remaining string str
		if(find(dict.begin(), dict.end(), prefix) != dict.end()) {
			if(word_break(dict, str.substr(i))) return true;
		}
	}
	
	 // return false if the string can't be segmented
	return false;
}

void solve()
{
	// to input dictionary size
  	int n; cin >> n;
  	
  	// vector of strings to represent a dictionary
    // we can also use a Trie or a set to store a dictionary
  	vector<string> dict(n);
  	for(int i = 0; i < n; i++) cin >> dict[i];
  	
  	// to input the string which is to be segmented
  	string str; 
  	cin >> str;
  	
  	if(word_break(dict, str)) cout << "YES\n";
  	else cout << "NO\n";
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

// TC: Exponential

/***********************************************************************************************/

// Method 2 (Bottom up DP)

// Note: this method can also find out the number of space separated sequences of dictionary
//       into which the string can be segmented.
// Approach link: https://www.youtube.com/watch?v=2NaaM_z_Jig

#include<bits/stdc++.h>
using namespace std;
typedef vector<long long> vll;

// Function to tell if it is possible segment a given string into 
// a space-separated sequence of one or more dictionary words

bool word_break(vector<string> &dict, string str) {
	int len = str.length();
	
	// dp[i] = #ways the prefix of length (i+1) can be divided into space 
	// separated sequences of dictionary words
	// Therefore, final result lies in dp[len-1]
	vll dp(len, 0);
	
	for(int i = 0; i < len; i++) {
		for(int j = 0; j <= i; j++) {
			string word = str.substr(j, i - j + 1);
			if(find(dict.begin(), dict.end(), word) != dict.end()) {
				if(j > 0) dp[i] += dp[j-1];
				else dp[i] += 1LL;
			}
		}
	}
	
	if(dp[len-1]) return true;
	else return false;
}

void solve()
{
	// to input dictionary size
  	int n; cin >> n;
  	
  	// vector of strings to represent a dictionary
    // we can also use a Trie or a set to store a dictionary
  	vector<string> dict(n);
  	for(int i = 0; i < n; i++) cin >> dict[i];
  	
  	// to input the string which is to be segmented
  	string str; 
  	cin >> str;
  	
  	if(word_break(dict, str)) cout << "YES\n";
  	else cout << "NO\n";
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

// TC: O(len^2 * (len + n*w)), 
// where w = length of the longest string present in dict

// Note: This solution may Time out (as it has timed out on Leetcode)
// Therefore to resolve this I have modified the word_break() fn a little  and 
// it got an AC on Leetcode--->

bool word_break(vector<string> &dict, string str) {
	int len = str.length();
	
	// dp[i] = #ways the prefix of length (i+1) can be divided into space 
	// separated sequences of dictionary words
	// Therefore, final result lies in dp[len-1]
	vector<bool> dp(len, 0);
	
	for(int i = 0; i < len; i++) {
		for(int j = 0; j <= i; j++) {
			string word = str.substr(j, i - j + 1);
			if(find(dict.begin(), dict.end(), word) != dict.end()) {
				if(j > 0) {
                	if(dp[j-1]) dp[i] = 1;
                }  
                    
                else dp[i] = 1;
			}
		}
	}
	
	if(dp[len-1]) return true;
	else return false;
}

/**********************************************************************************************/

// Method 3 (Top down DP)
// Explanation: https://www.youtube.com/watch?v=XtIGGdrF67E

#include<bits/stdc++.h>
using namespace std;

// Function to tell if it is possible segment a given string into 
// a space-separated sequence of one or more dictionary words

unordered_map<string, bool> dp;

bool word_break(vector<string> &dict, string str) {
	int len = str.length();
	
	// base case
	if(len == 0) return 1;
	
	// check if already calculated or not
	if(dp[str]) return 1;
	
	for(int i = 1; i <= len; i++) {
		string prefix = str.substr(0, i);
		
		bool found = 0;
		for(int j = 0; j < dict.size(); j++) {
			if(prefix.compare(dict[j]) == 0) {
				found = 1;
				break;
			}
		}
		
		if(found and word_break(dict, str.substr(i))) return dp[str] = 1;
	}
	
	return dp[str] = 0;
}

void solve()
{
	// to input dictionary size
  	int n; cin >> n;
  	
  	// vector of strings to represent a dictionary
    // we can also use a Trie or a set to store a dictionary
  	vector<string> dict(n);
  	for(int i = 0; i < n; i++) cin >> dict[i];
  	
  	// to input the string which is to be segmented
  	string str; 
  	cin >> str;
  	
  	if(word_break(dict, str)) cout << "YES\n";
  	else cout << "NO\n";
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