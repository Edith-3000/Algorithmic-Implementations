// BOTTOM UP APPROACH

#include<bits/stdc++.h>
using namespace std;

int mcm_bottom_up(vector<int> &v){
	int n = v.size() - 1; // if x dimensions are given then
	                      // there will be x-1 matrices
	                      
	vector<vector<int>> dp(n, vector<int>(n, 0));
	
	for(int i = 1; i < n; i++){
		int r = 0, c = i;
		
		while(c < n){
			int tmp = INT_MAX;
			for(int pivot = r; pivot < c; pivot++){
				tmp = min(tmp, dp[r][pivot] + dp[pivot+1][c] + v[r]*v[pivot+1]*v[c+1]);
			}
			
			dp[r][c] = tmp;
			r++; c++;
		}
	}
	
	return dp[0][n-1];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter matrix dimensions to be multiplied,\nto multiply n matrices enter n+1 dimensions: ";
    vector<int> v;
    int x;
    while(cin >> x) v.push_back(x);
    for(auto x: v) cout << x << " ";
    
    cout << "\n\nMinimum cost to multiply matrices = ";
    cout << mcm_bottom_up(v);
    
    return 0;
}

// Time complexity: O(n^3)
// Space complexity: O(n^2)