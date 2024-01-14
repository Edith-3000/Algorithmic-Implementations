// Problem: https://leetcode.com/problems/numbers-with-repeated-digits/description/

// Reference: https://leetcode.com/problems/numbers-with-repeated-digits/

/********************************************************************************************************************************************************************/

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

    private static int[][][] dp;

    private static void initDP() {
        dp = new int[10][2][1025];

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 2; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
    }

    private static int numbersWithNoRepeatingDigit(int index, int tightBound, int mask, String str) {
        // Base case(s)
        if (index == str.length()) {
            if (mask == 0) return 0;
            else return 1;
        }

        // Check if already calculated
        if (dp[index][tightBound][mask] != -1) {
            return dp[index][tightBound][mask];
        }

        int result = 0;
        int end = (tightBound == 0) ? 9 : (int) (str.charAt(index) - '0');

        for (int digit = 0; digit <= end; digit++) {
            // mask == 0 => No digit has been selected yet and dig == 0 => we can't select first digit of any number as 0
            if ((mask == 0) && (digit == 0)) {
                int newTightBound = ((tightBound == 1) && (digit == end)) ? 1 : 0;
                result += numbersWithNoRepeatingDigit(index + 1, newTightBound, mask, str);
                continue;
            }

            // Check if the current digit has already been included
            int digitIncluded = (mask >> digit) & 1;

            // If current digit hasn't been included yet, then include it and further proceed
            if (digitIncluded == 0) {
                int newTightBound = ((tightBound == 1) && (digit == end)) ? 1 : 0;
                int newMask = mask | (1 << digit);
                result += numbersWithNoRepeatingDigit(index + 1, newTightBound, newMask, str);
            }
        }

        return dp[index][tightBound][mask] = result;
    }

    private static int numDupDigitsAtMostN(int n) {
        initDP();
        int count = numbersWithNoRepeatingDigit(0, 1, 0, Integer.toString(n));
        return (n - count);
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int result = numDupDigitsAtMostN(n);
        System.out.println(result);
    }
}