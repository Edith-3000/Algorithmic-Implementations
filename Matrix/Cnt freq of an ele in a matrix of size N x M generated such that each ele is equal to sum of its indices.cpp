// Ques. based on this: https://www.codechef.com/COOK127B/problems/MATXOR
// Ref: https://www.youtube.com/watch?v=E0y2SOZNXjI&list=PLQXZIFwMtjoyG62-RUlcpyYR18mIlL-c-&index=4
/******************************************************************************************************/

/* Suppose n = 4, m = 5. Then according to the requirement the matrix would look like as follows --->
   
   2 3 4 5 6
   3 4 5 6 7
   4 5 6 7 8
   5 6 7 8 9

   Therefore 2 occurs 1 time, 3 occurs 2 times, 4 occurs 3 times and so on.
*/

#include<bits/stdc++.h>
using namespace std;

void calc(int n, int m) {
    for(int i = 1; i <= n; i++) {
        int cnt = min(i, m);
        cout << (i + 1) << " occurs: " << cnt << " times\n";
    }
    
    for(int j = 2; j <= m; j++) {
        int cnt = min(n, m - j + 1);
        cout << (n + j) << " occurs: " << cnt << " times\n";
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    calc(n, m);
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
    // int test = 1;
    // cin >> t;
    while(t--) {
      // cout << "Case #" << test++ << ": ";
      solve();
    }

    return 0;
}