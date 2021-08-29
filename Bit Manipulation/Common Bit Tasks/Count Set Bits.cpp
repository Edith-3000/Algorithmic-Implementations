// USING THE PREDEFINED FUNCTIONS

/* __builtin_popcount(n) when n is int
   __builtin_popcountl(n) when n is long
   __builtin_popcountll(n) when n is long long
*/

/*******************************************************************************************************/

// USING ITERATIVE IMPLEMENTATION OF "BRIAN KERNIGHAN’S ALGORITHM"

/* Algorithm ===>
   1. Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) 
      including the rightmost set bit.
   2. So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the rightmost 
      set bit. If we do n & (n-1) in a loop and count the no of times loop executes we get the set 
      bit count.
   3. The beauty of this algorithm is the number of times it loops is equal to the number of set bits 
      in a given integer.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Function to count the total #set bits in n
ll cnt_set_bits(ll n) {
	ll res = 0LL;
	
	while(n > 0) {
		res += 1;
		n = (n & (n - 1));
	}
	
	return res;
}

void solve()
{
  	ll n; cin >> n;
  	cout << cnt_set_bits(n) << "\n";
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

// Time Complexity: O(no. of set bits in n)