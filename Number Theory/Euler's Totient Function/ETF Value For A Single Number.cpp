// function phi(n) return the #numbers from 1 to n (inclusive) which are co-prime with n, 
// where n is any +ve integer.

/*************************************************************************************************************/

// Naive approach 

ll phi(ll n) {
	ll res = 0;
	for(ll i = 1; i <= n; i++) {
		if(GCD(i, n) == 1) res++;
	}

	return res;
}

// Time complexity: O(n x log2(n))

/************************************************************************************************************/

ll phi(ll n) {
	// to store the result
	ll res = n;

	for(ll i = 2; (i * i) <= n; i++) {
		if(n % i == 0) {
			res /= i;
			res *= (i - 1);
			while(n % i == 0) n /= i;
		}
	}

	if(n > 1) res /= n, res *= (n - 1);

	// return final result
	return res;
}

// Time complexity: O(sqrt(n))

/*************************************************************************************************************/