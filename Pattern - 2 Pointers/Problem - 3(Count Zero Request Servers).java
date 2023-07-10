// Problem: https://leetcode.com/problems/count-zero-request-servers/description/

// Reference: https://www.youtube.com/watch?v=wNThUhqrxEU

/***************************************************************************************************************************************************************/

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

    public static int[] countServers(int n, int[][] logs, int x, int[] queries) {
        int logsCount = logs.length, queriesCount = queries.length;

        int[][] newQueries = new int[queriesCount][2];
        for(int i = 0; i < queriesCount; i++) {
            newQueries[i][0] = queries[i];
            newQueries[i][1] = i;
        }

        Arrays.sort(logs, ((o1, o2) -> {
            if(o1[1] != o2[1]) return o1[1] - o2[1];
            return o1[0] - o2[0];
        }));

        Arrays.sort(newQueries, (o1, o2) -> {
            if(o1[0] != o2[0]) return o1[0] - o2[0];
            return o1[1] - o2[1];
        });

        int[] res = new int[queriesCount];

        Map<Integer, Integer> map = new HashMap<>();
        int L = 0, R = 0;

        for(int i = 0; i < queriesCount; i++) {
            int startTime = newQueries[i][0] - x;
            int endTime = newQueries[i][0];

            while((R < logsCount) && (logs[R][1] <= endTime)) {
                map.put(logs[R][0], map.getOrDefault(logs[R][0], 0) + 1);
                R += 1;
            }

            while((L < logsCount) && (logs[L][1] < startTime)) {
                map.put(logs[L][0], map.getOrDefault(logs[L][0], 0) - 1);
                if(map.get(logs[L][0]) == 0) {
                    map.remove(logs[L][0]);
                }

                L += 1;
            }

            int queryIdx = newQueries[i][1];
            res[queryIdx] = n - map.size();
        }

        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int servers, logsCount, x, queriesCount;
        servers = fr.nextInt();
        logsCount = fr.nextInt();
        x = fr.nextInt();
        queriesCount = fr.nextInt();

        int[][] logs = new int[logsCount][2];
        for(int i = 0; i < logsCount; i++) {
            for(int j = 0; j < 2; j++) {
                logs[i][j] = fr.nextInt();
            }
        }

        int[] queries = new int[queriesCount];
        for(int i = 0; i < queriesCount; i++) {
            queries[i] = fr.nextInt();
        }

        System.out.println(Arrays.toString(countServers(servers, logs, x, queries)));
    }
}
