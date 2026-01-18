/*
* Problem Description:
* The country of Hackerland is depicted as a graph with numberOfCities cities numbered from 1 to numberOfCities.
* These cities are interconnected by bi-directional roads, where the ith road connects city from fromCities[i] to city toCities[i],
* and the fuel required to travel this road is roadFuelCost[i] units.
* Vehicles in Hackerland have unlimited fuel capacity, and the cost of one unit of fuel in the ith city is given by fuelPrice[i].
* Any amount of fuel can be purchased in any city.
*
* Given two cities A and B (1 <= A, B <= numberOfCities), determine the minimum cost to travel from city A to city B.
* If travel between these cities is impossible return -1.
* 
**************************************************************************************************************************************************************************

* Example 1:
* numberOfCities = 5
* fromCities = [4, 5, 4, 1, 3, 4, 4]
* toCities = [1, 3, 5, 5, 1, 2, 3]
* roadFuelCost = [1, 1, 8, 1, 3, 9, 5]
* fuelPrice = [9, 11, 3, 2, 10]
* sourceCity = 3
* destinationCity = 2
*
* Expected Answer = 27
*
********************************************************************
*
* Example 2:
* numberOfCities = 4
* fromCities = [1, 2, 2]
* toCities = [2, 3, 4]
* roadFuelCost = [3, 1, 7]
* fuelPrice = [3, 6, 2, 2]
* sourceCity = 1
* destinationCity = 4
*
* Expected Answer = 28
*
********************************************************************
*
* Example 3:
* numberOfCities = 5
* fromCities = [2, 4, 2, 5]
* toCities = [3, 1, 5, 3]
* roadFuelCost = [8, 4, 8, 2]
* fuelPrice = [9, 5, 9, 6, 3]
* sourceCity = 2
* destinationCity = 4
*
* Expected Answer = -1
*
********************************************************************
*
* Reference(s):
* https://chatgpt.com/share/696c6f86-1504-8001-98f8-f39e88e1195a - [https://chatgpt.com/c/696c6d8b-5a40-8320-b09e-c839fd062524]
* */

import java.util.*;

public class MinimumFuelCost {

    static class State {
        long totalCost;
        int currentCity;
        int cheapestFuelCity;

        State(long totalCost, int currentCity, int cheapestFuelCity) {
            this.totalCost = totalCost;
            this.currentCity = currentCity;
            this.cheapestFuelCity = cheapestFuelCity;
        }
    }

    public static long getMinCost(
            int numberOfCities,
            int[] fromCities,
            int[] toCities,
            int[] roadFuelCost,
            int[] fuelPrice,
            int sourceCity,
            int destinationCity
    ) {

        sourceCity--;        // convert to 0-based
        destinationCity--;

        List<List<int[]>> adjacencyList = new ArrayList<>();
        for (int i = 0; i < numberOfCities; i++) {
            adjacencyList.add(new ArrayList<>());
        }

        for (int i = 0; i < fromCities.length; i++) {
            int from = fromCities[i] - 1;
            int to = toCities[i] - 1;
            int fuelNeeded = roadFuelCost[i];

            adjacencyList.get(from).add(new int[]{to, fuelNeeded});
            adjacencyList.get(to).add(new int[]{from, fuelNeeded});
        }

        long INF = (long) 1e18;
        long[][] minCost = new long[numberOfCities][numberOfCities];

        for (int i = 0; i < numberOfCities; i++) {
            Arrays.fill(minCost[i], INF);
        }

        PriorityQueue<State> minHeap = new PriorityQueue<>(
                Comparator.comparingLong(s -> s.totalCost)
        );

        minCost[sourceCity][sourceCity] = 0;
        minHeap.add(new State(0, sourceCity, sourceCity));

        while (!minHeap.isEmpty()) {
            State state = minHeap.poll();

            long totalCost = state.totalCost;
            int currentCity = state.currentCity;
            int cheapestFuelCity = state.cheapestFuelCity;

            if (totalCost > minCost[currentCity][cheapestFuelCity]) {
                continue;
            }

            for (int[] edge : adjacencyList.get(currentCity)) {
                int nextCity = edge[0];
                int fuelNeeded = edge[1];

                int newCheapestFuelCity = cheapestFuelCity;
                if (fuelPrice[nextCity] < fuelPrice[cheapestFuelCity]) {
                    newCheapestFuelCity = nextCity;
                }

                long newCost = totalCost + (long) fuelNeeded * fuelPrice[cheapestFuelCity];

                if (newCost < minCost[nextCity][newCheapestFuelCity]) {
                    minCost[nextCity][newCheapestFuelCity] = newCost;
                    minHeap.add(
                            new State(newCost, nextCity, newCheapestFuelCity)
                    );
                }
            }
        }

        long answer = INF;
        for (int i = 0; i < numberOfCities; i++) {
            answer = Math.min(answer, minCost[destinationCity][i]);
        }

        return answer == INF ? -1 : answer;
    }

    // --------------------------------------------------
    // MAIN METHOD FOR TESTING (STATIC ARRAYS)
    // --------------------------------------------------
    public static void main(String[] args) {

        int numberOfCities = 5;

        int[] fromCities = {4, 5, 4, 1, 3, 4, 4};
        int[] toCities   = {1, 3, 5, 5, 1, 2, 3};
        int[] roadFuelCost = {1, 1, 8, 1, 3, 9, 5};

        int[] fuelPrice = {9, 11, 3, 2, 10};

        int sourceCity = 3;
        int destinationCity = 2;

//        Expected Answer = 27

//        int numberOfCities = 4;
//
//        int[] fromCities = {1, 2, 2};
//        int[] toCities   = {2, 3, 4};
//        int[] roadFuelCost = {3, 1, 7};
//
//        int[] fuelPrice = {3, 6, 2, 2};
//
//        int sourceCity = 1;
//        int destinationCity = 4;

//        Expected Answer = 28

//        int numberOfCities = 5;
//
//        int[] fromCities = {2, 4, 2, 5};
//        int[] toCities   = {3, 1, 5, 3};
//        int[] roadFuelCost = {8, 4, 8, 2};
//
//        int[] fuelPrice = {9, 5, 9, 6, 3};
//
//        int sourceCity = 2;
//        int destinationCity = 4;

//        Expected Answer = -1

        long result = getMinCost(
                numberOfCities,
                fromCities,
                toCities,
                roadFuelCost,
                fuelPrice,
                sourceCity,
                destinationCity
        );

        System.out.println("Minimum travel cost = " + result);
    }
}
