// Problem: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
// Ref: https://www.youtube.com/watch?v=Shuy_KYFQI4
/*******************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int minTaps(int n, vector<int>& ranges) {
    vector<pair<int, int>> v;
        
    for(int i = 0; i < ranges.size(); i++) {
        v.push_back({max(0, i - ranges[i]), i + ranges[i]});
    }
        
    sort(v.begin(), v.end());
        
    int start = 0, end = 0, i = 0;
    int res = 0;
        
    while(true) {
        res += 1;
            
        int new_end = end;
        while(i < v.size() and v[i].first >= start and v[i].first <= end) {
            new_end = max(new_end, v[i].second);
            i++;
        }
            
        if(new_end >= n) return res;
        if(new_end == end) return -1;
            
        end = new_end;
    }
}

void solve()
{
	int n; cin >> n;
  	vector<int> v(n + 1);
  	for(int i = 0; i <= n; i++) cin >> v[i];
  	
  	cout << minTaps(n, v) << "\n";
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