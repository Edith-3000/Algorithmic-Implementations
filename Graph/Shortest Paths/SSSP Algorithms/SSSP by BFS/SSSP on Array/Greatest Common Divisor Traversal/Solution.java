// Prob: https://leetcode.com/problems/greatest-common-divisor-traversal/description/

// Ref: https://www.youtube.com/watch?v=8VYpqr-r4jw&ab_channel=codingMohan

/******************************************************************************************************************************************************************/

/* # This problem is a very good example for dealing with construction of a graph which can be very dense [O(n^2) edges].
   
   # Ofcourse addition of n^2 will timeout.
   
   # Therefore the graph is constructed intelligently to not to add all the n^2 edges.
*/

/******************************************************************************************************************************************************************/

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    int n;
    ArrayList<ArrayList<Integer>> g;

    int N = 100000;

    // spf[i] stores the smallest prime factor for i
    int[] spf;

    void SPF() {
        // marking smallest prime factor for every number to be itself initially
        for(int i = 0; i <= N; i++) spf[i] = i;

        // separately marking spf for every even number as 2
        for(int i = 4; i <= N; i += 2) spf[i] = 2;

        for(int i = 3; (long)i * i <= N; i += 2) {
            // checking if i is prime or not as only a prime no. can be it's own spf
            if(spf[i] == i) {
                // marking spf for all numbers divisible by i as i
                for(long j = (long)i * i; j <= N; j += i)  {
                    if(spf[(int)j] == j) spf[(int)j] = i;
                }
            }
        }
    }

    void prime_factors(int idx, int num, ArrayList<ArrayList<Integer>> bucket) {
        while(num > 1) {
            int s = spf[num];
            while(spf[num] == s) num /= s;
            bucket.get(s).add(idx);
        }
    }

    boolean bfs() {
        ArrayList<Boolean> vis = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            vis.add(false);
        }

        vis.set(0, true);

        Queue<Integer> q = new LinkedList<>();
        q.offer(0);

        int visitedCount = 1;

        while(!q.isEmpty()) {
            int cur = q.poll();

            for(int nbr: g.get(cur)) {
                if(!vis.get(nbr)) {
                    vis.set(nbr, true);
                    q.offer(nbr);
                    visitedCount += 1;
                }
            }
        }

        return (visitedCount == n);
    }

    public boolean canTraverseAllPairs(int[] nums) {
        int maxNumber = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > maxNumber) {
                maxNumber = nums[i];
            }
        }

        N = maxNumber;

        spf = new int[N + 1];
        SPF();

        ArrayList<ArrayList<Integer>> bucket = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i <= N; i++) {
            bucket.add(new ArrayList<>());
        }

        n = nums.length;

        for(int i = 0; i < n; i++) {
            prime_factors(i, nums[i], bucket);
        }

        g = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }

        for(int i = 0; i < bucket.size(); i++) {
            for(int j = 0; j + 1 < bucket.get(i).size(); j++) {
                int x = bucket.get(i).get(j);
                int y = bucket.get(i).get(j + 1);

                g.get(x).add(y);
                g.get(y).add(x);
            }
        }

        return bfs();
    }
}