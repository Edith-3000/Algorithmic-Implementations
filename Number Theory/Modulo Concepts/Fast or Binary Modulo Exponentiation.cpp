// RECURSIVE IMPLEMENTATION

/* CONCEPT: aᵇ = a * (a^(b/2))², when b is odd
		    aᵇ = (a^(b/2))², when b is even
*/   

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;

ll mod_exp(ll a, ll b) {
	// base case(s)
	if(b == 0LL) return 1LL;
	if(a == 0LL) return 0LL;
	
	ll res = mod_exp(a, b / 2) % mod;
	res = (res * res) % mod;
	
	if(b & 1) res = (res * a) % mod;
	return res;
}

void solve()
{
  	ll a, b; cin >> a >> b;
  	cout << mod_exp(a, b) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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

// Time complexity: O(log₂b), where b is the exponent in aᵇ 

/*******************************************************************************************************/

// ITERATIVE IMPLEMENTATION USING BITMASKS
// 𝑹𝒆𝒎𝒆𝒎𝒃𝒆𝒓, 𝒈𝒆𝒏𝒆𝒓𝒂𝒍𝒍𝒚 𝒊𝒕𝒆𝒓𝒂𝒕𝒊𝒗𝒆 𝒊𝒎𝒑𝒍𝒆𝒎𝒆𝒏𝒕𝒂𝒕𝒊𝒐𝒏𝒔 𝒂𝒓𝒆 "𝑭𝑨𝑺𝑻𝑬𝑹" 𝒕𝒉𝒂𝒏 𝒓𝒆𝒄𝒖𝒓𝒔𝒊𝒗𝒆 𝒊𝒎𝒑𝒍𝒆𝒎𝒆𝒏𝒕𝒂𝒕𝒊𝒐𝒏𝒔.

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;

ll mod_exp(ll a, ll b) {
	a %= mod; // update a if a >= p
	if(a == 0LL) return 0LL; // in case a is divisible by p

    ll res = 1LL; // initialize result
    
    while(b > 0) {
    	if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
       	b >>= 1;  
    }

	return res;
}

void solve()
{
  	ll a, b; cin >> a >> b;
  	cout << mod_exp(a, b) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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

// Time complexity: O(log₂b), ∵ there can be at most (log₂b) bits in the binary representation of b,
//                              where b is the exponent in aᵇ 
