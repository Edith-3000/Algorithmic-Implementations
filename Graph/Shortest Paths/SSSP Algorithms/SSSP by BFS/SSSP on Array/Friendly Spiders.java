// Prob: https://codeforces.com/problemset/problem/1775/D

// Ref: https://www.youtube.com/watch?v=Ea-3Tj3MVLA&ab_channel=CompetitiveCoding-NewtonSchool
//      https://www.youtube.com/watch?v=cBUhrPqgiEI&ab_channel=BeaconCodes

/******************************************************************************************************************************************************************/

/* # This problem is a very good example for dealing with construction of a graph which can be very dense [O(n^2) edges].
   
   # Ofcourse addition of n^2 will timeout.
   
   # Therefore with the help of few SPECIAL NODES, the nmber of edges are brought down to [O(n x log₂(MAX_NODE_VALUE))] while still 
     preserving the graph information.
*/

/******************************************************************************************************************************************************************/

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

    static int n, src, dst;
    static ArrayList<ArrayList<Integer>> g;

    static int N = 300000, INF = 10000000, OFFSET = 300000;

    // spf[i] stores the smallest prime factor for i
    static int[] spf;

    static void SPF() {
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

    static void prime_factors(int idx, int num) {
        while(num > 1) {
            int s = spf[num];
            while(spf[num] == s) num /= s;

            int x = idx, y = s + OFFSET;
            g.get(x).add(y);
            g.get(y).add(x);
        }
    }

    static void sssp_by_bfs() {
        // to store the distance of all vertices from src vertex, it'll also be used to
        // check if a vertex is already visited or not
        List<Integer> d = new ArrayList<>();

        // initialising the distances of all nodes from src as infinity (i.e. very large)
        for(int i = 0; i < (2 * OFFSET); i++) {
            d.add(INF);
        }

        // the minimum distance of src from itself = 0
        d.set(src, 0);

        // parent[i] stores the immediate parent of ith node in the
        // shortest path from src to this node
        List<Integer> parent = new ArrayList<>();

        for(int i = 0; i < (2 * OFFSET); i++) {
            parent.add(-1);
        }

        // queue to remember which vertex to visit next in case of dead end in iteration
        Queue<Integer> q = new LinkedList<>();

        // initialisation of the bfs process pushing the src in queue
        q.offer(src);

        // iterative process
        while(!q.isEmpty()) {
            // taking out vertex from q
            int cur = q.poll();

            // visiting all the adjacent vertices of v
            for(int nbr: g.get(cur)) {
                // check if nbr is visited for the first time or not
                if(d.get(nbr) == INF) {
                    // update the distance from src i.e. d[child] = d[parent] + 1
                    d.set(nbr, d.get(cur) + 1);

                    // push it in the queue
                    q.offer(nbr);

                    // mark the immediate parent of nbr as cur
                    parent.set(nbr, cur);
                }
            }
        }

        if(d.get(dst) == INF) {
            System.out.println(-1);
            return;
        }

        List<Integer> path = new ArrayList<>();

        int cur = dst;
        while(cur != -1) {
            if(cur < OFFSET) path.add(cur);
            cur = parent.get(cur);
        }

        System.out.println((d.get(dst) / 2) + 1);

        for(int i = path.size() - 1; i >= 0; i--) {
            System.out.print(path.get(i) + 1 + " ");
        }

        System.out.println();
    }

    // https://www.youtube.com/watch?v=Ea-3Tj3MVLA&ab_channel=CompetitiveCoding-NewtonSchool
    // https://www.youtube.com/watch?v=cBUhrPqgiEI&ab_channel=BeaconCodes
    public static void main(String[] args) {
        FastReader fr = new FastReader();
        n = fr.nextInt();

        List<Integer> a = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            a.add(fr.nextInt());
        }

        src = fr.nextInt();
        dst = fr.nextInt();

        if(src == dst) {
            System.out.println(1);
            System.out.println(src);
            return;
        }

        int maxNumber = a.get(0);

        for (int i = 1; i < a.size(); i++) {
            if (a.get(i) > maxNumber) {
                maxNumber = a.get(i);
            }
        }

        N = maxNumber;

        spf = new int[N + 1];
        SPF();

        g = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < (2 * OFFSET); i++) {
            g.add(new ArrayList<>());
        }

        for(int i = 0; i < n; i++) {
            prime_factors(i, a.get(i));
        }

        src -= 1;
        dst -= 1;

        sssp_by_bfs();
    }
}
