// Problem: https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/description/

// Ref: https://www.youtube.com/watch?v=Chl2-fBuSOs&ab_channel=codingMohan

/***************************************************************************************************************************************************************/

/* # This is perfect example of a problem where first recursive solution was created.
   # Then recursive solution was transformed into a Top-Down DP approach.
   # But it was difficult to optimise the Top-Down approach further.
   # Therefore Bottom-Up DP solution was formulated and then optimised further to fit in the contraints of problem, because sometime it is
     easier to optimise Bottom-Up solution than Top-Down.
*/

/***************************************************************************************************************************************************************/

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

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
    public int maxIncreasingCells(int[][] mat) {
        int n = mat.length, m = mat[0].length;

        List<Cell> list = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                list.add(new Cell(i, j, mat[i][j]));
            }
        }

        list.sort(((o1, o2) -> o1.getValue() - o2.getValue()));

        List<Integer> maxInRow = new ArrayList<>();
        List<Integer> maxInCol = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            maxInRow.add(-1);
        }

        for(int i = 0; i < m; i++) {
            maxInCol.add(-1);
        }

        int result = 1;

        for(int i = (n * m) - 1; i >= 0;) {
            int curValue = list.get(i).getValue();

            Map<Integer, Integer> curMaxInRow = new HashMap<>();
            Map<Integer, Integer> curMaxInCol = new HashMap<>();

            for(int j = i; (j >= 0) && (list.get(j).getValue() == curValue); j--, i--) {
                int r = list.get(j).getRow(), c = list.get(j).getCol();
                int curResult = 1 + Math.max(0, Math.max(maxInRow.get(r), maxInCol.get(c)));

                if(!curMaxInRow.containsKey(r)) {
                    curMaxInRow.put(r, curResult);
                }

                else if(curMaxInRow.get(r) < curResult) {
                    curMaxInRow.put(r, curResult);
                }

                if(!curMaxInCol.containsKey(c)) {
                    curMaxInCol.put(c, curResult);
                }

                else if(curMaxInCol.get(c) < curResult) {
                    curMaxInCol.put(c, curResult);
                }

                result = Math.max(result, curResult);
            }

            for(Map.Entry<Integer, Integer> entry: curMaxInRow.entrySet()) {
                int r = entry.getKey(), mx = entry.getValue();
                maxInRow.set(r, mx);
            }

            for(Map.Entry<Integer, Integer> entry: curMaxInCol.entrySet()) {
                int c = entry.getKey(), mx = entry.getValue();
                maxInCol.set(c, mx);
            }
        }

        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        int[][] mat = { { 3, 1, 6 }, { -9, 5, 7 } };

        Solution sol = new Solution();
        int result = sol.maxIncreasingCells(mat);

        System.out.println(result);
    }
}
