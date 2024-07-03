// Problem: https://leetcode.com/problems/shortest-path-to-get-all-keys/description/

// Reference: https://youtu.be/boKdhdIjE5E

/**********************************************************************************************************************************************************/

import javafx.util.Pair;

import java.awt.datatransfer.StringSelection;
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

    static class State {
        int x, y, keyMask;

        public State(int x, int y, int keyMask) {
            this.x = x;
            this.y = y;
            this.keyMask = keyMask;
        }
    }

    private static final int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    private static boolean isValidCell(int x, int y, int n, int m) {
        return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
    }

    private static Pair<Integer, Integer> findSourceCell(String[] grid, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((grid[i].charAt(j) == '@')) {
                    return new Pair<>(i, j);
                }
            }
        }

        return new Pair<>(-1, -1);
    }

    private static int findKeysCount(String[] grid, int n, int m) {
        int keysCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (Character.isLowerCase(grid[i].charAt(j))) {
                    keysCount += 1;
                }
            }
        }

        return keysCount;
    }

    private static int shortestPathAllKeys(String[] grid) {
        int n = grid.length;

        if (n == 0) {
            return -1;
        }

        int m = grid[0].length();

        Pair<Integer, Integer> source = findSourceCell(grid, n, m);

        int totalKeys = findKeysCount(grid, n, m);

        boolean[][][] isVisitedState = new boolean[n][m][1 << totalKeys];
        isVisitedState[source.getKey()][source.getValue()][0] = true;

        Queue<State> queue = new LinkedList<>();
        queue.add(new State(source.getKey(), source.getValue(), 0));

        int result = 0;

        while (!queue.isEmpty()) {
            int queueSize = queue.size();

            while (queueSize-- > 0) {
                State currentState = queue.poll();

                if (currentState.keyMask == ((1 << totalKeys) - 1)) {
                    return result;
                }

                for (int[] direction: directions) {
                    int nx = currentState.x + direction[0];
                    int ny = currentState.y + direction[1];

                    if (!isValidCell(nx, ny, n, m) || (grid[nx].charAt(ny) == '#')) {
                        continue;
                    }

                    char ch = grid[nx].charAt(ny);

                    int newKeyMask = currentState.keyMask;

                    if (Character.isUpperCase(ch) && (((newKeyMask >> (ch - 'A')) & 1) == 0)) {
                        continue;
                    }

                    if (Character.isLowerCase(ch)) {
                        newKeyMask |= (1 << (ch - 'a'));
                    }

                    if (!isVisitedState[nx][ny][newKeyMask]) {
                        isVisitedState[nx][ny][newKeyMask] = true;
                        queue.add(new State(nx, ny, newKeyMask));
                    }
                }
            }

            result += 1;
        }

        return -1;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        String[] grid = new String[n];

        for (int i = 0; i < n; i++) {
            grid[i] = fr.next();
        }

        System.out.println(shortestPathAllKeys(grid));
    }
}

// TC and SC explained very well in the reference YouTube video at the end.