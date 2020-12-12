/* PROBLEM STATEMENT ------> 
In a village fair kids play a very interesting game called Rock, Paper and Scissor. Each kid chooses a role for 
himself where he can play the role of a rock, a paper or a scissor.
You have R number of rocks, S number of Scissors and T number of papers.
Rock kills Scissor, Scissor kills Paper and Paper kills Rock.
You have to tell the respective probabilities of Rock being the only survivor in the game, Scissor being the only 
survivor in the game and Paper being the only survivor in the game.
 
Input Format:
The first line consists of number of test cases T. Each test case consists of three integers R, S and P. 
 
Constraints: 1 <= T <= 10
             1 <= R, S, P <= 100
 
Output Format:
Output the respective probabilities in a newline for each test case.
 
NOTE: You have to output exactly 9 places after the decimal point in your answer.
 
Sample Input:
3
2 2 2
2 1 2
1 1 3
 
Sample Output:
0.333333333 0.333333333 0.333333333 
0.150000000 0.300000000 0.550000000
0.057142857 0.657142857 0.285714286

Time Limit: 5 sec.
*/

// TOP DOWN DP METHOD

#include<bits/stdc++.h>
using namespace std;

void init_dp_matrix(vector<vector<vector<double>>> &dp, int r, int s, int p){
	for(int i = 0; i <= r; i++){
		for(int j = 0; j <= s; j++){
			for(int k = 0; k <= p; k++){
				dp[i][j][k] = -1.0;
			}
		}
	}
}

double rock(vector<vector<vector<double>>> &dp, int r, int s, int p){
	// base cases
	if(r == 0 || (s == 0 && p != 0)) return 0.0;
	if(p == 0) return 1.0;
	
	// if already calculated return result
	if(dp[r][s][p] != -1.0) return dp[r][s][p];
	
	// total number of possible fights
	double tot = r*s + s*p + p*r;
	// tp store the result of state(r, p, s)
	double res = 0.0;
	
	res += rock(dp, r, s-1, p) * ((r*s)/tot); // if fight b/w rock & scissor
	res += rock(dp, r, s, p-1) * ((s*p)/tot); // if fight b/w scissor & paper
	res += rock(dp, r-1, s, p) * ((p*r)/tot); // if fight b/w paper & rock
	
	// return final result
	return dp[r][s][p] = res;
}

double scissor(vector<vector<vector<double>>> &dp, int r, int s, int p){
	// base cases
	if(s == 0 || (p == 0 && r != 0)) return 0.0;
	if(r == 0) return 1.0;
	
	// if already calculated return result
	if(dp[r][s][p] != -1.0) return dp[r][s][p];
	
	// total number of possible fights
	double tot = r*s + s*p + p*r;
	// tp store the result of state(r, p, s)
	double res = 0.0;
	
	res += scissor(dp, r, s-1, p) * ((r*s)/tot); // if fight b/w rock & scissor
	res += scissor(dp, r, s, p-1) * ((s*p)/tot); // if fight b/w scissor & paper
	res += scissor(dp, r-1, s, p) * ((p*r)/tot); // if fight b/w paper & rock
	
	// return final result
	return dp[r][s][p] = res;
}

double paper(vector<vector<vector<double>>> &dp, int r, int s, int p){
	// base cases
	if(p == 0 || (r == 0 && s != 0)) return 0.0;
	if(s == 0) return 1.0;
	
	// if already calculated return result
	if(dp[r][s][p] != -1.0) return dp[r][s][p];
	
	// total number of possible fights
	double tot = r*s + s*p + p*r;
	// tp store the result of state(r, p, s)
	double res = 0.0;
	
	res += paper(dp, r, s-1, p) * ((r*s)/tot); // if fight b/w rock & scissor
	res += paper(dp, r, s, p-1) * ((s*p)/tot); // if fight b/w scissor & paper
	res += paper(dp, r-1, s, p) * ((p*r)/tot); // if fight b/w paper & rock
	
	// return final result
	return dp[r][s][p] = res;
}

void solve(){
	int r, s, p;
	cin >> r >> s >> p;
	
	vector<vector<vector<double>>> dp(r+1, vector<vector<double>>(s+1, vector<double>(p+1)));
	init_dp_matrix(dp, r, s, p);
	double r_res = rock(dp, r, s, p);
	
	init_dp_matrix(dp, r, s, p);
	double s_res = scissor(dp, r, s, p);
	
	init_dp_matrix(dp, r, s, p);
	double p_res = paper(dp, r, s, p);
	
	cout << fixed << setprecision(9) << r_res << " " << s_res << " " << p_res << "\n";	
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }

    return 0;
}

// Time complexity: O(r*s*p)
// Space complexity: O(r*s*p)