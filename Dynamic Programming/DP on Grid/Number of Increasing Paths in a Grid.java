// Problem: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/

/**************************************************************************************************************************************************************/

import java.util.ArrayList;
import java.util.List;

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

    public int countPaths(int[][] grid) {
        int n = grid.length, m = grid[0].length;

        List<Cell> list = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                list.add(new Cell(i, j, grid[i][j]));
            }
        }

        list.sort(((o1, o2) -> o1.getValue() - o2.getValue()));

        int[][] dp = new int[n][m];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = 1;
            }
        }

        int result = 0;

        for(int i = (n * m) - 1; i >= 0; i--) {
            int r = list.get(i).getRow(), c = list.get(i).getCol();
            int val = list.get(i).getValue();

            for(int k = 0; k < 4; k++) {
                int nx = r + dx[k], ny = c + dy[k];

                if(isValid(nx, ny, n, m) && (grid[nx][ny] > grid[r][c])) {
                    dp[r][c] = (dp[r][c] + dp[nx][ny]) % mod;
                }
            }

            result = (result + dp[r][c]) % mod;
        }

        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] grid = { { 1, 1 }, { 3, 4 } };

        Solution sol = new Solution();
        int result = sol.countPaths(grid);

        System.out.println(result);
    }
}
