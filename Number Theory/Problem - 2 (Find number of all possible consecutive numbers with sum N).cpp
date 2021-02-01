// Problem: D - Staircase Sequences
// Contest: AtCoder - AtCoder Beginner Contest 190
// URL: https://atcoder.jp/contests/abc190/tasks/abc190_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Parsed on: 31-01-2021 21:19:40 IST (UTC+05:30)
// Author: Kapil Choudhary
// ********************************************************************
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
// मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि || १.४७ ||
// ********************************************************************

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
  	ll n; cin >> n;
  	ll res = 0;
  	for(ll len = 2; (len * (len + 1))/2 <= n; len++) {
  		if(((n - (len * (len + 1))/2) % len) == 0) res++;
  	}
  	
  	cout << (res + 1) * 2LL << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}