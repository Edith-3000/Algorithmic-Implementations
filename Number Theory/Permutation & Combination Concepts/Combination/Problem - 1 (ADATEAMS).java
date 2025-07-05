// PROBLEM: https://www.spoj.com/problems/ADATEAMS/

/************************************************************************************************************************************************/


// METHOD - 1

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    private static final long mod = 1_000_000_007L;
    private static final int MAX = 1_000_000;

    private static long[] fact;

    private static long moduloExp(long a, long b) {
        a %= mod;
        if (a == 0L) {
            return 0L;
        }

        long result = 1L;

        while (b > 0L) {
            if ((b & 1) == 1L) {
                result = (result * a) % mod;
            }

            a = (a * a) % mod;
            b >>= 1L;
        }

        return result;
    }

    private static long moduloMultiInv(long a, long b) {
        return moduloExp(a, b - 2);
    }

    private static void computeFactorials(int n) {
        fact = new long[n + 1];
        fact[0] = 1L;

        for (int i = 1; i <= n; i++) {
            fact[i] = (i * fact[i - 1]) % mod;
        }
    }

    private static long computeCombination(int n, int r) {
        if (r < 0 || r > n) return 0L;
        if (r == 0 || r == n) return 1L;

        long num = fact[n];
        long den = (fact[n - r] * fact[r]) % mod;

        long nCr = (num * moduloMultiInv(den, mod)) % mod;

        return nCr;
    }

    public static void main(String[] args) throws java.lang.Exception {
        computeFactorials(MAX);

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String inputLine;

        while ((inputLine = br.readLine()) != null && !inputLine.trim().isEmpty()) {
            String[] tokens = inputLine.trim().split("\\s+");

            int N = Integer.parseInt(tokens[0]);
            int A = Integer.parseInt(tokens[1]);
            int B = Integer.parseInt(tokens[2]);
            int D = Integer.parseInt(tokens[3]);

            long result = (computeCombination(N, A) * moduloExp(computeCombination(B, D), A) % mod) % mod;

            System.out.println(result);
        }
    }
}


/***********************************************************************************************************************************************************/

// METHOD - 2

// NOTE: Slightly optimized by precomputing and using an inverse factorial array (invFact). This avoids repeated expensive modular inverse calculations
//       using moduloExp() during nCr computation.


import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    private static final long mod = 1_000_000_007L;
    private static final int MAX = 1_000_000;

    private static long[] fact;
    private static long[] invFact;

    private static long moduloExp(long a, long b) {
        a %= mod;
        if (a == 0L) {
            return 0L;
        }

        long result = 1L;

        while (b > 0L) {
            if ((b & 1) == 1L) {
                result = (result * a) % mod;
            }

            a = (a * a) % mod;
            b >>= 1L;
        }

        return result;
    }

    private static long moduloMultiInv(long a, long b) {
        return moduloExp(a, b - 2);
    }

    private static void computeFactorials(int n) {
        fact = new long[n + 1];
        invFact = new long[n + 1];

        fact[0] = invFact[0] = 1L;

        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        // Compute inverse factorials using Fermat's Little Theorem
        invFact[n] = moduloExp(fact[n], mod - 2);
        for (int i = n - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
        }
    }

    private static long computeCombination(int n, int r) {
        if (r < 0 || r > n) return 0L;
        if (r == 0 || r == n) return 1L;

        return (((fact[n] * invFact[r]) % mod) * invFact[n - r]) % mod;
    }

    public static void main(String[] args) throws java.lang.Exception {
        computeFactorials(MAX);

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String inputLine;

        while ((inputLine = br.readLine()) != null && !inputLine.trim().isEmpty()) {
            String[] tokens = inputLine.trim().split("\\s+");

            int N = Integer.parseInt(tokens[0]);
            int A = Integer.parseInt(tokens[1]);
            int B = Integer.parseInt(tokens[2]);
            int D = Integer.parseInt(tokens[3]);

            long result = (computeCombination(N, A) * moduloExp(computeCombination(B, D), A) % mod) % mod;

            System.out.println(result);
        }
    }
}
