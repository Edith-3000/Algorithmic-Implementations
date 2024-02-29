// Problem: https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/description/

// Reference: https://www.youtube.com/watch?v=pGwkuwMUuPM

/*********************************************************************************************************************************************************************/

// METHOD - 1 (RECUSRION)

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

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

    private static int helper(int idx, int ele, int n, int[] nums) {
        // Base case(s)
        if (idx == n) {
            return 0;
        }

        // Case 1: Do not consider the element at current index i.e. idx
        int res = helper(idx + 1, ele, n, nums);

        // Case 2: Consider the element at current index i.e. idx (if possible)
        if ((nums[idx] == ele) || (nums[idx] + 1 == ele)) {
            res = Math.max(res, 1 + helper(idx + 1, ele + 1, n, nums));
        }

        return res;
    }

    private static int maxSelectedElements(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;

        int result = 1;

        for (int ele = 1; ele <= nums[n - 1]; ele++) {
            result = Math.max(result, helper(0, ele, n, nums));
        }

        return result;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = fr.nextInt();
        }

        System.out.println(maxSelectedElements(nums));
    }
}

/*********************************************************************************************************************************************************************/

// METHOD - 2 (TOP-DOWN DP)

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

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

    static int[][] dp;

    private static void initDP(int n, int m) {
        dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
    }

    private static int helper(int idx, int ele, int n, int[] nums) {
        // Base case(s)
        if (idx == n) {
            return 0;
        }

        // Check if already calculated
        if (dp[idx][ele] != -1) {
            return dp[idx][ele];
        }

        // Case 1: Do not consider the element at current index i.e. idx
        int res = helper(idx + 1, ele, n, nums);

        // Case 2: Consider the element at current index i.e. idx (if possible)
        if ((nums[idx] == ele) || (nums[idx] + 1 == ele)) {
            res = Math.max(res, 1 + helper(idx + 1, ele + 1, n, nums));
        }

        return dp[idx][ele] = res;
    }

    private static int maxSelectedElements(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;

        initDP(n, nums[n - 1] + 3);

        int result = 1;

        for (int ele = 1; ele <= nums[n - 1]; ele++) {
            result = Math.max(result, helper(0, ele, n, nums));
        }

        return result;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = fr.nextInt();
        }

        System.out.println(maxSelectedElements(nums));
    }
}

/*********************************************************************************************************************************************************************/

// METHOD - 3 (BOTTOM-UP DP)
// NOTE: NOT SURE WHY THIS IS NOT GIVING CORRECT RESULT AND THEREBY NOT GETTING AN AC ON LEETCODE


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

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

    static int[][] dp;

    private static void initDP(int n, int m) {
        dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], 0);
        }
    }

    private static int maxSelectedElements(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;

        initDP(n + 1, nums[n - 1] + 3);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = nums[n - 1]; j >= 1; j--) {
                dp[i][j] = dp[i + 1][j];
                if ((nums[i] == j) || (nums[i] + 1 == j)) {
                    dp[i][j] = Math.max(dp[i][j], 1 + dp[i + 1][j + 1]);
                }
            }
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < dp[i].length; j++) {
                result = Math.max(result, dp[i][j]);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = fr.nextInt();
        }

        System.out.println(maxSelectedElements(nums));
    }
}

/*********************************************************************************************************************************************************************/

// METHOD - 4 (BOTTOM-UP DP, SPACE OPTIMIZED)

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

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

    static int[] dp;

    private static void initDP(int n) {
        dp = new int[n];
        Arrays.fill(dp, 0);
    }

    private static int maxSelectedElements(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;

        initDP(nums[n - 1] + 3);

        for (int i = n - 1; i >= 0; i--) {
            dp[nums[i]] = Math.max(dp[nums[i]], 1 + dp[nums[i] + 1]);
            dp[nums[i] + 1] = Math.max(dp[nums[i] + 1], 1 + dp[nums[i] + 2]);
        }

        int result = 0;

        for (int i = 0; i < dp.length; i++) {
            result = Math.max(result, dp[i]);
        }

        return result;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = fr.nextInt();
        }

        System.out.println(maxSelectedElements(nums));
    }
}