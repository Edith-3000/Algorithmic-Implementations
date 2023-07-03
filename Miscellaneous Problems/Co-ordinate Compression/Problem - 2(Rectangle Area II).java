// Problem - https://leetcode.com/problems/rectangle-area-ii/description/

// Reference: https://leetcode.com/problems/rectangle-area-ii/editorial/

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

    static long mod = (long) 1e9+7;

    static int rectangleArea(int[][] rectangles) {
        int n = rectangles.length;

        Set<Integer> xValues = new HashSet<>();
        Set<Integer> yValues = new HashSet<>();

        for(int[] rectangle: rectangles) {
            xValues.add(rectangle[0]);
            xValues.add(rectangle[2]);
            yValues.add(rectangle[1]);
            yValues.add(rectangle[3]);
        }

        Integer[] inverseMapX = xValues.toArray(new Integer[0]);
        Arrays.sort(inverseMapX);

        Integer[] inverseMapY = yValues.toArray(new Integer[0]);
        Arrays.sort(inverseMapY);

        Map<Integer, Integer> mapX = new HashMap<>();
        Map<Integer, Integer> mapY = new HashMap<>();

        for(int i = 0; i < inverseMapX.length; i++) {
            mapX.put(inverseMapX[i], i);
        }

        for(int i = 0; i < inverseMapY.length; i++) {
            mapY.put(inverseMapY[i], i);
        }

        boolean[][] grid = new boolean[mapX.size()][mapY.size()];

        for(int[] rectangle: rectangles) {
            for(int i = mapX.get(rectangle[0]); i < mapX.get(rectangle[2]); i++) {
                for(int j = mapY.get(rectangle[1]); j < mapY.get(rectangle[3]); j++) {
                    grid[i][j] = true;
                }
            }
        }

        long res = 0;

        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[i].length; j++) {
                if(!grid[i][j]) continue;

                long contribution = ((long) (inverseMapX[i + 1] - inverseMapX[i]) * (inverseMapY[j + 1] - inverseMapY[j])) % mod;
                res = (res + contribution) % mod;
            }
        }

        return (int) res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[][] rectangles = new int[n][4];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 4; j++) {
                rectangles[i][j] = fr.nextInt();
            }
        }

        System.out.println(rectangleArea(rectangles));
    }
}
