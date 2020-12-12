// PROBLEM LINK: https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/

// RECURSIVE METHOD

#include<bits/stdc++.h>
using namespace std;

int recursive(int i, int j, vector<int> &v){
	// base cases
	if(i > j) return 0;
	if(i == j) return v[i];
	if(j == i+1) return max(v[i], v[j]);
	
	return max(v[i] + min(recursive(i+2, j, v), recursive(i+1, j-1, v)),
	           v[j] + min(recursive(i+1, j-1, v), recursive(i, j-2, v)));
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    vector<int> v{20, 30, 2, 2, 2, 10};
    int n = v.size();
    
    cout << recursive(0, n-1, v);

    return 0;
}

/*************************************************************************************************************/

// TOP DOWN METHOD

#include<bits/stdc++.h>
using namespace std;

int top_down(int i, int j, vector<int> &v, vector<vector<int>> &dp){
	// base cases
	if(i > j) return 0;
	if(i == j) return v[i];
	if(j == i+1) return max(v[i], v[j]);
	
	if(dp[i][j] != -1) return dp[i][j];
	
	return dp[i][j] = max(v[i] + min(top_down(i+2, j, v, dp), top_down(i+1, j-1, v, dp)),
	           		      v[j] + min(top_down(i+1, j-1, v, dp), top_down(i, j-2, v, dp)));
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    vector<int> v{20, 30, 2, 2, 2, 10};
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    
    cout << top_down(0, n-1, v, dp);

    return 0;
}

/********************************************************************************************************/

// BOTTOM UP METHOD

#include<bits/stdc++.h>
using namespace std;

int bottom_up(vector<int> &v){
	int n = v.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	
	for(int i = 0; i < n; i++){
		dp[i][i] = v[i];
		if(i < n-1) dp[i][i+1] = max(v[i], v[i+1]);
	}
	
	for(int i = 2; i < n; i++){
		int r = 0, c = i;
		while(c < n){
			dp[r][c] = max(v[r] + min(dp[r+2][c], dp[r+1][c-1]),
			               v[c] + min(dp[r+1][c-1], dp[r][c-2]));
			               
			r++; c++;
		}
	}
	
	return dp[0][n-1];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    vector<int> v{8, 15, 3, 7};
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    
    cout << bottom_up(v);

    return 0;
}