// 𝒅𝒐𝒖𝒃𝒍𝒆 𝒔𝒒𝒓𝒕(𝒅𝒐𝒖𝒃𝒍𝒆 𝒂𝒓𝒈): 𝑰𝒕 𝒓𝒆𝒕𝒖𝒓𝒏𝒔 𝒕𝒉𝒆 𝒔𝒒𝒖𝒂𝒓𝒆 𝒓𝒐𝒐𝒕 𝒐𝒇 𝒂 𝒏𝒖𝒎𝒃𝒆𝒓 𝒕𝒐 𝒕𝒚𝒑𝒆 𝒅𝒐𝒖𝒃𝒍𝒆
// int gets typecasted to double when it is passed as an arguement in sqrt()

#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool is_perfect_square(ll n) {
	// if difference of floating point value of square root of x  
    // & floor of x is 0, then no. is perfect sq.
      
	return ((sqrt(n) - floor(sqrt(n))) == 0) ? 1 : 0;
}

void solve()
{
  	ll n; cin >> n;
  	
  	if(is_perfect_square(n)) cout << "YES\n";
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
    
    // #ifndef ONLINE_JUDGE
    //      freopen("error.txt", "w", stderr);
    // #endif
    
    int t = 1;
    // int test = 1;
    // cin >> t;
    while(t--) {
        // cout << "Case #" << test++ << ": ";
        solve();
    }

    return 0;
}