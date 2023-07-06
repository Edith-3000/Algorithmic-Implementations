// Problem: https://leetcode.com/problems/continuous-subarrays/description/

// Reference: https://www.youtube.com/watch?v=tHPMTQDArls

/*******************************************************************************************************************************************************************/

// NOTE: This approach wasn't getting an AC on LeetCode since the runtime is exceeding little bit over 10^7
//       operations per second, but it's worth learning this Binary Search with Segment Tree approach.

import javafx.util.Pair;

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

    // Segment Tree to return Minimum and Maximum in one go for a given range
    public static class SegmentTree {
        // data members ==>

        // size of array[] for which segment tree will be build
        int n;

        // underlying array used for representing segment tree in
        // linear space. An array of size n can have approx. around
        // (4 * n + 1) nodes in the corresponding segment tree
        int[][] t;

        // member functions ===>

        // constructor
        public SegmentTree(int n) {
            this.n = n;
            t = new int[2][(4 * n) + 1];
        }

        // build t[][] function where,
        // t[0][ind] and t[1][ind] are responsible for storing result corresponding to segment a[tl......tr]
        void build(int tl, int tr, int ind, int[] a) {
            // base case
            if(tl == tr) {
                t[0][ind] = a[tl];
                t[1][ind] = a[tl];
                return;
            }

            // similar to postorder traversal
            int m = (tl + tr) / 2;

            // compute results for child nodes & after it for the parent node i.e. ind
            build(tl, m, 2 * ind, a);
            build(m + 1, tr, 2 * ind + 1, a);
            t[0][ind] = Math.min(t[0][2 * ind], t[0][2 * ind + 1]);
            t[1][ind] = Math.max(t[1][2 * ind], t[1][2 * ind + 1]);

            return;
        }

        // The overlaps are of [tl, tr] with respect to [ql, qr]. tl, tr, ql, qr are 0-based indexed
        Pair<Integer, Integer> rangeQuery(int tl, int tr, int ql, int qr, int ind) {
            // base case(s)
            // Case 1: complete overlap
            if((tl >= ql) && (tr <= qr)) {
                return new Pair<>(t[0][ind], t[1][ind]);
            }

            // Case 2: no overlap
            if((tl > qr) || (tr < ql)) {
                return new Pair<>(Integer.MAX_VALUE, Integer.MIN_VALUE);
            }

            // Recursive case
            // Case 3: partial overlap
            int m = (tl + tr) / 2;
            Pair<Integer, Integer> lf = rangeQuery(tl, m, ql, qr, 2 * ind);
            Pair<Integer, Integer> rg = rangeQuery(m + 1, tr, ql, qr, 2 * ind + 1);

            return new Pair<>(Math.min(lf.getKey(), rg.getKey()), Math.max(lf.getValue(), rg.getValue()));
        }
    }

    static int bestRightIndex(int L, int R, int idx, int n, SegmentTree segmentTree) {
        int res = idx;

        while(L <= R) {
            int mid = L + ((R - L) >> 1);

            Pair<Integer, Integer> pair = segmentTree.rangeQuery(0, n - 1, idx, mid, 1);
            if(pair.getValue() - pair.getKey() <= 2) {
                res = mid;
                L = mid + 1;
            }

            else {
                R = mid - 1;
            }
        }

        return res;
    }

    public static long continuousSubarrays(int[] nums) {
        int n = nums.length;

        SegmentTree segmentTree = new SegmentTree(n);
        segmentTree.build(0, n - 1, 1, nums);

        long res = 0;

        for(int i = 0; i < n; i++) {
            int j = bestRightIndex(i, n - 1, i, n, segmentTree);
            res += (j - i + 1);
        }

        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();
        int[] nums = new int[n];

        for(int i = 0; i < n; i++) {
            nums[i] = fr.nextInt();
        }

        System.out.println(continuousSubarrays(nums));
    }
}

// Time Complexity: [O(n x (log₂(n))^2)]