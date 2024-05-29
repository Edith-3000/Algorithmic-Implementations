// Problem: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/

// Reference: https://www.youtube.com/watch?v=xaL5rO_o7kw

/***************************************************************************************************************************************************/

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

    private static int numSubmatrixSumTarget(int[][] matrix, int target) {
        int n = matrix.length;
        if (n == 0) {
            return 0;
        }

        int m = matrix[0].length;

        int[][] rowPrefixSum = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowPrefixSum[i][j] = matrix[i][j];
                if (j > 0) {
                    rowPrefixSum[i][j] += rowPrefixSum[i][j - 1];
                }
            }
        }

        int result = 0;

        for (int colStart = 0; colStart < m; colStart++) {
            for (int colEnd = colStart; colEnd < m; colEnd++) {
                HashMap<Integer, Integer> sumCount = new HashMap<>();
                sumCount.put(0, 1);

                int sum = 0;

                for (int row = 0; row < n; row++) {
                    sum += rowPrefixSum[row][colEnd];
                    if (colStart > 0) {
                        sum -= rowPrefixSum[row][colStart - 1];
                    }

                    if (sumCount.containsKey(sum - target)) {
                        result += sumCount.get(sum - target);
                    }

                    sumCount.put(sum, sumCount.getOrDefault(sum, 0) + 1);
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();
        int m = fr.nextInt();

        int[][] matrix = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = fr.nextInt();
            }
        }

        int target = fr.nextInt();

        System.out.println(numSubmatrixSumTarget(matrix, target));
    }
}