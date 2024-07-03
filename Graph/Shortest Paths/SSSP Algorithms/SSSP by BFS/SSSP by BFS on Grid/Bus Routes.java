// Problem: https://leetcode.com/problems/bus-routes/description/

// Reference: https://youtu.be/WhuiqhMXhxM

/*******************************************************************************************************************/

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        int buses = routes.length;
        int busStops = -1;

        for (int i = 0; i < routes.length; i++) {
            for (int j = 0; j < routes[i].length; j++) {
                busStops = Math.max(busStops, routes[i][j]);
            }
        }

        busStops = Math.max(busStops, Math.max(source, target));

        List<List<Integer>> graph = new ArrayList<>();

        for (int i = 0; i <= busStops; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < buses; i++) {
            for (int j = 0; j < routes[i].length; j++) {
                int busStop = routes[i][j];

                graph.get(busStop).add(i);
            }
        }

        int busesNeeded = 0;

        boolean[] busStopVisited = new boolean[busStops + 1];
        boolean[] busVisited = new boolean[buses];

        busStopVisited[source] = true;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(source);

        while (!queue.isEmpty()) {
            int queueSize = queue.size();

            while (queueSize-- > 0) {
                int currentBusStop = queue.poll();

                if (currentBusStop == target) {
                    return busesNeeded;
                }

                for (int bus: graph.get(currentBusStop)) {
                    if (busVisited[bus]) {
                        continue;
                    }

                    for (int busStop: routes[bus]) {
                        if (busStopVisited[busStop]) {
                            continue;
                        }

                        busStopVisited[busStop] = true;
                        queue.add(busStop);
                    }

                    busVisited[bus] = true;
                }
            }

            busesNeeded += 1;
        }

        return -1;
    }
}