#include<bits/stdc++.h>
using namespace std;

int method_1(int n, int k) {
	// base cases
	if(n < 0) return 0;
	if(n == 0) return 1;
	
	int res = 0;
	for(int i = 1; i <= k; i++) {
		res += method_1(n - i, k);
	}
	
	return res;
}

int method_2(int n, int k) {
	// base case
	if(n == 0) return 1;
	
	int res = 0;
	for(int i = 1; i <= k; i++) {
		if((n - i) >= 0) res += method_2(n - i, k);
	}
	
	return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n, k; cin >> n >> k;
    cout << "Ans. by Method 1: " << method_1(n, k);
    cout << "\nAns. by Method 2: " << method_2(n, k);

    return 0;
}

/* Sample i/p ---> 8 3
   Sample o/p ---> Ans. by Method 1: 81
				   Ans. by Method 2: 81
*/

// Note: Ofcourse the solution can be optimized using DP, but here the main idea was to solve 
//       using recursion only.