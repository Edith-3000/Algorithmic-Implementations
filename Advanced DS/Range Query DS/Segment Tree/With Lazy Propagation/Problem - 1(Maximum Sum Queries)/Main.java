// Problem: https://leetcode.com/problems/maximum-sum-queries/description/

// Reference: https://www.youtube.com/watch?v=XU7Wu70XpBw&ab_channel=codingMohan

/*************************************************************************************************************************************************************/

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

    static int lowerBound(List<Pair<Integer, Integer>> list, int num) {
        int n = list.size();

        int L = 0, R = n - 1, res = -1;

        while(L <= R) {
            int mid = L + ((R - L) >> 1);
            if(list.get(mid).getKey() < num) L = mid + 1;
            else {
                res = mid;
                R = mid - 1;
            }
        }

        return res;
    }

    static int[] maximumSumQueries(int[] nums1, int[] nums2, int[][] queries) {
        int n = nums1.length, q = queries.length;

        List<Pair<Integer, Integer>> list1 = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            list1.add(new Pair<>(nums1[i], i));
        }

        list1.sort(((o1, o2) -> Integer.compare(o1.getKey(), o2.getKey())));

        List<Pair<Integer, Integer>> list2 = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            int idx = list1.get(i).getValue();
            list2.add(new Pair<>(nums2[idx], idx));
        }

        Map<Integer, Integer> indexMap = new HashMap<>();
        for(int i = 0; i < n; i++) {
            indexMap.put(list1.get(i).getValue(), i);
        }

        List<Pair<Integer, Integer>> list3 = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            list3.add(new Pair<>(nums2[i], i));
        }

        list3.sort(((o1, o2) -> Integer.compare(o2.getKey(), o1.getKey())));

        int[][] sortedQueries = new int[q][3];
        for(int i = 0; i < q; i++) {
            sortedQueries[i][0] = queries[i][0];
            sortedQueries[i][1] = queries[i][1];
            sortedQueries[i][2] = i;
        }

        Arrays.sort(sortedQueries, ((o1, o2) -> Integer.compare(o2[1], o1[1])));

        int[] a = new int[n];
        Arrays.fill(a, Integer.MIN_VALUE);
        int list3Idx = 0;

        SegmentTree segmentTree = new SegmentTree(n);
        segmentTree.build(0, n - 1, 1, a);

        int[] res = new int[q];

        for(int k = 0; k < q; k++) {
            int x = sortedQueries[k][0], y = sortedQueries[k][1];

            while((list3Idx < n) && (list3.get(list3Idx).getKey() >= y)) {
                int idx = indexMap.get(list3.get(list3Idx).getValue());

                int list1Value = list1.get(idx).getKey();
                int list2Value = list2.get(idx).getKey();

                int delta = list1Value + list2Value;
                a[idx] = delta;
                segmentTree.pointUpdate(0, n - 1, idx, delta, 1);

                list3Idx += 1;
            }

            int lbIndex = lowerBound(list1, x);
            if(lbIndex == -1) {
                res[sortedQueries[k][2]] = -1;
                continue;
            }

            int ans = segmentTree.rangeQuery(0, n - 1, lbIndex, n - 1, 1);

            if(ans == Integer.MIN_VALUE) res[sortedQueries[k][2]] = -1;
            else res[sortedQueries[k][2]] = ans;
        }

        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n, q;
        n = fr.nextInt();
        q = fr.nextInt();

        int[] nums1 = new int[n];
        int[] nums2 = new int[n];

        for(int i = 0; i < n; i++) {
            nums1[i] = fr.nextInt();
        }

        for(int i = 0; i < n; i++) {
            nums2[i] = fr.nextInt();
        }

        int[][] queries = new int[q][2];

        for(int i = 0; i < q; i++) {
            for(int j = 0; j < 2; j++) {
                queries[i][j] = fr.nextInt();
            }
        }

        int[] res = maximumSumQueries(nums1, nums2, queries);

        for(int x: res) {
            System.out.print(x + " ");
        }
    }
}
