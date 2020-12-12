// RECURSIVE APPROACH

#include<bits/stdc++.h>
using namespace std;

int lcs_recursive(string s1, string s2, int i, int j){
	// base case
	if(i == s1.length() || j == s2.length()) return 0;
	
	if(s1[i] == s2[j]){
		return 1 + lcs_recursive(s1, s2, i+1, j+1);
	}
	
	// option 1
	int op1 = lcs_recursive(s1, s2, i+1, j);
	// option 2
	int op2 = lcs_recursive(s1, s2, i, j+1);
	
	return max(op1, op2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    string s1, s2;
    cout << "Enter 2 strings: ";
    cin >> s1 >> s2;
    cout << s1 << " " << s2 << "\n";
    
    cout << "LCS length = " << lcs_recursive(s1, s2, 0, 0);

    return 0;
}

/*****************************************************************************************************/

// TOP DOWN APPROACH

#include<bits/stdc++.h>
using namespace std;

int lcs_top_down(string s1, string s2, int i, int j, vector<vector<int>> &dp){
	// base case
	if(i == s1.length() || j == s2.length()) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	if(s1[i] == s2[j]){
		return dp[i][j] = 1 + lcs_top_down(s1, s2, i+1, j+1, dp);
	}
	
	// option 1
	int op1 = lcs_top_down(s1, s2, i+1, j, dp);
	// option 2
	int op2 = lcs_top_down(s1, s2, i, j+1, dp);
	
	return dp[i][j] = max(op1, op2);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    string s1, s2;
    cout << "Enter 2 strings: ";
    cin >> s1 >> s2;
    cout << s1 << " " << s2 << "\n";
    
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    cout << "LCS length = " << lcs_top_down(s1, s2, 0, 0, dp);

    return 0;
}

/*********************************************************************************************************/