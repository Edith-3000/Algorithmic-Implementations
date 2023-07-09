// Problem: https://leetcode.com/problems/decremental-string-concatenation/description/

// Reference: https://www.youtube.com/watch?v=5XER2thL3HI

/****************************************************************************************************************************************************************/

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

    // dp[i][j][k] = minimum concatenation length of the strings from [i, n - 1] such that
    //               the start and end characters of strings already concatenated from [0, i) are j & k
    //               (ASCII representation) respectively.
    static int[][][] dp;

    static void initDP(int n) {
        dp = new int[n][26][26];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 26; j++) {
                for(int k = 0; k < 26; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
    }

    static int helper(int idx, char firstChar, int lastChar, int n, String[] a) {
        // Base case(s)
        if(idx == n) {
            return 0;
        }

        // Check if already calculated
        if((idx != 0) && dp[idx][firstChar - 'a'][lastChar - 'a'] != -1) {
            return dp[idx][firstChar - 'a'][lastChar - 'a'];
        }

        char curFirstChar = a[idx].charAt(0);
        char curLastChar = a[idx].charAt(a[idx].length() - 1);

        // Handle special case separately
        if(idx == 0) {
            return a[idx].length() + helper(idx + 1, curFirstChar, curLastChar, n, a);
        }

        int prvCurNotMatched = a[idx].length() + helper(idx + 1, firstChar, curLastChar, n, a);
        int curPrvNotMatched = a[idx].length() + helper(idx + 1, curFirstChar, lastChar, n, a);

        int prvCurMatched = Integer.MAX_VALUE;
        int curPrvMatched = Integer.MAX_VALUE;

        if(lastChar == curFirstChar) {
            prvCurMatched = a[idx].length() - 1 + helper(idx + 1, firstChar, curLastChar, n, a);
        }

        if(curLastChar == firstChar) {
            curPrvMatched = a[idx].length() - 1 + helper(idx + 1, curFirstChar, lastChar, n, a);
        }

        int res = Math.min(prvCurNotMatched, Math.min(curPrvNotMatched, Math.min(prvCurMatched, curPrvMatched)));

        return dp[idx][firstChar - 'a'][lastChar - 'a'] = res;
    }

    public static int minimizeConcatenatedLength(String[] words) {
        int n = words.length;
        if(n == 1) return words[0].length();

        initDP(n);

        int res = helper(0, '#', '#', n, words);
        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();
        String[] words = new String[n];

        for(int i = 0; i < n; i++) {
            words[i] = fr.next();
        }

        System.out.println(minimizeConcatenatedLength(words));
    }
}
