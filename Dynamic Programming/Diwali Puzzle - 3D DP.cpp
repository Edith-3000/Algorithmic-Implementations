/* PROBLEM STATEMENT ------> 
It's Diwali time and everyone is busy decorating there homes using light bulbs. The light bulbs are arranged 
in a row. Little bob is bored of participating in contests so he decided to write 1 for every bulb which is 
on and 0 for every bulb which is off and creates an array of size equal to number of light bulbs. 
Since he is a bright kid he looks at his array and calculates the sum of all the adjacent pairwise products 
and wonders how many such combinations exist. More formally you are given an array of size n (consisting of 
0 and 1 only) and k = a1a2 + a2a3 + a3a4 + … an-1an. You have to find out how many combinations of these light 
bulbs of size n (on and off) will give the sum of products equal to given value k. 
You have to calculate this value modulo 10^6+3.

Input Format:
The first line consists of number of test cases. The second line consists of two values n and k.

Constraints:
test cases <= 100 
n <= 100 
k <= 100

Output Format
The number of combinations modulo 10^6+3.

Sample Input
6
5 3
10 9
99 87
23 34
66 23
23 12

Sample Output
2
1
185141
0
375215
84498
*/

// TOP DOWN APPROACH

#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e6+3;
int dp[105][3][105];
int n, k;

int top_down(int i, int prev, int sum){
	// base case
	if(i == n){
		return (sum == k ? 1 : 0);
	}
	
	// check if already computed
	if(dp[i][prev][sum] != -1){
		return dp[i][prev][sum];
	}
	
	int res = 0;
	// cases if we take the current element at index i as 1
	if(prev == 1) res += top_down(i+1, 1, sum+1);
	else res += top_down(i+1, 1, sum);
	res %= mod;
	
	// cases if we take the current element at index i as 0
	res += top_down(i+1, 0, sum);
	res %= mod;
	
	// return final result
	return dp[i][prev][sum] = res;
}

void solve()
{
  	cin >> n >> k;
  	memset(dp, -1, sizeof(dp));
  	
  	cout << (top_down(1, 0, 0) + top_down(1, 1, 0))%mod << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}