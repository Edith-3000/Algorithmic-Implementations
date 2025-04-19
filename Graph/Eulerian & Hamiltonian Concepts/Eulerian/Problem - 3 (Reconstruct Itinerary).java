// Problem: https://leetcode.com/problems/reconstruct-itinerary/description/

/****************************************************************************************************************************************************/

import java.util.*;

class Solution {
    private Map<String, Stack<String>> createGraph(List<List<String>> tickets) {
        Map<String, List<String>> map = new HashMap<>();

        for (List<String> ticket: tickets) {
            String from = ticket.get(0);
            String to = ticket.get(1);

            List<String> neighbours = map.getOrDefault(from, new ArrayList<>());
            neighbours.add(to);

            map.put(from, neighbours);
        }

        Map<String, Stack<String>> graph = new HashMap<>();

        for (Map.Entry<String, List<String>> entry: map.entrySet()) {
            List<String> neighbours = entry.getValue();
            Collections.sort(neighbours);

            Stack<String> stack = new Stack<>();

            for (int i = neighbours.size() - 1; i >= 0; i--) {
                stack.push(neighbours.get(i));
            }

            graph.put(entry.getKey(), stack);
        }

        return graph;
    }

    private void dfs(String curNode, Map<String, Stack<String>> graph, List<String> path) {
        Stack<String> neighbours = graph.getOrDefault(curNode, new Stack<>());

        while (!neighbours.empty()) {
            String neighbour = neighbours.pop();
            dfs(neighbour, graph, path);
        }

        path.add(curNode);
    }

    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String, Stack<String>> graph = createGraph(tickets);

        List<String> path = new ArrayList<>();

        dfs("JFK", graph, path);

        Collections.reverse(path);

        return path;
    }
}