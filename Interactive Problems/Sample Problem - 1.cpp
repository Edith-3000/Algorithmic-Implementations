// Problem: 1. Guess the Number
// Contest: Codeforces - Interactive Problem Training Contest
// URL: https://codeforces.com/gym/101021/problem/1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 16-11-2020 08:00:38 IST (UTC+05:30)
// Author: kapil_choudhary

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int>	vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pii>	vpii;
typedef vector<pll>	vpll;
typedef vector<vi> vvi;
typedef vector<vll>	vvll;
typedef vector<vull> vvull;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const int mod = 1e9+7;

string query_to_judge(int mid)
{
	cout << mid << endl;
	string s; cin >> s;
	
	return s;
}

void solve()
{
  	int l = 1, r = 1e6;
  	int mid, res;
  	
  	while(l <= r){
  		mid = l + (r - l)/2; // to avoid overflow
  		if(query_to_judge(mid) == "<"){
  			r = mid - 1;
  		}
  		
  		else{
  			res = mid;
  			l = mid + 1;
  		}
  	}
  	
  	cout << "! " << res << endl;
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