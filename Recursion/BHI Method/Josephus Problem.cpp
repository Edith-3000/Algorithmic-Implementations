// Prob: https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle1840/1#
//       https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
/*********************************************************************************************************/

// METHOD - 1
// Ref: https://www.youtube.com/watch?v=ULUNeD0N9yI&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=19

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define sz(x) ((int)(x).size())

int helper(int k, vi &v, int idx) {
	// base case
	if(sz(v) == 1) {
		return v[0];
	}
	
	idx = (idx + k) % sz(v);
	v.erase(v.begin() + idx);
	
	return helper(k, v, idx);
}

// NOTE: it returns 1-based index of the safe position
int josephus_problem(int n, int k) {
	vi v(n);
	for(int i = 0; i < n; i++) v[i] = i + 1;
	
	int start_idx = 0;
	k -= 1;
	
	return helper(k, v, start_idx);
}

void solve()
{
  	int n, k; cin >> n >> k;
  	
  	int res = josephus_problem(n, k);
  	
  	cout << "The safe position is: " << res << "\n";
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

// TC: O(n^2)
// SC: O(n)

/****************************************************************************************************************/

// METHOD - 2
// https://www.youtube.com/watch?v=dzYq5VEMZIg

#include<bits/stdc++.h>
using namespace std;

int helper(int n, int k) {
	// base case
	if(n == 1) {
		return 0;
	}
	
	// hypothesis
	int x = helper(n - 1, k);
	
	// induction
	int res = (x + k) % n;
	
	return res;
}

// NOTE: it returns 1-based index of the safe position
int josephus_problem(int n, int k) {
	// NOTE: the helper return 0-based index, so add 1 to make adjustment
	return helper(n, k) + 1;
}

void solve()
{
  	int n, k; cin >> n >> k;
  	
  	int res = josephus_problem(n, k);
  	
  	cout << "The safe position is: " << res << "\n";
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

// TC: O(n)