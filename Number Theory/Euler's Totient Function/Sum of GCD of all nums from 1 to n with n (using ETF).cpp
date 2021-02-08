/* Problem statement --->
   Given Q queries and each query a number n is given.
   For each query you have to evaluate sum of GCD of all the numbers from 1 till n with n.
*/

/***********************************************************************************************************/

// Naive approach 

ll res = 0;
for(ll i = 1; i <= n; i++) {
	res += GCD(i, n);
}

// Time complexity: for each query = O(n x log(n))
//                  for Q queries = O(Q x n x log(n))

/***********************************************************************************************************/

// Better approach

/* Few observations:
   1. GCD(i, n) = one of the divisors of n.
   2. Therefore for each divisor d of n we can find out the count of numbers from 1 to n, such that
      GCD(i, n) = d.
	  
	  Now, how to efficiently calculate the count of numbers from 1 to n, having GCD = d with n
	  See these observations: -
	  if GCD(i, n) = d, then GCD(i/d, n/d) = 1, therefore
	  #numbers with GCD = d with n = #numbers which are coprime with n/d
	                               = phi(n/d)

	  for proof visit: ==>
	  https://www.youtube.com/watch?v=khCze6j1vXg&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=29
	  https://www.geeksforgeeks.org/sum-of-gcd-of-all-numbers-upto-n-with-n-itself/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef vector<ll> vll;

const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const ll N = 1e6;

vll phi(N + 1);
ll n;

void ETF() {
	// initialising result phi(i) for each number i
	for(ll i = 1; i <= N; i++) phi[i] = i;
	
	for(ll i = 2; i <= N; i++) {
		if(phi[i] == i) {
			for(ll j = i; j <= N; j += i) {
				phi[j] /= i;
				phi[j] *= (i - 1);
			}
		}
	}
}

// function to return the count of numbers in the range [1, n]
// s.t. gcd(number, n) = d, where d is a divisor of n
ll get_count(ll d, ll n) {
	// result is just phi[n/d]
	return phi[n/d];
}

void solve()
{
  	cin >> n;
  	
  	ll res = 0;
  	for(ll i = 1; (i * i) <= n; i++) {
  		if(n % i == 0) {
  			ll d1 = i, d2 = n/i;
  			res += d1 * get_count(d1, n);
  			if(d1 != d2) res += d2 * get_count(d2, n);
  		}
  	}
  	
  	cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
	
	  ETF();
    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

// Time complexity: Preprocessing to calculate the phi[] array takes O(n x log(log(n)))
//                  and for each n main algorithm works in O(sqrt(n))
//                  For Q queries it takes O(Q x sqrt(n)).