/* Problem description ---> 
   You are given a string which contains zero or more occurrences of the substring "pi" in it. Your task is to
   replace all the occurrences of "pi" with "3.14" and then print the string again.
   Max length of the string can be 1500 characters. There are no spaces in the string
   For eg. string "kplotpi59yupi" must be converted to "kplot3.1459yu3.14".

   * NOTE: Solve this question using recursion & perform in place replacement (no other output string should
           be used).
 */

#include<bits/stdc++.h>
using namespace std;

void replace_pi(char a[], int i) {
	// base case
	if(a[i] == '\0' || a[i + 1] == '\0') return;
	
	if(a[i] == 'p' && a[i + 1] == 'i') {
		int j = i + 2;
		while(a[j] != '\0') j++;
		
		while(j >= i + 2) {
			a[j + 2] = a[j];
			j--;
		}
		
		a[i] = '3'; a[i + 1] = '.'; 
		a[i + 2] = '1'; a[i + 3] = '4';
		
		replace_pi(a, i + 4);
	}
	
	else replace_pi(a, i + 1);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    char a[2000];
    cin >> a;
    replace_pi(a, 0);
    cout << a;

    return 0;
}

// Sample i/p: kplotpi59yupi
// Sample o/p: kplot3.1459yu3.14