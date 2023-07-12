// Problem: https://leetcode.com/problems/robot-collisions/description/

// Reference: https://www.youtube.com/watch?v=9cDY3ZuWirk

/*************************************************************************************************************************************************************************/

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

    static class Robot {
        int position, health;
        char direction;
        int index;

        Robot(int position, int health, char direction, int index) {
            this.position = position;
            this.health = health;
            this.direction = direction;
            this.index = index;
        }
    }

    public static List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;

        List<Robot> list = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            Robot robot = new Robot(positions[i], healths[i], directions.charAt(i), i);
            list.add(robot);
        }

        list.sort((o1, o2) -> o1.position - o2.position);

        Stack<Robot> stack = new Stack<>();

        for(int i = 0; i < n; i++) {
            if(stack.isEmpty()) {
                stack.push(list.get(i));
            }

            else if(list.get(i).direction == 'R') {
                stack.push(list.get(i));
            }

            else {
                boolean pushCurrentRobot = true;

                while(!stack.isEmpty()) {
                    Robot topRobot = stack.peek();

                    if(topRobot.direction == 'L') {
                        break;
                    }

                    else {
                        if(topRobot.health == list.get(i).health) {
                            topRobot.health = 0;
                            list.get(i).health = 0;
                            stack.pop();
                            pushCurrentRobot = false;
                            break;
                        }

                        else if(topRobot.health > list.get(i).health) {
                            topRobot.health -= 1;
                            list.get(i).health = 0;
                            pushCurrentRobot = false;
                            break;
                        }

                        else {
                            topRobot.health = 0;
                            list.get(i).health -= 1;
                            stack.pop();
                        }
                    }
                }

                if(pushCurrentRobot) {
                    stack.push(list.get(i));
                }
            }
        }

        list.sort((o1, o2) -> o1.index - o2.index);

        List<Integer> res = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            if(list.get(i).health != 0) {
                res.add(list.get(i).health);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        int[] positions = new int[n];
        for(int i = 0; i < n; i++) {
            positions[i] = fr.nextInt();
        }

        int[] healths = new int[n];
        for(int i = 0; i < n; i++) {
            healths[i] = fr.nextInt();
        }

        String directions = fr.next();

        List<Integer> result = survivedRobotsHealths(positions, healths, directions);
        for(Integer health: result) {
            System.out.print(health + " ");
        }
    }
}
