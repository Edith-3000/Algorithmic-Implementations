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

    private static int largestPowerOfTwoLessThanOrEqualToN(long n) {
        int largestPower = 0;

        while((1L << (long) largestPower) <= n) {
            largestPower += 1;
        }

        largestPower -= 1;
        return largestPower;
    }

    private static void countSetBitsAtEveryPositionHelper(long n, long[] bitsCount) {
        // Base condition
        if (n == 0L) {
            return;
        }

        int x = largestPowerOfTwoLessThanOrEqualToN(n);

        for (int bitPos = 0; bitPos < x; bitPos++) {
            bitsCount[bitPos] += (1L << (long) (x - 1));
        }

        bitsCount[x] += (n - (1L << (long) x) + 1);
        n -= (1L << (long) x);

        countSetBitsAtEveryPositionHelper(n, bitsCount);
    }

    private static long[] countSetBitsAtEveryPosition(long n) {
        long[] bitsCount = new long[64];

        for (int i = 0; i < 64; i++) {
            bitsCount[i] = 0;
        }

        countSetBitsAtEveryPositionHelper(n, bitsCount);
        return bitsCount;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();
        long n = fr.nextLong();

        long[] result = countSetBitsAtEveryPosition(n);

        for (int i = result.length - 1; i >= 0; i--) {
            System.out.print(result[i] + " ");
        }
    }
}