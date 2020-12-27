#include<bits/stdc++.h>
using namespace std;

char words[][15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void solve(int n) {
	// base case
	if(n == 0) return;
	
	solve(n/10);
	int digit = n%10;
	cout << words[digit] << " ";
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
    
    if(n == 0) cout << words[0];
    else solve(n);

    return 0;
}

/* Sample i/p ---> 11071999
   Sample o/p ---> one one zero seven one nine nine nine 
*/

// Time complexity: #digits in the i/p number n.