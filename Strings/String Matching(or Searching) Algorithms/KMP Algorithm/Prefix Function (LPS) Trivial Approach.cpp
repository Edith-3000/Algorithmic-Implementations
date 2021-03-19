// Reference: https://cp-algorithms.com/string/prefix-function.html

#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> prefix_function_trivial(string s)
{
	ll n = s.length();
	vector<ll> lps(n, 0);
	
	for(ll i = 0; i < n; i++){
		for(ll length = 0; length <= i; length++){
			if(s.substr(0, length) == s.substr((i - length + 1), length)){
				lps[i] = length;
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
    
    vector<ll> lps = prefix_function_trivial(s);
    
    for(auto ch: s) cout << ch << " ";
    cout << "\n";
    for(auto x: lps) cout << x << " ";
        
    return 0;
}

// Time complexity: O(n^3), where n = string length

// Sample i/p: aabaaab
// Sample o/p: Enter string: aabaaab
//			   a a b a a a b 
//             0 1 2 3 4 5 6 