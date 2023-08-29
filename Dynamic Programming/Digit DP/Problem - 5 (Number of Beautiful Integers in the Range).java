// Problem: https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/

// Reference: https://youtu.be/vU583zje8K8

/********************************************************************************************************************************************************************/

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

    static int[][][][][][] dp;

    private static void initDP() {
        dp = new int[10][2][10][10][20][2];

        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 10; k++) {
                    for(int l = 0; l < 10; l++) {
                        for(int m = 0; m < 20; m++) {
                            for(int n = 0; n < 2; n++) {
                                dp[i][j][k][l][m][n] = -1;
                            }
                        }
                    }
                }
            }
        }
    }

    private static int helper(int idx, int isStarted, int oddCount, int evenCount, int remainder, int tight, int k, String str) {
        // Base case(s)
        if(idx == str.length()) {
            if((isStarted == 1) && (oddCount == evenCount) && (remainder == 0)) return 1;
            else return 0;
        }

        // Check if already calculated
        int res = dp[idx][isStarted][oddCount][evenCount][remainder][tight];
        if(res != -1) {
            return res;
        }

        res = 0;

        int start = 0, end = 9;
        if(tight == 1) end = str.charAt(idx) - '0';

        for(int d = start; d <= end; d++) {
            int newIsStarted = ((isStarted == 1 || (d != 0))) ? 1 : 0;
            int newOddCount = ((newIsStarted == 1) && (d % 2 == 1)) ? (oddCount + 1) : oddCount;
            int newEvenCount = ((newIsStarted == 1) && (d % 2 == 0)) ? (evenCount + 1) : evenCount;
            int newRemainder = ((remainder * 10) + d) % k;

            int newTight = ((tight == 1) && (d == end)) ? 1 : 0;

            // For better explanation of value assignment to newTight refer below code
            // int newTight;
            // if(tight == 0) newTight = 0;
            // else {
            //     if(d == end) newTight = 1;
            //     else newTight = 0;
            // }

            res += helper(idx + 1, newIsStarted, newOddCount, newEvenCount, newRemainder, newTight, k, str);
        }

        return dp[idx][isStarted][oddCount][evenCount][remainder][tight] = res;
    }

    private static int numberOfBeautifulIntegers(int low, int high, int k) {
        initDP();
        int R = helper(0, 0, 0, 0, 0, 1, k, Integer.toString(high));

        initDP();
        int L = 0;
        if(low != 1) {
            L = helper(0, 0, 0, 0, 0, 1, k, Integer.toString(low - 1));
        }

        return (R - L);
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int low = fr.nextInt();
        int high = fr.nextInt();
        int k = fr.nextInt();

        int res = numberOfBeautifulIntegers(low, high, k);
        System.out.println(res);
    }
}