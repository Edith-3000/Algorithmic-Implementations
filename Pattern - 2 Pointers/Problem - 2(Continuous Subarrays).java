// Problem: https://leetcode.com/problems/continuous-subarrays/description/

// Reference: https://www.youtube.com/watch?v=tHPMTQDArls

/*******************************************************************************************************************************************************************/

// METHOD - 1 [O(n x log₂(n))]

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

    static class Multiset<E> {
        private NavigableMap<E, Integer> map;

        public Multiset() {
            map = new TreeMap<>();
        }

        public void add(E element) {
            map.put(element, map.getOrDefault(element, 0) + 1);
        }

        public void remove(E element) {
            int count = map.getOrDefault(element, 0);
            if(count > 0) {
                map.put(element, count - 1);
                count -= 1;
                if(count == 0) {
                    map.remove(element);
                }
            }
        }

        public int count(E element) {
            return map.getOrDefault(element, 0);
        }

        public int size() {
            int totalElements = 0;

            for(int count: map.values()) {
                totalElements += count;
            }

            return totalElements;
        }

        public boolean isEmpty() {
            return map.isEmpty();
        }

        // public E firstEntry() throws IllegalAccessException {
        //    Map.Entry<E, Integer> entry = map.firstEntry();
        //    if(entry == null) {
        //        throw new IllegalAccessException();
        //    }

        //    return entry.getKey();
        // }

         public E firstEntry() {
            Map.Entry<E, Integer> entry = map.firstEntry();
            return entry.getKey();
         }

         // public E lastEntry() throws IllegalAccessException {
         //   Map.Entry<E, Integer> entry = map.lastEntry();
         //   if(entry == null) {
         //       throw new IllegalAccessException();
         //   }

         //   return entry.getKey();
         // }

        public E lastEntry() {
            Map.Entry<E, Integer> entry = map.lastEntry();
            return entry.getKey();
        }
    }

    static boolean isGood(int num, Multiset<Integer> multiset) {
        if(multiset.isEmpty()) return true;

        int max = multiset.lastEntry();
        int min = multiset.firstEntry();

        max = Math.max(max, num);
        min = Math.min(min, num);

        return (max - min) <= 2;
    }

    public static long continuousSubarrays(int[] nums) {
        int n = nums.length;

        // Since Java doesn't have in-built Multiset, therefore custom Multiset class is
        // being used to achieve the same functionality
        Multiset<Integer> multiset = new Multiset<>();

        long res = 0;
        int j = 0;

        for(int i = 0; i < n; i++) {
            while((j < n) && isGood(nums[j], multiset)) {
                multiset.add(nums[j]);
                j += 1;
            }

            res += (j - i);
            multiset.remove(nums[i]);
        }

        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();
        int[] nums = new int[n];

        for(int i = 0; i < n; i++) {
            nums[i] = fr.nextInt();
        }

        System.out.println(continuousSubarrays(nums));
    }
}

/*******************************************************************************************************************************************************************/

// METHOD - 1 [O(n x (log₂(n))^2)]

// NOTE: This approach wasn't getting an AC on LeetCode since the runtime is exceeding little bit over 10^7
//       operations per second, but it's worth learning this Binary Search with Segment Tree approach.

// Refer: "/Advanced DS/Range Query DS/Segment Tree/With Lazy Propagation/Problem - 2(Continuous Subarrays).java"
