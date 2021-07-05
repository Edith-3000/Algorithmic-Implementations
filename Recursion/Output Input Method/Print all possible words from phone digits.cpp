// Problem link: https://www.geeksforgeeks.org/find-possible-words-phone-digits/?ref=lbp

#include<bits/stdc++.h>
using namespace std;

char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

// i & j are used to traverse ip[] & op[] respectively
void generate_names(char *ip, char *op, int i, int j) {
	// base case
	if(ip[i] == '\0') {
		op[j] = '\0'; 
		cout << op << "\n"; 
		return;
	}
	
	int digit = ip[i] - '0';
	
	// if digit is either 0 or 1, just skip them as no characters
	// are associated with them in a mobile keypad
	if(digit == 0 || digit == 1) {
		generate_names(ip, op, i + 1, j);
		return;
	}
	
	for(int k = 0; keypad[digit][k] != '\0'; k++) {
		op[j] = keypad[digit][k];
		generate_names(ip, op, i + 1, j + 1); // fill the remaining part
	}
	
	return;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    char ip[20]; cin >> ip;
    char op[2000];
    
    generate_names(ip, op, 0, 0);

    return 0;
}

/*

Sample i/p --->

9421

Sample o/p --->

WGA
WGB
WGC
WHA
WHB
WHC
WIA
WIB
WIC
XGA
XGB
XGC
XHA
XHB
XHC
XIA
XIB
XIC
YGA
YGB
YGC
YHA
YHB
YHC
YIA
YIB
YIC
ZGA
ZGB
ZGC
ZHA
ZHB
ZHC
ZIA
ZIB
ZIC

*/

// Time Complexity: O(4^n), where n is the number of digits in the input number. 
//                  Each digit of a number has 3 or 4 alphabets, so it can be said that each digit has 4 
//                  alphabets as options. If there are n digits then there are 4 options for the first digit 
//                  and for each alphabet of the first digit there are 4 options in the second digit, i.e for 
//                  every recursion 4 more recursions are called (if it does not match the base case). 
//                  So the time complexity is O(4^n).

// Space Complexity:O(1), since no extra space is needed.