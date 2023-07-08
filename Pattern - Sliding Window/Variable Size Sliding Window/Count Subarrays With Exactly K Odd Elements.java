// Problem: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

// Reference: https://www.youtube.com/watch?v=O0bbpT710KA

/**************************************************************************************************************************************************************/

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

    // This method returns the #subarrays having AT-MOST k odd numbers
    public static int helper(int[] nums, int k) {
        int n = nums.length;

        int res = 0, oddCount = 0;
        int i = 0, j = 0;

        while(j < n) {
            if(nums[j] % 2 == 1) {
                oddCount += 1;
            }

            if(oddCount <= k) {
                res += (j - i + 1);
            }

            else {
                while(oddCount > k) {
                    if(nums[i] % 2 == 1) {
                        oddCount -= 1;
                    }

                    i += 1;
                }

                res += (j - i + 1);
            }

            j += 1;
        }

        return res;
    }

    public static int numberOfSubarrays(int[] nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n, k;
        n = fr.nextInt();
        k = fr.nextInt();

        int[] nums = new int[n];

        for(int i = 0; i < n; i++) {
            nums[i] = fr.nextInt();
        }

        System.out.println(numberOfSubarrays(nums, k));
    }
}
