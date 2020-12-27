#include<bits/stdc++.h>
using namespace std;

int method_1(int *a, int n, int key) {
	// base cases
	if(n == 0) return -1;
	if(a[0] == key) return 0;
	
	int i = method_1(a + 1, n - 1, key);
	if(i == -1) return -1;
	return i + 1;
}

// This method seems more intuitive, as it's almost
// similar to the for loop which we generally use in linear search
int method_2(int *a, int n, int key, int i) {
	// base cases
	if(i == n) return -1;
	if(a[i] == key) return i;
	
	return method_2(a, n, key, i + 1);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int a[] = {4, 8, 9, -1, 16, 0, 5, 8};
    int n = sizeof(a)/sizeof(int);
    int key = 5;
    
    cout << method_1(a, n, key) << "\n";
    
    int i = 0;
    cout << method_2(a, n, key, i);

    return 0;
}

// Sample o/p ---> 6
//                 6

// Time complexity: O(n), as in the worst case we traverse the whole i/p array of size n.