// References: https://www.geeksforgeeks.org/string-hashing-using-polynomial-rolling-hash-function/
//             https://cp-algorithms.com/string/string-hashing.html

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll poly_rolling_hash(string s)
{
	// p is any num(preferrably a prime)
	// mod(a prime num) is used to avoid overflow
	ll p = 31, mod = 1e9 + 7;
	
	// to store the hash value of string
	ll hash = 0; 
	
	// since p^0 = 1
	ll p_power = 1; 
	
	for(ll i = 0; i < s.size(); i++){
		hash += (p_power * (s[i] - 'a' + 1));
		hash %= mod;
		p_power *= p;
		p_power %= mod;
	}
	
	return hash;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	cout<<"Enter string whose hash-value to be calculated: ";
	string s; cin >> s;
	cout << s <<"\n";
	
	ll string_hash = poly_rolling_hash(s);
	cout << string_hash;

    return 0;
}

// Sample i/p: abababab
// Sample o/p: Enter string whose hash-value to be calculated: abababab
//             970973947