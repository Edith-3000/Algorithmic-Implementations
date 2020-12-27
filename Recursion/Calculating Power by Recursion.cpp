// Problem ---> Compute a^b

#include<bits/stdc++.h>
using namespace std;

// We know a^b = a * a^(b - 1)
int power(int a, int b) {
	// base case
	if(b == 0) return 1;
	return a * power(a, b - 1);
}

// We know a^b = (a^(b/2))^2, when b is even
//               a * (a^(b/2))^2, when b is odd
int fast_power(int a, int b) {
	// base case
	if(b == 0) return 1;
	
	int tmp = fast_power(a, b/2);
	tmp *= tmp;
	
	if(b & 1) return a * tmp;
	return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int a, b; cin >> a >> b;
    cout << "Ans by O(b) approach: " << power(a, b) << "\n";
    cout << "Ans by O(log2(b)) approach: " << fast_power(a, b) << "\n";

    return 0;
}

/* Sample i/p --->
   
   5 4
   
   Sample o/p --->

   Ans by O(b) approach: 625
   Ans by O(log2(b)) approach: 625

*/

// Time complexity: power() ==> O(b)
//                  fast_power() ==> O(log2(b))