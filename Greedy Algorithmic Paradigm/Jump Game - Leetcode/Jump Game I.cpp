// Problem: https://leetcode.com/problems/jump-game/
// Ref: https://www.youtube.com/watch?v=A-Mc_0WsoaM

/*****************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &v) {
	int n = v.size();
    int last = n - 1;
        
    for(int i = n - 2; i >= 0; i--) {
        if((i + v[i]) >= last) last = i;
    }
        
    return last == 0;
}

void solve()
{
	int n; cin >> n;
  	vector<int> v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	if(canJump(v)) cout << "YES\n";
  	else cout << "NO\n";
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