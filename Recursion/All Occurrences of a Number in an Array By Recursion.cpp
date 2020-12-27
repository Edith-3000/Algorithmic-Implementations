#include<bits/stdc++.h>
using namespace std;

// this method will store all the occurrences of the key in the 
// res[] array & will return the final size of res[] array
int method_1(int *a, int n, int key, int i, int j, int *res)  {
	// base case
	if(i == n) return j;
	
	if(a[i] == key) {
		res[j] = i; // store the index
	    j++; // increment j to accomodate next occurrence, if found
	}
	
	return method_1(a, n, key, i + 1, j, res);
}

// This method seems more intuitive, as it's almost
// similar to the for loop which we generally use in linear search
void method_2(int *a, int n, int key, int i) {
	// base cases
	if(i == n) return;
	if(a[i] == key) cout << i << " ";
	
	method_2(a, n, key, i + 1);
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
    
    // the res[] array will basically all the indices of
    // occurrences of the key, variable j is used to traverse
    // the res[] array
    int res[100];
    int cnt = method_1(a, n, key, 0, 0, res);
    for(int i = 0; i < cnt; i++) cout << res[i] << " ";
    
    cout << "\n";
    
    int i = 0;
    method_2(a, n, key, i);

    return 0;
}

// Sample i/p ---> 4 7 8
//                 4 7 8

// Time complexity: O(n), as in each case we traverse the whole i/p array of size n by the help of recursion