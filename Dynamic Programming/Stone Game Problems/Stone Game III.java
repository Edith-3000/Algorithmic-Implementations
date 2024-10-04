// Problem: https://leetcode.com/problems/stone-game-iii/description/

// Reference: https://youtu.be/KI8suf35r38

/***********************************************************************************************************************************************************/

// METHOD - 1 (RECUSRION)

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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

    private static int helper(int idx, int n, int[] stoneValue) {
        // Base case
        if (idx == n) {
            return 0;
        }

        int diff = Integer.MIN_VALUE;

        diff = Math.max(diff, stoneValue[idx] - helper(idx + 1, n, stoneValue));

        if ((idx + 1) < n) {
            diff = Math.max(diff, stoneValue[idx] + stoneValue[idx + 1] - helper(idx + 2, n, stoneValue));
        }

        if ((idx + 2) < n) {
            diff = Math.max(diff, stoneValue[idx] + stoneValue[idx + 1] + stoneValue[idx + 2] - helper(idx + 3, n, stoneValue));
        }

        return diff;
    }

    private static String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;

        int diff = helper(0, n, stoneValue);

        if (diff > 0) {
            return "Alice";
        } else if (diff < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[] stoneValue = new int[n];

        for (int i = 0; i < n; i++) {
            stoneValue[i] = fr.nextInt();
        }

        System.out.println(stoneGameIII(stoneValue));
    }
}

/***********************************************************************************************************************************************************/

// METHOD - 2 (Memoization)

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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

    private static int[] initDP(int n) {
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return dp;
    }

    private static int helper(int idx, int n, int[] stoneValue, int[] dp) {
        // Base case
        if (idx == n) {
            return 0;
        }

        // Check if already calculated
        if (dp[idx] != -1) {
            return dp[idx];
        }

        int diff = Integer.MIN_VALUE;

        diff = Math.max(diff, stoneValue[idx] - helper(idx + 1, n, stoneValue, dp));

        if ((idx + 1) < n) {
            diff = Math.max(diff, stoneValue[idx] + stoneValue[idx + 1] - helper(idx + 2, n, stoneValue, dp));
        }

        if ((idx + 2) < n) {
            diff = Math.max(diff, stoneValue[idx] + stoneValue[idx + 1] + stoneValue[idx + 2] - helper(idx + 3, n, stoneValue, dp));
        }

        return dp[idx] = diff;
    }

    private static String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;

        int[] dp = initDP(n);
        int diff = helper(0, n, stoneValue, dp);

        if (diff > 0) {
            return "Alice";
        } else if (diff < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[] stoneValue = new int[n];

        for (int i = 0; i < n; i++) {
            stoneValue[i] = fr.nextInt();
        }

        System.out.println(stoneGameIII(stoneValue));
    }
}

/***********************************************************************************************************************************************************/

// METHOD - 3 (Tabulation)

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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

    private static int[] initDP(int n) {
        return new int[n + 1];
    }

    private static int helper(int n, int[] stoneValue, int[] dp) {
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = Integer.MIN_VALUE;
            dp[i] = Math.max(dp[i], stoneValue[i] - dp[i + 1]);

            if ((i + 1) < n) {
                dp[i] = Math.max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            }

            if ((i + 2) < n) {
                dp[i] = Math.max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
            }
        }

        return dp[0];
    }

    private static String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;

        int[] dp = initDP(n);
        int diff = helper(n, stoneValue, dp);

        if (diff > 0) {
            return "Alice";
        } else if (diff < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[] stoneValue = new int[n];

        for (int i = 0; i < n; i++) {
            stoneValue[i] = fr.nextInt();
        }

        System.out.println(stoneGameIII(stoneValue));
    }
}

/***********************************************************************************************************************************************************/

// METHOD - 4 (Tabulation - Space Optimized)

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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

    private static int helper(int n, int[] stoneValue) {
        int a = 0, b = 0, c = 0;

        for (int i = n - 1; i >= 0; i--) {
            int ans = Integer.MIN_VALUE;
            ans = Math.max(ans, stoneValue[i] - a);

            if ((i + 1) < n) {
                ans = Math.max(ans, stoneValue[i] + stoneValue[i + 1] - b);
            }

            if ((i + 2) < n) {
                ans = Math.max(ans, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - c);
            }

            c = b;
            b = a;
            a = ans;
        }

        return a;
    }

    private static String stoneGameIII(int[] stoneValue) {
        int n = stoneValue.length;

        int diff = helper(n, stoneValue);

        if (diff > 0) {
            return "Alice";
        } else if (diff < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[] stoneValue = new int[n];

        for (int i = 0; i < n; i++) {
            stoneValue[i] = fr.nextInt();
        }

        System.out.println(stoneGameIII(stoneValue));
    }
}