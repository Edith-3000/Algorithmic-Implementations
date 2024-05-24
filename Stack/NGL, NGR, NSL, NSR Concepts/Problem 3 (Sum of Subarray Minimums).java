// Problem: https://leetcode.com/problems/sum-of-subarray-minimums/description/

/**************************************************************************************************************************************************/

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

    static void nearestSmallerOrEqualToLeft(List<Integer> left, int[] arr, int n) {
        Stack<Pair<Integer, Integer>> st = new Stack<>();

        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                left.set(i, -1);
            } else if(st.peek().getKey() <= arr[i]) {
                left.set(i, st.peek().getValue());
            } else {
                while(!st.empty() && st.peek().getKey() > arr[i]) {
                    st.pop();
                }

                if(st.empty()) left.set(i, -1);
                else left.set(i, st.peek().getValue());
            }

            st.push(new Pair<>(arr[i], i));
        }
    }

    static void nearestSmallerToRight(List<Integer> right, int[] arr, int n) {
        Stack<Pair<Integer, Integer>> st = new Stack<>();

        for(int i = (n - 1); i >= 0; i--) {
            if(st.empty()) {
                right.set(i, n);
            }
            else if(st.peek().getKey() < arr[i]) {
                right.set(i, st.peek().getValue());
            }
            else {
                while(!st.empty() && st.peek().getKey() >= arr[i]) {
                    st.pop();
                }

                if(st.empty()) right.set(i, n);
                else right.set(i, st.peek().getValue());
            }

            st.push(new Pair<>(arr[i], i));
        }
    }

    private static int sumSubarrayMins(int[] arr) {
        int n = arr.length;

        List<Integer> nslList = new ArrayList<>();
        List<Integer> nsrList = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            nslList.add(0);
            nsrList.add(0);
        }

        nearestSmallerOrEqualToLeft(nslList, arr, n);
        nearestSmallerToRight(nsrList, arr, n);

        long mod = (long) 1e9 + 7;
        long result = 0;

        for (int i = 0; i < n; i++) {
            long contribution = (long) (i - nslList.get(i)) * (nsrList.get(i) - i);
            contribution = (contribution * arr[i]) % mod;
            result = (result + contribution) % mod;
        }

        return (int) result;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = fr.nextInt();
        }

        System.out.println(sumSubarrayMins(arr));
    }
}