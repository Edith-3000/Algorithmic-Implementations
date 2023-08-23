// Problem: https://leetcode.com/problems/sorting-three-groups/description/

// Reference: https://www.youtube.com/watch?v=fkNO1By4fTc
//            Hint section of LeetCode

/*************************************************************************************************************************************************************************/

// METHOD - 1 [O(n^3)]

// Refer the YouTube video above.

/*************************************************************************************************************************************************************************/

// METHOD - 2 [O(n^2)]

// Refer the YouTube video above.

/*************************************************************************************************************************************************************************/

// METHOD - 3 [O(n)]

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                if (st.hasMoreTokens()) {
                    str = st.nextToken("\n");
                } else {
                    str = br.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    // dp[i][j] = minimum #operations required from [i, n - 1] such that the element at
    //            index 'i' belongs to group 'j'
    static int[][] dp;

    static void initDP(int n, int m) {
        dp = new int[n][m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = -1;
            }
        }
    }

    static int helper(int idx, int val, int n, List<Integer> nums) {
        // Base case(s)
        if(idx >= n) {
            return 0;
        }

        // Check if already calculated
        int res = dp[idx][val];
        if(res != -1) return res;

        res = Integer.MAX_VALUE;

        for(int j = val; j <= 3; j++) {
            res = Math.min(res, ((nums.get(idx) != val) ? 1 : 0) +  helper(idx + 1, j, n, nums));
        }

        return dp[idx][val] = res;
    }

    static int minimumOperations(List<Integer> nums) {
        int n = nums.size();
        initDP(n, 4);

        int res = Integer.MAX_VALUE;

        for(int j = 1; j <= 3; j++) {
            res = Math.min(res, helper(0, j, n, nums));
        }

        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();
        List<Integer> nums = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            nums.add(fr.nextInt());
        }

        System.out.println(minimumOperations(nums));
    }
}