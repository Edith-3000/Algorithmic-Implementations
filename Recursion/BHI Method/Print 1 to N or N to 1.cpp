// PRINT NOS. FROM 1 to N

#include<bits/stdc++.h>
using namespace std;

void print_1_to_n(int n) {
	// base condition(s)
	if(n <= 0) return;
	if(n == 1) {
		cout << 1 << " ";
		return;
	}
	
	// hypothesis
	print_1_to_n(n - 1);
	
	// induction
	cout << n << " ";
}

void solve()
{
  	int n; cin >> n;
  	print_1_to_n(n);
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

/*****************************************************************************************************************/

// PRINT NOS. FROM N to 1

#include<bits/stdc++.h>
using namespace std;

void print_n_to_1(int n) {
    // base condition(s)
    if(n <= 0) return;
    if(n == 1) {
        cout << 1 << " ";
        return;
    }
    
    // induction
    cout << n << " ";
    
    // hypothesis
    print_n_to_1(n - 1);
}

void solve()
{
    int n; cin >> n;
    print_n_to_1(n);
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
