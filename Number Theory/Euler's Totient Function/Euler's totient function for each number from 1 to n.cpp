// Problem statement --->
// Find efficient way to find phi(n) for all the numbers from 1 to n.
// Constraints: 1 <= n <= 10^6

/*********************************************************************************************************/

// Reference(s): https://www.geeksforgeeks.org/eulers-totient-function/
/*********************************************************************************************************/

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

void solve()
{
  	cin >> n;
  	cout << "ETF for " << n << ": " << phi[n] << "\n";
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

// Time complexity of the ETF() function = O(n x log(log(n)))
// Time complexity for exch query = O(1)

// Results are well tested and validated from the website: https://primefan.tripod.com/Phi500.html