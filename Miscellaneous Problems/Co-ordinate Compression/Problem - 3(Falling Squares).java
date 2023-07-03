// Problem: https://leetcode.com/problems/falling-squares/description/

// Reference: https://leetcode.com/problems/falling-squares/editorial/

/*****************************************************************************************************************************************************************/

// METHOD - 1 [O(n^2)]

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

    // NOTE: ids are 0-based indexed
    static class CoordinateCompression {
        // id[u] = v ==> compressed co-ordinate of u is v
        // rid[v] = u ==> v is the compressed co-ordinate of u
        public Map<Integer, Integer> id, rid;

        public CoordinateCompression() {
            id = new TreeMap<>();
            rid = new TreeMap<>();
        }

        public void compress(List<Integer> list) {
            for(int ele: list) {
                id.put(ele, -1);
            }

            int order = -1;

            for(Map.Entry<Integer, Integer> entry: id.entrySet()) {
                entry.setValue(++order);
                rid.put(entry.getValue(), entry.getKey());
            }
        }
    }

    static int queryHeights(int L, int R, List<Integer> maxHeight) {
        int res = 0;

        for(int i = L; i <= R; i++) {
            res = Math.max(res, maxHeight.get(i));
        }

        return res;
    }

    static void updateHeights(int L, int R, int h, List<Integer> maxHeight) {
        for(int i = L; i <= R; i++) {
            maxHeight.set(i, h);
        }
    }

    static List<Integer> fallingSquares(int[][] positions) {
        int n = positions.length;

        List<Integer> list = new ArrayList<>();
        for (int[] position : positions) {
            // the #co-ordinates a square covers = side length of that square, that's why -1 is done
            // https://leetcode.com/problems/falling-squares/editorial/comments/1624292
            list.add(position[0]);
            list.add(position[0] + position[1] - 1);
        }

        CoordinateCompression cc = new CoordinateCompression();
        cc.compress(list);

        int m = cc.id.size();

        List<Integer> maxHeight = new ArrayList<>();
        for(int i = 0; i < m; i++) {
            maxHeight.add(0);
        }

        List<Integer> res = new ArrayList<>();
        int bestHeight = 0;

        for(int i = 0; i < n; i++) {
            int L = cc.id.get(positions[i][0]);
            int R = cc.id.get(positions[i][0] + positions[i][1] - 1);

            int mxHeightInRange = queryHeights(L, R, maxHeight);
            int h = mxHeightInRange + positions[i][1];

            bestHeight = Math.max(bestHeight, h);
            res.add(bestHeight);

            updateHeights(L, R, h, maxHeight);
        }

        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[][] positions = new int[n][2];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                positions[i][j] = fr.nextInt();
            }
        }

        System.out.println(fallingSquares(positions));
    }
}

/*****************************************************************************************************************************************************************/

// METHOD - 2 [O(n x log₂(n))]

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

    public static class SegmentTree {
        // data members ==>

        // size of array[] for which segment tree will be build
        int n;

        // underlying array used for representing segment tree in
        // linear space. An array of size n can have approx. around
        // (4 * n + 1) nodes in the corresponding segment tree
        int[] t;

        // array to store the lazy values for all the segment tree nodes
        int[] lazy;

        // member functions ===>

        // constructor
        public SegmentTree(int n) {
            this.n = n;
            t = new int[(4 * n) + 1];
            lazy = new int[(4 * n) + 1];
        }

        // build t[] function where,
        // t[ind] is responsible for storing result corresponding to segment a[tl......tr]
        void build(int tl, int tr, int ind, int[] a) {
            // base case
            if(tl == tr) {
                t[ind] = a[tl];
                return;
            }

            // similar to postorder traversal
            int m = (tl + tr) / 2;

            // compute results for child nodes & after it for the parent node i.e. ind
            build(tl, m, 2 * ind, a);
            build(m + 1, tr, 2 * ind + 1, a);
            t[ind] = Math.max(t[2 * ind], t[2 * ind + 1]);

            return;
        }

        // The overlaps are of [tl, tr] with respect to [ql, qr]. tl, tr, ql, qr are 0-based indexed
        int rangeQuery(int tl, int tr, int ql, int qr, int ind) {
            // before going down resolve the lazy value of the current node if it exists
            if(lazy[ind] != 0) {
                // include lazy value
                t[ind] = lazy[ind];

                // if this node is non-leaf node pass it's lazy value to it's children
                if(tl != tr) {
                    lazy[2 * ind] = lazy[ind];
                    lazy[2 * ind + 1] = lazy[ind];
                }

                // clear the lazy value of current node
                lazy[ind] = 0;
            }

            // base case(s)
            // Case 1: complete overlap
            if((tl >= ql) && (tr <= qr)) {
                return t[ind];
            }

            // Case 2: no overlap
            if((tl > qr) || (tr < ql)) {
                return Integer.MIN_VALUE;
            }

            // Recursive case
            // Case 3: partial overlap
            int m = (tl + tr) / 2;
            int lf = rangeQuery(tl, m, ql, qr, 2 * ind);
            int rg = rangeQuery(m + 1, tr, ql, qr, 2 * ind + 1);

            return Math.max(lf, rg);
        }

        // p is the index in a[] at which update is to be done
        void pointUpdate(int tl, int tr, int p, int delta, int ind) {
            // base case(s)
            // case to handle when p is out of bounds of the current segment
            if((p < tl) || (p > tr)) {
                return;
            }

            // in leaf node, perform update
            if(tl == tr) {
                t[ind] = delta;
                return;
            }

            int m = (tl + tr) / 2;
            pointUpdate(tl, m, p, delta, 2 * ind);
            pointUpdate(m + 1, tr, p, delta, 2 * ind + 1);
            t[ind] = Math.max(t[2 * ind], t[2 * ind + 1]);

            return;
        }

        // The overlaps are of [tl, tr] with respect to [l, r], tl, tr, l, r are 0-based indexed
        public void rangeUpdate(int tl, int tr, int l, int r, int delta, int ind) {
            // before going down resolve the lazy value of the current node if it exists
            if(lazy[ind] != 0) {
                // include lazy value
                t[ind] = lazy[ind];

                // if this node is non-leaf node pass it's lazy value to it's children
                if(tl != tr) {
                    lazy[2 * ind] = lazy[ind];
                    lazy[2 * ind + 1] = lazy[ind];
                }

                // clear the lazy value of current node
                lazy[ind] = 0;
            }

            // base case(s)

            // Case 1: no overlap
            if((tl > r) || (tr < l)) {
                return;
            }

            // Case 2: complete overlap (this is the case where code is being optimized as we are returning
            //         from here w/o actually updating all the nodes in the subtree rooted at node
            //         ind, instead their changed value is just being stored in the lazy array)
            if((tl >= l) && (tr <= r)) {
                t[ind] = delta;

                // if this node is non-leaf node pass it's lazy value to it's children
                if(tl != tr) {
                    lazy[2 * ind] = delta;
                    lazy[2 * ind + 1] = delta;
                }

                return;
            }

            // recursive case (Case 3: partial overlap)
            int m = (tl + tr)/2;
            rangeUpdate(tl, m, l, r, delta, 2 * ind);
            rangeUpdate(m + 1, tr, l, r, delta, 2 * ind + 1);
            t[ind] = Math.max(t[2 * ind], t[2 * ind + 1]);

            return;
        }
    }

    // NOTE: ids are 0-based indexed
    static class CoordinateCompression {
        // id[u] = v ==> compressed co-ordinate of u is v
        // rid[v] = u ==> v is the compressed co-ordinate of u
        public Map<Integer, Integer> id, rid;

        public CoordinateCompression() {
            id = new TreeMap<>();
            rid = new TreeMap<>();
        }

        public void compress(List<Integer> list) {
            for(int ele: list) {
                id.put(ele, -1);
            }

            int order = -1;

            for(Map.Entry<Integer, Integer> entry: id.entrySet()) {
                entry.setValue(++order);
                rid.put(entry.getValue(), entry.getKey());
            }
        }
    }

    static List<Integer> fallingSquares(int[][] positions) {
        int n = positions.length;

        List<Integer> list = new ArrayList<>();
        for (int[] position : positions) {
            // the #co-ordinates a square covers = side length of that square, that's why -1 is done
            // https://leetcode.com/problems/falling-squares/editorial/comments/1624292
            list.add(position[0]);
            list.add(position[0] + position[1] - 1);
        }

        CoordinateCompression cc = new CoordinateCompression();
        cc.compress(list);

        int m = cc.id.size();

        int[] maxHeight = new int[m];

        SegmentTree segmentTree = new SegmentTree(m);
        segmentTree.build(0, m - 1, 1, maxHeight);

        List<Integer> res = new ArrayList<>();
        int bestHeight = 0;

        for(int i = 0; i < n; i++) {
            int L = cc.id.get(positions[i][0]);
            int R = cc.id.get(positions[i][0] + positions[i][1] - 1);

            int mxHeightInRange = segmentTree.rangeQuery(0, m - 1, L, R, 1);
            int h = mxHeightInRange + positions[i][1];

            bestHeight = Math.max(bestHeight, h);
            res.add(bestHeight);

            segmentTree.rangeUpdate(0, m - 1, L, R, h, 1);
        }

        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[][] positions = new int[n][2];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                positions[i][j] = fr.nextInt();
            }
        }

        System.out.println(fallingSquares(positions));
    }
}
