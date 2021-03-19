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
	
	while(i < n){
		if(s[i] == s[j]){
			lps[i] = j + 1;
			i++;
			j++;
		}
		
		else{
			// find the longest prefix which was also 
			// the suffix in the suffix
			if(j == 0){
				lps[i] = 0;
				i++;
			}
			
			else{
				j = lps[j - 1];
			}
		}
	}
	
	return lps;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter string: ";
    string s; cin >> s; cout << s << "\n";
    
    vector<ll> lps = prefix_function_optimized(s);
    
    for(auto ch: s) cout << ch << " ";
    cout << "\n";
    for(auto x: lps) cout << x << " ";

    return 0;
}

// Time complexity: O(n), where n = string length
// Reference: https://cp-algorithms.com/string/prefix-function.html

// Sample i/p: aabaaab
// Sample o/p: Enter string: aabaaab
//			   a a b a a a b 
//             0 1 2 3 4 5 6 

/****************************************************************************************************************/

// Below code is also same as above with few lines of code

#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> prefix_function_optimized(string s)
{
	ll n = s.length();
	vector<ll> lps(n);
	
	lps[0] = 0;
	
	for(ll i = 1; i < n; i++){
		// j basically stores the length of the longest prefix
		// which is also a suffix in the substring from [0...(i-1)]
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

    cout << "Enter string: ";
    string s; cin >> s; cout << s << "\n";
    
    vector<ll> lps = prefix_function_optimized(s);
    
    for(auto ch: s) cout << ch << " ";
    cout << "\n";
    for(auto x: lps) cout << x << " ";

    return 0;
}

// Time complexity: O(n), where n = string length
// Reference: https://cp-algorithms.com/string/prefix-function.html

// Sample i/p: aabaaab
// Sample o/p: Enter string: aabaaab
//			   a a b a a a b 
//             0 1 2 3 4 5 6 