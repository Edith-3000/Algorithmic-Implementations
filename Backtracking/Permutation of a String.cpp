#include<bits/stdc++.h>
using namespace std;

// here string must be passed by reference
void permute(int i, string &s, int n)
{
	// base case
	if(i == n){
		cout << s <<"\n";
	}
	
	for(int j = i; j < n; j++){
		// swapping done 
		swap(s[i], s[j]);

		// recurse for smaller subproblem
		permute(i+1, s, n);

		// as string is passed by reference therefore in 
		// the returning phase again place back the swapped
		// chars at their original position
		// i.e. while backtracking we are restoring the 
		// original string
		swap(s[i], s[j]);
	}
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout<<"Enter string: ";
    string s; cin >> s;
    cout << s<<"\n";
    
    int n = s.length();
    
    permute(0, s, n);
    
    return 0;
}

/* # Time Complexity: O(n * n!) 
     As there are n! permutations and it requires O(n) time to print a a permutation.
   # Note : The above solution prints duplicate permutations if there are repeating characters in input string. 
   # Refer: https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/

/* 
Sample i/p:

abc

Sample o/p:

Enter string: abc
abc
acb
bac
bca
cba
cab

*/

/****************************************************************************************************************/

// CODE TO GENERATE ONLY UNIQUE PERMUTATION AND ALSO IN LEXOGRAPHICALLY SORTED ORDER

// Just make use of a set to store the result

/*****************************************************************************************************************/

// USING C++ STL FUNCTION (next_permutation())

#include<bits/stdc++.h>
using namespace std;

void permute(string s)
{
	// sort the string in lexicographically
    // ascennding order
	sort(s.begin(), s.end());
	
	// keep printing next permutation while there
    // is next permutation
	do{
		cout << s <<"\n";
	}while(next_permutation(s.begin(), s.end()));
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout<<"Enter string: ";
    string s; cin >> s;
    cout << s<<"\n";
    
    permute(s);
    
    return 0;
}

// Time complexity: O(n * n!)
// As there are n! permutations and next_permutation() requires O(n) time to find lexicographically
// next permutation