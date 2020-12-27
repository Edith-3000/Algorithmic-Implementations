/* Problem description --->

Given a wall of dimensions (4 x N) [4 is breadth & N is length] & tiles of size (1 x 4) & (4 x 1).
In how many ways can the wall be build ?
Note: for dimensions (i x j), i = breadth & j = length.

*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
	// base case 
	// there is only 1 way to build the wall if n <= 3
	if(n <= 3) return 1;
	
	// recursive case
	return solve(n - 1) + solve(n - 4);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n; cin >> n; // n is the length of wall to be build
    cout << solve(n);

    return 0;
}

// Sample i/p ---> 15
// Sample o/p ---> 69

// Note: Ofcourse the solution can be optimized using DP, but here the main idea was to solve 
//       using recursion only.