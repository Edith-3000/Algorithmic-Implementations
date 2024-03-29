// PRIMALITY TEST: To check whether an input no. is prime or not.

// NAIVE APPROACH

bool is_prime(long long n) {
   // 1 is neither prime nor composite
	if(n == 1LL) return false; 

	for(long long i = 2LL; i < n; i++) {
	    if((n % i) == 0LL) return false;
	}

	return true;
}


// Time complexity: O(n)

/*********************************************************************************************************************************************************/

// BETTER APPROACH

/* 
   # All divisors of a number occur in pairs.
   # For a divisor pair (a, b) of a no. n, one of them lies below sqrt(n) & the other lies above sqrt(n)
*/

bool is_prime(long long n) {
	// 1 is neither prime nor composite
	if(n == 1LL) return false; 

	for(long long i = 2LL; (i * i) <= n; i++) {
		if((n % i) == 0LL) return false;
	}

	return true;
}

// Time complexity: O(sqrt(n))

/*********************************************************************************************************************************************************/

// MOST OPTIMIZED APPROACH ---> Using Sieve of Eratosthenes

/*********************************************************************************************************************************************************/

// FERMAT PRIMALITY TEST 

/* 
	# It's a rejection test for primality i.e. it only confirms that a number is NOT prime under certain conditions.
     So basically it's a probabilistic primality test (not deterministic).

   # For more info, visit: • https://cp-algorithms.com/algebra/primality_tests.html
   						      • https://brilliant.org/wiki/fermats-little-theorem/ (last of the webpage)
   						      • https://brilliant.org/wiki/prime-testing/
*/

/*********************************************************************************************************************************************************/

// MILLER-RABIN PRIMALITY TEST (𝒇𝒐𝒓 𝒏𝒖𝒎𝒃𝒆𝒓𝒔 𝒕𝒊𝒍𝒍 10^18) 

/* 
   # This test extends the ideas from the Fermat test.
   # For more info visit: https://brilliant.org/wiki/prime-testing/
*/