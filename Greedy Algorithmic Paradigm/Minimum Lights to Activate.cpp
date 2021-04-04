// Problem: https://www.interviewbit.com/problems/minimum-lights-to-activate/
/*****************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int find_ans(vector<int> &v, int B) {
    if(B == 0) return -1;
    
    int n = v.size();
    int res = 0, i = 0;
    
    while(i < n) {
        int idx = -1;
        
        for(int j = max(0, i - B + 1); j <= min(n - 1, i + B - 1); j++) {
            if(v[j] == 1) idx = j;
        }
        
        if(idx == -1) return -1;
        res += 1;
        i = idx + B;
    }
    
    return res;
}

void solve()
{
	int n, b; cin >> n >> b;
  	vector<int> v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	
  	cout << find_ans(v, b) << "\n";
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