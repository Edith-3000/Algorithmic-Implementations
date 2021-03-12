// Ref: https://www.educative.io/m/merge-overlapping-intervals
//      https://leetcode.com/problems/merge-intervals/
//      https://www.geeksforgeeks.org/merging-intervals/
/***************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
typedef pair<int, int> pii;
typedef vector<pii>	vpii;

vpii merge_intervals(vpii &v, int n) {
	vpii res;
	if(n == 0) return res;
	
	sort(v.begin(), v.end());
	res.pb(v[0]);
	
	for(int i = 1; i < n; i++) {
		int x1 = v[i].F;
		int y1 = v[i].S;
		
		int x2 = res[res.size() - 1].F;
		int y2 = res[res.size() - 1].S;
		
		if(y2 >= x1) res[res.size() - 1].S = max(y2, y1);
		else res.pb({x1, y1});
	}
	
	return res; 
}

void solve()
{
  	int n; cin >> n;
  	vpii v(n);
  	for(int i = 0; i < n; i++) {
  		cin >> v[i].F >> v[i].S;
  	}
  	
  	vpii res = merge_intervals(v, n);
  	
  	cout << res.size() << "\n";
  	for(auto x: res) cout << x.F << " " << x.S << " ";
  	cout << "\n";
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
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}