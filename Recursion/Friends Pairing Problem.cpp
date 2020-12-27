/* Problem description ---> Given N friends who want to go to a party on bikes. Each person can go single or
                            as a couple. Find the number of ways in which the friends can go to the party.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
	// base cases
	if(n == 0 || n == 1) return 1;
	return solve(n - 1) + (n - 1) * solve(n - 2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n; cin >> n;
    cout << solve(n);

    return 0;
}

// Sample i/p ---> 7
// Sample o/p ---> 232

// Note: Ofcourse the solution can be optimized using DP, but here the main idea was to solve 
//       using recursion only.