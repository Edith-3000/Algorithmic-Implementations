/* Problem --->
   Find the count of numbers between L and R (both inclusive) which have a sum of digits = X.
   Constraints --->
   L = 0, L <= R <= 10^200
   1 <= X <= 200
*/

#include<bits/stdc++.h>
using namespace std;

int recursive(string &num, int n, int x, bool tight) {
	// base case(s)
	if(n == 0) {
		return (x == 0) ? 1 : 0;
	}
	
	int ub = tight ? num[num.length() - n] : 9;
	int res = 0;
	for(int digit = 0; digit <= ub; digit++) {
		res += recursive(num, n - 1, x - digit, tight & (digit == ub));
	}
	
	return res;
}

void solve()
{
  	string num; cin >> num;
  	int x; cin >> x;
  	
  	cout << recursive(num, num.length(), x, 1);
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