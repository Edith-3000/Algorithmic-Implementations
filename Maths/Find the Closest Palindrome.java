// Problem: https://leetcode.com/problems/find-the-closest-palindrome/description/       

/*************************************************************************************************************************************************************************/

// METHOD - 1
// Ref: https://leetcode.com/problems/find-the-closest-palindrome/editorial/

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

    private static boolean isPalindrome(long num) {
        long x = num, reverse = 0;

        while(x > 0) {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }

        return (reverse == num);
    }

    private static String nearestPalindromic(String n) {
        long num = Long.parseLong(n);

        for(long i = 1; ; i++) {
            if (isPalindrome(num - i)) {
                return "" + (num - i);
            }

            if (isPalindrome(num + i)) {
                return "" + (num + i);
            }
        }
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();
        String n = fr.next();

        String res = nearestPalindromic(n);
        System.out.println(res);
    }
}

// Time Complexity: See the Complexity Analysis of Approach #1 Brute Force[Time Limit Exceeded] from
//                  https://leetcode.com/problems/find-the-closest-palindrome/editorial/

/*************************************************************************************************************************************************************************/

// METHOD - 2
// Ref: https://www.youtube.com/watch?v=vJBlA5y4q3w

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

    private static Long framePalindromeFromLeftHalf(String str, long digitsCount) {
        StringBuilder rightHalf = new StringBuilder(str);
        if (digitsCount % 2 == 1) {
            rightHalf.deleteCharAt(rightHalf.length() - 1);
        }

        rightHalf.reverse();

        return Long.parseLong(str + rightHalf);
    }

    private static String nearestPalindromic(String n) {
        long num = Long.parseLong(n);
        long digitsCount = n.length();

        if (digitsCount == 1) {
            return "" + (num - 1);
        }

        String leftHalfString = n.substring(0, (int)(digitsCount + 1) / 2);

        String leftHalfStringIncremented = Long.toString(Long.parseLong(leftHalfString) + 1);
        String leftHalfStringDecremented = Long.toString(Long.parseLong(leftHalfString) - 1);

        List<Long> candidates = new ArrayList<>();

        // 3 candidate palindromes if the resulting palindrome is having the same number of digits as num
        candidates.add(framePalindromeFromLeftHalf(leftHalfString, digitsCount));
        candidates.add(framePalindromeFromLeftHalf(leftHalfStringIncremented, digitsCount));
        candidates.add(framePalindromeFromLeftHalf(leftHalfStringDecremented, digitsCount));

        long oneDigitMorePalindromicCandidate = (long)Math.pow(10, digitsCount) + 1;
        long oneDigitLessPalindromicCandidate = (long)Math.pow(10, digitsCount - 1) - 1;

        // 2 candidate palindromes if the resulting palindrome is having the 1 digit more and 1 digit less than num
        candidates.add(oneDigitMorePalindromicCandidate);
        candidates.add(oneDigitLessPalindromicCandidate);
        
        Collections.sort(candidates);

        long minDifference = Long.MAX_VALUE;
        long minDifferencePalindrome = Long.MAX_VALUE;

        for(Long candidate: candidates) {
            long diff = Math.abs(candidate - num);
            if((diff != 0) && (diff < minDifference)) {
                minDifference = diff;
                minDifferencePalindrome = candidate;
            }
        }

        return Long.toString(minDifferencePalindrome);
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();
        String n = fr.next();

        String res = nearestPalindromic(n);
        System.out.println(res);
    }
}