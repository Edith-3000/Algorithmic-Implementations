#include<bits/stdc++.h>
using namespace std;

int string_to_int(char *s, int n) {
	if(n == 0) return 0;
	
	int tmp = string_to_int(s, n - 1);
	int d = s[n - 1] - '0';
	tmp = (tmp * 10) + d;
	return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    char s[] = "2111261331";
    int len = strlen(s);
    
    cout << string_to_int(s, len);

    return 0;
}

// Sample o/p ---> 2111261331

// Time complexity: O(len), where len = size of input string.