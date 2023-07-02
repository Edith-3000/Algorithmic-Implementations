public class SegmentTree {
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
}
