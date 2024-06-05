// PROBLEM: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/

// REFERENCE: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/editorial/

/********************************************************************************************************************************************************************/

// METHOD - 1 (EXTREME BRUTE FORCE)

// For this refer the above "REFERENCE"

/********************************************************************************************************************************************************************/

// METHOD - 2 (DIVIDE & CONQUER)

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

    private static int longestSubstringWithAtLeastKRepeatingCharactersUtil(String s, int start, int end, int k) {
        if (start > end) {
            return 0;
        }

        if ((end - start + 1) < k) {
            return 0;
        }

        int[] count = new int[26];
        for (int i = start; i <= end; i++) {
            count[s.charAt(i) - 'a'] += 1;
        }

        for (int i = start; i <= end; i++) {
            if (count[s.charAt(i) - 'a'] >= k) {
                continue;
            }

            int leftPartAnswer = longestSubstringWithAtLeastKRepeatingCharactersUtil(s, start, i - 1, k);
            int rightPartAnswer = longestSubstringWithAtLeastKRepeatingCharactersUtil(s, i + 1, end, k);

            return Math.max(leftPartAnswer, rightPartAnswer);
        }

        return (end - start + 1);
    }

    private static int longestSubstringWithAtLeastKRepeatingCharacters(String s, int k) {
        if (s.isEmpty()) {
            return 0;
        }

        return longestSubstringWithAtLeastKRepeatingCharactersUtil(s, 0, s.length() - 1, k);
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        String s = fr.next();
        int k = fr.nextInt();

        System.out.println(longestSubstringWithAtLeastKRepeatingCharacters(s, k));
    }
}

/********************************************************************************************************************************************************************/

// METHOD - 3 (SLIDING WINDOW)

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

    private static int findUniqueCharactersCount(String s) {
        int result = 0;
        boolean[] isPresent = new boolean[26];

        for (int i = 0; i < s.length(); i++) {
            int idx = s.charAt(i) - 'a';

            if (!isPresent[idx]) {
                result += 1;
            } else {
                isPresent[idx] = true;
            }
        }

        return result;
    }

    private static int longestSubstringWithAtLeastKRepeatingCharacters(String s, int k) {
        int totalUniqueCharacters = findUniqueCharactersCount(s);
        int result = 0;

        for (int uniqueCharacters = 1; uniqueCharacters <= totalUniqueCharacters; uniqueCharacters++) {
            int windowStart = 0, windowEnd = 0, uniqueCharactersInWindow = 0, uniqueCharactersInWindowWithAtLeastKFreq = 0;
            int[] count = new int[26];

            while (windowEnd < s.length()) {
                int idx = s.charAt(windowEnd) - 'a';

                // expand the sliding window
                if (uniqueCharactersInWindow <= uniqueCharacters) {
                    if (count[idx] == 0) {
                        uniqueCharactersInWindow += 1;
                    }

                    count[idx] += 1;

                    if (count[idx] == k) {
                        uniqueCharactersInWindowWithAtLeastKFreq += 1;
                    }

                    windowEnd += 1;
                }

                // shrink the sliding window
                else {
                    idx = s.charAt(windowStart) - 'a';

                    if (count[idx] == k) {
                        uniqueCharactersInWindowWithAtLeastKFreq -= 1;
                    }

                    count[idx] -= 1;

                    if (count[idx] == 0) {
                        uniqueCharactersInWindow -= 1;
                    }

                    windowStart += 1;
                }

                if ((uniqueCharactersInWindow == uniqueCharacters) && (uniqueCharactersInWindow == uniqueCharactersInWindowWithAtLeastKFreq)) {
                    result = Math.max(result, windowEnd - windowStart);
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        String s = fr.next();
        int k = fr.nextInt();

        System.out.println(longestSubstringWithAtLeastKRepeatingCharacters(s, k));
    }
}