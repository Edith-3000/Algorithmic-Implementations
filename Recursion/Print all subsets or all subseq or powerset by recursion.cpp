// The concept used is exactly same as used in "Print all subsets or all subseq or powerset by recursion.txt",
// only the way of implementation has changed

#include<bits/stdc++.h>
using namespace std;

// Remember char[] is by default passed by reference
void solve(char *input, char *output, int i, int j) {
	// base case
	if(input[i] == '\0') {
		output[j] = '\0';
		cout << output << "\n";
		return;
	}
	
	// Case 1: include the current character at i
	output[j] = input[i];
	solve(input, output, i + 1, j + 1);
	
	// Case 2: exclude the current character at i
	// for this case we don't want to do output[j] = input[i]
	// but it has already been done in above case, but in the below
	// case we are not incrementing j, therefore it will be overwritten later on
	solve(input, output, i + 1, j); 
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    char input[20];
    cin >> input;
    
    char output[20];
    solve(input, output, 0, 0);

    return 0;
}

/* Sample i/p ---> abc
   Sample o/p ---> abc
				   ab
				   ac
				   a
				   bc
				   b
				   c
*/