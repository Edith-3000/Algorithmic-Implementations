// Link: https://algorithms.tutorialhorizon.com/sum-of-all-sub-arrays-in-on-time/
//       https://www.geeksforgeeks.org/sum-of-all-subarrays/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve(vll &v)
{
  	ll n = v.size();
  	ll res = 0;
  	for(ll i = 0; i < n; i++) {
  		res += (v[i] * (n - i) * (1 + i));
  	}
  	
  	cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    vll v {1, 5, 9, 11, 16};
    solve(v);

    return 0;
}