// Problem: https://leetcode.com/problems/number-of-squareful-arrays/description/

// Reference(s): https://leetcode.com/problems/number-of-squareful-arrays/solutions/2033584/fully-explained-bitmasking-recursion/
//               https://leetcode.com/problems/number-of-squareful-arrays/solutions/2033584/fully-explained-bitmasking-recursion/comments/1433856

/*******************************************************************************************************************************************************************/

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

    static boolean goodPair(int x, int y) {
        int sum = x + y;
        double squareRoot = Math.sqrt((double) sum);
        return (squareRoot - Math.floor(squareRoot) == 0);
    }

    static int countPermutations(int lastTakenIdx, int mask, int n, int[] a) {
        // Base case(s)
        if(mask == (1 << n) - 1) return 1;

        // Check if already calculated
        int res = dp[lastTakenIdx][mask];
        if(res != -1) return res;

        res = 0;

        for(int i = 0; i < n; i++) {
            if(((mask >> i) & 1) == 1) continue;
            if((mask != 0) && !goodPair(a[i], a[lastTakenIdx])) continue;

            // This condition will prevent counting of duplicates
            if((i > 0) && (a[i - 1] == a[i]) && (((mask >> (i - 1)) & 1) == 0)) continue;

            res += countPermutations(i, mask | (1 << i), n, a);
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

        // Done to avoid counting of duplicate permutations
        Arrays.sort(a);

        int res = countPermutations(0, 0, n, a);

        System.out.println(res);
    }
}
