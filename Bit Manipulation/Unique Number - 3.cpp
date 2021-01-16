/* Problem --->

We are given an array containg n numbers. All the numbers are present thrice except for one number which is 
only present once. Find the unique number.

Input Format
First line contains the number n. Second line contains n space separated number.

Constraints
N < 10^5

Output Format
Output a single line containing the unique number

Sample Input
7
1 1 1 2 2 2 3
Sample Output
3

*/

#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int cnt[64] = {0};
  	int n; cin >> n;
  	for(int i = 0; i < n; i++) {
  		int x; cin >> x;
  		int j = 0;
  		while(x > 0) {
  			cnt[j] += (x & 1);
  			j++;
  			x >>= 1;
  		}
  	}
  	
  	int res = 0, p = 1;
  	for(int i = 0; i < 64; i++) {
  		cnt[i] %= 3;
  		res += (cnt[i] * p);
  		p <<= 1;
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

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}