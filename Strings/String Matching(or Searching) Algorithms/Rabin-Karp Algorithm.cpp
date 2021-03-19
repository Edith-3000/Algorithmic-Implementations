// PROBLEM STATEMENT: Problem: Given two strings - a pattern and a text, determine if the pattern appears 
//                             in the text and if it does, enumerate all its occurrences in O(|n|+|m|) time.
//                             n = text length, m = pattern length.

/**************************************************************************************************************/

/*
   # 𝑹𝒂𝒃𝒊𝒏-𝑲𝒂𝒓𝒑 𝒊𝒔 𝒆𝒂𝒔𝒊𝒆𝒓 𝒕𝒐 𝒊𝒎𝒑𝒍𝒆𝒎𝒆𝒏𝒕 𝒊𝒇 𝒘𝒆 𝒂𝒔𝒔𝒖𝒎𝒆 𝒕𝒉𝒂𝒕 𝒂 𝒄𝒐𝒍𝒍𝒊𝒔𝒊𝒐𝒏 𝒘𝒊𝒍𝒍 𝒏𝒆𝒗𝒆𝒓 𝒉𝒂𝒑𝒑𝒆𝒏, 𝒃𝒖𝒕 𝒊𝒇 𝒕𝒉𝒆 𝒑𝒓𝒐𝒃𝒍𝒆𝒎 
     𝒚𝒐𝒖 𝒉𝒂𝒗𝒆 𝒊𝒔 𝒂 𝒕𝒚𝒑𝒊𝒄𝒂𝒍 𝒔𝒕𝒓𝒊𝒏𝒈 𝒔𝒆𝒂𝒓𝒄𝒉𝒊𝒏𝒈 𝒕𝒉𝒆𝒏 𝑲𝑴𝑷 𝒘𝒊𝒍𝒍 𝒃𝒆 𝒎𝒐𝒓𝒆 𝒔𝒕𝒂𝒃𝒍𝒆 𝒏𝒐 𝒎𝒂𝒕𝒕𝒆𝒓 𝒘𝒉𝒂𝒕 𝒊𝒏𝒑𝒖𝒕 𝒚𝒐𝒖 𝒉𝒂𝒗𝒆. 
     𝑯𝒐𝒘𝒆𝒗𝒆𝒓, 𝑹𝒂𝒃𝒊𝒏-𝑲𝒂𝒓𝒑 𝒉𝒂𝒔 𝒎𝒂𝒏𝒚 𝒐𝒕𝒉𝒆𝒓 𝒂𝒑𝒑𝒍𝒊𝒄𝒂𝒕𝒊𝒐𝒏𝒔, 𝒘𝒉𝒆𝒓𝒆 𝑲𝑴𝑷 𝒊𝒔 𝒏𝒐𝒕 𝒂𝒏 𝒐𝒑𝒕𝒊𝒐𝒏.
   # Reference: https://stackoverflow.com/questions/23336807/when-to-use-rabin-karp-or-kmp-algorithms#:~:text=
                Rabin%2DKarp%20is%20easier%20to,KMP%20is%20not%20an%20option.
*/

// METHOD 1

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll p = 31;
const ll mod = 1e9 + 7;

ll poly_rolling_hash(string s)
{
    // to store the hash value of string
    ll hash = 0;
    
    // since p^0 = 1
    ll p_power = 1;
    
    for(ll i = 0; i < s.length(); i++){
        hash += (p_power * (s[i] - 'a' + 1));
        hash %= mod;
        p_power *= p;
        p_power %= mod;
    }
    
    return hash;
}

// fast exponentiation under modulo mod
ll fast_exponent(ll a, ll b)
{
    a %= mod;
    if(a == 0) return 0;
    
    ll res = 1;
    while(b > 0){
        if(b & 1ll) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    
    return res;
}

// to calculate modulo multiplicative inverse of p under mudulo mod
// fermat's little theorem is used
ll mod_mul_inv(ll p){
    return fast_exponent(p, mod-2);
}

void rabin_karp(string text, string pat)
{
    ll n = text.length();
    ll m = pat.length();
    
    ll text_hash = poly_rolling_hash(text.substr(0, m));
    ll pat_hash = poly_rolling_hash(pat);
    
    if(text_hash == pat_hash){
        cout << "Pattern starting from index: "  << 0 << "\n";
    }
    
    // precompute the mod_mul_inv of p under modulo mod
    ll x = mod_mul_inv(p);
    
    // now try to find the string in the subsequent windows of size m
    for(ll i = 1; i <= (n - m); i++){
        ll curr_hash = text_hash;
        
        // Step 1: remove the contribution of the first character 
        // from the hash value of previous window
        curr_hash = (curr_hash - (text[i-1] - 'a' + 1) + mod) % mod;
        
        // Step 2: divide the hash value by p
        // as division is under modulo mod, therefore we can calculate
        // mod_mul_inv of p under modulo mod
        curr_hash *= x;
        curr_hash %= mod;
        
        // Step 3: inculcate the contribution of the last character of the
        // current window 
        curr_hash += (fast_exponent(p, m-1) * (text[i + m - 1] -'a' + 1));
        curr_hash %= mod;
        
        // compare if hashes of text and pattern comes out to be same
        if(curr_hash == pat_hash){
            cout << "Pattern starting from index: "  << i << "\n";
        }
        
        // update for next iteration
        text_hash = curr_hash;
    }
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
        return;
    }

    rabin_karp(text, pat);
    
    return 0;
}

// Time complexity: O(n + m)
// Reference: https://cp-algorithms.com/string/rabin-karp.html

/*

Sample i/p:

aabsgksaabsghaabs
aabs

Sample o/p:

Enter the text(haystack): aabsgksaabsghaabs
Enter the pattern to be searched(needle): aabs
Pattern starting from index: 0
Pattern starting from index: 7
Pattern starting from index: 13

*/

/************************************************************************************************************/

// METHOD 2 (Using Prefix Sum)

// It's in another file