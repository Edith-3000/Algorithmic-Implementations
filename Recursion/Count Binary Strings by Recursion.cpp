// Problem description ---> Count the number of unique binary strings of length N having no consecutive ones.

#include<bits/stdc++.h>
using namespace std;

int solve(int n) {
	// base case
	if(n == 0) return 1;
	if(n == 1) return 2;
	
	return solve(n - 1) + solve(n - 2);
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

// Sample i/p ---> 10
// Sample o/p ---> 144

// Note: Ofcourse the solution can be optimized using DP, but here the main idea was to solve 
//       using recursion only. 