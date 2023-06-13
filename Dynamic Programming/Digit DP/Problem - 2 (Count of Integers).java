// Problem: https://leetcode.com/problems/count-of-integers/description/

// Ref: https://www.youtube.com/watch?v=ZsHbl-DEjX8&t=342s&ab_channel=codingMohan

/*****************************************************************************************************************************************************************/

class Solution {
    int mod = (int) 1e9+7;
    int minSum, maxSum;
    String s;

    int[][][] dp = new int[23][199][2];

    int goodNumbers(int idx, int sum, int isAlreadySmaller) {
        // base case(s)
        if(idx == s.length()) {
            if((minSum <= sum) && (sum <= maxSum)) return 1;
            else return 0;
        }

        // check if already calculated
        int res = dp[idx][sum][isAlreadySmaller];
        if(res != -1) return res;

        res = 0;

        int start = 0, end = 9;
        if(isAlreadySmaller == 0) end = s.charAt(idx) - '0';

        for(int i = start; i <= end; i++) {
            int newIsAlreadySmaller = (isAlreadySmaller == 1) ? 1 : ((i != end) ? 1 : 0);
            res = (res + goodNumbers(idx + 1, sum + i, newIsAlreadySmaller)) % mod;
        }

        return dp[idx][sum][isAlreadySmaller] = res;
    }

    void buildStr(String t) {
        int n = t.length();
        s = "";

        for(int i = 0; i < (23 - n); i++) {
            s += "0";
        }

        s += t;
    }

    String subtractOne(String t) {
        int n = t.length();
        int idx = n - 1;

        while(idx >= 0) {
            if(t.charAt(idx) != '0') break;
            idx -= 1;
        }

        assert (idx >= 0);

        StringBuilder res = new StringBuilder(t);
        res.setCharAt(idx, (char) (t.charAt(idx) - 1));

        for(int i = idx + 1; i < n; i++) {
            res.setCharAt(i, '9');
        }

        return res.toString();
    }

    void initDP() {
        for(int i = 0; i < 23; i++) {
            for(int j = 0; j < 199; j++) {
                for(int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
    }

    public int count(String num1, String num2, int min_sum, int max_sum) {
        minSum = min_sum;
        maxSum = max_sum;

        initDP();
        buildStr(num2);
        int a = goodNumbers(0, 0, 0);

        initDP();
        buildStr(subtractOne(num1));
        int b = goodNumbers(0, 0, 0);
        
        int res = (a - b + mod) % mod;

        return res;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.count("1", "12", 1, 8));
    }
}
