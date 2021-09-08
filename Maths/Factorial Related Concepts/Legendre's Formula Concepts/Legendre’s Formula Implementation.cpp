// Prob: Given an integer n and a prime number p, find the largest x such that p^x divides n! 
// Ref: https://www.geeksforgeeks.org/legendres-formula-highest-power-of-prime-number-that-divides-n/
//      http://e-maxx.ru/algo/factorial_divisors
/*********************************************************************************************************/

// METHOD - 1
// NOTE: This method may give overflow errors in some cases, since in legendre_formula() function
//       we continuously multiply x with p, which may get out of range, so better use "METHOD - 2"

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// For any number n and prime number p, this function returns the 
// largest power of p, which divides n!
ll legendre_formula(ll n, ll p) {
	ll res = 0LL, x = p;
	
	// calculating res = n/p + n/(p^2) + n/(p^3) + ....
	while((n / x) > 0) {
		res += (n / x);
		x *= p;
	}
	
	return res;
}

void solve()
{
  	ll n, p; cin >> n >> p;
  	cout << legendre_formula(n, p) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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

// Time complexity: O(log(n) base p)

/********************************************************************************************************/

// METHOD - 2
// Just a slight change in implementation of METHOD - 1.

#include<bits/stdc++.h>
using namespace std;

#define ll long long

// For any number n and prime number p, this function returns the 
// largest power of p, which divides n!
ll legendre_formula(ll n, ll p) {
	// initialising result
	ll res = 0LL;
	
	// calculating res = n/p + n/(p^2) + n/(p^3) + ....
	while(n > 0) {
		n /= p;
		res += n;
	}
	
	return res;
}

void solve()
{
  	ll n, p; cin >> n >> p;
  	cout << legendre_formula(n, p) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
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

// Time complexity: O(log(n) base p)