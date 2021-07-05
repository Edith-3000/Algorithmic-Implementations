// METHOD - 1 (ITERATIVE)

#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string &s) {
    int n = (int)s.size();
    
    for(int i = 0, j = n - 1; i < j; i++, j--) {
        if(s[i] != s[j]) return 0;
    }
    
    return 1;
}

void solve()
{
    string s; cin >> s;
    if(is_palindrome(s)) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}

/******************************************************************************************************/

// METHOD - 2 (RECURSIVE)

#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(int i, string &s, int n) {
    if(i >= (n / 2)) return 1;
    return (s[i] == s[n-1-i]) and is_palindrome(i+1, s, n);
}

void solve()
{
    string s; cin >> s;
    if(is_palindrome(0, s, (int)s.length())) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}