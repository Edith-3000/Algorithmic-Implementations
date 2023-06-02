// Problem: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

/******************************************************************************************************************************************************************/

// METHOD - 1

// Ref: https://www.youtube.com/watch?v=bI27Vnwakxc&ab_channel=ShiranAfergan

/******************************************************************************************************************************************************************/

// METHOD - 2

// This method is an implementation of what's being discussed in the below "Highlighted comment" of the reference of "METHOD - 1" --->
// https://www.youtube.com/watch?v=bI27Vnwakxc&lc=Ugyp5fNTO84tQOvgWmF4AaABAg&ab_channel=ShiranAfergan

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Cell {
    int row, col, value;

    Cell(int row, int col, int value) {
        this.row = row;
        this.col = col;
        this.value = value;
    }

    public int getRow() {
        return row;
    }

    public int getCol() {
        return col;
    }

    public int getValue() {
        return value;
    }
}

class Solution {
    int mod = (int) (1e9+7);

    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, 1, 0, -1};

    private boolean isValid(int x, int y, int n, int m) {
        return (x >= 0) && (x < n) && (y >= 0) && (y < m);
    }

    public int longestIncreasingPath(int[][] grid) {
        int n = grid.length, m = grid[0].length;

        List<Cell> list = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                list.add(new Cell(i, j, grid[i][j]));
            }
        }

        list.sort(((o1, o2) -> o1.getValue() - o2.getValue()));

        // dp[i][j] = length of the longest increasing path starting from cell(i, j)
        int[][] dp = new int[n][m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = 1;
            }
        }

        int result = 1;

        for(int i = (n * m) - 1; i >= 0; i--) {
            int r = list.get(i).getRow(), c = list.get(i).getCol();

            for(int k = 0; k < 4; k++) {
                int nx = r + dx[k], ny = c + dy[k];

                if(isValid(nx, ny, n, m) && (grid[nx][ny] > grid[r][c])) {
                    dp[r][c] = Math.max(dp[r][c], 1 + dp[nx][ny]);
                }
            }

            result = Math.max(result, dp[r][c]);
        }

        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        // int[][] matrix = { {9, 9, 4}, {6, 6, 8}, {2, 1, 1} };

        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt(), m = scan.nextInt();

        int[][] matrix = new int[n][m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                matrix[i][j] = scan.nextInt();
            }
        }

        scan.close();

        Solution sol = new Solution();
        int result = sol.longestIncreasingPath(matrix);

        System.out.println(result);
    }
}
