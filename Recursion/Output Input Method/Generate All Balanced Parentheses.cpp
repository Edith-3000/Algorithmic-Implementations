// Prob: https://leetcode.com/problems/generate-parentheses/
// Ref: https://www.youtube.com/watch?v=eyCj_u3PoJE&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=17
/**************************************************************************************************************/

// METHOD - 1

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef vector<string> vs;

void generate_parentheses(string op, int n, int open, int close, vs &res) {
	// base case
	if(open == n and close == n) {
		res.pb(op);
		return;
	}
	
	if(open < n) {
		string op1 = op + "(";
		generate_parentheses(op1, n, open + 1, close, res);
	}
	
	if(close < open) {
		string op2 = op + ")";
		generate_parentheses(op2, n, open, close + 1, res);
	}
}

void solve()
{
  	int n; cin >> n;
  	
  	int open = 0, close = 0;
  	string op = "";
  	vs res;
  	
  	generate_parentheses(op, n, open, close, res);
  	
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

/**************************************************************************************************************/

// METHOD - 2

// The concept used is exactly same as used in METHOD - 2, only the way of implementation has changed

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