// Ques. based on the concept: https://www.codechef.com/COOK127B/problems/MATXOR
/*****************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Function to compute XOR of all nos. in the range [1...n]
ll xor_from_1_to_n(ll n) {
	if(n == 0) return 0LL;
	
	// Modulus operator are expensive on most of the  
    // computers. So, (n & 3) will be equivalent to (n % 4).    
    switch(n & 3) {  
        case 0: return n;      // if n is multiple of 4 
        case 1: return 1;      // if n % 4 gives remainder 1   
        case 2: return n + 1;  // if n % 4 gives remainder 2     
        case 3: return 0;      // if n % 4 gives remainder 3   
    } 

    return EXIT_SUCCESS; // it's just to avoid warning
}

ll xor_from_l_to_r(ll l, ll r) {
    // since xor(1 to l-1) ^ xor(1 to r) = xor(l to r)
	return xor_from_1_to_n(l-1) ^ xor_from_1_to_n(r);
}

void solve()
{
  	ll l, r; cin >> l >> r;
  	cout << xor_from_l_to_r(l, r) << "\n";
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