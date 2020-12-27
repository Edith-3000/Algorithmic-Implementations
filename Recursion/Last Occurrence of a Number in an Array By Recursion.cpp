#include<bits/stdc++.h>
using namespace std;

int last_occur(int *a, int n, int key) {
	// base case (if array is empty)
	if(n == 0) return -1;
	
	// in this method first go to the complete depth
	// of the recursion
	int i = last_occur(a + 1, n - 1, key);
	
	// update answer in the returning phase of the recursion
	if(i == -1) {
		if(a[0] == key) return 0;
		else return -1;
	}
	
	return i + 1;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int a[] = {4, 8, 9, -1, 5, 16, 0, 5, 5, 8};
    int n = sizeof(a)/sizeof(int);
    int key = 5;
    
    cout << last_occur(a, n, key) << "\n";

    return 0;
}

// Sample o/p ---> 8

// Time complexity: O(n), as in each case we traverse the whole i/p array of size n by the help of recursion