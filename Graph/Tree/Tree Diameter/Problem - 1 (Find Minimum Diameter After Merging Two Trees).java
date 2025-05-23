// Problem: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/

// Reference: https://youtu.be/uz_WISpySFs

/*****************************************************************************************************************************************************/

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    private static List<List<Integer>> createGraph(int[][] edges) {
        int n = edges.length + 1;
        List<List<Integer>> graph = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge: edges) {
            int x = edge[0];
            int y = edge[1];

            graph.get(x).add(y);
            graph.get(y).add(x);
        }

        return graph;
    }

    // findMaxDistanceNodeAndDistance is a BFS helper function to find the maximum distance node and its distance from the src [node, distance]
    private static int[] findMaxDistanceNodeAndDistance(int src, int n, List<List<Integer>> graph) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];

        queue.add(src);
        visited[src] = true;

        int maxDistanceNode = src;
        int maxDistance = 0;

        while (!queue.isEmpty()) {
            int queueSize = queue.size();

            while (queueSize-- > 0) {
                int cur = queue.poll();
                maxDistanceNode = cur;

                for (int nbr: graph.get(cur)) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        queue.add(nbr);
                    }
                }
            }

            if (!queue.isEmpty()) {
                maxDistance += 1;
            }
        }

        return new int[]{maxDistanceNode, maxDistance};
    }

    private static int treeDiameter(int n, List<List<Integer>> graph) {
        // First BFS to find the farthest node from node any arbitrary node (here 0 taken)
        int[] firstBFSResult = findMaxDistanceNodeAndDistance(0, n, graph);
        int farthestNode = firstBFSResult[0];

        // Second BFS from the farthest node to get the diameter
        int[] secondBFSResult = findMaxDistanceNodeAndDistance(farthestNode, n, graph);
        int diameter = secondBFSResult[1];

        return diameter;
    }

    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        int n1 = edges1.length + 1;
        int n2 = edges2.length + 1;

        List<List<Integer>> graph1 = createGraph(edges1);
        List<List<Integer>> graph2 = createGraph(edges2);

        int diameter1 = treeDiameter(n1, graph1);
        int diameter2 = treeDiameter(n2, graph2);

        int tentativeMergeDiameter = ((diameter1 + 1) / 2) + ((diameter2 + 1) / 2) + 1;

        int finalDiameter = Math.max(diameter1, Math.max(diameter2, tentativeMergeDiameter));

        return finalDiameter;
    }
}
