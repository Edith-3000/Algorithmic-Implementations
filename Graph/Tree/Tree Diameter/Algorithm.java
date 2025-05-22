// Problem: https://cses.fi/alon/task/1131/
//          https://leetcode.com/problems/tree-diameter/description/

// Reference(s): https://youtu.be/na3LE8CBYLo

/****************************************************************************************************************************************************/

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

    // treeDiameter returns diameter of a tree using two BFS calls
    // NOTE: 0-based indexing is considered
    private static int treeDiameter(int[][] edges) {
        // n = count of nodes in graph(tree)
        int n = edges.length + 1;

        // Build adjacency list
        List<List<Integer>> graph = createGraph(edges);

        // First BFS to find the farthest node from node any arbitrary node (here 0 taken)
        int[] firstBFSResult = findMaxDistanceNodeAndDistance(0, n, graph);
        int farthestNode = firstBFSResult[0];

        // Second BFS from the farthest node to get the diameter
        int[] secondBFSResult = findMaxDistanceNodeAndDistance(farthestNode, n, graph);
        int diameter = secondBFSResult[1];

        return diameter;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[][] edges = new int[n][2];

        for (int i = 0; i < (n - 1); i++) {
            edges[i][0] = fr.nextInt();
            edges[i][1] = fr.nextInt();
        }

        System.out.println(treeDiameter(edges));
    }
}
