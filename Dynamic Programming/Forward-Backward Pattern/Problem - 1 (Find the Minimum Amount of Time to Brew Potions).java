// Problem: https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/

// Reference(s): https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/solutions/6568581/back-and-forth-by-votrubac-g35v
//               https://chatgpt.com/share/681d7565-f7f0-8001-9e41-3c6edc968286 - [https://chatgpt.com/c/681d57c2-1864-8001-92d1-9307a2d19650?model=auto]

/*********************************************************************************************************************************************************************/


class Solution {
    public long minTime(int[] skill, int[] mana) {
        int n = skill.length; // #wizards
        int m = mana.length; // #potions

        long[] endTime = new long[n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) {
                    endTime[j] = Math.max(endTime[j], endTime[j - 1]) + (skill[j] * mana[i]);
                } else {
                    endTime[j] = endTime[j] + (skill[j] * mana[i]);
                }
            }

            for (int j = n - 2; j >= 0; j--) {
                endTime[j] = endTime[j + 1] - (skill[j + 1] * mana[i]);
            }
        }

        return endTime[n - 1];
    }
}
