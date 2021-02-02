/* # Source(s): https://www.youtube.com/watch?v=O7yKm2hVrf4&list=PL2q4fbVm1Ik5HC7D3gUwc8cqwDtvOaqke&index=6
                https://www.youtube.com/watch?v=iqeo8fuER0E&list=PL2q4fbVm1Ik5HC7D3gUwc8cqwDtvOaqke&index=7

   # Problem description --->
     Given a permutation of length N and Q queries, in each query you will be given an integer K, find the 
     cost of Kth right cyclic shift.
     Contraints: N <= 10^5
     			 Q <= 10^5
     			 K <= 10^18
*/

/* # IMPORTANT OBSERVATIONS --->
   * For a permutation of length of length N, there exists only N unique permutations after the cyclic shift.
     i.e. from 0th to the (N-1)th cyclic shifts are unique after it they keep getting repeated.
   * In other words: Permutation after Kth cyclic shift = Permutation after (K % N) cyclic shift.

     eg. array = { 2, 4, 3, 1, 5 }
     0th cyclic shift: 2, 4, 3, 1, 5 ==> Cost = 3
     1st cyclic shift: 5, 2, 4, 3, 1 ==> Cost = 4
     2nd cyclic shift: 1, 5, 2, 4, 3 ==> Cost = 3
     3rd cyclic shift: 3, 1, 5, 2, 4 ==> Cost = 5
     4th cyclic shift: 4, 3, 1, 5, 2 ==> Cost = 5
     5th cyclic shift: 2, 4, 3, 1, 5 ==> Cost = 3 (repetition starts now onwards)
*/

/*************************************************************************************************************/

// Naive Method for calculating the cost of cyclic shifts from 0th to (N-1)th

void calculate() {
	for(int i = 0; i < n; i++) {
		int cnt = 0;
		// v[] is 1-based indexed
		for(int j = 1; j <= n; j++) {
			if(j != v[j]) cnt++;
		}

		// cost of the ith cyclic shit = cnt
		cost[i] = cnt;

		// now right shift the array
		rightShift()
	}
}

// Time complexity: O(n^2)

/***************************************************************************************************************/

// METHOD 2 --->

/* # For a permutation an element is on it's correct position only in one of the total "N" unique cyclic 
     shifts (0th to (N-1)th).
   # If in the ith cyclic shift if 'k' elements are on their correct position then cost of that ith cyclic
     shift = (N - k).
     Therefore in order to minimize the cost we need to maximize 'k'.  

   # Now, for an element 'j' to be at it's correct position, 
     the #cyclic shifts required = (j + pos[j] + N) % N
     where, 'j' is the required position of the element 'j' (which will be j only as it's as permutation from 1 to N)
             pos[j] = position of element 'j' in the given input permutation (1-based indexed).
 */

// EXTRAS: Identity permutation = 1, 2, 3, 4, 5, 6, 7, .....