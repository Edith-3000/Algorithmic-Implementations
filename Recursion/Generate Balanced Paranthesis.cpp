// The concept used is exactly same as used in "Generate Balanced Paranthesis.txt", only the way of 
// implementation has changed

#include<bits/stdc++.h>
using namespace std;

void solve(char *out, int n, int ind, int open, int close) {
	// base case
	if(ind == 2 * n) {
		out[ind] = '\0';
		cout << out << "\n";
		return;
	}
	
	// we have 2 choices available for each index ind
	// Choice 1
	if(open < n) {
		out[ind] = '(';
		solve(out, n, ind + 1, open + 1, close);
	}
	
	// Choice 2
	if(close < open) {
		out[ind] = ')';
		solve(out, n, ind + 1, open, close + 1);
	}
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n; cin >> n;
    char out[2000];
    solve(out, n, 0, 0, 0);

    return 0;
}

/* Sample i/p ---> 3
   Sample o/p ---> ((()))
                   (()())
                   (())()
                   ()(())
                   ()()()
*/