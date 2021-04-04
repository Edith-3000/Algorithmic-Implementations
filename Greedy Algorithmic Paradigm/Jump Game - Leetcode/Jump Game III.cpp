// Problem: https://leetcode.com/problems/jump-game-iii/
// Ref: https://www.youtube.com/watch?v=A-Mc_0WsoaM

/*****************************************************************************************************/

// NOTE: This approach is not greedy.

#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> &v, vector<bool> &vis, int start, int n) {
    if(start < 0 || start >= n || vis[start]) return false;
    if(v[start] == 0) return true;
        
    vis[start] = true;
    return dfs(v, vis, start + v[start], n) || dfs(v, vis, start - v[start], n);
}
    
bool canReach(vector<int>& v, int start) {
    int n = v.size();
    vector<bool> vis(n, false);
    return dfs(v, vis, start, n);
}

void solve()
{
	int n, start; cin >> n >> start;
  	vector<int> v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	if(canReach(v, start)) cout << "YES\n";
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