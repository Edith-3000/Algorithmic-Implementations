// Problem: https://leetcode.com/problems/valid-arrangement-of-pairs/description/

// Reference(s): https://youtu.be/ElXqjhZoUC0
//               https://youtu.be/_YbIBChaknQ?t=1850

/*****************************************************************************************************************************************************/

import java.util.*;

class Solution {
    private void createGraph(int[][] pairs, Map<Integer, Stack<Integer>> graph, Map<Integer, Integer> inDegree, Map<Integer, Integer> outDegree) {
        for (int[] pair: pairs) {
            int u = pair[0];
            int v = pair[1];

            Stack<Integer> neighbours = graph.getOrDefault(u, new Stack<>());
            neighbours.push(v);
            graph.put(u, neighbours);

            outDegree.put(u, outDegree.getOrDefault(u, 0) + 1);
            inDegree.put(v, inDegree.getOrDefault(v, 0) + 1);
        }
    }

    private int findStartNode(Map<Integer, Integer> inDegree, Map<Integer, Integer> outDegree) {
        int startNode = -1;

        for (Map.Entry<Integer, Integer> entry: outDegree.entrySet()) {
            int node = entry.getKey();
            int nodeOutDegree = entry.getValue();

            if ((nodeOutDegree - inDegree.getOrDefault(node, 0)) == 1) {
                return node; // Euler path exists but not Euler Circuit
            }

            if (nodeOutDegree > 0) {
                startNode = node;
            }
        }

        return startNode; // Euler circuit exists
    }

    private void dfs(int cur, Map<Integer, Stack<Integer>> graph, List<int[]> eulerPath) {
        Stack<Integer> neighbours = graph.getOrDefault(cur, new Stack<>());

        while (!neighbours.empty()) {
            int nbr = neighbours.pop();
            dfs(nbr, graph, eulerPath);
            eulerPath.add(new int[]{cur, nbr});
        }
    }

    public int[][] validArrangement(int[][] pairs) {
        Map<Integer, Stack<Integer>> graph = new HashMap<>();
        Map<Integer, Integer> inDegree = new HashMap<>();
        Map<Integer, Integer> outDegree = new HashMap<>();

        createGraph(pairs, graph, inDegree, outDegree);

        // Euler path is guaranteed in this problem
        int startNode = findStartNode(inDegree, outDegree);

        List<int[]> eulerPath = new ArrayList<>();
        dfs(startNode, graph, eulerPath);

        Collections.reverse(eulerPath);

        int[][] res = new int[eulerPath.size()][2];

        for (int i = 0; i < eulerPath.size(); i++) {
            res[i][0] = eulerPath.get(i)[0];
            res[i][1] = eulerPath.get(i)[1];
        }

        return res;
    }
}