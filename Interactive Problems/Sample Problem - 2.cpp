// Problem: B. Lost Numbers
// Contest: Codeforces - Educational Codeforces Round 65 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1167/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Parsed on: 16-11-2020 09:17:05 IST (UTC+05:30)
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

int query_to_judge(int i, int j)
{
	cout << "? " << i << " " << j << endl;
	int prod; cin >> prod;
	return prod;
}

void solve()
{
  	vector<int> v {4, 8, 15, 16, 23, 42};
  	vector<int> x(4);
  	
  	for(int i = 0; i < 4; i++){
  		x[i] = query_to_judge(i+1, i+2);
  	}
  	
  	do{
  		bool flag = true;
  		
  		for(int i = 0; i < 4; i++){
  			if(x[i] != (v[i] * v[i + 1])){
  				flag = false;
  			}
  		}
  		
  		if(flag){
  			cout << "! ";
  			for(auto num: v) cout << num << " ";
  			return;
  		}
  	}while(next_permutation(v.begin(), v.end()));
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