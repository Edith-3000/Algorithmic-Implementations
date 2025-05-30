// Problem: https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/description/

// Reference(s): https://youtu.be/cxzwBjbIx4E

/********************************************************************************************************************/


import java.util.ArrayList;
import java.util.List;

class Solution {
    private void createGraph(int n, int[][] edges, List<List<Integer>> outGraph, List<List<Integer>> inGraph) {
        for (int i = 0; i < n; i++) {
            outGraph.add(new ArrayList<>());
            inGraph.add(new ArrayList<>());
        }

        for (int[] edge: edges) {
            int x = edge[0];
            int y = edge[1];

            outGraph.get(x).add(y);
            inGraph.get(y).add(x);
        }
    }

    private void dfs1(int cur, int par, int[] dp1, List<List<Integer>> outGraph, List<List<Integer>> inGraph) {
        for (int nbr: outGraph.get(cur)) {
            if (nbr == par) {
                continue;
            }

            dfs1(nbr, cur, dp1, outGraph, inGraph);

            dp1[cur] += dp1[nbr];
        }

        for (int nbr: inGraph.get(cur)) {
            if (nbr == par) {
                continue;
            }

            dfs1(nbr, cur, dp1, outGraph, inGraph);

            dp1[cur] += (1 + dp1[nbr]);
        }
    }

    private void dfs2(int cur, int par, int[] dp1, int[] dp2, List<List<Integer>> outGraph, List<List<Integer>> inGraph) {
        // value for cur node
        dp2[cur] = dp1[cur];

        for (int nbr: outGraph.get(cur)) {
            if (nbr == par) {
                continue;
            }

            // shifting the root from cur root to its child nbr, it involves 2 steps ===>
            // 1. remove the contribution of nbr in answer of cur
            // 2. so now nbr becomes parent of cur, so add contribution of cur in answer of nbr
            dp1[cur] -= dp1[nbr];
            dp1[nbr] += (1 + dp1[cur]);

            // recursively calculating values for child nodes
            dfs2(nbr, cur, dp1, dp2, outGraph, inGraph);

            // rolling back the changes done previously
            // 1. remove the contribution of cur in answer of nbr
            // 2. add contribution of nbr in answer of cur
            dp1[nbr] -= (1 + dp1[cur]);
            dp1[cur] += dp1[nbr];
        }

        for (int nbr: inGraph.get(cur)) {
            if (nbr == par) {
                continue;
            }

            // shifting the root from cur root to its child nbr, it involves 2 steps ===>
            // 1. remove the contribution of nbr in answer of cur
            // 2. so now nbr becomes parent of cur, so add contribution of cur in answer of nbr
            dp1[cur] -= (1 + dp1[nbr]);
            dp1[nbr] += dp1[cur];

            // recursively calculating values for child nodes
            dfs2(nbr, cur, dp1, dp2, outGraph, inGraph);

            // rolling back the changes done previously
            // 1. remove the contribution of cur in answer of nbr
            // 2. add contribution of nbr in answer of cur
            dp1[nbr] -= dp1[cur];
            dp1[cur] += (1 + dp1[nbr]);
        }
    }

    public int[] minEdgeReversals(int n, int[][] edges) {
        List<List<Integer>> outGraph = new ArrayList<>(), inGraph = new ArrayList<>();

        createGraph(n, edges, outGraph, inGraph);

        // dp1[i] = answer for node 'i' if we consider only the subtree rooted at node 'i'
        //          and all the edges above this subtree are not taken into account
        int[] dp1 = new int[n];

        // dp2[i] = final answer for node 'i' if we consider the tree rooted at node 'i'
        int[] dp2 = new int[n];

        dfs1(0, -1, dp1, outGraph, inGraph);
        dfs2(0, -1, dp1, dp2, outGraph, inGraph);

        return dp2;
    }
}
