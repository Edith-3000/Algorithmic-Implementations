// Problem: https://leetcode.com/problems/special-permutations/

// Reference(s): https://www.youtube.com/watch?v=xHsHC2lCDD4&t=821s&ab_channel=codingMohan

/****************************************************************************************************************************************************************/

/* # NOTE: The reference video beautifully explains on how to reach a DP with Bitmasking solution for a problem.
           It gives a walkthrough from brute force to optimised solution.
*/

/****************************************************************************************************************************************************************/

// METHOD - 1 [O(n^2 x 2^n x n)]

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

    static int mod = (int) 1e9 + 7;

    static int dp[][][];

    static void initDP(int n) {
        dp = new int[n][n][1 << n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < (1 << n); k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
    }

    static boolean goodPair(int x, int y) {
        return (x % y == 0) || (y % x == 0);
    }

    static int countSpecialPermutations(int idx, int lastTakenIdx, int mask, int n, int[] a) {
        // base case(s)
        if(idx == n) return 1;

        // check if already calculated
        int res = dp[idx][lastTakenIdx][mask];
        if(res != -1) return res;

        res = 0;

        for(int i = 0; i < n; i++) {
            if(((mask >> i) & 1) == 1) continue;
            if((idx != 0) && !goodPair(a[i], a[lastTakenIdx])) continue;

            res = (res + countSpecialPermutations(idx + 1, i, mask | (1 << i), n, a)) % mod;
        }

        return dp[idx][lastTakenIdx][mask] = res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();
        int[] a = new int[n];

        for(int i = 0; i < n; i++) {
            a[i] = fr.nextInt();
        }

        initDP(n);

        int res = countSpecialPermutations(0, 0, 0, n, a);

        System.out.println(res);
    }
}


// TC explanation: (n^2 x 2^n) DP states and it takes O(n) time to compute a single state (i.e. the Transition Time)

/****************************************************************************************************************************************************************/

// METHOD - 2 [O(n x 2^n x n)]

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

    static int mod = (int) 1e9 + 7;

    static int[][] dp;

    static void initDP(int n) {
        dp = new int[n][1 << n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < (1 << n); j++) {
                dp[i][j] = -1;
            }
        }
    }

    static boolean goodPair(int x, int y) {
        return (x % y == 0) || (y % x == 0);
    }

    static int countSpecialPermutations(int lastTakenIdx, int mask, int n, int[] a) {
        // base case(s)
        if(mask == (1 << n) - 1) return 1;

        // check if already calculated
        int res = dp[lastTakenIdx][mask];
        if(res != -1) return res;

        res = 0;

        for(int i = 0; i < n; i++) {
            if(((mask >> i) & 1) == 1) continue;
            if((mask != 0) && !goodPair(a[i], a[lastTakenIdx])) continue;

            res = (res + countSpecialPermutations(i, mask | (1 << i), n, a)) % mod;
        }

        return dp[lastTakenIdx][mask] = res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();
        int[] a = new int[n];

        for(int i = 0; i < n; i++) {
            a[i] = fr.nextInt();
        }

        initDP(n);

        int res = countSpecialPermutations(0, 0, n, a);

        System.out.println(res);
    }
}


// TC explanation: (n x 2^n) DP states and it takes O(n) time to compute a single state (i.e. the Transition Time)