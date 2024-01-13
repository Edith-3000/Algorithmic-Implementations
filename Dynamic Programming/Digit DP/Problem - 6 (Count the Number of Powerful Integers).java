// Problem: https://leetcode.com/problems/count-the-number-of-powerful-integers/description/

// Reference: https://www.youtube.com/watch?v=xVT3ZuDfFnA

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

    private static int countDigits(long num) {
        if (num == 0) {
            return 1;
        }

        int digitsCount = 0;

        while(num > 0) {
            digitsCount += 1;
            num /= 10;
        }

        return digitsCount;
    }

    private static List<List<Long>> initialiseDP(int rowsCount) {
        List<List<Long>> dp = new ArrayList<>();

        for (int i = 0; i < rowsCount; i++) {
            List<Long> list = new ArrayList<>(List.of(-1L, -1L));
            dp.add(list);
        }

        return dp;
    }

    private static long countHelper(int idx, int tightBound, String val, int limit, String suffix, List<List<Long>> dp, int length) {
        // Base condition(s)
        if (length < suffix.length()) {
            return 0L;
        }

        if (idx == length) {
            return 1L;
        }

        // Check if already calculated
        if (dp.get(idx).get(tightBound) != -1) {
            return dp.get(idx).get(tightBound);
        }

        long res = 0;

        int start = (idx == 0) ? 1 : 0;
        int end = Math.min(limit, (tightBound == 0) ? 9 : (int) (val.charAt(idx) - '0'));

        for (int digit = start; digit <= end; digit++) {
            int suffixLength = suffix.length();

            if ((idx >= length - suffixLength) && (digit != (int) (suffix.charAt(idx - length + suffixLength) - '0'))) {
                continue;
            }

            int newTightBound;
            if (tightBound == 0) {
                newTightBound = 0;
            } else {
                if (digit == (int) (val.charAt(idx)) - '0') newTightBound = 1;
                else newTightBound = 0;
            }

            res += countHelper(idx + 1, newTightBound, val, limit, suffix, dp, length);
        }

        dp.get(idx).set(tightBound, res);

        return dp.get(idx).get(tightBound);
    }

    private static long countPowerfulIntegers(long num, int limit, String s) {
        if (num == 0) {
            if (s.equals("0")) return 1;
            else return 0;
        }

        long result = 0;
        int digitsCounts = countDigits(num);
        String numString = Long.toString(num);

        for (int len = 1; len <= digitsCounts; len++) {
            List<List<Long>> dp = initialiseDP(len);
            int tightBound = 1;
            if (len < digitsCounts) tightBound = 0;
            result += countHelper(0, tightBound, numString, limit, s, dp, len);
        }

        return result;
    }

    private static long numberOfPowerfulInt(long start, long finish, int limit, String s) {
        long R = countPowerfulIntegers(finish, limit, s);
        long L = countPowerfulIntegers(start - 1, limit, s);
        
        return (R - L);
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        long start = fr.nextLong();
        long finish = fr.nextLong();
        int limit = fr.nextInt();
        String s = fr.next();

        long result = numberOfPowerfulInt(start, finish, limit, s);
        System.out.println(result);
    }
}