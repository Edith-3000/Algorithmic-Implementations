// Problem description: Refer Sec - 23, Lec - 5

#include<bits/stdc++.h>
using namespace std;

// i & j are iterators for input & output char arrays respectively
void generate_strings(char ip[], char op[], int i, int j) {
	// base case
	if(ip[i] == '\0') {
		op[j] = '\0';
		cout << op << "\n";
		return;
	}
	
	// recursive cases
	// Case 1: take 1 digit from ip[]
	int digit = ip[i] - '0';
	if(digit != 0) {
		char ch = digit + 'A' - 1;
		op[j] = ch;
		generate_strings(ip, op, i + 1, j + 1);
	}
	
	// Case 2: take 2 digits from ip[] while
	// handling the case of 0
	if(ip[i + 1] != '\0') {
		int second_digit = ip[i + 1] - '0';
		int num = (digit * 10) + second_digit;
		if(num >= 1 && num <= 26) {
			char ch = num + 'A' - 1;
			op[j] = ch;
			generate_strings(ip, op, i + 2, j + 1);
		}
		
		else if(num == 0) {
			i += 2;
			while(ip[i] == '0' && ip[i] != '\0') i++;
			generate_strings(ip, op, i, j);
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    char ip[500]; // to store the input digits (number)
	cin >> ip;
	
	char op[500]; // to store the result
	generate_strings(ip, op, 0, 0);

    return 0;
}

/*

Sample i/p --->

10120034

Sample op --->

AABCD
AATCD
JABCD
JATCD
JLCD

*/