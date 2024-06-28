// Problem: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/

// Reference: https://www.youtube.com/watch?v=UvLVFTEnYoE

/*********************************************************************************************************************************************************/

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
        int x, y, eliminationsLeft;

        public State(int x, int y, int eliminationsLeft) {
            this.x = x;
            this.y = y;
            this.eliminationsLeft = eliminationsLeft;
        }
    }

    private static final int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    private static boolean isValidCell(int x, int y, int n, int m) {
        return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
    }

    private static int shortestPath(int[][] grid, int k) {
        int n = grid.length;

        if (n == 0) {
            return -1;
        }

        int m = grid[0].length;

        boolean[][][] isVisited = new boolean[n][m][(n * m) + 1];

        Queue<State> queue = new LinkedList<>();
        queue.add(new State(0, 0, k));

        int steps = 0;

        while (!queue.isEmpty()) {
            int queueSize = queue.size();

            while (queueSize-- > 0) {
                State currentState = queue.poll();

                if ((currentState.x == n - 1) && (currentState.y == m - 1)) {
                    return steps;
                }

                for (int[] direction: directions) {
                    int nx = currentState.x + direction[0];
                    int ny = currentState.y + direction[1];

                    if (!isValidCell(nx, ny, n, m)) {
                        continue;
                    }

                    if ((grid[nx][ny] == 0) && !isVisited[nx][ny][currentState.eliminationsLeft]) {
                        isVisited[nx][ny][currentState.eliminationsLeft] = true;
                        queue.add(new State(nx, ny, currentState.eliminationsLeft));
                    } else if ((grid[nx][ny] == 1) && (currentState.eliminationsLeft > 0) && !isVisited[nx][ny][currentState.eliminationsLeft - 1]) {
                        isVisited[nx][ny][currentState.eliminationsLeft - 1] = true;
                        queue.add(new State(nx, ny, currentState.eliminationsLeft - 1));
                    }
                }
            }

            steps += 1;
        }

        return -1;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();
        int m = fr.nextInt();

        int[][] grid = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = fr.nextInt();
            }
        }

        int k = fr.nextInt();

        System.out.println(shortestPath(grid, k));
    }
}

// TC and SC explained very well in the reference YouTube video at the end.