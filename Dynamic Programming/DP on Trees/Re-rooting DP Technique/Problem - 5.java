/*
* Problem Description:
* A country can be represented as a graph with numberOfCities cities connected by numberOfCities - 1 unidirectional edges.
* The ith edge connects cities fromCities[i] to city toCities[i].

* If the roads were bi-directional, every node would be reachable from every other node. The resulting graph would be a tree.

* For each city i (1 <= i <= numberOfCities), find the minimum number of edges that must be reversed so that it is possible to 
* travel from City i to any other city using the directed edges.
* 
**************************************************************************************************************************************************************************

* Example 1:
* numberOfCities = 4
* fromCities = [1, 2, 3]
* toCities = [4, 4, 4]
*
* Expected Answer = [2, 2, 2, 3]
*
********************************************************************
*
* Example 2:
* numberOfCities = 3
* fromCities = [2, 2]
* toCities = [1, 3]
*
* Expected Answer = [1, 0, 1]
*
********************************************************************
*
* Example 3:
* numberOfCities = 4
* fromCities = [1, 2, 3]
* toCities = [2, 3, 4]
*
* Expected Answer = [0, 1, 2, 3]
*
********************************************************************
*
* Reference(s):
* https://chatgpt.com/share/697c81b4-6e60-8001-a94f-fc078508c08c - [https://chatgpt.com/c/697c80cc-13d4-8323-ad5f-992040a761d8]
* */

import java.util.*;

public class Solution {

    private static class Edge {
        int neighbor;
        int weight;

        Edge(int neighbor, int weight) {
            this.neighbor = neighbor;
            this.weight = weight;
        }
    }

    private static List<Edge>[] buildGraph(int numberOfCities, int[] fromCities, int[] toCities) {
        List<Edge>[] graph = new ArrayList[numberOfCities];

        for (int i = 0; i < numberOfCities; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < fromCities.length; i++) {
            int from = fromCities[i] - 1;
            int to = toCities[i] - 1;

            // Original edge with weight 0
            graph[from].add(new Edge(to, 0));
            // Reverse edge with weight 1
            graph[to].add(new Edge(from, 1));
        }

        return graph;
    }

    private static void dfs1(int node, List<Edge>[] graph, boolean[] visited, int[] dp) {
        visited[node] = true;

        for (Edge edge : graph[node]) {
            int neighbor = edge.neighbor;
            int weight = edge.weight;

            if (!visited[neighbor]) {
                dfs1(neighbor, graph, visited, dp);
                dp[node] += dp[neighbor] + weight;
            }
        }
    }

    private static void dfs2(int node, List<Edge>[] graph, boolean[] visited, int[] dp, int numberOfCities) {
        visited[node] = true;

        for (Edge edge : graph[node]) {
            int neighbor = edge.neighbor;
            int weight = edge.weight;

            if (!visited[neighbor]) {
                // Re-rooting formula
                dp[neighbor] = dp[node] + (weight == 0 ? 1 : -1);
                dfs2(neighbor, graph, visited, dp, numberOfCities);
            }
        }
    }

    private static int[] countReverseEdges(int numberOfCities, int[] fromCities, int[] toCities) {
        List<Edge>[] graph = buildGraph(numberOfCities, fromCities, toCities);

        int[] dp = new int[numberOfCities];
        boolean[] visited = new boolean[numberOfCities];

        // First DFS to calculate dp values for root node (0)
        dfs1(0, graph, visited, dp);

        // Reset visited array for second DFS
        Arrays.fill(visited, false);

        // Second DFS to re-root the tree and calculate dp values for all nodes
        dfs2(0, graph, visited, dp, numberOfCities);

        return dp;
    }

    // --------------------------------------------------
    // MAIN METHOD FOR TESTING (STATIC ARRAYS)
    // --------------------------------------------------
    public static void main(String[] args) {

        int numberOfCities = 4;

        int[] fromCities = {1, 2, 3};
        int[] toCities   = {4, 4, 4};

        // int numberOfCities = 3;

        // int[] fromCities = {2, 2};
        // int[] toCities   = {1, 3};

        // int numberOfCities = 4;

        // int[] fromCities = {1, 2, 3};
        // int[] toCities   = {2, 3, 4};

        int[] result = countReverseEdges(numberOfCities, fromCities, toCities);

        System.out.println("Minimum edges to be reversed for each node ==> ");

        for (int i = 0; i < result.length; i++) {
            System.out.println("City " + (i + 1) + " : " + result[i]);
        }
    }
}