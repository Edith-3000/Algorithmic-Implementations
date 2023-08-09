// Problem: https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/

// Reference: Hint section of LC
//            https://www.youtube.com/watch?v=ZqEX8Eab3ZA
//            Highlighted comment - https://www.youtube.com/watch?v=ZqEX8Eab3ZA&lc=UgwOB8QAIiGMA6N1ESN4AaABAg

/**********************************************************************************************************************************************************************/

// METHOD - 1 [O((log₂(n) x n^2]

import javafx.util.Pair;

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

    static int INF = (int) 1e9;

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static boolean isValid(int x, int y, int n, int m) {
        return (x >= 0) && (x < n) && (y >= 0) && (y < m);
    }

    static List<List<Integer>> findMinimumManhattanDistance(List<List<Integer>> grid) {
        int n = grid.size(), m = grid.get(0).size();

        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        List<List<Integer>> distance = new ArrayList<>();
        List<List<Boolean>> visited = new ArrayList<>();
        
        for(int i = 0; i < n; i++) {
            distance.add(new ArrayList<>());
            visited.add(new ArrayList<>());

            for(int j = 0; j < m; j++) {
                if(grid.get(i).get(j) == 1) {
                    queue.add(new Pair<>(i, j));
                    distance.get(i).add(0);
                    visited.get(i).add(true);
                }

                else {
                    distance.get(i).add(INF);
                    visited.get(i).add(false);
                }
            }
        }

        while(!queue.isEmpty()) {
            Pair<Integer, Integer> current = queue.poll();

            for(int k = 0; k < 4; k++) {
                int nx = current.getKey() + dx[k], ny = current.getValue() + dy[k];

                if(isValid(nx, ny, n, m) && !visited.get(nx).get(ny)) {
                    visited.get(nx).set(ny, true);
                    queue.add(new Pair<>(nx, ny));
                    distance.get(nx).set(ny, distance.get(current.getKey()).get(current.getValue()) + 1);
                }
            }
        }

        return distance;
    }

    static boolean pathFound(int value, List<List<Integer>> distance) {
        int n = distance.size(), m = distance.get(0).size();

        if (distance.get(0).get(0) < value) {
            return false;
        }

        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        List<List<Boolean>> visited = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            visited.add(new ArrayList<>());
            for(int j = 0; j < m; j++) {
                visited.get(i).add(false);
            }
        }

        queue.add(new Pair<>(0, 0));
        visited.get(0).set(0, true);

        while(!queue.isEmpty()) {
            Pair<Integer, Integer> current = queue.poll();

            if((current.getKey() == n - 1) && (current.getValue() == m - 1)) {
                return true;
            }

            for(int k = 0; k < 4; k++) {
                int nx = current.getKey() + dx[k], ny = current.getValue() + dy[k];

                if(isValid(nx, ny, n, m) && !visited.get(nx).get(ny) && distance.get(nx).get(ny) >= value) {
                    visited.get(nx).set(ny, true);
                    queue.add(new Pair<>(nx, ny));
                }
            }
        }

        return false;
    }

    public static int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size(), m = grid.get(0).size();

        List<List<Integer>> distance = findMinimumManhattanDistance(grid);
        
        int L = 0, R = 400, res = 0;

        while(L <= R) {
            int mid = L + ((R - L) >> 1);

            if(pathFound(mid, distance)) {
                res = mid;
                L = mid + 1;
            }

            else {
                R = mid - 1;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n, m;
        n = fr.nextInt();
        m = fr.nextInt();

        List<List<Integer>> grid = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            grid.add(new ArrayList<>());
            for(int j = 0; j < m; j++) {
                int val = fr.nextInt();
                grid.get(i).add(val);
            }
        }

        System.out.println(maximumSafenessFactor(grid));
    }
}

/**********************************************************************************************************************************************************************/

// METHOD - 2 [O(n^2)]
// The TC is O(n^2) because DSU methods take amortized CONSTANT 𝑶(1) time

import javafx.util.Pair;
import org.w3c.dom.ls.LSException;

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

    // CAUTION : use 0-based indexing for the nodes
    static class DSU {
        int[] parent, siz;

        DSU(int n) {
            parent = new int[n];
            siz = new int[n];
        }

        void makeSet(int n) {
            for(int i = 0; i < n; i++) {
                parent[i] = i;
                siz[i] = 1;
            }
        }

        int findSet(int v) {
            if(v == parent[v]) return v;
            return parent[v] = findSet(parent[v]);
        }

        void unionSets(int a, int b) {
            int s1 = findSet(a);
            int s2 = findSet(b);

            if(s1 != s2) {
                if(siz[s1] < siz[s2]) {
                    int temp = s1;
                    s1 = s2;
                    s2 = temp;
                }

                parent[s2] = s1;
                siz[s1] += siz[s2];
            }
        }
    };

    static int INF = (int) 1e9;

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static boolean isValid(int x, int y, int n, int m) {
        return (x >= 0) && (x < n) && (y >= 0) && (y < m);
    }

    static List<List<Integer>> findMinimumManhattanDistance(List<List<Integer>> grid) {
        int n = grid.size(), m = grid.get(0).size();

        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        List<List<Integer>> distance = new ArrayList<>();
        List<List<Boolean>> visited = new ArrayList<>();
        
        for(int i = 0; i < n; i++) {
            distance.add(new ArrayList<>());
            visited.add(new ArrayList<>());

            for(int j = 0; j < m; j++) {
                if(grid.get(i).get(j) == 1) {
                    queue.add(new Pair<>(i, j));
                    distance.get(i).add(0);
                    visited.get(i).add(true);
                }

                else {
                    distance.get(i).add(INF);
                    visited.get(i).add(false);
                }
            }
        }

        while(!queue.isEmpty()) {
            Pair<Integer, Integer> current = queue.poll();

            for(int k = 0; k < 4; k++) {
                int nx = current.getKey() + dx[k], ny = current.getValue() + dy[k];

                if(isValid(nx, ny, n, m) && !visited.get(nx).get(ny)) {
                    visited.get(nx).set(ny, true);
                    queue.add(new Pair<>(nx, ny));
                    distance.get(nx).set(ny, distance.get(current.getKey()).get(current.getValue()) + 1);
                }
            }
        }

        return distance;
    }

    static Integer oneDimensionValue(int x, int y, int n, int m) {
        return (x * n) + y;
    }

    static Pair<Integer, Integer> twoDimensionValue(int index, int n, int m) {
        return new Pair<>(index / n, index % m);
    }

    public static int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size(), m = grid.get(0).size();

        List<List<Integer>> distance = findMinimumManhattanDistance(grid);

        Map<Integer, List<Integer>> indices = new TreeMap<>(((o1, o2) -> o2.compareTo(o1)));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(indices.containsKey(distance.get(i).get(j))) {
                    List<Integer> list = indices.get(distance.get(i).get(j));
                    list.add(oneDimensionValue(i, j, n, m));
                }

                else {
                    List<Integer> list = new ArrayList<>();
                    list.add(oneDimensionValue(i, j, n, m));
                    indices.put(distance.get(i).get(j), list);
                }
            }
        }

        List<Boolean> isActive = new ArrayList<>();
        for(int i = 0; i < (n * m); i++) {
            isActive.add(false);
        }

        // initialising DSU structure
        DSU dsu = new DSU(n * m);
        dsu.makeSet(n * m);

        for(Map.Entry<Integer, List<Integer>> entry: indices.entrySet()) {
            for(Integer index: entry.getValue()) {
                isActive.set(index, true);
                Pair<Integer, Integer> current = twoDimensionValue(index, n, m);

                for(int k = 0; k < 4; k++) {
                    int nx = current.getKey() + dx[k], ny = current.getValue() + dy[k];

                    if(isValid(nx, ny, n, m) && isActive.get(oneDimensionValue(nx, ny, n, m))) {
                        dsu.unionSets(index, oneDimensionValue(nx, ny, n, m));
                    }
                }
            }

            if(dsu.findSet(oneDimensionValue(0, 0, n, m)) == dsu.findSet(oneDimensionValue(n - 1, m - 1, n, m))) {
                return entry.getKey();
            }
        }

        return INF;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n, m;
        n = fr.nextInt();
        m = fr.nextInt();

        List<List<Integer>> grid = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            grid.add(new ArrayList<>());
            for(int j = 0; j < m; j++) {
                int val = fr.nextInt();
                grid.get(i).add(val);
            }
        }

        System.out.println(maximumSafenessFactor(grid));
    }
}

