// Link(s): https://www.youtube.com/watch?v=HbbYPQc-Oo4
//          https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/

/****************************************************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef vector<ll> vll;

void solve()
{
  	vll v {10, 2, -2, -20, 10};
  	unordered_map<ll, ll> M;
  	ll res = 0, curr_sum = 0, k = -10;
  	
  	for(ll i = 0; i < v.size(); i++) {
  		curr_sum += v[i];
  		if(curr_sum == k) res++;
  		if(M.find(curr_sum - k) != M.end()) res += M[curr_sum - k];
  		M[curr_sum]++;
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

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

// Time complexity: O(n)