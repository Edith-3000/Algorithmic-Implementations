// Problem: https://leetcode.com/problems/jump-game-ii/
// Ref: https://www.youtube.com/watch?v=A-Mc_0WsoaM

/*****************************************************************************************************/

// METHOD - 1 O(n^2)
// https://towardsdatascience.com/tackling-jump-game-problems-leetcode-e0a718e7dfba

#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

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
        
    vector<int> dp(n, INF);
    dp[0] = 0;
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(j + v[j] >= i) dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    
    return dp[n-1];
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

/*****************************************************************************************************/

// METHOD - 2 O(n)
// https://towardsdatascience.com/tackling-jump-game-problems-leetcode-e0a718e7dfba

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
        
    int max_reach = v[0], steps = v[0];
    int res = 1;
    
    for(int i = 1; i < (n - 1); i++) {
        max_reach = max(max_reach, i + v[i]);
        steps--;
        if(steps == 0) {
            res++;
            steps = max_reach - i;
        }
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