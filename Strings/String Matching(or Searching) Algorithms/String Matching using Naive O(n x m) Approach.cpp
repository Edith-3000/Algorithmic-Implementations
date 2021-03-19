#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    cout << "Enter the text(haystack): ";
    string text; cin >> text; cout << text <<"\n";
    cout << "Enter the pattern to be searched(needle): ";
    string pat; cin >> pat; cout << pat <<"\n";
    
    if(pat.length() > text.length()){
        cout << "Pattern length > Text length" << "\n";
        return 0;
    }
    
    cout << "\nPattern found at following positions --->\n";
    
    int n = text.size(), m = pat.size();
    
    for(int i = 0; i <= (n - m); i++){
    	if(text.substr(i, m) == pat){
    		cout << i << "\n";
    	}
    }
    
    return 0;
}

// Time complexity: O(n x m)

/*
Sample i/p: aabsgksaabsghaabs
            aabs

Sample o/p: Enter the text(haystack): aabsgksaabsghaabs
            Enter the pattern to be searched(needle): aabs

            Pattern found at following positions --->
            0
            7
            13
*/