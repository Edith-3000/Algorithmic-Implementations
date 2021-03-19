// PROBLEM STATEMENT: Given a text and a pattern, find all occurrences of pattern in text.

/*
  # The most important difference between KMP & Rabin-Karp is how reliable they are in finding a match. 
  # KMP guarantees 100% reliability. You cannot guarantee 100% with Rabin Karp because of a chance of collision 
    during hash table lookup. 
  # But with good hash generation algorithms that do exist today, it is possible that Rabin Karp can yield very 
    close to 100% reliability in finding a match. And both have complexity of O(n + m). Also Rabin Karp is easier 
    to implement than KMP it works based on a rolling hash whereas KMP works based on a failure function.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> prefix_function_optimized(string s)
{
	ll n = s.length();
	vector<ll> lps(n);
	
	lps[0] = 0;
	
	// i is the normal iterator
	// j basically denotes the length of the longest 
	// prefix which is also a suffix in the substring [0....(i-1)]
	ll i = 1, j = 0;
	
	while(i < n) {
		if(s[i] == s[j]) {
			lps[i] = j + 1;
			i++; j++;
		}
		
		else{
			if(j == 0) {
				lps[i] = 0;
				i++;
			}
			
			else {
				j = lps[j - 1];
			}
		}
	}
	
	return lps;
}

vector<ll> kmp(string text, string pat)
{
	// calculating the lps for pattern
	vector<ll> lps = prefix_function_optimized(pat);
	
	// for storing the result
	vector<ll> occurrences;
	
	ll n = text.size(), m = pat.size();
	
	ll i = 0; // iterator for the text
	ll j = 0; // iterator for the pattern
	
	while(i < n) {
		if(text[i] == pat[j]){
			i++; 
			j++;
		}
		
		else {
			if(j == 0) i++;
			else j = lps[j - 1];		
		}
		
		if(j == m) {
			occurrences.push_back(i - m);
			j = lps[j - 1];
		}
	}
	
	// return the result
	return occurrences;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter the text(haystack): ";
    string text; cin >> text; cout << text <<"\n";
    cout << "Enter the pattern to be searched(needle): ";
    string pat; cin >> pat; cout << pat <<"\n";
       
    if(pat.length() > text.length()){
        cout << "Pattern length > Text length" << "\n";
        return 0;
    }
    
    cout << "\nPattern found at the following positions ---> \n";
    vector<ll> res = kmp(text, pat);
    for(auto x: res) cout << x << "\n";

    return 0;
}

// Time complexity: O(n + m)
// Reference: https://cp-algorithms.com/string/prefix-function.html

/* Sample i/p: abaabababaababa
			   aba

   Sample o/p: Enter the text(haystack): abaabababaababa
			   Enter the pattern to be searched(needle): aba

			   Pattern found at the following positions ---> 
			   0
			   3
			   5
			   7
			   10
			   12
*/

/***************************************************************************************************************/

// Following is a very simple & short implementation of the above method by making use of prefix function
// only on the concatenated string i.e. on text + "$" + pattern

#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> prefix_function_optimized(string s)
{
	ll n = s.size();
	vector<ll> lps(n);
	
	lps[0] = 0;
	
	for(ll i = 1; i < n; i++){
		ll j = lps[i - 1];
		
        while((j > 0) && (s[i] != s[j])){
        	j = lps[j - 1];
        }
        
        if(s[i] == s[j]) j++;
        lps[i] = j;
	}
	
	return lps;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter the text(haystack): ";
    string text; cin >> text; cout << text <<"\n";
    cout << "Enter the pattern to be searched(needle): ";
    string pat; cin >> pat; cout << pat <<"\n";
       
    if(pat.length() > text.length()){
        cout << "Pattern length > Text length" << "\n";
        return 0;
    }
    
    string good = pat + "$" + text;
    vector<ll> lps = prefix_function_optimized(good);
    
    cout << "\nPattern found at the following positions ---> \n";
    ll n = text.size(), m = pat.size();
    
    for(ll i = (m + 1); i < good.size(); i++){
    	if(lps[i] == m){
    		cout << ((i - m + 1) - (m + 1)) << "\n";
    	}
    }

    return 0;
}

// Time complexity: O(n + m)
// Reference: https://cp-algorithms.com/string/prefix-function.html

/* Sample i/p: abaabababaababa
			   aba

   Sample o/p: Enter the text(haystack): abaabababaababa
			   Enter the pattern to be searched(needle): aba

			   Pattern found at the following positions ---> 
			   0
			   3
			   5
			   7
			   10
			   12
*/