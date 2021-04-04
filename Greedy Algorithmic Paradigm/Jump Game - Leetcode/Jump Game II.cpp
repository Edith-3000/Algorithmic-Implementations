// Problem: https://leetcode.com/problems/jump-game-ii/
// Ref: https://www.youtube.com/watch?v=A-Mc_0WsoaM

/*****************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> &v) {
    int n = v.size();
    int last = n - 1;

    for(int i = n - 2; i >= 0; i--) {
        if((i + v[i]) >= last) last = i;
    }

    return last == 0;
}

int jump(vector<int>& v) {
    int n = v.size();
        
    if(!possible(v)) return -1;        
    if(n == 1) return 0;
        
    int max_reach = v[0], cur_reach = v[0], i = 1;
    int res = 1;
        
    while(max_reach < (n - 1)) {
    	if(i + v[i] >= cur_reach) cur_reach = i + v[i];
        if(i == max_reach) max_reach = cur_reach, res += 1;
        i += 1;
    }
        
    return res;
}

void solve()
{
	int n; cin >> n;
  	vector<int> v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << jump(v) << "\n";
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