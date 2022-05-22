// Prob: https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/
// Ref: https://www.youtube.com/watch?v=l45md3RYX7c&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=11
/***************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

void TOH(int n, char src_pole, char aux_pole, char dst_pole) {
	// base condition
	if(n == 0) return;
	
	// hypothesis and induction
	TOH(n - 1, src_pole, dst_pole, aux_pole);
	cout << "Move disk " << n << " from pole " << src_pole << " to pole " << dst_pole << "\n";
	TOH(n - 1, aux_pole, src_pole, dst_pole);
}

void solve()
{
  	int n; cin >> n;
  	
  	TOH(n, 'A', 'B', 'C');
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

// Time complexity analysis: https://www.youtube.com/watch?v=hGoIo7cVw80