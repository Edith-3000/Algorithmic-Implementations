// Prob: https://leetcode.com/problems/k-th-symbol-in-grammar/
// Ref: https://www.youtube.com/watch?v=5P84A0YCo_Y&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=10
/**************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

long long pow(long long a, long long b) {
    if(b == 0) return 1;
    long long res = 1;

    while(b) {
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }

    return res;
}

int kth_grammar(int n, int k) {
	// base condition
	if(n == 1 and k == 1) return 0;
	
	// hypothesis and induction
	int len = pow(2, n - 1);
	int mid = len / 2;
	
	if(k <= mid) return kth_grammar(n - 1, k);
	else return !kth_grammar(n - 1, k - mid);
}

void solve()
{
  	int n, k; cin >> n >> k;
  	
  	cout << kth_grammar(n, k) << "\n";
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