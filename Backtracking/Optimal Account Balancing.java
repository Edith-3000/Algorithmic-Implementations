// Problem: https://leetcode.com/problems/optimal-account-balancing/

/*********************************************************************************************************************************************************************/

// METHOD - 1 [Using Backtracking]

// Reference: https://youtu.be/WaUlOC1T07c
//            https://walkccc.me/LeetCode/problems/465/#__tabbed_1_2
//            https://prepfortech.io/leetcode-solutions/optimal-account-balancing

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

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

    private static final int maxUserId = 11;

    private static int backtrack(List<Integer> list, int idx, int count) {
        while ((idx < list.size()) && (list.get(idx) == 0)) {
            idx += 1;
        }

        if (idx == list.size()) {
            return count;
        }

        int minTransactions = Integer.MAX_VALUE;

        for (int i = idx + 1; i < list.size(); i++) {
            if ((list.get(idx) * list.get(i)) < 0) {
                list.set(i, list.get(i) + list.get(idx));
                minTransactions = Math.min(minTransactions, backtrack(list, idx + 1, count + 1));
                list.set(i, list.get(i) - list.get(idx));
            }
        }

        return minTransactions;
    }

    private static int minTransfers(int[][] transactions) {
        int transactionsCount = transactions.length;

        int[] balance = new int[maxUserId + 1];

        for (int[] transaction: transactions) {
            balance[transaction[0]] -= transaction[2];
            balance[transaction[1]] += transaction[2];
        }

        List<Integer> list = new ArrayList<>();

        for (int userBalance: balance) {
            if (userBalance != 0) {
                list.add(userBalance);
            }
        }

        return backtrack(list, 0, 0);
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[][] transactions = new int[n][3];

        for (int i = 0; i < n; i++) {
            int from = fr.nextInt();
            int to = fr.nextInt();
            int amount = fr.nextInt();

            transactions[i][0] = from;
            transactions[i][1] = to;
            transactions[i][2] = amount;
        }

        System.out.println(minTransfers(transactions));
    }
}

// TC: O(n!)
// SC: O(n)

/*********************************************************************************************************************************************************************/

// METHOD - 2 [Using DP]

// Potential Ref: https://algo.monster/liteproblems/465

// NOTE: Did not understand this approach, hence implementation is pending.