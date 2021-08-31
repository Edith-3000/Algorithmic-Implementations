// Ref: // Link: https://www.techiedelight.com/bit-hacks-part-3-playing-rightmost-set-bit-number/#P2
/********************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// Function to return the rightmost set bit (0-based indexed) in n
// NOTE: in the code below 0-based indexing of bits from RHS to LHS(i.e. from 
//       LSB to MSB) is considered
ll rightmost_set(ll n) {
    // unset rightmost bit (as well as the bits following it) 
    // and xor with number itself so as to produce a number which
    // has only the right most bit of n in on condition.
    // n = (n & (-n)) would also do the same thing as well
    n = n ^ (n & (n - 1));
    
    // now find the position of the only set bit in the n 
    // (we can directly return log2(n) + 1 using inbuilt function)
    ll pos = -1;
    
    while(n) {
        pos += 1;
        n >>= 1LL;
    }
    
    // if (pos == -1), then no set bit present in n
    return pos;
}

void solve()
{
    ll n; cin >> n;
    
    cout << n << " in binary is " << bitset<64>(n) << "\n";
    cout << "Position of the rightmost set bit is: ";
    cout << rightmost_set(n) << "\n";
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