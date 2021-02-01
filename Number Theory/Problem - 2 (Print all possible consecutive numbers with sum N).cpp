// Source(s): https://www.geeksforgeeks.org/print-all-possible-consecutive-numbers-with-sum-n/
// IN THIS PROBLEM ONLY POSITIVE CONSECUTIVE NUMBERS ARE TO BE CONSIDERED.

/***************************************************************************************************************/

/* Main idea of algorithm: --->
   One important fact is we can not find consecutive numbers above N/2 that adds up to N, 
   because N/2 + (N/2 + 1) would be more than N. So we start from start = 1 till end = N/2 and check for every 
   consecutive sequence whether it adds up to N or not. If it is then we print that sequence and start looking 
   for the next sequence by incrementing start point.
*/

// O(n^2) Approach

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef vector<ll> vll;

ll ceil(ll x, ll y) {
	return (x % y == 0) ? (x/y) : (x/y) + 1;
}

void driver(ll n) {
	if(n == 1) {
		cout << 1 << "\n";
		return;
	}
	
	ll start = 1, end = ceil(n, 2);
	while(start < end) {
		ll sum = 0;
		for(ll i = start; i <= end; i++) {
			sum += i;
			if(sum > n) break;
			if(sum == n) {
				for(int j = start; j <= i; j++) cout << j << " ";
				cout << "\n";
			}
		}
		
		start += 1;
	}
	
	cout << n << "\n";
}

void solve()
{
  	ll n; cin >> n;
  	driver(n);
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

/*********************************************************************************************************/

// O(n) Approach

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef vector<ll> vll;

ll ceil(ll x, ll y) {
	return (x % y == 0) ? (x/y) : (x/y) + 1;
}

void driver(ll n) {
	if(n == 1) {
		cout << 1 << "\n";
		return;
	}
	
	ll start = 1, end = 1, sum = 1;
	while(start <= ceil(n, 2)) {
		if(sum < n) { end += 1; sum += end; }
		else if(sum > n) { sum -= start; start += 1; }
		else {
			for(ll i = start; i <= end; i++) cout << i << " ";
			cout << "\n";
			sum -= start;
			start += 1;
		}
	}
	
	cout << n << "\n";
}

void solve()
{
  	ll n; cin >> n;
  	driver(n);
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}