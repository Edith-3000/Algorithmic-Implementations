// Problem: https://leetcode.com/problems/jump-game/
// Ref: https://www.youtube.com/watch?v=A-Mc_0WsoaM

/*****************************************************************************************************/

// METHOD - 1 (BACKWARD ITERATION)
// https://towardsdatascience.com/tackling-jump-game-problems-leetcode-e0a718e7dfba

#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &v) {
	int n = v.size();
    int last_reach = n - 1;
        
    for(int i = n - 2; i >= 0; i--) {
        if((i + v[i]) >= last_reach) last_reach = i;
    }
        
    return last_reach == 0;
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

/*****************************************************************************************************/

// METHOD - 2 (FORWARD ITERATION)
// https://towardsdatascience.com/tackling-jump-game-problems-leetcode-e0a718e7dfba

#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int> &v) {
	int n = v.size();
    int max_reach = 0;
    int i = 0;
    
    while(i < n and i <= max_reach) {
    	max_reach = max(max_reach, i + v[i]);
    	i++;
    }
        
    return max_reach >= (n - 1);
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