// Problem: Crossword Puzzle
// Contest: HackerRank - Algorithms - Recursion
// URL: https://www.hackerrank.com/challenges/crossword-puzzle/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Parsed on: 28-12-2020 14:05:10 IST (UTC+05:30)
// Author: kapil_choudhary

#include<bits/stdc++.h>
using namespace std;

bool flag = false;

void print(char a[][10]) {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) cout << a[i][j];
		cout << "\n";
	}
}

bool no_empty(char a[][10]) {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(a[i][j] == '-') return false;
		}
	}
	
	return true;
}

void fill(char a[][10], string w[], int n, int used, int taken[]) {
	// base case
	if(flag) return;
	
	if((used == n) && no_empty(a)) {
		flag = true;
		print(a);
	}	
	
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(a[i][j] == '-') {
				int h_depth = 1, v_depth = 1;
				
				while((j + h_depth < 10) && (a[i][j + h_depth] != '+')) h_depth++;
				while((i + v_depth < 10) && (a[i + v_depth][j] != '+')) v_depth++;
				
				// Case 1
				if((h_depth > 1) && (j == 0 || (j > 0 && a[i][j - 1] == '+'))) {
					for(int k = 0; k < n; k++) {
						if((w[k].length() == h_depth) && !taken[k]) {
							taken[k] = 1;
							for(int h = 0; h < h_depth; h++) {
								if(a[i][j + h] >= 'A' && a[i][j + h] <= 'Z' && a[i][j + h] != w[k][h]) {
									taken[k] = 0;
									while(h >= 0) a[i][j + h--] = '-';
									break; 
								}
								
								a[i][j + h] = w[k][h];
							}
							
							fill(a, w, n, used + 1, taken);
							for(int h = 0; h < h_depth; h++) a[i][j + h] = '-';
							taken[k] = 0;
						}
					}
				}
				
				// Case 2
				else if((v_depth > 1) && (i == 0 || (i > 0 && a[i - 1][j] == '+'))) {
					for(int k = 0; k < n; k++) {
						if((w[k].length() == v_depth) && !taken[k]) {
							taken[k] = 1;
							for(int v = 0; v < v_depth; v++) {
								if(a[i + v][j] >= 'A' && a[i + v][j] <= 'Z' && a[i + v][j] != w[k][v]) {
									taken[k] = 0;
									while(v >= 0) a[i + v--][j] = '-';
									break; 
								}
								
								a[i + v][j] = w[k][v];
							}
							
							fill(a, w, n, used + 1, taken);
							for(int v = 0; v < v_depth; v++) a[i + v][j] = '-';
							taken[k] = 0;
						}
					}
				}
				
				// Case 3 
				else if((h_depth > 1) && (j > 0 && a[i][j - 1] != '+')) {
					for(int k = 0; k < n; k++) {
						if((w[k].length() == h_depth + 1) && (a[i][j - 1] == w[k][0])  && !taken[k]) {
							taken[k] = 1;
							for(int h = 0; h < h_depth; h++) {
								if(a[i][j + h] >= 'A' && a[i][j + h] <= 'Z' && a[i][j + h] != w[k][h + 1]) {
									taken[k] = 0;
									while(h >= 0) a[i][j + h--] = '-';
									break; 
								}
								
								a[i][j + h] = w[k][h + 1];
							}
							
							fill(a, w, n, used + 1, taken);
							for(int h = 0; h < h_depth; h++) a[i][j + h] = '-';
							taken[k] = 0;
						}
					}
				}
				
				// Case 4
				else if((v_depth > 1) && (i > 0 && a[i - 1][j] != '+')) {
					for(int k = 0; k < n; k++) {
						if((w[k].length() == v_depth + 1) && (a[i - 1][j] == w[k][0]) && !taken[k]) {
							taken[k] = 1;
							for(int v = 0; v < v_depth; v++) {
								if(a[i + v][j] >= 'A' && a[i + v][j] <= 'Z' && a[i + v][j] != w[k][v + 1]) {
									taken[k] = 0;
									while(v >= 0) a[i + v--][j] = '-';
									break; 
								}
								
								a[i + v][j] = w[k][v + 1];
							}
							
							fill(a, w, n, used + 1, taken);
							for(int v = 0; v < v_depth; v++) a[i + v][j] = '-';
							taken[k] = 0;
						}
					}
				}
			}
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

    char mat[10][10]; // to take the i/p matrix
    for(int i = 0; i < 10; i++) {
    	for(int j = 0; j < 10; j++) {
    		cin >> mat[i][j];
    	}
    }
    
    string s; cin >> s;
    string words[20]; // to store each word separately
    int counter = 0; // to calulate the total #words
    
    for(int i = 0; i < s.length(); i++) {
    	if(s[i] == ';') counter++;
    	else words[counter] += s[i];
    }
    
    // token[i] indicates whether the ith word is already
    // taken or not 
    int taken[counter + 1] = {0};
    
    fill(mat, words, counter + 1, 0, taken);

    return 0;
}

// Time complexity: 

/* EXTRA KNOWLEDGE --->
   # Had the input words been separated by a comma "," instead of a semi-colon ";", then you can 
     separated the words as given in the following approach ==>
     https://www.tutorialspoint.com/parsing-a-comma-delimited-std-string-in-cplusplus
*/