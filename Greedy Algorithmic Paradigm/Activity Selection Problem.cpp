// We'll greedily select those activities which END first.
/*==============================================================================================================*/

// Problem: I AM VERY BUSY
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/BUSYMAN/
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// Parsed on: 16-11-2020 14:33:57 IST (UTC+05:30)
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

class myComparator{
	public:
		bool operator()(pair<int, int> &p1, pair<int, int> &p2){
			if(p1.second == p2.second){
				return p1.first < p2.first;
			}
			
			return p1.second < p2.second;
		}
};

void solve()
{
  	int n; cin >> n;
  	vpii v(n);
  	for(int i = 0; i < n; i++){
  		int start, end;
  		cin >> start >> end;
  		v[i] = {start, end};
  	}
  	
  	sort(v.begin(), v.end(), myComparator());  	
  	int res = 1, end_prev = v[0].second;
  	
  	for(int  i = 1; i < n; i++){
  		if(v[i].first >= end_prev){
  			res++;
  			end_prev = v[i].second;
  		}
  	}
  	
  	cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

// Time complexity: O(n x log(n)) (for 1 test case)
// Space complexity: O(1)

/****************************************************************************************************************************************************************/

// NOTE: Using similar concepts following can also be solved --->
//       https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/