// Problem: https://leetcode.com/problems/beautiful-arrangement/description/

/**************************************************************************************************************************************************************/

// METHOD - 1

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

    static int[][] dp;

    static void initDP(int n) {
        dp = new int[n][1 << n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < (1 << n); j++) {
                dp[i][j] = -1;
            }
        }
    }

    static int countArrangement(int idx, int mask, int n, int[] a) {
        // Base case(s)
        if(idx == n) return 1;

        // Check if already calculated
        int res = dp[idx][mask];
        if(res != -1) return res;

        res = 0;

        for(int i = 0; i < n; i++) {
            if(((mask >> i) & 1) == 1) continue;
            if((a[i] % (idx + 1) != 0) && ((idx + 1) % a[i] != 0)) continue;
            res += countArrangement(idx + 1, mask | (1 << i), n, a);
        }

        return dp[idx][mask] = res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();
        int[] a = new int[n];

        for(int i = 0; i < n; i++) {
            a[i] = i + 1;
        }

        initDP(n);

        int res = countArrangement(0, 0, n, a);

        System.out.println(res);
    }
}

/**************************************************************************************************************************************************************/

// METHOD - 2

// Reference: https://leetcode.com/problems/beautiful-arrangement/editorial/