#include<bits/stdc++.h>
using namespace std;

int solve(int *w, int p[], int n, int c) {
	// base cases
	if(n == 0 || c == 0) return 0;
	
	int include, exclude;
	include = exclude = INT_MIN;
	
	if(c - w[n - 1] >= 0) {
		include = p[n - 1] + solve(w, p, n - 1, c - w[n - 1]);
	}
	
	exclude = solve(w, p, n - 1, c);
	
	return max(include, exclude);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int w[] = {1, 2, 3, 5}; // weight array
    int p[] = {40, 20, 30, 100}; // profit array
    int c = 7; // max capacity of the knapsack
    int n = sizeof(w)/sizeof(int);
    
    cout << solve(w, p, n, c);

    return 0;
}

// Sample o/p ---> 140

// Note: Ofcourse the solution can be optimized using DP, but here the main idea was to solve 
//       using recursion only.