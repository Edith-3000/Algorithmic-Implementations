// Problem: https://leetcode.com/problems/maximum-students-taking-exam/description/

// Reference: Hint section of LeetCode

/*****************************************************************************************************************************************************************/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
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

    static void initDP(int n, int m) {
        dp = new int[n][1 << m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < (1 << m); j++) {
                dp[i][j] = -1;
            }
        }
    }

    static boolean validCurRowMask(int curRow, List<Integer> setBits, int prevRowMask, int n, int m, char[][] a) {
        int k = setBits.size();

        for(int i = 0; i < k; i++) {
            int idx = setBits.get(i);

            if(a[curRow][idx] == '#') return false;

            if((i > 0) && (setBits.get(i - 1) == idx - 1)) return false;
            if((i < k - 1) && (setBits.get(i + 1) == idx + 1)) return false;

            if((idx > 0) && (((prevRowMask >> (idx - 1)) & 1) == 1)) return false;
            if((idx < m - 1) && (((prevRowMask >> (idx + 1)) & 1) == 1)) return false;
        }

        return true;
    }

    static List<Integer> findSetBits(int num, int m) {
        List<Integer> list = new ArrayList<>();

        for(int j = 0; j < m; j++) {
            if(((num >> j) & 1) == 1) {
                list.add(j);
            }
        }

        return list;
    }

    static int maxStudents(int curRow, int prevRowMask, int n, int m, char[][] a) {
        // Base case(s)
        if(curRow == n) {
            return 0;
        }

        // Check if already calculated
        int res = dp[curRow][prevRowMask];
        if(res != -1) return res;

        res = 0;

        for(int curRowMask = 0; curRowMask < (1 << m); curRowMask++) {
            List<Integer> setBits = findSetBits(curRowMask, m);

            if(validCurRowMask(curRow, setBits, prevRowMask, n, m, a)) {
                int ans = setBits.size() + maxStudents(curRow + 1, curRowMask, n, m, a);
                res = Math.max(res, ans);
            }
        }

        return dp[curRow][prevRowMask] = res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n, m;
        n = fr.nextInt();
        m = fr.nextInt();

        char[][] a = new char[n][m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = fr.next().charAt(0);
            }
        }

        initDP(n, m);

        int res = maxStudents(0, 0, n, m, a);

        System.out.println(res);
    }
}

// TC: There are O(n x 2^m) DP states and the transition time is O(2^m x n).
//     Therefore overall time complexity is O(n^2 x 2^(2 x m))