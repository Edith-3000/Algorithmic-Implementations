// Prob: https://www.geeksforgeeks.org/print-n-bit-binary-numbers-1s-0s-prefixes/
// Ref: https://www.youtube.com/watch?v=U81n0UYtk98&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=19
/*************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector<string> vs;

void find_ans(string op, int ones, int zeros, int n, vs &res) {
	// base case
	if((ones + zeros) == n) {
		res.pb(op);
		return;
	}
	
	// choice for including 1 in the o/p is always available
	string op1 = op + "1";
	find_ans(op1, ones + 1, zeros, n, res);
	
	// choice for including 0 in the o/p is only available when #1's > #0's
	if(zeros < ones) {
		string op2 = op + "0";
		find_ans(op2, ones, zeros + 1, n, res);
	}
}

void solve()
{
  	int n; cin >> n;
  	
  	int ones = 0, zeros = 0;
  	string op = "";
  	vs res;
  	
  	find_ans(op, ones, zeros, n, res);
  	
  	for(auto x: res) {
  		cout << x << "\n";
  	}
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

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