// Ref: https://www.geeksforgeeks.org/check-number-palindrome-not-without-using-extra-space/
/******************************************************************************************************/

// METHOD - 1

#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(int n) {
	// not considering -ve numbers as palindromic
	if(n < 0) return 0;
	
	// Finding the appropriate divisor
    // to extract the leading digit
	int divisor = 1;
	while(n / divisor >= 10) {
		divisor *= 10;
	}
	
	while(n > 0) {
		int leading = n / divisor;
		int trailing = n % 10;
		
		// If first and last digit not same return false
		if(leading != trailing) return 0;
		
		// Removing the leading and trailing digits from number
		n = (n % divisor) / 10;
		
		// Reducing divisor by a factor of 2 as 2 digits are dropped
		divisor /= 100;
	}
	
	return 1;
}

void solve()
{
  	int n; cin >> n;
  	
  	if(is_palindrome(n)) cout << "YES\n";
  	else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}

/****************************************************************************************************/

// METHOD - 2 
// Easier than METHOD - 1

#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(int n) {
	// not considering -ve numbers as palindromic
	if(n < 0) return 0;
	
	int tmp = n, x = 0;
	
	while(tmp > 0) {
		int rem = tmp % 10;
		tmp /= 10;
		x = (x * 10) + rem;
	}
	
	return x == n;
}

void solve()
{
  	int n; cin >> n;
  	
  	if(is_palindrome(n)) cout << "YES\n";
  	else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}