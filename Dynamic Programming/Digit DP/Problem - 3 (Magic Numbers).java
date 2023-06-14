// Problem: https://codeforces.com/contest/628/problem/D

// Ref: https://codeforces.com.cn/blog/entry/89981
//      https://codeforces.com.cn/contest/628/submission/119295777
//      https://codeforces.com/blog/entry/43203?#comment-280049

/*****************************************************************************************************************************************************************/

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

    static int mod = (int) 1e9+7;
    static int m, d;
    static String L, R;

    static int[][][] dp;

    static void initDP() {
        for(int i = 0; i < R.length(); i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
    }

    static String subtractOne(String t) {
        int n = t.length();
        int idx = n - 1;

        while(idx >= 0) {
            if(t.charAt(idx) != '0') break;
            idx -= 1;
        }

        assert (idx >= 0);

        StringBuilder res = new StringBuilder(t);
        res.setCharAt(idx, (char) (t.charAt(idx) - 1));

        for(int i = idx + 1; i < n; i++) {
            res.setCharAt(i, '9');
        }

        return res.toString();
    }

    static int countGoodNumbers(int idx, int rem, int tight, String str) {
        // base case(s)
        if(idx == str.length()) {
            return (rem == 0) ? 1 : 0;
        }

        // check if already calculated
        int res = dp[idx][rem][tight];
        if(res != -1) return res;

        res = 0;

        int start = 0, end = 9;
        if(tight == 1) end = str.charAt(idx) - '0';

        for(int i = start; i <= end; i++) {
            if(((idx + 1) % 2 == 1) && (i == d)) continue;
            if(((idx + 1) % 2 == 0) && (i != d)) continue;

            int newTight = ((tight == 1) && (i == end)) ? 1 : 0;

            // For better explanation of value assignment to newTight refer below code
            // int newTight;
            // if(tight == 0) newTight = 0;
            // else {
            //     if(i == end) newTight = 1;
            //     else newTight = 0;
            // }

            int newRem = ((rem * 10) + i) % m;

            res = (res + countGoodNumbers(idx + 1, newRem, newTight, str)) % mod;
        }

        return dp[idx][rem][tight] = res;
    }

    // https://codeforces.com.cn/blog/entry/89981
    // https://codeforces.com.cn/contest/628/submission/119295777
    // https://codeforces.com/blog/entry/43203?#comment-280049
    public static void main(String[] args) {
        FastReader fr = new FastReader();

        m = fr.nextInt();
        d = fr.nextInt();

        L = fr.nextLine();
        R = fr.nextLine();

        dp = new int[R.length()][m][2];

        initDP();
        int x = countGoodNumbers(0, 0, 1, R);

        initDP();
        int y = countGoodNumbers(0, 0, 1, subtractOne(L));

        int res = (x - y + mod) % mod;

        System.out.println(res);
    }
}
