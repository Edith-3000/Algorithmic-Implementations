// Problem: https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/description/

// Reference: https://youtu.be/R3YJP_gxZqc

/*********************************************************************************************************************************************/

/* # NOTE: As mentioned in the follow-ups of the reference video, this problem's concept can be very well
           extended to more than 2 arrays or finding the longest non-decreasing subsequence from by choosing
           elements from 2 or more arrays.
*/

/*********************************************************************************************************************************************/

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

    static int[][] dp;

    static void initDP(int n) {
        dp = new int[2][n];

        Arrays.fill(dp[0], -1);
        Arrays.fill(dp[1], -1);
    }

    static int helper(int arrIdx, int curIdx, int n, int[] nums1, int[] nums2) {
        // Base case(s)
        if(curIdx == n) {
            return 0;
        }

        // Check if already calculated
        int res = dp[arrIdx][curIdx];
        if(res != -1) {
            return res;
        }

        res = 0;

        if(arrIdx == 0) {
            if(nums1[curIdx - 1] <= nums1[curIdx]) {
                res = Math.max(res, 1 + helper(0, curIdx + 1, n, nums1, nums2));
            }

            if(nums1[curIdx - 1] <= nums2[curIdx]) {
                res = Math.max(res, 1 + helper(1, curIdx + 1, n, nums1, nums2));
            }
        }

        else {
            if(nums2[curIdx - 1] <= nums1[curIdx]) {
                res = Math.max(res, 1 + helper(0, curIdx + 1, n, nums1, nums2));
            }

            if(nums2[curIdx - 1] <= nums2[curIdx]) {
                res = Math.max(res, 1 + helper(1, curIdx + 1, n, nums1, nums2));
            }
        }

        return dp[arrIdx][curIdx] = res;
    }

    public static int maxNonDecreasingLength(int[] nums1, int[] nums2) {
        int n = nums1.length;

        initDP(n);

        int res = 1;

        for(int i = 0; i < n; i++) {
            res = Math.max(res, 1 + helper(0, i + 1, n, nums1, nums2));
            res = Math.max(res, 1 + helper(1, i + 1, n, nums1, nums2));
        }

        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[] nums1 = new int[n];
        for(int i = 0; i < n; i++) {
            nums1[i] = fr.nextInt();
        }

        int[] nums2 = new int[n];
        for(int i = 0; i < n; i++) {
            nums2[i] = fr.nextInt();
        }

        System.out.println(maxNonDecreasingLength(nums1, nums2));
    }
}

// Time Complexity: O(n + (2 x n)) ≡ O(n)
